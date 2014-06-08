#include "Player.h"
#include <cstdio>
#include <iostream>

Player::Player(){
	
	this->mana = 20;
	this->health = 2000;
}

void Player::getCard(){
	
	Card* card_temp = new (Card);
	card_temp = this->deck.back();
	std::cout<<"w getcard: "<<card_temp->id_of_card<<std::endl;
	this->cards_in_hand.push_back(card_temp);
	this->deck.pop_back();
	
};
