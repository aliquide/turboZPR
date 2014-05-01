#include "Table.h"


void Table::useCard(Player& player, int i){
	Card& card = *(player.cards_in_hand.operator[](i));

	player.mana -= card.cost_of_mana;
	std::cout <<"mana w usecard: "<< player.cards_in_hand.operator[](i)->cost_of_mana << std::endl;

	if (card.type_of_card == MONSTER){
		AllyCard& acard = dynamic_cast<AllyCard&>(card);
		if (acard.status == false)
			return;
	}

	if (&player == player_1){
		player_2->health += card.interaction;
	}
	else
	{
		player_1->health += card.interaction;
	}
	
};

void Table::throwCard(Player& player, int i){
	
	Card& card = *player.cards_in_hand.operator[](i);

	//if card is type of ally or spell we throw it on table and wait for action 
	this->cards_on_table.push_back(card);

	//we must get it from hand ofc
	player.cards_in_hand.erase(player.cards_in_hand.begin() + i);
};

void Table::activateCard(Player& player, int i){ //tutaj nie dziala cos

	Card& card = *player.cards_in_hand.operator[](i);

	if (card.type_of_card == MONSTER){
		AllyCard& acard = dynamic_cast<AllyCard&>(card);
		if (acard.status == false)
			acard.status = true;
		player.cards_in_hand.operator[](i) = &static_cast<Card&>(acard);
		
	}
	else
		return;

};