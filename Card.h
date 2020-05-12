//
//  Card.h
//  Card
//
//  Created by Pranav Raman on 12/20/19.
//  Copyright © 2019 Pranav Raman. All rights reserved.
//

#ifndef Card_h
#define Card_h
#include <string>
#include <iostream>
#include <vector>
class Card {
public:
    Card(int num, std::string svalue,std::string namein);
    std::vector<int> getValue();
    std::string getSuit();
    std::string getName();
    friend std::ostream & operator << (std::ostream &out, const Card &c);
    bool operator < (const Card& str) const {
        return (values[0] < str.values[0]);
    }
private:
    std::vector<int> values;
    std::string suit;
    std::string name;
};
#endif /* Card_h */

