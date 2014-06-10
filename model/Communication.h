#ifndef COMMUNICATION
#define COMMUNICATION

#include "Model.h"


struct Communication{
	int id_player_A;
	int id_player_B;
	
	PlayersMove kind_of_move;
	StateOfTour actual_state_of_tour;
	StateOfGame actual_state_of_game;
	
	int id_card;
	int id_of_aim;
};

#endif
