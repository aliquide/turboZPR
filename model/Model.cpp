#include "Model.h"
#include <utility>

Model::Model(int id_player_a, int id_player_b){
	table.create(id_player_a, id_player_b);
};

Model::Model(){
};

bool Model::saveData(){


if(this->changed_move == BEGIN){
	for (unsigned int i=0; i<max_on_table; i++){
		mockup.cards_on_table_player_A[i].setIdOfCard(0);
		mockup.cards_on_table_player_B[i].setIdOfCard(0);
	}
	for (unsigned int i=0; i<max_in_hand; i++){
		mockup.cards_in_hand_player_A[i].setIdOfCard(0);
		mockup.cards_in_hand_player_B[i].setIdOfCard(0);
	}
}


for (unsigned int i=0; i<max_on_table; i++){
	if (this->changed_state_tour == TOUR_PLAYER_A)
		mockup.cards_on_table_player_A[i].setIdOfCard(0);
	else
		mockup.cards_on_table_player_B[i].setIdOfCard(0);
}

for (unsigned int i=0; i<max_in_hand; i++){
	if (this->changed_state_tour == TOUR_PLAYER_A)
		mockup.cards_in_hand_player_A[i].setIdOfCard(0);
	else
		mockup.cards_in_hand_player_B[i].setIdOfCard(0);
}


//if (this->changed_state_tour == TOUR_PLAYER_A){
	for(unsigned int i=0; i< max_in_hand && i< table.player_A->cards_in_hand.size(); i++){
		mockup.cards_in_hand_player_A[i]=*table.player_A->cards_in_hand.at(i);
	}
	for(unsigned int i=0; i< max_on_table && i<table.player_A->cards_on_table.size(); i++ ){
		mockup.cards_on_table_player_A[i]=*table.player_A->cards_on_table.at(i);
	}
//}
//else{
	for(unsigned int i=0; i< max_on_table && i<table.player_B->cards_on_table.size(); i++ ){
		mockup.cards_on_table_player_B[i]=*table.player_B->cards_on_table.at(i);
	}

	for(unsigned int i=0; i< max_in_hand && i<table.player_B->cards_in_hand.size(); i++){
		mockup.cards_in_hand_player_B[i]=*table.player_B->cards_in_hand.at(i);
	}
//}
	mockup.actual_state_of_tour=this->changed_state_tour;
	mockup.actual_state_of_game=this->changed_state_game;
	mockup.actual_move = this->changed_move;
	mockup.id_player_A = this->table.player_A->getPlayerId();
	mockup.id_player_B = this->table.player_B->getPlayerId();

return 0;
};
