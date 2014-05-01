#include "Player.h"


Player::Player(){
	this->mana = 20;
	this->health = 2000;
}


void Player::getCart(){
	Cart cart_temp;
	cart_temp = deck.back();
	deck.pop_back();
	carts_in_hand.push_back(cart_temp);
};