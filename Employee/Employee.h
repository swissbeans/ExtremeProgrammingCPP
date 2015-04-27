///* 
// * File:   Employee.h
// * Author: Carole Schroeder and Joel Atyas
// *
// * Created on March 23, 2015, 4:45 PM
// */



#ifndef __HW4__Employee__
#define __HW4__Employee__

#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

class Employee
{
private:
    
    int eID;
    std::string name;
    double payRate;
    
public:
    
    const double TAX_RATE = 0.25;
    
    //constructors
    Employee();
    
    Employee(const Employee& orig);
    
    Employee(int newId, std::string newName, double newPayRate);
    
    //accessor methods
    int getId() const;
    std::string getName() const;
    double getPayRate() const;
    double grossPay(double hours) const;
    double netPay(double hours) const;
    
    //mutator methods
    void setName(std::string newName);
    
    friend std::ostream &operator<<(std::ostream &output, const Employee emp);
    
};

class HourlyEmployee : public Employee
{
private:
    double payRate;
    
public:
    //constructors
    HourlyEmployee();
    
    HourlyEmployee(const HourlyEmployee& orig);
    
    HourlyEmployee(int newId, std::string newName, double newPayRate);
    
    friend std::ostream &operator<<(std::ostream &output, const HourlyEmployee hEmp);
    
};

#endif /* defined(__HW4__Employee__) */