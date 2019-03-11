//Tae Kweon
//GasPump implementation file
#include <iostream>
#include <string>
#include "gaspump.h"
using namespace std;

//constructor 
GasPump::GasPump(string type, double capacity, double price)
{
    fuelType = type;
    fuelCapacity = capacity;
    pricePerGal = price;
    replenish();

}
//this function replenishes the fuel pump
void GasPump::replenish()
{
    fuelAmount = fuelCapacity;

}
//this function controls the fueling of a single vehicle.
//it accepts a pointer to a double array, and a double of the 
//desired purchase amount of fuel. It uses the pointer to set
//values in the array: actual purchase amount in element[0] and
//actual quantity of fuel dispensed in element[1].
//The vehicles gets the full amount of fuel requested if it is available, 
//but gets the remainining if there is not enough in the fuel tank.
//The vehicle receives no fuel if the tank is completely empty.
void GasPump::dispenseFuel(double *ptrArray, double custPurAmount)
{

    double custGalAmount = custPurAmount/pricePerGal;  //converted to gallons
    if(fuelAmount >= custGalAmount) //if enough fuel in dispenser
    {
        *(ptrArray + 0) = custPurAmount;        //element [0] = the actual purchase amount in dollars
        *(ptrArray + 1) = custGalAmount;      //element[1] = the actual quantity of fuel dispensed in gallons
        totalDispensed += custGalAmount;
        totalRevenue += custPurAmount;
        fuelAmount -= custGalAmount;
        isEmpty = false;                
    }
    else if(fuelAmount < custGalAmount && fuelAmount != 0) //if not enough fuel in dispenser
    {
        *(ptrArray + 0) = fuelAmount * pricePerGal;   //converted to $ price
        *(ptrArray + 1) = fuelAmount;
        totalDispensed += fuelAmount;
        totalRevenue += (fuelAmount * pricePerGal);
        fuelAmount = 0;
        isEmpty = true;
    }
    else if(isEmpty)    //if no fuel in dispenser
    {
        *(ptrArray + 0) = 0;
        *(ptrArray + 1) = 0;
        replenish();
        isEmpty = false;
    }
}
