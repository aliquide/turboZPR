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
#include "Communication.h"
#include "Mockup.h"


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
	
//TO jest w kontrolerze +co w starcie gry sie dzieje co na zakonczenie, opakowac w kontroler,
//dodanie celu
//

	std::string player_id_A="playerA", player_id_B="playerB";
	
	Communication communication;

	Model model(player_id_A, player_id_B);
	std::cout<<"Karty w talii gracza A:  ";
	for (unsigned int i = 0; i < model.table.player_A->deck.size(); i++) {
		std::cout<<" "<< model.table.player_A->deck.at(i)->id_of_card << " typu: "<< model.table.player_A->deck.at(i)->type_of_card<<";";
	}
	std::cout<<std::endl;
	std::cout<<"Karty w talii gracza B:  ";
	for (unsigned int i = 0; i < model.table.player_B->deck.size(); i++) {
		std::cout<<" "<< model.table.player_B->deck.at(i)->id_of_card << " typu: "<< model.table.player_B->deck.at(i)->type_of_card<<";";
	}
	std::cout<<std::endl;
	communication.kind_of_move = THROW_CARD_ON_TABLE;
	
	Player *actual_player;
	
	communication.actual_state_of_tour = TOUR_PLAYER_A;
	
	int state;

	communication.id_card=200;
	
	char c = 'a';
	
while (c!= 'n'){
	
	std::cout << "Ktory gracz ma ruch (0 - player A; 1 - player B)?"<<std::endl;
	std::cin >> state;
	
	//tylko na potrzeby testowania
	if(state == 0){
		communication.actual_state_of_tour = TOUR_PLAYER_A;
	}
	else{
		communication.actual_state_of_tour = TOUR_PLAYER_B;
	}
	
	//interpretujemy czyja tura teraz jest
	if(communication.actual_state_of_tour == TOUR_PLAYER_A){
		actual_player = model.table.player_A;
		model.changed_state_tour = TOUR_PLAYER_A;
	}
	else if (communication.actual_state_of_tour == TOUR_PLAYER_B){
		actual_player = model.table.player_B;
		model.changed_state_tour = TOUR_PLAYER_B;
	}
	
	std::cout<<"Co chcesz zrobic (0 - throw card on table; 1 - attack; 2 - get card from deck) ?"<<std::endl;
	std::cin>>state;
	
	//na potrzeby testowania, to bedziemy zczytywac z komunikatu
	switch (state){
		case 0:
		communication.kind_of_move = THROW_CARD_ON_TABLE;
		break;
		
		case 1:
		communication.kind_of_move = ATTACK;
		break;
		
		case 2:
		communication.kind_of_move = GET_CARD;
	}
	
	//na potrzeby testowania
if(communication.kind_of_move != GET_CARD){
	std::cout<<"Twoje karty na stole (id_card): " << std::endl;
	for(unsigned int i=0; i< actual_player->cards_on_table.size(); i++){
		std::cout<<actual_player->cards_on_table.at(i)->id_of_card<<std::endl;
	}
	
	std::cout<<"Twoje karty w reku (id_card): " << std::endl;
	for(unsigned int i=0; i< actual_player->cards_in_hand.size(); i++){
		std::cout<<actual_player->cards_in_hand.at(i)->id_of_card<<std::endl;
	}
	
	std::cout<<"Ktora karta chcesz GRAC" <<std::endl;
	std::cin>>state;
}	
	
	
//sensowne dla kontrolera
switch ( communication.kind_of_move ){
	
	case THROW_CARD_ON_TABLE:
	model.table.throwCard(*actual_player, state);
	model.saveData(model.mockup,model.table);
	break;
	
	case ATTACK:
	model.table.attack(*actual_player,state);
	model.saveData(model.mockup,model.table);
	break;
	
	case GET_CARD:
	actual_player->getCard();
	model.saveData(model.mockup,model.table);
	break;
	
	default:
	model.saveData(model.mockup,model.table);
	;
};

//na potrzeby testowania
	std::cout << "Pozostalo zycia : " << std::endl;
	std::cout << "Gracz A: " << model.table.player_A->health << std::endl;
	std::cout << "Gracz B: " << model.table.player_B->health << std::endl;

	std::cout << "Pozostalo many : " << std::endl;
	std::cout << "Gracz A: " << model.table.player_A->mana << std::endl;
	std::cout << "Gracz B: " << model.table.player_B->mana << std::endl;

	std::cout<< "Karty na stole graczy: "<<std::endl;
	for(unsigned int i=0; i<max_on_table;i++){
		
		if(model.mockup.cards_on_table_player_A[i].id_of_card!=0){
			std::cout<<"Player_A: ";
			std::cout<<model.mockup.cards_on_table_player_A[i].id_of_card<<std::endl;
		}
		
		if(model.mockup.cards_on_table_player_B[i].id_of_card!=0){
			std::cout<<"Player_B: ";
			std::cout<<model.mockup.cards_on_table_player_B[i].id_of_card<<std::endl;
		}
	}
	
	std::cout<< "Karty w rekach graczy: "<<std::endl;
	for(unsigned int i=0; i<max_on_table;i++){
		
		if(model.mockup.cards_in_hand_player_A[i].id_of_card!=0){
			std::cout<<"Player_A: ";
			std::cout<<model.mockup.cards_in_hand_player_A[i].id_of_card<<std::endl;
		}
		
		if(model.mockup.cards_in_hand_player_B[i].id_of_card!=0){
			std::cout<<"Player_B: ";
			std::cout<<model.mockup.cards_in_hand_player_B[i].id_of_card<<std::endl;
		}
	}
	
	std::cout << "Dalej? t/n" << std::endl;
	std::cin >> c;
};

	return 0;
}
