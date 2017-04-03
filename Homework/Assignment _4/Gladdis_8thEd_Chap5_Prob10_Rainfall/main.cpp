/* 
  File:   main.cpp
  Author: Veronica Walton
  Created on April 2, 2017, 3:24 PM
  Purpose:  Average rainfall over a period of years
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
    int year, //User input of number of years
        inch, //User input of rainfall in inches
        total=0,//Total amount of inches
        avg,  //Average in inches
        month;
    
    //User input of years
    cout<<"This program calculates the average rainfall over a period of time."<<endl;
    cout<<"Enter the number of years: ";
    cin>>year;
    
    //Input validation
    if(year<=0){
        cout<<"Must input at least 1 year."<<endl;
        return 0;
    }
    
    //Year loop
    for(int n=0;n<year;n++)
    {
        //Month loop
        for(month=1;month<=12;month++)
        {
            cout<<"Enter the amount of rainfall in inches for month "<<month<<": ";
            cin>>inch;
                //Input validation
                if(inch<0)
                {
                   cout<<"Invalid input: No negative values."<<endl;
                   return 0;
                }
            total+=inch;//Accumulate total
        }

    }
   avg=total/(year*12);
   cout<<"The average rainfall for "<<year<<" years is "<<avg<<" inches."<<endl;
   
    //Exit stage right!
    return 0;
}