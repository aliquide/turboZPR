#include "Player.h"

void Player::hit(Player& ofiara, Cart karta){
	ofiara.health += karta.interaction;
	carts_in_hand.pop_back();
}

void Player::getCart(){
	Cart cart_temp;
	cart_temp = deck.back();
	deck.pop_back();
	carts_in_hand.push_back(cart_temp);
};