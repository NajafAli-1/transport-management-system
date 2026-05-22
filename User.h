#include<iostream>
#pragma once

using namespace std;

class User{
private:
    string name;
    int ID;
    string passward;

public:
    void Info() {

        cout<<"Enter name: ";
        getline(cin,name);
        //cin.ignore();
        
        cout<<"Enter ID: ";
        cin>>ID;
        cin.ignore();
        
        cout<<"Enter passward: ";
        getline(cin,passward);
        

    }
};