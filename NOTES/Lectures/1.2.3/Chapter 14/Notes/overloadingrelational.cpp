#include <iostream>
using namespace std;

class Square
{
    private:
    double side;
    public:
    Square(int x=0) : side(x) {}

    double getSide() const { return side; }
    double getArea() const { return side * side; }
    bool operator<(const Square& s) const;
};

int main()
{
    Square a(5), b(10);
    //a=>lhs, b=>rhs
    //a.operator<(b) => a<b
    if (a < b)
        cout << "a is less than b" << endl;
    else
        cout << "a is not less than b" << endl;

    cin.ignore();
    cin.get();
    return 0;
}

bool Square::operator<(const Square& rhs) const
{
    return getArea() < rhs.getArea();
}
//bool Square::operator==(const Square& rhs) const
//{
//    return getArea() == rhs.getArea();
//}
