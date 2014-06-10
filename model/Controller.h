#ifndef CONTROLLER
#define CONTROLLER

#include "Model.h"
#include "Communication.h"
#include <boost/shared_ptr.hpp>


class Controller{
public:

	boost::shared_ptr<Player> actual_player;
	//Player *actual_player;
	Model model;
	
	void readCommunication(Communication);
	
	Mockup startGame(Communication);
	Mockup makeMove(Communication);
	Mockup endGame();
	
};
#endif
