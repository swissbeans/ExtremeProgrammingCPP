/* 
 * File:   main.cpp
 * Author: Matt Matney
 *
 * Created on February 10, 2015, 3:14 PM
 */

#include <cstdlib>
//#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;

const int MAX = 210;
int cube[6];
int index = 0;
string permutations[MAX];
int numbers = 0;
int count = 0;


//int combinations[3628800];

string IntToString(int number) {
    std::ostringstream oss;

    // Works just like cout
    oss << number;

    // Return the underlying string
    return oss.str();
}

void generateCombinations() {
    for (int a = 0; a < 10; a++) {
        cube[0] = a;
        for (int b = a + 1; b < 10; b++) {
            cube[1] = b;
            for (int c = b + 1; c < 10; c++) {
                cube[2] = c;
                for (int d = c + 1; d < 10; d++) {
                    cube[3] = d;
                    for (int e = d + 1; e < 10; e++) {
                        cube[4] = e;
                        for (int f = e + 1; f < 10; f++) {
                            cube[5] = f;
                            /*
                            while (numbers < 6) {
                                permutations[index][numbers] = cube[numbers];
                                numbers++;
                                if (numbers == 6) {
                                    numbers = 0;
                                }
                                index++;
                            }
                             * */
                            string result = IntToString(cube[0]) + IntToString(cube[1]) + IntToString(cube[2]) + IntToString(cube[3]) + IntToString(cube[4]) + IntToString(cube[5]);
                            permutations[index] = result;
                            index++;
                            //cout <<  result << endl;
                            //cout << cube[0] << cube[1] << cube[2] << cube[3] << cube[4] << cube[5] << endl;
                        }
                    }
                }
            }
        }
    }
}

bool contains(string one, char a) {
    for (int i = 0; i < 6; i++) {
        //cout << one.at(i) << endl;
        if (one.at(i) == a) {
            
            return true;
        }
    }
    return false;
}

bool validSquare(string array1, string array2, char a, char b) {
    printf("%c\n", a);
    return ((contains(array1, a) && (contains(array2, b))) || (contains(array2, a) && (contains(array1, b))));
}

int checkPermutations(string array[]) {
    for (int i = 0; i < MAX; i++) {
        //cout << i << ": " << permutations[i] << endl;
        //cout << "The current count is: " << count << endl;
        for (int j = i+1; j < MAX; j++) {
            if ((validSquare(permutations[i], permutations[j], '0', '1'))
                    && (validSquare(permutations[i], permutations[j], '0', '4'))
                    && (validSquare(permutations[i], permutations[j], '0', '9'))
                    && (validSquare(permutations[i], permutations[j], '1', '6'))
                    && (validSquare(permutations[i], permutations[j], '2', '5'))
                    && (validSquare(permutations[i], permutations[j], '3', '6'))
                    && (validSquare(permutations[i], permutations[j], '4', '9'))
                    && (validSquare(permutations[i], permutations[j], '6', '4'))
                    && (validSquare(permutations[i], permutations[j], '8', '1'))) {
                count++;
            }
        }
    }
    return count;
}

//void printArray(string array[], int size) {
//    for (int i = 0; i < size; i++) {
//        cout << array[i] << endl;
//    }
//}

int main(int argc, char** argv) {

    generateCombinations();
    cout << checkPermutations(permutations);
    //printArray(permutations, MAX);
//    cout << validSquare(permutations[0], permutations[1], '2', '5') << endl;
//    cout << permutations[0]<< endl;
//    cout << permutations[1];
    return 0;
}