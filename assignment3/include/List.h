//==============================================================
// Filename    : List.h    
// Authors     : Srikrishnan Srinivasan (s3603288), Raghavendran Srinivasan (s3656721)
// Group       : Group 16
// License     : N.A. or opensource license like LGPL
// Description : Defines the functions of the list, concatenate function of the assignment is defined here. This file is from the template function of List.h as provided.
//==============================================================
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h" // ListNode class definition

template<typename NODETYPE>
class List {
public:
    // default constructor
    List() : firstPtr(nullptr), lastPtr(nullptr) {
        // empty body
    } // end List constructor

   // destructor
   ~List() {
      if (!isEmpty()) { // List is not empty
         //std::cout << "Destroying nodes ...\n"; commented out to remove spam in solution

         ListNode<NODETYPE>* currentPtr{firstPtr};
         ListNode<NODETYPE>* tempPtr{nullptr};

         while (currentPtr != nullptr) { // delete remaining nodes
            tempPtr = currentPtr;
            //std::cout << tempPtr->data << '\n';
            currentPtr = currentPtr->nextPtr;  
            delete tempPtr;
         } 
      } 

      //std::cout << "All nodes destroyed\n\n"; commented out to remove spam in solution, does not affect destructor role in any way.
   } 

   // insert node at front of list
   void insertAtFront(const NODETYPE& value) {
      ListNode<NODETYPE>* newPtr{getNewNode(value)}; // new node

      if (isEmpty()) { // List is empty
         firstPtr = lastPtr = newPtr; // new list has only one node
      } 
      else { // List is not empty
         newPtr->nextPtr = firstPtr; // point new node to old 1st node
         firstPtr = newPtr; // aim firstPtr at new node
      } 
   } 

   // insert node at back of list
   void insertAtBack(const NODETYPE& value) {
      ListNode<NODETYPE>* newPtr{getNewNode(value)}; // new node

      if (isEmpty()) { // List is empty
         firstPtr = lastPtr = newPtr; // new list has only one node
      } 
      else { // List is not empty
         lastPtr->nextPtr = newPtr; // update previous last node
         lastPtr = newPtr; // new last node
      } 
   } 

   // delete node from front of list
   bool removeFromFront(NODETYPE& value) {
      if (isEmpty()) { // List is empty
         return false; // delete unsuccessful
      } 
      else {
         ListNode<NODETYPE>* tempPtr{firstPtr}; // hold item to delete

         if (firstPtr == lastPtr) {
            firstPtr = lastPtr = nullptr; // no nodes remain after removal
         } 
         else {
            firstPtr = firstPtr->nextPtr; // point to previous 2nd node
         } 

         value = tempPtr->data; // return data being removed
         delete tempPtr; // reclaim previous front node
         return true; // delete successful
      } 
   } 

   // delete node from back of list

   bool removeFromBack(NODETYPE& value) {
      if (isEmpty()) { // List is empty
         return false; // delete unsuccessful
      } 
      else {
         ListNode<NODETYPE>* tempPtr{lastPtr}; // hold item to delete

         if (firstPtr == lastPtr) { // List has one element
            firstPtr = lastPtr = nullptr; // no nodes remain after removal
         }
         else {
            ListNode<NODETYPE>* currentPtr{firstPtr};

            // locate second-to-last element            
            while (currentPtr->nextPtr != lastPtr) {   
               currentPtr = currentPtr->nextPtr; // move to next node
            }

            lastPtr = currentPtr; // remove last node
            currentPtr->nextPtr = nullptr; // this is now the last node
         } 

         value = tempPtr->data; // return value from old last node
         delete tempPtr; // reclaim former last node
         return true; // delete successful
      } 
   } 

   // is List empty?

   bool isEmpty() const {
      return firstPtr == nullptr; 
   } 

   // display contents of List
   void print() const {
      if (isEmpty()) { // List is empty
         std::cout << "The list is empty\n\n";
         return;
      } 

      ListNode<NODETYPE>* currentPtr{firstPtr};

      std::cout << "The list is: ";

      while (currentPtr != nullptr) { // get element data
         std::cout << currentPtr->data << ' ';
         currentPtr = currentPtr->nextPtr;
      } 

      std::cout << "\n\n";
   }
   // concatenate function, appends the second list to the first at the end.
   void concatenate(List<NODETYPE>& argumentList) {
    if (argumentList.isEmpty()){
        return; //scenario where the second list is empty
        }
    if (isEmpty()){
        firstPtr = argumentList.firstPtr;
        lastPtr  = argumentList.lastPtr; // scenario where the first list is empty
        }
    else{
        lastPtr->nextPtr = argumentList.firstPtr;
        lastPtr = argumentList.lastPtr; //both lists are not empty
        }
    argumentList.firstPtr=nullptr;
    argumentList.lastPtr=nullptr;
   }

private:
   ListNode<NODETYPE>* firstPtr{nullptr}; // pointer to first node
   ListNode<NODETYPE>* lastPtr{nullptr}; // pointer to last node  

   // utility function to allocate new node
   ListNode<NODETYPE>* getNewNode(const NODETYPE& value) {
      return new ListNode<NODETYPE>{value};
   } 
}; 

#endif


