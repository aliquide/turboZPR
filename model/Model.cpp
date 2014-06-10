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

	if (this->changed_state_game == GAMESTART_TRUE) {
		for (unsigned int i = 0; i < max_on_table; i++) {
			mockup.cards_on_table_player_A[i].setIdOfCard(0);
			mockup.cards_on_table_player_B[i].setIdOfCard(0);
		}
		for (unsigned int i = 0; i < max_in_hand; i++) {
			mockup.cards_in_hand_player_A[i].setIdOfCard(0);
			mockup.cards_in_hand_player_B[i].setIdOfCard(0);
		}
	}

	for (unsigned int i = 0; i < max_on_table; i++) {
		if (this->changed_state_tour == TOUR_PLAYER_A)
			mockup.cards_on_table_player_A[i].setIdOfCard(0);
		else
			mockup.cards_on_table_player_B[i].setIdOfCard(0);
	}

	for (unsigned int i = 0; i < max_in_hand; i++) {
		if (this->changed_state_tour == TOUR_PLAYER_A)
			mockup.cards_in_hand_player_A[i].setIdOfCard(0);
		else
			mockup.cards_in_hand_player_B[i].setIdOfCard(0);
	}

	for (unsigned int i = 0;
			i < max_in_hand && i < table.player_A->cards_in_hand.size(); i++) {
		mockup.cards_in_hand_player_A[i] = *table.player_A->cards_in_hand.at(i);
	}
	for (unsigned int i = 0;
			i < max_on_table && i < table.player_A->cards_on_table.size();
			i++) {
		mockup.cards_on_table_player_A[i] = *table.player_A->cards_on_table.at(
				i);
	}

	for (unsigned int i = 0;
			i < max_on_table && i < table.player_B->cards_on_table.size();
			i++) {
		mockup.cards_on_table_player_B[i] = *table.player_B->cards_on_table.at(
				i);
	}

	for (unsigned int i = 0;
			i < max_in_hand && i < table.player_B->cards_in_hand.size(); i++) {
		mockup.cards_in_hand_player_B[i] = *table.player_B->cards_in_hand.at(i);
	}

	mockup.actual_state_of_tour = this->changed_state_tour;
	mockup.actual_state_of_game = this->changed_state_game;
	mockup.actual_move = this->changed_move;
	mockup.id_player_A = this->table.player_A->getPlayerId();
	mockup.id_player_B = this->table.player_B->getPlayerId();

	return 1;
}

