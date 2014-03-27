$(document).ready(function() {

  function Card (name, image, description, attack, health) {
  	this.name = name;
  	this.image = image;
  	this.description = description;
  	this.attack = attack;
  	this.health = health;
  }

  var MAX_CARDS_ON_HAND = 8;
  var MAX_CARDS_ON_BOARD = 5;

  var monsterCard = new Card("Smoczysko", "images/monster1.jpg", "Straszny potwór", 6, 5);

  $("#cardsPlayerBoard").droppable();

  Card.prototype.displayCard = function(x) {

    if(($("#playerCardList li").size() != MAX_CARDS_ON_HAND && x === 1 ) || ($("#opponentCardList li").size() != MAX_CARDS_ON_HAND && x === 2 )) {

      var htmlCard = "<li class=\"draggable\"><div><div class=\"card\">"
      htmlCard += "<h1 class=\"monsterName\">" + this.name + "</h1>"
      htmlCard += "<div class=\"monsterImgBorder\"><img class=\"monsterImg\" src=\"" + this.image + "\"></div>"
      htmlCard += "<div class=\"monsterDescription\">" + this.description + "</div>"
      htmlCard += "<div class=\"attackField\">" + this.attack + "</div>"
      htmlCard += "<div class=\"healthField\">" + $("#playerCardList li").size() + "</div>"
      htmlCard += "</div></div></li>"

      if (x === 1)
  	   $("#playerCardList").append(htmlCard);
      else if (x === 2)
       $("#opponentCardList").append(htmlCard);
    }
  	$(".draggable").draggable({stack: "div", revert: "invalid"});
  }

  $("#addCard1").click(function () { monsterCard.displayCard(1); });
  $("#addCard2").click(function () { monsterCard.displayCard(2); });
});
