/* 
 * File:   main.cpp
 * Author: Veronica Walton
 * Created on March 14, 2017, 11:32 AM
 * Purpose:  Calculate time!
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const int MINUTE=60;     //How many seconds in a minute
const int HOUR=60*MINUTE;//How many seconds in a hour
const int DAY=24*HOUR;   //How many seconds in a day
const int WEEK=7*DAY;    //How many seconds in a week
const int YEAR=52*WEEK;  //How many seconds in a year

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    int nSecs;//Number of seconds to convert
    int nYrs,nMths,nWks,nDys,nMin,nHrs;
    
    //Initialize variables
    cout<<"This program converts seconds to Years/Months/Weeks/Days/Hours"<<endl;
    cout<<"Input the number of seconds for the conversion/equivalence"<<endl;
    cin>>nSecs;
    
    //Map inputs to outputs or process the data
    nYrs=nSecs/YEAR;          //Number of Years
    cout<<nYrs<<" Years, (";
    nSecs=nSecs-nYrs*YEAR;    //Subtract the yearly seconds from remaining
    
    nWks=nSecs/WEEK;          //Number of weeks
    cout<<nWks<<" Weeks or ";
    nMths=nWks*3/13;          //Covert number of weeks to months
    cout<<nMths<<" Months), ";
    nDys=nSecs/DAY;           //Number of days
    cout<<nDys<<" Days, ";
    nSecs-=nDys*DAY;         //Subtract the daily seconds from remaining
    
    nHrs=nSecs/HOUR;         //Number of hours
    cout<<nHrs<<" Hours, ";
    nSecs-=nHrs*HOUR;        //Subtract the hourly seconds from remaining
    
    nMin=nSecs/MINUTE;       //Number of minutes
    cout<<nMin<<" Minutes and ";
    nSecs-=nMin*MINUTE;      //Remaining number of seconds
    cout<<nSecs<<" Seconds.";
    
    
    //Output the transformed data
    
    //Exit stage right!
    return 0;
}

