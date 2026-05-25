#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class AddVehicle{
protected:

    string name;
    int count;
    string bustype;
    string store;

public:
    void Add(){
        ofstream file("AddVehicle.txt",ios::app);

        
        cout<<"How many vehicle do you want to add: ";
        cin>>count;
        cin.ignore();
        
        vector<string> name(count);
        vector<string> bustype(count);
        vector<int> capacity(count);

        for(int i=0; i<count; i++){
            cout<<"Route name "<<i+1<<": ";
            getline(cin,name[i]);

            cout<<"Bus type "<<i+1<<": ";
            getline(cin,bustype[i]);
            
            cout<<"Capacity "<<i+1<<": ";
            cin>>capacity[i];
            cin.ignore();
        }

        for(int i=0; i<count; i++){
            cout<<endl;
            cout<<"========================================="<<endl;
            cout<<"    ---------ROUTE DETAIL---------       "<<endl;
            cout<<""<<i+1<<". Route "<<i+1<<" name: "<<name[i]<<endl;
            cout<<"   Bus type "<<": "<<bustype[i]<<endl;
            cout<<"   Capacity "<<": "<<capacity[i]<<endl;
            cout<<"=========================================="<<endl;
        }

        for(int i=0; i<count; i++){
            file<<name[i]<<endl;
            file<<bustype[i]<<endl;
            file<<capacity[i]<<endl;
        }

        file.close();
        
    }
};