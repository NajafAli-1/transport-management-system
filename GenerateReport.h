#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

class GenerateReport{
private:

    // ── Helper: print a section header ──
    void header(string title){
        cout<<"\n=========================================="<<endl;
        cout<<"   "<<title<<endl;
        cout<<"=========================================="<<endl;
    }

    // ── Helper: check if file exists and is non-empty ──
    bool fileReady(ifstream &f, string filename){
        f.open(filename);
        if(!f.is_open() || f.peek()==EOF){
            cout<<"  [No data found]"<<endl;
            f.close();
            return false;
        }
        return true;
    }

public:

    void generate(){

        cout<<"\n=========================================="<<endl;
        cout<<"   UNIVERSITY TRANSPORT MANAGEMENT SYSTEM "<<endl;
        cout<<"         FULL SYSTEM REPORT               "<<endl;
        cout<<"=========================================="<<endl;

        // ─────────────────────────────────────────
        // 1. REGISTERED STUDENTS  (Student.txt)
        //    Format per record: name, password, ID,
        //                       rollNumber, department, role
        // ─────────────────────────────────────────
        header("1. REGISTERED STUDENTS");
        {
            ifstream file;
            if(fileReady(file,"Student.txt")){
                string name,pass,idStr,roll,dept,role;
                int count=1;
                while(getline(file,name) && getline(file,pass) &&
                      getline(file,idStr) && getline(file,roll) &&
                      getline(file,dept)  && getline(file,role)){
                    cout<<count++<<". Name       : "<<name<<endl;
                    cout<<"   ID         : "<<idStr<<endl;
                    cout<<"   Roll No    : "<<roll<<endl;
                    cout<<"   Department : "<<dept<<endl;
                    cout<<"   Role       : "<<role<<endl;
                    cout<<"------------------------------------------"<<endl;
                }
                file.close();
            }
        }

        // ─────────────────────────────────────────
        // 2. REGISTERED ADMINS  (Admin.txt)
        //    Format per record: name, password, ID,
        //                       email, role
        // ─────────────────────────────────────────
        header("2. REGISTERED ADMINS");
        {
            ifstream file;
            if(fileReady(file,"Admin.txt")){
                string name,pass,idStr,email,role;
                int count=1;
                while(getline(file,name) && getline(file,pass) &&
                      getline(file,idStr)&& getline(file,email) &&
                      getline(file,role)){
                    cout<<count++<<". Name  : "<<name<<endl;
                    cout<<"   ID    : "<<idStr<<endl;
                    cout<<"   Email : "<<email<<endl;
                    cout<<"   Role  : "<<role<<endl;
                    cout<<"------------------------------------------"<<endl;
                }
                file.close();
            }
        }

        // ─────────────────────────────────────────
        // 3. AVAILABLE VEHICLES  (AddVehicle.txt)
        //    Format per record: name, bustype, capacity
        // ─────────────────────────────────────────
        header("3. AVAILABLE VEHICLES");
        {
            ifstream file;
            if(fileReady(file,"AddVehicle.txt")){
                string n,b,c;
                int count=1;
                while(getline(file,n) && getline(file,b) && getline(file,c)){
                    cout<<count++<<". Vehicle  : "<<n<<endl;
                    cout<<"   Bus Type : "<<b<<endl;
                    cout<<"   Capacity : "<<c<<endl;
                    cout<<"------------------------------------------"<<endl;
                }
                file.close();
            }
        }

        // ─────────────────────────────────────────
        // 4. AVAILABLE ROUTES  (ViewRoute.txt)
        // ─────────────────────────────────────────
        header("4. AVAILABLE ROUTES");
        {
            ifstream file;
            if(fileReady(file,"ViewRoute.txt")){
                string line;
                while(getline(file,line))
                    cout<<"  "<<line<<endl;
                file.close();
            }
        }

        // ─────────────────────────────────────────
        // 5. TRANSPORT APPLICATIONS  (ApplyTransport.txt)
        // ─────────────────────────────────────────
        header("5. TRANSPORT APPLICATIONS");
        {
            ifstream file;
            if(fileReady(file,"ApplyTransport.txt")){
                string line;
                int pending=0, approved=0, rejected=0;
                vector<string> allLines;

                while(getline(file,line)){
                    allLines.push_back(line);
                    if(line.find("Pending")  != string::npos) pending++;
                    if(line.find("Approved") != string::npos) approved++;
                    if(line.find("Rejected") != string::npos) rejected++;
                }
                file.close();

                for(auto &l : allLines) cout<<l<<endl;

                cout<<"\n  -- Summary --"<<endl;
                cout<<"  Pending  : "<<pending<<endl;
                cout<<"  Approved : "<<approved<<endl;
                cout<<"  Rejected : "<<rejected<<endl;
            }
        }

        // ─────────────────────────────────────────
        // 6. BILLS  (BillGenerate.txt)
        // ─────────────────────────────────────────
        header("6. GENERATED BILLS");
        {
            ifstream file;
            if(fileReady(file,"BillGenerate.txt")){
                string line;
                int unpaid=0, paid=0;
                vector<string> allLines;

                while(getline(file,line)){
                    allLines.push_back(line);
                    if(line.find("Unpaid") != string::npos) unpaid++;
                    if(line.find("Paid")   != string::npos &&
                       line.find("Unpaid") == string::npos) paid++;
                }
                file.close();

                for(auto &l : allLines) cout<<l<<endl;

                cout<<"\n  -- Summary --"<<endl;
                cout<<"  Paid   : "<<paid<<endl;
                cout<<"  Unpaid : "<<unpaid<<endl;
            }
        }

        // ─────────────────────────────────────────
        // Save report to ReportOutput.txt
        // ─────────────────────────────────────────
        cout<<"\n=========================================="<<endl;
        cout<<"  Saving report to ReportOutput.txt ...  "<<endl;
        cout<<"=========================================="<<endl;
        saveToFile();
    }

private:
    void saveToFile(){
        ofstream out("ReportOutput.txt");

        out<<"=========================================="<<endl;
        out<<"  UNIVERSITY TRANSPORT MANAGEMENT SYSTEM "<<endl;
        out<<"           FULL SYSTEM REPORT            "<<endl;
        out<<"=========================================="<<endl;

        // Students
        out<<"\n-- REGISTERED STUDENTS --"<<endl;
        ifstream s("Student.txt");
        if(s.is_open()){
            string name,pass,idStr,roll,dept,role;
            int c=1;
            while(getline(s,name)&&getline(s,pass)&&getline(s,idStr)&&
                  getline(s,roll)&&getline(s,dept)&&getline(s,role)){
                out<<c++<<". "<<name<<" | ID: "<<idStr<<" | Roll: "<<roll
                   <<" | Dept: "<<dept<<endl;
            }
            s.close();
        }

        // Admins
        out<<"\n-- REGISTERED ADMINS --"<<endl;
        ifstream a("Admin.txt");
        if(a.is_open()){
            string name,pass,idStr,email,role;
            int c=1;
            while(getline(a,name)&&getline(a,pass)&&getline(a,idStr)&&
                  getline(a,email)&&getline(a,role)){
                out<<c++<<". "<<name<<" | ID: "<<idStr<<" | Email: "<<email<<endl;
            }
            a.close();
        }

        // Vehicles
        out<<"\n-- AVAILABLE VEHICLES --"<<endl;
        ifstream v("AddVehicle.txt");
        if(v.is_open()){
            string n,b,cap;
            int c=1;
            while(getline(v,n)&&getline(v,b)&&getline(v,cap)){
                out<<c++<<". "<<n<<" | Type: "<<b<<" | Capacity: "<<cap<<endl;
            }
            v.close();
        }

        // Routes
        out<<"\n-- AVAILABLE ROUTES --"<<endl;
        ifstream r("ViewRoute.txt");
        if(r.is_open()){
            string line;
            while(getline(r,line)) out<<line<<endl;
            r.close();
        }

        // Applications
        out<<"\n-- TRANSPORT APPLICATIONS --"<<endl;
        ifstream ap("ApplyTransport.txt");
        if(ap.is_open()){
            string line;
            while(getline(ap,line)) out<<line<<endl;
            ap.close();
        }

        // Bills
        out<<"\n-- GENERATED BILLS --"<<endl;
        ifstream bl("BillGenerate.txt");
        if(bl.is_open()){
            string line;
            while(getline(bl,line)) out<<line<<endl;
            bl.close();
        }

        out<<"\n=========================================="<<endl;
        out.close();
        cout<<"Report saved successfully!"<<endl;
    }
};