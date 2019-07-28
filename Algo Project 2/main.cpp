#include<iostream>
#include<vector>
#include <set>
using namespace std;

int numS; 
int maxS;

void Answers(int steps, int sum, vector<int> &stamps, vector<int> &answer)
{

    answer.push_back(sum);
    if(steps > maxS)
    {
        return;
    }

    for (int s :stamps) 
    { 
        // to find denominations through brute force
            Answers(steps + 1, sum + s, stamps, answer); 
    }

}

int main(){
    cout << "Please enter the number of stamps you plan to use and max amount of stamps allowed." << endl;
    cin >> numS >> maxS;

    vector<int> stamps(numS);

    vector<int> answer;

    for(int i = 0; i < numS; i++)
    {
            cout << "Enter number " << i+1 << " stamp value:";
            cin >> stamps[i];
    }

    Answers(1, 0, stamps, answer);

    //converting vector to set
    set<int> s;
    unsigned size = answer.size();
    for( unsigned i = 0; i < size; ++i ) 
    {
        s.insert( answer[i] );
    }
    
    //assigning set values back to vector
    answer.assign( s.begin(), s.end() );

    //Printing out the vector values
    int* PrintAns = answer.data();
    for(int i=0; (unsigned)i < answer.size(); ++i)
    {
        cout << *PrintAns++ <<" ";
    }

    cout << endl;
    
    return 0;
}