#include <iostream>
using namespace std;



template<class T>
class DynIntStack{
    private:
    //Structure for stack nodes
    struct StackNode
    {
        T value;   //node value
        StackNode* next; //pointer to next node
    };
    StackNode* top;    //top of the stack

    public:
    //constructor
    DynIntStack();

    //destrcutor
    ~DynIntStack();

    //Stack operation
    void push(T);
    void pop(T &);
    bool isEmpty ();
};

//Constructor
template<class T>
DynIntStack<T>::DynIntStack()
{
    top=nullptr;  //*
}

//Destructor //*
//nodePtr, nextNode top
template<class T>
DynIntStack<T>::~DynIntStack()
{
    StackNode *nodePtr=nullptr, *nextNode=nullptr;
    nodePtr=top;  //position nodePtr at the stack top

    //Traverse the list deleting each node
    while (nodePtr!=nullptr) 
    {
        nextNode=nodePtr->next;
        delete nodePtr;
        nodePtr=nextNode;
    }

}


//Mmeber function Stack Operation

//push  //*
//newMode  top
template<class T>
void DynIntStack<T>::push (T num)
{
    StackNode *newNode=nullptr; //pointer to a new node

    //allocate a new node and store num in new node
    newNode=new StackNode;
    newNode->value=num;


    //** 
    if (isEmpty)
    {
        top=newNode;
        newNode->next=nullptr;
    }
    else
    {
        newNode->next=top;
        top=newNode;
    }
}

//pop
//temp top
template<class T>
void DynIntStack<T>::pop(T &num)
{
    StackNode *temp=nullptr; //pointer to a temporary node

    //** 
    if (isEmpty)
    {
        cout<<"The stack is Empty"
    }
    else
    {
        num=top->value;
        temp=top->next;
        delete top;
        top=temp;
    }
}

//isEmpty
template<class T>
bool DynIntStack<T>::isEmpty()const
{
    bool status;

    if(!top)  //*
        status=true;
    else
        status=false;
    return status;
}

int main()
{
    DynIntStack <string> stack;

    stack.push(5);
    stack.pop(5);
    return 0;
}