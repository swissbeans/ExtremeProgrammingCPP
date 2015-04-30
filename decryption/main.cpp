/* 
 * File:   main.cpp
 * Author: Carole Schroeder, with help from Dr. Mec and Matt Matney
 *
 * Created on April 25, 2015, 3:35 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string line;
    ifstream keylog;
    keylog.open("p079_keylog.txt");

    int array[10][10] = {0}; //2d array
    int count[10] = {0}; //array to count the digits within 2d array
    int itIsThere[10] = {0}; //array to verify if a digit is used in keylog
    int keys[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //array of indices for swap

    //if the textfile isn't found, it prints an error
    if (!keylog) {
        cout << "sorry, bad file.";
        exit(0);
    }

    //gets the information from the keylog.txt
    //counts the digits in the successful keys, to make sure they're used
    //puts a 1 into the 2d array if digit 1 comes before 2, if digit 1 comes
    //before 3, and if digit 2 comes before 3.  
    if (keylog.is_open()) {
        while (getline(keylog, line)) {
            int digit1 = atoi(line.substr(0, 1).c_str());
            int digit2 = atoi(line.substr(1, 1).c_str());
            int digit3 = atoi(line.substr(2, 1).c_str());

            itIsThere[digit1]++;
            itIsThere[digit2]++;
            itIsThere[digit3]++;

            array[(digit1)][(digit2)] = 1;
            array[(digit1)][(digit3)] = 1;
            array[(digit2)][(digit3)] = 1;
        }
        keylog.close();
    }

    // loop for finding the used digits used in the secret passcode
    //prints out the 2d array of information, adds up the 1's in the rows
    // prints out the sum of the rows and the index in which they're at
    for (int row = 0; row < 10; row++) {
        if (itIsThere[row] > 0) {
            cout << endl;
            for (int col = 0; col < 10; col++) {
                cout << " " << array[row][col];
                if (array[row][col] == 1) {
                    count[row]++;
                }
            }
            cout << "  =  " << count[row] << " (which is at index: " << row << ")";
        }
    }

    //bubblesort for count, added index array called keys to sort with count, 
    //to give the secret passcode
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10 - i; j++) {
            if (count[j] < count[j + 1]) {
                int swap = count[j];
                count[j] = count[j + 1];
                count[j + 1] = swap;
                swap = keys[j];
                keys[j] = keys[j + 1];
                keys[j + 1] = swap;
            }
        }
    }

    //print out the passcode
    printf("\n\nThis is the secret passcode: \n");
    for (int c = 1; c < 9; c++) {
        cout << keys[c] << " ";
    }

    return 0;
}