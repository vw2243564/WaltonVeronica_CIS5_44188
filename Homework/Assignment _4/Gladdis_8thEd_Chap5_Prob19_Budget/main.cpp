/* 
  File:   main.cpp
  Author: Veronica Walton
  Created on April 2, 2017, 8:00 PM
  Purpose:  Calculating monthly budget
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    int bud,//User monthly budget
        dol,//User input of expenses
        total=0,//Total user expenses
        bal;
    char choice;//Y/N
    
    //Input values
    cout<<"This program will calculate how close you are to your budget."<<endl;
    cout<<"Input your monthly budgets in dollars: $";
    cin>>bud;
    
    //Process by mapping inputs to outputs  
    do{
        cout<<"Input an expense for the month: $";
        cin>>dol;
        total+=dol;
        cout <<"Would you like to enter another expense Y/N: "; 
        cin >> choice;
    }while(choice=='y'||choice=='Y');
    
    bal=bud-total;
    
    cout<<"The total expense is "<<total<<endl;
    
    //Over budget
    if(bal<0)
    {
        cout<<"Careful, you are over your budget by $"<<bal<<endl;
    //Under budget
    }else if (bal>0)
    {
        cout<<"Good job, you are under your budget by $"<<bal<<endl;
    }else{
        cout<<"You spent all you budget."<<endl;
    }

    //Exit stage right!
    return 0;
}