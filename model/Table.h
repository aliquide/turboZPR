#ifndef TABLE
#define TABLE

#include <cstdio>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "Card.h"
#include "Player.h"
#include "Mockup.h"

class Table{
public:
	//dodac destruktory i konstruktory odpowiednie
	Player* player_A, * player_B;

	bool throwCard(Player&, int);
	bool attack(Player&, int,int);
	void create(int, int);

//protected:
	Table();

};


#endif
