/*
Class: CPSC 122-01
James Stevenson
GU Username: jstevenson4
Assignment: asgn5.cpp
class List
*/


#include <iostream>
using namespace std;

#include "asgn5.h"

List::List()
{
 length = 0;
 head = NULL;
 tail = NULL;
}

List::List(List* lst)
{
 length = lst->length;
 head = NULL;
 tail = NULL;
 if (length > 0)
 {
   node* source = lst->head;
   node* target = new node;
   head = target;
   while (source->next != NULL)
   {
     target->item = source->item;
     source = source->next;
     target->next = new node;
     target = target->next;
   }
   target->item = source->item;
   target->next = NULL;
 }
}

List::~List()
{
 while(length > 0)
   DeleteItemH();
}

bool List::IsEmpty()
{
 if(length == 0)
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
 if (length == 0)
   tail = cur;
 cur->item = newItem;
 cur->next = head;
 head = cur;
 length++;
 cur = NULL;
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
 if (length == 0)
   tail = NULL;
 delete cur;
 cur = NULL;
}

void List::PutItemT(itemType newItem)
{
 node* cur = new node;
 cur->item = newItem;
 cur->next = NULL;
 if (length == 0 )
   head = cur;
 else
   tail->next = cur;
 tail = cur;
 length++;
 cur = NULL;
}

itemType List::GetItemT()
{
 return tail->item;
}

void List::DeleteItemT()
{
 node* cur = tail;
 length--;
 delete cur;
 cur = NULL;
 tail = ptrTo(length);
 tail->next = NULL;
}

void List::PutItem(int pos, itemType newItem)
{
 if (pos > length + 1 || pos < 1)
 {
   cout << "invalid position, item not inserted" << endl;
   return;
 }

 node* cur = new node;
 cur->item = newItem;

 if (pos > 1)
 {
   node* prev = ptrTo(pos - 1);
   cur->next = prev->next;
   prev->next = cur;
   if (pos == length + 1)
     tail = cur;
 }
 else
 {
   cur->next = ptrTo(pos);
   head = cur;
 }

 length++;
}

itemType List::GetItem(int pos)
{
 node* cur = ptrTo(pos);
 return cur->item;
}

void List::DeleteItem(int pos)
{
 if (pos > length || pos < 1)
 {
   cout << "invalid position, item not deleted" << endl;
   return;
 }

 node* cur = ptrTo(pos);

 if (pos > 1)
 {
   node* prev = ptrTo(pos - 1);
   prev->next = cur->next;
   if (pos == length)
     tail = prev;
 }
 else
   head = cur->next;

 length--;
 delete cur;
 cur = NULL;
}

node* List::ptrTo(int pos)
{
 node* cur = head;

 if (pos > length || pos < 1)
 {
   cout << "position was bad, pointer is to NULL" << endl;
   return NULL;
 }

 for(int i = 1; i < pos; i++)
   cur = cur->next;
 return cur;
}

void List::Print()
{
 node* cur = head;
 for(int i = 0; i < length; i++)
 {
   cout << cur->item << endl;
   cur = cur->next;
 }
}
