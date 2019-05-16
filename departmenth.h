#ifndef DEPARTMENTH_H
#define DEPARTMENTH_H
#include "employee.h"

class DepartmentH : public Employee {
    public:
    DepartmentH(
        const string &JobTitle, 
        const string &FirstName, 
        const string &LastName, 
        string ContactInfo,
        int EmployeeID,
        int GrossPay
    );

    ~DepartmentH();

};
#endif