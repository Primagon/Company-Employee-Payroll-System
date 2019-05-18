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
#include <fstream>

void populateTree(CEO boss);

int main(){

    CEO boss('R', "Giovanni", 1, 200000);
    populateTree(boss);

    Employee bro = boss.getDepartmentH()[1].getManagers()[2].getEmployees()[4];

    cout << bro.GetName() << endl;
    cout << bro.GetEmployeeID() << endl;
    cout << bro.GetContactInfo() << endl;
    cout << bro.GetGrossPay() << endl;

    return 0;
}

void populateTree(CEO boss){

    ifstream myfile;
    myfile.open("randLastName.txt");
    srand(time(NULL));
    vector<string> names;
    int a = 0;
    string line;

    if(myfile.is_open()){
        while(getline (myfile,line)){
            names.push_back(line);
        }
        myfile.close();
    }

    for(int i=1; i<=2; i++){
        int tempID = boss.GetEmployeeID()*10;
        boss.addDepartmentH(DepartmentH((char)(rand()%26+65), names[rand()%61], tempID+i, 150000));
        for(int j=1; j<=3; j++){
            tempID = boss.getDepartmentH()[i].GetEmployeeID()*10;
            boss.getDepartmentH()[i].addManager(Manager((char)(rand()%26+65), names[rand()%61], tempID+j, 100000));
            for(int k=1; k<=5; k++){
                tempID = boss.getDepartmentH()[i].getManagers()[j].GetEmployeeID()*10;
                boss.getDepartmentH()[i].getManagers()[j].addEmployee(Employee((char)(rand()%26+65), names[rand()%61], tempID+k, 75000));
            }
        }
    }
}