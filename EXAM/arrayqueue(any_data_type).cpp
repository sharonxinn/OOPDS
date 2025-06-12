#include <iostream>
using namespace std;



template <class T>
class IntQueue{
    private:
    T *queueArray; //pointer queueArray
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

    //Queue operation
    void enqueue(T); //push
    void dequeue(T &);  //pop
    bool isFull ();
    bool isEmpty ();
    void clear();    //^
};

//Constructor
template <class T>
IntQueue<T>::IntQueue(int size)
{
    queueArray=new T[size];
    queueSize=size;
    front=-1;  //^
    rear=-1;   //^
    numItems=0; //^
}

//Copy Constructor
template <class T>
IntQueue<T>::IntQueue(const IntQueue &obj)
{
    queueArray=new T[obj.queueSize];
    queueSize=obj.queueSize;
    front=obj.front;  //^
    rear=obj.rear; //^
    numItems=obj.numItems; //^

     //Copy the queue contents
    for (int count=0; count<queueSize;count++)
     queueArray[count]=obj.queueArray[count];
}

//Destructor
template <class T>
IntQueue<T>::~IntQueue()
{
    delete[] queueArray;
}


//Mmeber function Queue Operation

//enqueue (push) //^
template <class T>
void IntQueue<T>::enqueue (T num)
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
template <class T>
void IntQueue<T>::dequeue(T &num)
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
template <class T>
bool IntQueue<T>::isFull()const
{
    bool status;

    if(numItems<queueSize)  //^
        status=false;
    else
        status=true;
    return status;
}

//isEmpty
template <class T>
bool IntQueue<T>::isEmpty()const
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
    IntQueue<string> queue;

    queue.enqueue(5);
    queue.dequeue(5);
    return 0;
}