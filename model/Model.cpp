#include "Model.h"
#include <utility>

/// \brief Konstruktor argumentowy tworzy z odpowiednimi id stół dla graczy
/// \param id_player_a oraz \param id_player_b określają identyfikatory graczy
Model::Model(int id_player_a, int id_player_b) {
	table.create(id_player_a, id_player_b);
}

/// \brief Konstruktor bezargumentowy nie tworzy nowego stołu gry, jest to zbędne gdy nie posiadamy id graczy
Model::Model() {
}

/// \brief Funkcja saveData zapisuje zmiany stanów do makiety wysyłanej serwerowi
/// \return zwraca 1 w przypadku prawidłowego zapisu
bool Model::saveData() {

	for (unsigned int i = 0; i < max_on_table; i++) {
		mockup.cards_on_table_player_A[i].setIdOfCard(0);
		mockup.cards_on_table_player_B[i].setIdOfCard(0);
	}
	for (unsigned int i = 0; i < max_in_hand; i++) {
		mockup.cards_in_hand_player_A[i].setIdOfCard(0);
		mockup.cards_in_hand_player_B[i].setIdOfCard(0);
	}

	for (unsigned int i = 0; i < max_in_hand && i < table.player_A->cards_in_hand.size(); i++) {
		mockup.cards_in_hand_player_A[i] = *table.player_A->cards_in_hand.at(i);
	}
	for (unsigned int i = 0; i < max_on_table && i < table.player_A->cards_on_table.size(); i++) {
		mockup.cards_on_table_player_A[i] = *table.player_A->cards_on_table.at(i);
	}

	for (unsigned int i = 0; i < max_on_table && i < table.player_B->cards_on_table.size(); i++) {
		mockup.cards_on_table_player_B[i] = *table.player_B->cards_on_table.at(i);
	}

	for (unsigned int i = 0; i < max_in_hand && i < table.player_B->cards_in_hand.size(); i++) {
		mockup.cards_in_hand_player_B[i] = *table.player_B->cards_in_hand.at(i);
	}

	mockup.actual_state_of_tour = this->changed_state_tour;
	mockup.actual_state_of_game = this->changed_state_game;
	mockup.actual_move = this->changed_move;
	mockup.id_player_A = this->table.player_A->getPlayerId();
	mockup.id_player_B = this->table.player_B->getPlayerId();
	
	mockup.mana_player_A = this->table.player_A->getMana();
	mockup.mana_player_B = this->table.player_B->getMana();
	
	mockup.health_player_A = this-> table.player_A->getHealth();
	mockup.health_player_B = this-> table.player_B->getHealth();
	
	return 1;
}

/// \brief Funkcja makeAttack odpowiedzialna za przeprowadzenie ataku
/// \return zwraca zaktualizowana makiete danych
Mockup Model::makeAttack(Player& actual_player, Communication communication){
	
	bool state = 0;
	
	state = table.attack(actual_player, communication.id_card, communication.id_of_aim);

	//if attack was successful we change actual player and send it in new mockup data
	if (state == 1) {
		if (communication.actual_state_of_tour == TOUR_PLAYER_A){
			if(table.player_B->getHealth() <= 0)
				changed_state_game = END_OF_GAME;
			changed_state_tour = TOUR_PLAYER_B;
		}
		else{
			if(table.player_A->getHealth() <= 0)
				changed_state_game = END_OF_GAME;
			changed_state_tour = TOUR_PLAYER_A;
		}
		changed_move = END_OF_TOUR; //end of tour preview player
		saveData();
	}
	//nothing happen when function attack doesn't work properly
	return mockup;
}

/// \brief Funkcja throwingCard odpowiedzialna za rzucanie karty na stół
/// \return zwraca zaktualizowana makiete danych
Mockup Model::throwingCard(Player& actual_player, Communication communication){
	
	bool state = 0;
	
	state = table.throwCard(actual_player, communication.id_card);

	//if throwing card was successful we save it to mockup data
	if (state == 1)
		saveData();

	return mockup;
}

/// \brief Funkcja gettingCard odpowiedzialna za dobieranie kart do ręki
/// \return zwraca zaktualizowana makiete danych
Mockup Model::gettingCard(Player& actual_player, Communication communication){
	
	bool state = 0;
	
	state = actual_player.getCard();
	if (state == 1)
		saveData();
		
	return mockup;
}

/// \brief Funkcja gettingStart odpowiedzialna za nadanie odpowiednich stanów gry na jej początku
/// \return zwraca zaktualizowana makiete danych
Mockup Model::gettingStart(Communication communication){
	
	changed_state_game = GAMESTART_TRUE;
	changed_move = BEGIN;
	changed_state_tour = TOUR_PLAYER_A;
	saveData();
	
	return this->mockup;
}

/// \brief Funkcja endingGame odpowiedzialna za nadanie odpowiednich stanów gry na jej końcu
/// \return zwraca zaktualizowana makiete danych
Mockup Model::endingGame(){
	changed_move = END_OF_TOUR;
	changed_state_game = END_OF_GAME;
	saveData();
	
	return mockup;
}
