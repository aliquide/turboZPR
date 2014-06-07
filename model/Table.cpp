#include "Table.h"
#include "FactoryOfCards.h"

void Table::useCard(Player& player, int i){
	
	
	Card* card = new (Card);
	card = (player.cards_on_table.operator[](i));

	player.mana -= card->cost_of_mana;

	if (card->type_of_card == MONSTER){
		AllyCard* acard = dynamic_cast<AllyCard*>(card);
		if (acard->status == false)
			return;
	}

	if (&player == player_A){
		player_B->health += card->interaction;
	}
	else
	{
		player_A->health += card->interaction;
	}
	
};

void Table::throwCard(Player& player, int id_card){

	Card* card = new (Card);

	for(unsigned int i=0; i< player.cards_in_hand.size(); i++)
		if (player.cards_in_hand.at(i)->id_of_card == id_card)
			card = player.cards_in_hand.at(i);

	//if card is type of ally or spell we throw it on table and wait for action 
	player.cards_on_table.push_back(card);

	//we must get it from hand ofc
	for(unsigned int i=0; i< player.cards_in_hand.size(); i++)
		if (id_card == player.cards_in_hand.at(i)->id_of_card)
			player.cards_in_hand.erase(player.cards_in_hand.begin() + i);
};

void Table::activateCard(Player& player, int id_card){ 

	Card* card = new (Card);;

	for(unsigned int i=0; i< player.cards_on_table.size(); i++)
		if (id_card == player.cards_on_table.at(i)->id_of_card)
			card = player.cards_on_table.at(i);


	if (card->type_of_card == MONSTER){
		AllyCard* acard = dynamic_cast<AllyCard*>(card);
		if (acard->status == false)
			acard->status = true;	
	}
	else
		return;

};

void Table::create(std::string player_A_id, std::string player_B_id){

	FactoryOfCards factory;
	
	player_A->player_id= player_A_id;
	player_B->player_id= player_B_id;
	
	//for example we create same deck for each player with 10 spell carts and 10 ally carts
	for (int i = 0; i < 20; i++){
		
		player_A->deck.push_back(factory.createCard(SPELL));
		player_A->deck.at(i)->id_of_card = 200+i;
		
		i++;
		player_A->deck.push_back(factory.createCard(MONSTER));
		player_A->deck.at(i)->id_of_card = i;

		i--;
		player_B->deck.push_back(factory.createCard(SPELL));
		player_B->deck.at(i)->id_of_card = 200+i;
		
		i++;
		player_B->deck.push_back(factory.createCard(MONSTER));
		player_B->deck.at(i)->id_of_card = i;
		
	}

	//we choose 3 cards to hand, it would be random or chosen by player later
	for (int i = 0; i < 3; i++){
		player_A->getCard();
		player_B->getCard();
	}
	
	
	
	
	return;
};

Table::Table(){
	player_A = new (Player);
	player_B = new (Player);
}
