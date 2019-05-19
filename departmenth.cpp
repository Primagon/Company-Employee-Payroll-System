#include "departmenth.h"
#include <vector>

vector<Manager> DeptHSubs;
vector<Manager> getManagers();
void addManager(Manager staff);

DepartmentH::DepartmentH(char FirstInitial, string LastName, int EmployeeID, int eSalary){
    this->eFirstInitial = FirstInitial;
    this->eLastName = LastName;
    this->EmployeeID = EmployeeID;
    this->eSalary = eSalary;
}

char DepartmentH::getFirstInitial(){
    return eFirstInitial;
}

string DepartmentH::getLastName(){
    return eLastName;
}

string DepartmentH::GetContactInfo(){
    return eFirstInitial + eLastName + "@company.com";
}

int DepartmentH::GetEmployeeID(){
    return EmployeeID;
}

string DepartmentH::GetName(){
    string substitute(1,getFirstInitial());
    return substitute + "." + getLastName();
}

int DepartmentH::GetGrossPay(){
    return eSalary;
}

vector<Manager> DepartmentH::getManagers(){
    return DeptHSubs;
}

void DepartmentH::addManager(Manager staff){
    DeptHSubs.push_back(staff);
}

void DepartmentH::setDeptHSubs(vector<Manager> newDeptHSubs){
    DeptHSubs.clear();
    for(int i=0; i<newDeptHSubs.size(); i++){
        DeptHSubs.push_back(newDeptHSubs[i]);
    }
}