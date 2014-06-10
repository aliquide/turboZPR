#include "Controller.h"
#include "Mockup.h"
#include <ctime>

//w kazdym momencie to trzeba robic :P zmiana garcza, chyba tutaj nie musimy wysylac makiety
void Controller::readCommunication(Communication communication){
	
	//interpretujemy czyja tura teraz jest
	if(communication.actual_state_of_tour == TOUR_PLAYER_A){
		actual_player = model.table.player_A;
		model.changed_state_tour = TOUR_PLAYER_A;
	}
	else if (communication.actual_state_of_tour == TOUR_PLAYER_B){
		actual_player = model.table.player_B;
		model.changed_state_tour = TOUR_PLAYER_B;
	}

}

//tylko przy starcie gry, nadanie id itp
Mockup Controller::startGame(Communication communication){

	Model model(communication.id_player_A, communication.id_player_B);

	model.table.player_A->setPlayerId(communication.id_player_A);
	model.table.player_B->setPlayerId(communication.id_player_B);

	model.changed_state_game= GAMESTART_TRUE;
	model.saveData();

	this->model = model;
	this->actual_player = new (Player);

	return model.mockup;
};

//wykonanie ruchu
Mockup Controller::makeMove(Communication communication){
	
	bool state = 0;

	//if game is running
	if(communication.actual_state_of_game == RUNNING){

		switch ( communication.kind_of_move ){
		
			case THROW_CARD_ON_TABLE:
				state = model.table.throwCard(*actual_player, communication.id_card);

				//if throwing card was successfull we save it to mockup data
				if(state == 1)
					model.saveData();

				break;
	
			case ATTACK: //attack end tour of player
				state = model.table.attack(*actual_player,communication.id_card, communication.id_of_aim);

				//if attack was succesfull we change actual player and send it in new mockup data
				if(state == 1){
					if (communication.actual_state_of_tour == TOUR_PLAYER_A)
						model.changed_state_tour = TOUR_PLAYER_B;
					else
						model.changed_state_tour = TOUR_PLAYER_A;

					model.changed_move = END_OF_TOUR; //end of tour preview player ?
					model.saveData();
				}
				//nothing happen when function attack doesn't work properly

				break;
	
			case GET_CARD:
				state = actual_player->getCard();

				if(state == 1)
					model.saveData();

				break;
	
			default:
				model.saveData();
		};
	}
	return model.mockup;
};
	
//zakonczenie gry, sprzatanie po sobie
Mockup Controller::endGame(){

	model.changed_move = END_OF_TOUR;
	model.changed_state_game= END_OF_GAME;
	model.saveData();

	return model.mockup;
};

