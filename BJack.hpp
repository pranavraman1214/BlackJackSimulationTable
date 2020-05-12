//
//  BJack.hpp
//  Blackjack
//
//  Created by Pranav Raman on 12/20/19.
//  Copyright © 2019 Pranav Raman. All rights reserved.
//

#ifndef BJack_hpp
#define BJack_hpp
#include "Deck.hpp"
#include <stdio.h>
#include <utility>
#include <map>
#include <tuple>
#include <fstream>
class BJack {
public:
    BJack();
    std::map<std::pair<std::pair<std::tuple<Card,Card>,Card>,std::string>,int> winmap;
    void printmapcontents(); 
private:
    void Simulation(int current, int current2, std::vector<Card> deck);
    std::vector<std::string> allpossibilites;
};
#endif /* BJack_hpp */
