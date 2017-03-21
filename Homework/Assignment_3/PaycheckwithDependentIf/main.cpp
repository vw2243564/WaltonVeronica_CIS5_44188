/* 
 * File:   main.cpp
 * Author: Veronica Walton
 * Created on March 16, 2017, 12:25 PM
 * Purpose:  Paycheck with dependent if
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    signed short payR, //Pay rate
                 hrsWd,//Hours worked
                 ovrT, //Overtime
                 payC; //Paycheck
    
    
    //Input data
    cout<<"This program calculates your paycheck."<<endl;
    cout<<"The data type used is an integer."<<endl;
    cout<<"Type in your hours worked: "<<endl;
    cin>>hrsWd;
    cout<<"Type in your pay rate per hour: "<<endl;
    cin>>payR;
    
    //Map inputs to outputs or process the data
    if(hrsWd<=40) payC=payR*hrsWd;
    else payC=(payR*hrsWd)+payR*(hrsWd-40);
    
    //Output the transformed data
    cout<<"For a pay rate of $"<<payR<<" per hour and "<<hrsWd<<" hours worked, your paycheck is $"<<payC<<endl;
    
    //Exit stage right!
    return 0;
}

