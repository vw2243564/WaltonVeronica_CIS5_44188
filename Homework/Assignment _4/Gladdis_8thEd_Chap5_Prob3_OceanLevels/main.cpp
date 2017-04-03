/* 
  File:   main.cpp
  Author: Veronica Walton
  Created on April 2, 2017, 2:15 PM
  Purpose:  Display a table of rising ocean levels
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
    int level;//1.5 millimeters
    int year=1;
    
    //Output header
    cout<<"Ocean levels over the next 25 years\n";
    cout<<"Year                    Level in mm\n";
    cout<<"____________________________________\n";
    
    //Table
    while(year<=25)
    {
        cout<<year<<"\t\t\t"<<(year*1.50f)<<endl;
        year++;
    }

    //Exit stage right!
    return 0;
}