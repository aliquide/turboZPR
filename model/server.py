import socket
import tornado.httpserver
import tornado.websocket
import tornado.ioloop
from tornado.ioloop import PeriodicCallback
import tornado.web

def msg_from_game():
	client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	client_socket.connect(("127.0.0.1", 11000))
	client_socket.send('hello')
	return client_socket.recv(1024)

class WSHandler(tornado.websocket.WebSocketHandler):
        def open(self):
                self.callback = PeriodicCallback(self.send_msg,9000)
                self.send_msg()
                self.callback.start()

        def send_msg(self):
                self.write_message(msg_from_game())

        def on_message(self, message):
                self.write_message(message.upper())
        

        def on_close(self):
                self.callback.stop()
        

application = tornado.web.Application([
    (r'/', WSHandler),
])

if __name__ == "__main__":
        http_server = tornado.httpserver.HTTPServer(application)
        http_server.listen(8888)
        tornado.ioloop.IOLoop.instance().start()
	
