#pragma once
#include<iostream>
#include "ViewRoute.h"
#include "StudentPanel.h"

using namespace std;

int select;
bool again;

class ApplyTransport{
protected:
    string data;
public:
    void Apply() {
        ifstream file("ViewRoute.txt");

        cout<<"============================================"<<endl;
        cout<<"   Apply for University Transport Service   "<<endl;
        cout<<"============================================"<<endl;

        cout<< "_______________________"<<endl;
        cout<<"|                       |"<<endl;
        cout<<"|Please select Route    |"<<endl;
        cout<<"|_______________________|"<<endl;
        while(getline(file,data)){
            cout<<data<<endl;
        }
        cout<<"Route Number: ";
        cin>>select;

        if(select==1 || select==2 || select==3){
            cout<<"Your application for route "<<select<<" has been sent to Administration."<<endl;
        }
        else{
            cout<<"No such route are available !!!!"<<endl;
            cout<<"Please select Route that are available in University......"<<endl;
            cout<<"Do you want to select route again (y=yes/n=no): ";
            cin>>again;

            if(again=='y'){
                Apply();
            }
            else{
                StudentPanel s1;            // Here is the problem
                s1.Display();
            }
        }
        
        
    }
};