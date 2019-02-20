//Stack using List and composition 
#include <iostream>
using namespace std;
#include "ques4.h"

Stack::Stack()
{
 lst = new List;
}

Stack::Stack(Stack* stk)
{
 //stk->lst is the underlying list for the argument)
 lst = new List(stk->lst);
}

Stack::~Stack()
{
 cout << "starting destructor for stack" << endl;
 delete lst;
}

bool Stack::IsEmpty()
{
 if (lst->IsEmpty()) 
    return true;
 return false;
}

void Stack::Push(itemType newItem)
{ 
 lst->PutItemH(newItem);
}

void Stack::Pop()
{
 lst->DeleteItemH();
}

itemType Stack::Peek()
{
 return lst->GetItemH(); 
}
	
void Stack::Print()
{
  lst->Print();
}

int Stack::HowMany()
{
  lst->GetLength();
}
