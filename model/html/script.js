$(document).ready(function() {
  $("#table").hide();

  var playerNick = "";

  function gameStatus (playerHP, playerMP, enemyHP, enemyMP)
  {
    this.playerHP = playerHP;
    this.playerMP = playerMP;
    this.enemyHP = enemyHP;
    this.enemyMP = enemyMP;
  }

  function Card (name, image, description, attack, health) {
  	this.name = name;
  	this.image = image;
  	this.description = description;
  	this.attack = attack;
  	this.health = health;
  }

  var MAX_CARDS_ON_HAND = 8;
  var MAX_CARDS_ON_BOARD = 10;

  var monsterCard = new Card("Smoczysko", "images/monster1.jpg", "Straszny potwór", 6, 5);

  /*$("#cardsPlayerBoard").droppable({
    accept: function() {
      return $("#playerBoard").find("ul").find("li").size() < MAX_CARDS_ON_BOARD;
    },
    drop: function(event, ui) {
        (ui.draggable).css({"left": 0, "top": 0}).appendTo($("#playerBoard").find("ul"));
    }
  });*/

  $("#cardsPlayerBoard").on('click', '.card', function()
  {
    //alert("Player Board clicked");
    if($(this).hasClass("selected"))
      $(this).removeClass("selected");
    else
    {
      $(".selected").removeClass("selected");
      $(this).addClass("selected");
    }
    //$(".selected").parent("li").detach().appendTo('#cardsPlayerBoard');
    //$(".selected").removeClass("selected");
  });

  $('#playerHand').on('click', '.card', function()
  {
    //alert("Card clicked!");
    $(this).parent("li").detach().appendTo('#cardsPlayerBoard');
    
    //if()
    //$(".selected").removeClass("selected");
    //else if(!$("#playerBoard").hasClass("selected"))
    //  $(this).addClass("selected");
  });

  $('#cardsOpponentBoard')

  Card.prototype.displayCard = function(x) {

      var htmlCard = "<li><div class=\"card\">"
      htmlCard += "<h1 class=\"monsterName\">" + this.name + "</h1>"
      htmlCard += "<div class=\"monsterImgBorder\"><img class=\"monsterImg\" src=\"" + this.image + "\"></div>"
      htmlCard += "<div class=\"monsterDescription\">" + this.description + "</div>"
      htmlCard += "<div class=\"attackField\">" + this.attack + "</div>"
      htmlCard += "<div class=\"healthField\">" + this.health + "</div>"
      htmlCard += "</div></li>"

      if (x === 1)
  	   $("#playerCardList").append(htmlCard);
      else if (x === 2)
       $("#opponentCardList").append(htmlCard);
  }

  $("#start").click(function (){

    alert("in comunication()");

    var ws = new WebSocket("ws://localhost:8888/ws");

    ws.onopen = function(evt) { 
      alert("Connection open ...");
      playerNick = $('#nick').val();
      $('#playerNick').html(playerNick);

      $("#main").hide();

      $("#table").show();
    
      var jsonMessage = {
        "playerNick" : playerNick,
        "playerID" : -1,
        "cardID" : -1,
        "targetID": -1
      };

      ws.send(JSON.stringify(jsonMessage));
    };

    ws.onmessage = function(evt) {
      alert("Message: " + evt.data);
      var status = JSON.parse(evt.data);
      $('#enemyNick').html(status.enemyNick);
      monsterCard.displayCard(1);
      monsterCard.displayCard(1);
      monsterCard.displayCard(1);
      monsterCard.displayCard(2);
    }

    ws.onclose = function(evt) { 
          alert("Connection closed.");
    }
  });
});
