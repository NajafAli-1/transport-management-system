#include<iostream>
#include<fstream>

#include "StudentPanel.h"

using namespace std;

int choose;

class Login{
private:
    string inputname;
    string inputpass;
    string Role;
    string filename;
    string filepass;
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

        bool found=false;
        
        while(getline(file,filename) && getline(file,filepass)){

            if(filename == inputname && filepass == inputpass){
                cout<<"Login Successfully!!!!"<<endl;
                found=true;
                break;
            }


        }

        

        while(getline(file1,filename) && getline(file1,filepass)){
            

            if(filename == inputname && filepass == inputpass){
                cout<<"Login Successfully!!!!"<<endl;
                found=true;
                break;
            }

        }

        if(!found){
            cout<<inputname<<" is not registered"<<endl;
        }

        if(found){
            cout<<"_________________________"<<endl;
            cout<<"|     1. Student Menu    |"<<endl;
            cout<<"|     2. Admin Menu      |"<<endl;
            cout<<"|________________________|"<<endl;
            cin>>choose;
            
            if(choose==1){
                StudentPanel SP;
                SP.Display();
            }
        }

        
    }
};