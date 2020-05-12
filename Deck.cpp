//
//  Deck.cpp
//  Card
//
//  Created by Pranav Raman on 12/20/19.
//  Copyright © 2019 Pranav Raman. All rights reserved.
//

#include "Deck.hpp"

Deck::Deck() {
    std::vector<std::string> labels = {"Diamonds","Clubs","Spades","Hearts"};
    for (unsigned i = 0; i < labels.size(); i++) {
        for (int j = 1; j < 14; j++) {
            int temp = j;
            if (temp > 10) {
                temp = 10;
            }
            std::string name = std::to_string(temp);
            if (j == 1) {
                name = "A"; 
            }
            if (j == 11) {
                name = "J";
            }
            if (j == 12) {
                name = "Q";
            }
            if (j == 13) {
                name = "K";
            }
            Card deckcard(temp,labels[i],name);
            mydeck.push_back(deckcard);
        }
    }
    //shuffle();
}
std::vector<Card> Deck::getDeck() {
    return mydeck;
}
void Deck::shuffle() {
    std::random_shuffle(mydeck.begin(),mydeck.end());
}
