#ifndef PLAYER
#define PLAYER


#include <cstdio>
#include <cstdlib>
#include <vector>

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
	String player_id;

	Character type_;

	//smart pointers
	std::vector<Card*> cards_in_hand;
	std::vector<Card*> deck;

	Player();
	
	void getCard();

};


#endif
