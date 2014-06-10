#include "AllyCard.h"

AllyCard::AllyCard(){
	this->cost_of_mana = 2;
	this->health = 1000;
	this->interaction = -200;
	this->type_of_card = "MONSTER";
	this->id_of_card = 0;
};

const AllyCard& AllyCard::operator=(AllyCard card){
	this->cost_of_mana = card.cost_of_mana;
	this->health = card.health;
	this->interaction = card.interaction;
	this->type_of_card ="MONSTER";
	this->id_of_card = card.id_of_card;
	return *this;
}

void AllyCard::setHealth(int new_health){
	this->health = new_health;
};

int AllyCard::getHealth(){
	return this->health;
};
