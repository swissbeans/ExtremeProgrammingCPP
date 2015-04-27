///* 
// * File:   Employee.cpp
// * Author: Carole Schroeder and Joel Atyas
// * 
// * Created on March 23, 2015, 4:45 PM
// */


#include "Employee.h"

Employee::Employee()
{
    this->eID = 0;
    this->name = "";
    this->payRate = 0.0;
}

Employee::Employee(const Employee& orig)
{
    this->eID = orig.getId();
    this->name = orig.getName();
    this->payRate = orig.getPayRate();
}

Employee::Employee(int newId, std::string newName, double newPayRate)
{
    this->eID = newId;
    this->name = newName;
    this->payRate = newPayRate;
}

int Employee::getId() const
{
    return this->eID;
}

std::string Employee::getName() const
{
    return this->name;
}

double Employee::getPayRate() const
{
    return this->payRate;
}

double Employee::grossPay(double hours) const
{
    return hours*this->payRate;
}

double Employee::netPay(double hours) const
{
    return (1-TAX_RATE)*hours*this->payRate;
}

void Employee::setName(std::string newName)
{
    this->name = newName;
}


HourlyEmployee::HourlyEmployee(int newId, std::string newName, double newPayRate):
    Employee(newId, newName, newPayRate)
{
    
}

HourlyEmployee::HourlyEmployee(const HourlyEmployee& orig):
    Employee(orig)
{
    
}

std::ostream &operator<<(std::ostream &output, const Employee emp)
{
    return std::cout << "";
}


std::ostream &operator<<(std::ostream &output, const HourlyEmployee hEmp)
{
    return std::cout << "";
}
