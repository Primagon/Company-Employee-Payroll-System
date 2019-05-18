#include "employee.h"
#include "employee.cpp"
#include "manager.h"
#include "manager.cpp"
#include "departmenth.h"
#include "departmenth.cpp"
#include "ceo.h"
#include "ceo.cpp"
#include <vector>
#include <cmath>
#include <ctime>

void populateTree(CEO boss);

int main(){

    CEO boss('R', "Giovanni", 1, 200000);
    populateTree(boss);

    /*Employee Hey('C', "Dwayne", 23312, 3); // defining the employees here
    Employee Billy('B', "Batson", 13345, 5);
    Employee Dude('F', "Jay", 44152, 8);

    Employee Boy('V', "Gary", 2222, 4);
    Employee Girl('Q', "Jane", 54433, 66);
    Employee Nonbinary('M', "What", 22434, 66);

    Employee Cyan('L', "Crayola", 4322, 4344);
    Employee Blue('N', "Nice", 1233, 6336);
    Employee Red('G', "Rose", 15634, 2466);

    Manager Jerry('J', "Gerald", 1245, 2); // defining the managers here
    Jerry.addEmployee(Hey);
    Jerry.addEmployee(Billy);
    Jerry.addEmployee(Dude);

    Manager Constant('R', "Constant", 7788, 98);
    Constant.addEmployee(Boy);
    Constant.addEmployee(Girl);
    Constant.addEmployee(Nonbinary);

    Manager Goon('X', "Sigg", 6655, 1123);
    Goon.addEmployee(Cyan);
    Goon.addEmployee(Blue);
    Goon.addEmployee(Red);

    DepartmentH Fire('F', "Why", 112345, 1065); // defining the department heads here
    Fire.addManager(Constant);
    Fire.addManager(Jerry);

    DepartmentH Water('W', "Cold", 223445, 1084);
    Water.addManager(Goon);

    CEO God('Z', "God", 10001, 9999); // defining the ceo here
    God.addDepartmentH(Fire);
    God.addDepartmentH(Water);*/

    vector<Employee> temp;
    vector<Manager> manage;
    vector<DepartmentH> dept;
    vector<CEO> chief;
 
    for(int i=0; i<Jerry.getEmployees().size(); i++){
        temp.push_back(Jerry.getEmployees()[i]);
    }

    for(int i=0; i<Constant.getEmployees().size(); i++){
        temp.push_back(Constant.getEmployees()[i]);
    }

    for(int i=0; i<Goon.getEmployees().size(); i++){
        temp.push_back(Goon.getEmployees()[i]);
    }
    for(int i=0; i<temp.size(); i++){
        cout << "Name:" <<temp[i].GetName() << ", EmployeeID: "<< temp[i].GetEmployeeID() <<  endl;
    }

    return 0;
}

void populateTree(CEO boss){
    srand(time(NULL));
    for(int i=0; i<2; i++){
        boss.addDepartmentH();
    }
}