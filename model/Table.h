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
	std::vector<Card*> cards_on_table_player_A;
	std::vector<Card*> cards_on_table_player_B;
	
	Player* player_A, * player_B;

	void useCard(Player&, int);
	void throwCard(Player&, int);
	void activateCard(int);

	void create(String, String);
	
//protected:
	//Table();

};


#endif
