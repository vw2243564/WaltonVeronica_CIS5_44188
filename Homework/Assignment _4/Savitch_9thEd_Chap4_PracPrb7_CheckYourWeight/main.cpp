 /* 
 * File:   main.cpp
 * Author: Veronica Walton
 * Created on March 30th, 2017, 12:22 AM
 * Purpose:  Calculate your weight
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Format
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const float MSSERTH=5.972e27f;  //Mass of Earth in grams
const float GCONST=6.673E-8f;   //Gravitational constant cm^3/gm sec^2
const float CNVFTCM=1.0f/30.48f;//Conversion from feet to centimeters
const float CNVMFT=5280.0f;     //Conversion from miles to feet
const float RADERTH=3959;       //Radius of Earth in miles

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float myWeight;//pounds
    float myMass=6;//Units of slugs(English unit)
    
    
    //Map inputs to outputs or process the data
    myWeight=GCONST*CNVFTCM*CNVFTCM*CNVFTCM*MSSERTH*myMass
            /(RADERTH*RADERTH*CNVMFT*CNVMFT);
    
    //Output the transformed data
    cout<<fixed<<setprecision(1)<<showpoint;
    cout<<"You weigh "<<myWeight<<" lbs on Earth."<<endl;
    
    //Exit stage right!
    return 0;
}

