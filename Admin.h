#include<iostream>
#include<string>
#include<fstream>

#include "User.h"

using namespace std;

class Admin: public User{
private:
    string email;
    string Role;

public:
    void INFO(){
        ofstream file1("Admin.txt",ios::app);       //Creating file 

        User::Info();

        cout<<"Enter email: ";
        getline(cin,email);
        cout<<"Enter your Role (Student/Admin): ";
        getline(cin,Role);

        file1<<name<<endl;
        file1<<passward<<endl;
        file1<<ID<<endl;
        file1<<email<<endl;
        file1<<Role<<endl;

        file1.close();
    }
};