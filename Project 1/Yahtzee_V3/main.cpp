/* 
 * File:   main.cpp
 * Author: Veronica Walton
 * Created on April 14, 2017 4:30AM
 * Purpose: Yahtzee Version 3
 */

//System Libraries
#include <iostream> //Input - Output Library
#include <cstdlib>  //Srand to set the seed
#include <ctime>    //Time for rand
#include <iomanip>  //Format library
#include <fstream>  //File IO
#include <string>   //String Library
using namespace std; //Name-space under which system libraries exist

//Function Prototypes
void inst(void);//Instructions Function

//Execution begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    string name;     //Name of user
    ifstream inGame; //Input File
    ofstream outGame;//Output File
    char choice;     //User inputs of Y/N
    char reroll;     //Y/N inputs
    int score=0;     //Score holder
    int ones=0;      //Score holder for Ones
    int twos=0;      //Score holder for Twos
    int threes=0;    //Score holder for Threes
    int fours=0;     //Score holder for Fours
    int fives=0;     //Score holder for Fives
    int sixes=0;     //Score holder for Sixes
    int threek=0;    //Score holder for 3 of a kind
    int fourk=0;     //Score holder for 4 of a kind
    int fullH=0;     //Score holder for Full House
    int chance=0;    //Score holder for Chance
    int small=0;     //Score holder for Small Straight
    int large=0;     //Score holder for Large Straight
    int yahtzee=0;   //Score holder for Yahtzee
    int small1=0,small2=0,small3=0,small4=0,small5=0;//Temp sums for Small Straight
    int roll=0;
    //Temp variables to make sure the user can't choose the same value more than once
    char temp1=0, temp2=0, temp3=0, temp4=0, temp5=0, temp6=0;
    char tempA=0, tempB=0, tempC=0, tempD=0, tempE=0, tempF=0, tempG=0;
    
    //Output beginning of game
    cout<<"Welcome to Yahtzee!"<<endl;
    cout<<endl;
    
    //Take user name
    cout<<"What's your name?"<<endl;
    cin>>name;
    cout<<"Welcome, "<<name<<"!"<<endl;
    cout<<"Do you require rules to a standard yahtzee game?"<<endl;
    cout<<"Input Y/N: ";
    
    //Prompt user for instructions
    cin>>choice;
    
    //Input validation
    int i=1;
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
                //Output options for the user to choose from
                cout<<"Your options are Ones (1), Twos (2), Threes (3), Fours (4), Fives (5), Sixes(6)\n"
                        "Three of a Kind (A), Four of a Kind (B), Full house (C)\n"
                        "Small Straight (D), Large Straight (E), Chance (F), YAHTZEE (G)"<<endl;
                cout<<endl;
                //Ask if the user wants to re-roll
                cout<<"Would you like to re-roll (Y/N)?"<<endl;
                cin>>reroll;
                //User gets to re-roll each die 3 times
                for(int r=1;r<=3;r++){
                    switch(reroll){
                        case 'y':
                        case 'Y':{
                        //Re-roll die 1
                        cout<<"Do you want to re-roll dice 1?";
                        char dice1;//Temp variable to see if user wants to re-roll (Y/N)
                        cin>>dice1;
                        (dice1=='y'||dice1=='Y')?(die1=rand()%6+1):(die1=die1);
                        //Re-roll die 2
                        cout<<"Do you want to re-roll dice 2?";
                        char dice2;
                        cin>>dice2;
                        (dice2=='y'||dice2=='Y')?(die2=rand()%6+1):(die2=die2);
                        //Re-roll die 3
                        cout<<"Do you want to re-roll dice 3?";
                        char dice3;
                        cin>>dice3;
                        (dice3=='y'||dice3=='Y')?(die3=rand()%6+1):(die3=die3);
                        //Re-roll die 4
                        cout<<"Do you want to re-roll dice 4?";
                        char dice4;
                        cin>>dice4;
                        (dice4=='y'||dice4=='Y')?(die4=rand()%6+1):(die4=die4);
                        //Re-roll die 5
                        cout<<"Do you want to re-roll dice 5?";
                        char dice5;
                        cin>>dice5;
                        (dice5=='y'||dice5=='Y')?(die5=rand()%6+1):(die5=die5);
                        //Table for dice
                        cout<<"Dice Number: 1 | 2 | 3 | 4 | 5"<<endl;
                        //Show user dice
                        cout<<"Your Dice:"<<setw(4)<<die1<<setw(4)<<die2<<setw(4)<<die3
                            <<setw(4)<<die4<<setw(4)<<die5<<endl;
                        cout<<endl;
                        }break;
                        default :{
                            r=3;
                        }break;
                    }
                    //Leave loop if user does not want to re-roll
                    if(r==3){
                        cout<<"You have decided not to re-roll or are out of re-rolls."<<endl;
                        cout<<endl;
                        r=3;
                        cout<<"Your options are Ones (1), Twos (2), Threes (3), Fours (4), Fives (5), Sixes(6)\n"
                        "Three of a Kind (A), Four of a Kind (B), Full house (C)\n"
                        "Small Straight (D), Large Straight (E), Chance (F), YAHTZEE (G)"<<endl;
                        cout<<endl;
                    }
                    //Ask user if they want to re-roll again
                    else{
                        cout<<"Do you want to re-roll again?"<<endl;
                        cin>>reroll;
                    }
                }
                int k=0;
                do{
                    cout<<"What would you like to do next? Type in the character enclosed in parentheses to make your decision."<<endl;
                    //Prompt user for option
                    char pick;
                    cin>>pick;
                    //Catch if the user tries to pick the same options
                    while(pick==temp1||pick==temp2||pick==temp3||pick==temp4||pick==temp5||pick==temp6||
                          pick==tempA||pick==tempB||pick==tempC||pick==tempD||pick==tempE||pick==tempF||pick==tempG){
                        cout<<"You have already selected this category, pick another"<<endl;
                        cin>>pick;
                    }
                    //Categories for the user to choose from
                    if (pick=='1'){
                        //If Ones is chosen, add the dice that are 1
                        if(die1==1) ones++;
                        if(die2==1) ones++;
                        if(die3==1) ones++;
                        if(die4==1) ones++;
                        if(die5==1) ones++;
                        cout<<"You received "<<ones<<" points."<<endl;
                        cout<<endl;
                        temp1='1';
                        roll++;
                        k=1;
                        } 
                    else if (pick=='2'){
                        //If Twos is chosen, add the dice that are 2
                        if(die1==2) twos+=2;
                        if(die2==2) twos+=2;
                        if(die3==2) twos+=2;
                        if(die4==2) twos+=2;
                        if(die5==2) twos+=2;
                        cout<<"You received "<<twos<<" points."<<endl;
                        cout<<endl;
                        temp2='2';
                        roll++;
                        k=1;
                    }
                    else if (pick=='3'){
                        //If Threes is chosen, add the dice that are 3
                        if(die1==3) threes+=3;
                        if(die2==3) threes+=3;
                        if(die3==3) threes+=3;
                        if(die4==3) threes+=3;
                        if(die5==3) threes+=3;
                        cout<<"You received "<<threes<<" points."<<endl;
                        cout<<endl;
                        temp3='3';
                        roll++;
                        k=1;
                    }
                    else if (pick=='4'){
                        //If Fours is chosen, add the dice that are 4
                        if(die1==4) fours+=4;
                        if(die2==4) fours+=4;
                        if(die3==4) fours+=4;
                        if(die4==4) fours+=4;
                        if(die5==4) fours+=4;
                        cout<<"You received "<<fours<<" points."<<endl;
                        cout<<endl;
                        temp4='4';
                        roll++;
                        k=1;
                    }
                    else if (pick=='5'){
                        //If Fives is chosen, add the dice that are 5
                        if(die1==5) fives+=5;
                        if(die2==5) fives+=5;
                        if(die3==5) fives+=5;
                        if(die4==5) fives+=5;
                        if(die5==5) fives+=5;
                        cout<<"You received "<<fives<<" points."<<endl;
                        cout<<endl;
                        temp5='5';
                        roll++;
                        k=1;
                    }
                    else if (pick=='6'){
                        //If Sixes is chosen, add the dice that are 6
                        if(die1==6) sixes+=6;
                        if(die2==6) sixes+=6;
                        if(die3==6) sixes+=6;
                        if(die4==6) sixes+=6;
                        if(die5==6) sixes+=6;
                        cout<<"You received "<<sixes<<" points."<<endl;
                        cout<<endl;
                        temp6='6';
                        roll++;
                        k=1;
                    }
                    else if (pick=='A'){
                        //If 3 of a kind is chosen, match 3 dice and add them
                        if(die1==die2&&die1==die3){//Die combination 1,2,3
                            cout<<"Three of a kind!"<<endl;
                        }
                        else if(die1==die2&&die1==die4){//Die combination 1,2,4
                            cout<<"Three of a kind!"<<endl;
                        }
                        else if(die1==die2&&die1==die5){//Die combination 1,2,5
                            cout<<"Three of a kind!"<<endl;
                        }
                        else if(die1==die3&&die1==die4){//Die combination 1,3,4
                            cout<<"Three of a kind!"<<endl;
                        }
                        else if(die1==die3&&die1==die5){//Die combination 1,3,5
                            cout<<"Three of a kind!"<<endl;
                        }
                        else if(die1==die4&&die1==die5){//Die combination 1,4,5
                            cout<<"Three of a kind!"<<endl;
                        }
                        else if(die2==die3&&die2==die4){//Die combination 2,3,4
                            cout<<"Three of a kind!"<<endl;
                        }
                        else if(die2==die3&&die2==die5){//Die combination 2,3,5
                            cout<<"Three of a kind!"<<endl;
                        }
                        else if(die2==die4&&die2==die5){//Die combination 2,4,5
                            cout<<"Three of a kind!"<<endl;
                        }
                        else if(die3==die4&&die3==die5){//Die combination 3,4,5
                            cout<<"Three of a kind!"<<endl;
                        }
                        else{
                            cout<<"You do not have three of a kind!"<<endl;
                        }
                        threek=die1+die2+die3+die4+die5;
                        cout<<"You have received "<<threek<<" points."<<endl;
                        cout<<endl;
                        tempA='A';
                        roll++;
                        k=1;
                    }
                    else if (pick=='B'){
                        //If 4 of a kind is chosen, match 4 dice and add them
                        if(die1==die2&&die1==die3&&die1==die4){//Die combination 1,2,3,4
                        cout<<"Four of a kind!"<<endl;
                        }
                        else if(die1==die2&&die1==die3&&die1==die5){//Die combination 1,2,3,5
                        cout<<"Four of a kind!"<<endl;
                        }
                        else if(die1==die2&&die1==die4&&die1==die5){//Die combination 1,2,4,5
                        cout<<"Four of a kind!"<<endl;
                        }
                        else if(die1==die3&&die1==die4&&die1==die5){//Die combination 1,3,4,5
                        cout<<"Four of a kind!"<<endl;
                        }
                        else if(die2==die3&&die2==die4&&die2==die5){//Die combination 2,3,4,5
                        cout<<"Four of a kind!"<<endl;
                        }
                        else{
                            cout<<"You do not have four of a kind!"<<endl;
                        }
                        fourk=die1+die2+die3+die4+die5;
                        cout<<"You have received "<<fourk<<" points."<<endl;
                        cout<<endl;
                        tempB='B';
                        roll++;
                        k=1;
                    }
                    else if (pick=='C'){
                        //If Full House is chosen, match 3 dice and 2 dice
                        if(die1==die2&&die1==die3&&die4==die5){//Die 1,2,3 are the same
                            cout<<"Full house!"<<endl;
                            fullH=25;
                        }
                        else if(die1==die2&&die1==die4&&die3==die5){//Die 1,2,4 are the same
                            cout<<"Full house!"<<endl;
                            fullH=25;
                        }
                        else if(die1==die2&&die1==die5&&die3==die4){//Die 1,2,5 are the same
                            cout<<"Full house"<<endl;
                            fullH=25;
                        }
                        else if(die1==die3&&die1==die4&&die2==die5){//Die 1,3,4 are the same
                            cout<<"Full house"<<endl;
                            fullH=25;
                        }
                        else if(die1==die3&&die1==die5&&die2==die4){//Die 1,3,5 are the same
                            cout<<"Full house"<<endl;
                            fullH=25;
                        }
                        else if(die1==die4&&die1==die5&&die2==die3){//Die 1,4,5 are the same
                            cout<<"Full house"<<endl;
                            fullH=25;
                        }
                        else if(die2==die3&&die2==die4&&die1==die5){//Die 2,3,4 are the same
                            cout<<"Full house!"<<endl;
                            fullH=25;
                        }
                        else if(die2==die3&&die2==die5&&die1==die4){//Die 2,3,5 are the same
                            cout<<"Full house"<<endl;
                            fullH=25;
                        }
                        else if(die2==die4&&die2==die5&&die1==die3){//Die 2,4,5 are the same
                            cout<<"Full house"<<endl;
                            fullH=25;
                        }
                        else if(die3==die4&&die3==die5&&die1==die2){//Die 3,4,5 are the same
                            cout<<"Full house"<<endl;
                            fullH=25;
                        }
                        else{
                            cout<<"You do not have Full house!"<<endl;
                        }
                        cout<<"You received "<<fullH<<" points."<<endl;
                        cout<<endl;
                        tempC='C';
                        roll++;
                        k=1;
                    }
                    else if (pick=='D'){
                        //If Small Straight is chosen, add up each possible combination
                        small1=die2+die3+die4+die5;
                        small2=die1+die3+die4+die5;
                        small3=die1+die2+die4+die5;
                        small4=die1+die2+die3+die5;
                        small5=die1+die2+die3+die4;
                        //10,14 and 18 are the possibilities small straight can add up to
                        //Check if any of the options are valid
                        if(small1==10||small1==14||small1==18){
                            cout<<"You got a Small Straight!"<<endl;
                            small=30;
                        }
                        else if(small2==10||small2==14||small2==18){
                            cout<<"You got a Small Straight!"<<endl;
                            small=30;
                        }
                        else if(small3==10||small3==14||small3==18){
                            cout<<"You got a Small Straight!"<<endl;
                            small=30;
                        }
                        else if(small4==10||small4==14||small4==18){
                            cout<<"You got a Small Straight!"<<endl;
                            small=30;
                        }
                        else if(small5==10||small5==14||small5==18){
                            cout<<"You got a Small Straight!"<<endl;
                            small=30;
                        }
                        //If no options are valid the user gets no points
                        else{
                            cout<<"You do not have Small Straight!"<<endl;
                        }
                        cout<<"You received "<<small<<" points."<<endl;
                        cout<<endl;
                        tempD='D';
                        roll++;
                        k=1;
                    }
                    else if (pick=='E'){
                        //If Large Straight it chosen, check to see if it fits parameters
                        //1-5 Straight
                        if((die1!=die2)&&(die2!=die3)&&(die3!=die4)&&(die4!=die5)&&
                                (die1!=6)&&(die2!=6)&&(die3!=6)&&(die4!=6)&&(die5!=6)){
                            cout<<"You got a Large Straight!"<<endl;
                            large=40;
                        }
                        //2-6 Straight
                        else if((die1!=die2)&&(die2!=die3)&&(die3!=die4)&&(die4!=die5)&&
                                (die1!=1)&&(die2!=1)&&(die3!=1)&&(die4!=1)&&(die5!=1)){
                            cout<<"You got a Large Straight!"<<endl;
                            large=40;
                        }
                        //If neither large straight conditions are met, the user gets no points
                        else{
                            cout<<"You do not have a Large Straight!"<<endl;
                        }
                        cout<<"You received "<<large<<" points."<<endl;
                        cout<<endl;
                        tempE='E';
                        roll++;
                        k=1;
                    }
                    else if (pick=='F'){
                        //If chance is chosen, sum all dice
                        cout<<"You have selected the chance option, all of your dice will be added together."<<endl;
                        chance=die1+die2+die3+die4+die5;
                        cout<<"You received "<<chance<<" points."<<endl;
                        cout<<endl;
                        tempF='F';
                        roll++;
                        k=1;
                    }
                    else if (pick=='G'){
                        //If Yahtzee is chosen, see if all dice are the same value
                        if((die1==die2)&&(die1==die3)&&(die1==die4)&&(die1==die5)){
                        cout<<"YAHTZEE!"<<endl;
                        yahtzee=50;
                        }
                        //If not the user gets 0 points
                        else{
                            cout<<"You do not have Yahtzee!"<<endl;
                        }
                        cout<<"You received "<<yahtzee<<" points."<<endl;
                        cout<<endl;
                        tempG='G';
                        roll++;
                        k=1;
                    }
                    else{//Prompt user to re-pick if any invalid options
                        cout<<"Error, you choose an incorrect value, try again."<<endl;
                    }
                    //Only output total score if user inputs a valid value
                    if(pick=='1'||pick=='2'||pick=='3'||pick=='4'||pick=='5'||pick=='6'||
                            pick=='A'||pick=='B'||pick=='C'||pick=='D'||pick=='E'||pick=='F'||pick=='G'){
                        score=ones+twos+threes+fours+fives+sixes+threek+fourk+fullH+small+large+chance+yahtzee;
                        cout<<"Your current score is: "<<score<<" points!"<<endl;
                        cout<<"You are on "<<roll<<" out of 13."<<endl;
                        cout<<endl;
                    }
                    //End game once roll is 13
                    if(roll==13){
                        float pscore;//Percentage of max score
                        pscore=score/340.0f*100.0f;
                        cout<<"Game over! Your score is "<<score<<" points!"<<endl;
                        cout<<"The max points you can have is 340, you got "<<static_cast<int>(pscore)<<"% of 340!"<<endl;
                        //Open input and output files
                        inGame.open("HighScore.dat");
                        outGame.open("HighScore.dat");
                        outGame<<score;
                        cout<<endl;
                        //Prompt user for high score
                        cout<<"Would you like to see the highest score?(Y/N)"<<endl;
                        char opt;
                        cin>>opt;
                        switch(opt){
                            case 'y':
                            case 'Y':{
                                //If yes, read score from file, output highest score
                                int highs;
                                inGame>>highs;
                                if(score<=highs){
                                    cout<<"The highest score is "<<highs<<endl;
                                    cout<<endl;
                                }
                                else{
                                    cout<<"The highest score is "<<score<<endl;
                                }
                            }break;
                            default:{
                                //If no, end game
                                cout<<"Thanks for playing!"<<endl;
                                inGame.close();
                                outGame.close();
                                return 0;
                            }
                        }
                        //Close Files and Exit
                        cout<<"Thanks for playing!"<<endl;
                        inGame.close();
                        outGame.close();
                        return 0;
                    }
                    }while(k<1);
                }
        }
        //If anything else re-prompt user
        else{
        cout<<"Invalid input, please try again."<<endl;
        cout<<"Input Y/N: ";
        cin>>choice;
        }
    }
    //Close Files and Exit
    inGame.close();
    outGame.close();
    return 0;
}
void inst(void){
    //Instructions
    cout<<"Standard instructions to Yahtzee:"<<endl;
    cout<<"You will be able to re-roll three times for each roll. You can only choose each category once."<<endl;
    cout<<"Ones: Get as many ones as possible by re-rolling. Points are the sum of all ones."<<endl;
    cout<<"Twos: Get as many twos as possible by re-rolling. Points are the sum of all twos."<<endl;
    cout<<"Threes: Get as many threes as possible by re-rolling. Points are the sum of all threes."<<endl;
    cout<<"Fours: Get as many fours as possible by re-rolling. Points are the sum of all fours."<<endl;
    cout<<"Fives: Get as many fives as possible by re-rolling. Points are the sum of all fives."<<endl;
    cout<<"Sixes: Get as many sixes as possible by re-rolling. Points are the sum of all sixes"<<endl;
    cout<<"Three of a kind: Get three dice with the same number. Points are the sum all dice."<<endl;
    cout<<"Four of a kind: Get four dice with the same number. Points are the sum all dice."<<endl;
    cout<<"Full house: Get three of a kind and a pair. 25 points if valid."<<endl;
    cout<<"Small straight: Get four sequential dice. 30 points if valid."<<endl;
    cout<<"Large straight: Get five sequential dice. 40 points if valid."<<endl;
    cout<<"Chance: You can put any roll into chance. Points are the sum all dice."<<endl;
    cout<<"YAHTZEE: Get all dice with the same number. 50 points if valid."<<endl;
    cout<<"Restart the game to play!"<<endl;
}

