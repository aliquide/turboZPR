#include "Player.h"


Player::Player(){
	
	this->mana = 20;
	this->health = 2000;
}

void Player::getCard(){
	
	Card* card_temp = new (Card);
	card_temp = deck.back();
	cards_in_hand.push_back(card_temp);
	deck.pop_back();
	
};
