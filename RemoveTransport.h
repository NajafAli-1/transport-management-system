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
        ofstream tempfile("Tempfile.txt");
        
        string remove1;
        string n,b,ty,na,c_str,ca_str;
        int c,ca;

        while(getline(file,n) && getline(file,b) && getline(file,c_str)){
            name.push_back(n);
            bustype.push_back(b);
            capacity.push_back(stoi(c_str));
        }

        


        for(int i = 0; i < name.size(); i++){
            cout << "Vehicle: "  << name[i]     << endl;
            cout << "Type: "     << bustype[i]  << endl;
            cout << "Capacity: " << capacity[i] << endl;
            cout << "-------------------" << endl;
        }

        cout<<"Write the name of a transport you want to remove: ";
        cin>>remove1;

        while(getline(file,na)){
            getline(file,ty);
            getline(file,ca_str);

            if(remove1 != na){
                tempfile<<na<<endl;
                tempfile<<ty<<endl;
                tempfile<<ca<<endl;
            }
        }

        

        file.close();
        tempfile.close();
    }
};