//
//  BJack.cpp
//  Blackjack
//
//  Created by Pranav Raman on 12/20/19.
//  Copyright © 2019 Pranav Raman. All rights reserved.
//

#include "BJack.hpp"

void permutationcalculator() {
    
}

BJack::BJack() {
    
    for (int i = 0; i < 4; i++) {
        std::string all = "";
        for (int j = 0; j < i; j++) {
            all += "1";
        }
        all += "0";
        allpossibilites.push_back(all);
    }
    Deck mydeck;
    std::vector<Card> deck = mydeck.getDeck();
    for (int i = 0; i < 500; i++) {
        std::cout << i << std::endl;
        for (int j = 0; j < deck.size(); j++) {
            for (int z = j; z < deck.size(); z++) {
                if (j == z) {
                    continue;
                } else {
                    Simulation(j, z, deck);
                }
            }
        }
    }
    printmapcontents();
}


void BJack::Simulation(int current, int current2, std::vector<Card> deck) {
    std::vector<int> myints;
    std::vector<int> userints;
    for (int klip = 0; klip < deck.size(); klip++) {
        for (int drip = 0; drip < deck.size(); drip++) {
            if (drip == klip || drip == current || drip == current2 || klip == current || klip == current2) {
                continue;
            } else {
                int rand1 = klip;
                int rand2 = drip;
                for (int i = 0; i < allpossibilites.size(); i++) {
                    userints.push_back(current);
                    userints.push_back(current2);
                    myints.push_back(current);
                    myints.push_back(current2);
                    myints.push_back(rand1);
                    myints.push_back(rand2);
                    bool winnerfound = false;
                    int dealersum = 0;
                    int usersum = 0;
                    for (int j = 0; j < allpossibilites[i].size(); j++) {
                        char choice = allpossibilites[i][j];
                        if (choice == '0') {
                            // Dealer Draws Till 17
                            std::vector<int> dealercards;
                            dealercards.push_back(rand1);
                            dealercards.push_back(rand2);
                            dealersum = 0;
                            std::vector<Card> dealercardobjs;
                            while (dealersum < 17) {
                                int rand3 = rand() % deck.size();
                                while (std::find(myints.begin(), myints.end(), rand3) != myints.end()) {
                                       rand3 = rand() % deck.size();
                                }
                                myints.push_back(rand3);
                                dealercards.push_back(rand3);
                                for (int q = 0; q < dealercards.size(); q++) {
                                    dealercardobjs.push_back(deck[dealercards[q]]);
                                }
                                std::sort(dealercardobjs.begin(),dealercardobjs.end());
                                int num = 0;
                                for (int q = 0; q < dealercardobjs.size(); q++) {
                                    num += dealercardobjs[q].getValue()[0];
                                    if (num > 21 && dealercardobjs[q].getValue()[0] == 11) {
                                        num = num - 10;
                                    }
                                }
                                dealersum = num;
                            }
                            
                            // Sums up the users cards
                            std::vector<Card> usercards;
                            for (int q = 0; q < userints.size(); q++) {
                                usercards.push_back(deck[userints[q]]);
                            }
                            std::sort(usercards.begin(),usercards.end());
                            for (int q = 0; q < usercards.size(); q++) {
                                usersum += usercards[q].getValue()[0];
                                if (usersum > 21 && usercards[q].getValue()[0] == 11) {
                                    usersum += -10;
                                }
                            }
                            
                            // Rule Checking
                            if (usersum > 21) {
                                winnerfound = false;
                                break;
                            }
                            if (dealersum > 21) {
                                winnerfound = true;
                                break;
                            }
                            if (usersum <= 21 && usersum > dealersum) {
                                winnerfound = true;
                                break;
                            } else {
                                winnerfound = false;
                                break;
                            }
                        } else if (choice == '1') {
                            if (myints.size() < 52) {
                                int rand3 = rand() % deck.size();
                                while (std::find(myints.begin(), myints.end(), rand3) != myints.end()) {
                                    rand3 = rand() % deck.size();
                                }
                                //std::cout << "Player Hit: " << deck[rand3] << std::endl;
                                myints.push_back(rand3);
                                userints.push_back(rand3);
                            }
                        }
                    }
                    //Creates map of dealers
                    std::tuple<Card,Card> usercards = std::make_tuple(deck[current],deck[current2]);
                    std::pair<std::tuple<Card,Card>, Card> cardpairs(usercards,deck[rand1]);
                    std::pair<std::pair<std::tuple<Card,Card>, Card>,std::string> choicepair(cardpairs,allpossibilites[i]);
                    if (winmap.find(choicepair) != winmap.end()) {
                        if (winnerfound) {
                            winmap[choicepair] += 1;
                        } else {
                            winmap[choicepair] += -1;
                        }
                    } else {
                        if (winnerfound) {
                            winmap[choicepair] = 1;
                        } else {
                            winmap[choicepair] = -1;
                        }
                    }
                    
                    //Prints out what happened in the game
                    /*std::cout << "Choices: " << allpossibilites[i] << std::endl;
                    std::cout << "User Card 1: " << deck[current] << std::endl;
                    std::cout << "User Card 2: " << deck[current2] << std::endl;
                    std::cout << "Dealer Card 1: " << deck[rand1] << std::endl;
                    std::cout <<"Dealer Sum: " << dealersum << std::endl;
                    std::cout <<"User Sum: " << usersum << std::endl;
                    std::cout <<"Winner: " << winnerfound << std::endl;
                    std::cout << std::endl;*/
                    //Resets Sums
                    dealersum = 0;
                    usersum = 0;
                    userints.clear();
                    myints.clear();
                }
            }
        }
    }
    
    
    
    
    
    
    
    
}

void BJack::printmapcontents() {
    std::ofstream excel;
    std::cout << "In print map contents" << std::endl;
    excel.open("/Users/pranavraman/Documents/Blackjack/Blackjack/data.csv");
    excel << "User Card 1 , User Card 2, Dealer Card, Choice, Frequency" << std::endl;
    for (auto it = winmap.begin(); it != winmap.end(); ++it) {
           std::pair<std::pair<std::tuple<Card,Card>, Card>,std::string> choicepair = it -> first;
        int myint = it -> second;
        std::string choice = choicepair.second;
        std::pair<std::tuple<Card,Card>, Card> mycards = choicepair.first;
        std::tuple<Card,Card> usercards = mycards.first;
        Card card1 = std::get<0>(usercards);
        std::string cards1 = card1.getName() + " of " + card1.getSuit();
        Card card2 = std::get<1>(usercards);
        std::string cards2 = card2.getName() + " of " + card2.getSuit();
        Card dealercard = mycards.second;
        std::string dealer = dealercard.getName() + " of " + dealercard.getSuit();
        excel <<  cards1 + " , " + cards2 + " , " + dealer + " , " + choice + " , " + std::to_string(myint) << std::endl;
    }
    excel.close();
}

