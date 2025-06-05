//memberwise assignment

#include <iostream>
#include <string>
using namespace std;

class Foo
{
    private:
        //int x; //memberwise assignment
        int *xptr;
    public:
        //Foo(){x=0;}
        Foo(){xptr = new int; *xptr-0;} //default constructor
        Foo(const Foo& p) //copy constructor, executes instead of default constructor 
        {
            xptr = new int; //allocate memory for the new object
            *xptr = p.get(); //copy the value of the object being copied
        }
        void set(int i){*xptr=i;}
        int get()const{return *xptr;}};
        //copy constructor

int main()
{
    Foo f;
    f.set(5);

    //initialise g with f
    //member wise assignment g.x=f.x
    Foo g = f; //copy constructor called
    //Foo g(f);  same thing as above

    cout <<g.get()<<endl; //5

    g.set(33);
    cout <<g.get()<<endl; //33    //class copy constructor to avoid this     
    cout <<f.get()<<endl; //33                                          //5


    return 0;
}
