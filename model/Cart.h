#ifndef CART
#define CART

enum TypeOfCart{
	MONSTER,
	SPELL
};

class Cart{
public:

	TypeOfCart type_of_cart;
	int interaction;
	int cost_of_mana;

//protected:
	//Cart();
	//~Cart();


};


#endif