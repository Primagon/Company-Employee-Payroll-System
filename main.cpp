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

    int insertHere=0;

    for(int i=1; i<=allEmployees.size(); i++){
        if(i%numEmployees==0){
            allManagers[insertHere].setManagerSubs(employeeHolder);
            employeeHolder.clear();
            insertHere++;
        }
        employeeHolder.push_back(allEmployees[i-1]);
    }

    vector<Manager> managerHolder;

    insertHere=0;

    for(int i=1; i<=allManagers.size(); i++){
        if(i%numManagers==0){
            allDeptH[insertHere].setDeptHSubs(managerHolder);
            managerHolder.clear();
            insertHere++;
        }
        managerHolder.push_back(allManagers[i-1]);
    }

    boss.setCEOSubs(allDeptH);

    for(int i=0; i<boss.getDepartmentH().size(); i++){
        cout << boss.getDepartmentH()[i].GetName() << endl;
        DepartmentH tempDeptH = boss.getDepartmentH()[i];
        for(int j=0; j<tempDeptH.getManagers().size(); j++){
            cout << "\t" << tempDeptH.getManagers()[j].GetName() << endl;
            Manager tempManager = tempDeptH.getManagers()[j];
            for(int k=0; k<tempManager.getEmployees().size(); k++){
                cout << "\t\t" << tempManager.getEmployees()[k].GetName() << endl;
            }
        }
    }
    // application starts here
    bool active = true;
    string userInput;

    while (active){
        cout << "What would you like to search? Type 'quit' to exit, and 'help' for possible commands: " << ends;
        cin >> userInput;

        if (userInput == "quit"){
            active = false;
        }
        else if (userInput == "help") {
            cout << "The possible commands are: 'help', 'quit', 'employeeid', 'ceo', 'departmentheads', 'managers', 'employees'." << endl;
        }
        else if (userInput == "employeeid") {
            //the code for searching for employeeids prints out their information
        }
        else if (userInput == "ceo") {
            // should list the ceo along with their information
        }
        else if (userInput == "departmentheads"){
            //should list the departmentheads and print out their information
        }
        else if (userInput == "managers"){
            // should list the managers and print out their information
        }
        else if (userInput == "employees") {
            //should list the employees and print out their information
        }
    }
    //application ends here
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