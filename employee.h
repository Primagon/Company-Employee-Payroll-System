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
    Employee(char FirstInitial, string LastName, int EmployeeID, int eSalary);
    
    ~Employee(){};

    string GetName();
    string GetContactInfo();
    int GetEmployeeID();
    int GetGrossPay();
    char getFirstInitial();
    string getLastName();

    private:
    int EmployeeID;
    char eFirstInitial;
    string eLastName;
    int eSalary;
};
#endif