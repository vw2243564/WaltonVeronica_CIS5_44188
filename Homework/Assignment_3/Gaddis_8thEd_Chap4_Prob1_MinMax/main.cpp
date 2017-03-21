/* 
  File:   main.cpp
  Author: Veronica Walton
  Created on March 20, 2017, 6:20 PM
  Purpose:  Minimum/Maximum
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
    int num1, num2;//User inputs of numbers
    
    //Input values
    cout<<"This program will tell you which of two numbers is smaller or larger."<<endl;
    cout<<"Input number 1 :";
    cin>>num1;
    cout<<"Input number 2 :";
    cin>>num2;
    
    //Process by mapping inputs to outputs
    int min, max;
    num1<num2 ? min=num1 : max=num1;
    num1>num2 ? min=num2 : max=num2;
    
    //Output values
    cout<<min<<" is the smaller value."<<endl;
    cout<<max<<" is the larger value."<<endl;
    

    //Exit stage right!
    return 0;
}