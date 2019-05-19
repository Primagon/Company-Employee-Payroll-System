#ifndef CEO_H
#define CEO_H
#include "departmenth.h"

class CEO{
    public:
    CEO(char FirstInitial, string LastName, int EmployeeID, int eSalary);

    string GetName();
    string GetContactInfo();
    int GetEmployeeID();
    int GetGrossPay();
    char getFirstInitial();
    string getLastName();

    vector<DepartmentH> getDepartmentH();
    void addDepartmentH(DepartmentH staff);
    void setCEOSubs(vector<DepartmentH> CEOSubs);

    private:
    int EmployeeID;
    char eFirstInitial;
    string eLastName;
    int eSalary;
    
    private:
    vector<DepartmentH> CEOSubs;
};
#endif