/*
Class: CPSC 122-01
Paul De Palma
GU Username: depalma
Example: ex10.cpp
Selection sort
*/

#include <iostream>
#include <cstdlib>
using namespace std;

void getStuff(int[],int,int);
void displayStuff(int[],int);

void sort(int[], int);
int findLargest(int[],int,int);
void swap(int[],int,int);


int main()
{
  const int NUM = 15;  //number of items in the array
  const int LARGE = 100; //largest item in the array
  int stuff[NUM];

  getStuff(stuff, NUM, LARGE);

  cout << "Unsorted" << endl;
  displayStuff(stuff,NUM);
  cout << endl;

  sort(stuff,NUM);

  cout << "Sorted" << endl;
  displayStuff(stuff,NUM);

  return 0;
}

/*
Pre: stuff is an array of integers; size is its length;  
Post: stuff contains pseudo randomly generated integers <= LARGEST 
*/
void getStuff(int stuff[], int size, int largest)
{
 srand(time(NULL));
 for (int i = 0; i < size; i++)
   stuff[i] = rand() % (largest + 1);
}

/*
Pre: stuff is an array of integers; size is its length 
Post: each item from stuff is displayed on the screen 
*/
void displayStuff(int stuff[], int size)
{
 for (int i = 0; i < size; i++)
   cout << stuff[i] << endl; 
}
 
/*
Pre: stuff is an array of ints; size is its length 
Post: items in stuff are in sorted order 
Notice: for loop executes size - 1 times 
*/
void sort(int stuff[], int size)
{
 for (int cur = 0; cur < size - 1; cur++) 
  {
   int largest = findLargest(stuff, cur, size);
   swap(stuff, largest, cur);
  }
}

/*
Pre: stuff is an array of ints. start is where the search starts from.
     size is the size of the array;
Post: Returns the index of the smallest item in the array after start
Notice: For loop executes one less time on each pass 
        Initially it executes size - 1 times
	So the sequence is: (size-1), (size-2), ..., 1 because it is called
	size - 1 times
Notice Further: This is linear search
*/
int findLargest(int stuff[], int start, int size)
{

 int idxLarge = start; 
 for (int i = start + 1; i < size; i++)
  if (stuff[i] > stuff[idxLarge])
      idxLarge = i;

 return idxLarge;
}

/*
Pre: Stuff is an array of ints; 0 <= a, b < size of array
Post: Array element indexed by a is exchanged with array element indexed by b
*/
void swap(int stuff[], int a, int b)
{
 int spare;
 spare = stuff[a];
 stuff[a] = stuff[b];
 stuff[b] = spare;
}
