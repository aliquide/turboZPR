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
	std::vector<Card*> cards_on_table;
	std::vector<Card*> cards_in_hand;
	std::vector<Card*> deck;
	
	Player();
	
	bool getCard();
	int getPlayerId();
	int getHealth();
	int getMana();
	Character getCharacter();

	void setPlayerId(int);
	void setHealth(int);
	void setMana(int);
	void setCharacter(Character);

protected:
	int mana;
	int health;
	int player_id;
	Character type_;

};


#endif
