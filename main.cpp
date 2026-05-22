#include<iostream>
#include<string>
#include "Registration.h"


using namespace std;

int main(){
    cout<<"========================================================"<<endl;
    cout<<"|        UNIVERSITY TRANSPORT MANAGMENT SYSTEM         |"<<endl;
    cout<<"========================================================"<<endl;
    cout<<endl;
    int choice;
    cout<<"___________________________"<<endl;
    cout<<"|  1. Register             |"<<endl;
    cout<<"|  2. Login                |"<<endl;
    cout<<"|  0. Logout               |"<<endl;
    cout<<"|__________________________|"<<endl;
    cin>>choice;
    cin.ignore();

    if(choice==1){
        cout<<"Welcome to registration"<<endl;
        Registration R;
        R.Info();
        
    }
    else if(choice==2){
        cout<<"Welcome to Login "<<endl;
    }
    else if(choice==0){
        cout<<"Logout Successfully!!!"<<endl;
    }
    else{
        cout<<"Please choose correct option"<<endl;
    }
}