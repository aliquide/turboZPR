#ifndef COMMON
#define COMMON

#include<string>
#define max_on_table 5
#define max_in_hand 5

enum PlayersMove {
	THROW_CARD_ON_TABLE, ATTACK, GET_CARD, END_OF_TOUR, BEGIN
};

enum StateOfTour {
	TOUR_PLAYER_A, TOUR_PLAYER_B,
};

enum StateOfGame {
	GAMESTART_TRUE, RUNNING, END_OF_GAME
};

std::string toStringGame(StateOfGame g);
std::string toStringTour(StateOfTour g);
std::string toStringMove(PlayersMove g);

#endif
