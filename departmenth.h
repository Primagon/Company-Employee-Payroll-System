#ifndef DEPARTMENTH_H
#define DEPARTMENTH_H
#include "manager.h"

class DepartmentH : public Manager {
    public:
    DepartmentH(char FirstInitial, string LastName, int EmployeeID, int GrossPay);

    ~DepartmentH();

    Manager* getManagers();
    
    void addManager();

    private:
    vector<Manager*> DeptHSubs;
};
#endif