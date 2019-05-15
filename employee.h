#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

class Employee
{
    public:
    Employee(
        const string &JobTitle, 
        const string &FirstName, 
        const string &LastName, 
        string ContactInfo,
        int EmployeeID,
        int GrossPay
        );
        
    void shift_to_root( );
    void shift_up( );
    void shift_left( );
    void shift_right( );


    private:
    string EmployeeTitle;
    string EmployeeName;
    int EmployeeID;

};
#endif