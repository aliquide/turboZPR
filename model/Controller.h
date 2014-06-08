#ifndef CONTROLLER
#define CONTROLLER

#include "Model.h"
#include "Communication.h"

class Controller{
public:
	Player *actual_player;
	Model model;
	
	void readCommunication(Communication);
	
	Mockup startGame(Communication);
	
	Mockup makeMove(Communication);
	
	Mockup endGame();
	
};
#endif
