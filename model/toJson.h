#ifndef TOJSON
#define TOJSON

#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"
#include "jMockUp.h"

boost::property_tree::ptree addCards(std::pair<int, std::string> *el) {
	boost::property_tree::ptree pCards;
	for (int indeks = 0; indeks < CARDS; ++indeks) {
		boost::property_tree::ptree card;
		card.put("Id", el[indeks].first);
		card.put("cardStr", el[indeks].second);
		pCards.push_back(std::make_pair("", card));
	}
	return pCards;
}

boost::property_tree::ptree toJson(jMockUp mp) {

	boost::property_tree::ptree pt, pCards;

	pt.add_child("p1Table", addCards(mp.p1Table));
	pt.add_child("p2Table", addCards(mp.p2Table));
	pt.add_child("p1Hand", addCards(mp.p1Hand));
	pt.add_child("p2Hand", addCards(mp.p2Hand));

	pt.put("p1", mp.id_player_A);
	pt.put("p2", mp.id_player_B);
	pt.put("StanGry", mp.actual_state_of_game);
	pt.put("RuchGracza", mp.actual_move);
	pt.put("TuraGracza", mp.actual_state_of_tour);

	write_json("test2.json", pt);
	return pt;
}


Communication fromJson(boost::property_tree::ptree cm){
        Communication com;
        Dictionary di;
        com.id_player_A = cm.get<int>("p1");
        com.id_player_B = cm.get<int>("p2");
        com.actual_state_of_tour = di.fromStringTour(cm.get<std::string>("TuraGracza"));
        com.kind_of_move = di.fromStringMove(cm.get<std::string>("RuchGracza"));
        com.actual_state_of_game = di.fromStringGame(cm.get<std::string>("StanGry"));
        com.id_card = cm.get<int>("IdKarty");
        com.id_card = cm.get<int>("IdCelu");
        return com;
}

#endif
