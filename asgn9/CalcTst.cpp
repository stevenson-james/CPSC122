#include <iostream>
using namespace std;

#include "Calc.h"

int main(int argc, char* argv[])
{
 Calculator myCalc(argv[1]);
 myCalc.DisplayInFix();
 if(myCalc.CheckTokens())
 {
  if(myCalc.CheckParens())
  {
   myCalc.Infix_To_Postfix();
   cout << "Postfix: " << endl;
   myCalc.DisplayPostFix();
   myCalc.MakeSymbolTable();
   myCalc.EvalPostFix();
  }
 }
}
