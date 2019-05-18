#include"employee.h"
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<string>
using namespace std;

Employee::Employee(char FirstInitial, string LastName, int EmployeeID, int eSalary){
    this->eFirstInitial = FirstInitial;
    this->eLastName = LastName;
    this->EmployeeID = EmployeeID;
    this->eSalary = eSalary;
}

char Employee::getFirstInitial(){
    return eFirstInitial;
}

string Employee::getLastName(){
    return eLastName;
}

string Employee::GetContactInfo(){
    return eFirstInitial + eLastName + "@company.com";
}

int Employee::GetEmployeeID(){
    return EmployeeID;
}

string Employee::GetName(){
    string substitute(1,getFirstInitial());
    return substitute + "." + getLastName();
}

int Employee::GetGrossPay(){
    return eSalary;
}