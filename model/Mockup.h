#ifndef MOCKUP
#define MOCKUP

#include "SpellCard.h"
#include "AllyCard.h"
#include "Table.h"
#include "Card.h"

#define max_on_table 5
#define max_in_hand 5

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
	
	Card cards_on_table_player_A[max_on_table];
	Card cards_on_table_player_B[max_on_table];
	
	Card cards_in_hand_player_A[max_in_hand];
	Card cards_in_hand_player_B[max_in_hand];
	
	//plus cards in deck
	
	//ID gracza ktory ma teraz ture
	std::string id_tour;
	
	StateOfTour actual_state_of_tour;
	
	StateOfGame actual_state_of_game;
	
	};

#endif 
