/* 
 * File:   PokerHand.cpp
 * Author: Matt Matney and Carole Schroeder
 * 
 * Created on February 20, 2015, 8:58 PM
 */

#include <stdio.h>

#include "PokerHand.h"
#include <algorithm>    //std::remove
#include <iostream>



using namespace std;

PokerHand::PokerHand() {

}

//string PokerHand::handRankings [] = {"High Card", "One Pair", "Two Pair",
//    "Three of a Kind", "Straight", "Flush", "Full House", "Four of a Kind",
//    "Straight Flush", "Royal Flush"};

string PokerHand::cardValues = "23456789TJQKA";

string PokerHand::removeWhiteSpace(string line) {
    line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
    return line;
}

string PokerHand::getHandPlayer1(string line) {
    string cards = line.substr(0, line.length() / 2);
    return cards;
}

string PokerHand::getHandPlayer2(string line) {
    string cards = line.substr(line.length() / 2, line.size());
    return cards;
}

char PokerHand::getHighCard(string hand) {
    int value;
    char highCard = hand.at(0);
    for (int i = 2; i < hand.length(); i += 2) {
        value = cardValues.find(hand.at(i));
        if (value > cardValues.find(highCard)) {
            highCard = hand.at(i);
        }
    }
    return highCard;
}

bool PokerHand::pair(string hand) {
    for (int i = 0; i < hand.length(); i += 2) {
        for (int j = i + 2; j < hand.length(); j += 2) {
            if (hand.at(i) == hand.at(j)) {
                return true;
            }
        }
    }
    return false;
}

bool PokerHand::twoPair(string hand) {
    for (int i = 0; i < hand.length(); i += 2) {
        for (int j = i + 2; j < hand.length(); j += 2) {
            if (hand.at(i) == hand.at(j)) {
                for (int h = 0; h < hand.length(); h += 2) {
                    for (int k = h + 2; k < hand.length(); k += 2) {
                        if (hand.at(h) == hand.at(k) && hand.at(i) != hand.at(h)) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool PokerHand::three(string hand) {
    for (int i = 0; i < hand.length(); i += 2) {
        for (int j = i + 2; j < hand.length(); j += 2) {
            for (int h = j + 2; h < hand.length(); h += 2) {
                if (hand.at(i) == hand.at(j) && hand.at(i) == hand.at(h)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool PokerHand::straight(string hand) {
    while (cardValues.find(getHighCard(hand)) > 5) {
        return (((hand.find(cardValues.at(cardValues.find(getHighCard(hand)))) != string::npos))
                && (hand.find(cardValues.at(cardValues.find(getHighCard(hand)) - 1)) != string::npos)
                && (hand.find(cardValues.at(cardValues.find(getHighCard(hand)) - 2)) != string::npos)
                && (hand.find(cardValues.at(cardValues.find(getHighCard(hand)) - 3)) != string::npos)
                && (hand.find(cardValues.at(cardValues.find(getHighCard(hand)) - 4)) != string::npos));
    }
    return false;
}

bool PokerHand::flush(string hand) {
    return (hand.at(1) == hand.at(3) && hand.at(3) == hand.at(5) && hand.at(5) == hand.at(7) && hand.at(7) == hand.at(9));
}

bool PokerHand::fullHouse(string hand) {
    if (three(hand) && pair(hand)) {
        for (int i = 0; i < hand.length(); i += 2) {
            for (int j = i + 2; j < hand.length(); j += 2) {
                for (int h = j + 2; h < hand.length(); h += 2) {
                    if (hand.at(i) != hand.at(j) && hand.at(i) != hand.at(h) && hand.at(j) != hand.at(h)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}

bool PokerHand::four(string hand) {
    for (int i = 0; i < hand.length(); i += 2) {
        for (int j = i + 2; j < hand.length(); j += 2) {
            for (int h = j + 2; h < hand.length(); h += 2) {
                for (int k = h + 2; k < hand.length(); k += 2) {
                    if (hand.at(i) == hand.at(j) && hand.at(i) == hand.at(h) && hand.at(i) == hand.at(k)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool PokerHand::straightFlush(string hand) {
    return (straight(hand) && flush(hand) && getHighCard(hand) != 'A');
}

bool PokerHand::royalFlush(string hand) {
    return (straight(hand) && flush(hand) && getHighCard(hand) == 'A');

    //    return (((hand.find("T") != string::npos) && (hand.find("J") != string::npos) && (hand.find("Q") != string::npos) && (hand.find("K") != string::npos) && (hand.find("A") != string::npos))
    //            && (hand.at(1) == hand.at(3) && hand.at(3) == hand.at(5) && hand.at(5) == hand.at(7) && hand.at(7) == hand.at(9)));
}

string PokerHand::evaluateHand(string hand) {
    if (royalFlush(hand)) return "Royal Flush";

    else if (straightFlush(hand)) return "Straight Flush";

    else if (four(hand)) return "Four of a Kind";

    else if (fullHouse(hand)) return "Full House";

    else if (flush(hand)) return "Flush";

    else if (straight(hand)) return "Straight";

    else if (three(hand)) return "Three of a Kind";

    else if (twoPair(hand)) return "Two Pair";

    else if (pair(hand)) return "Pair";

    else return "High Card";
}

int PokerHand::getRank(string hand) {
    if (hand == "Royal Flush") return 10;

    else if (hand == "Straight Flush") return 9;

    else if (hand == "Four of a Kind") return 8;

    else if (hand == "Full House") return 7;

    else if (hand == "Flush") return 6;

    else if (hand == "Straight") return 5;

    else if (hand == "Three of a Kind") return 4;

    else if (hand == "Two Pair") return 3;

    else if (hand == "Pair") return 2;

    else return 1;
}

string PokerHand::compareHands(string hand1, string hand2) {
    if (getRank(hand1) > getRank(hand2)) {
        return "Player 1 Wins!";
    } else if (getRank(hand1) < getRank(hand2)) {
        return "Player 2 Wins!";
    } else {
        return "tie!";
    }
}