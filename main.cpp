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

    for(int i=0; i<allManagers.size(); i++){
        for(int j=0; j<numEmployees; j++){
            employeeHolder.push_back(allEmployees[0]);
            allEmployees.erase(allEmployees.begin());
        }
        allManagers[i].setManagerSubs(employeeHolder);
        employeeHolder.clear();
    }

    vector<Manager> managerHolder;

    
    for(int i=0; i<allDeptH.size(); i++){
        for(int j=0; j<numManagers; j++){
            managerHolder.push_back(allManagers[0]);
            allManagers.erase(allManagers.begin());
        }
        allDeptH[i].setDeptHSubs(managerHolder);
        managerHolder.clear();
    }

    boss.setCEOSubs(allDeptH);
    
    cout<<boss.GetName()<<endl;
    for(int i=0; i<boss.getDepartmentH().size(); i++){
        cout << "\t"<< boss.getDepartmentH()[i].GetName() << endl;
        DepartmentH tempDeptH = boss.getDepartmentH()[i];
        for(int j=0; j<tempDeptH.getManagers().size(); j++){
            cout << "\t\t" << tempDeptH.getManagers()[j].GetName() << endl;
            Manager tempManager = tempDeptH.getManagers()[j];
            for(int k=0; k<tempManager.getEmployees().size(); k++){
                cout << "\t\t\t" << tempManager.getEmployees()[k].GetName() << endl;
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
            cout << "The possible commands are: 'help', 'quit', show, Lastname, EmployeeID, CEO, DeptH, Managers, Employees " << endl;
        }
        else if (userInput == "show") {
            cout<<boss.GetName()<<endl;
            for(int i=0; i<boss.getDepartmentH().size(); i++){
                cout << "\t"<< boss.getDepartmentH()[i].GetName() << endl;
                DepartmentH tempDeptH = boss.getDepartmentH()[i];
            for(int j=0; j<tempDeptH.getManagers().size(); j++){
                cout << "\t\t" << tempDeptH.getManagers()[j].GetName() << endl;
                Manager tempManager = tempDeptH.getManagers()[j];
            for(int k=0; k<tempManager.getEmployees().size(); k++){
                cout << "\t\t\t" << tempManager.getEmployees()[k].GetName() << endl;
            }
            }
            }        
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
                for(int i=0; i<boss.getDepartmentH().size(); i++){
                    boss.getDepartmentH()[i].GetEmployeeID();
                    DepartmentH tempDeptH = boss.getDepartmentH()[i];
                    if(tempDeptH.GetEmployeeID() == emplid){
                        cout<<"Position: Department Head"<<endl;
                        cout<<"Contact Info: "<<tempDeptH.GetContactInfo()<<endl;
                        cout<<"Employee ID: "<<tempDeptH.GetEmployeeID()<<endl;
                        cout<<"Gross Pay: "<<tempDeptH.GetGrossPay()<<endl;
                    }
                for(int j=0; j<tempDeptH.getManagers().size(); j++){
                    tempDeptH.getManagers()[j].GetEmployeeID();
                    Manager tempManager = tempDeptH.getManagers()[j];
                    if(tempManager.GetEmployeeID() == emplid){
                        cout<<"Position: Manager"<<endl;
                        cout<<"Contact Info: "<<tempManager.GetContactInfo()<<endl;
                        cout<<"Employee ID: "<<tempManager.GetEmployeeID()<<endl;
                        cout<<"Gross Pay: "<<tempManager.GetGrossPay()<<endl;
                    }
                for(int k=0; k<tempManager.getEmployees().size(); k++){
                    tempManager.getEmployees()[k].GetEmployeeID();
                    Employee tempEmployee = tempManager.getEmployees()[k];
                    if(tempEmployee.GetEmployeeID() == emplid){
                        cout<<"Position: Manager"<<endl;
                        cout<<"Contact Info: "<<tempEmployee.GetContactInfo()<<endl;
                        cout<<"Employee ID: "<<tempEmployee.GetEmployeeID()<<endl;
                        cout<<"Gross Pay: "<<tempEmployee.GetGrossPay()<<endl;
                    }
                }}}

            }
               
                
        }
            
        else if (userInput == "Lastname") {
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
                for(int i=0; i<boss.getDepartmentH().size(); i++){
                    boss.getDepartmentH()[i].getLastName();
                    DepartmentH tempDeptH = boss.getDepartmentH()[i];
                    if(tempDeptH.getLastName() == lname){
                        cout<<"Position: Department Head"<<endl;
                        cout<<"Contact Info: "<<tempDeptH.GetContactInfo()<<endl;
                        cout<<"Employee ID: "<<tempDeptH.GetEmployeeID()<<endl;
                        cout<<"Gross Pay: "<<tempDeptH.GetGrossPay()<<endl;
                    }
                for(int j=0; j<tempDeptH.getManagers().size(); j++){
                    tempDeptH.getManagers()[j].getLastName();
                    Manager tempManager = tempDeptH.getManagers()[j];
                    if(tempManager.getLastName() == lname){
                        cout<<"Position: Manager"<<endl;
                        cout<<"Contact Info: "<<tempManager.GetContactInfo()<<endl;
                        cout<<"Employee ID: "<<tempManager.GetEmployeeID()<<endl;
                        cout<<"Gross Pay: "<<tempManager.GetGrossPay()<<endl;
                    }
                for(int k=0; k<tempManager.getEmployees().size(); k++){
                    tempManager.getEmployees()[k].getLastName();
                    Employee tempEmployee = tempManager.getEmployees()[k];
                    if(tempEmployee.getLastName() == lname){
                        cout<<"Position: Manager"<<endl;
                        cout<<"Contact Info: "<<tempEmployee.GetContactInfo()<<endl;
                        cout<<"Employee ID: "<<tempEmployee.GetEmployeeID()<<endl;
                        cout<<"Gross Pay: "<<tempEmployee.GetGrossPay()<<endl;
                    }
                }}}

            }
        }
        else if(userInput == "CEO"){
            cout<<boss.GetName()<<endl;
        }
        else if(userInput == "DeptH"){
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