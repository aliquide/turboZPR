#ifndef CARD
#define CARD

enum TypeOfCard{
	MONSTER,
	SPELL
};

class Card{
public:

	int id_of_card;
	TypeOfCard type_of_card;
	int interaction;
	int cost_of_mana;

	virtual void virtual_method(){};
//protected:
	//Cart();
	//~Cart();

};


#endif
