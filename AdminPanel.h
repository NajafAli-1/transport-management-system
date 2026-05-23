#include<iostream>

using namespace std;

class AdminPanel{
private:

public:
    void Display() {
        cout<<"=============Admin Menu============"<<endl;
        cout<<"|        1. Add vehicle           |"<<endl;
        cout<<"|        2. Remove vehicle        |"<<endl;
        cout<<"|        3. Add route             |"<<endl;
        cout<<"|        4. View Applications     |"<<endl;
        cout<<"|        5. Generate Report       |"<<endl;
        cout<<"|        6. Save Data             |"<<endl;
        cout<<"|        7. Logout                |"<<endl;
        cout<<"|_________________________________|"<<endl;
    }
};