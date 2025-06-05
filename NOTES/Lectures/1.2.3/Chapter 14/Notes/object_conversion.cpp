#include <iostream>
using namespace std;

class Foo
{
    private:
    int a[10];
    public:
    Foo()
    {
        for(auto &i : a)
            i=2;
    }
    //operator conversion function
    operator int() //no return type, and we have empty parameter list
    {
        int total=0;
        for(auto i : a)
            total+=i;
        cout<<"Sum of array elements: "<<total<<endl;
        return total; //returning the sum of array elements
    }

    operator double()
    {
        return 8.8;
    }
    operator float();
};
int main()
{
    int x;
    Foo f;
    x=f;
    cout<<"x: "<<x<<endl; //calls the conversion operator int()

    double d;
    d=f;
    cout<<"d: "<<d<<endl; //calls the conversion operator double()

    float ff=f;
    cout<<"ff: "<<ff<<endl; //calls the conversion operator double() and then converts to float


    cin.ignore();
    cin.get();
    return 0;
}

Foo::operator float()
{
    float total=0;
    for (auto i : a)
        total+=i;
    return total/3;
    
}