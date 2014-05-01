#include "Table.h"

Table* Table::copy = 0;

Table* Table::Copy(){
	if (copy == 0) {
		copy = new Table;
	}
	return copy;
}

void Table::useCart(Player& player, int i){
	Cart cart = player.carts_in_hand.operator[](i);

	player.mana -= cart.cost_of_mana;

	if (cart.type_of_cart == MONSTER){
		Cart *cast = &cart;
		AllyCart* acart = static_cast<AllyCart*>(cast);
		if (acart->status == false)
			return;
	}

	if (&player == player_1){
		player_2->health += cart.interaction;
	}
	else
	{
		player_1->health += cart.interaction;
	}
	
};

void Table::throwCart(Player& player, int i){
	
	Cart& cart = player.carts_in_hand.operator[](i);

	//if cart is type of spell, we use it and forget about it
	if (cart.type_of_cart == SPELL){
		useCart(player, i);
	}
	else { //if cart is type of ally we throw it on table and wait for action 
		this->carts_on_table.push_back(cart);
	}
	//we must get it from hand ofc
	player.carts_in_hand.erase(player.carts_in_hand.begin() + i);
};