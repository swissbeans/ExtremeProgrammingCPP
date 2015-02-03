/* 
 * File:   main.cpp
 * Author: Carole Schroeder
 * version: 1.00
 *
 * Created on January 25, 2015, 5:02 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;



int UpperBound;

//this is taking the input from the user, and implementing into the for loop
int multiplesOrderN(){
    int total = 0;
    
    for (int i = 1; i < UpperBound; i++){
        if((i%3 == 0) || (i%5 == 0)){
            total = total + i;
        }
    }
    cout << "This is Order(n) of your upper bound: ";
    cout << total;
    cout << endl;
  }

//this is O(1), taking the parameters and entering it into an equation
int multiplesOrderOne(){
    int t = 3;
    int u = 5;
    int v = 15;
    int w = 999;
    int x = w / t;
    int y = w / u;
    int z = w / v;
    cout << endl;
    cout << "This is Order(1) of 1000: ";
    cout << (t * x * (x + 1) / 2) + (u * y * (y + 1) / 2) - (v * z * (z + 1) / 2);
    cout << endl;
}



int orderOneWithInput(){
    int t = 3;
    int u = 5;
    int v = 15;
    int w = UpperBound - 1;
    int x = w/t;
    int y = w/u;
    int z = w/v;
    cout << endl;
    cout << ("This is Order(1) of your upper bound: ");
    cout << (t * x * (x + 1) / 2) + (u * y * (y + 1) / 2) - (v * z * (z + 1) / 2);
    cout << endl;
}


int main(int argc, char** argv) {
    cout << "Enter the upper bound: " << endl;
    cin >> UpperBound;
    
    multiplesOrderN();
    multiplesOrderOne();
    
    orderOneWithInput();
    return 0;
}

