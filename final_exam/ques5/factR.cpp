#include <iostream>
#include <cstdlib>
using namespace std;

int factR(int);

int main(int argc, char* argv[])
{
 int num = atoi(argv[1]);

 cout << factR(num) << endl;
}

int factR(int num)
{
 cout << num << endl;
 if (num == 0) 
  return 1; 
 return (num * (factR(num - 1)));
}
