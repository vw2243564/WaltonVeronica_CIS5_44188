/* 
  File:   main.cpp
  Author: Veronica Walton
  Created on March 20, 2017, 10:11 PM
  Purpose: Calculating Body Mass Index
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
    int wt;//Weight measured in pounds
    int ht;//Height measured in inches
    
    //Input values
    cout<<"This program will calculate your BMI."<<endl;
    cout<<"Input your weight : ";
    cin>>wt;
    cout<<"Input your height : ";
    cin>>ht;
    
    //Process by mapping inputs to outputs
    float BMI=(wt*703)/(ht*ht);
    if(BMI>=25)
        cout<<"Your BMI is "<<BMI<<", you are overweight."<<endl;
    else if (BMI<25&&BMI>=18.5)
        cout<<"Your BMI is "<<BMI<<", you are at a healthy weight."<<endl;
    else
        cout<<"Your BMI is "<<BMI<<", you are underweight."<<endl;
    
   
    //Output values
    
    //Exit stage right!
    return 0;
}