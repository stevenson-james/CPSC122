/*
Class: CPSC 122-01
James Stevenson and Cade Newell
GU Username: jstevenson4 cnewell
Assignment: asgn4.cpp
struct List
*/

#include <iostream>
using namespace std;

#include "asgn4.h"

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

 delete cur;
 cur = NULL;
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

