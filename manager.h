#ifndef MANAGER_H
#define MANAGER_H
#include "employee.h"

class Manager : public Employee {
    public:
    Manager(
        const string &JobTitle, 
        const string &FirstName, 
        const string &LastName, 
        string ContactInfo,
        int EmployeeID,
        int GrossPay
    );

    ~Manager();

};
#endif
