#include "ceo.h"
#include <vector>

vector<DepartmentH> CEOSubs;
vector<DepartmentH> getDepartmentH();
void addDepartmentH(DepartmentH staff);

CEO::CEO(char FirstInitial, string LastName, int EmployeeID, int eSalary){
    this->eFirstInitial = FirstInitial;
    this->eLastName = LastName;
    this->EmployeeID = EmployeeID;
    this->eSalary = eSalary;
}

char CEO::getFirstInitial(){
    return eFirstInitial;
}

string CEO::getLastName(){
    return eLastName;
}

string CEO::GetContactInfo(){
    return eFirstInitial + eLastName + "@company.com";
}

int CEO::GetEmployeeID(){
    return EmployeeID;
}

string CEO::GetName(){
    string substitute(1,getFirstInitial());
    return substitute + "." + getLastName();
}

int CEO::GetGrossPay(){
    return eSalary;
}

vector<DepartmentH> CEO::getDepartmentH(){
    return CEOSubs;
}

void CEO::addDepartmentH(DepartmentH staff){
    CEOSubs.push_back(staff);
}

