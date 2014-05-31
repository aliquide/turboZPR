#ifndef MODEL
#define MODEL

#include "FactoryOfCards.h"
#include "Player.h"
#include "Table.h"
#include "Card.h"
#include "AllyCard.h"
#include "SpellCard.h"
#include "Mockup.h"




class Model{
public:
	
	Table table;

	void update(Player&);

	Model(String, String);

};

#endif
