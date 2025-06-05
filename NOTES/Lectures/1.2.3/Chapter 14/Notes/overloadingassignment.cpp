//overloading assignment operator bypass memberwise assignment operartor

#include <iostream>
using namespace std;
class Foo
{
    private:
    int *p;
    int size;
    public:
    Foo(int s)
    {
        size=s;
        p=new int[size]; //allocate memory for the array
        for (int i=0;i<size;i++)
            p[i]=0; //initialize the array to 0

    }
    ~Foo()
    {
        delete [] p; //deallocate memory for the array
    }

    //mutator function to set the value of the array
    void set(int index, int val)
    {
        p[index]=val; }//set the value of the array
        
        //accesor
        int getSize() const
        {
            return size; //get the size of the array
        };
        int get(int index) const
        {
            return p[index]; //get the value of the array
        };

        //As we have *this, return by copy temporary, thus we need a copy constructor
        Foo(const Foo& rhs) //copy constructor
        {
            size=rhs.size; //copy the size of the array
            p=new int[size]; //allocate memory for the array
            for(int i=0;i<size;i++)
                p[i]=rhs.p[i]; //copy the contents of the array
        };
        //You overload operators by adding a function to the class
        const Foo operator=(const Foo& rhs) //overloading assignment operator
        {
            if (this != &rhs)
            {
                //delete the existing lhs array (f)
            delete [] p;                             //have a problem if f=f since all original array ost
            //update the lhs size (f) **
            size=rhs.size; 
            //create a new array of the same size as rhs (g) for lhs (f)
            p=new int[size]; //allocate memory for the array

            //copy the contents of rhs (g) to lhs (f) 
            for(int i=0;i<size;i++)
                p[i]=rhs.p[i]; 
            }
            
            return *this; //return the lhs (f) object //self reference object //* return copy of Foo itself
        };
};

int main()
{

    Foo f(5),g(6),h(8);
    //f.operaor=(g); //overloading assignment operator //==f=g;

    for(int i=0;i<h.getSize();i++)
        h.set(i,i*i); //set the value of the array


//Problem operator = is void, can;t assign void to f
//Thus change to const Foo operator=()
    f=g=h; //f is lhs, g is rhs
    //f.operator=(g.operator=(h)); //overloading assignment operator //==f=g=h; //f=g=h; //overloading assignment operator

    for(int i=0;i<f.getSize();i++)
        cout<<f.get(i)<<" "; //get the value of the array
    cout<<endl; //print the value of the array

    cin.ignore();
    cin.get();
    return 0;
}