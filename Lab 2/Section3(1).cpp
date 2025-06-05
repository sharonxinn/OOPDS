#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int month, day, year;

    // Array to store the number of days in each month
    static const int daysInMonth[12];

    // Array of month names
    static const string monthNames[12];

    // Function to validate the date
    bool isValidDate(int m, int d, int y) {
        if (m < 1 || m > 12) return false;
        if (d < 1 || d > daysInMonth[m - 1]) return false;
        return true;
    }

public:
    // Constructor with default values
    Date(int m = 1, int d = 1, int y = 2001) {
        if (isValidDate(m, d, y)) {
            month = m;
            day = d;
            year = y;
        } else {
            month = 1;
            day = 1;
            year = 2001;
        }
    }

    // Function to print date in format: MM/DD/YY
    void printNumeric() {
        cout << month << "/" << day << "/" << (year % 100) << endl;
    }

    // Function to print date in format: Month DD, YYYY
    void printLongForm() {
        cout << monthNames[month - 1] << " " << day << ", " << year << endl;
    }

    // Function to print date in format: DD Month YYYY
    void printDayMonthYear() {
        cout << day << " " << monthNames[month - 1] << " " << year << endl;
    }
};

// Definition of static arrays
const int Date::daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const string Date::monthNames[12] = { "January", "February", "March", "April", "May", "June",
                                      "July", "August", "September", "October", "November", "December" };

int main() {
    Date date1(3, 15, 2016); // Valid date
    Date date2(13, 40, 2025); // Invalid date, should default to 1/1/2001
    Date date3; // Default date

    cout << "Date 1:\n";
    date1.printNumeric();
    date1.printLongForm();
    date1.printDayMonthYear();

    cout << "\nDate 2 (Invalid Date, should be defaulted):\n";
    date2.printNumeric();
    date2.printLongForm();
    date2.printDayMonthYear();

    cout << "\nDate 3 (Default Date):\n";
    date3.printNumeric();
    date3.printLongForm();
    date3.printDayMonthYear();

    return 0;
}
