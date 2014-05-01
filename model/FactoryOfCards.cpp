#include "FactoryOfCards.h"


Card* FactoryOfCards::createCard(TypeOfCard type_){
	if (type_ == MONSTER)
		return new AllyCard();
	else if (type_ == SPELL)
		return new SpellCard();
	else
		return new Card();
}
