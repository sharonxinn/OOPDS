#include <iostream>
#include <cstdlib>
using namespace std;

main( )
{
    int i, iInt;
    char a, aChar;
    long g;
    float f;
    double d, dDouble;
    // Assign values
    i = 65;
    a = 'r';
    g = 241;
    f = 2.06;
    d = 122.448;

    cout << "The integer " << i << " converted to a character "
    << "is " << static_cast<char>(i) << "\n";
    cout << "The character " << a << " converted to an integer "
    << "is " << static_cast<int>(a) << "\n";
    cout << "The long integer " << g << " converted to a character "
    << "is " << static_cast<char>(g) << "\n";
    cout << "The float value " << f << " converted to an integer "
    << "is " << static_cast<int>(f) << "\n";
    cout << "The double value " << d << " converted to a character "
    << "is " << static_cast<char>(d) << "\n";
    cout << "\n\n";
    iInt = g + i;
    aChar = i + a;
    dDouble = d + g;

    cout << "The long integer " << g << " + " << " the integer "
    << i << " converted to an integer " << "is "
    << static_cast<int>(iInt) << "\n";
    cout << "The long integer " << g << " + " << " the integer "
    << i << " converted to a character " << "is "
    << static_cast<char>(iInt) << "\n";
    cout << "The integer " << i << " + " << " the character "
    << a << " converted to an integer " << "is "
    << static_cast<int>(aChar) << "\n";
    cout << "The integer " << i << " + " << " the character "
    << a << " converted to a character " << "is "
    << static_cast<char>(aChar) << "\n";

    cout << "The integer " << i << " * " << " the character "
    << a << " converted to an integer " << "is "
    << static_cast<double>(d * a) << "\n";
    cout << "The double " << d << " / " << " the character "
    << a << " converted to an integer " << "is "
    << static_cast<int>(d / a) << "\n";
    cout << "The double " << d << " + " << " the long integer "
    << g << " converted to an integer " << "is "
    << static_cast<int>(dDouble) << "\n";
    cout << "\n\n";
    return 0;
}