/* 
 * File:   main.cpp
 * Author: Veronica Walton
 * Created on May 5, 2017, 6:45 PM
 * Purpose:  Menu to be utilized on Homework 6
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Format Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
void menu(void);
void prob1(void);
void prob2(void);
void prob3(void);
void prob4(void);
void prob5(void);
void prob6(void);
void prob7(void);
void prob8(void);
void prob9(void);
float calculateRetail(float,float);
int getLength();
int getWidth();
int getArea(int,int);
void displayData(int,int,int);
float getSales();
void findHighest(float,float,float,float);
int getNumAccidents();
void findLowest(int,int,int,int,int);
float fallingDistance(float);
float kineticEnergy(float,float);
float celsius(int);
bool coinToss();
void getScore(int &);
void calcAverage(int,int,int,int,int);
int findLowest1(int,int,int,int,int);

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    char choice;
    
    //Show menu and loop
    do{
        //Display Menu
        menu();
       
        //Input the choice
        cout<<"Problem ";
        cin>>choice;
        
        //Place solutions to problems in switch statement
        switch(choice){
            case '1': prob1();break;
            case '2': prob2();break;
            case '3': prob3();break;
            case '4': prob4();break;
            case '5': prob5();break;
            case '6': prob6();break;
            case '7': prob7();break;
            case '8': prob8();break;
            case '9': prob9();break;
            default:{
                cout<<"Exit the program"<<endl;
            }
        }
    }while(choice>='1'&&choice<='9');
    
    //Exit stage right!
    return 0;
}

void prob9(void){
    //Declare Variables
    int score1,score2,score3,score4,score5;
    int test1,test2,test3,test4,test5;
    
    //Test 1
    cout<<"For Test 1 \n";
    getScore(test1);
    //Test 2
    cout<<"For Test 2 \n";
    getScore(test2);
    //Test 3
    cout<<"For Test 3 \n";
    getScore(test3);
    //Test 4
    cout<<"For Test 4 \n";
    getScore(test4);
    //Test 5
    cout<<"For Test 5 \n";
    getScore(test5);
    
    //Call lowest function
    findLowest1(test1,test2,test3,test4,test5);
}

void prob8(void){
    //Declare Variables
    int num;//How many times the users wants to roll
    bool coin;
    
    //Input values
    cout<<"How many times do you want to flip a coin? ";
    cin>>num;
    
    //Process by mapping inputs to outputs
    for(int i=1;i<=num;i++){
        coin=coinToss();
        if (coin)cout<<"Heads!"<<endl;
        else cout<<"Tails!"<<endl;
    }
}

void prob7(void){
    //Declare Variables
    float deg;//Degrees Celsius
    
    //Header
    cout<<"Fahrenheit    Celsius"<<endl;
    
    //Input values
    for(int fa=0;fa<=20;fa++){
        deg=celsius(fa);
        cout<<setprecision(4)<<showpoint<<setw(3)<<fa<<setw(18)<<deg<<endl;
    }
}

void prob6(void){
    //Declare Variables
    float ke, mass, vel;//Kinetic Energy, Mass in kilograms and Velocity in meters per second
    
    //Input values
    cout<<"Input the mass of an object in kilograms: ";
    cin>>mass;
    cout<<"Input the velocity of an object un meters per second: ";
    cin>>vel;
    cout<<endl;
    
    //Call calculation function
    ke=kineticEnergy(mass,vel);
    
    //Output values
    cout<<"The kinetic energy of the object is "<<ke<<endl;
}

void prob5(void){
    //Declare Variables
    float sec;//seconds
    
    //Input values
    cout<<"Input the number of seconds an item fell: ";
    cin>>sec;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    for(int i=0;i<10;i++){
        fallingDistance(sec);
    }
}

void prob4(void){
    //Declare Variables
    int north,south,east,west,central;//regions
    
    //North
    cout<<"How many accidents were in the north region? ";
    north=getNumAccidents();
    //South
    cout<<"How many accidents were in the south region? ";
    south=getNumAccidents();
    //East
    cout<<"How many accidents were in the east region? ";
    east=getNumAccidents();
    //West
    cout<<"How many accidents were in west region? ";
    west=getNumAccidents();
    //Central
    cout<<"How many accidents were in the central region? ";
    central=getNumAccidents();
    
    //Call lowest function
    findLowest(north,south,east,west,central);
}

void prob3(void){
    //Declare Variables
    float divNE, divNW, divSE, divSW;//Divisions Northeast, Northwest, Southeast and Southwest
    
    //Prompt for sales
    cout<<"How much did the Northeast division make quarterly? $";
    divNE=getSales();
    cout<<"How much did the Northwest division make quarterly? $";
    divNW=getSales();
    cout<<"How much did the Southeast division make quarterly? $";
    divSE=getSales();
    cout<<"How much did the Southwest division make quarterly? $";
    divSW=getSales();
    
    findHighest(divNE,divNW,divSE,divSW);
}

void prob2(void){
    //Declare variables
    int length,width,area;
    
    //Call prompt functions
    length=getLength();
    width=getWidth();

    //Call calculation function
    area=getArea(length,width);
    
    //Output values
    displayData(length,width,area);
}

void prob1(void){ 
    //Declare Variables
    float cost, total=0.0f, percent;
    
    //Input values
    cout<<"This program will calculate an item's retail cost."<<endl;
    cout<<"Input the wholesale cost: ";
    cin>>cost;
    cout<<"Input the markup percentage: ";
    cin>>percent;
    
    //Call function
    total=calculateRetail(cost,percent);
    
    //Output values
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"The retail cost is $"<<total<<endl;
}

void menu(void){
    cout<<endl<<endl<<"Type 0 to exit"<<endl;
    cout<<"Type 1 for Markup Problem"<<endl;
    cout<<"Type 2 for Rectangle Area Problem"<<endl;
    cout<<"Type 3 for Calculate Sales Problem"<<endl;
    cout<<"Type 4 for Safe Driving Problem"<<endl;
    cout<<"Type 5 for Falling Problem"<<endl;
    cout<<"Type 6 for Kinetic Energy Problem"<<endl;
    cout<<"Type 7 for Celsius from Fahrenheit Problem"<<endl;
    cout<<"Type 8 for Coin Toss Problem"<<endl;
    cout<<"Type 9 for Drop Lowest Score Problem"<<endl<<endl;
}
float calculateRetail(float cost, float percent){
    return (percent/100)*cost+cost;
}
int getLength(){
    int length;
    
    cout<<"Enter the length of the rectangle: ";
    cin>>length;
    return length;
}
int getWidth(){
    int width;
    
    cout<<"Enter the width of the rectangle: ";
    cin>>width;
    return width;
}
int getArea(int length,int width){
    int area;
    return length*width;
}
void displayData(int length, int width, int area){
    cout<<"The area of the rectangle with "<<length<<" length and "<<width<<" width is "<<area<<".";
}
float getSales (){
    //Input values for Northeast
    float sales;
    
    cin>>sales;
    
    if (sales<0){
        cout<<"Error, enter more than 0."<<endl;
        return 0;
    }
    else return sales;

}
void findHighest(float divNE, float divNW, float divSE, float divSW){
    float high;
    
    //Northeast highest
    if(divNE>divNW&&divNE>divSW&&divNE>divSE){
        high=divNE;
        cout<<"Northeast is the highest grossing division with $"<<divNE<<endl;
    }
    
    //Northwest highest
    if (divNW>divSW&&divNW>divSE&&divNW>divNE){
        high=divNW;
        cout<<"Northwest is the highest grossing division with $"<<divNW<<endl;
    }
    
    //Southwest highest
    if (divSW>divNW&&divSW>divSE&&divSW>divNE){
        high=divSW;
        cout<<"Southwest is the highest grossing division with $"<<divSW<<endl;
    }
    
    //Southeast highest
    if (divSE>divNW&&divSE>divSW&&divSE>divNE){
        high=divSE;
        cout<<"Southeast is the highest grossing division with $"<<divSE<<endl;
    }
    
}
int getNumAccidents(){
    int num;
    cin>>num;
    if (num<0){
        cout<<"In valid number of accidents."<<endl;
        return 0;
    }
    else return num;
}
void findLowest(int north,int south,int east,int west,int central){
    
    //North is lowest
    if(north<south&&north<east&&north<west&&north<central){
        cout<<"North has the fewest car accidents with "<<north<<endl;
    }
    
    //South is lowest
    if(south<north&&south<east&&south<west&&south<central){
        cout<<"South has the fewest car accidents with "<<south<<endl;
    }
    
    //East is lowest
    if(east<south&&east<north&&east<west&&east<central){
        cout<<"East has the fewest car accidents with "<<east<<endl;
    }
    
    //West is lowest
    if(west<south&&west<east&&west<north&&west<central){
        cout<<"West has the fewest car accidents with "<<west<<endl;
    }
    
    //Central is lowest
    if(central<south&&central<east&&central<west&&central<north){
        cout<<"Central has the fewest car accidents with "<<central<<endl;
    }
}
float fallingDistance(float sec){
    float meter;
    meter=(9.8*sec*sec)/2;
    cout<<"The distance the item fell is "<<meter<<" meters."<<endl;
}
float kineticEnergy(float mass, float vel){
    return (mass*vel*vel)/2;
}
float celsius(int fa){
    float deg;
    deg=5*(fa-32)/9.0f;
    return deg;
}
bool coinToss(){
    bool toss;
    char coin=rand()%2+1;//[1,2]
    if (coin==1)toss=true;//heads
    else toss=false;//tails
    return toss;
}
void getScore(int &score){
    cout<<"Enter test score: ";
    cin>>score;
    cout<<endl;
}
int findLowest1(int score1, int score2, int score3, int score4, int score5){
   //Test 1 is lowest
    if(score1<score2&&score1<score3&&score1<score4&&score1<score5){
        score1=0;
    } 
    
    //Test 2 is lowest
    if(score1>score2&&score2<score3&&score2<score4&&score2<score5){
        score2=0;
    } 
    
    //Test 3 is lowest
    if(score3<score2&&score1>score3&&score3<score4&&score3<score5){
        score3=0;
    } 
    
    //Test 4 is lowest
    if(score4<score2&&score4<score3&&score1>score4&&score4<score5){
        score4=0;
    } 
    
    //Test 5 is lowest
    if(score5<score2&&score5<score3&&score5<score4&&score1>score5){
        score5=0;
    } 
    calcAverage(score1,score2,score3,score4,score5);
}
void calcAverage(int score1,int score2, int score3, int score4, int score5){
    int total;
    total=(score1+score2+score3+score4+score5)/4;
    cout<<"The average is "<<total<<endl;
}