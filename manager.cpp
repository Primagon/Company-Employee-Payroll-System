#include "manager.h"

Manager::Manager(char FirstInitial, string LastName, int EmployeeID, int eSalary){
    this->eFirstInitial = FirstInitial;
    this->eLastName = LastName;
    this->EmployeeID = EmployeeID;
    this->eSalary = eSalary;
    this->ManagerSubs.clear();
}

Manager::vector<Employee*> getEmployees(){
    return ManagerSubs;
}

Manager::void addEmployees(Employee* staff){
    ManagerSubs.push_back(staff);
}