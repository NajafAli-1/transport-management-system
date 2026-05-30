#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

class CancelRegistration{
public:
    void Cancel(string studentName, int studentID){
        ifstream file("ApplyTransport.txt");
        if(!file.is_open() || file.peek() == EOF){
            cout<<"You have no active transport registration."<<endl;
            return;
        }

        vector<string> lines;
        string line;
        while(getline(file, line)) lines.push_back(line);
        file.close();

        bool found = false;
        // We'll rebuild the file skipping the block that contains our studentID
        ofstream out("ApplyTransport.txt");

        int i = 0;
        while(i < (int)lines.size()){
            // Detect block start
            if(lines[i].find("=========================") != string::npos){
                // Peek ahead for Student ID match
                bool isOurs = false;
                for(int j=i+1; j<i+6 && j<(int)lines.size(); j++){
                    if(lines[j].find("Student ID") != string::npos){
                        size_t pos = lines[j].find(":");
                        if(pos != string::npos){
                            string idStr = lines[j].substr(pos+1);
                            while(!idStr.empty() && idStr[0]==' ') idStr.erase(0,1);
                            try{
                                if(stoi(idStr) == studentID) isOurs = true;
                            } catch(...){}
                        }
                    }
                }
                if(isOurs){
                    // Skip entire block until closing "======"
                    i++; // skip opening "====="
                    while(i < (int)lines.size() && lines[i].find("=========================") == string::npos) i++;
                    i++; // skip closing "====="
                    found = true;
                    continue;
                }
            }
            out<<lines[i]<<endl;
            i++;
        }
        out.close();

        if(found)
            cout<<"Your transport registration has been cancelled successfully."<<endl;
        else
            cout<<"No registration found for your account."<<endl;
    }
};