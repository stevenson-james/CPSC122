//A list with a tail pointer, the capacity to manipulate arbitrary nodes,
//and a copy constructor

#ifndef LIST_H
#define LIST_H

typedef int itemType;

struct node
{
 itemType item;
 node* next;
};

class ListT
{
 public:
   ListT();

   /*
   use: copies listIn to the list being created
   pre: an instance of listIn exists
   post: the list created with the constructor contains the contents of
         listIn
   */
   ListT(ListT* lst);

   ~ListT();

   /*
   use: reports on the empty status of a list 
   pre: an instance of lists exists
   post: returns true if list is empty, false otherwise
   */ 
   bool IsEmpty();

   /*
   use: reports the length of a list
   pre: an instance of list exists
   post: returns length of the list 
   */
   int GetLength();

   /*
   use: adds an item to the head of the list
   pre: an instance of list exists
   post: newItem is at the head of the list 
   */
   void PutItemH(itemType newItem);

   /*
   use: reports the contents of the head of the list 
   pre: an instance of list exists and is not empty
   post: Returns the contents of the head of the list. 
   */
   itemType GetItemH();

   /*
   use: deletes the head of the list 
   pre: an instance of list exists and is not empty
   post: head of the list is deleted 
   */
   void DeleteItemH();

   /*
   use: adds an item to the tail of the list
   pre: an instance of list exists
   post: newItem is at the tail of the list 
   */
   void PutItemT(itemType newItem);

   /*
   use: reports the contents of the tail of the list 
   pre: an instance of list exists and is not empty
   post: Returns the contents of the tail of the list. 
   */
   itemType GetItemT();

   /*
   use: deletes the tail of the list 
   pre: an instance of list exists and is not empty
   post: tail of the list is deleted 
   */
   void DeleteItemT();

   /*
   use: displays the contents of the list on the screen 
   pre: an instance of list exists and is not empty
   post: contents of list nodes are displayed on subsequent lines 
   */
   void Print();

   /*
   use: Reverses a list.  A list that contains A B C will
        now contain C B A 
   pre: an instance of list exists and is not empty
   post: nodes in the list are reversed 
   */
   void Reverse();


 private:
   /*
   use: finds the address of an arbitratry node.  Use it with DeleteItem
        and PutItem
   pre: an instance of list exists, pos > 0
   post: Returns the address of the node in position pos  
   */
   node* ptrTo(int pos); 

   int length; //length of the list
   node* head; //points to the first node on the list 
   node* tail; //points to the last node on the list
};
#endif

