#include <iostream>
#include <climits>
using namespace std;

#include "exam1.h"

Array::Array(itemType sizeIn)
{
 size = sizeIn;
 numItems = 0; 
 holder = new itemType[size]; 
 for (int i = 0; i < size; i++)
   holder[i] = INT_MIN; //initialize to minimum value an int can hold
}

bool Array::Insert(itemType item, int pos)
{
 if(pos < 0 || pos > size - 1)
  return false;
 if(pos >= numItems)
  numItems++;
 holder[pos] = item;
 return true;
}

void Array::Display()
{
 //possibly change numItems to size
 for(int i = 0; i < numItems; i++)
  cout << holder[i]<<endl;
}

bool Array::IsFull()
{
 if(numItems == size)
  return true;
 return false;
}

bool Array::IsIn(itemType item)
{
 for(int i = 0; i < numItems; i++)
  if(holder[i] == item)
   return true;
 return false;
}

bool Array::Get(int pos, itemType& item)
{
 if(pos < 0 || pos > size - 1)
  return false;
 item = holder[pos];
 return true;
}

void Array::Sort()
{
 for (int cur = 0; cur < size - 1; cur++) 
  {
   int smallest = FindSmallest(cur);
   Swap(smallest, cur);
  }
}

int Array::FindSmallest(int start)
{
 int smallest = start; 
 for (int i = start + 1; i < size; i++)
  if (holder[i] < holder[smallest])
   smallest = i;
 return smallest;
}

void Array::Swap(int a, int b)
{
 int spare;
 spare = holder[a];
 holder[a] = holder[b];
 holder[b] = spare;
}

