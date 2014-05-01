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
	Player *player_1, *player_2;

	void update(Table&,Player&);

};

#endif