#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"

using namespace std;
using boost::property_tree::ptree;
using boost::property_tree::basic_ptree;

boost::property_tree::ptree toJson(JMockUp mp){

    boost::property_tree::ptree pt;

    for(int indeks= 0; indeks<5; ++indeks){
        boost::property_tree::ptree name, id, card;
        id.put("Id", mp.p1Table[indeks].first);
        name.put("cardStr", mp.p1.Table[indeks].second);
        card.put("", name);
        card.put("", id);
        pt.add_child("p1Tabl", card);
    }
    write_json("test2.json", pt);

}
