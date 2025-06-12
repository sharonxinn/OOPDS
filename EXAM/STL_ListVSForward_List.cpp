//list container doubly linked list
//forward list container singly linked list

#include <list>

//List Definition
list<dataType>name; //Default Constructor
list<dataType>name(size); //Fill Constructor
list<dataType>name(size,value); //Fill Constructor
list<dataType>name(iterator1,iterator2); //Range Constructor
list<dataType>name(lisr2); //Copy Constructor

//List Member Functions
back()
begin()
cbegin()
cend()
clear()
crbegin() //reverse
crend() //reverse
emplace(it, args) 
emplace_back(args)
emplace_front(args)
empty()
end()
erase(it)
erase(iterator1,iterator2)
front()
insert(it,value)
insert(it,n,value)
insert(iterator1,iterator2,iterator3)
max_size()
merge(second)
pop_back()
pop_front()
push_back(value)
push_front(value)
rbegin() //reverse
remove(value)
remove_if(function)
rend() //reverse
resize(n)
resize(n,value)
reverse()
size()
sort()
swap(second)
unique()

#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int>myList;
    for(int x=0;x<100;x+=10)
        myList.push_back(x);

    for(auto it=myList.begin(); it!=myList.end; it++)
        cout<<*it<<" ";
    cout<<endl;

    myList.reverse();
    for(auto element:myList)
        cout<<element<<" ";
    cout<<endl;
    return 0;
}