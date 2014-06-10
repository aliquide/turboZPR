$(document).ready(function() {
  $("#table").hide();

  var playerNick = "";
  var playerID = (new Date().getTime());
  var opponentID = -1;
  var lastStatus = "";
  var callback;
  var idleMessage;
  var ws;

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

  var monsterCard = new Card("MONSTER", "images/monster1.jpg", "TERRIBLE MONSTER", 6, 5);

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

  $("#")
  $("#cardsOpponentBoard").on('click', '.card', function()
  {
    alert("Card: " + $(".selected").attr('id') + "\nTarget: " + $(this).attr('id'));
    if($(".selected").length > 0 && lastStatus.TuraGracza === playerID
      && lastStatus.RuchGracza === "ATTACK")
    {
      var message = {
          "playerNick" : playerNick,
          "playerID" : playerID,
          "cardID" : $(".selected").attr('id'),
          "targetID": $(this).attr('id')
        };

      ws.send(JSON.stringify(message));
    }
  });

  $("#opponentImage").click(function(){
    alert("Attacking other player!");
    if($(".selected").length > 0 && lastStatus.TuraGracza === playerID
      && lastStatus.RuchGracza === "ATTACK")
    {
      var message = {
          "playerNick" : playerNick,
          "playerID" : playerID,
          "cardID" : $(".selected").attr('id'),
          "targetID": opponentID
        };

      ws.send(JSON.stringify(message));
    }
  });

  $('#playerHand').on('click', '.card', function()
  {
    //alert("Card clicked!");
    if(lastStatus.TuraGracza === playerID
      && lastStatus.RuchGracza === "THROW_CARD_ON_TABLE")
    {
        var message = {
          "playerNick" : playerNick,
          "playerID" : playerID,
          "cardID" : $(this).attr('id'),
          "targetID": -1
        };
        ws.send(JSON.stringify(message)); 
    }
    //$(this).parent("li").detach().appendTo('#cardsPlayerBoard');
    
  });

  $('#cardsOpponentBoard')

  Card.prototype.displayCard = function(where, id, hp, att) {

      var htmlCard = "<li><div class=\"card\" id=\"" + id +"\">"
      htmlCard += "<h1 class=\"monsterName\">" + this.name + "</h1>"
      htmlCard += "<div class=\"monsterImgBorder\"><img class=\"monsterImg\" src=\"" + this.image + "\"></div>"
      htmlCard += "<div class=\"monsterDescription\">" + this.description + "</div>"
      htmlCard += "<div class=\"attackField\">" + att + "</div>"
      htmlCard += "<div class=\"healthField\">" + hp + "</div>"
      htmlCard += "</div></li>"

      switch(where)
      {
        case 1: // player Hand
          $("#playerCardList").append(htmlCard);
          break;
        case 2: // player Board
          $("#cardsPlayerBoard").append(htmlCard);
          break;
        case 3: // opponent Hand
          $("#opponentCardList").append(htmlCard);
          break;
        case 4: // opponent Board
          $("#cardsOpponentBoard").append(htmlCard);
          break;

      }
  }

  $("#start").click(function (){

    alert("in comunication()");

    ws = new WebSocket("ws://localhost:8888/ws");

    ws.onopen = function(evt) { 
      alert("Connection open ...");
      playerNick = $('#nick').val();
      $('#playerNick').html(playerNick);

      $("#main").hide();

      $("#table").show();
    
      callback = setInterval(function()
      {
        idleMessage = {
          "playerNick" : playerNick,
          "playerID" : playerID,
          "cardID" : -1,
          "targetID": -1
        };

         ws.send(JSON.stringify(idleMessage));
      }, 3000);
    };

    ws.onmessage = function(evt) {
      //alert("Message: " + lastStatus + " " + evt.data);
      var status = JSON.parse(evt.data);

      $('#enemyNick').html(status.enemyNick);
      
      // SETTING EVERYTHING HERE!!!
      if(JSON.stringify(status) !== JSON.stringify(lastStatus))
      {
        if(status.p2 == -1)
          $("#gameStatus").html("Waiting for another player... ");
        else
        {
          if(status.TuraGracza == playerID)
          {
            if(status.RuchGracza == "THROW_CARD_ON_TABLE")
              $("#gameStatus").html("Throw card on table... ");
            else if(status.RuchGracza == "ATTACK")
              $("#gameStatus").html("Attack... ");
          } else {
            $("#gameStatus").html("Opponent turn!");
          }

          if(playerID === status.p1) {
            opponentID = status.p2;
            $('#enemyHP').html(status.lifep2);
            $('#enemyMP').html(status.manap2);
            $('#playerHP').html(status.lifep1);
            $('#playerMP').html(status.manap1);
          } else {
            opponentID = status.p1;
            $('#enemyHP').html(status.lifep1);
            $('#enemyMP').html(status.manap1);
            $('#playerHP').html(status.lifep2);
            $('#playerMP').html(status.manap2);
          }

          $("#enemyNick").html(status.opponentNick);

          $(".card").remove();

          for(var i = 0; i < 5; i ++ )
          {
            if(status.p1 === playerID)
            {
              monsterCard.displayCard(1, status.p1Hand[i].Id, status.p1Hand[i].HP, status.p1Hand[i].att);
              monsterCard.displayCard(2, status.p1Table[i].Id, status.p1Table[i].HP, status.p1Table[i].att);
              monsterCard.displayCard(3, status.p2Hand[i].Id, status.p2Hand[i].HP, status.p2Hand[i].att);
              monsterCard.displayCard(4, status.p2Table[i].Id, status.p2Table[i].HP, status.p2Table[i].att);
            } else
            {
              monsterCard.displayCard(3, status.p1Hand[i].Id, status.p1Hand[i].HP, status.p1Hand[i].att);
              monsterCard.displayCard(4, status.p1Table[i].Id, status.p1Table[i].HP, status.p1Table[i].att);
              monsterCard.displayCard(1, status.p2Hand[i].Id, status.p2Hand[i].HP, status.p2Hand[i].att);
              monsterCard.displayCard(2, status.p2Table[i].Id, status.p2Table[i].HP, status.p2Table[i].att);
          }


        }
        lastStatus = status;
      }
    }

    ws.onclose = function(evt) { 
          alert("Connection closed.");
    }


  });
});
