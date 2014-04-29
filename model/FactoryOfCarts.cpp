#include "FactoryOfCarts.h"


Cart* FactoryOfCarts::createCart(TypeOfCart type_){
	if (type_ == MONSTER)
		return new AllyCart();
	else if (type_ == SPELL)
		return new SpellCart();
	else
		return new Cart();
}
