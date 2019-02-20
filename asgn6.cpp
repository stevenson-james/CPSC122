/*
Class: CPSC 122-01
James Stevenson
GU Username: jstevenson4
Assignment: asgn6.cpp
circular List
*/


#include <iostream>
using namespace std;

#include "asgn6.h"

List::List()
{
 length = 0;
 head = NULL;
}

List::List(List* lst)
{
 length = lst->length;
 head = NULL;
 if (length > 0)
 {
  node* source = lst->head;
  node* target = new node;
  head = target;
  int i = 0;
  for (int i = 0; i < length - 1; i++)
  {
   target->item = source->item;
   target->next = new node;
   source = source->next;
   target = target->next;
  }
  target->item = source->item;
  target->next = head;
 }
}

List::~List()
{
 while(length > 0)
 {
  node* cur = new node;
  cur = head;
  head = head->next;
  length--;
  delete cur;
  cur = NULL;
 }
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

void List::PutItem(itemType newItem)
{
 node* cur = new node;
 if (length > 0)
 {
  node* prev = ptrTo(newItem);
  if (prev->item > newItem)
   head = cur;
  cur->next = prev->next;
  cur->item = newItem;
  prev->next = cur;
 }
 else
 {
  head = cur;
  cur->item = newItem;
  cur->next = cur;
 }
 length++;
}

bool List::IsIn(itemType item)
{
 node* cur = head;
 for (int i = 0; i < length; i++)
 {
  if (cur->item == item)
   return true;
  cur = cur-> next;
 }
 return false;
}

void List::DeleteItem(itemType item)
{
 node* prev = head;
 node* cur = head;
 if (cur->item == item)
 {
  cout << "yup" << endl;
  for (int i = 0; i < length; i++)
  { 
   prev = cur;
   cur = cur->next;
  }
  prev->next = cur->next;
  head = cur->next;
  delete cur;
  cur = NULL;
 }
 else
 {
  for (int i = 0; i < length; i++)
  {
   prev = cur;
   cur = cur->next;
   if (cur->item == item)
   {
    prev->next = cur->next;
    delete cur;
    cur = NULL;
    break;
   }
  }
 }
 length--;
}

void List::Print(int pos, int num)
{
 node* cur = head;
 for (int i = 1; i < pos; i++)
  cur = cur->next;
 for (int i = 0; i < num; i++)
 {
  cout << cur->item << endl;
  cur = cur->next;
 }
}

void List::Print()
{
 node* cur = head;
 for (int i = 0; i < length; i++)
 {
  cout << cur->item << endl;
  cur = cur->next;
 }
}

void List::Reverse()
{
 node* prev;
 node* cur;
 node* last = head;
 for (int i = 1; i < length; i++)
  last = last->next;
 node* tolast = new node;
 tolast->next = last;
 last = NULL;

 int i = length;
 while (i != 1)
 {
  cur = head;
  for (int j = 1; j < i; j++)
  {
   prev = cur;
   cur = cur->next;
  }
  cur->next = prev;
  i--;
 }
 head->next = tolast->next;
 head = tolast->next;
}

node* List::ptrTo(itemType item)
{
 node* small = new node;
 node* big = head;
 if (length == 0)
  return head;

 if (head->item >= item)
 {
  for (int i = 0; i < length; i++)
  {
   small = big;
   big = big->next;
  }
 }

 for (int i = 0; i < length; i++)
 {
  if (big->item > item)
   return small;
  small = big;
  big = big->next;
 }
 return small;
}

