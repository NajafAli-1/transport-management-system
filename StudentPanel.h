#pragma once
#include<iostream>
#include<string>

#include "ApplyTransport.h"
#include "ViewRoute.h"
#include "ViewBill.h"

using namespace std;

class StudentPanel{
private:
    int choice;
    string studentName;
    int studentID;

public:
    
    StudentPanel(string name, int id) : choice(0), studentName(name), studentID(id) {}

    void Display() {
        
        while(true){
            cout<<"\n=============Student Menu============="<<endl;
            cout<<"|         1. View Routes             |"<<endl;
            cout<<"|         2. Apply for Transport     |"<<endl;
            cout<<"|         3. View my registration    |"<<endl;
            cout<<"|         4. View Bill               |"<<endl;
            cout<<"|         5. Cancel Registration     |"<<endl;
            cout<<"|         6. Logout                  |"<<endl;
            cout<<"|____________________________________|"<<endl;
            cout<<"Choice: ";
            cin>>choice;
            cin.ignore();

            if(choice==1){
                ViewRoute V;
                V.Display();
            }
            else if(choice==2){
                ApplyTransport AT;
                AT.Apply(studentName, studentID);
            }
            else if(choice==3){
                
                
            }
            else if(choice==4){
                ViewBill VB(studentName, studentID);
                VB.View();
            }
            else if(choice==5){
                

            }
            else if(choice==6){
                
                cout<<"Logged out successfully!"<<endl;
                break;
            }
            else{
                cout<<"Wrong Choice. Please try again."<<endl;
            }
        }
    }
};