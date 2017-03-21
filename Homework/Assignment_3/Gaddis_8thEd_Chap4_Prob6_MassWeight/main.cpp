/* 
  File:   main.cpp
  Author: Veronica Walton
  Created on March 20, 2017, 10:11 PM
  Purpose: Calculate weight
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
    int mass;//Mass of an object in kilograms
    
    //Input values
    cout<<"This program will calculate the weight of an object."<<endl;
    cout<<"Input the mass of the object : ";
    cin>>mass;
    
    //Process by mapping inputs to outputs
    int wt=mass*9.8;//Weight in Newtons
    if(1000<wt)
        cout<<mass<<" kilograms is too heavy!"<<endl;
    else if (wt<10)
        cout<<mass<<" kilograms is too light!"<<endl;
    else
        cout<<"The weight of the object is "<<wt<<" newtons."<<endl;
    
   
    //Output values
    
    //Exit stage right!
    return 0;
}