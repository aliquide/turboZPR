#include "Model.h"

void Model::update(Table& table, Player& player){
	std::cout << "to co wskazuje: " << table.player_1->mana << std::endl;

	for (unsigned int i = 0 ; i < table.cards_on_table.size(); i++){
		Card& card = (table.cards_on_table.at(i));
		std::cout << "w update: " << table.cards_on_table.at(i).cost_of_mana << std::endl;
		if (card.type_of_card == MONSTER){
			AllyCard& acard = static_cast<AllyCard&>(card);
			if (acard.status == true){
				table.useCard(player, i);
				std::cout << "to co wskazuje" << player.cards_in_hand.operator[](i)->cost_of_mana << std::endl;
				if (acard.health <= 0)
					table.cards_on_table.erase(table.cards_on_table.begin() + i);
				else
					return;
			}
			else{
				if (acard.health <= 0)
					table.cards_on_table.erase(table.cards_on_table.begin() + i);
				else
					return;
			}
		}
		else{ //if type of SPELL
			std::cout << "to co wskazuje przed usecard: " << player.cards_in_hand.operator[](i)->cost_of_mana << std::endl;
			table.useCard(player, i);
			//std::cout << player.health << std::endl;
			std::cout << "to co wskazuje: " << player.cards_in_hand.operator[](i)->cost_of_mana << std::endl;
			table.cards_on_table.erase(table.cards_on_table.begin() + i);
		}
	}
};