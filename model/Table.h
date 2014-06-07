#ifndef TABLE
#define TABLE

#include <cstdio>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "Card.h"
#include "Player.h"


class Table{
public:
	
	Player* player_A, * player_B;

	void useCard(Player&, int);
	void throwCard(Player&, int);
	void activateCard(Player&, int);

	void create(std::string, std::string);
	
//protected:
	//Table();

};


#endif
