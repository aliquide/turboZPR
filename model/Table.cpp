#include <boost/shared_ptr.hpp>
#include "Table.h"
#include "FactoryOfCards.h"

/// \brief Funkcja throwCard odpowiedzialna jest za przerzucanie karty na stół (z ręki na stół przez danego gracza).
/// \param player określa który gracz wykonuje akcję, \param id_card identyfikuję którą kartę rzucamy z ręki danego gracza na stół.
/// \return funkcja zwraca 1 w przypadku prawidłowego przeprowadzenia akcji oraz 0 w przyapdku nieprawidłowego przeprowadzenia akcji (np.brak karty w ręku gracza).
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

/// \brief Funkcja create odpowiedzialna jest za tworzenie talii dla graczy oraz dobranie 3 kart do ręki.
/// \param player_A_id identyfikuje gracza A, \param player_B_id identyfikuje gracza B.
void Table::create(int player_A_id, int player_B_id){

	FactoryOfCards factory;

	player_A->setPlayerId(player_A_id);
	player_B->setPlayerId(player_B_id);

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
}

/// \brief Konstruktor bezargumentowy dba o prawidłowe tworzenie sprytnych wskaźników.
Table::Table(){
	player_A = boost::shared_ptr<Player>(new Player);
	player_B = boost::shared_ptr<Player>(new Player);
}

/// \brief Destruktor
Table::~Table(){
}

/// \brief Funkcja attack odpowiedzialna jest za przeprowadzenie akcji ofensywnej na przeciwnym graczu lub karcie.
/// \param player identyfikuje gracza rozgrywajacego \param id_card identyfikuje kartę rozgrywającą \param id_of_aim identyfikuje cel ataku
/// \return zwraca 1 w przypadku prawidłowo przeprowadzonego ataku, 0 w przeciwnym wypadku.
bool Table::attack(Player& player, int id_card, int id_of_aim){
	
	Card* card = new (Card);
	int position = -1; //position of card with id_card in vector
	int position_of_aim = -1; //position of aim if it is a card
	int flag = 0; //flag which would be helpful

	boost::shared_ptr<Player> opponent;

	//finding position of card which is used to attack in vector
	for(unsigned int i=0; i< player.cards_on_table.size(); i++)
		if (id_card == player.cards_on_table.at(i)->getIdOfCard()){
			card = player.cards_on_table.at(i);
			position = i;
	}

	//if there was no card with id_card return (the card with this id is not on table)
	if(position == -1)
		return 0; //return 0 if function doesn't work properly

	//we must know which one of player, in our model, is the opponent
	if (player.getPlayerId() == this->player_A->getPlayerId()){
		opponent = player_B;
	}
	else if (player.getPlayerId() == this->player_B->getPlayerId()){
		opponent = player_A;
	}

	//looking for object which is identified by id_of_aim
	for(unsigned int i=0; i< opponent->cards_on_table.size(); i++)
		if(id_of_aim == opponent->cards_on_table.at(i)->getIdOfCard()){
			if(opponent->cards_on_table.at(i)->getTypeOfCard() == "MONSTER" ){
				AllyCard* acard = dynamic_cast<AllyCard*>(card);
				if (acard->getHealth() >= 0){
					acard->setHealth(acard->getHealth() + card->getInteraction());
				}
			}
			else if (opponent->cards_on_table.at(i)->getTypeOfCard() == "SPELL"){
				position_of_aim = i;
			}
			flag=1;
		}

	if (id_of_aim == opponent->getPlayerId()){
		if(opponent->getHealth() > 0)
			opponent->setHealth(opponent->getHealth() + card->getInteraction());

		flag=1;
	}

	if(flag == 0) //if we didn't find the card in vector and aim wasn't opponent return 0 and nothing happen
		return 0;

	//if aim is card we is card which is type of SPELL we erase it
	if(position_of_aim != -1){
		opponent->cards_on_table.erase(opponent->cards_on_table.begin() + position_of_aim);
	}
	
	//for cards type of MONSTER we must check if it have health to live or just disappear after using
	if (card->getTypeOfCard() == "MONSTER"){
		AllyCard* acard = dynamic_cast<AllyCard*>(card);
			if (acard->getHealth() <= 0)
				player.cards_on_table.erase(player.cards_on_table.begin()+position);		
		}
	else if (card->getTypeOfCard() == "SPELL"){ //if type of SPELL it always disappear after using
		player.cards_on_table.erase(player.cards_on_table.begin()+position);
	}

	//every attack cost mana
	player.setMana(player.getMana() - card->getCostOfMana());
	return 1; //return 1 when the attack was succesfull
}
