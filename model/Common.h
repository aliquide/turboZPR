#ifndef COMMON
#define COMMON

#include<string>
#include<map>
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


class Dictionary{
public:
    Dictionary();
    PlayersMove fromStringMove(std::string);
    StateOfTour fromStringTour(std::string);
    StateOfGame fromStringGame(std::string);
private:
    std::map<std::string, PlayersMove> dicMove;
    std::map<std::string, StateOfTour> dicTour;
    std::map<std::string, StateOfGame> dicGame;
};

#endif
