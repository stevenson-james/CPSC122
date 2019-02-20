/*
Class: CPSC 122-01
James Stevenson
GU Username: jstevenson4
Assignment: PTQueue.cpp
Prioity Queue
*/

#include <iostream>
using namespace std;
#include "PTQueueInh.h"

PTQueue::PTQueue() : ListT()
{}

PTQueue::PTQueue(PTQueue* que) : ListT(que)
{}

PTQueue::~PTQueue()
{
 while(length > 0)
  DeleteItemH();
}

void PTQueue::Enqueue(itemType newItem)
{
 if (length == 0)
 {
  PutItemH(newItem);
  tail = head;
  return;
 }

 if (newItem <= head->item && length > 0)
 {
  node* cur = new node;
  cur->item = newItem;
  cur->next = head;
  head = cur;
  length++;
  return;
 }

 node* cur = ptrTo(newItem);
 node* fresh = new node;
 fresh->item = newItem;
 fresh->next = cur->next;
 cur->next = fresh;
 if (cur == tail)
  tail = fresh;
 length++;
}

itemType PTQueue::Dequeue()
{
 int i = GetItemH();
 DeleteItemH();
 return i;
}

itemType PTQueue::LookH()
{
 return GetItemH();
}

itemType PTQueue::LookT()
{
 return tail->item;
}

node* PTQueue::ptrTo(itemType num)
{
 node* cur = head;
 node* bigger = head->next;
 while (num > cur->item)
 {
  if (cur == tail)
   return cur;
  if (num < bigger->item)
   return cur;
  cur = cur->next;
  bigger = bigger->next;
 }
}

