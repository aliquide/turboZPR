#include "Card.h"

int Card::getIdOfCard(){
	return this->id_of_card;
};

std::string Card::getTypeOfCard(){
	return this->type_of_card;
};

int Card::getInteraction(){
	return this->interaction;
};

int Card::getCostOfMana(){
	return this->cost_of_mana;
};

void Card::setIdOfCard(int new_id){
	this->id_of_card = new_id;
}

void Card::setInteraction(int new_interaction){
	this->interaction = new_interaction;
}

void Card::setCostOfMana(int new_cost){
	this->cost_of_mana = new_cost;
}
