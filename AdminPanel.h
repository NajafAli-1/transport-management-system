// #include<iostream>
// #include "AddVehicle.h"
// #include "RemoveTransport.h"
// #include "ViewApplications.h"

// using namespace std;



// class AdminPanel{
// private:
//     int selection;
// public:
//     void Display() {
//         while(true){

//         cout<<"=============Admin Menu============"<<endl;
//         cout<<"|        1. Add vehicle           |"<<endl;
//         cout<<"|        2. Remove vehicle        |"<<endl;
//         cout<<"|        3. Add route             |"<<endl;
//         cout<<"|        4. View Applications     |"<<endl;
//         cout<<"|        5. Generate Report       |"<<endl;
//         cout<<"|        6. Save Data             |"<<endl;
//         cout<<"|        7. Logout                |"<<endl;
//         cout<<"|_________________________________|"<<endl;
//         cin>>selection;

//         if(selection==1){
//             AddVehicle V1;
//             V1.Add();
//         }
//         else if(selection==2){
//             RemoveTransport rt;
//             rt.remove();
//         }
//         else if(selection==3){
//             ViewApplication VA;
//             VA.view();
//         }
//         else if(selection==4){
            
//         }
//         else if(selection==5){
            
//         }
//         else if(selection==6){
            
//         }
//         else if(selection==7){
            
//         }
//       }
//     }
// };

#pragma once
#include<iostream>
#include<string>

#include "AddVehicle.h"
#include "RemoveTransport.h"
#include "ViewApplications.h"


using namespace std;

class AdminPanel{
private:
    int selection;

public:
    AdminPanel() : selection(0) {}

    void Display() {
        while(true){
            cout<<"\n=============Admin Menu============="<<endl;
            cout<<"|        1. Add Vehicle             |"<<endl;
            cout<<"|        2. Remove Vehicle          |"<<endl;
            cout<<"|        3. Add Route               |"<<endl;
            cout<<"|        4. View Applications       |"<<endl;
            cout<<"|        5. Generate Report         |"<<endl;
            cout<<"|        6. Save Data               |"<<endl;
            cout<<"|        7. Logout                  |"<<endl;
            cout<<"|__________________________________|"<<endl;
            cout<<"Choice: ";
            cin>>selection;
            cin.ignore();

            if(selection==1){
                AddVehicle V1;
                V1.Add();
            }
            else if(selection==2){
                RemoveTransport rt;
                rt.remove();
            }
            else if(selection==3){
                
                addRoute();
            }
            else if(selection==4){
                
                ViewApplication VA;
                VA.view();
            }
            else if(selection==5){
                
            }
            else if(selection==6){
                
                cout<<"========================================="<<endl;
                cout<<"  Data is saved automatically after each"<<endl;
                cout<<"  action. Current saved files:"<<endl;
                cout<<"  - Student.txt      (registered students)"<<endl;
                cout<<"  - Admin.txt        (registered admins)"<<endl;
                cout<<"  - AddVehicle.txt   (vehicles)"<<endl;
                cout<<"  - ViewRoute.txt    (routes)"<<endl;
                cout<<"  - ApplyTransport.txt (applications)"<<endl;
                cout<<"  - Bill.txt         (bills)"<<endl;
                cout<<"========================================="<<endl;
            }
            else if(selection==7){
                
                cout<<"Admin logged out successfully!"<<endl;
                break;
            }
            else{
                cout<<"Invalid option. Please try again."<<endl;
            }
        }
    }

private:
    // MISSING LOGIC: Add Route writes a new route to Routes.txt
    // in your direct file-writing style
    void addRoute(){
        ofstream file("Routes.txt", ios::app);

        if(!file.is_open()){
            cout<<"ERROR: Could not open Routes.txt"<<endl;
            return;
        }

        string routeName, startPoint, endPoint;
        int distance, stopCount;
        string stop;

        cout<<"========================================="<<endl;
        cout<<"             ADD NEW ROUTE               "<<endl;
        cout<<"========================================="<<endl;

        cout<<"Route Name  : "; getline(cin, routeName);
        cout<<"Start Point : "; getline(cin, startPoint);
        cout<<"End Point   : "; getline(cin, endPoint);
        cout<<"Distance(Km): "; cin>>distance; cin.ignore();
        cout<<"No. of Stops: "; cin>>stopCount; cin.ignore();

        file<<"========================"<<endl;
        file<<"| "<<routeName<<"              |"<<endl;

        for(int i=0; i<stopCount; i++){
            cout<<"Stop "<<i+1<<": ";
            getline(cin, stop);
            file<<"|--> "<<stop<<endl;
        }

        file<<"|Distance ---> "<<distance<<" Km   |"<<endl;
        file<<"========================"<<endl;
        file.close();

        cout<<"Route '"<<routeName<<"' added and saved to Routes.txt!"<<endl;
    }
};