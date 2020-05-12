//
//  Deck.hpp
//  Card
//
//  Created by Pranav Raman on 12/20/19.
//  Copyright © 2019 Pranav Raman. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp
#include "Card.h"
#include <algorithm>
class Deck {
public:
    Deck();
    void shuffle();
    std::vector<Card> getDeck(); 
private:
    std::vector<Card> mydeck;
};
#endif /* Deck_hpp */
