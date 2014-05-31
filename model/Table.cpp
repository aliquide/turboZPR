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

void Table::create(String player_A_id, String player_B_id){

	FactoryOfCards factory;
	
	player_A->player_id= player_A_id;
	player_B->player_id= player_B_id;
	
	//for example we create same deck for each player with 10 spell carts and 10 ally carts
	for (int i = 0; i < 10; i++){
		player_A->deck.push_back(factory.createCard(SPELL));
		player_A->deck.push_back(factory.createCard(MONSTER));

		player_B->deck.push_back(factory.createCard(SPELL));
		player_B->deck.push_back(factory.createCard(MONSTER));
	}

	//we choose 3 carts to hand, it would be random or chosen by player later
	for (int i = 0; i < 3; i++){
		player_A->getCard();
		player_B->getCard();
	}
	
	return;
};
