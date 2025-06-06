#include <iostream>
using namespace std;

// Animal is a base class.
class Animal
{
public:
   // Constructor
   Animal()
      { cout << "Animal constructor executing.\n"; }
   
   // Destructor        //virtual destructor
   virtual ~Animal()
      { cout << "Animal destructor executing.\n"; }
};

// The Dog class is derived from Animal
class Dog : public Animal
{
public:
   // Constructor
   Dog() : Animal()
      { cout << "Dog constructor executing.\n"; }

   // Destructor
   ~Dog()
      { cout << "Dog destructor executing.\n"; }
};

//*************************************************
// main function                                  *
//*************************************************

int main()
{
   // Create a Dog object, referenced by an
   // Animal pointer.
   Animal *myAnimal = new Dog;
   
   // Delete the dog object.
   delete myAnimal;  //since my animal destrcutoris virtual, will call dog destructor then animal destrcutor
   return 0;
} 

//Animal constructor executing.
//Dog constructor executing.
//Dog destrcutor executing.
//Animal destructor executing.
