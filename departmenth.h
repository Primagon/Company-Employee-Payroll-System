#ifndef DEPARTMENTH_H
#define DEPARTMENTH_H
#include "manager.h"

class DepartmentH{
    public:
    DepartmentH(char FirstInitial, string LastName, int EmployeeID, int eSalary);

    string GetName();
    string GetContactInfo();
    int GetEmployeeID();
    int GetGrossPay();
    char getFirstInitial();
    string getLastName();

    vector<Manager> getManagers();
    void addManager(Manager staff);

    private:
    int EmployeeID;
    char eFirstInitial;
    string eLastName;
    int eSalary;
    

    private:
    vector<Manager> DeptHSubs;
};
#endif