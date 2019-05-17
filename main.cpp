#include "employee.h"
#include "employee.cpp"

int main(){

    Employee Hey();

    Employee Billy("poop", 'B', "Batson", 1, 5);

    cout << Billy.GetEmployeeID() << endl;

    cout << Billy.getName() << endl;

    cout << Billy.GetContactInfo() << endl;

    cout << "dasi" <<std::endl;

    return 0;
}