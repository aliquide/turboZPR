#ifndef CARD
#define CARD

#include <string>

/**
\brief Klasa Card reprezentuje obiekt kartę.
\details Karty posiadają pewne cechy. Identyfikuje się je przez indywidualne ID, nadawane podczas ich tworzenia.
Karta posiada również swój typ: zaklęcie lub sojusznik, interakcję (siłę ataku) oraz koszt many towarzyszący jej użyciu (wyrzuceniu na stół).
**/

class Card{
public:

	int getIdOfCard();
	std::string getTypeOfCard();
	int getInteraction();
	int getCostOfMana();

	void setIdOfCard(int);
	void setTypeOfCard(std::string);
	void setInteraction(int);
	void setCostOfMana(int);

	virtual void virtual_method(){}

protected:
	int id_of_card;
	std::string type_of_card;
	int interaction;
	int cost_of_mana;
};

#endif
