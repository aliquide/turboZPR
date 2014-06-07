#include "Model.h"

void Model::update(Player& player){
	
	for (unsigned int i = 0 ; i < player.cards_on_table.size(); i++){

		Card* card = player.cards_on_table.at(i);

		if (card->type_of_card == MONSTER){
			AllyCard* acard = dynamic_cast<AllyCard*>(card);
			if (acard->status == true){
				table.useCard(player, i);
				if (acard->health <= 0)
					player.cards_on_table.erase(player.cards_on_table.begin() + i);
				else
					return;
			}
			else{
				if (acard->health <= 0)
					player.cards_on_table.erase(player.cards_on_table.begin() + i);
				else
					return;
			}
		}
		else if (card->type_of_card == SPELL){ //if type of SPELL
			table.useCard(player, i);
			player.cards_on_table.erase(player.cards_on_table.begin() + i);
		}
	}
};


Model::Model(std::string id_player_a, std::string id_player_b){
	
	table.create(id_player_a, id_player_b);
	
};
