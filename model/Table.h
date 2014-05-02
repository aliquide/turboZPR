#ifndef TABLE
#define TABLE

#include <cstdio>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "Card.h"
#include "Player.h"

class Table{
public:
	//smart_ptr
	std::vector<Card*> cards_on_table;
	Player* player_1, * player_2;

	void useCard(Player&, int);
	void throwCard(Player&, int);
	void activateCard(int);

//protected:
	//Table();

};


#endif