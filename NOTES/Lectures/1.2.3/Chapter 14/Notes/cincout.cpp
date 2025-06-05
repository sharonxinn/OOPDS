#include <iostream>
using std::istream;
using std::ostream;

class Foo
{
    private:
    int bar;
    public:
    friend ostream& operator<<(ostream&,const Foo&);
    friend istream& operator>>(istream&,Foo&);
    
};
ostream& operator<<(ostream& os, const Foo& f)
{
    os << f.bar;
    return os;
}
istream& operator>>(istream& is, Foo& f)
{
    is >> f.bar;
    return is;
}
int main()
{
    Foo f;
    std::cout << "Enter a number: ";
    std::cin >> f;
    std::cout << "You entered: " << f << std::endl;
    return 0;
}