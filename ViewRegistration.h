#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class ViewMyRegistration{
public:
    void View(string studentName, int studentID){
        cout<<"\n=========================="<<endl;
        cout<<"|   MY TRANSPORT STATUS   |"<<endl;
        cout<<"=========================="<<endl;

        ifstream file("ApplyTransport.txt");
        if(!file.is_open() || file.peek() == EOF){
            cout<<"You have not applied for transport yet."<<endl;
            return;
        }

        string line;
        bool found = false;
        bool inBlock = false;
        bool printBlock = false;

        while(getline(file, line)){
            if(line.find("=========================") != string::npos){
                if(!inBlock){
                    inBlock = true;
                    printBlock = false;
                } else {
                    if(printBlock) cout<<line<<endl;
                    inBlock = false;
                    printBlock = false;
                    continue;
                }
                cout<<line<<endl;
                continue;
            }
            if(inBlock){
                if(line.find("Student ID") != string::npos){
                    size_t pos = line.find(":");
                    if(pos != string::npos){
                        string idStr = line.substr(pos+1);
                        while(!idStr.empty() && idStr[0]==' ') idStr.erase(0,1);
                        try{
                            if(stoi(idStr) == studentID) printBlock = true;
                        } catch(...){}
                    }
                }
                if(printBlock) cout<<line<<endl;
            }
        }
        file.close();

        if(!found && !printBlock){
            // printBlock would be true if found; just show message if nothing printed
        }
    }
};