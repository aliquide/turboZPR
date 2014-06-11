import json
from json import JSONEncoder
import socket
import tornado.httpserver
import tornado.websocket
import tornado.ioloop
from tornado.ioloop import PeriodicCallback
import tornado.web
import time
MockUp = {
    "pHP" : 5,
    "pMP" : 8    
}



class Retval:
    PLEXIST = 1
    WAITFP2 = 2
    GAMESTART = 3

Makieta ={
	"p1Table" : [
	{
        "Id": 1 ,
        "cardStr" : "nazwaobrazka1"
    },
	{
        "Id": 2 ,
        "cardStr" : "nazwaobrazka2"
    },
    {
        "Id": 3 ,
        "cardStr" : "nazwaobrazka3"
    },
    {
        "Id": 4 ,
        "cardStr" : "nazwaobrazka4"
    },
    {
        "Id": 5 ,
        "cardStr" : "nazwaobrazka5"
    },

 ],

 "p2Table" : [
	{
        "Id": 1 ,
        "cardStr" : "nazwaobrazka1"
    },
	{
        "Id": 2 ,
        "cardStr" : "nazwaobrazka2"
    },
    {
        "Id": 3 ,
        "cardStr" : "nazwaobrazka3"
    },
    {
        "Id": 4 ,
        "cardStr" : "nazwaobrazka4"
    },
    {
        "Id": 5 ,
        "cardStr" : "nazwaobrazka5"
    },

 ],

  "p1Hand" : [
	{
        "Id": 1 ,
        "cardStr" : "nazwaobrazka1"
    },
	{
        "Id": 2 ,
        "cardStr" : "nazwaobrazka2"
    },
    {
        "Id": 3 ,
        "cardStr" : "nazwaobrazka3"
    },
    {
        "Id": 4 ,
        "cardStr" : "nazwaobrazka4"
    },
    {
        "Id": 5 ,
        "cardStr" : "nazwaobrazka5"
    },

 ],

 "p2Hand" : [# cyfra - id karty dane przez serwer, string - nazwa obrazka ktorego klient ma wyswietlic
	{
        "Id": 1 ,
        "cardStr" : "nazwaobrazka1"
    },
	{
        "Id": 2 ,
        "cardStr" : "nazwaobrazka2"
    },
    {
        "Id": 3 ,
        "cardStr" : "nazwaobrazka3"
    },
    {
        "Id": 4 ,
        "cardStr" : "nazwaobrazka4"
    },
    {
        "Id": 5 ,
        "cardStr" : "nazwaobrazka5"
    },

 ],
 "p1" : "tutajID",
 "p2" : "tutajID",
 "StanGry" : "tutajstan", # start gry / gra trwa / koniec gry
 "RuchGracza    " : "tutajstan", # wykladanie kart/ atakuj gracza / doloswanie kart/ koniec tury
 "TuraGracza" : "Idgracza", # id gracza ktory wlasnie sie rusza to w mock up stan tury
 "p1mana": 1,
 "p2mana": 2,
 "p1life": 3,
 "p2life": 4
}
DATA = { "p1" : { "playerNick" : "", "playerID" : 0, "TimeSinceLastCall" : 0},
         "p2" : { "playerNick" : "", "playerID" : 0, "TimeSinceLastCall" : 0}}

def msg_from_game(comm):
	global Makieta
	client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	client_socket.connect(("127.0.0.1", 11000))
	client_socket.send(json.dumps(comm))
	Makieta = json.loads(client_socket.recv(1024).strip())

def player_exist(login_ID):
	global DATA
	if (DATA["p1"]["playerID"] == login_ID[1] and DATA["p2"]["playerID"] !=0) or (DATA["p2"]["playerID"] == login_ID[1] and DATA["p1"]["playerID"] != 0):
		#gracz istnieje
		return Retval.PLEXIST
	elif DATA["p1"]["playerNick"] == "":
		DATA["p1"] = { "playerNick" : login_ID[0], "playerID" : login_ID[1], "TimeSinceLastCall" : time.time()}
		return Retval.WAITFP2
	elif DATA["p2"]["playerNick"] == "":
		DATA["p2"] = { "playerNick" : login_ID[0], "playerID" : login_ID[1], "TimeSinceLastCall" : time.time()}
		return Retval.GAMESTART

def get_key(playerId):
	global DATA
	for key, value in DATA.iteritems():
		if value["playerID"] == playerId:
			return key

def msg_for_client(player):
	global Makieta
	com = {}
	com["p1"] = Makieta["p1"]
	com["p2"] = -1
	com["p1Table"] = Makieta["p1Table"]
	com["p2Table"] = Makieta["p2Table"]
	com[player +"Hand"] = Makieta[player + "Hand"]
	com["p1mana"] = Makieta["p1mana"]
	com["p2mana"] = Makieta["p2mana"]
	com["p1life"] = Makieta["p1life"]
	com["p2life"] = Makieta["p2life"]
	return com

def com_to_game(stanGry, turaGracza, ruchGracza, idKarty, idCelu): #byc moze zamienic na deepcopy tutaj mock up to jest makieta ktora dostaje od Pawla
	global DATA
	com = {}
	com["p1"] = DATA["p1"]["playerID"]
	com["p2"] = DATA["p2"]["playerID"]
	com["StanGry"] = stanGry
	com["TuraGracza"] = stanTury   # wypisuje co gracz chce zrobic chyba ze nie zmienia tury' lub z mockup biore
	com["RuchGracza"] = ruchGracza
	com["IdKarty"] = idKarty
	com["IdCelu"] = idCelu
	return com

def switch( dane_klient):
	global Makieta
	tup = dane_klient["playerNick"], dane_klient["playerID"]
	state = player_exist(tup)

	if state == Retval.WAITFP2:
		return msg_for_client(get_key(tup[1]))
	elif state == Retval.GAMESTART:
		#stworzenie gry, odebranie makiety i wytworzenie komunikatow
		msg_from_game(com_to_game("GAMESTART_TRUE", "","", -1, -1)) # mamy ustawiona aktualna makiete
		return msg_for_client(get_key(tup[1]))
	elif state == Retval.PLEXIST:
		if state[0] == -1 and state[1] == -1:
			#przeslanie odpowiedniemu graczowi widoku
			return msg_for_client(get_key(tup[1]))
		elif state[0] != -1 and state[1] == -1:
			#karta wylozona na stol
			msg_from_game(com_to_game(Makieta["StanGry"], Makieta["TuraGracza"],"THROW_CARD_ON_TABLE", dane_klient["cardID"], -1))
			return msg_for_client(get_key(tup[1]))
		else:
			#atak konkretnego przeciwnika na konkretna karte
			msg_from_game(com_to_game(Makieta["StanGry"], Makieta["TuraGracza"],"ATTACK", dane_klient["cardID"], -1))
			return msg_for_client(get_key(tup[1]))

class WSHandler(tornado.websocket.WebSocketHandler):
        def open(self):
                #self.callback = PeriodicCallback(self.send_msg,1000)
                #self.send_msg()
                #self.callback.start()
                return

        def send_msg(self):
            return
             #   self.write_message(msg_from_game())

        def on_message(self, message):

                jsonMessage = json.loads(message)
                
                jsonAnswer = {}
                jsonAnswer = switch(jsonMessage)
                
                #~ jsonAnswer = {}
                #~ jsonAnswer["playerNick"] = jsonMessage["playerNick"]
                #~ jsonAnswer["playerID"] = 1
                #~ jsonAnswer["enemyNick"] = "Alfons"
                #~ jsonAnswer["enemyID"] = 2

                self.write_message(json.dumps(jsonAnswer))
        

        def on_close(self):
                self.callback.stop()
        

application = tornado.web.Application([
    (r'/ws', WSHandler),
])

if __name__ == "__main__":
        http_server = tornado.httpserver.HTTPServer(application)
        http_server.listen(8888)
        tornado.ioloop.IOLoop.instance().start()
	
