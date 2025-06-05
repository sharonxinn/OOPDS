// This program demonstrates a class that redefines
// a base class function.
#include <iostream>
#include <iomanip>
#include "CurvedActivity.h"
using namespace std;

int main()
{
   double numericScore;  // To hold the numeric score
   double percentage;    // To hold curve percentage

   // Define a CurvedActivity object.
   CurvedActivity exam;

   // Get the unadjusted score.
   cout << "Enter the student's raw numeric score: ";
   cin >> numericScore; //20

   // Get the curve percentage.
   cout << "Enter the curve percentage for this student: ";
   cin >> percentage;//20

   // Send the values to the exam object.
   exam.setPercentage(percentage);
   exam.setScore(numericScore);

   // Display the grade data.
   cout << fixed << setprecision(2);
   cout << "The raw score is "  //20.00
        << exam.getRawScore() << endl;
   cout << "The curved score is "  //400.00
        << exam.getScore() << endl;
   cout << "The curved grade is "  //A
        << exam.getLetterGrade() << endl;

   return 0;
}