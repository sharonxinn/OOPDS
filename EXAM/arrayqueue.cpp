#include <iostream>
using namespace std;




class IntQueue{
    private:
    int *queueArray; //pointer queueArray
    int queueSize;    //queue size
    int front;    //front of the queue  //^
    int rear;    //back of the queue    //^
    int numItems;            //^

    public:
    //constructor
    IntQueue(int);

    //Copy constrcutor
    IntQueue(const IntQueue &);

    //destrcutor
    ~IntQueue();

    //Stack operation
    void enqueue(int); //push
    void dequeue(int &);  //pop
    bool isFull ();
    bool isEmpty ();
    void clear();    //^
};

//Constructor
IntQueue::~IntQueue(int size)
{
    queueArray=new int[size];
    queueSize=size;
    front=-1;  //^
    rear=-1;   //^
    numItems=0; //^
}

//Copy Constructor
IntQueue::IntQueue(const IntQueue &obj)
{
    queueArray=new int[obj.queueSize];
    queueSize=obj.queueSize;
    front=obj.front;  //^
    rear=obj.rear; //^
    numItems=obj.numItems; //^

     //Copy the queue contents
    for (int count=0; count<queueSize;count++)
     queueArray[count]=obj.queueArray[count];
}

//Destructor
IntQueue::~IntQueue()
{
    delete[] queueArray;
}


//Mmeber function Queue Operation

//enqueue (push) //^
void IntQueue::enqueue (int num)
{
    if (isFull())
    {
        cout<<"The queue is full."<<endl;
    }
    else
    {
        //calculate the new rear position
        rear=(rear+1)% queueSize;
        //Insert new item
        queueArray[rear]=num;
        //Update item count;
        numItems ++;
    }
}

//dequeue (pop) //^
void IntQueue::dequeue(int &num)
{
    if (isEmpty())
    {
        cout<<"The queue is empty."<<endl;
    }
    else
    {
        //calculate the new front position
        front=(front+1)% queueSize;
        //Remove the front item
        num=queueArray[front];
        //Update item count;
        numItems --;
    }
}

//isFull
bool IntQueue::isFull()const
{
    bool status;

    if(numItems<queueSize)  //^
        status=false;
    else
        status=true;
    return status;
}

//isEmpty
bool IntQueue::isEmpty()const
{
    bool status;

    if(numItems)  //^
        status=false;
    else
        status=true;
    return status;
}

int main()
{
    IntQueue queue(5);

    queue.enqueue(5);
    queue.dequeue(5);
    return 0;
}