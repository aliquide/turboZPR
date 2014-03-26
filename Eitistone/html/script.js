$(document).ready(function() {

  function Card (name, image, description, attack, health) {
  	this.name = name;
  	this.image = image;
  	this.description = description;
  	this.attack = attack;
  	this.health = health;
  }

  var monsterCard = new Card("Smoczysko", "images/monster1.jpg", "Straszny potwór", 6, 5);

  Card.prototype.displayCard = function() {
  	var htmlCard = "<div class=\"draggable\"><div class=\"card\">"
  	htmlCard += "<h1 class=\"monsterName\">" + this.name + "</h1>"
  	htmlCard += "<div class=\"monsterImgBorder\"><img class=\"monsterImg\" src=\"" + this.image + "\"></div>"
  	htmlCard += "<div class=\"monsterDescription\">" + this.description + "</div>"
  	htmlCard += "<div class=\"attackField\">" + this.attack + "</div>"
  	htmlCard += "<div class=\"healthField\">" + this.health + "</div>"
  	htmlCard += "</div></div>"

  	$("#playerHand").append(htmlCard);
  	$(".draggable").draggable({stack: "div"});
  }

  $("#addCard").click(function () { monsterCard.displayCard(); });
});
