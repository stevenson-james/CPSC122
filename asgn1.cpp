/*
CPSC 122
James Stevenson
jstevenson4
Assignment 1
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int SIZE = 25;

ifstream gfopen(string);
void loadArray(int[], ifstream&);
int binSrch(int[], int);

int main (int argc, char* argv[])
{
 string filename;
 ifstream fin;
 int data[SIZE];
 int target = atoi(argv[1]);
 filename = argv[2];
 fin = gfopen(filename);

 loadArray(data, fin);

 fin.close();

 int pos = binSrch(data, target);
 cout << pos << endl;
 return 0;
}

 /* 
pre: fileName is the name of an input file
post: opens input file
*/ 

ifstream gfopen(string fileName)
{
 ifstream fileIn;
 fileIn.open(fileName);
 if (fileIn)
  return fileIn;
 cout << "Error opening input file: " << fileName << endl;
 exit(EXIT_FAILURE);
}

/*
pre: fin contains integers; data is an integer array
post: places integers from fin into data
*/

void loadArray(int data[], ifstream& fin)
{
 int num;
 for (int i = 0; i < 25; i++)
  fin >> data[i];
}

/*
pre: data[] contains ints [0,SIZE]; target is target number
post: if target is in domain [0,SIZE] return position of target,
else return -1
*/

int binSrch(int data[], int target)
{
 int i = SIZE / 2;
 int l = 0;
 int r = SIZE;
 if (target < SIZE && target >= 0)
 {
  while (i >= 0)
  {
   if (data[i] == target)
    return i;
   else if (data[i] < target)
   {
    l = i;
    i = (r + i) / 2;
   }
   else
   {
    r = i;
    i = (l + i) / 2;
   }
  }
 }
 return -1;
}
