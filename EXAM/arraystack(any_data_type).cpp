#include <iostream>
using namespace std;



template <class T>
class IntStack{
    private:
    T *stackArray; //pointer stackArray
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
    void push(T);
    void pop(T &);
    bool isFull ();
    bool isEmpty ();
};

//Constructor
template <class T>
IntStack<T>::IntStack(int size)
{
    stackArray=new T[size];
    stackSize=size;
    top=-1;  //*
}

//Copy Constructor
template <class T>
IntStack<T>::IntStack(const IntStack &obj)
{
    stackArray=new T[obj.stackSize];
    stackSize=obj.stackSize;

    //Copy the stack contents
    for (int count=0; count<stackSize;count++)
    stackArray[count]=obj.stackArray[count];
    top=obj.top;  //*
}

//Destructor
template <class T>
IntStack<T>::~IntStack()
{
    delete[] stackArray;
}


//Mmeber function Stack Operation

//push
IntStack<T>
void IntStack<T>::push (T num)
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
template <class T>
void IntStack<T>::pop(int &T)
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
template <class T>
bool IntStack<T>::isFull()const
{
    bool status;

    if(top==stackSize-1)  //*
        status=true;
    else
        status=false;
    return status;
}

//isEmpty
template <class T>
bool IntStack<T>::isEmpty()const
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
    IntStack <string> stack;
    stack.push(5);
    stack.pop(5);
    return 0;
}