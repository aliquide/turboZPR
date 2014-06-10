#ifndef CARD
#define CARD
#include <string>

class Card{
public:
	virtual void virtual_method(){};

	int getIdOfCard();
	std::string getTypeOfCard();
	int getInteraction();
	int getCostOfMana();

	void setIdOfCard(int);
	void setTypeOfCard(std::string);
	void setInteraction(int);
	void setCostOfMana(int);

protected:
	int id_of_card;
	std::string type_of_card;
	int interaction;
	int cost_of_mana;

};


#endif
