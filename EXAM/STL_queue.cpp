//deque =double ended queue
//queue ADT container use deque as default container

//push-back
//pop_dront
//front

//deque
#include<deque>
const int MAX=8;
int count;

//Define an STL deque object
deque<int> iDeque;

for (count=0;count<MAX; count++)
{
    iDeque.push_back(count);
}

iDeque.size();

for (count=0;count<MAX; count++)
{
    iDeque.pop_front(count);
}


----------------------------------------------------------------------------------------------------
//push
//pop
//front

//queue
#include<queue>
const int MAX=8;
int count;

//Define an STL deque object
queue<int> iQueue;

for (count=0;count<MAX; count++)
{
    iQueue.push(count);
}

iQueue.size();

for (count=0;count<MAX; count++)
{
    iQueue.pop(count);
}
