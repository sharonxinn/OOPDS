#include <iostream>
using namespace std;

//class declaration
class Integer
{
    private:
    int num; //instance variable
    static int shared; //static number variable

    public:
    Integer(){num =0;}
    void set(int i){num=i;}
    int get()const{return num;}

    int getShared()const{return shared;}
    void bump(){shared++;} //increment the static variable


    //static member function cannot access instance variable
    //static int set(){ return num;} //ERROR

    //static member function caannot have accesor const
    //Satic funcctions cannot update instance variables, so there's no point to make them const
    //static int get()const{return num;} //ERROR
    static void updatedShared(int i){shared=i;} //static function to set the static variable static member function
    static int retriveShared(){return shared;} //static function to get the static variable


};

//definition of the static member variable outsdide of the class

int Integer::shared=0;

class Foo
{
    public:
    static int add(int a, int b)
    {
        return a+b;
    }
    static int sub(int a, int b)
    {
        return a-b;
    }
};

int main()
{

    //no instance of Intger defined
    cout<<Integer::retriveShared()<<endl; //access the static variable using class name
    Integer::updatedShared(99); //update the static variable using class name

    cout <<Foo::add(5, 6)<<endl; //access the static function using class name
    cout <<Foo::sub(5, 6)<<endl; //access the static function using class name


    Integer obj1, obj2;
    obj1.set(8);
    obj2.set(14);

    cout<<obj1.get()<<""<<obj2.get()<<endl;

    obj1.set(15);

    cout<<obj1.get()<<""<<obj2.get()<<endl;


    cout<<obj1.getShared()<<" "<<obj2.getShared()<<endl;
    obj1.bump(); //increment the static variable using obj1
    cout<<obj1.getShared()<<" "<<obj2.getShared()<<endl;
    obj2.bump(); //increment the static variable using obj1
    cout<<obj1.getShared()<<" "<<obj2.getShared()<<endl;
    
    
    Integer obj3; //create a new object
    cout<<obj3.getShared()<<endl; //access the static variable using obj3

    cin.ignore();
    cin.get();
}