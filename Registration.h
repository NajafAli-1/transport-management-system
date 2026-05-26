#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include "Student.h"
#include "Admin.h"


using namespace std;

class Registration{
private:

    int choise;
    
public:
    Registration() {
        cout<<"Please create you account"<<endl;
    }
    void Info() {
        cout<<"Registration as: "<<endl;
        cout<<" 1. Student  "<<endl;
        cout<<" 2. Admin "<<endl;
        cin>>choise;
        cin.ignore();

        if(choise==1){
            cout<<"Student Registration "<<endl;
            Student s;
            s.INfo();

        }
        else if(choise==2){
            cout<<"Admin Registration "<<endl;
            Admin A;
            A.INFO();
        }
        else{
            cout<<"Wrong choice"<<endl;
        }
        
    }
};