#include "Player.h"
#include "Mockup.h"

/// \brief Konstruktor bezargumentowy nadaje początkowe wartości składowych gracza.
Player::Player() {
	this->player_id = 0;
	this->type_ = DRUID;
	this->mana = 20;
	this->health = 2000;
}

/// \brief destruktor dba o prawidłowe zwolnienie pamięci dla kontenerów przechowujących wskaźniki na karty
Player::~Player() {
	for (unsigned int i = 0; i < cards_on_table.size(); i++)
		delete cards_on_table.at(i);

	for (unsigned int i = 0; i < cards_in_hand.size(); i++)
		delete cards_in_hand.at(i);

	for (unsigned int i = 0; i < deck.size(); i++)
		delete deck.at(i);
}

/// \brief Metoda getCard() dobiera kartę z talii do ręki.
/// \return zwraca 1 w przypadku prawidłowego przeprowadzenia akcji dobierania do ręki (nie przekracza maksymalnego zakresu itp)
bool Player::getCard() {
	if (this->cards_in_hand.size() < max_in_hand) {
		Card* card_temp = new (Card);
		card_temp = this->deck.back();
		this->cards_in_hand.push_back(card_temp);
		this->deck.pop_back();
		return 1;
	} else
		return 0;
}

int Player::getPlayerId() {
	return this->player_id;
}

int Player::getHealth() {
	return this->health;
}

int Player::getMana() {
	return this->mana;
}

void Player::setPlayerId(int new_id) {
	this->player_id = new_id;
}

void Player::setMana(int new_mana) {
	this->mana = new_mana;
}

void Player::setHealth(int new_health) {
	this->health = new_health;
}
