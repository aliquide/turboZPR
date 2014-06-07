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

//STan tury
enum PlayersMove{
	THROW_CARD_ON_TABLE,
	ATTACK,
	GET_CARD,
	END_OF_TOUR	
};


class Model{
public:
	Mockup mockup;
	Table table;

	void update(Player&);

	Model(std::string, std::string);
	
};

#endif
