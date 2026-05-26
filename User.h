#pragma once
#include<iostream>
#include<string>

using namespace std;

class User{
protected:
    string name;
    int ID;
    string passward;

public:
    void Info() {

        cout<<"Enter name: ";
        getline(cin,name);
        

        cout<<"Enter passward: ";
        getline(cin,passward);
        
        cout<<"Enter ID: ";
        cin>>ID;
        cin.ignore();
        
       
        

    }
};