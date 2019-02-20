#include <iostream>
using namespace std;

#include "ques1.h"

void staticList();
void dynamicList();
void recursive_print();

int main()
{

 //staticList();
 //dynamicList(); 
 recursive_print();
 return 0;
}

void staticList()
{ 

 List lst; 

 cout << "insert 0 through 4 on the list" << endl;
 for (int i = 0; i < 5; i++)
   lst.PutItemH(i);
 cout << "Print the items in the list" << endl; 
 lst.Print();

 cout << "Get and display the head of the list" << endl;
 itemType item = lst.GetItemH();
 cout << item << endl; 

 cout << "Delete the head of the list and print the the new list" << endl;
 lst.DeleteItemH();
 lst.Print();
}


void dynamicList()
{
 List* lst = new List;

 cout << "insert 0 through 4 on the list" << endl;
 for (int i = 0; i < 5; i++)
   lst->PutItemH(i);

 cout << "Print the items in the list" << endl; 
 lst->Print();

 cout << "Get and display the head of the list" << endl;
 itemType item = lst->GetItemH();
 cout << item << endl; 

 cout << "Delete the head of the list and print the the new list" << endl;
 lst->DeleteItemH();
 lst->Print();

 delete lst;
}

void recursive_print()
{
 List* lst = new List;
 cout << "insert 0 through 4 on the list" << endl;
 for (int i = 0; i < 5; i++)
   lst->PutItemH(i);

 cout << "Print the items in the list recursively" << endl; 
 lst->PrintR();
}
