#ifndef PLAYER
#define PLAYER


#include <cstdio>
#include <cstdlib>
#include <vector>

#include "Cart.h"
#include "AllyCart.h"
#include "SpellCart.h"

enum Character{
	DRUID,
	PRIEST,
	HUNTER
};


class Player{
public:
	int mana;
	int health;

	Character type_;

	//smart pointers
	std::vector<Cart> carts_in_hand;
	std::vector<Cart> deck;

	Player();

	
	void getCart();

};


#endif