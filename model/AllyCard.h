#ifndef ALLY_CARD
#define ALLY_CARD

#include "Card.h"

class AllyCard: public Card{
public:
	int health;
	bool status;

	AllyCard();
	~AllyCard();

};


#endif