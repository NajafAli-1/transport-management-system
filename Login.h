#pragma once
#include<iostream>
#include<fstream>

#include "StudentPanel.h"
#include "AdminPanel.h"

using namespace std;

int choose;

class Login{
private:
    string inputname,storename;
    string inputpass,storepass;
    string Role;
    string filename;
    string filepass;
    string skip;
    bool found=false;
    bool found1=false;
public:
    Login() {
        cout<<"==============="<<endl;
        cout<<"|   LOGIN     |"<<endl;
        cout<<"==============="<<endl;
        cout<<"Welcome!! Please enter your Credentials"<<endl;
    }

    void detail(){

        ifstream file("Student.txt");
        ifstream file1("Admin.txt");

        cout<<"Name: ";
        getline(cin,inputname);
        cout<<"Passward: ";
        getline(cin,inputpass);

        
        
        while(getline(file,filename) && getline(file,filepass)){

            if(filename == inputname && filepass == inputpass){
                cout<<"Login Successfully!!!!"<<endl;
                found=true;
                break;
            }


        }

        

        while(getline(file1,filename) && getline(file1,filepass)){
            getline(file1, skip); // skip ID
            getline(file1, skip); // skip email
            getline(file1, skip); // skip Role

            if(filename == inputname && filepass == inputpass){
                cout<<"Login Successfully!!!!"<<endl;
                found1=true;
                break;
            }

        }

        if(!found && !found1){
            cout<<inputname<<" is not registered"<<endl;
        }

        if(found){
            cout<< "________________________"<<endl;
            cout<<"| Click '1' to enter     |"<<endl;
            cout<<"|     Student Menu       |"<<endl;
            cout<<"|________________________|"<<endl;
            cin>>choose;
            
            if(choose==1){
                StudentPanel SP;
                SP.Display();
            }
            
        }
        
        else if(found1){
            cout<< "________________________"<<endl;
            cout<<"| Click '1' to enter     |"<<endl;
            cout<<"|     Admin Menu         |"<<endl;
            cout<<"|________________________|"<<endl;
            cin>>choose;

            if(choose==1){
                AdminPanel A;
                A.Display();
            }
           
        }

        
    }

    void store(){
        storename=inputname;
        storepass=inputpass;
        cout<<"Name: "<<storename<<endl;
    }
};