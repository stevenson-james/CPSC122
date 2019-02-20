/*
Class: CPSC 122-01
James Stevenson
GU Username: jstevenson4
Assignment: asgn9.cpp
Calculator
*/

#include <iostream>
#include <string.h>
using namespace std;
#include "Calc.h"

Calculator::Calculator(char* inFixIn)
{
 numVariables = 0;
 numOperators = 0;
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
 while (inFix[i] != '\0')
 {
  if (isBadToken(inFix[i]))
   return false;
  i++;
  if (isupper(inFix[i]))
   numVariables++;
  if (!isNotOperator(inFix[i]))
   numOperators++;
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
 while (inFix[i] != '\0')
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

void Calculator::Infix_To_Postfix()
{
 postFix = new char[numVariables + numOperators + 1];
 Stack stk;
 int i = 0;
 int j = 0;
 char element;
 while (i < strlen(inFix))
 {
  if (inFix[i] == '(')
   stk.Push(inFix[i]);
  if (isupper(inFix[i]))
  {
   postFix[j] = inFix[i];
   j++;
  }
  if (!isNotOperator(inFix[i]))
   stk.Push(inFix[i]);
  if (inFix[i] == ')')
  {
   element = stk.Peek();
   while (element != '(')
   {
    stk.Pop();
    postFix[j] = element;
    element = stk.Peek();
    j++;
   }
   stk.Pop();
  }
  i++;
 }
 postFix[j] = '\0';
}

void Calculator::DisplayPostFix()
{
 cout << postFix << endl;
}

void Calculator::MakeSymbolTable()
{
 int j = 0;
 vars = new symbols[numVariables];
 for(int i = 0; postFix[i] != '\0'; i++)
 {
  if(isupper(postFix[i]))
  {
   symbols* cur = new symbols;
   cur->symbolName = postFix[i];
   cout << "Enter value for " << postFix[i] << endl;
   cin >> cur->symbolValue;
   vars[j] = *cur;
   j++;
  }
 }
}

void Calculator::EvalPostFix()
{
 Stack stk;
 int num1, num2, ans;
 for(int i = 0; postFix[i] != '\0'; i++)
 {
  if(isupper(postFix[i]))
   for(int j = 0; j < numVariables; j++)
   {
    if (postFix[i] == vars[j].symbolName)
    {
     stk.Push(vars[j].symbolValue);
    }
   }
  if(!isNotOperator(postFix[i]))
  {
   num1 = stk.Peek();
   stk.Pop();
   num2 = stk.Peek();
   stk.Pop();
   if(postFix[i] == '+')
    ans = num2 + num1;
   if(postFix[i] == '-')
    ans = num2 - num1;
   if(postFix[i] == '*')
    ans = num2 * num1;
   if(postFix[i] == '/')
    ans = num2 / num1;
   stk.Push(ans);
  }
 }
 ans = stk.Peek();
 stk.Pop();
 cout << "Answer is " << ans << endl;
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
