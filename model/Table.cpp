#include "Table.h"
#include "FactoryOfCards.h"
#include <sstream>

//poki co nie korzystamy z tego
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

bool Table::throwCard(Player& player, int id_card){

	Card* card = new (Card);
	int position; //position of card with id_card in vector

	for(unsigned int i=0; i< player.cards_in_hand.size(); i++)
		if (player.cards_in_hand.at(i)->id_of_card == id_card){
			card = player.cards_in_hand.at(i);
			position = i;
		}
	//if there was no card with id_card return (the card with this id is not in hand of player
	if(card->id_of_card == 0) 
		return 0;
	
	
	//if there is room for new card we throw it on table and wait for action 
	if(player.cards_on_table.size() < max_on_table )
		player.cards_on_table.push_back(card);
	else
		return 0;

	//we must get it from hand
	player.cards_in_hand.erase(player.cards_in_hand.begin() + position);

	return 1; //if everything gone well we return 1
};

//poki co nie korzystamy z tego
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

//create deck, cards etc with unique ID
void Table::create(int player_A_id, int player_B_id){

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
		player_B->deck.at(i)->id_of_card = 200+i+1;
		
		i++;
		player_B->deck.push_back(factory.createCard(MONSTER));
		player_B->deck.at(i)->id_of_card = i+1;
		
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

//sensowne jezeli zaklecie tez dziala tylko jesli jest klikniete przez gracza a tak to sobie moze lezec a stole
//dodac cel ataku i przerzucenie tury gracza
bool Table::attack(Player& player, int id_card, int id_of_aim){
	
	Card* card = new (Card);
	int position; //position of card with id_card in vector

	for(unsigned int i=0; i< player.cards_on_table.size(); i++)
		if (id_card == player.cards_on_table.at(i)->id_of_card){
			card = player.cards_on_table.at(i);
			position = i;
	}

	//if there was no card with id_card return (the card with this id is not on table)
	if(card->id_of_card == 0)
		return 0; //return 0 if function doesn't work properly

	player.mana -= card->cost_of_mana;

	int flag = 0;



	//tutaj DODANIE CELU ATAKU

	if (&player == player_A){

		for(unsigned int i=0; i< player_B->cards_on_table.size(); i++)
			if(id_of_aim == player_B->cards_on_table.at(i)->id_of_card){
				if(player_B->cards_on_table.at(i)->type_of_card == MONSTER ){
					AllyCard* acard = dynamic_cast<AllyCard*>(card);
					if (acard->health >= 0)
						acard->health += card->interaction;
					flag=1;
				}
			}

		if (id_of_aim == player_B->player_id){
				player_B->health += card->interaction;
				flag=1;
		}

		if(flag == 0)
			return 0;

	}
	else if (&player == player_B)
	{
		for(unsigned int i=0; i< player_A->cards_on_table.size(); i++)
			if(id_of_aim == player_A->cards_on_table.at(i)->id_of_card){
				if(player_A->cards_on_table.at(i)->type_of_card == MONSTER ){
					AllyCard* acard = dynamic_cast<AllyCard*>(card);
					if (acard->health >= 0)
						acard->health += card->interaction;
					flag=1;
				}
			}

		if (id_of_aim == player_A->player_id){
				player_A->health += card->interaction;
				flag=1;
		}

		if(flag == 0)
			return 0;
	}
	
	if (card->type_of_card == MONSTER){
		AllyCard* acard = dynamic_cast<AllyCard*>(card);
			if (acard->health <= 0)
				player.cards_on_table.erase(player.cards_on_table.begin()+position);		
		}
	else if (card->type_of_card == SPELL){ //if type of SPELL
		player.cards_on_table.erase(player.cards_on_table.begin()+position);
	}

	return 1; //return 1 when the attack was succesfull

};
