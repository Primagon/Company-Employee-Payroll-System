#include "manager.h"
#include <vector>

vector<Employee> ManagerSubs;
vector<Employee> getEmployees();
void addEmployee(Employee staff);

Manager::Manager(char FirstInitial, string LastName, int EmployeeID, int eSalary){
    this->eFirstInitial = FirstInitial;
    this->eLastName = LastName;
    this->EmployeeID = EmployeeID;
    this->eSalary = eSalary;
}

char Manager::getFirstInitial(){
    return eFirstInitial;
}

string Manager::getLastName(){
    return eLastName;
}

string Manager::GetContactInfo(){
    return eFirstInitial + eLastName + "@company.com";
}

int Manager::GetEmployeeID(){
    return EmployeeID;
}

string Manager::GetName(){
    string substitute(1,getFirstInitial());
    return substitute + "., " + getLastName();
}

int Manager::GetGrossPay(){
    return eSalary;
}

vector<Employee> Manager::getEmployees(){
    return ManagerSubs;
}

void Manager::addEmployee(Employee staff){
    ManagerSubs.push_back(staff);
}