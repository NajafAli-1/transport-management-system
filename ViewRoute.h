#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class ViewRoute{

public:
    void Display() {
        ofstream file("ViewRoute.txt");                   //Creating file       

        cout<<"========================"<<endl;           //Showing data 
        cout<<"| Route 1              |"<<endl;
        cout<<"|--> Harbsnspura       |"<<endl;
        cout<<"|--> Madina Town       |"<<endl;
        cout<<"|--> Taj Bagh          |"<<endl;
        cout<<"|--> Fateh Garh        |"<<endl;
        cout<<"|--> New Pull          |"<<endl;
        cout<<"|--> Lal Pul           |"<<endl;
        cout<<"|--> Mughal Pura       |"<<endl;
        cout<<"|--> Dharam Pura       |"<<endl;
        cout<<"|--> New Campus        |"<<endl;
        cout<<"|Distance ---> 30 Km   |"<<endl;
        cout<<"========================"<<endl;

        cout<<"========================"<<endl;
        cout<<"| Route 2              |"<<endl;
        cout<<"|--> Nishtar Colony    |"<<endl;
        cout<<"|--> Chungi Amarsudu   |"<<endl;
        cout<<"|--> General Hospital  |"<<endl;
        cout<<"|--> Defence morr      |"<<endl;
        cout<<"|--> Fibous Market     |"<<endl;
        cout<<"|--> Kalma Chowk       |"<<endl;
        cout<<"|--> Ichra             |"<<endl;
        cout<<"|--> Qartba Chowk      |"<<endl;
        cout<<"|--> New Campus        |"<<endl;
        cout<<"|Distance ---> 37 Km   |"<<endl;
        cout<<"========================"<<endl;

        cout<<"========================"<<endl;
        cout<<"| Route 3              |"<<endl;
        cout<<"|--> Muslim Town       |"<<endl;
        cout<<"|--> Naqsha Stop       |"<<endl;
        cout<<"|--> Baikhe wala       |"<<endl;
        cout<<"|--> Raza Block        |"<<endl;
        cout<<"|--> Wahdat Road       |"<<endl;
        cout<<"|--> Sabza Zar         |"<<endl;
        cout<<"|--> Babu Sabu         |"<<endl;
        cout<<"|--> Shadhra Station   |"<<endl;
        cout<<"|--> New Campus        |"<<endl;
        cout<<"|Distance ---> 37 Km   |"<<endl;
        cout<<"========================"<<endl;

        file<<"========================"<<endl;                 //Storing data into the file
        file<<"| Route 1              |"<<endl;
        file<<"|--> Harbsnspura       |"<<endl;
        file<<"|--> Madina Town       |"<<endl;
        file<<"|--> Taj Bagh          |"<<endl;
        file<<"|--> Fateh Garh        |"<<endl;
        file<<"|--> New Pull          |"<<endl;
        file<<"|--> Lal Pul           |"<<endl;
        file<<"|--> Mughal Pura       |"<<endl;
        file<<"|--> Dharam Pura       |"<<endl;
        file<<"|--> New Campus        |"<<endl;
        file<<"|Distance ---> 30 Km   |"<<endl;
        file<<"========================"<<endl;

        file<<"========================"<<endl;
        file<<"| Route 2              |"<<endl;
        file<<"|--> Nishtar Colony    |"<<endl;
        file<<"|--> Chungi Amarsudu   |"<<endl;
        file<<"|--> General Hospital  |"<<endl;
        file<<"|--> Defence morr      |"<<endl;
        file<<"|--> Fibous Market     |"<<endl;
        file<<"|--> Kalma Chowk       |"<<endl;
        file<<"|--> Ichra             |"<<endl;
        file<<"|--> Qartba Chowk      |"<<endl;
        file<<"|--> New Campus        |"<<endl;
        file<<"|Distance ---> 37 Km   |"<<endl;
        file<<"========================"<<endl;

        file<<"========================"<<endl;
        file<<"| Route 3              |"<<endl;
        file<<"|--> Muslim Town       |"<<endl;
        file<<"|--> Naqsha Stop       |"<<endl;
        file<<"|--> Baikhe wala       |"<<endl;
        file<<"|--> Raza Block        |"<<endl;
        file<<"|--> Wahdat Road       |"<<endl;
        file<<"|--> Sabza Zar         |"<<endl;
        file<<"|--> Babu Sabu         |"<<endl;
        file<<"|--> Shadhra Station   |"<<endl;
        file<<"|--> New Campus        |"<<endl;
        file<<"|Distance ---> 37 Km   |"<<endl;
        file<<"========================"<<endl;

        file.close();

    }
};