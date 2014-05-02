#include "Table.h"


void Table::useCard(Player& player, int i){
	Card* card = (cards_on_table.operator[](i));

	player.mana -= card->cost_of_mana;

	if (card->type_of_card == MONSTER){
		AllyCard* acard = dynamic_cast<AllyCard*>(card);
		if (acard->status == false)
			return;
	}

	if (&player == player_1){
		player_2->health += card->interaction;
	}
	else
	{
		player_1->health += card->interaction;
	}
	
};

void Table::throwCard(Player& player, int i){

	//if card is type of ally or spell we throw it on table and wait for action 
	this->cards_on_table.push_back(player.cards_in_hand.at(i));

	//we must get it from hand ofc
	player.cards_in_hand.erase(player.cards_in_hand.begin() + i);
};

void Table::activateCard(int i){ 

	Card* card = cards_on_table.at(i);

	if (card->type_of_card == MONSTER){
		AllyCard* acard = dynamic_cast<AllyCard*>(card);
		if (acard->status == false)
			acard->status = true;	
	}
	else
		return;

};