/* 
 * File:   main.cpp
 * Author: Matt Matney and Carole Schroeder
 *
 * Created on February 16, 2015, 8:30 PM
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "PokerHand.h"

using namespace std;

int main(int argc, char** argv) {

    PokerHand ph;

    ifstream handHistory("poker.txt");
    string line;
    int lineNumber = 1;
    if (handHistory.is_open()) {
        while (getline(handHistory, line)) {
            cout << lineNumber << ": " << endl;
            
            cout << "Player 1 Hand: " << ph.evaluateHand(ph.getHandPlayer1(ph.removeWhiteSpace(line))) << endl;
            cout << "Player 2 Hand: " << ph.evaluateHand(ph.getHandPlayer2(ph.removeWhiteSpace(line))) << endl;

            cout << ph.compareHands(ph.evaluateHand(ph.getHandPlayer1(ph.removeWhiteSpace(line))), ph.evaluateHand(ph.getHandPlayer2(ph.removeWhiteSpace(line)))) << endl;
            
            cout << endl;
            lineNumber++;
        }
        handHistory.close();
    } else cout << "Unable to open file";

    return 0;
}