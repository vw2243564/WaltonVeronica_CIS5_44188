/* 
  File:   main.cpp
  Author: Veronica Walton
  Created on March 20, 2017, 10:11 PM
  Purpose: Calculating Days in a month
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
    int mnth;//User input between 1 and 12
    int year, day;
    
    //Input values
    cout<<"This program will calculate the number of days in a given month."<<endl;
    cout<<"Input the number of the month between 1 and 12 : ";
    cin>>mnth;
    cout<<"Input the year : ";
    cin>>year;
    
    //Process by mapping inputs to outputs
    int lp1;//leap year 1
    int nlp;//not a leap year
    year%400=0 ? lp1 : nlp;
    
    if (lp1 && mnth==2)
        day=29;
    else if (nlp && mnth==2)
        day=28;
    else if (mnth==4 ||mnth==6|| mnth==9||mnth==11)
        day=30;
    else
        day=31;
   
    //Output values
    
    //Exit stage right!
    return 0;
}