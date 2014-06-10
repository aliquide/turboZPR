#ifndef MOCKUP
#define MOCKUP

#include "SpellCard.h"
#include "AllyCard.h"
#include "Table.h"
#include "Card.h"

#define max_on_table 5
#define max_in_hand 5

enum StateOfTour{
	
};

enum StateOfGame{
	GAMESTART_TRUE;
	TOUR_PLAYER_A;
	TOUR_PLAYER_B;
};

struct Mockup{
	
	Card[max_on_table] cards_on_table_player_A;
	Card[max_on_table] cards_on_table_player_B;
	
	Card[max_in_hand] cards_in_hand_player_A;
	Card[max_in_hand] cards_in_hand_player_B;
	
	//plus cards in deck
	
	//ID of game tour
	string tour;
	
	StateOfTour actual_state_of_tour;
	
	StateOfGame actual_state_of_game;
	
	}

#endif 
