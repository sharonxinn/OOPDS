//Three types of friends:
//1.classes
//2.class member functions
//3.standalone functions

//Friends can access a class's private and protected members

#include <iostream>
#include <string>
using namespace std;

class Square; //forward declaration

class Shapes
{
    public:
    double findArea(const Square&) const; //friend function
};

class Foo {
    public:
    double getSide(const Square& s) const; // accessor function
    void cubeSide(Square& s) const; // modifying the private member of Square class
};

class Square
{
    private:
        double side;
    public:
        Square(double s = 0): side(s) {} // constructor
        double getSide() const { return side; } // accessor function

        //friend list to access private members of Square class
        friend double Shapes::findArea(const Square&) const; // class member function as friend
        friend void updateSquare(Square&);                   // standalone function as friend
        friend class Foo;                                    // entire class Foo is a friend
};

// friend member function definition
double Shapes::findArea(const Square& s) const {
    return s.side * s.side; // accessing the private member of Square class
}

// friend standalone function definition
void updateSquare(Square& s) {
    s.side = 99.1; // modifying the private member of Square class
}

void Foo::cubeSide(Square& s) const{
    s.side = s.side * s.side * s.side; // modifying the private member of Square class
};

// friend class method definition
double Foo::getSide(const Square& s) const {
    return s.side; // accessing the private member of Square class
}


int main() {
    Square sq(5.1);
    Shapes s;

    cout << s.findArea(sq) << endl; // friend class member function
    updateSquare(sq);               // friend standalone function
    cout << sq.getSide() << endl;   // public accessor
    Foo f;
    cout << f.getSide(sq) << endl;  // friend class method

    f.cubeSide(sq);                 // friend class method
    cout << sq.getSide() << endl;   // public accessor

    cin.ignore();
    cin.get();
    return 0;
}
