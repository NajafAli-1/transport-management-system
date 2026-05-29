#pragma once
#include<iostream>
#include<limits>
#include<vector>
#include<string>
#include<fstream>

#include "AddVehicle.h"

using namespace std;

class RemoveTransport : public AddVehicle {

public:
    void remove(){

        // ── Step 1: Read all vehicles from AddVehicle.txt ──
        vector<string> names, bustypes;
        vector<int>    capacities;

        ifstream file("AddVehicle.txt");
        if(!file.is_open() || file.peek() == EOF){
            cout<<"No vehicles found. Please add vehicles first."<<endl;
            return;
        }

        string n, b, c;
        while(getline(file,n) && getline(file,b) && getline(file,c)){
            names.push_back(n);
            bustypes.push_back(b);
            capacities.push_back(stoi(c));
        }
        file.close();

        if(names.empty()){
            cout<<"No vehicles to remove."<<endl;
            return;
        }

        // ── Step 2: Display vehicles (same style as AddVehicle) ──
        cout<<endl;
        for(int i=0; i<(int)names.size(); i++){
            cout<<"========================================="<<endl;
            cout<<"    ---------VEHICLE DETAIL---------     "<<endl;
            cout<<i+1<<". Vehicle name : "<<names[i]<<endl;
            cout<<"   Bus type     : "<<bustypes[i]<<endl;
            cout<<"   Capacity     : "<<capacities[i]<<endl;
            cout<<"=========================================="<<endl;
        }

        // ── Step 3: Ask which vehicle to remove ──
        string target;
        cout<<"\nEnter the vehicle name to remove: ";
        getline(cin, target);

        // ── Step 4: Rewrite AddVehicle.txt without the removed entry ──
        bool found = false;
        ofstream out("AddVehicle.txt");          // overwrite (no ios::app)

        for(int i=0; i<(int)names.size(); i++){
            if(names[i] == target){
                found = true;                    // skip this entry
            } else {
                out<<names[i]<<endl;
                out<<bustypes[i]<<endl;
                out<<capacities[i]<<endl;
            }
        }
        out.close();

        if(found)
            cout<<"Vehicle '"<<target<<"' removed successfully!"<<endl;
        else
            cout<<"Vehicle '"<<target<<"' not found."<<endl;
    }

    // ── Bonus: call AddVehicle::Add() directly from here ──
    void addNew(){
        Add();
    }
};