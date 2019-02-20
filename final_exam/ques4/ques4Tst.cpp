#include <iostream>
using namespace std;

#include "ques4.h"

int main()
{
 Stack* stk = new Stack;

 cout << "push 0 through 4 on the stack" << endl;
 for (int i = 0; i < 5; i++)
   stk->Push(i);

 cout << "print old stack" << endl;
 stk->Print();

 Stack* stk1 = new Stack(stk);
 stk1->Pop();
 cout << "print new stack" << endl;
 stk1->Print();

 cout << "length of new stack" << endl;
 cout << stk1->HowMany() << endl;

 delete stk;
 delete stk1;
 return 0;

}
