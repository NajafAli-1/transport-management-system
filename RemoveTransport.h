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
            cout<<i+1<<". Driver name : "<<names[i]<<endl;
            cout<<"   Bus type     : "<<bustypes[i]<<endl;
            cout<<"   Capacity     : "<<capacities[i]<<endl;
            cout<<"=========================================="<<endl;
        }

        // ── Step 3: Ask which vehicle number to remove ──
        int choice;
        cout << "\nEnter vehicle number to remove: ";
        cin >> choice;

        if(choice < 1 || choice > names.size()){
        cout << "Invalid vehicle number!" << endl;
        return;
        }

        // ── Step 4: Rewrite AddVehicle.txt without the selected entry ──
        ofstream out("AddVehicle.txt");

        for(int i = 0; i < names.size(); i++){
            if(i == choice - 1){
            continue;   // Skip selected vehicle
        }

        out << names[i] << endl;
        out << bustypes[i] << endl;
        out << capacities[i] << endl;
        }

        out.close();

        cout << "Vehicle " << choice << " removed successfully!" << endl;

        
    }
    // ── Bonus: call AddVehicle::Add() directly from here ──
    // void addNew(){
    //     Add();
    // }
};