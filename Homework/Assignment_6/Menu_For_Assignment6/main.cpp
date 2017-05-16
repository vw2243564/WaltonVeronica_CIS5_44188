/* 
 * File:   main.cpp
 * Author: Veronica Walton
 * Created on May 16, 2017, 1:05 AM
 * Purpose:  Menu for Assignment 6
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <string>
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
long search(long[],long,long);//Prob 6 Function
void prob7(void);
void bSort(int [], int);//Prob 7
void sSort(int [], int);//Prob 7
void showArray(int [],int);//Prob 7
void prob8(void);
int lotto(int[],int,int);//Prob 8
void prob9(void);
void sortRain(float[],int);//Prob 9
void showRain(float[],int);//Prob 9

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
    //Declare variables
    const int SIZE=12;//12 total values
    float month[SIZE]={};
    string name[SIZE]={"January","February","March","April","May","June","July",
                        "August","September","October","November","December"};
    float total=0.0f, avg=0.0f;
    string lmonth,hmonth;

    //Input data
    cout<<"This program will output rainfall statistics."<<endl;
    cout<<"Input the inches of rainfall for each month."<<endl;
    for(int k=0;k<SIZE;k++){
        cout<<name[k]<<": ";
        cin>>month[k];
        while(month[k]<0){
            cout<<"Please enter a number greater than 0: ";
            cin>>month[k];
        }
    }
    
    //Year total
    for(int z=0;z<=SIZE;z++){
        total+=month[z];
    }
    cout<<endl;
    cout<<"The total for the year is "<<total<<" inches."<<endl;
    cout<<endl;
    
    //Average
    avg=total/12.0f;
    cout<<"The average for each month is "<<avg<<" inches."<<endl;
    cout<<endl;
    
    //Lowest rainfall
    float low=month[0];
    float high=month[0];
    lmonth=name[0];
    hmonth=name[0];
    for (int x=1;x<SIZE;x++){
        if(month[x]<low){
            low=month[x];
            lmonth=name[x];
        }
        else if(month[x]>high){
            high=month[x];
            hmonth=name[x];
        }
    }
    cout<<lmonth<<" had the lowest amount of rainfall with "<<low<<" inches."<<endl;
    cout<<hmonth<<" had the highest amount of rainfall with "<<high<<" inches."<<endl;
    cout<<endl;
    
    //Display Array
    cout<<"The unsorted values are: ";
    showRain(month,SIZE);
    
    //Sort Array
    sortRain(month,SIZE);
    
    //Display Array
    cout<<"The unsorted values are: ";
    showRain(month,SIZE);
}

void sortRain(float array[],int num){
    bool swap;
    int temp;
    
    do{
        swap=false;
        for(int i=0;i<(num-1);i++){
            if(array[i]>array[i+1]){
                temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                swap=true;
            }
        }
    }while(swap);
}

void showRain(float array[],int num){
    for(int i=0;i<num;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void prob8(void){
    //Declare Variables
    int num[10]={13579,26791,26792,33445,55555,
    62483,77777,79422,85647,93121};
    int result,find;
    
    //Prompt User
    cout<<"Enter this week's winning 5 digit number: ";
    cin>>find;
    
    //Search Array
    result=lotto(num,10,find);
    
    //If search returns -1, find variable was not found
    if(result==-1){
        cout<<"Your number "<<find<<" did not win!"<<endl;
    }
    else{
        cout<<find<<" is a winning number!!"<<endl;
    }
}

int lotto(int list[],int numElm, int value){
    int index=0;
    int pos =-1;
    bool found=false;
    
    while(index<numElm && !found){
        if(list[index]==value){//If value has been found
            found=true;
            pos=index;
        }
        index++;    
    }
    return pos;
}

void prob7(void){
    //Declare Variables
    int bArray[8]={88,77,66,99,55,11,22,44};//Array for bubble sort
    int sArray[8]={88,77,66,99,55,11,22,44};//Array for selection sort
    
    //Bubble Sort
    cout<<"Values sorted by Bubble Sort:"<<endl;
    bSort(bArray,8);
    cout<<endl;
    
    //Selection Sort
    cout<<"Values sorted by Selection Sort:"<<endl;
    sSort(sArray,8);
}

void showArray(int array[],int num){
    for(int i=0;i<num;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void bSort(int array[],int num){
    bool swap;
    int temp;
    
    do{
        swap=false;
        for(int i=0;i<(num-1);i++){
            if(array[i]>array[i+1]){
                temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                swap=true;
            }
        }
       showArray(array,num);
    }while(swap);
}

void sSort(int array[],int size){
    int start,minIndx,minVal;
    
    for(start=0;start<(size-1);start++){
        minIndx=start;
        minVal=array[start];
        for(int index=start+1;index<size;index++){
            if(array[index]<minVal){
                minVal=array[index];
                minIndx=index;
            }
        }
        array[minIndx]=array[start];
        array[start]=minVal;
        showArray(array,size);
    }
}

void prob6(void){
    //Declare Variables
    long num[18]={5658845,4520125,7895122,8777541,8451277,1302850,
    8080152,4562555,5552012,5050552,7825877,1250255,
    1005231,6545231,3852085,7576651,7881200,4581002};
    long result,find;
    
    //Prompt User
    cout<<"Input a charge account number and we'll check if it's in the system: ";
    cin>>find;
    
    //Search Array
    result=search(num,18,find);
    
    //If search returns -1, find variable was not found
    if(result==-1){
        cout<<find<<" was not found in our system."<<endl;
    }
    else{
        cout<<find<<" has been located in sector number "<<result+1<<endl;
    }
}

long search(long list[],long numElm, long value){
    int index=0;
    int pos =-1;
    bool found=false;
    
    while(index<numElm && !found){
        if(list[index]==value){//If value has been found
            found=true;
            pos=index;
        }
        index++;    
    }
    return pos;
}

void prob5(void){
    //Declare Variables
    int monkey[3][5];//Monkeys apparently only get fed 5 times a week
    int total=0, low, high;
    
    //Input values
    for(int i=0;i<3;i++){
        for(int k=0;k<5;k++){
            cout<<"Input how much monkey "<<i+1<<" ate on day "<<k+1<<": ";
            cin>>monkey[i][k];
        }
    }
    cout<<endl;
    
    //Add values
    for(int i=0;i<3;i++){
        for(int k=0;k<5;k++){
            total+=monkey[i][k];
        }
    }  
    float avg;
    avg=total/3.0f/5.0f;
    cout<<"The average amount of food eaten per day is "<<avg<<" pounds."<<endl;
    
    //Lowest and Highest
    low=monkey[0][0];
    high=monkey[0][0];
    for (int x=1;x<3;x++){
        for(int k=1;k<5;k++){
            if(monkey[x][k]<low){
            low=monkey[x][k];
        }
            else if(monkey[x][k]>high){
                high=monkey[x][k];
            }
        }
    }    
    cout<<"The least amount of food eaten on a single day was "<<low<<endl;
    cout<<"The greatest amount of food eaten on a single day was "<<high<<endl;
}

void prob4(void){
    //Declare Variables
    int size, num;
    int array[size];
    
    //Input values
    cout<<"This program will output all values greater than n."<<endl;
    cout<<"Input the size of the array: ";
    cin>>size;
    cout<<"Input the value of n: ";
    cin>>num;
    cout<<endl;
    
    //Fill Array
    cout<<"Input values of array"<<endl;
    for(int k=0;k<size;k++){
        cout<<k+1<<": ";
        cin>>array[k];
    }
    cout<<endl;
    
    //Process by mapping inputs to outputs
    cout<<"The numbers greater than "<<num<<" are: ";
    for(int i=0;i<size;i++){
        if (array[i]>num) cout<<array[i]<<" ";
    }
}

void prob3(void){
    //Declare Variables
    const int SIZE=5;//Number of jars
    int salsa[SIZE]={};
    string name[SIZE]={"Mild","Medium","Sweet","Hot","Zesty"};
    string lsalsa,hsalsa;
    int total=0;
    
    //Input values
    cout<<"This program calculate sales."<<endl;
    cout<<"Input the sales for each salsa."<<endl;
    for(int k=0;k<SIZE;k++){
        cout<<name[k]<<": ";
        cin>>salsa[k];
        while(salsa[k]<0){
            cout<<"Please enter a number greater than 0: ";
            cin>>salsa[k];
        }
    }
    
    //Salsa total
    for(int z=0;z<=SIZE;z++){
        total+=salsa[z];
    }
    cout<<endl;
    cout<<"The total number of salsa sold is "<<total<<" jars."<<endl;
    cout<<endl;
    
    //Lowest/Highest Sales
    int low=salsa[0];
    int high=salsa[0];
    lsalsa=name[0];
    hsalsa=name[0];
    for (int x=1;x<SIZE;x++){
        if(salsa[x]<low){
            low=salsa[x];
            lsalsa=name[x];
        }
        else if(salsa[x]>high){
            high=salsa[x];
            hsalsa=name[x];
        }
    }
    cout<<lsalsa<<" had the lowest amount of jars sold with "<<low<<" jars."<<endl;
    cout<<hsalsa<<" had the highest amount of jars sold with "<<high<<" jars."<<endl;
}

void prob2(void){
    //Declare variables
    const int SIZE=12;//12 total values
    float month[SIZE]={};
    string name[SIZE]={"January","February","March","April","May","June","July",
                        "August","September","October","November","December"};
    float total=0.0f, avg=0.0f;
    string lmonth,hmonth;

    //Input data
    cout<<"This program will output rainfall statistics."<<endl;
    cout<<"Input the inches of rainfall for each month."<<endl;
    for(int k=0;k<SIZE;k++){
        cout<<name[k]<<": ";
        cin>>month[k];
        while(month[k]<0){
            cout<<"Please enter a number greater than 0: ";
            cin>>month[k];
        }
    }
    
    //Year total
    for(int z=0;z<=SIZE;z++){
        total+=month[z];
    }
    cout<<endl;
    cout<<"The total for the year is "<<total<<" inches."<<endl;
    cout<<endl;
    
    //Average
    avg=total/12.0f;
    cout<<"The average for each month is "<<avg<<" inches."<<endl;
    cout<<endl;
    
    //Lowest rainfall
    float low=month[0];
    float high=month[0];
    lmonth=name[0];
    hmonth=name[0];
    for (int x=1;x<SIZE;x++){
        if(month[x]<low){
            low=month[x];
            lmonth=name[x];
        }
        else if(month[x]>high){
            high=month[x];
            hmonth=name[x];
        }
    }
    cout<<lmonth<<" had the lowest amount of rainfall with "<<low<<" inches."<<endl;
    cout<<hmonth<<" had the highest amount of rainfall with "<<high<<" inches."<<endl;
}

void prob1(void){
    //Declare variables
    const int SIZE=9;//10 total values
    int num[SIZE]={};
      
    //Input data
    cout<<"This program will output the largest and smallest of 10 values."<<endl;
    for(int i=0;i<=SIZE;i++){
        cout<<"Input value "<<(i+1)<<": ";
        cin>>num[i];
    }
       
    //Smallest number
    int small=num[0];
    for (int x=1;x<=SIZE;x++){
        if(num[x]<small)
            small=num[x];
    }
    cout<<"The smallest number is "<<small<<endl;
    
    //Largest number
    int large=num[0];
    for (int x=1;x<=SIZE;x++){
        if(num[x]>large)
            large=num[x];
    }
    cout<<"The largest number is "<<large<<endl;     
}

void menu(void){
    cout<<endl<<endl<<"Type 0 to exit"<<endl;
    cout<<"Type 1 for Largest/Smallest Array Problem"<<endl;
    cout<<"Type 2 Rainfall Statistics Problem"<<endl;
    cout<<"Type 3 Salsa Sales Problem"<<endl;
    cout<<"Type 4 N Problem"<<endl;
    cout<<"Type 5 Monkey Business Problem"<<endl;
    cout<<"Type 6 Charge Account Problem"<<endl;
    cout<<"Type 7 for Sorting Orders Problem"<<endl;
    cout<<"Type 8 for Lottery Problem"<<endl;
    cout<<"Type 9 for Modified Rainfall Problem"<<endl<<endl;
}