#include <iostream>
using namespace std;




class DynIntStack{
    private:
    //Structure for stack nodes
    struct StackNode
    {
        int value;   //node value
        StackNode* next; //pointer to next node
    };
    StackNode* top;    //top of the stack

    public:
    //constructor
    DynIntStack();

    //destrcutor
    ~DynIntStack();

    //Stack operation
    void push(int);
    void pop(int &);
    bool isEmpty ();
};

//Constructor
DynIntStack::DynIntStack()
{
    top=nullptr;  //*
}

//Destructor //*
//nodePtr, nextNode ,top
DynIntStack::~DynIntStack()
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
void DynIntStack::push (int num)
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
void DynIntStack::pop(int &num)
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
bool DynIntStack::isEmpty()const
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
    DynIntStack stack(5);

    stack.push(5);
    stack.pop(5);
    return 0;
}