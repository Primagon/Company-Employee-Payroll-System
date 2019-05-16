#ifndef CEO-H
#define CEO_H
#include "employee.h"

class Ceo : public Employee {
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