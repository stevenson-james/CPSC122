#include <iostream>
#include <string.h>
using namespace std;
#include "Queue.h"

Queue::Queue(int size_in)
{
 front = 0;
 back = -1;
 count = 0;
 size = size_in;
 stuff = new itemType[size];
}

Queue::~Queue()
{
 delete stuff;
}

void Queue::Enqueue(itemType newItem)
{
 back = (back + 1) % size;
 stuff[back] = newItem;
 count++;
}

void Queue::Dequeue()
{
 front = (front + 1) % size;
 count--;
}

itemType Queue::LookF()
{
 return stuff[front];
}

itemType Queue::LookB()
{
 return stuff[back];
}

bool Queue::IsFull()
{
 if(count == size)
  return true;
 return false;
}

void Queue::Print()
{
 for(int i = front; i <= back; i++)
  cout << stuff[i] << endl;
}
