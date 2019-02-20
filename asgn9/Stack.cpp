//Stack implemented using List and inheritance
#include <iostream>
using namespace std;

#include "Stack.h"

Stack::Stack() : List()
{}


Stack::Stack(Stack* stk): List(stk)
{}


void Stack::Push(itemType newItem)
{ 
 PutItemH(newItem);
}

void Stack::Pop()
{
 DeleteItemH();
}

itemType Stack::Peek()
{
 return GetItemH(); 
}

bool Stack::IsEmpty()
{
 return List::IsEmpty();
}

void Stack::Print()
{
 List::Print();
} 
