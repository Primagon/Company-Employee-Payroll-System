#ifndef MANAGER_H
#define MANAGER_H
#include "employee.h"
#include <vector>

class Manager{
    public:
    Manager(char FirstInitial, string LastName, int EmployeeID, int eSalary);

    string GetName();
    string GetContactInfo();
    int GetEmployeeID();
    int GetGrossPay();
    char getFirstInitial();
    string getLastName();

    vector<Employee> getEmployees();
    void addEmployee(Employee staff);
    void setManagerSubs(vector<Employee> ManagerSubs);

    private:
    int EmployeeID;
    char eFirstInitial;
    string eLastName;
    int eSalary;
    
    vector<Employee> ManagerSubs;
};
#endif
