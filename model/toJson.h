#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"
#include "jMockUp.h"

using namespace std;
using boost::property_tree::ptree;
using boost::property_tree::basic_ptree;

boost::property_tree::ptree toJson(jMockUp mp){

    boost::property_tree::ptree pt, pCards;

    for(int indeks= 0; indeks<5; ++indeks){
        boost::property_tree::ptree name, id, card;
        card.put("Id", mp.p1Table[indeks].first);
        card.put("cardStr", mp.p1Table[indeks].second);
        pCards.push_back(std::make_pair("",card));
    }
    pt.add_child("p1Table", pCards);

    for(int indeks= 0; indeks<5; ++indeks){
        boost::property_tree::ptree name, id, card;
        card.put("Id", mp.p2Table[indeks].first);
        card.put("cardStr", mp.p2Table[indeks].second);
        pCards.push_back(std::make_pair("",card));
    }

    pt.add_child("p2Table", pCards);

    for(int indeks= 0; indeks<5; ++indeks){
        boost::property_tree::ptree name, id, card;
        card.put("Id", mp.p1Hand[indeks].first);
        card.put("cardStr", mp.p1Hand[indeks].second);
        pCards.push_back(std::make_pair("",card));
    }
    pt.add_child("p1Hand", pCards);

    for(int indeks= 0; indeks<5; ++indeks){
        boost::property_tree::ptree name, id, card;
        card.put("Id", mp.p2Hand[indeks].first);
        card.put("cardStr", mp.p2Hand[indeks].second);
        pCards.push_back(std::make_pair("",card));
    }

    pt.add_child("p2Hand", pCards);
    pt.put("p1", mp.id_player_A);
    pt.put("p2", mp.id_player_B);
    pt.put("StanGry", mp.actual_state_of_game);
    pt.put("RuchGracza", mp.actual_move);
    pt.put("TuraGracza", mp.actual_state_of_tour);

    write_json("test2.json", pt);
    return pt;
}
