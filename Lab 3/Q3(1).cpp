#include <iostream>
#include <string>
using namespace std;

class Numbers {
private:
    int number;
    static const string lessThan20[];
    static const string tens[];
    static const string hundred;
    static const string thousand;
    
public:
    Numbers(int num) {
        if (num < 0 || num > 9999) {
            cout << "Number out of range (0-9999). Setting to 0." << endl;
            number = 0;
        } else {
            number = num;
        }
    }
    
    void print() const {
        if (number == 0) {
            cout << lessThan20[0];
            return;
        }
        
        int n = number;
        if (n >= 1000) {
            int thousands = n / 1000;
            cout << lessThan20[thousands] << " " << thousand << " ";
            n %= 1000;
        }
        
        if (n >= 100) {
            int hundreds = n / 100;
            cout << lessThan20[hundreds] << " " << hundred << " ";
            n %= 100;
        }
        
        if (n >= 20) {
            int ten = n / 10;
            cout << tens[ten - 2] << " ";
            n %= 10;
        }
        
        if (n > 0) {
            cout << lessThan20[n];
        }
        
        cout << endl;
    }
};

const string Numbers::lessThan20[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", 
    "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", 
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

const string Numbers::tens[] = {
    "twenty", "thirty", "forty", "fifty", 
    "sixty", "seventy", "eighty", "ninety"
};

const string Numbers::hundred = "hundred";
const string Numbers::thousand = "thousand";

int main() {
    int num;
    cout << "Enter a number between 0 and 9999: ";
    cin >> num;
    
    Numbers n(num);
    n.print();
    
    return 0;
}