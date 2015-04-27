/* 
 * File:   main.cpp
 * Author: Carole Schroeder and Joel Atyas
 *
 * Created on March 23, 2015, 4:43 PM
 */

#include <cstdlib>

#include "Employee.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
 
    Employee newEmp(1234, "Pat", 15.75);
    
    cout << "Employee:" << endl;
    cout << "\tName:  " << newEmp.getName() << endl;
    cout << "\tID:  " << newEmp.getId() << endl;
    cout << "\tPay Rate:  " << newEmp.getPayRate() << endl;
    cout << "\tGross Pay (40hr):  " << newEmp.grossPay(40) << endl;
    cout << "\tNet Pay (40hr):  " << newEmp.netPay(40) << endl;

    
    return 0;
}

