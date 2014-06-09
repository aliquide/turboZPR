#include "Model.h"

//poki co nie korzystamy z tego
void Model::update(Player& player){

	for (unsigned int i = 0 ; i < player.cards_on_table.size(); i++){

		Card* card = player.cards_on_table.at(i);

		if (card->type_of_card == MONSTER){
			AllyCard* acard = dynamic_cast<AllyCard*>(card);
			if (acard->status == true){
				table.useCard(player, i);
				if (acard->health <= 0)
					player.cards_on_table.erase(player.cards_on_table.begin() + i);
				else
					return;
			}
			else{
				if (acard->health <= 0)
					player.cards_on_table.erase(player.cards_on_table.begin() + i);
				else
					return;
			}
		}
		else if (card->type_of_card == SPELL){ //if type of SPELL
			table.useCard(player, i);
			player.cards_on_table.erase(player.cards_on_table.begin() + i);
		}
	}

};


Model::Model(int id_player_a, int id_player_b){

	table.create(id_player_a, id_player_b);

};


Model::Model(){
	
};


bool Model::saveData(){

for (unsigned int i=0; i<max_on_table; i++){
	if (this->changed_state_tour == TOUR_PLAYER_A)
		mockup.cards_on_table_player_A[i].id_of_card=0;
	else
		mockup.cards_on_table_player_B[i].id_of_card=0;
}

for (unsigned int i=0; i<max_in_hand; i++){
	if (this->changed_state_tour == TOUR_PLAYER_A)
		mockup.cards_in_hand_player_A[i].id_of_card=0;
	else
		mockup.cards_in_hand_player_B[i].id_of_card=0;
}


if (this->changed_state_tour == TOUR_PLAYER_A){
	for(unsigned int i=0; i< max_in_hand && i< table.player_A->cards_in_hand.size(); i++){
		mockup.cards_in_hand_player_A[i]=*table.player_A->cards_in_hand.at(i);
	}
	for(unsigned int i=0; i< max_on_table && i<table.player_A->cards_on_table.size(); i++ ){

		mockup.cards_on_table_player_A[i]=*table.player_A->cards_on_table.at(i);
	}
}
else{
	for(unsigned int i=0; i< max_on_table && i<table.player_B->cards_on_table.size(); i++ ){

		mockup.cards_on_table_player_B[i]=*table.player_B->cards_on_table.at(i);
	}

	for(unsigned int i=0; i< max_in_hand && i<table.player_B->cards_in_hand.size(); i++){

		mockup.cards_in_hand_player_B[i]=*table.player_B->cards_in_hand.at(i);
	}
}
	mockup.actual_state_of_tour=this->changed_state_tour;

	mockup.actual_state_of_game=this->changed_state_game;

	mockup.actual_move = this->changed_move;

return 0;
};
