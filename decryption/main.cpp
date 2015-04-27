/* 
 * File:   main.cpp
 * Author: Carole
 *
 * Created on April 25, 2015, 3:35 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <regex>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    string line;
    string str;

    ifstream keylog;
    keylog.open("p079_keylog.txt");

    int array[10][10] = {0};
    int count[10] = {0};
    int isItThere[10] = {0};

    if (!keylog) {
        cout << "sorry, bad file.";
        exit(0);
    }
    if (keylog.is_open()) {
        while (getline(keylog, line)) {

            array[atoi(line.substr(0, 1).c_str())][atoi(line.substr(1, 1).c_str())] = 1;
            array[atoi(line.substr(0, 1).c_str())][atoi(line.substr(2, 1).c_str())] = 1;
            array[atoi(line.substr(1, 1).c_str())][atoi(line.substr(2, 1).c_str())] = 1;

        }

        keylog.close();
    }
   
//    while (!keylog.eof()) {
//        string regex_str = "[0-9]";
//        regex reg1(regex_str);
//        int lineno = 0;
//        ++lineno;
//        getline(keylog, str);
//        if (regex_search(str, reg1)) {
//            cout << "Number found at: " << endl << lineno << endl;
//        }
//    }

    for (int row = 0; row < 10; row++) {
        cout << endl;
        for (int col = 0; col < 10; col++) {
            cout << " " << array[row][col];
            if (array[row][col] == 1) {
                count[row]++;
            }
        }
    }

    for (int row = 0; row < 10; row++) {
        cout << endl;
        printf("This is the count of row %d: ", row);
        cout << count[row];
    }

    return 0;
}