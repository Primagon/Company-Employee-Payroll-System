#ifndef DEPARTMENTH_H
#define DEPARTMENTH_H
#include "manager.h"

class DepartmentH : public Manager {
    public:
    DepartmentH(
        const string &JobTitle, 
        const string &FirstName, 
        const string &LastName,
        int EmployeeID,
        int GrossPay
    );

    ~DepartmentH();

};
#endif