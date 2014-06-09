#ifndef PLAYER
#define PLAYER


//#include <cstdio>
//#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <map>

#include "Card.h"
#include "AllyCard.h"
#include "SpellCard.h"

enum Character{
	DRUID,
	PRIEST,
	HUNTER
};


class Player{
public:
	int mana;
	int health;

	int player_id;

	Character type_;

	//smart pointers
	std::vector<Card*> cards_on_table;
	std::vector<Card*> cards_in_hand;
	std::vector<Card*> deck;
	
	//std::map<int, Card*> cards_on_table;
	//std::map<int, Card*> cards_in_hand;
	//std::map<int, Card*> deck;
	
	
	Player();
	
	bool getCard();

};


#endif
