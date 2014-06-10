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
#include <utility>


class Model{
public:
	Mockup mockup;
	Table table;

	void update(Player&);

	Model();
	Model(int, int);
	bool saveData();

	StateOfTour changed_state_tour;
	StateOfGame changed_state_game;
	PlayersMove changed_move;
};

#endif
