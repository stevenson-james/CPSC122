#include <iostream>
using namespace std;

#include "ques1.h"

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
 node* cur = head;
 head = head->next;
 delete cur;
 cur = NULL;
 --length;
}
	
void List::Print()
{
 node* cur = head;
 cout << cur->item << endl;
 while(cur->next)
  {
   cur = cur->next;
   cout << cur->item << endl;
  }
}

void List::PrintR()
{
 node* cur = head;
 Print_R(cur);
}

void List::Print_R(node* cur)
{
 cout << cur->item << endl;
 if (cur->next == '\0')
  return;
 Print_R(cur->next);
}
