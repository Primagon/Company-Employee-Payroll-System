#include "employee.h"
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

Employee::Employee(string JobTitle, char FirstInitial, string LastName,
int EmployeeID, int GrossPay){
    this->EmployeeTitle = JobTitle;
    this->eFirstInitial = FirstInitial;
    this->eLastName = LastName;
    this->EmployeeID = EmployeeID;
    this->eSalary = GrossPay;
}

//Employee::~Employee();

string Employee::GetContactInfo(){
    return eFirstInitial + eLastName + "@company.com";
}

int Employee::GetEmployeeID(){
    return EmployeeID;
}

string Employee::getName(){
    return  eFirstInitial + ". " + eLastName;
}

string GetGrossPay(){
    return eSalary;
}

void shift_to_root(){

}

void shift_up( ){

}

void shift_left( ){

}

void shift_right( ){

}