#ifndef MODEL
#define MODEL
#include <cstring>
#include "FactoryOfCards.h"
#include "Player.h"
#include "Table.h"
#include "Card.h"
#include "AllyCard.h"
#include "SpellCard.h"
#include "Mockup.h"


enum PlayersMove{
	THROW_CARD_ON_TABLE,
	ATTACK,
	GET_CARD
	
	
	
};


class Model{
public:
	
	Table table;

	void update(Player&);

	Model(std::string, std::string);

};

#endif
