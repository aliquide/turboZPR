#ifndef SPELL_CARD
#define SPELL_CARD

#include "Card.h"
/**
\brief Klasa SpellCard reprezentuje obiekt kartę typu zaklęcie.
\details Zaklęcia nie posiadają punktów życia i znikają po użyciu ich w celu zaatakowania.
**/

class SpellCard : public Card{
public:
	SpellCard();
	~SpellCard();
	
	const SpellCard& operator=(SpellCard);
	
};

#endif
