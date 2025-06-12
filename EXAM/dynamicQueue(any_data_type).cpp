#include <iostream>
using namespace std;



template <class T>
class DynIntQueue{
    private:
    //Structure for queue nodes
    struct QueueNode
    {
        T value;   //node value
        QueueNode* next; //pointer to next node
    };
   QueueNode* front;    //front of thr queue //^
   QueueNode* rear;    //rear of thr queue   //^
   int numItems;

    public:
    //constructor
    DynIntQueue();

    //destrcutor
    ~DynIntQueue();

    //Stack operation
    void enqueue(T);
    void dequeue(T &);
    bool isEmpty ();
    bool isFull(); //circular queue  //^
    void clear();   //^
};

//Constructor
template <class T>
DynIntQueue<T>::DynIntQueue()
{
    front=nullptr;  //^
    rear =nullptr; //^
    numItems=0; //^
}

//Destructor //^
template <class T>
DynIntQueue<T>::~DynIntQueue()
{
   clear();
}


//Mmeber function Queue Operation

//enqueue(push)  //^
//newMode  front rear
template <class T>
void DynIntQueue<T>::enqueue (T num)
{
    QueueNode *newNode=nullptr; //pointer to a new node

    //allocate a new node and store num in new node
    newNode=new QueueNode;
    newNode->value=num;
    newNode->next=nullptr;

    //** 
    if (isEmpty)
    {
        front=newNode;
        rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
    numItems ++;
}

//dequeue(pop) //^
//temp front rear
template <class T>
void DynIntQueue<T>::dequeue(T &num)
{
    QueueNode *temp=nullptr; //pointer to a temporary node

    //** 
    if (isEmpty)
    {
        cout<<"The queue is Empty"
    }
    else
    {
        num=front->value;
        temp=front;
        front=front->next;
        delete temp;
        
        numItems--;
    }
}

//isEmpty
template <class T>
bool DynIntQueue<T>::isEmpty()const
{
    bool status;

    if(numItems<0)  //*
        status=true;
    else
        status=false;
    return status;
}

//clear
template <class T>
void DynIntQueue<T>:: clear()
{
    int value;  //dummy variable for dequeue

    while(!isEmpty())  
    dequeue(value);
}
int main()
{
    DynIntQueue<string> queue;
    queue.enqueue(5);
    queue.dequeue(5);
    return 0;
}