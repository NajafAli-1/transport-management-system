#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include "StudentPanel.h"
#include "AdminPanel.h"

using namespace std;

class Login{
private:
    string inputname, storename;
    string inputpass, storepass;
    string filename, filepass;
    string skip;
    bool found  = false;
    bool found1 = false;

    // BUG FIX: was  int choose;  as a GLOBAL variable (outside the class).
    // Moved inside class as private member.
    int choose;

    // MISSING: store student info read from file so StudentPanel can use it
    int    loggedInStudentID;
    string loggedInRoll;

public:
    Login() : choose(0), loggedInStudentID(0) {
        cout<<"==============="<<endl;
        cout<<"|   LOGIN     |"<<endl;
        cout<<"==============="<<endl;
        cout<<"Welcome!! Please enter your Credentials"<<endl;
    }

    void detail(){
        // BUG FIX: need cin.ignore() here if called right after cin>>choice in main
        cout<<"Name    : ";
        getline(cin, inputname);
        cout<<"Password: ";
        getline(cin, inputpass);

        // ---- Check Student.txt ----
        // Student.txt format (6 lines per record): name, pass, ID, roll, dept, role
        ifstream file("Student.txt");
        if(file.is_open()){
            string s_name, s_pass, s_id_str, s_roll, s_dept, s_role;
            int    s_id;

            while(getline(file, s_name) && getline(file, s_pass)){
                // BUG FIX: your original only read name+pass (2 lines) then looped.
                // Student.txt has 6 lines per record so after reading 2, the next
                // iteration reads the ID line as a name -- misaligned after 1st record.
                // Fixed: read all 6 lines to stay aligned.
                file >> s_id;
                file.ignore();
                getline(file, s_roll);
                getline(file, s_dept);
                getline(file, s_role);

                if(s_name == inputname && s_pass == inputpass){
                    cout<<"Login Successful! Welcome, "<<s_name<<"!"<<endl;
                    found = true;
                    loggedInStudentID = s_id;
                    loggedInRoll      = s_roll;
                    break;
                }
            }
            file.close();
        }

        // ---- Check Admin.txt ----
        // Admin.txt format (5 lines per record): name, pass, ID, email, role
        if(!found){
            ifstream file1("Admin.txt");
            if(file1.is_open()){
                string a_name, a_pass, a_email, a_role;
                int a_id;

                while(getline(file1, a_name) && getline(file1, a_pass)){
                    // BUG FIX: same misalignment issue -- read remaining 3 lines
                    file1 >> a_id;
                    file1.ignore();
                    getline(file1, a_email);
                    getline(file1, a_role);

                    if(a_name == inputname && a_pass == inputpass){
                        cout<<"Login Successful! Welcome, "<<a_name<<"!"<<endl;
                        found1 = true;
                        break;
                    }
                }
                file1.close();
            }
        }

        if(!found && !found1){
            cout<<inputname<<" is not registered. Please register first."<<endl;
            return;
        }

        if(found){
            cout<<"________________________"<<endl;
            cout<<"| Click '1' to enter    |"<<endl;
            cout<<"|     Student Menu      |"<<endl;
            cout<<"|_______________________|"<<endl;
            cin>>choose;
            cin.ignore();

            if(choose==1){
                // CORRECTED: StudentPanel now needs (name, id) -- pass them
                StudentPanel SP(inputname, loggedInStudentID);
                SP.Display();
            }
        }
        else if(found1){
            cout<<"________________________"<<endl;
            cout<<"| Click '1' to enter    |"<<endl;
            cout<<"|     Admin Menu        |"<<endl;
            cout<<"|_______________________|"<<endl;
            cin>>choose;
            cin.ignore();

            if(choose==1){
                AdminPanel A;
                A.Display();
            }
        }
    }

    void store(){
        storename = inputname;
        storepass = inputpass;
        cout<<"Name: "<<storename<<endl;
    }
};