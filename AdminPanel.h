#include<iostream>
#include "AddVehicle.h"
#include "RemoveTransport.h"

using namespace std;



class AdminPanel{
private:
    int selection;
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
        cin>>selection;

        if(selection==1){
            AddVehicle V1;
            V1.Add();
        }
        else if(selection==2){
            RemoveTransport rt;
            rt.remove();
        }
        else if(selection==3){
            
        }
        else if(selection==4){
            
        }
        else if(selection==5){
            
        }
        else if(selection==6){
            
        }
        else if(selection==7){
            
        }
    }
};