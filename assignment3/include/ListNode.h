//==============================================================
// Filename    : ListNode.h    
// Authors     : Srikrishnan Srinivasan (s3603288), Raghavendran Srinivasan (s3656721)
// Group       : Group 16
// License     : N.A. or opensource license like LGPL
// Description : Defines the List structure, taken from the template function of ListNode.h as provided.
//==============================================================

#ifndef LISTNODE_H
#define LISTNODE_H

// forward declaration of class List required to announce that class 
// List exists so it can be used in the friend declaration at line 12
template<typename NODETYPE> class List;                            

template<typename NODETYPE> 
class ListNode {
   friend class List<NODETYPE>; // make List a friend

public:
    // constructor
    explicit ListNode(const NODETYPE& info) 
      : data{info}, nextPtr{nullptr} {   
          // empty body
    } // end ListNode constructor

    // return copy of data in node
   NODETYPE getData() const {return data;} 
   
private:
   NODETYPE data; // data
   ListNode<NODETYPE>* nextPtr; // pointer to next node in list
   
};    // end class ListNode

#endif


