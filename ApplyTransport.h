#pragma once
#include<iostream>
#include "ViewRoute.h"


using namespace std;





class ApplyTransport{
protected:

    string data;
    string data2;
    int select;
    char again;

public:
    void Apply(string studentname, int studentID) {
        again='y';
        while(again=='y'){
        ifstream file("ViewRoute.txt");
        if(!file.is_open()){
                ViewRoute V;
                V.Display();
                file.open("ViewRoute.txt");
        }

        ofstream file2("ApplyTransport.txt",ios::app);

        cout<<"============================================"<<endl;
        cout<<"   Apply for University Transport Service   "<<endl;
        cout<<"============================================"<<endl;

        cout<< "_______________________"<<endl;
        cout<<"|                       |"<<endl;
        cout<<"|Please select Route    |"<<endl;
        cout<<"|_______________________|"<<endl;

        while(getline(file,data)){                    // Extracting data from file "ViewRoute.txt"
            cout<<data<<endl;
        }

        cout<<"Route Number: ";
        cin>>select;

        if(select==1 || select==2 || select==3){
            cout<<"Your application for route "<<select<<" has been sent to Administration. "<<endl;
            file2<<"========================="<<endl;
            file2<<"Student Name : "<<studentname<<endl;
            file2<<"Student ID   : "<<studentID<<endl;
            file2<<"Applied Route: "<<select<<endl;
            file2<<"Status       : Pending"<<endl;
            file2<<"========================="<<endl;
            file2.close();
            again = 'n'; 

        }
        else{
            cout<<"No such route are available !!!!"<<endl;
            cout<<"Please select Route that are available in University......"<<endl;
            cout<<"Do you want to select route again (y=yes/n=no): ";
            cin>>again;
            cin.ignore();
            file2.close();

        }
        
        file.close();
        file2.close();

        }
        
    }
};