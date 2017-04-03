/* 
  File:   main.cpp
  Author: Veronica Walton
  Created on April 2, 2017, 1:27 PM
  Purpose:  Counter
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
    int input;//User input of a positive value
    int sum=0; 
   
    //Input data
    cout<<"This program will sum all integers up to your input."<<endl;
    cout<<"Input a positive integer: ";
    cin>>input;
    if(input<=0){
        cout<<"This program requires a positive value."<<endl;
        return 1;//Exit program
    }
    for(int num=0;num<=input;num++){
        sum=sum+num;
    }
    cout<<"The sum from 1 to "<<input<<" is "<<sum<<"."<<endl;
    

    //Exit stage right!
    return 0;
}