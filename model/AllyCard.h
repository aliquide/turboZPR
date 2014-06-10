#ifndef ALLY_CARD
#define ALLY_CARD

#include "Card.h"

class AllyCard: public Card{
public:

	const AllyCard& operator=(AllyCard);

	int getHealth();
	void setHealth(int);

	AllyCard();
	~AllyCard();

private:
	int health;

};


#endif
