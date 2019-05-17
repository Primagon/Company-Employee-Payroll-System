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
    Employee(string JobTitle, char FirstInitial, string LastName, int EmployeeID, int GrossPay);
    
    //~Employee();
    ostream& operator <<(ostream &os);

    string GetJobTtile();
    string GetName();
    string GetContactInfo();
    int GetEmployeeID();
    int GetGrossPay();
    string getName();

        
    void shift_to_root( );
    //Precondition: size() > 0.
    //Postcondition: The "current node" is now the root of the tree.

    void shift_up( );
    //Precondition: has_parent( ) returns true.
    //Postcondition: The "current node" has been shifted up to the parent of
    //the old current node.

    void shift_left( );
    //Precondition: has_left_child( ) returns true.
    //Postcondition: The "current node" been shifted down to the left child
    //of the original current node.

    void shift_right( );
    //Precondition: has_left_child( ) returns true.
    //Postcondition: The "current node" been shifted down to the left child
    //of the original current node.


    private:

    string EmployeeTitle;
    string EmployeeName;
    int EmployeeID;
    vector<string> Employees;
    char eFirstInitial;
    string eLastName;
    int eSalary;

};
#endif