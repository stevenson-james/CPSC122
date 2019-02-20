/*
Class: CPSC 122-01
James Stevenson
GU Username: jstevenson4
Assignment: asgn8.cpp
Calculator
*/

#include <iostream>
#include <string.h>
using namespace std;
#include "Calc.h"

Calculator::Calculator(char* inFixIn)
{
 numVariables = 0;
 
 inFix = new char[strlen(inFixIn) + 1];
 strcpy(inFix, inFixIn);
 postFix = NULL; 
}

Calculator::~Calculator()
{
 delete [] inFix;
 delete [] postFix;
}

void Calculator::DisplayInFix()
{
 cout << inFix << endl;
}

bool Calculator::CheckTokens()
{
 int i = 0;
 numVariables = 0;
 while (inFix[i] != NULL)
 {
  if (isBadToken(inFix[i]))
   return false;
  i++;
  if (isupper(inFix[i]))
   numVariables++;
 }
 return true;
}

bool Calculator::CheckParens()
{
 Stack stk;
 int i = 0;
 if (inFix[0] != '(')
 {
  cout << "No starting parenthesis" << endl;
  return false;
 }
 while (inFix[i] != NULL)
 {
  if (inFix[i] == '(')
   stk.Push(inFix[i]);
  if (inFix[i] == ')')
  {
   if (stk.IsEmpty())
   {
    cout << "You've got too many ')'" << endl;
    return false;
   }
   stk.Pop();
  }
  i++;
 }
 if (stk.IsEmpty())
  return true;
 cout << "You've got too many '('" << endl;
 return false;
}

bool Calculator::isNotParens(char cur)
{
 if (cur == '(' || cur == ')')
  return false;
 return true;
}

bool Calculator::isNotOperator(char cur)
{
 if (cur == '+' || cur == '-' || cur == '*' || cur == '/')
  return false;
 return true;
}

bool Calculator::isBadToken(char cur)
{
 if (!isupper(cur) && isNotParens(cur) && isNotOperator(cur))
   return true;
 return false;
}
