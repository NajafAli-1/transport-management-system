#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

// ---- Data structure to hold one application ----
struct Application {
    string studentName;
    string studentID;
    string route;
    string status;        // "Pending" | "Approved" | "Rejected"
};

class ViewApplication{
private:
    vector<Application> apps;

    // Read all applications from ApplyTransport.txt into apps vector
    void loadApplications(){
        apps.clear();
        ifstream file("ApplyTransport.txt");
        if(!file.is_open()) return;

        string line;
        while(getline(file, line)){
            // Each record:
            // =========================
            // Student Name : John
            // Student ID   : 123
            // Applied Route: 1
            // Status       : Pending
            // =========================
            if(line.find("=====") != string::npos){
                Application a;
                string sName, sID, sRoute, sStatus;

                getline(file, sName);           // "Student Name : John"
                getline(file, sID);             // "Student ID   : 123"
                getline(file, sRoute);          // "Applied Route: 1"
                getline(file, sStatus);         // "Status       : Pending"
                getline(file, line);            // closing "===..."

                // Extract values after ": "
                auto extract = [](const string& s) -> string {
                    size_t pos = s.find(": ");
                    if(pos == string::npos) return "";
                    return s.substr(pos + 2);
                };

                a.studentName = extract(sName);
                a.studentID   = extract(sID);
                a.route       = extract(sRoute);
                a.status      = extract(sStatus);
                apps.push_back(a);
            }
        }
        file.close();
    }

    // Save all applications back to ApplyTransport.txt
    void saveApplications(){
        ofstream file("ApplyTransport.txt");    // overwrite
        for(auto& a : apps){
            file<<"========================="<<endl;
            file<<"Student Name : "<<a.studentName<<endl;
            file<<"Student ID   : "<<a.studentID<<endl;
            file<<"Applied Route: "<<a.route<<endl;
            file<<"Status       : "<<a.status<<endl;
            file<<"========================="<<endl;
        }
        file.close();
    }

    // Generate a bill entry in Bill.txt for an approved student
    void generateBill(const Application& a){
        ofstream bill("Bill.txt", ios::app);
        if(!bill.is_open()){
            cout<<"WARNING: Could not open Bill.txt"<<endl;
            return;
        }

        // Simple fare table based on route distance
        int fare = 0;
        if(a.route == "1") fare = 3000;       // 30 km
        else if(a.route == "2") fare = 3700;  // 37 km
        else if(a.route == "3") fare = 3700;  // 37 km
        else fare = 3000;                     // default

        bill<<"========================="<<endl;
        bill<<"Student Name : "<<a.studentName<<endl;
        bill<<"Student ID   : "<<a.studentID<<endl;
        bill<<"Route        : "<<a.route<<endl;
        bill<<"Monthly Bill : Rs. "<<fare<<"/month"<<endl;
        bill<<"Status       : Approved"<<endl;
        bill<<"========================="<<endl;
        bill.close();

        cout<<"Bill of Rs."<<fare<<"/month generated for "<<a.studentName<<endl;
    }

public:
    void view(){
        loadApplications();

        cout<<"\n========================================="<<endl;
        cout<<"         TRANSPORT APPLICATIONS          "<<endl;
        cout<<"========================================="<<endl;

        if(apps.empty()){
            cout<<"No applications found."<<endl;
            return;
        }

        // Display all applications with index
        for(int i = 0; i < (int)apps.size(); i++){
            cout<<"\n["<<i+1<<"] Student Name : "<<apps[i].studentName<<endl;
            cout<<"    Student ID   : "<<apps[i].studentID<<endl;
            cout<<"    Applied Route: "<<apps[i].route<<endl;
            cout<<"    Status       : "<<apps[i].status<<endl;
        }

        // Admin action menu
        cout<<"\n-----------------------------------------"<<endl;
        cout<<"Options:"<<endl;
        cout<<"  Enter application number to Approve/Reject"<<endl;
        cout<<"  Enter 0 to go back"<<endl;
        cout<<"Choice: ";
        int choice;
        cin>>choice;
        cin.ignore();

        if(choice == 0) return;

        if(choice < 1 || choice > (int)apps.size()){
            cout<<"Invalid selection."<<endl;
            return;
        }

        Application& selected = apps[choice - 1];

        if(selected.status != "Pending"){
            cout<<"This application is already '"<<selected.status<<"'. No changes made."<<endl;
            return;
        }

        cout<<"Application of '"<<selected.studentName<<"' for Route "<<selected.route<<":"<<endl;
        cout<<"  1. Approve"<<endl;
        cout<<"  2. Reject"<<endl;
        cout<<"  0. Cancel"<<endl;
        cout<<"Choice: ";
        int action;
        cin>>action;
        cin.ignore();

        if(action == 1){
            selected.status = "Approved";
            saveApplications();
            generateBill(selected);
            cout<<"Application APPROVED for "<<selected.studentName<<"!"<<endl;
        }
        else if(action == 2){
            selected.status = "Rejected";
            saveApplications();
            cout<<"Application REJECTED for "<<selected.studentName<<"."<<endl;
        }
        else{
            cout<<"No changes made."<<endl;
        }
    }
};