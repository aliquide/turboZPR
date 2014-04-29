#ifndef TABLE
#define TABLE

#include <cstdio>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "Cart.h"
#include "Player.h"

//singleton - only one table in game
class Table{
public:

	static Table* Copy();
	//smart_ptr
	std::vector<Cart> carts_on_table;
	Player* player_1, * player_2;

protected:
	//Table();
		
private:
	static Table *copy;
};


#endif