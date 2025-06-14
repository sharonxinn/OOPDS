// This program demonstrates the Car, Truck, and SUV
// classes that are derived from the Automobile class.
#include <iostream>
#include <iomanip>
#include "Car.h"
#include "Truck.h"
#include "SUV.h"
using namespace std;

int main()
{
    // Create a Car object for a used 2007 BMW with
    // 50,000 miles, priced at $15,000, with 4 doors.
    Car car("BMW", 2007, 50000, 15000.0, 4);
    
    // Create a Truck object for a used 2006 Toyota
    // pickup with 40,000 miles, priced at $12,000, 
    // with 4-wheel drive.
    Truck truck("Toyota", 2006, 40000, 12000.0, "4WD");    
    
    // Create an SUV object for a used 2005 Volvo
    // with 30,000 miles, priced at $18,000, with
    // 5 passenger capacity.
    SUV suv("Volvo", 2005, 30000, 18000.00, 5);
    
    // Display the automobiles we have in inventory.
    cout << fixed << showpoint << setprecision(2);
    cout << "We have the following car in inventory:\n"
         << car.getModel() << " " << car.getMake()  //2007 BMV
         << " with " << car.getDoors() << " doors and " //4
         << car.getMileage() << " miles.\nPrice: $" //50000
         << car.getPrice() << endl << endl;  //15000.00

    cout << "We have the following truck in inventory:\n"
         << truck.getModel() << " " << truck.getMake() //2006 Toyota
         << " with " << truck.getDriveType()  //4WD
         << " drive type and " << truck.getMileage()  //40000
         << " miles.\nPrice: $" << truck.getPrice()  //12000.00
         << endl << endl;

    cout << "We have the following SUV in inventory:\n"
         << suv.getModel() << " " << suv.getMake()  //2005 vOLVO
         << " with " << suv.getMileage() << " miles and " //30000
         << suv.getPassengers() << " passenger capacity.\n" //5
         << "Price: $" << suv.getPrice() << endl;  //18000.00

    return 0;
}