
#include <iostream>
using namespace std;

#include "List.h"

List::List(List* lst)
{
 length = lst->length;
 node* newLst;  //pointer to the current item in the new list 
 node* origLst = lst->head; //pointer to the current item in the original list
 if (origLst != NULL)
  {
   head = new node; //set head pointer of the the new list
   newLst = head;
  }
 else
  head = NULL;

 //traverse the original, copying each node to the new list
 while (origLst != NULL)
  {
   newLst->item = origLst->item;
   if (origLst->next == NULL)  //at end of original list
     {
      newLst->next = NULL;
      origLst = NULL;
     }
   else    //more to do
   {
    origLst=origLst->next;  
    newLst->next = new node;
    newLst = newLst->next;
   }
  }
}
   
List::List()
{
 length = 0;
 head = NULL;
}

List::~List()
{
 while(length > 0)
   DeleteItemH();
}

bool List::IsEmpty()
{
 if (length == 0)
   return true;
 return false; 
}


int List::GetLength()
{
 return length;
}

void List::PutItemH(itemType newItem)
{ 
 node* cur = new node;
 cur->item = newItem;
 cur->next = head;
 head = cur;
 cur = NULL;
 length++;
}

itemType List::GetItemH()
{
  return head->item;
}

void List::DeleteItemH()
{
 node* cur;

 cur = head;
 head = cur->next;
 cur->next = NULL;
 length--;

 delete cur;
 cur = NULL;
}
	
void List::Print()
{
 node* cur = head;
 while (cur != NULL)
  {
   cout << cur->item << endl;
   cur = cur->next;
  }
}  

