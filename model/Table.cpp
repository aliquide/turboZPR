#include "Table.h"
#include "FactoryOfCards.h"
#include <boost/shared_ptr.hpp>

bool Table::throwCard(Player& player, int id_card){

	Card* card = new (Card);
	int position; //position of card with id_card in vector

	for(unsigned int i=0; i< player.cards_in_hand.size(); i++)
		if (player.cards_in_hand.at(i)->getIdOfCard() == id_card){
			card = player.cards_in_hand.at(i);
			position = i;
		}
	//if there was no card with id_card return (the card with this id is not in hand of player
	if(card->getIdOfCard() == 0)
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

//create deck, cards etc with unique ID
void Table::create(int player_A_id, int player_B_id){

	FactoryOfCards factory;
	std::cout<<__FILE__ << ":" << __LINE__ <<std::endl;
	player_A->setPlayerId(player_A_id);// ->setPlayerId(player_A_id);
	std::cout<<__FILE__ << ":" << __LINE__ <<std::endl;
	player_B->setPlayerId(player_B_id);
	std::cout<<__FILE__ << ":" << __LINE__ <<std::endl;
	//for example we create same deck for each player with 10 spell carts and 10 ally carts
	for (int i = 0; i < 20; i++){
		
		player_A->deck.push_back(factory.createCard("SPELL"));
		player_A->deck.at(i)->setIdOfCard(200+i);
		
		i++;
		player_A->deck.push_back(factory.createCard("MONSTER"));
		player_A->deck.at(i)->setIdOfCard(i);

		i--;
		player_B->deck.push_back(factory.createCard("SPELL"));
		player_B->deck.at(i)->setIdOfCard(200+i+1);
		
		i++;
		player_B->deck.push_back(factory.createCard("MONSTER"));
		player_B->deck.at(i)->setIdOfCard(i+1);
		
	}

	//we choose 3 cards to hand, it would be random or chosen by player later
	for (int i = 0; i < 3; i++){
		player_A->getCard();
		player_B->getCard();
	}
	
	return;
};

Table::Table(){
	player_A = boost::shared_ptr<Player>(new Player);
	player_B = boost::shared_ptr<Player>(new Player);
}

Table::~Table(){
}

bool Table::attack(Player& player, int id_card, int id_of_aim){
	
	Card* card = new (Card);
	int position = 0; //position of card with id_card in vector
	int position_of_aim = -1; //position of aim if it is a card
	int flag = 0;

	boost::shared_ptr<Player> opponent;
	//Player *opponent;

	//finding position of card which is used to attack in vector
	for(unsigned int i=0; i< player.cards_on_table.size(); i++)
		if (id_card == player.cards_on_table.at(i)->getIdOfCard()){
			card = player.cards_on_table.at(i);
			position = i;
	}

	//if there was no card with id_card return (the card with this id is not on table)
	if(card->getIdOfCard() == 0)
		return 0; //return 0 if function doesn't work properly

	player.setMana(player.getMana() - card->getCostOfMana());

	std::cout<<"DUPA"<<std::endl;
	if (player.getPlayerId() == this->player_A->getPlayerId()){
		opponent = player_B;
	}
	else if (player.getPlayerId() == this->player_B->getPlayerId()){
		opponent = player_A;
	}

	for(unsigned int i=0; i< opponent->cards_on_table.size(); i++)
		if(id_of_aim == opponent->cards_on_table.at(i)->getIdOfCard()){
			if(opponent->cards_on_table.at(i)->getTypeOfCard() == "MONSTER" ){
				AllyCard* acard = dynamic_cast<AllyCard*>(card);
				if (acard->getHealth() >= 0){
					acard->setHealth(acard->getHealth() + card->getInteraction());
				}
				std::cout<<"Zycie potwora: " <<acard->getHealth()<<std::endl;
			}
			else if (opponent->cards_on_table.at(i)->getTypeOfCard() == "SPELL"){
				position_of_aim = i;
			}
			flag=1;
		}

	if (id_of_aim == opponent->getPlayerId()){
		opponent->setHealth(opponent->getHealth() + card->getInteraction());
		flag=1;
	}

	if(flag == 0) //if we didn't find the card in vector return 0 and nothing happen
		return 0;

	if(position_of_aim != -1){
		opponent->cards_on_table.erase(opponent->cards_on_table.begin() + position_of_aim);
	}
	
	if (card->getTypeOfCard() == "MONSTER"){
		AllyCard* acard = dynamic_cast<AllyCard*>(card);
			if (acard->getHealth() <= 0)
				player.cards_on_table.erase(player.cards_on_table.begin()+position);		
		}
	else if (card->getTypeOfCard() == "SPELL"){ //if type of SPELL
		player.cards_on_table.erase(player.cards_on_table.begin()+position);
	}

	return 1; //return 1 when the attack was succesfull

};
