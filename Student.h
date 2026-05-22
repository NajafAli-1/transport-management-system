#include<iostream>
#include "User.h"

using namespace std;

class Student : public User{
private:
    string Roll_Number;
    string department;

public:
    void Info() {
        User::Info();
        cout<<"Enter Roll number: ";
        getline(cin,Roll_Number);
        
        cout<<"Enter Department: ";
        getline(cin,department);
    }
};


