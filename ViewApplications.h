#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "ApplyTransport.h"
//#include "Login.h"


using namespace std;

class ViewApplication{
private:

public:
    void view(){
        cout<<"========================="<<endl;
        cout<<"|                       |"<<endl;
        cout<<"| Pending Application   |"<<endl;
        cout<<"|                       |"<<endl;
        cout<<"========================="<<endl;

        ifstream file("ApplyTransport.txt");

       // Login l;
        //l.store();
    }
};