// This program demonstrates passing arguments to a base
// class constructor.
#include <iostream>
#include "Box.h"
using namespace std;

int main()
{
   double boxWidth;   // To hold the box's width
   double boxLength;  // To hold the box's length
   double boxHeight;  // To hold the box's height

   // Get the width, length, and height from the user.
   cout << "Enter the dimensions of a box:\n";
   cout << "Width: ";
   cin >> boxWidth;  //2
   cout << "Length: ";
   cin >> boxLength; //2
   cout << "Height: ";
   cin >> boxHeight; //2

   // Define a Box object.
   Box myBox(boxWidth, boxLength, boxHeight);

   // Display the Box object's properties.
   cout << "Here are the box's properties:\n";
   cout << "Width: " << myBox.getWidth() << endl; //2
   cout << "Length: " << myBox.getLength() << endl; //2
   cout << "Height: " << myBox.getHeight() << endl; //2
   cout << "Base area: " << myBox.getArea() << endl; //4
   cout << "Volume: " << myBox.getVolume() << endl; //8
   return 0;
}