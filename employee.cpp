#include"employee.h"
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<string>
using namespace std;

Employee::Employee(string JobTitle, char FirstInitial, string LastName,
int EmployeeID, int eSalary){
    this->EmployeeTitle = JobTitle;
    this->eFirstInitial = FirstInitial;
    this->eLastName = LastName;
    this->EmployeeID = EmployeeID;
    this->eSalary = eSalary;
}

string Employee::GetContactInfo(){
    return eFirstInitial + eLastName + "@company.com";
}

int Employee::GetEmployeeID(){
    return EmployeeID;
}

string Employee::GetName(){
    string substitute(1,eFirstInitial);
    return substitute + "." + eLastName;
}

int Employee::GetGrossPay(){
    return eSalary;
}

string Employee::GetJobTtile(){
    return EmployeeTitle;
}

void shift_to_root(){

}

void shift_up( ){

}

void shift_left( ){

}

void shift_right( ){

}