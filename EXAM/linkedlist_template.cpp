#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
    private:
    //Declare a structure for the list
    struct ListNode
    {
        T value; //node value
        struct ListNode *next; //point to next node
    };
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
    newNode= new ListNode;
    newNode->value=num;
    newNode->next=nullptr;

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
    newNode = new ListNode;
    newNode->value=num;

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
    return 0;
}


//length
template <class T>
int LinkedList<T>:: length()
{
    int count=0;
    ListNode<T> *nodePtr=front;
    while(nodePtr!=front)
    {
        count++
        nodePtr=nodePtr->next;
    }
    return count;
}

//add
template <class T>
void LinkedList<T>:: add(T value)
{
    if(head==nullptr)
        head=newListNode<T>(value);
}

//sum
template <class T>
T LinkedList<T>::sum() const
{
    T total = T(); // Initialize with default value for type T
    ListNode* current = head;
    while (current != nullptr)
    {
        total += current->value;
        current = current->next;
    }
    return total;
}

//push_front
template <class T>
void LinkedList<T>:: push_front(T value)
{
    ListNode *newNode;
    newNode=new ListNode(value,head);
    head=newNode;
    if(tail==nullptr) tail=newNode;
}

//push_back
template <class T>
void LinkedList<T>::push_back(T value)
{
    ListNode* newNode = new ListNode(value, nullptr); // Create new node with null next pointer
    if (tail == nullptr) // If list is empty
    {
        head = tail = newNode; // Both head and tail point to new node
    }
    else
    {
        tail->next = newNode; // Link current tail to new node
        tail = newNode;       // Update tail to new node
    }
}

//insert_after
template <class T>
void LinkedList<T>:: insert_after(T& target, T& newElement)
{
    //new node creation
    ListNode<T>*newNode=new ListNode;
    newNode->setItem(newElement);
    bool found = false;

    Node<T>* ptr = start;
    while (ptr != nullptr && !found)
    {
        if (ptr->getItem() == target)
            found = true;
        if (!found)
            ptr = ptr->getNext();
    }

    if (found) {
        newNode->setNext(ptr->getNext());
        ptr->setNext(newNode);
        return true;
    }
    return false;

}

//remove Last
template <class T>
void LinkedList<T>:: removeLast()
{
    if (size == 0) {
            return null;
        }
        else if (size == 1) {
            E temp = head.element;
            head = tail = null;
            size = 0;
            return temp;
        }
        else {
            ListNode<T> current = head;
            while (current.next != tail) {
                current = current.next;
            }
            E temp = tail.element;
            tail = current;
            tail.next = null;
            size--;
            return temp;
        }
}
