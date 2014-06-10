#ifndef MOCKUP
#define MOCKUP

#include "SpellCard.h"
#include "AllyCard.h"
#include "Table.h"
#include "Card.h"

#define max_on_table 5
#define max_in_hand 5
//STan tury
enum PlayersMove{
	THROW_CARD_ON_TABLE,
	ATTACK,
	GET_CARD,
	END_OF_TOUR
};

enum StateOfTour{
	TOUR_PLAYER_A,
	TOUR_PLAYER_B,
};

enum StateOfGame{
	GAMESTART_TRUE,
	RUNNING,
	END_OF_GAME
};

struct Mockup{
	int id_player_A;
	int id_player_B;

	Card cards_on_table_player_A[max_on_table];
	Card cards_on_table_player_B[max_on_table];

	Card cards_in_hand_player_A[max_in_hand];
	Card cards_in_hand_player_B[max_in_hand];

	PlayersMove actual_move;
	StateOfTour actual_state_of_tour;
	StateOfGame actual_state_of_game;

	std::string toStringGame(StateOfGame g){
        switch (g){
            case GAMESTART_TRUE: return std::string m("GAMESTART_TRUE");
            case RUNNING:        return std::string m("RUNNING");
            case END_OF_GAME:    return std::string m("END_OF_GAME");
	}

	std::string toStringTour(StateOfTour g){
        switch (g){
            case GBEGIN_TOUR:          return std::string m("BEGIN_TOUR");
            case TOUR_PLAYER_A:        return std::string m("TOUR_PLAYER_A");
            case TOUR_PLAYER_B:        return std::string m("TOUR_PLAYER_B");
	}

	std::string toStringMove(StateOfGame g){
        switch (g){
            case THROW_CARD_ON_TABLE:   return std::string m("THROW_CARD_ON_TABLE");
            case ATTACK:                return std::string m("ATTACK");
            case GET_CARD:              return std::string m("GET_CARD");
            case END_OF_TOUR:           return std::string m("END_OF_TOUR");
        }
	}

	};

#endif
