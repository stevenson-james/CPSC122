#include <iostream>
#include <cstdlib>
using namespace std;

int fib(int);
int count = 0;
int main(int argc, char* argv[])
{
 int num = atoi(argv[1]);
 cout << fib(num) << endl;
 cout << count << endl;
 return 0;
}

int fib(int num)
{
 count++;
 if (num == 1 || num == 2)
    return 1;
 return (fib(num-2) + fib(num-1));
}
