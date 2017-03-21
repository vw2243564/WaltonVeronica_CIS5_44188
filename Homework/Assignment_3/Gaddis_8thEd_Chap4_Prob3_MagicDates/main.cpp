/* 
  File:   main.cpp
  Author: Veronica Walton
  Created on March 20, 2017, 6:45 PM
  Purpose:  Calculate if a date is magic or not
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
    int day, mnth, year;//User numerical inputs of a date with day, month and year
    
    //Input values
    cout<<"This program will calculate if a date is magical or not."<<endl;
    cout<<"Input month numerically  : ";
    cin>>mnth;
    cout<<"Input day of month : ";
    cin>>day;
    cout<<"Input last 2 digits of year : ";
    cin>>year;
    
    //Process by mapping inputs to outputs
    if(day*mnth==year)
        cout<<"The inputed date of "<<mnth<<"/"<<day<<"/"<<year<<" is magical!"<<endl;
    else
        cout<<"The inputed date of "<<mnth<<"/"<<day<<"/"<<year<<" is not magic."<<endl;
    
   
    //Output values
    
    //Exit stage right!
    return 0;
}