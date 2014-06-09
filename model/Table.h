#ifndef TABLE
#define TABLE

#include <cstdio>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "Card.h"
#include "Player.h"
#include "Mockup.h"

class Table{
public:
	//dodac destruktory i kosntruktory odpowiednie
	Player* player_A, * player_B;

	void useCard(Player&, int);//nie uzywanya

	bool throwCard(Player&, int);
	void activateCard(Player&, int);//nie uzywanya

	bool attack(Player&, int,int);
	void create(int, int);
	

	
//protected:
	Table();

};


#endif
