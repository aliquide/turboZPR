import json
from json import JSONEncoder
import socket
import tornado.httpserver
import tornado.websocket
import tornado.ioloop
from tornado.ioloop import PeriodicCallback
import tornado.web

MockUp = {
    "pHP" : 5,
    "pMP" : 8    
}

def msg_from_game():
    return json.dumps(MockUp)

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
                jsonAnswer["playerNick"] = jsonMessage["playerNick"]
                jsonAnswer["playerID"] = 1
                jsonAnswer["enemyNick"] = "Alfons"
                jsonAnswer["enemyID"] = 2

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
	
