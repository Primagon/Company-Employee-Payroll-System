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
        int GrossPay,
        );
    
    private:
    string EmployeeTitle;
    string EmployeeName;
    int EmployeeID;


};
#endif