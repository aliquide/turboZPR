#ifndef MOCKUP
#define MOCKUP

#include "SpellCard.h"
#include "AllyCard.h"
#include "Table.h"
#include "Card.h"
#include "Common.h"



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

	};

#endif
