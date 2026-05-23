#include<iostream>
#include<fstream>

#include "User.h"                     //Header file to extra data from User file

using namespace std;

class Student : public User{        //Using Inheritence concept
private:
    string Roll_Number;
    string department;
    string Role;

public:
    void INfo() {
        ofstream file("Student.txt",ios::app);

        User::Info();                     //Exract user INFO 

        cout<<"Enter Roll number: ";
        getline(cin,Roll_Number);
        
        cout<<"Enter Department: ";
        getline(cin,department);

        cout<<"Enter your role (Student/Admin): ";
        getline(cin,Role);

        file<<name<<endl;
        file<<passward<<endl;
        file<<ID<<endl;
        file<<Roll_Number<<endl;
        file<<department<<endl;
        file<<Role<<endl;

        file.close();
    }
};


