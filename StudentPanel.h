#pragma once
#include<iostream>
#include "ApplyTransport.h"
#include "ViewRoute.h"


using namespace std;

int choice;


class StudentPanel{


public:
    void Display() {
        cout<<"=============Student Menu============="<<endl;
        cout<<"|         1. View Routes             |"<<endl;
        cout<<"|         2. Apply for Transport     |"<<endl;
        cout<<"|         3. View my registration    |"<<endl;
        cout<<"|         4. View Bill               |"<<endl;
        cout<<"|         5. Cancel Registration     |"<<endl;
        cout<<"|         6. Logout                  |"<<endl;
        cout<<"|____________________________________|"<<endl;
        cin>>choice;

        if(choice==1){
            ViewRoute V;
            V.Display();
        }
        else if(choice==2){
            ApplyTransport AT;
            AT.Apply();
        }
        else if(choice==3){

        }
        else if(choice==4){

        }
        else if(choice==5){

        }
        else if(choice==6){

        }
        else{
            cout<<"Wrong Choice......."<<endl;
        }
    }
};