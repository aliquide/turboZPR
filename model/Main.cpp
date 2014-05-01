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

	model.player_1 = player_1;
	model.player_2 = player_2;
	table.player_1 = player_1;
	table.player_2 = player_2;

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

		//we must activate cart if we want to make effect
		table.activateCard(*player_1, i);


		model.update(table, *player_1);

		std::cout << "Gracz nr 2 rozgrywa ture" << std::endl;
		std::cout << "Wybierz karte (0-2), ktora chcesz wylozyc na stol." << std::endl;
		std::cin >> i;

		//get cart on table
		table.throwCard(*player_2, i);

		//take new cart
		player_2->getCard();

		//we must activate cart if we want to make effect
		table.activateCard(*player_2, i);

		//update model
		model.update(table, *player_2);

		std::cout << "Pozostalo zycia : " << std::endl;
		std::cout << "Gracz 1: " << model.player_1->health << std::endl;
		std::cout << "Gracz 2: " << model.player_2->health << std::endl;

		std::cout << "Pozostalo many : " << std::endl;
		std::cout << "Gracz 1: " << model.player_1->mana << std::endl;
		std::cout << "Gracz 2: " << model.player_2->mana << std::endl;



		std::cout << "Dalej? t/n" << std::endl;
		std::cin >> c;

	};
	return 0;
}