#ifndef ALLY_CARD
#define ALLY_CARD

#include "Card.h"

/**
\brief Klasa AllyCard reprezentuje obiekt kartę typu sojusznik/potwór.
\details Sojusznicy/potwory posiadają dodatkowo punkty życia. Aby karta tego typu zniknęła, należy pozbyć jej wszystkich punktów życia.
**/

class AllyCard: public Card {
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
