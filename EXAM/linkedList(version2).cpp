#include <iostream>
using namespace std;


//create a type used to store a node od the linked list
template <class T>
class ListNode
{
    public:
    T value; //Node value
    ListNode<T> *next; //Pointer to next node

    //Constructor
    ListNode( T nodeValue)
    {
        value=nodeValue;
        next=nullptr;
    }
}

//LinkedList class
template <class T>
class LinkedList
{
    private:
    ListNode *head;  //head pointer

    public:
    //Constructor
    LinkedList()
    {
        head=nullptr;
    }
    //Destructor
    ~LinkedList();
    //Linked list Operations
    void appendNode(T);
    void insertNode(T);
    void deleteNode(T);
    void displayList();
};

//append a node containgn the value, append to the end of list
template <class T>
void LinkedList <T>:: appendNode(T newValue)
{
    ListNode *newNode; //Point to a new node
    ListNode *nodePtr; //Move thorugh list

    //Allocate a new node and stor num there
    newNode= new ListNode<T>(newValue);

    //If no nodes in list , make newNode first node
    if(!head) //head!=nullptr
        head=newNode;
    //else insert newNode at end
    else
    {
        //initialise nodePtr to head of list
        nodePtr=head;
        //Find last node in list
        while(nodePtr->next)
            nodePtr=nodePtr->next;

        //Insert newNode as last node
        nodePtr->next=newNode;
    }
}

//show the value store din each node of linked lit pointed to by head
template <class T>
void LinkedList <T>:: displayList() 
{
    ListNode *nodePtr; //Move thorugh list

    //Position nodePtr at the head of list
    nodePtr=head;

    //While nodePtr points to a node, traverse te list
    while (nodePtr)
    {
        //Display node value
        cout <<nodePtr->value <<endl;
        nodePtr=nodePtr->next;
    }
}

//inserts a node with newValue copied to its value member
template <class T>
void LinkedList <T>:: insertNode(T newValue) 
{
    ListNode *newNode; //A new node
    ListNode *nodePtr; //Move thorugh list
    ListNode *previousNode=nullptr; //The previous node

    //Allocate a new node and store num there
    newNode = new ListNode<T>(newValue);

    //If no nodes in list , make newNode first node
    if(!head) //head!=nullptr
        head=newNode;
        newNode->next=nullptr;
    //else insert newNode at end
    else
    {
        //initialise nodePtr to head of list
        nodePtr=head;
        //initialise previousNode to nullptr
        previousNode=nullptr;
        //Skip all nodes value less than num
        while(nodePtr!=nullptr &&nodePtr->value<num){
            previousNode=nodePtr;
            nodePtr=nodePtr->next;}

        //If new node is to be the 1st in the list, insert it before all other nodes
        if(previousNode==nullptr)
        {
            head=newNode;
            newNode->next=nodePtr;
        }
        //else insert after the previous node
        previousNode->next=newNode;
        newNode->next=nodePtr;
    }
}

//with searchValue as its value, the node, if found, deleted from the list and memory
template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
    ListNode *nodePtr; //Move thorugh list 
    ListNode *previousNode; //Point to previous node

    //If list empty, do nothing
    if(!head)
        return;
    //Determine if the first node is the one
    if(head->value ==num)
    {
        nodePtr=head->next;
        delete head;
        head=nodePtr;
    }
    //else transverse the list
    else
    {
        nodePtr=head; //Initialize nodePtr to head of list
        //Skip all nodes whose value member is not equal to num
        while (nodePtr!=nullptr &&nodePtr->value!=num)
        {
            previousNode=nodePtr;
            nodePtr=nodePtr->next;
        }

        //If nodePtr is not at the end of list, link the previous node to the node after nodePtr, then delete nodePtr
        if(nodePtr)
        {
            previousNode->next=nodePtr->next;
            delete nodePtr;
        }
    }
}

//Destructor delete every node in list
template <class T>
LinkedList<T>:: ~LinkedList()
{
    ListNode *nodePtr; //Move thorugh list 
    ListNode *nextNode; //Point to next node

    //Position nodePtr at the head of list
    nodePtr=head;

    //While nodePtr points to a node, traverse te list
    while (nodePtr)
    {
        //save a pointer to next node
        nextNode=nodePtr->next;
        //delete current node
        delete nodePtr;
        //Position nodePtr at the next node
        nodePtr=nextNode;
    }
}

int main()
{
    LinkedList<FeetInches> list;

    FeetInches distance1(5,40);

    list.appendNode(distance1);
    list.displayList();
    FeetInches distance1(7,2);
    list.insertNode(distance1);
    list.deleteNode(distance1);
}