#include <iostream>
#include <string>
using namespace std;

class DayOfYear {
private:
    int day;
    static const string months[];
    static const int daysInMonth[];
    static const int totalDays[];
    
public:
    DayOfYear(int d) {
        if (d < 1 || d > 365) {
            cout << "Day out of range (1-365). Setting to 1." << endl;
            day = 1;
        } else {
            day = d;
        }
    }
    
    void print() const {
        int month = 0;
        while (day > totalDays[month]) {
            month++;
        }
        
        int dayOfMonth = day - totalDays[month - 1];
        cout << months[month] << " " << dayOfMonth << endl;
    }
};

const string DayOfYear::months[] = {
    "January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December"
};

const int DayOfYear::daysInMonth[] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

// Initialize totalDays array (cumulative days up to each month)
const int DayOfYear::totalDays[] = {
    0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365
};

int main() {
    int day;
    cout << "Enter a day of the year (1-365): ";
    cin >> day;
    
    DayOfYear doy(day);
    doy.print();
    
    return 0;
}