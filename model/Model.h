#ifndef MODEL
#define MODEL

#include "FactoryOfCards.h"
#include "Player.h"
#include "Table.h"
#include "Card.h"
#include "AllyCard.h"
#include "SpellCard.h"
#include "Mockup.h"

/**
    \brief Klasa Model odpowiedzialna jest za zarządzanie grą.
    \details Model zarządza odpowiednimi stanami gry, stołem oraz aktualizuje makietę.
 **/

class Model {
public:
	Mockup mockup;
	Table table;

	Model();
	Model(int, int);

	StateOfTour changed_state_tour;
	StateOfGame changed_state_game;
	PlayersMove changed_move;

	bool saveData();
};

#endif
