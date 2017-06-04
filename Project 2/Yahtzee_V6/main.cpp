/* 
 * File:   main.cpp
 * Author: Veronica Walton
 * Created on June 2, 2017 1:50 PM
 * Purpose:  Yahtzee Version 6
 */

//System Libraries
#include <iostream> //Input - Output Library
#include <cstdlib>  //Srand to set the seed
#include <ctime>    //Time for rand
#include <iomanip>  //Format library
#include <fstream>  //File IO
#include <string>   //String Library
#include <vector>   //To define Vectors
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const int COLS=2;

//Function Prototypes
void menu(void);//Menu Function
void inst(void);//Instructions Function
int shwScr(int,int[][COLS]);//Score function
void shwScr(ofstream &,int,string);//Output High Scores
void outStat(ofstream &,int,string,int[][COLS],vector<int>);//Output Game Stats
void rollDie(int[]);//Roll and re-roll dice
void addNum(int, int[],int[][COLS]);//Function for adding number category
void add3Knd(int,int[],int[][COLS]);//Function for 3 of a Kind
void add4Knd(int,int[],int[][COLS]);//Function for 4 of a Kind
void addFH(int,int[],int[][COLS]);//Function for Full House
void addSmlS(int,int[],int[][COLS]);//Function for Small Straight
void addLrgS(int,int[],int[][COLS]);//Function for Large Straight
void addChn(int,int[],int[][COLS]);//Function for Chance
void addYhtz(int,int[],int[][COLS]);//Function for Yahtzee
int srchLst(int[][COLS],int,int);//Search Function

//Execution begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    char choice;//Option for menu selection
    string name;//Name of user
    int die[5]={};//Array of 5 dice
    int scrTemp[14][COLS]={};//Score and temp for each category
    int chance,score=0;
    vector<int> nums{1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    ifstream in ("InHighScores.txt"); //Input High Scores File
    ofstream out ("HighScores.txt");//Output High Scores File
    ofstream outSt("GameStats.txt");//Output Game Stats File
    float pscore;//Percentage of max score
    string line;

   //Show menu and loop
    do{
        //Show menu function
        menu();
       
        //Choice from menu
        cout<<"Option: ";
        cin>>choice;
        cout<<endl;
        
        //Options from menu
        switch(choice){
            case '1': {//Game starts here
                cout<<"Welcome to Yahtzee!"<<endl;
                cout<<endl;
                
                //Take user name
                cout<<"What's your name? ";
                cin>>name;
                cout<<"Welcome, "<<name<<"!"<<endl<<endl;
                
                //Loop 13 rolls for game
                for(int a=11;a<13;a++){
                    //Roll dice and re-roll if necessary
                    rollDie(die);

                    cout<<"What would you like to do next? Type the number enclosed in parentheses."<<endl;
                    cout<<"Your options are Ones (1), Twos (2), Threes (3), Fours (4), Fives (5), Sixes(6)\n"
                        "Three of a Kind (7), Four of a Kind (8), Full house (9)\n"
                        "Small Straight (10), Large Straight (11), Chance (12), YAHTZEE (13)"<<endl;
                    //Prompt user for option
                    int pick;
                    cout<<"Option: ";
                    cin>>pick;

                    while(scrTemp[pick][1]==1){
                        cout<<"You have already chosen this option, pick another"<<endl;
                        cout<<"Option: ";
                        cin>>pick;
                    }
                    if(pick<=6&&pick>=1){//Number addition
                        addNum(pick,die,scrTemp);
                    }
                    else if(pick==7){//Three of a kind
                        add3Knd(pick,die,scrTemp);
                    }
                    else if(pick==8){//Four of a kind
                        add4Knd(pick,die,scrTemp);
                    }
                    else if(pick==9){//Full House
                        addFH(pick,die,scrTemp);
                    }
                    else if(pick==10){//Small Straight
                        addSmlS(pick,die,scrTemp);
                    }
                    else if(pick==11){//Large Straight
                        addLrgS(pick,die,scrTemp);
                    }
                    else if(pick==12){//Chance
                        addChn(pick,die,scrTemp);
                    }
                    else if(pick==13){//Yahtzee
                        addYhtz(pick,die,scrTemp);
                    }
                    else{
                        while(pick<1||pick>13){
                        cout<<"Error, you choose an incorrect value, try again.";
                        cout<<"Option: ";
                        cin>>pick;
                        }
                    }
                    //Only output total score if user inputs a valid value
                    if(pick<=13&&pick>=1){
                        score=shwScr(score,scrTemp);
                        cout<<"Your current score is "<<score<<"!"<<endl;
                    }
                }
                pscore=score/340.0f*100.0f;
                cout<<"Game over! Your score is "<<score<<" points!"<<endl;
                cout<<"The max points you can have is 340 and you got "<<static_cast<int>(pscore)<<"% of 340!"<<endl;
                
            };break;
            case '2': inst();break;//Show instructions
            case '3': {
                cout<<"Previous High Scores"<<endl;
                while(getline(in,line)){
                    cout<<line<<endl;
                }
            };break;
            case '4':{
                int num;
                num=srchLst(scrTemp,14,0);
                if(num==-1){
                cout<<"You didn't get a zero in any categories, good job!"<<endl;
                }
                else{
                    cout<<"You received a zero in a category!"<<endl;
                }
            }
            default:{
                cout<<"Exit the program"<<endl;
            }
        }
        
    }while(choice>='1'&&choice<='4');
    
    //Output to file
    shwScr(out,score,name);
    outStat(outSt,score,name,scrTemp,nums);
    
    //Close files
    in.close();
    out.close();
    outSt.close();
   
    //Exit stage right!
    return 0;
}

void menu(void){
    cout<<endl<<endl<<"Type 1 to play Yahtzee!"<<endl;
    cout<<"Type 2 for Instructions"<<endl;
    cout<<"Type 3 High Scores"<<endl;
    cout<<"Type 4 To see if you got a zero in any category after playing"<<endl;
    cout<<"Type 0 to exit the program"<<endl<<endl;
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

int shwScr(int score,int total[][COLS]){//Calculate Score
    score=(total[0][0]+total[1][0]+total[2][0]+total[3][0]+total[4][0]+total[5][0]+
        total[6][0]+total[7][0]+total[8][0]+total[9][0]+total[10][0]+total[11][0]+
        total[12][0]+total[13][0]);
    return score;
}

void shwScr(ofstream &out,int score,string name){//High Scores
    out<<fixed<<setprecision(2)<<showpoint;
    out<<"High scores in Yahtzee\n";
    out<<"Name       Score\n";
    out<<name<<setw(13)<<score<<endl;
}

void outStat(ofstream &out,int score,string name,int total[][COLS],vector<int> vect){
    out<<"Latest Player: "<<name<<endl;
    out<<"Score in each category"<<endl;
    for(int a=0;a<14;a++){
        out<<"Category "<<vect[a]<<":";
        out<<total[a][0]<<endl;
    }
}

void rollDie(int dice[]){
    //Declare variables
    char roll,reroll,r;
    //Roll Dice
    for(int i=0;i<5;i++){
        dice[i]=rand()%6+1;//Assign each die a value 1-6
    }
    //Table for dice
    cout<<"Dice Number: 1 | 2 | 3 | 4 | 5"<<endl;
    //Show user dice
    cout<<"Your Dice:"<<setw(4)<<dice[0]<<setw(4)<<dice[1]<<setw(4)<<dice[2]
        <<setw(4)<<dice[3]<<setw(4)<<dice[4]<<endl<<endl;
    //Output options for the user to choose from
    cout<<"Your options are Ones (1), Twos (2), Threes (3), Fours (4), Fives (5), Sixes(6)\n"
            "Three of a Kind (7), Four of a Kind (8), Full house (9)\n"
            "Small Straight (10), Large Straight (11), Chance (12), YAHTZEE (13)"<<endl;
    cout<<endl;
    //Ask if the user wants to re-roll
    for(int k=1;k<=3;k++){
        cout<<"Would you like to re-roll (Y/N)?"; 
        cin>>roll;

        if(roll=='y'||roll=='Y'){
            for (int i=0;i<5;i++){
                cout<<"Would you like to re-roll die "<<i+1<<"? (Y/N)";
                cin>>reroll;
                //Re-roll the dice
                if(reroll=='y'||reroll=='Y')dice[i]=rand()%6+1;
            }
            //Table for dice
            cout<<"Dice Number: 1 | 2 | 3 | 4 | 5"<<endl;
            //Show user dice
            cout<<"New Dice:"<<setw(4)<<dice[0]<<setw(4)<<dice[1]<<setw(4)<<dice[2]
                <<setw(4)<<dice[3]<<setw(4)<<dice[4]<<endl<<endl;
        }
        else k=3;
    }
}

void addNum(int pick,int dice[],int total[][COLS]){//When pick is 1-6
    for(int i=0;i<5;i++){
        if(dice[i]==pick) total[pick][0]+=pick;
    }
    cout<<"You have received "<<total[pick][0]<<" points!"<<endl;
    total[pick][1]=1; 
}

void add3Knd(int pick,int dice[],int total[][COLS]){//When pick is 7
    if(dice[0]==dice[1]&&dice[0]==dice[2]){//Die combination 1,2,3
        cout<<"Three of a kind!"<<endl;
    }
    else if(dice[0]==dice[1]&&dice[0]==dice[3]){//Die combination 1,2,4
        cout<<"Three of a kind!"<<endl;
    }
    else if(dice[0]==dice[1]&&dice[0]==dice[4]){//Die combination 1,2,5
        cout<<"Three of a kind!"<<endl;
    }
    else if(dice[0]==dice[2]&&dice[0]==dice[3]){//Die combination 1,3,4
        cout<<"Three of a kind!"<<endl;
    }
    else if(dice[0]==dice[2]&&dice[0]==dice[4]){//Die combination 1,3,5
        cout<<"Three of a kind!"<<endl;
    }
    else if(dice[0]==dice[3]&&dice[0]==dice[4]){//Die combination 1,4,5
        cout<<"Three of a kind!"<<endl;
    }
    else if(dice[1]==dice[2]&&dice[1]==dice[3]){//Die combination 2,3,4
        cout<<"Three of a kind!"<<endl;
    }
    else if(dice[1]==dice[2]&&dice[1]==dice[4]){//Die combination 2,3,5
        cout<<"Three of a kind!"<<endl;
    }
    else if(dice[1]==dice[3]&&dice[1]==dice[4]){//Die combination 2,4,5
        cout<<"Three of a kind!"<<endl;
    }
    else if(dice[2]==dice[3]&&dice[2]==dice[4]){//Die combination 3,4,5
        cout<<"Three of a kind!"<<endl;
    }
    else{
        cout<<"You do not have three of a kind!"<<endl;
    }
    //Add all the values
    for(int a=0;a<5;a++){
        total[pick][0]+=dice[a];
    }
    cout<<"You have received "<<total[pick][0]<<" points!"<<endl;
    total[pick][1]=1; 
}

void add4Knd(int pick,int dice[],int total[][COLS]){//When pick is 8
    if(dice[0]==dice[1]&&dice[0]==dice[2]&&dice[0]==dice[3]){//Die combination 1,2,3,4
    cout<<"Four of a kind!"<<endl;
    }
    else if(dice[0]==dice[1]&&dice[0]==dice[2]&&dice[0]==dice[4]){//Die combination 1,2,3,5
    cout<<"Four of a kind!"<<endl;
    }
    else if(dice[0]==dice[1]&&dice[0]==dice[3]&&dice[0]==dice[4]){//Die combination 1,2,4,5
    cout<<"Four of a kind!"<<endl;
    }
    else if(dice[0]==dice[2]&&dice[0]==dice[3]&&dice[0]==dice[4]){//Die combination 1,3,4,5
    cout<<"Four of a kind!"<<endl;
    }
    else if(dice[1]==dice[2]&&dice[1]==dice[3]&&dice[1]==dice[4]){//Die combination 2,3,4,5
    cout<<"Four of a kind!"<<endl;
    }
    else{
        cout<<"You do not have four of a kind!"<<endl;
    }
    //Add all the values
    for(int a=0;a<5;a++){
        total[pick][0]+=dice[a];
    }
    cout<<"You have received "<<total[pick][0]<<" points!"<<endl;
    total[pick][1]=1; 
}

void addFH(int pick,int dice[],int total[][COLS]){//When pick is 9
    if(dice[0]==dice[1]&&dice[0]==dice[2]&&dice[3]==dice[4]){//Die 1,2,3 are the same
        cout<<"Full house!"<<endl;
        total[pick][0]=25;
    }
    else if(dice[0]==dice[1]&&dice[0]==dice[3]&&dice[2]==dice[4]){//Die 1,2,4 are the same
        cout<<"Full house!"<<endl;
        total[pick][0]=25;
    }
    else if(dice[0]==dice[1]&&dice[0]==dice[4]&&dice[2]==dice[3]){//Die 1,2,5 are the same
        cout<<"Full house!"<<endl;
        total[pick][0]=25;
    }
    else if(dice[0]==dice[2]&&dice[0]==dice[3]&&dice[1]==dice[4]){//Die 1,3,4 are the same
        cout<<"Full house!"<<endl;
        total[pick][0]=25;
    }
    else if(dice[0]==dice[2]&&dice[0]==dice[4]&&dice[1]==dice[3]){//Die 1,3,5 are the same
        cout<<"Full house!"<<endl;
        total[pick][0]=25;
    }
    else if(dice[0]==dice[3]&&dice[0]==dice[4]&&dice[1]==dice[2]){//Die 1,4,5 are the same
        cout<<"Full house!"<<endl;
        total[pick][0]=25;
    }
    else if(dice[1]==dice[2]&&dice[1]==dice[3]&&dice[0]==dice[4]){//Die 2,3,4 are the same
        cout<<"Full house!"<<endl;
        total[pick][0]=25;
    }
    else if(dice[1]==dice[2]&&dice[1]==dice[4]&&dice[0]==dice[3]){//Die 2,3,5 are the same
        cout<<"Full house!"<<endl;
        total[pick][0]=25;
    }
    else if(dice[1]==dice[3]&&dice[1]==dice[4]&&dice[0]==dice[2]){//Die 2,4,5 are the same
        cout<<"Full house!"<<endl;
        total[pick][0]=25;
    }
    else if(dice[2]==dice[3]&&dice[2]==dice[4]&&dice[0]==dice[1]){//Die 3,4,5 are the same
        cout<<"Full house!"<<endl;
        total[pick][0]=25;
    }
    //If no options are valid the user gets no points
    else{
        cout<<"You do not have Full house!"<<endl;
    }
    cout<<"You have received "<<total[pick][0]<<" points!"<<endl;
    total[pick][1]=1; 
}

void addSmlS(int pick,int dice[],int total[][COLS]){//When pick is 10
    static int temp1,temp2,temp3,temp4,temp5;
    temp1=dice[1]+dice[2]+dice[3]+dice[4];//Dice 2,3,4,5 combo
    temp2=dice[0]+dice[2]+dice[3]+dice[4];//Dice 1,3,4,5 combo
    temp3=dice[0]+dice[1]+dice[3]+dice[4];//Dice 1,2,4,5 combo
    temp4=dice[0]+dice[1]+dice[2]+dice[4];//Dice 1,2,3,5 combo
    temp5=dice[0]+dice[1]+dice[2]+dice[3];//Dice 1,2,3,4 combo
    //10,14 and 18 are the possibilities small straight can add up to
    //Check if any of the options are valid
    if(temp1==10||temp1==14||temp1==18){
        cout<<"You got a Small Straight!"<<endl;
        total[pick][0]=30;
    }
    else if(temp2==10||temp2==14||temp2==18){
        cout<<"You got a Small Straight!"<<endl;
        total[pick][0]=30;
    }
    else if(temp3==10||temp3==14||temp3==18){
        cout<<"You got a Small Straight!"<<endl;
        total[pick][0]=30;
    }
    else if(temp4==10||temp4==14||temp4==18){
        cout<<"You got a Small Straight!"<<endl;
        total[pick][0]=30;
    }
    else if(temp5==10||temp5==14||temp5==18){
        cout<<"You got a Small Straight!"<<endl;
        total[pick][0]=30;
    }
    //If no options are valid the user gets no points
    else{
        cout<<"You do not have Small Straight!"<<endl;
    }
    cout<<"You have received "<<total[pick][0]<<" points!"<<endl;
    total[pick][1]=1; 
}

void addLrgS(int pick,int dice[],int total[][COLS]){//When pick is 11
    if((dice[0]!=dice[1])&&(dice[1]!=dice[2])&&(dice[2]!=dice[3])&&(dice[3]!=dice[4])&&
            (dice[0]!=6)&&(dice[1]!=6)&&(dice[2]!=6)&&(dice[3]!=6)&&(dice[4]!=6)){//1-5 Straight
        cout<<"You got a Large Straight!"<<endl;
        total[pick][0]=40;
    }
    //2-6 Straight
    else if((dice[0]!=dice[1])&&(dice[1]!=dice[2])&&(dice[2]!=dice[3])&&(dice[3]!=dice[4])&&
            (dice[0]!=1)&&(dice[1]!=1)&&(dice[2]!=1)&&(dice[3]!=1)&&(dice[4]!=1)){
        cout<<"You got a Large Straight!"<<endl;
        total[pick][0]=40;
    }
    //If neither large straight conditions are met, the user gets no points
    else{
        cout<<"You do not have a Large Straight!"<<endl;
    }
    cout<<"You receive "<<total[pick][0]<<" points!"<<endl;
    total[pick][1]=1; 
}

void addChn(int pick,int dice[],int total[][COLS]){//When pick is 12
    cout<<"You have selected the chance option, all of your dice will be added together."<<endl;
    for(int i=0;i<5;i++){
        total[pick][0]+=dice[i];
    }
    cout<<"You have received "<<total[pick][0]<<" points!"<<endl;
    total[pick][1]=1; 
}

void addYhtz(int pick,int dice[],int total[][COLS]){//When pick is 13
    if((dice[0]==dice[1])&&(dice[0]==dice[2])&&(dice[0]==dice[3])&&(dice[0]==dice[4])){//If dice are the same
    cout<<"YAHTZEE!"<<endl;
    total[pick][0]=50;
    }
    //If not the user gets 0 points
    else{
        cout<<"You do not have Yahtzee!"<<endl;
    }
    cout<<"You have received "<<total[pick][0]<<" points!"<<endl;
    total[pick][1]=1; 
}

int srchLst(int list[][COLS],int numElm,int value){
    int index=0;
    int pos=-1;
    bool found=false;
    
    while(index<numElm&&!found){
        if(list[index][0]==value)
        {
            found=true;
            pos=index;
        }
        index++;
    }
    return pos;
}