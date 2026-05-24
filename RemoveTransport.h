#include<iostream>
#include<vector>
#include<string>
#include<fstream>

#include "AddVehicle.h"

using namespace std;

class RemoveTransport{
private:
vector<string> name;
vector<string> bustype;
vector<int> capacity;

public:
    void remove(){
        AddVehicle A;

        ifstream file("AddVehicle.txt");
        string n,b,c_str;
        int c;

        while(getline(file,n) && getline(file,b) && getline(file,c_str)){
            name.push_back(n);
            bustype.push_back(b);
            capacity.push_back(stoi(c_str));
        }

        file.close();


        for(int i = 0; i < name.size(); i++){
            cout << "Vehicle: "  << name[i]     << endl;
            cout << "Type: "     << bustype[i]  << endl;
            cout << "Capacity: " << capacity[i] << endl;
            cout << "-------------------" << endl;
        }
    }
};