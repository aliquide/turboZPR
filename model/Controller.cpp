#include "Controller.h"
#include "Mockup.h"
#include "Model.h"

/// \brief Funkcja readCommunication interpretuje komunikat przychodzący od serwera w celu określenia gracza rozgrywającego.
/// \param communication jest komunikatem, ktory otrzymujemy od serwera.
void Controller::readCommunication(Communication communication) {

	//which one player is actual
	if (communication.actual_state_of_tour == TOUR_PLAYER_A) {
		actual_player = model.table.player_A;
		model.changed_state_tour = TOUR_PLAYER_A;
		
	} else if (communication.actual_state_of_tour == TOUR_PLAYER_B) {
		actual_player = model.table.player_B;
		model.changed_state_tour = TOUR_PLAYER_B;
	}

}

/// \brief Funkcja startGame odpowiedzialna jest za rozpoczęcie rozgrywki, ustawienie odpowiednich stanów w makiecie przesyłanej do serwera.
/// \param communication jest komunikatem otrzymywanym z serwera
/// \return zwraca makietę danych, przesyłaną do serwera w celu powiadomienia o rozpoczątej rozgrywce
Mockup Controller::startGame(Communication communication) {
	
	Mockup mockup;
	Model model(communication.id_player_A, communication.id_player_B);
	
	mockup = model.gettingStart(communication);
	
	this->model = model;
	this->actual_player = boost::shared_ptr<Player>(new Player);

	return mockup;
}

/// \brief Funkcja makeMove odpowiedzialna jest za przeprowadzenie odpowiedniej akcji.
/// \param communication jest komunikatem otrzymywanym z serwera
/// \return zwraca makietę danych, przesyłaną do serwera w celu powiadomienia o zmianach dokonanych podczas rozgrywki
Mockup Controller::makeMove(Communication communication) {

	Mockup mockup;
	bool state = 0; //helpful variable which would be needed to check state of actual action

	//if game is running
	if (communication.actual_state_of_game == RUNNING) {

		switch (communication.kind_of_move) {

		case THROW_CARD_ON_TABLE:
			mockup = model.throwingCard(*actual_player, communication);
			break;

		case ATTACK: //attack end tour of player
			mockup = model.makeAttack(*actual_player, communication);
			break;

		case GET_CARD: //get Card from deck to hand
			mockup = model.gettingCard(*actual_player, communication);
			break;

		default:
			break;
		};
	}
	return mockup;
}

/// \brief Funkcja endGame odpowiedzialna jest za konczenie gry.
/// \return zwraca makietę danych, przesyłaną do serwera w celu powiadomienia o zmianach i zakończeniu gry.
Mockup Controller::endGame() {
	Mockup mockup;
	mockup = model.endingGame();
	return mockup;
}

/// \brief Funkcja update wywoluje pozostale metody w odpowiednich stanach gry
/// \param communication jest komunikatem otrzymywanym z serwera
/// \return zwraca makietę danych, przesyłaną do serwera w celu powiadomienia o zmianach
Mockup Controller::update(Communication communication) {
	Mockup mockup;
	
	switch (communication.actual_state_of_game) {

	case GAMESTART_TRUE:
		mockup = startGame(communication);
		readCommunication(communication);
		break;

	case RUNNING:
		readCommunication(communication);
		mockup = makeMove(communication);
		break;

	case END_OF_GAME:
		mockup = endGame();
		break;

	default:
		mockup = endGame();
		break;
	}
	return mockup;
}
