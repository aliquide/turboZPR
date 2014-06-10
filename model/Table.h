#ifndef TABLE
#define TABLE

#include <boost/shared_ptr.hpp>
#include <vector>
#include "Card.h"
#include "Player.h"
#include "Mockup.h"

/**
\brief Klasa Table reprezentuje stół gry na którym odbywa się rozgrywka.
\details Na stole rozgrywane są takie akcje jak: rzucenie karty na stół przez gracza, zaatakowanie przeciwnika czy, na początku gry,
utworzenie nowego stołu, nadanie ID graczom.
**/


class Table{
public:
	boost::shared_ptr<Player> player_A, player_B;

	bool throwCard(Player&, int);
	bool attack(Player&, int,int);
	void create(int, int);

	Table();
	~Table();
};


#endif
