#ifndef SPELL_CARD
#define SPELL_CARD

#include "Card.h"

class SpellCard : public Card{
public:
	SpellCard();
	~SpellCard();
	
	const SpellCard& operator=(SpellCard);
	
};




#endif
