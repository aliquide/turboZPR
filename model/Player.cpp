#include "Player.h"


Player::Player(){
	this->mana = 20;
	this->health = 2000;
}

void Player::getCard(){
	Card* card_temp;
	card_temp = deck.back();
	deck.pop_back();
	cards_in_hand.push_back(card_temp);
};