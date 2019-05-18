#ifndef CEO-H
#define CEO_H
#include "departmenth.h"

class Ceo : public DepartmentH {
    public:
    Ceo(char FirstInitial, string LastName, int EmployeeID, int GrossPay);

    ~Ceo();

    vector<DepartmentH*> getDeptHs();
    
    void addDeptH();

    private:
    vector<DepartmentH*> CEOSubs;
};
#endif