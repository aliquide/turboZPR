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
	
	Player* player_A, * player_B;

	void useCard(Player&, int);
	bool throwCard(Player&, int);
	void activateCard(Player&, int);

	bool attack(Player&, int);
	void create(std::string, std::string);
	

	
//protected:
	Table();

};


#endif
