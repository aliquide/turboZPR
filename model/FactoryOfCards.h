#ifndef FACTORY_OF_CARDS
#define FACTORY_OF_CARDS

#include "Card.h"
#include "AllyCard.h"
#include "SpellCard.h"

class FactoryOfCards{
public:
	Card* createCard(TypeOfCard);
};



#endif