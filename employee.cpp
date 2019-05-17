#include "employee.h"
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

Employee::Employee(const string &JobTitle, const char &FirstInitial, const string &LastName, 
string ContactInfo, int EmployeeID, int GrossPay)
{
    this->EmployeeTitle = JobTitle;
    this->eFirstInitial = FirstInitial;
    this->eLastName = LastName;
    //Can someone connect first name and last names? 
    //I want it seperated for the case we have two people with the same last or first name and it'll return them too.
    this->ContactInfo = ContactInfo; //Can someone fix this? should have int for phone #, 
    //and a string for address.
    this->EmployeeID = EmployeeID;
    this->eSalary = GrossPay;
}

Employee::~Employee();

string GetContactInfo(){

}

int GetEmployeeID(){
    return EmployeeID;
}

string getName(){
    return  "" + eFirstInital + ". " + eLastName;
}

string GetGrossPay(){

}

void shift_to_root(){

}

void shift_up( ){

}

void shift_left( ){

}

void shift_right( ){

}