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
    string lname;
    int emplid;
    while (active){

        cout << "What would you like to search? Type 'quit' to exit, and 'help' for possible commands: " << ends;
        cin >> userInput;

        if (userInput == "quit"){
            active = false;
        }
        else if (userInput == "help") {
            cout << "The possible commands are: 'help', 'quit', Lastname, EmployeeID, CEO, DeptH, Managers, Employees " << endl;
        }
        else if (userInput == "EmployeeID") {
            cout<<"What is the Employee ID?"<<endl;
            cin>>emplid;
            if(emplid == boss.GetEmployeeID()){
                cout<<boss.GetName()<<endl;
                cout<<"Position: CEO"<<endl;
                cout<<"Contact Info: "<<boss.GetContactInfo()<<endl;
                cout<<"Employee ID: "<<boss.GetEmployeeID()<<endl;
                cout<<"Gross Pay: "<<boss.GetGrossPay()<<endl;
            }
            else{
                for(int i=0; i<allDeptH.size(); i++){
                    
                    //allDeptH[i];
                    if(emplid == allDeptH[i].GetEmployeeID()){
                    cout<<allDeptH[i].GetName()<<endl;
                    cout<<"Position: Department Head"<<endl;
                    cout<<"Contact Info: "<<allDeptH[i].GetContactInfo()<<endl;
                    cout<<"Employee ID: "<<allDeptH[i].GetEmployeeID()<<endl;
                    cout<<"Gross Pay: "<<allDeptH[i].GetGrossPay()<<endl;
                    }
                }
                for(int i=0; i<allManagers.size(); i++){
                    allManagers[i];
                    if(emplid == allManagers[i].GetEmployeeID()){
                    cout<<allManagers[i].GetName()<<endl;
                    cout<<"Position: Manager"<<endl;
                    cout<<"Contact Info: "<<allManagers[i].GetContactInfo()<<endl;
                    cout<<"Employee ID: "<<allManagers[i].GetEmployeeID()<<endl;
                    cout<<"Gross Pay: "<<allManagers[i].GetGrossPay()<<endl;
                    }
                }
                for(int i=0; i<allEmployees.size(); i++){
                    allEmployees[i];
                    if(emplid == allEmployees[i].GetEmployeeID()){
                    cout<<allEmployees[i].GetName()<<endl;
                    cout<<"Position: Employee"<<endl;
                    cout<<"Contact Info: "<<allEmployees[i].GetContactInfo()<<endl;
                    cout<<"Employee ID: "<<allEmployees[i].GetEmployeeID()<<endl;
                    cout<<"Gross Pay: "<<allEmployees[i].GetGrossPay()<<endl;
                    }
                }
            }
        }
        else if (userInput == "Lastname") {
            //ask what is the last name
            cout<<"What is the last name?"<<endl;
            cin>>lname;
            if(lname == boss.getLastName()){
                cout<<boss.GetName()<<endl;
                cout<<"Position: CEO"<<endl;
                cout<<"Contact Info: "<<boss.GetContactInfo()<<endl;
                cout<<"Employee ID: "<<boss.GetEmployeeID()<<endl;
                cout<<"Gross Pay: "<<boss.GetGrossPay()<<endl;
            }
            else{
                for(int i=0; i<allDeptH.size(); i++){
                    allDeptH[i];
                    if(lname == allDeptH[i].getLastName()){
                    cout<<allDeptH[i].GetName()<<endl;
                    cout<<"Position: Department Head"<<endl;
                    cout<<"Contact Info: "<<allDeptH[i].GetContactInfo()<<endl;
                    cout<<"Employee ID: "<<allDeptH[i].GetEmployeeID()<<endl;
                    cout<<"Gross Pay: "<<allDeptH[i].GetGrossPay()<<endl;
                    }
                }
                for(int i=0; i<allManagers.size(); i++){
                    allManagers[i];
                    if(lname == allManagers[i].GetName()){
                    cout<<allManagers[i].GetName()<<endl;
                    cout<<"Position: Manager"<<endl;
                    cout<<"Contact Info: "<<allManagers[i].GetContactInfo()<<endl;
                    cout<<"Employee ID: "<<allManagers[i].GetEmployeeID()<<endl;
                    cout<<"Gross Pay: "<<allManagers[i].GetGrossPay()<<endl;
                    }
                }
                for(int i=0; i<allEmployees.size(); i++){
                    allEmployees[i];
                    if(lname == allEmployees[i].GetName()){
                    cout<<allEmployees[i].GetName()<<endl;
                    cout<<"Position: Employee"<<endl;
                    cout<<"Contact Info: "<<allEmployees[i].GetContactInfo()<<endl;
                    cout<<"Employee ID: "<<allEmployees[i].GetEmployeeID()<<endl;
                    cout<<"Gross Pay: "<<allEmployees[i].GetGrossPay()<<endl;
                    }
                }
            }
        }
        else if(userInput == "CEO"){
            //list ceo
            cout<<boss.GetName()<<endl;
        }
        else if(userInput == "DeptH"){
            //list department heads
            for(int i=0; i<boss.getDepartmentH().size(); i++){
                DepartmentH tempDeptH = boss.getDepartmentH()[i];
                cout << boss.getDepartmentH()[i].GetName() << endl;
            } 
        }
        else if(userInput == "Managers"){
            for(int i=0; i<boss.getDepartmentH().size(); i++){
                DepartmentH tempDeptH = boss.getDepartmentH()[i];
                for(int j=0; j<tempDeptH.getManagers().size(); j++){
                    cout << "\t" << tempDeptH.getManagers()[j].GetName() << endl;
                    Manager tempManager = tempDeptH.getManagers()[j];
                }
            } 
        }
        else if(userInput == "Employees"){
            //list employees
            for(int i=0; i<boss.getDepartmentH().size(); i++){
                DepartmentH tempDeptH = boss.getDepartmentH()[i];
                for(int j=0; j<tempDeptH.getManagers().size(); j++){
                    Manager tempManager = tempDeptH.getManagers()[j];
                    for(int k=0; k<tempManager.getEmployees().size(); k++){
                        cout << "\t\t" << tempManager.getEmployees()[k].GetName() << endl;
                    }
                }
            } 
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