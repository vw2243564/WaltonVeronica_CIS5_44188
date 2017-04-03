/* 
  File:   main.cpp
  Author: Veronica Walton
  Created on April 2, 2017, 6:40 PM
  Purpose:  Calculate occupancy rate for a hotel
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
    int floor,//Number of floors
        room, //Number of rooms on a floor
        ocp,  //Number of rooms occupied
        troom,//Total number of rooms
        tocp; //Total number of occupied rooms
    float per;//percentage
    
    //Input values
    cout<<"This program will calculate occupancy rate for your hotel."<<endl;
    cout<<"How many floors does your hotel have? ";
    cin>>floor;

    //Loop for floors 1 to 13
    if (floor<=13)
    {
        troom=0;
        tocp=0;
        for(int n=0;n<floor;n++)
        {  
            cout<<"Input number of rooms on floor: ";
            cin>>room;
            troom+=room;//Accumulator
            cout<<"Input number of occupied rooms: ";
            cin>>ocp;
            tocp+=ocp;//Accumulator
            
        }
    } 
    //Loop for floor 14 and up
    if (floor>13)//subtract 1
    {
        troom=0;
        tocp=0;
        for(int n=0;n<(floor-1);n++)
        {  
            cout<<"Input number of rooms on floor: ";
            cin>>room;
            troom+=room;//Accumulator
            cout<<"Input number of occupied rooms: ";
            cin>>ocp;
            tocp+=ocp;//Accumulator
            
        }
    } 
    
    //Output values
    cout<<"Your hotel has "<<troom<<" rooms total.\n"
            <<tocp<<" are occupied and "<<troom-tocp<<" are unoccupied."<<endl;
    per=static_cast<float>(tocp)/troom;
    cout<<"The percentage of rooms occupied is "<<per*100<<"%."<<endl;

    //Exit stage right!
    return 0;
}