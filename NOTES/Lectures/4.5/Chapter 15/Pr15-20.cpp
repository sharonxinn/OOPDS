// This program demonstrates a class with multiple inheritance.
#include "DateTime.h"
using namespace std;

int main()
{
   // Define a DateTime object and use the default
   // constructor to initialize it.
   DateTime emptyDay;

   // Display the object's date and time.
   emptyDay.showDateTime(); //1/1/1900 0:0:0

   // Define a DateTime object and initialize it
   // with the date 2/4/1960 and the time 5:32:27.
   DateTime pastDay(2, 4, 1960, 5, 32, 27); 

   // Display the object's date and time.
   pastDay.showDateTime(); //4/2/1960 5:32:27
   return 0;
}