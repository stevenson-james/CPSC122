//Stack implemented using a List and inheritance
#ifndef STACK_H
#define STACK_H
 
#include "List.h"

class Stack : public List 
{
  public:
   Stack();
 
   //copy constructor
   Stack(Stack* stk);

   /*
   pre: an instance of stack exists
   post: newItem is at the top of the stack 
   */
   void Push(itemType newItem);

   /*
   pre: an instance of stack exists and is not empty
   post: top of the stack has been removed 
   */
   void Pop();

   /*
   pre: an instance of stack exists and is not empty
   post: returns the top of the stack. stack is undisturbed 
   */
   itemType Peek();

   /*
   pre: an instance of stack exists
   post: returns true if the stack is empty, false otherwise 
   */
   bool IsEmpty();

   /*
   pre: an instance of stack exists
   post: displays items in the stack beginning with the head 
   */
   void Print();
};
#endif

