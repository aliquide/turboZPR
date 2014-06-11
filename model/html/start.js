$(document).ready(function() {

	var gameStarted = false;

	$("#start").click(function (){

	    var ws = new WebSocket("ws://localhost:8888/ws");

	    ws.onopen = function(evt) {
	    	alert("Communication opened!");
		    
			var status = {
				"playerNick" : $('#nick').val(),
				"playerID" : 2,
				"card" : -1,
				"target" : -1
			};
	    	alert("Sending message: " + JSON.stringify(status));
	    	ws.send(JSON.stringify(status));
	    }

	    ws.onmessage = function(evt) {
	    	var status = JSON.parse(evt.data);
	    	alert("Got message " + status.id);
	    }

	    ws.onclose = function(evt) { 
	    	alert("Communication closed!");
	    }

	});
});
