#include <iostream>
using namespace std;

#include "ListT.h"


int main()
{
 ListT* list = new ListT();

 for (int i = 0; i < 5; i++)
   list->PutItemT(i);

 list->Print();
 cout << endl;
 list->Reverse();
 list->Print();

 return 0;
}
