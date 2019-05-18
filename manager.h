#ifndef MANAGER_H
#define MANAGER_H
#include "employee.h"
#include <vector>

class Manager : public Employee {
    public:
    Manager(char FirstInitial, string LastName, int EmployeeID, int GrossPay);

    ~Manager();

    vector<Employee*> getEmployees();

    void addEmployee(Employee* staff);

    private:
    vector<Employee*> ManagerSubs;
};
#endif
