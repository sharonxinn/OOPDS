#include <iostream>
#include <string>
using namespace std;

class Circle
{
private:
    double radius;

public:
    void setRadius(double r)
    {
        radius = r;
    }
    double calcArea()
    {
        return 3.14 * radius * radius;
    }
};

class Pizza
{
private:
    double price;
    Circle size;

public:
    void setPrice(double p)
    {
        price = p;
    }
    void setSize(double r)
    {
        size.setRadius(r);
    }
    double costPerSqIn()
    {
        return price / size.calcArea();
    }
};

int main()
{
    Pizza myPizza;
    myPizza.setPrice(314.159);
    myPizza.setSize(10);
    cout << "Cost per square inch: " << myPizza.costPerSqIn() << endl;
    return 0;
}
