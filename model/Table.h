#ifndef TABLE
#define TABLE

#include <boost/shared_ptr.hpp>
#include <vector>
#include "Card.h"
#include "Player.h"
#include "Mockup.h"

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
