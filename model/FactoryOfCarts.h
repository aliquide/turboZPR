#ifndef FACTORY_OF_CARTS
#define FACTORY_OF_CARTS

#include "Cart.h"
#include "AllyCart.h"
#include "SpellCart.h"

class FactoryOfCarts{
public:
	Cart* createCart(TypeOfCart);
};



#endif