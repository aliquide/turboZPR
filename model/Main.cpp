#include <cstdio>
#include <iostream>

#include <cstring>
#include <sys/types.h>
//#include <sys/socket.h> //linuks
//#include <winsock.h> //windows
//#include <windows.h> //windows
//#include <netdb.h> // linuks
//#include <netinet/in.h>//linuks

#include "Model.h"



int main(){
/*

	int slucham_bo_moge, msg_socket, rval;
	struct sockaddr_in server;
	char buffor[1024];
	slucham_bo_moge = socket(AF_INET, SOCK_STREAM, 0);

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(11000);

	while(true){
	int cokolwiek = bind(slucham_bo_moge, (struct sockaddr *) &server, sizeof server);

		std::cout<< "bind : "  << cokolwiek << std::endl;
	listen(slucham_bo_moge, 5);
	//msg_socket = accept(slucham_bo_moge, (struct sockaddr *) 0,(socklen_t *) 0); //dla linuksa
	msg_socket = accept(slucham_bo_moge, NULL ,NULL);
	if(msg_socket == -1)
	{
		std::cout<< "error -1" << std::endl;
	}
	else
	{
		memset(buffor, 0 , sizeof buffor);
        //rval = read(msg_socket, buffor, 1024); //dla linuksa
        rval = recv(msg_socket, buffor, 1024, 0);
		std::cout << "Wiadomosc " << rval << std::endl;
	}
	//int cntr = write(msg_socket, "dziala", 6);dla linuksa
	int cntr = send(msg_socket, "dziala", 6, 0);
	//close(msg_socket); // dla linuksa
	closesocket(msg_socket); //dla windowsa
	}

*/

	//create table
	Model model(player_id_A, player_id_B);


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
