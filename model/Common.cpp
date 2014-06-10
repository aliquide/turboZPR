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

Dictionary::Dictionary(){
    this->dicGame.insert(std::make_pair("GAMESTART_TRUE", GAMESTART_TRUE));
    this->dicGame.insert(std::make_pair("RUNNING", RUNNING));
    this->dicGame.insert(std::make_pair("END_OF_GAME", END_OF_GAME));
    this->dicTour.insert(std::make_pair("TOUR_PLAYER_A", TOUR_PLAYER_A));
    this->dicTour.insert(std::make_pair("TOUR_PLAYER_B", TOUR_PLAYER_B));;
    this->dicMove.insert(std::make_pair("BEGIN", BEGIN));
    this->dicMove.insert(std::make_pair("THROW_CARD_ON_TABLE", THROW_CARD_ON_TABLE));
    this->dicMove.insert(std::make_pair("ATTACK", ATTACK));
    this->dicMove.insert(std::make_pair("GET_CARD",GET_CARD));
    this->dicMove.insert(std::make_pair("END_OF_TOUR",END_OF_TOUR));

}

PlayersMove Dictionary::fromStringMove(std::string s){
    return dicMove[s];

}
StateOfTour Dictionary::fromStringTour(std::string s){
    return dicTour[s];
}
StateOfGame Dictionary::fromStringGame(std::string s){
    return dicGame[s];
}
