#include <iostream>
using namespace std;


class Integer{
    private:
    int i;
    public:
    Integer(int x=0):i(x){}
    int get()const{return i;}
    Integer operator++();     //empty parameter list =>PREFIX version
    Integer operator++(int);  //dummy parameter int =>POSTFIX version
    Integer operator--();     //empty parameter list =>PREFIX version
    Integer operator--(int);  //dummy parameter int =>POSTFIX version

};

//i++ =postfix, return the value then increment
//++i =prefix, increment the value then return
int main()
{
    Integer i(5),j;
    cout<<i.get()<<", "<<j.get()<<endl; //5, 0
    j=i++; //postfix increment, j=5, i=6
    cout<<i.get()<<", "<<j.get()<<endl; //6, 5

    j=++i; //prefix increment, j=7, i=7
    cout<<i.get()<<", "<<j.get()<<endl; //7, 7

    cin.ignore();
    cin.get();
    return 0;
}

//empty parameter list =>PREFIX version
Integer Integer::operator++()
{
    i++;
    return *this; //return the object itself
}
//dummy parameter int =>POSTFIX version
Integer Integer::operator++(int)
{
    //preserve the original state of our object
    Integer temp(i); //Need this temporary object
    i++; //increment our integer variable
    return temp; //return the copy of the object before incrementing
}