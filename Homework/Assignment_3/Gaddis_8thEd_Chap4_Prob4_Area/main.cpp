/* 
  File:   main.cpp
  Author: Veronica Walton
  Created on March 20, 2017, 10:11 PM
  Purpose: Calculate Area of rectangles
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
    int lnth1, lnth2, wid1, wid2;//Length and widths of two rectangles
    
    //Input values
    cout<<"This program will compare the areas of two rectangles."<<endl;
    cout<<"Input length of first rectangle  : ";
    cin>>lnth1;
    cout<<"Input width of first rectangle : ";
    cin>>wid1;
    cout<<"Input length of second rectangle : ";
    cin>>lnth2;
    cout<<"Input width of second rectangle : ";
    cin>>wid2;
    
    //Process by mapping inputs to outputs
    int area1=lnth1*wid1;
    int area2=lnth2*wid2;
    if(area1>area2)
        cout<<"The area with "<<lnth1<<" length and "<<wid1<<" width is the largest with "<<area1<<" area."<<endl;
    else if (area1<area2)
        cout<<"The area with "<<lnth2<<" length and "<<wid2<<" width is the largest with "<<area2<<" area."<<endl;
    else
        cout<<"Both areas are the same!"<<endl;
    
   
    //Output values
    
    //Exit stage right!
    return 0;
}