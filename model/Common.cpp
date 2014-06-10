#include "Common.h"

/// \brief Metoda toStringGame zastępuje typ enum StateOfGame odpowiednim napisem typu std::string.
std::string toStringGame(StateOfGame g) {
	switch (g) {
	case GAMESTART_TRUE:
		return "GAMESTART_TRUE";
	case RUNNING:
		return "RUNNING";
	case END_OF_GAME:
		return "END_OF_GAME";
	default:
		return "ERROR";
	}
}

/// \brief Metoda toStringTour zastępuje typ enum StateOfTour odpowiednim napisem typu std::string.
std::string toStringTour(StateOfTour g) {
	switch (g) {
	case TOUR_PLAYER_A:
		return "TOUR_PLAYER_A";
	case TOUR_PLAYER_B:
		return "TOUR_PLAYER_B";
	default:
		return "ERROR";
	}
}

/// \brief Metoda toStringMove zastępuje typ enum PlayersMove odpowiednim napisem typu std::string.
std::string toStringMove(PlayersMove g) {
	switch (g) {
	case BEGIN:
		return "BEGIN";
	case THROW_CARD_ON_TABLE:
		return "THROW_CARD_ON_TABLE";
	case ATTACK:
		return "ATTACK";
	case GET_CARD:
		return "GET_CARD";
	case END_OF_TOUR:
		return "END_OF_TOUR";
	default:
		return "ERROR";
	}
}
