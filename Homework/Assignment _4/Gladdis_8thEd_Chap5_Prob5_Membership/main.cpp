/* 
  File:   main.cpp
  Author: Veronica Walton
  Created on April 2, 2017, 2:29 PM
  Purpose:  Display projected rates
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
    int sum,year;
    float n=2500;//membership
    
    //Output purpose
    cout<<"This program will calculate the projected rates "
            "for membership over the next 6 years"<<endl;
    
    //Process by mapping inputs to outputs
    for(year=1;year<=6;++year)
    {
        n=(n*0.04)+n;//adds to current membership value
        cout<<"The projected rate for year "<<year<<" is $"<<n<<endl;
    }
    
    //Output values
    

    //Exit stage right!
    return 0;
}