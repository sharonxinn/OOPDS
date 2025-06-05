#include <iostream>
using namespace std;

class Money
{
private:
    int dollars;
    int cents;

public:
    // Constructor with default values for dollars and cents
    Money(int d = 0, int c = 0) : dollars(d), cents(c) {}

    // Mutator functions
    void setDollars(int d) { dollars = d; } //mutator function
    void setCents(int c) { cents = c; } //mutator function

    // Accessor functions
    int getDollars() const { return dollars; } //accessor function
    int getCents() const { return cents; } //accessor function

    // Overloading the + operator
    Money operator+(const Money& m) const
    {
        // Adding dollars and cents
        Money temp(dollars + m.dollars, cents + m.cents);

        // Handling case where cents are more than 100
        if (temp.cents >= 100)
        {
            temp.dollars += temp.cents / 100;  // Adding extra dollars
            temp.cents = temp.cents % 100;     // Remainder for cents
        }

        return temp; // Return the resulting Money object
    }
    

    // Display function to show money in $dollars.cents format
    void display() const
    {
        cout << "$" << dollars << "." << cents << endl;
    }
};

int main()
{
    Money m(1, 85), n(1, 86), o;

    // Use the overloaded + operator
    o = m + n;

    // Display the result
    o.display(); //print out the result in the format $dollars.cents

    cin.ignore();
    cin.get();
    return 0;
}
