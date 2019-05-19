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
#include <queue>

void populateTree(CEO boss);

int main(){

    CEO boss('R', "Giovanni", 1, 200000);

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

    /*for(int i=1; i<=2; i++){
        int tempID = boss.GetEmployeeID()*10;
        DepartmentH tempDepartmentH((char)(rand()%26+65), names[rand()%61], tempID+i, 150000);
        boss.addDepartmentH(tempDepartmentH);
        for(int j=1; j<=3; j++){
            tempID = boss.getDepartmentH()[i-1].GetEmployeeID()*10;
            Manager tempManager((char)(rand()%26+65), names[rand()%61], tempID+j, 100000);
            boss.getDepartmentH()[i-1].addManager(tempManager);
            tempDepartmentH = boss.getDepartmentH()[i-1];
            tempManager =  tempDepartmentH.getManagers()[j-1];
            cout << "\t" + tempManager.GetName() << endl;
            for(int k=1; k<=5; k++){
                tempID*=10;
                Employee tempEmployee((char)(rand()%26+65), names[rand()%61], tempID+k, 75000);
                tempDepartmentH = boss.getDepartmentH()[i-1];
                tempManager = tempDepartmentH.getManagers()[j-1];
                tempManager.addEmployee(tempEmployee);
                //cout << "\t" + tempDepartmentH.getManagers()[j-1].GetName() << endl;
                //tempDepartmentH.getManagers()[j-1].addEmployee(tempEmployee);
                //DepartmentH testing = boss.getDepartmentH()[0];
                //Manager test = testing.getManagers()[0];
                //test.addEmployee(tempEmployee); 
            }
            tempDepartmentH.getManagers()[j-1] = tempManager;
            boss.getDepartmentH()[i-1] = tempDepartmentH;
        }
    }
    
    //populateTree(boss);
/*
    DepartmentH bro = boss.getDepartmentH()[0];
    DepartmentH boi = boss.getDepartmentH()[1];
    //Manager hi = boss.getDepartmentH()[0].getManagers()[0];

    Manager bob('A', "BBBB", 12, 124);

    cout << bob.GetName() << endl;

    cout << bro.GetName() << endl;
    //cout << bro.GetEmployeeID() << endl;
    cout << bro.GetContactInfo() << endl;
    cout << bro.GetGrossPay() << endl;

    cout << boi.GetName() << endl;
    //cout << boi.GetEmployeeID() << endl;
    cout << boi.GetContactInfo() << endl;
    cout << boi.GetGrossPay() << endl;*/

    int numDeptH;
    int numManagers;
    int numEmployees;

    cout << "How many Department Heads under the CEO?\t";
    cin >> numDeptH;
    cout << "How many Managers under each Department Head?\t";
    cin >> numManagers;
    cout << "How many Employees under each Manager?\t\t";
    cin >> numEmployees;

    cout << numDeptH << " Department Head(s), " << numManagers << " Manager(s), " <<
        numEmployees << " Employee(s)" << endl;
    
    vector<Employee> allEmployees;
    vector<Manager> allManagers;
    vector<DepartmentH> allDeptH;

    for(int i=0; i<numDeptH; i++){
        DepartmentH tempDepartmentH((char)(rand()%26+65), names[rand()%61], 1, 150000);
        allDeptH.push_back(tempDepartmentH);
    }

    for(int i=1; i<=numDeptH*numManagers; i++){
        Manager tempManager((char)(rand()%26+65), names[rand()%61], 1, 100000);
        allManagers.push_back(tempManager);
    }

    for(int i=0; i<numDeptH*numManagers*numEmployees; i++){
        Employee tempEmployee((char)(rand()%26+65), names[rand()%61], 1, 75000);
        allEmployees.push_back(tempEmployee);
    }

    vector<Employee> employeeHolder;

    for(int i=1; i<=allEmployees.size(); i++){
        if(i%numEmployees==0){
            allManagers[i].setManagerSubs(employeeHolder);
            employeeHolder.clear();
        }
        employeeHolder.push_back(allEmployees[i-1]);
    }

    vector<Manager> managerHolder;

    for(int i=1; i<=allManagers.size(); i++){
        if(i%numManagers==0){
            allDeptH[i].setDeptHSubs(managerHolder);
            managerHolder.clear();
        }
        managerHolder.push_back(allManagers[i-1]);
    }

    for(int i=0; i<allDeptH.size(); i++){
        boss.setCEOSubs(allDeptH);
    }

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
        DepartmentH temp((char)(rand()%26+65), names[rand()%61], tempID+i, 150000);
        boss.addDepartmentH(temp);
        cout << boss.getDepartmentH()[i-1].GetEmployeeID() << endl;
        for(int j=1; j<=3; j++){
            tempID = boss.getDepartmentH()[i-1].GetEmployeeID()*10;
            boss.getDepartmentH()[i-1].addManager(Manager((char)(rand()%26+65), names[rand()%61], tempID+j, 100000));
            for(int k=1; k<=5; k++){
                tempID = boss.getDepartmentH()[i-1].getManagers()[j-1].GetEmployeeID()*10;
                boss.getDepartmentH()[i-1].getManagers()[j-1].addEmployee(Employee((char)(rand()%26+65), names[rand()%61], tempID+k, 75000));
            }
        }
    }
}