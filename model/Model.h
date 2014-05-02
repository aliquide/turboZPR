#ifndef MODEL
#define MODEL

#include "FactoryOfCards.h"
#include "Player.h"
#include "Table.h"
#include "Card.h"
#include "AllyCard.h"
#include "SpellCard.h"


class Model{
public:
	
	Table table;

	void update(Player&);

};

#endif