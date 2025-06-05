//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT bag: Link-based implementation - RECURSIVE VERSION.
    @file LinkedBag.h 
    Listing 4-3 */
#ifndef _LINKED_BAG
#define _LINKED_BAG

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node
   int itemCount;           // Current count of bag items
   
   // Fills the vector bagContents with the data in the nodes of
   // the linked chain to which curPtr points.
   void fillVector(vector<ItemType>& bagContents, Node<ItemType>* curPtr) const;
   
   // Locates a given entry within this bag.
   // Returns either a pointer to the node containing a given entry or
   // the null pointer if the entry is not in the bag.
   Node<ItemType>* getPointerTo(const ItemType& target,
                                Node<ItemType>* curPtr) const;
   
   // Counts the frequency of occurrence of a given entry in this bag.
   int countFrequency(const ItemType& anEntry, int counter,
                      Node<ItemType>* curPtr) const;

   // Deallocates all nodes assigned to this bag
   void deallocate(Node<ItemType>* nextNodePtr);
   
public:
   LinkedBag();
   LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
   virtual ~LinkedBag();                       // Destructor should be virtual
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   void clear();
   bool contains(const ItemType& anEntry) const;
   int getFrequencyOf(const ItemType& anEntry) const;
   vector<ItemType> toVector() const;
}; // end LinkedBag

#include "LinkedBag.cpp"
#endif