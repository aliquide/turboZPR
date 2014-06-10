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
#include "Wrapper.h"
#include "jMockUp.h"
#include "toJson.h"

int main(){


	Wrapper wrapper;
	Communication communication;
	Mockup mockup;

	communication.id_player_A= 1000;
	communication.id_player_B= 1001;

	//tworzenie talii kart itp

	mockup = wrapper.startGame(communication);

	//tutaj dostajemy info ze ok sie udalo zaczac gre itp:

	communication.actual_state_of_game = RUNNING;
	
	//na potrzeby testowania
	std::cout<<"Karty w talii gracza A:  ";
	for (unsigned int i = 0; i < wrapper.model.table.player_A->deck.size(); i++) {
		std::cout<<" "<< wrapper.model.table.player_A->deck.at(i)->getIdOfCard() << " typu: "<< wrapper.model.table.player_A->deck.at(i)->getTypeOfCard()<<";";
	}
	std::cout<<std::endl;
	std::cout<<"Karty w talii gracza B:  ";
	for (unsigned int i = 0; i < wrapper.model.table.player_B->deck.size(); i++) {
		std::cout<<" "<< wrapper.model.table.player_B->deck.at(i)->getIdOfCard() << " typu: "<< wrapper.model.table.player_B->deck.at(i)->getTypeOfCard()<<";";
	}
	std::cout<<std::endl;
	
	//zmienna do testow
	int state;
	
	char c = 'a';
	
while (c!= 'n'){
	
	std::cout << "Ktory gracz ma ruch (0 - player A; 1 - player B)?"<<std::endl;
	std::cin >> state;
	
	//tylko na potrzeby testowania
	if(state == 0){
		communication.actual_state_of_tour = TOUR_PLAYER_A;
		communication.id_of_aim = wrapper.model.table.player_B->getPlayerId();
	}
	else{
		communication.actual_state_of_tour = TOUR_PLAYER_B;
		communication.id_of_aim = wrapper.model.table.player_A->getPlayerId();
	}

	//okreslamy czyja tura, ktory gracz
	wrapper.readCommunication(communication);

//na potrzeby testowania, to bedziemy zczytywac z komunikatu	
	std::cout<<"Co chcesz zrobic (0 - throw card on table; 1 - attack; 2 - get card from deck) ?"<<std::endl;
	std::cin>>state;
	

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
	for(unsigned int i=0; i< wrapper.actual_player->cards_on_table.size(); i++){
		std::cout<<wrapper.actual_player->cards_on_table.at(i)->getIdOfCard()<<std::endl;
	}
	
	std::cout<<"Twoje karty w reku (id_card): " << std::endl;
	for(unsigned int i=0; i< wrapper.actual_player->cards_in_hand.size(); i++){
		std::cout<<wrapper.actual_player->cards_in_hand.at(i)->getIdOfCard()<<std::endl;
	}
	
	std::cout<<"Ktora karta chcesz GRAC" <<std::endl;
	std::cin>>state;
}	
	communication.id_card = state;

if(communication.kind_of_move == ATTACK){
	std::cout<<"Podaj cel (posrod kart, lub przeciwnika)"<<std::endl;
	if (communication.actual_state_of_tour == TOUR_PLAYER_A)
		std::cout<<wrapper.model.table.player_B->getPlayerId() << std::endl;
	else
		std::cout<<wrapper.model.table.player_A->getPlayerId() <<std::endl;

	std::cin>>state;
	communication.id_of_aim = state;
}
	communication.actual_state_of_game = RUNNING;
//wykonujemy odpowiedni ruch
	mockup = wrapper.makeMove(communication);
	jMockUp jmockup(mockup);
	toJson(jmockup);

//na potrzeby testowania
	std::cout << "Pozostalo zycia : " << std::endl;

	std::cout << "Gracz A: " << mockup.mana_player_A << std::endl;
	std::cout << "Gracz B: " << mockup.mana_player_B << std::endl;

	std::cout << "Pozostalo many : " << std::endl;
	std::cout << "Gracz A: " << mockup.health_player_A << std::endl;
	std::cout << "Gracz B: " << mockup.health_player_B << std::endl;

	std::cout<< "Karty na stole graczy: "<<std::endl;
	for(unsigned int i=0; i<max_on_table;i++){
		
		if(mockup.cards_on_table_player_A[i].getIdOfCard()!=0){
			std::cout<<"Player_A: ";
			std::cout<<mockup.cards_on_table_player_A[i].getIdOfCard()<<std::endl;
		}
		
		if(mockup.cards_on_table_player_B[i].getIdOfCard()!=0){
			std::cout<<"Player_B: ";
			std::cout<<mockup.cards_on_table_player_B[i].getIdOfCard()<<std::endl;
		}
	}
	
	std::cout<< "Karty w rekach graczy: "<<std::endl;
	for(unsigned int i=0; i<max_on_table;i++){
		
		if(mockup.cards_in_hand_player_A[i].getIdOfCard()!=0){
			std::cout<<"Player_A: ";
			std::cout<<mockup.cards_in_hand_player_A[i].getIdOfCard()<<std::endl;
		}
		
		if(mockup.cards_in_hand_player_B[i].getIdOfCard()!=0){
			std::cout<<"Player_B: ";
			std::cout<<mockup.cards_in_hand_player_B[i].getIdOfCard()<<std::endl;
		}
	}

	std::cout << "Dalej? t/n" << std::endl;
	std::cin >> c;
};

	return 0;
}
