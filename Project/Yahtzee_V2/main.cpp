/* 
 * File:   main.cpp
 * Author: Veronica Walton
 * Created on April 11, 2017 11:39AM
 * Purpose: Yahtzee Version 1
 */

//System Libraries
#include <iostream> //Input - Output Library
#include <cstdlib>  //Srand to set the seed
#include <ctime>    //Time for rand
#include <iomanip>  //Format library
#include <fstream>  //File IO
#include <cmath>    /////////////////////////////////////////See what I can do with this
#include <string>   //String Library //Use String to ask if user wants to play again or not
using namespace std; //Name-space under which system libraries exist
//Use switch to ask if user wants to see high score

//User Libraries

//Global Constants

//Function Prototypes
void inst(void);//Instructions Function

//Execution begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    ifstream in;
    ofstream out;
    char choice;//User inputs of Y/N
    bool One=true;
    char reroll;// Y/N inputs
    int score=0;
    int ones=0;//Score holder for Ones
    int twos=0;//Score holder for Twos
    int threes=0;//Score holder for Threes
    int fours=0;//Score holder for Fours
    int fives=0;//Score holder for Fives
    int sixes=0;//Score holder for Sixes
    int roll=0;
    int temp1=0, temp2=0, temp3=0, temp4=0, temp5=0, temp6=0;
    
    //Output beginning of game
    cout<<"Welcome to Yahtzee 8000!"<<endl;
    cout<<"Do you require rules to a standard yahtzee game?"<<endl;
    cout<<"Input Y/N: ";
    
    //Prompt user for instructions
    cin>>choice;
    
    //Input validation
    int i=1;
    int k=0;
    while(i>0){
        //If yes display instructions
        if(choice=='Y'||choice=='y'){
            inst();
            i--;
        }
        //If no start game
        else if(choice=='n'||choice=='N'){
            i--;
            while (roll<=13){
            
                //Roll Dice, 1-6
                int die1=rand()%6+1;
                int die2=rand()%6+1;
                int die3=rand()%6+1;
                int die4=rand()%6+1;
                int die5=rand()%6+1;

                //Table for dice
                cout<<"Dice Number: 1 | 2 | 3 | 4 | 5"<<endl;
                //Show user dice
                cout<<"Your Dice:"<<setw(4)<<die1<<setw(4)<<die2<<setw(4)<<die3
                        <<setw(4)<<die4<<setw(4)<<die5<<endl;
                cout<<endl;
                //Options
                cout<<"Your options are Ones (1), Twos (2), Threes (3), Fours (4), Fives (5), Sixes(6)\n"
                        "Three of a Kind (A), Four of a Kind (B), Full house (C)\n"
                        "Small Straight (D), Large Straight (E), Chance (F), YAHTZEE (G)"<<endl;
                cout<<endl;
                cout<<"What would you like to do next? Type in the character enclosed in parentheses to make your decision."<<endl;
                //Prompt user for option
                char pick;
                cin>>pick;
                
                do{
                    switch(pick){
                        case '1':{
                            if(temp1==1){
                                cout<<"You have already selected this category, pick another"<<endl;
                                cin>>pick;
                                break;
                            }
                            else{
                                //If Ones is chosen, add the dice that are 1
                                if(die1==1) ones++;
                                if(die2==1) ones++;
                                if(die3==1) ones++;
                                if(die4==1) ones++;
                                if(die5==1) ones++;
                                cout<<"You received "<<ones<<" points."<<endl;
                                cout<<endl;
                                temp1=1;
                                roll++;
                                k++;
                                break;
                            }
                        }
                        case '2':{
                            if(temp2==2){
                                cout<<"You have already selected this category, pick another"<<endl;
                                cin>>pick;
                                break;
                            }
                            else{
                                //If Twos is chosen, add the dice that are 2
                                if(die1==2) twos+=2;
                                if(die2==2) twos+=2;
                                if(die3==2) twos+=2;
                                if(die4==2) twos+=2;
                                if(die5==2) twos+=2;
                                cout<<"You received "<<twos<<" points."<<endl;
                                cout<<endl;
                                temp2=2;
                                roll++;
                                k++;
                                break;
                            }
                        }
                        case '3':{
                            if(temp3==3){
                                cout<<"You have already selected this category, pick another"<<endl;
                                cin>>pick;
                                break;
                            }
                            else{
                                //If Threes is chosen, add the dice that are 3
                                if(die1==3) threes+=3;
                                if(die2==3) threes+=3;
                                if(die3==3) threes+=3;
                                if(die4==3) threes+=3;
                                if(die5==3) threes+=3;
                                cout<<"You received "<<threes<<" points."<<endl;
                                cout<<endl;
                                temp3=3;
                                roll++;
                                k++;
                                break;
                            }
                        }
                        case '4':{
                            if(temp4==4){
                                cout<<"You have already selected this category, pick another"<<endl;
                                cin>>pick;
                                break;
                            }
                            else{
                                //If Fours is chosen, add the dice that are 4
                                if(die1==4) fours+=4;
                                if(die2==4) fours+=4;
                                if(die3==4) fours+=4;
                                if(die4==4) fours+=4;
                                if(die5==4) fours+=4;
                                cout<<"You received "<<fours<<" points."<<endl;
                                cout<<endl;
                                temp4=4;
                                roll++;
                                k++;
                                break;
                            }
                        }
                        case '5':{
                            if(temp5==5){
                                cout<<"You have already selected this category, pick another"<<endl;
                                cin>>pick;
                                break;
                            }
                            else{
                                //If Fives is chosen, add the dice that are 5
                                if(die1==5) fives+=5;
                                if(die2==5) fives+=5;
                                if(die3==5) fives+=5;
                                if(die4==5) fives+=5;
                                if(die5==5) fives+=5;
                                cout<<"You received "<<fives<<" points."<<endl;
                                cout<<endl;
                                temp5=5;
                                roll++;
                                k++;
                                break;
                            }
                        }
                        case '6':{
                            if(temp6==6){
                                cout<<"You have already selected this category, pick another"<<endl;
                                cin>>pick;
                                break;
                            }
                            else{
                                //If Sixes is chosen, add the dice that are 6
                                if(die1==6) sixes+=6;
                                if(die2==6) sixes+=6;
                                if(die3==6) sixes+=6;
                                if(die4==6) sixes+=6;
                                if(die5==6) sixes+=6;
                                cout<<"You received "<<sixes<<" points."<<endl;
                                cout<<endl;
                                temp6=6;
                                roll++;
                                k++;
                                break;
                            }
                        }
                        default :{
                            cout<<"Error, you choose an incorrect value, try again."<<endl;
                            cin>>pick;
                            //break;
                            //return 0;
                        }
                    }
                    /*score=ones+twos+threes+fours+fives+sixes;
                    cout<<"Your current score is: "<<score<<" points!"<<endl;
                    cout<<"You are on roll "<<roll<<" out of 13."<<endl;
                    cout<<endl;*/
                }while(k<1);
                /*else if (pick=='a'||pick=='A'){
                    cout<<"3kind"<<endl;
                }//Put inner if to check if the roll matches the conditions for 3 of a kind
                else if (pick=='b'||pick=='B'){
                    cout<<"4Kind"<<endl;
                }
                else if (pick=='c'||pick=='C'){
                    cout<<"Full"<<endl;
                }
                else if (pick=='d'||pick=='D'){
                    cout<<"Small"<<endl;
                }
                else if (pick=='e'||pick=='E'){
                    cout<<"4Kind"<<endl;
                }
                else if (pick=='f'||pick=='F'){
                    cout<<"Chance"<<endl;
                }
                else if (pick=='g'||pick=='G'){
                    cout<<"YAHTZEE"<<endl;
                }
                else{
                    cout<<"Error, you choose an incorrect value, try again."<<endl;
                      cin>>pick;
                      //break;
                      //return 0;
                }*/
                score=ones+twos+threes+fours+fives+sixes;
                cout<<"Your current score is: "<<score<<" points!"<<endl;
                cout<<"You are on roll "<<roll<<" out of 13."<<endl;
                cout<<endl;
        }
        }
        //If anything else re-prompt user
        else{
        cout<<"Invalid input, please try again."<<endl;
        cout<<"Input Y/N: ";
        cin>>choice;
        }
    }
    score=ones+twos+threes+fours+fives+sixes;
    //put if statement so this doesnt out put when asking for instructions
    cout<<"Testing"<<endl;
    cout<<"Your score is: "<<score<<endl;
    
    //Exit stage right!
    return 0;
}
void inst(void){
    cout<<"Instructions"<<endl;
}

