/*
Class: CPSC 122-01
James Stevenson
GU Username: jstevenson4
Assignment: asgn2.cpp
Selection sort
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

const int SIZE = 25;

ifstream gfopenIn(string);
ofstream gfopenOut(string);
void randomNums(ofstream&, int);
void loadArray(int[], ifstream&);
void sort (int[], string);
void sortAscending(int[]);
void sortDescending(int[]);
void swap(int& a, int& b);
void loadFile(int[], ofstream&);

int main (int argc, char* argv[])
{
 string fileName = argv[1];
 int limit = atoi(argv[2]);
 string mode = argv[3];
 int data[SIZE];

 ofstream fout = gfopenOut(fileName); 
 randomNums(fout, limit);
 fout.close();

 ifstream fin = gfopenIn(fileName);
 loadArray(data, fin);
 fin.close();
 
 sort(data, mode);
 fout = gfopenOut(fileName);
 loadFile(data, fout);
 fout.close();

 return 0;
}

/* 
pre: fileName is the name of an input file
post: opens input file
*/ 

ifstream gfopenIn(string fileName)
{
 ifstream fileIn;
 fileIn.open(fileName);
 if (fileIn)
  return fileIn;
 cout << "Error opening input file: " << fileName << endl;
 exit(EXIT_FAILURE);
}

/* 
pre: fileName is the name of an output file
post: opens output file
*/ 

ofstream gfopenOut(string fileName)
{
 ofstream fileOut;
 fileOut.open(fileName);
 if (fileOut)
  return fileOut;
 cout << "Error opening output file: " << fileName << endl;
 exit(EXIT_FAILURE);
}

/* 
pre: fout is an output file; limit is the max number
post: saves SIZE number of random integers [0, limit] to fout
*/ 

void randomNums(ofstream& fout, int limit)
{
 unsigned seed = time(0);
 srand(seed);
 for (int i = 0; i < SIZE; i++) 
   fout << rand() % (limit + 1) << endl;
}

/* 
pre: data[] is empty array; fin contains integers
post: moves integers from fin to data[]
*/ 

void loadArray(int data[], ifstream& fin)
{
 for (int i = 0; i < 25; i++)
  fin >> data[i];
}

/* 
pre: mode is either "a" or "d"; data[] contains integers
post: sorts data[] to be ascending or descending using selection sort
*/ 

void sort (int data[], string mode)
{
 if (mode == "a")
  sortAscending(data);
 if (mode == "d")
  sortDescending(data);
}

/* 
pre: data[] contains integers
post: uses selection sort to sort in ascending order
*/ 

void sortAscending(int data[])
{
 int min;
 for (int i = 0; i < SIZE - 1; i++) 
 {
  min = i;
  for (int j = i + 1; j < SIZE; j++) 
  {
   if (data[min] > data[j])
    min = j;
  }
  swap(data[min], data[i]);
 }
}

/* 
pre: data[] contains integers
post: uses selection sort to sort in descending order
*/ 

void sortDescending(int data[])
{
 int max;
 for (int i = 0; i < SIZE - 1; i++) 
 {
  max = i;
  for (int j = i + 1; j < SIZE; j++) 
  {
   if (data[max] < data[j])
    max = j;
  }
  swap(data[max], data[i]);
 }
}

/* 
pre: a and b are integers
post: a and b swap
*/ 

void swap(int& a, int& b)
{
 int temp = a;
 a = b;
 b = temp;
}

/* 
pre: data[] contains integers, sortedFile is an output file
post: copies data[] to sortedFile
*/ 

void loadFile(int data[], ofstream& fout)
{
 for (int i = 0; i < 25; i++)
  fout << data[i] << endl;
}
