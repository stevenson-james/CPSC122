/*
Class: CPSC 122-01
James Stevenson
GU Username: jstevenson4
Assignment: asgn7.cpp
Double List
*/

#include <iostream>
#include <climits>
using namespace std;

#include "asgn7.h"

   
DoubleList::DoubleList()
{
 length = 0;

 //dummy nodes are placed at head and tail
 //this makes writing list manipulaiton functions easier
 
 //create dummy nodes
 head = new doubleNode;
 tail = new doubleNode;

 //initialize head dummy node
 head->prev = NULL;
 head->item = 0; 
 head->next = tail;

 //initialize tail dummy node;
 tail->prev = head; 
 tail->item = 0; 
 tail->next = NULL;
}

bool DoubleList::IsEmpty()
{ 
 if (length == 0)
  return true;
 return false;
}

void DoubleList::PutItemH(itemType item)
{
 doubleNode* cur = new doubleNode;
 cur->prev = head;
 cur->item = item;
 cur->next = head->next;
 head->next->prev = cur;
 head->next = cur;
 length++;
}

bool DoubleList::PutItem(itemType item, int pos)
{
 if (pos < 0 || pos > length)
  return false;

 doubleNode* cur = new doubleNode;
 doubleNode* before = ptrTo(pos);
 cur->prev = before;
 cur->item = item;
 cur->next = before->next;
 before->next = cur;

 if (pos == length)
  tail->prev = cur;

 length++;

 return true;
}

bool DoubleList::GetItem(int pos,itemType& itemOut)
{
 if (pos < 0 || pos >= length)
  return false;
 itemOut = ptrTo(pos)->next->item;
 return true;
}

bool DoubleList::DeleteItem(int pos)
{
 if (pos < 0 || pos >= length)
  return false;

 doubleNode* cur = ptrTo(pos + 1);
 cur->prev->next = cur->next;
 cur->next->prev = cur->prev;
 length--;
 delete cur;
 cur = NULL;
 return true;
}

int DoubleList::FindItem(itemType item)
{
 doubleNode* cur = head->next;
 for(int i = 0; i < length; i++)
 {
  if (item == cur->item)
   return i;
  cur = cur->next;
 }
 return -1;
}

void DoubleList::PrintF()
{
 doubleNode* cur = head->next;
 for (int i = 0; i < length; i++)
 {
  cout << cur->item << endl;
  cur = cur->next;
 }
}

void DoubleList::PrintR()
{
 doubleNode* cur = tail->prev;
 for (int i = 0; i < length; i++)
 {
  cout << cur->item << endl;
  cur = cur->prev;
 }
}

//point to node before pos
doubleNode* DoubleList::ptrTo(int pos)
{
 doubleNode* cur = head;
 for (int i = 0; i < pos; i++)
  cur = cur->next;
 return cur;
}
