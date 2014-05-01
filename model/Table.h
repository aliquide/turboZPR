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
	//int no_active_cart <- maybe?
	static Table* Copy();
	//smart_ptr
	std::vector<Cart> carts_on_table;
	Player* player_1, * player_2;

	void useCart(Player&, int);
	void throwCart(Player&, int);

protected:
	//Table();
		
private:
	static Table *copy;
};


#endif