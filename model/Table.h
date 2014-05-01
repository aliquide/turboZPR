#ifndef TABLE
#define TABLE

#include <cstdio>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "Card.h"
#include "Player.h"

class Table{
public:
	//int no_active_cart <- maybe?

	//smart_ptr
	std::vector<Card> cards_on_table;
	Player* player_1, * player_2;

	void useCard(Player&, int);
	void throwCard(Player&, int);
	void activateCard(Player&, int);

//protected:
	//Table();

};


#endif