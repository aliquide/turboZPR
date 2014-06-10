#include "Player.h"
#include "Mockup.h"

Player::Player(){
	
	this->mana = 20;
	this->health = 2000;
}

bool Player::getCard(){
	
	Card* card_temp = new (Card);
	
	if(this->cards_in_hand.size() < max_in_hand){
		card_temp = this->deck.back();
		this->cards_in_hand.push_back(card_temp);
		this->deck.pop_back();
		return 1;
	}
	else
		return 0;
};

int Player::getPlayerId(){
	return this->player_id;
};

int Player::getHealth(){
	return this->health;
};

int Player::getMana(){
	return this->mana;
};

void Player::setPlayerId(int new_id){
	this->player_id = new_id;
}

void Player::setMana(int new_mana){
	this->mana = new_mana;
}

void Player::setHealth(int new_health){
	this->health = new_health;
}
