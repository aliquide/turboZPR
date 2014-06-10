#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"
#include "jMockUp.h"

using namespace std;
using boost::property_tree::ptree;
using boost::property_tree::basic_ptree;

boost::property_tree::ptree toJson(jMockUp mp){

    boost::property_tree::ptree pt, p1Table;

    for(int indeks= 0; indeks<5; ++indeks){
        boost::property_tree::ptree name, id, card;
        card.put("Id", mp.p1Table[indeks].first);
        card.put("cardStr", mp.p1Table[indeks].second);
        p1Table.push_back(std::make_pair("",card));
    }
       pt.add_child("p1Tabl", p1Table);
       std::cout<<"hue hue" <<std::endl;
    write_json("test2.json", pt);
    return pt;
}
