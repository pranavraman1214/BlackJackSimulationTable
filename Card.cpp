//
//  Card.cpp
//  Card
//
//  Created by Pranav Raman on 12/20/19.
//  Copyright © 2019 Pranav Raman. All rights reserved.
//
#include "Card.h"
Card::Card(int num, std::string svalue, std::string namein) {
    values.push_back(num);
    if (namein == "A") {
         values.clear(); 
         values.push_back(11);
    }
    name = namein;
    suit = svalue;
}

std::vector<int> Card::getValue() {
    return values;
}
std::string Card::getSuit() {
    return suit;
}
std::string Card::getName() {
    return name;
}
std::ostream & operator << (std::ostream &out, const Card &c) {
    out << c.name << " of " << c.suit;
    return out;
}

