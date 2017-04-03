/* 
  File:   main.cpp
  Author: Veronica Walton
  Created on April 2, 2017, 5:30 PM
  Purpose:  Determine the greatest and least numbers
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
    int num;//User input
    int big=-999999,small=999999;//largest and smallest numbers
    
    cout<<"This program will print the least and greatest "
            "number from numbers of your choice."<<endl;
    
    //Comparing numbers
    while(num!=-99)
    {
        cout<<"Enter your numbers, -99 to stop. ";
        cin>>num;
        if(num==-99)
            break;
        if(num>big)
        {
            big=num;
        }
        if(num<small)
        {
            small=num;
        }
    }
    
    //Output values
    cout<<"The largest number is "<<big<<endl;
    cout<<"The smallest number is "<<small<<endl;

    //Exit stage right!
    return 0;
}