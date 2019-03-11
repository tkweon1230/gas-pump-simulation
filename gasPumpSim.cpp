//Tae Kweon
//This program simulates fuel demand for a number of vehicles.
//It works with a class representing a gasoline pump. After execution,
//the program displays in order: the vehicle #, price per gallon, desired
//purchase amount, actual purchase amount, gallons dispensed, and the gallons remaining 
//in the fuel pump. The pump maintains a running total of the amount of fuel
//dispensed and revenues collected for all fuel types, and they are displayed
//at the end.

#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "gaspump.h"
using namespace std;
int main()
{
    ifstream myin;          

    int randoNum;
    int numOfVehicles;
    double purchaseAmount;
    double fuelPumpNum;         //stores random number between 0 and 1 to select
                                //which fuel type to use

    string gasType;
    double tankCapacity;
    double pricePerGal;

    GasPump *gasArray[3];           //Array pointers to three GasPump objects
    double n[3];                    //the chance percentage of selecting fuel type to use
    double outcomeArray[2];        //stores actual fuel purchase amount and actual fuel dispensed

    myin.open("gas.txt");
    myin >> randoNum;
    myin >> numOfVehicles;
    for(int i = 0; i < 3; i++)
    {
        myin >> gasType;
        myin >> tankCapacity;
        myin >> pricePerGal;
        myin >> n[i];
        gasArray[i] = new GasPump(gasType, tankCapacity, pricePerGal);
    }
    srand(randoNum);    //drawing a random number from 0 and 1 and comparing
                        //it against the "stacked" percentages read from the file                        //to select the pump pointer array index
   
    cout << fixed << setprecision(2);
    for(int i = 0; i < numOfVehicles; i++)  //iterate as much as the number of vehicles
    {
        fuelPumpNum = ((double) rand() +1)/RAND_MAX;    //generates number to select which fuel type to use
        purchaseAmount = ((rand() % 6) * 5) + 30;   //generates how much the customer is going to pay
        if(fuelPumpNum >= 0 && fuelPumpNum < n[2])  //if fuelPumpNum is between 0 and n[2]
        {
            gasArray[2]->dispenseFuel(outcomeArray, purchaseAmount);    //use premium+
            cout << i+1 << " " << gasArray[2]->getFuelType() << " " << gasArray[2]->getPricePerGal();
            cout << " " << purchaseAmount << " " << outcomeArray[0]  << " " << outcomeArray[1];
            cout << " " << gasArray[2]->getFuelAmount() << endl;
        }
        else if (fuelPumpNum >= n[2] && fuelPumpNum < n[2] + n[1]) //if fuelpumpnum is between n[2] and n[2]+n[1]
        {
            gasArray[1]->dispenseFuel(outcomeArray, purchaseAmount); //use leaded
            
            cout << i+1 << " " << gasArray[1]->getFuelType() << " " << gasArray[1]->getPricePerGal();
            cout << " " << purchaseAmount << " " << outcomeArray[0] << " " <<  outcomeArray[1];
            cout << " " <<  gasArray[1]->getFuelAmount() << endl;
        }
        else if (fuelPumpNum >= n[2] + n[1] && fuelPumpNum < 10) //if fuelpumpnum is between n[2]+n[1] and 10 
        {
            gasArray[0]->dispenseFuel(outcomeArray, purchaseAmount); //use unleaded
        
             cout << i+1 << " " << gasArray[0]->getFuelType() << " " << gasArray[0]->getPricePerGal();
             cout << " " << purchaseAmount << " " << outcomeArray[0] << " " << outcomeArray[1];
             cout << " " <<  gasArray[0]->getFuelAmount() << endl;
        }


    }

    cout << gasArray[0]->getFuelType() << " " << gasArray[0]->getTotalDispensed();
    cout << " " << gasArray[0]->getTotalRevenue() << endl;

    cout << gasArray[1]->getFuelType() << " " << gasArray[1]->getTotalDispensed();
    cout << " " << gasArray[1]->getTotalRevenue() << endl;

    cout << gasArray[2]->getFuelType() << " " << gasArray[2]->getTotalDispensed();
    cout << " " << gasArray[2]->getTotalRevenue() << endl;
    
    for(int i = 0; i < 3; i++)
    {
        delete gasArray[i];
    }
    myin.close();




    return 0;
}
