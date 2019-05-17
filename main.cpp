#include "employee.h"
#include "employee.cpp"

int main(){

    vector<Employee> Lists; //the vector of class employees

    Employee Hey("shoot", 'C', "Dwayne", 23312, 3); // defining the employees here
    Employee Billy("poop", 'B', "Batson", 13345, 5);
    Employee Dude("ceo", 'F', "Jay", 44152, 8);

    Lists.push_back(Hey);   /adding the employees to the vector
    Lists.push_back(Billy);
    Lists.push_back(Dude);

    bool setting = true; //conditional statement for the while loop

    while (setting) 
    {
        string input;
        cout << "What do you want to do?" << ends;
        cin >> input;
        if (input == "list" || input == "List" || input == "l") 
        {
            for (int i = 0; i < Lists.size(); i++) 
            {
                cout << "Name: " << Lists[i].GetName() << ", ID: " << Lists[i].GetEmployeeID() 
                   << ", Contact Information: " << Lists[i].GetContactInfo() << endl;
            }
            cout << "What would you like to do?" << ends;
            cin >> input;
        }

        if (input == "help" || input == "Help" || input == "h")
        {
            cout << "The commands are [help], [list], [edit], [quit]" << endl;
            cout << "what would you like to do?" << ends;
            cin >> input;
        }

        if (input == "edit" || input == "Edit" || input == "e")
        {   
            string edits;
            cout << "what data would you like to edit? " << ends;
            cin >> edits;
            // i stopped here.
        }

        if (input == "quit" || input == "Quit" || input == "q")
        {
        setting = false;
        }
    }

    //Billy.~Employee();

    return 0;
}