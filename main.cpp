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
        DepartmentH tempDepartmentH((char)(rand()%26+65), names[rand()%61], tempID+i, 150000);
        boss.addDepartmentH(tempDepartmentH);
        for(int j=1; j<=3; j++){
            tempID = boss.getDepartmentH()[i-1].GetEmployeeID()*10;
            Manager tempManager((char)(rand()%26+65), names[rand()%61], tempID+j, 100000);
            boss.getDepartmentH()[i-1].addManager(tempManager);
            for(int k=1; k<=5; k++){
                tempID*=10;
                Employee tempEmployee((char)(rand()%26+65), names[rand()%61], tempID+k, 75000);
                tempDepartmentH = boss.getDepartmentH()[i-1];
                tempDepartmentH.getManagers()[j-1].addEmployee(tempEmployee);
                //DepartmentH testing = boss.getDepartmentH()[0];
                //Manager test = testing.getManagers()[0];
                //test.addEmployee(tempEmployee); 
            }
            boss.getDepartmentH()[i-1] = tempDepartmentH;
        }
    }
    
    //populateTree(boss);

    DepartmentH bro = boss.getDepartmentH()[0];
    DepartmentH boi = boss.getDepartmentH()[1];
    //Manager hi = boss.getDepartmentH()[0].getManagers()[0];

    cout << bro.GetName() << endl;
    //cout << bro.GetEmployeeID() << endl;
    cout << bro.GetContactInfo() << endl;
    cout << bro.GetGrossPay() << endl;

    cout << boi.GetName() << endl;
    //cout << boi.GetEmployeeID() << endl;
    cout << boi.GetContactInfo() << endl;
    cout << boi.GetGrossPay() << endl;


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