#ifndef CONTROLLER
#define CONTROLLER

#include <boost/shared_ptr.hpp>
#include "Model.h"
#include "Communication.h"


/**
 	 \brief Klasa Wrapper odpowiada za kontrolowanie modelu i przebiegu gry i dostarczenie interfejsu kontrolerowi.
 	 \details Na podstawie interpretowanego komunikatu pochodzącego od serwera sterujemy przebiegiem gry.
 **/

class Wrapper {
public:
	boost::shared_ptr<Player> actual_player;
	Model model;

	void readCommunication(Communication);

	Mockup startGame(Communication);
	Mockup makeMove(Communication);
	Mockup endGame();
	Mockup update(Communication);
	
};
#endif
