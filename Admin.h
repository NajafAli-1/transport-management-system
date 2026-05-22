#include<iostream>
#include<string>

#include "User.h"

using namespace std;

class Admin: public User{
private:
    string email;

public:
    void INFO(){
        User::Info();
        cout<<"Enter email: ";
        cin>>email;
    }
};