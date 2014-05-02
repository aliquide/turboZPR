#include "Model.h"

void Model::update(Player& player){
	
	for (unsigned int i = 0 ; i < table.cards_on_table.size(); i++){

		Card* card = table.cards_on_table.at(i);

		if (card->type_of_card == MONSTER){
			AllyCard* acard = dynamic_cast<AllyCard*>(card);
			if (acard->status == true){
				table.useCard(player, i);
				if (acard->health <= 0)
					table.cards_on_table.erase(table.cards_on_table.begin() + i);
				else
					return;
			}
			else{
				if (acard->health <= 0)
					table.cards_on_table.erase(table.cards_on_table.begin() + i);
				else
					return;
			}
		}
		else if (card->type_of_card == SPELL){ //if type of SPELL
			table.useCard(player, i);
			table.cards_on_table.erase(table.cards_on_table.begin() + i);
		}
	}
};