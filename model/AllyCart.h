#ifndef ALLY_CART
#define ALLY_CART

#include "Cart.h"

class AllyCart: public Cart{
public:
	int health;
	bool status;

	AllyCart();
	~AllyCart();

};


#endif