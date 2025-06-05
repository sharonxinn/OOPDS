//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT queue: ADT list implementation.
 Listing 14-2.
 @file ListQueue.cpp */

#include "ListQueue.h"  // header file

template<class ItemType>
ListQueue<ItemType>::ListQueue()
{
   listPtr = new LinkedList<ItemType>();
}  // end default constructor

template<class ItemType>
ListQueue<ItemType>::ListQueue(const ListQueue& aQueue)
{
	// First, create our own list
	listPtr = new LinkedList<ItemType>();
	
	// Then add items to it using public methods
	for(int position = 1; position <= aQueue.listPtr->getLength(); position++)
	{
		listPtr->insert(position, aQueue.listPtr->getEntry(position));
	}  // end for
}  // end copy constructor

template<class ItemType>
ListQueue<ItemType>::~ListQueue()
{
}  // end destructor

template<class ItemType>
bool ListQueue<ItemType>::isEmpty() const
{
   return listPtr->isEmpty();
}  // end isEmpty

template<class ItemType>
bool ListQueue<ItemType>::enqueue(const ItemType& newEntry)
{
   return listPtr->insert(listPtr->getLength() + 1, newEntry);
}  // end enqueue

template<class ItemType>
bool ListQueue<ItemType>::dequeue()
{
   return listPtr->remove(1);
}  // end dequeue

template<class ItemType>
ItemType ListQueue<ItemType>::peekFront() const throw(PrecondViolatedExcep)
{
   if (isEmpty())
      throw PrecondViolatedExcep("peekFront() called with empty queue.");

   // Queue is not empty; return front
   return listPtr->getEntry(1);
}  // end peekFront
// End of implementation file.
