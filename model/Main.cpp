#include <cstdio>
#include <iostream>

#include "Model.h"



int main(){

	Model model;

	FactoryOfCards factory;

	//just for example
	Player* player_1,* player_2;
	player_1 = new Player;
	player_2 = new Player;

	//for example we create same deck for each player with 10 spell carts and 10 ally carts 
	for (int i = 0; i < 10; i++){
		player_1->deck.push_back(factory.createCard(SPELL));
		player_1->deck.push_back(factory.createCard(MONSTER));

		player_2->deck.push_back(factory.createCard(SPELL));
		player_2->deck.push_back(factory.createCard(MONSTER));
	}

	//we choose 3 carts to hand, it would be random or chosen by player later 
	for (int i = 0; i < 3; i++){
		player_1->getCard();
		player_2->getCard();
	}

	//create table
	Table table;

	table.player_1 = player_1;
	table.player_2 = player_2;
	model.table = table;
	model.table.cards_on_table = table.cards_on_table;

	int i;
	char c = 'a';
	while (c != 'n'){

		std::cout << "Gracz nr 1 rozgrywa ture" << std::endl;
		std::cout << "Wybierz karte (0-2), ktora chcesz wylozyc na stol." << std::endl;
		std::cin >> i;
		//get cart on table
		table.throwCard(*player_1, i);
		
		//take new cart
		player_1->getCard();
		
		std::cout << "Ktora karte, ze stolu chcesz aktywowac? " << std::endl;
		for (int i = 0; i < table.cards_on_table.size(); i++)
			std::cout << "Karta nr. " << i << ": " << table.cards_on_table.at(i)->type_of_card << std::endl;
		//we must activate cart if we want to make effect
		std::cin >> i;

		if (table.cards_on_table.at(i)->type_of_card == MONSTER)
			table.activateCard(i);
		

		model.table.cards_on_table = table.cards_on_table;

		model.update(*player_1);

		table.cards_on_table = model.table.cards_on_table;

		std::cout << "Gracz nr 2 rozgrywa ture" << std::endl;
		std::cout << "Wybierz karte (0-2), ktora chcesz wylozyc na stol." << std::endl;
		std::cin >> i;

		//get cart on table
		table.throwCard(*player_2, i);

		//take new cart
		player_2->getCard();

		
		std::cout << "Ktora karte, ze stolu chcesz aktywowac? " << std::endl;
		for (int i = 0; i < table.cards_on_table.size(); i++)
			std::cout << "Karta nr. " << i << ": " << table.cards_on_table.at(i)->type_of_card << std::endl;
		//we must activate cart if we want to make effect
		std::cin >> i;

		if (table.cards_on_table.at(i)->type_of_card == MONSTER)
			table.activateCard(i);
		

		model.table.cards_on_table = table.cards_on_table;

		//update model
		model.update(*player_2);
		table.cards_on_table = model.table.cards_on_table;
		
		table.player_1 = player_1;
		table.player_2 = player_2;

		std::cout << "Pozostalo zycia : " << std::endl;
		std::cout << "Gracz 1: " << model.table.player_1->health << std::endl;
		std::cout << "Gracz 2: " << model.table.player_2->health << std::endl;

		std::cout << "Pozostalo many : " << std::endl;
		std::cout << "Gracz 1: " << model.table.player_1->mana << std::endl;
		std::cout << "Gracz 2: " << model.table.player_2->mana << std::endl;

		std::cout << "Dalej? t/n" << std::endl;
		std::cin >> c;

	};
	return 0;
}