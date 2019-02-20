#ifndef PTQUEUE_H
#define PTQUEUE_H

#include "ListT.h"

class PTQueue : public ListT
{
 public:
   PTQueue();

   /*
   pre:  que is a pointer to an existing priority queue
   post: the current queue (self) is a copy of what que points to
   */
   PTQueue(PTQueue* que);

   ~PTQueue();

   /*
   pre: an instance of PTQueue exists 
   post: newItem is placed at its priority position within the queue. Priority is 
         indicated by the value of item within the struct itemType newItem; 
   */
   void Enqueue(itemType newItem);

   /*
   pre: an instance of PTQueue exists and is not empty
   post: item removed from the head of the queue and returned
   */
   itemType Dequeue();

   /*
   pre:  an instance of PTQueue exists and is not empty
   post: returns item at the head of the queue.  The queue is unchanged
   */
   itemType LookH();

   /*
   pre: an instance of PT exists and is not empty
   post: returns item at the tail of the queue.  The queue is unchanged
   */
   itemType LookT();

 private:
  
  node* ptrTo(itemType num);
};
#endif

