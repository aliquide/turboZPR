#ifndef ALLY_CARD
#define ALLY_CARD

#include "Card.h"

class AllyCard: public Card{
public:
	int health;
	bool status;

	const AllyCard& operator=(AllyCard);

	AllyCard();
	~AllyCard();

};


#endif
