/* 
 * File:   PokerHand.h
 * Author: Matt Matney and Carole Schroeder
 *
 * Created on February 20, 2015, 8:58 PM
 */

#ifndef POKERHAND_H_INCLUDED_  // if PokerHand.h hasn't been included yet...
#define	POKERHAND_H_INCLUDED_  // #define this so the compiler knows it has been included

#include <string>


class PokerHand {
public:
    PokerHand();
    //static std::string handRankings [];
    static std::string cardValues;
    
    std::string removeWhiteSpace(std::string);
    
    std::string getHandPlayer1(std::string);
    std::string getHandPlayer2(std::string);
    
    char getHighCard(std::string);
    bool pair(std::string);
    bool twoPair(std::string);
    bool three(std::string);
    bool straight(std::string);
    bool flush(std::string);
    bool fullHouse(std::string);
    bool four(std::string);
    bool straightFlush(std::string);
    bool royalFlush(std::string);
    
    std::string evaluateHand(std::string);
    int getRank(std::string);
    std::string compareHands(std::string, std::string);
};

#endif	/* POKERHAND_H */