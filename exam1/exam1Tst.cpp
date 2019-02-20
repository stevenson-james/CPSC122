#include "exam1.h"
#include <iostream> 
#include <climits>
using namespace std;

int main()
{
 Array holder(10);
 int item;

 int j = 9;
 for(int i = 0; i <= 9; i++)
 {
  cout << "Insert return value: " << holder.Insert(j,i) << endl;
  j--;
 }

 holder.Display();

 cout << "IsFull return value: " << holder.IsFull() << endl;

 cout << "IsIn return value: " << holder.IsIn(0) << endl;

 cout << "Get return value: " << holder.Get(5, item) << endl;
 cout << "Value of item: " << item << endl;

 holder.Sort();
 holder.Display();

 return 0;
}
   
