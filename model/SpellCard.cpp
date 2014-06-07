#include "SpellCard.h"

SpellCard::SpellCard(){
	this->cost_of_mana = 1;
	this->interaction = -100;
	this->type_of_card = SPELL;
	this->id_of_card = 0;
};

const SpellCard& SpellCard::operator=(SpellCard card){
	this->cost_of_mana = card.cost_of_mana;
	this->interaction = card.interaction;
	this->type_of_card = SPELL;
	this->id_of_card = card.id_of_card;
	return *this;
}
