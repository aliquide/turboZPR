#ifndef JMOCKUP
#define JMOCKUP

#include <utility>
#include "Common.h"
//json mockup:
#define CARDS 5

class jMockUp{
public:

    int id_player_A;
    int id_player_B;
    std::string actual_move;
std::string actual_state_of_tour;
std::string actual_state_of_game;

    std::pair<int, std::string> p1Hand[CARDS];
    std::pair<int, std::string> p2Hand[CARDS];
    std::pair<int, std::string> p1Table[CARDS];
    std::pair<int, std::string> p2Table[CARDS];

    jMockUp(Mockup mockup){

        this->id_player_A = mockup.id_player_A;
         this->id_player_B = mockup.id_player_B;
         this->actual_state_of_tour = toStringTour(mockup.actual_state_of_tour);
         this->actual_state_of_game = toStringGame(mockup.actual_state_of_game);
         this->actual_move = toStringMove(mockup.actual_move);

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
