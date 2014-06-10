#ifndef MODEL
#define MODEL

#include "FactoryOfCards.h"
#include "Player.h"
#include "Table.h"
#include "Card.h"
#include "AllyCard.h"
#include "SpellCard.h"
#include "Mockup.h"
#include "Communication.h"

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
	Mockup makeAttack(Player&, Communication);
	Mockup throwingCard(Player&, Communication);
	Mockup gettingCard(Player&, Communication);
	Mockup gettingStart(Communication communication);
	Mockup endingGame();
};

#endif
