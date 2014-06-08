#include "Controller.h"
#include "Mockup.h"

//w kazdym momencie to trzeba robic :Pzmiana garcza
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
	this->model = model;
	this->actual_player = new (Player);
	return model.mockup;
};

//wykonanie ruchu
Mockup Controller::makeMove(Communication communication){
	
	switch ( communication.kind_of_move ){
		
		case THROW_CARD_ON_TABLE:
			model.table.throwCard(*actual_player, communication.id_card);
			model.saveData(model.mockup,model.table);
			break;
	
		case ATTACK:
			model.table.attack(*actual_player,communication.id_card);
			model.saveData(model.mockup,model.table);
			break;
	
		case GET_CARD:
			actual_player->getCard();
			model.saveData(model.mockup,model.table);
			break;
	
		default:
			model.saveData(model.mockup,model.table);
		
	};
	
	return model.mockup;
	
};
	
//zakonczenie gry, sprzatanie po sobie
Mockup endGame();
