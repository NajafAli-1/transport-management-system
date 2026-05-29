#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class ViewBill{
private:
    string studentName;
    int    studentID;

public:
    // Constructor receives logged-in student info from StudentPanel
    ViewBill(string name, int id) : studentName(name), studentID(id) {}
    ViewBill(){
        cout<<"\n========================================="<<endl;
        cout<<"             YOUR BILL DETAILS           "<<endl;
        cout<<"========================================="<<endl;

    }

    void View(){
        ifstream file("Bill.txt");

        
        if(!file.is_open()){
            cout<<"No bills found. Your transport application may still be pending."<<endl;
            return;
        }

        bool found = false;
        string line;
        string sName, sID, sRoute, sBill, sStatus;

        while(getline(file, line)){
            // Each bill record:
            // =========================
            // Student Name : John
            // Student ID   : 123
            // Route        : 1
            // Monthly Bill : Rs. 3000/month
            // Status       : Approved
            // =========================
            if(line.find("=====") != string::npos){
                getline(file, sName);
                getline(file, sID);
                getline(file, sRoute);
                getline(file, sBill);
                getline(file, sStatus);
                getline(file, line);   // closing ===

                // Extract value after ": "
                auto extract = [](const string& s) -> string {
                    size_t pos = s.find(": ");
                    if(pos == string::npos) return "";
                    return s.substr(pos + 2);
                };

                string billName = extract(sName);
                string billID   = extract(sID);

                // Match by name AND ID
                if(billName == studentName && stoi(billID) == studentID){
                    found = true;
                    cout<<"\n  Student Name : "<<billName<<endl;
                    cout<<"  Student ID   : "<<billID<<endl;
                    cout<<"  Route        : "<<extract(sRoute)<<endl;
                    cout<<"  Monthly Bill : "<<extract(sBill)<<endl;
                    cout<<"  Status       : "<<extract(sStatus)<<endl;
                    cout<<"\n========================================="<<endl;
                }
            }
        }
        file.close();

        if(!found){
            cout<<"No bill found for your account."<<endl;
            cout<<"Your transport application may still be Pending or has been Rejected."<<endl;
        }
    }
};