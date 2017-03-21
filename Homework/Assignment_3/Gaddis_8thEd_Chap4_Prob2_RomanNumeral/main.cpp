/* 
  File:   main.cpp
  Author: Veronica Walton
  Created on March 20, 2017, 6:20 PM
  Purpose:  Roman Numeral Converter
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
    int num;//User inputs of number between 1 and 10
    
    //Input values
    cout<<"This program will convert a value between 1 and 10 to Roman numerals."<<endl;
    cout<<"Input number : ";
    cin>>num;
    
    //Process by mapping inputs to outputs
    
   
    //Output values
    switch (num)
    {
        case 1 :cout<<"Roman numeral I.\n";
        break;
        case 2 :cout<<"Roman numeral II.\n";
        break;
        case 3 :cout<<"Roman numeral III.\n";
        break;
        case 4 :cout<<"Roman numeral IV.\n";
        break;
        case 5 :cout<<"Roman numeral V.\n";
        break;
        case 6 :cout<<"Roman numeral VI.\n";
        break;
        case 7 :cout<<"Roman numeral VII.\n";
        break;
        case 8 :cout<<"Roman numeral VIII.\n";
        break;
        case 9 :cout<<"Roman numeral IX.\n";
        break;
        case 10:cout<<"Roman numeral X.\n";
        break;
        default:cout<<"You did not enter a value between 1 and 10.";
    }
    
    
    

    //Exit stage right!
    return 0;
}