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

/**
  	  \brief Klasa Player reprezentuje gracza.
  	  \details Gracz posiada karty w ręku, karty na stole oraz talię kart. Gracza identyfikujemy po jego indywidualnym ID.
 **/

enum Character {
	DRUID, PRIEST, HUNTER
};

class Player {
public:
	std::vector<Card*> cards_on_table;
	std::vector<Card*> cards_in_hand;
	std::vector<Card*> deck;

	Player();
	~Player();

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
