#include <iostream>
#include <stdlib.h>
using namespace std;

/*
pre:   str is a character array. When full it will be terminated by the
       null character.
post:  returns the position of target in str, -1 otherwise.
rules: find searches str recursively
usage: ./a.out thesearethedays d
where: "thesearethedays" is the string to be searched, 'd' is the target
hint:  find is linear search on a C-string instead of an array
*/
bool find(char* str, char target);

int main(int argc, char* argv[])
{

 char* str = argv[1];   //string to be searched
 char target = argv[2][0]; //target

 cout << find(str,target) << endl;

}
bool find(char* str, char target)
{
 if(*str == '\0')
  return false;
 if(*str == target)
  return true;
 find(++str,target);
}  
