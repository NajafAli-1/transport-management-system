#pragma once
#include<iostream>
#include "ViewRoute.h"


using namespace std;





class ApplyTransport{
protected:

    string data;
    string data2;
    int select;
    bool again;

public:
    void Apply() {
        while(again=='y'){
        ifstream file("ViewRoute.txt");
        ofstream file2("ApplyTransport.txt");

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
            file2<<"Your application for route "<<select<<" has been sent to Administration."<<endl;

           // while(getline(file,data2)){
           //     getline(file,)
           //}

            
        }
        else{
            cout<<"No such route are available !!!!"<<endl;
            cout<<"Please select Route that are available in University......"<<endl;
            cout<<"Do you want to select route again (y=yes/n=no): ";
            cin>>again;

        }
        
        file.close();
        file2.close();

        }
        
    }
};