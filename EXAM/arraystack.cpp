#include <iostream>
using namespace std;




class IntStack{
    private:
    int *stackArray; //pointer stackArray
    int stackSize;    //stack size
    int top;    //top of the stack

    public:
    //constructor
    IntStack(int);

    //Copy constrcutor
    IntStack(const IntStack &);

    //destrcutor
    ~IntStack();

    //Stack operation
    void push(int);
    void pop(int &);
    bool isFull ();
    bool isEmpty ();
};

//Constructor
IntStack::IntStack(int size)
{
    stackArray=new int[size];
    stackSize=size;
    top=-1;  //*
}

//Copy Constructor
IntStack::IntStack(const IntStack &obj)
{
    stackArray=new int[obj.stackSize];
    stackSize=obj.stackSize;

    //Copy the stack contents
    for (int count=0; count<stackSize;count++)
    stackArray[count]=obj.stackArray[count];
    top=obj.top;  //*
}

//Destructor
IntStack::~IntStack()
{
    delete[] stackArray;
}


//Mmeber function Stack Operation

//push
void IntStack::push (int num)
{
    if (isFull())
    {
        cout<<"The stack is full."<<endl;
    }
    else
    {
        top++;   //*
        stackArray[top]=num; //*
    }
}

//pop
void IntStack::pop(int &num)
{
    if (isEmpty())
    {
        cout<<"The stack is empty."<<endl;
    }
    else
    {
        num=stackArray[top]; //*
        top--;  //*
    }
}

//isFull
bool IntStack::isFull()const
{
    bool status;

    if(top==stackSize-1)  //*
        status=true;
    else
        status=false;
    return status;
}

//isEmpty
bool IntStack::isEmpty()const
{
    bool status;

    if(top==-1)  //*
        status=true;
    else
        status=false;
    return status;
}

int main()
{
    IntStack stack(5);

    stack.push(5);
    stack.pop(5);
    return 0;
}