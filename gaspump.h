#ifndef GASPUMP_H
#define GASPUMP_H
#include <string>
class GasPump
{
    private:
            std::string fuelType;
            double fuelAmount;
            double fuelCapacity;
            double pricePerGal;
            double totalDispensed;
            double totalRevenue;
            bool isEmpty; 
            void replenish();
    public:
            GasPump(std::string, double, double);
            inline std::string getFuelType()
            {
                return fuelType;
            }
            inline double getPricePerGal()
            {
                return pricePerGal;
            }
            inline double getFuelAmount()
            {
                return fuelAmount;
            }
            inline double getTotalDispensed()
            {
                return totalDispensed;
            }
            inline double getTotalRevenue()
            {
                return totalRevenue;
            }
            void dispenseFuel(double *, double);
             
};





#endif
