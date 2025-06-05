#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Heading {
private:
    string companyName;
    string reportName;

    // Function to center text
    void printCentered(const string& text, int width) const {
        int padding = (width - text.length()) / 2;
        cout << setw(padding + text.length()) << text << endl;
    }

public:
    // Constructor with default values
    Heading(string company = "ABC Industries", string report = "Report") {
        companyName = company;
        reportName = report;
    }

    // Function to print one-line format
    void printOneLine() const {
        cout << companyName << " " << reportName << endl;
    }

    // Function to print boxed format
    void printBoxed() const {
        const int width = 50; // Width for centering

        cout << string(width, '*') << endl;  // Top border
        printCentered(companyName, width);
        printCentered(reportName, width);
        cout << string(width, '*') << endl;  // Bottom border
    }
};

int main() {
    // Creating different Heading objects
    Heading heading1("Pet Pals", "Payroll Report"); // Custom heading
    Heading heading2; // Default heading

    // Display one-line format
    cout << "One-Line Format:\n";
    heading1.printOneLine();
    heading2.printOneLine();

    // Display boxed format
    cout << "\nBoxed Format:\n";
    heading1.printBoxed();
    heading2.printBoxed();

    return 0;
}
