#ifndef CEO-H
#define CEO_H
#include "departmenth.h"

class Ceo : public DepartmentH {
    public:
    Ceo(
        const string &JobTitle, 
        const string &FirstName, 
        const string &LastName, 
        string ContactInfo,
        int EmployeeID,
        int GrossPay
    );

    ~Ceo();

};
#endif