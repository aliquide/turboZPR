#ifndef JMOCKUP
#define JMOCKUP


#include <utility>
#include <string>

//json mockup:
#define CARDS 5

class jMockUp{
public:
	int x[100];
    int id_player_A;
    int x2[100];
    int id_player_B;
    int x3[100];
    std::string actual_move;
    int x4[100];
	std::string actual_state_of_tour;
	int x5[100];
	std::string actual_state_of_game;
	int x6[100];

    std::pair<int, std::string> p1Hand[CARDS];
    std::pair<int, std::string> p2Hand[CARDS];
    std::pair<int, std::string> p1Table[CARDS];
    std::pair<int, std::string> p2Table[CARDS];

    jMockUp(Mockup mockup){

       	 this->id_player_A = mockup.id_player_A;
         this->id_player_B = mockup.id_player_B;
         this->actual_state_of_tour = mockup.toStringTour(mockup.actual_state_of_tour);
         this->actual_state_of_game = mockup.toStringGame(mockup.actual_state_of_game);
         this->actual_move = mockup.toStringMove(mockup.actual_move);

     /**@todo
        przpisywanie cech kard do odpowiednich wektorow
    */
        for(int indeks = 0; indeks < CARDS; ++indeks ){
            p1Table[indeks].first = mockup.cards_on_table_player_A[indeks].getIdOfCard();
            p1Table[indeks].second = mockup.cards_on_table_player_A[indeks].getTypeOfCard();
            p2Table[indeks].first = mockup.cards_on_table_player_B[indeks].getIdOfCard();
            p2Table[indeks].second = mockup.cards_on_table_player_B[indeks].getTypeOfCard();
            p1Hand[indeks].first = mockup.cards_in_hand_player_A[indeks].getIdOfCard();
            p1Hand[indeks].second = mockup.cards_in_hand_player_A[indeks].getTypeOfCard();
            p2Hand[indeks].first = mockup.cards_in_hand_player_A[indeks].getIdOfCard();
            p2Hand[indeks].second = mockup.cards_in_hand_player_A[indeks].getTypeOfCard();
            }
    };
};

#endif
