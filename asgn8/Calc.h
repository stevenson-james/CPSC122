/*
Class: CPSC 122-01
James Stevenson
GU Username: jstevenson4
Assignment: asgn8.cpp
Calculator
*/

#ifndef CALC_H
#define CALC_H

struct symbols
{
 char symbolName;
 int symbolValue;
};


#include "Stack.h"
class Calculator 
{ 
  public: 
  /* 
  pre: inFixIn is a pointer to a null-terminated string
  post: dynamically allocated array pointed to by inFix is created. array 
        pointed to by inFixIn is copied to inFix.  
        The other member variables are set to NULL or 0 as appropriate.
  */
  Calculator(char* inFixIn);

  ~Calculator();

  /*
  pre:  instance of calculator exists
  post: return true if all characters in the infix expression are legal,
        false otherwise  Legal characters are ')', '(', '+','-','*','/',
        'A' ... 'Z'   
  */
  bool CheckTokens(); 

  /*
   pre:  instance of calculator exists and all input tokens are legal
   post: Using the technique discussed in class, returns true if parentheses
         are balanced, false otherwise 
  */
  bool CheckParens();
  
 /*
  pre:  instance of calculator exists and parens are balanced
  post: using the technique discussed in class, transforms the infix
	expression to postfix and copies it to a dynamically
	allocated array pointed to by the private variable postFix.
 */
 void Infix_To_Postfix();

 /*
  pre: instance of calculator exists. 
  post: displays the infix expression
 */
  void DisplayInFix();
 
 /*
  pre: instance of calculator exists and a postfix expression has been
       generated
  post: displays the postfix expression
 */
  void DisplayPostFix();

 /*
  pre: instance of calculator exists
  post:symbol talbe is created and loade with values. See assignment
       instructions 
 */
  void MakeSymbolTable();

 /*
  pre: instance of calculator exists. Symbol table has been loades
  post: returns the value of the input expression using the values
        stored in the symbol table
 */
  void EvalPostFix();

 private:
  int numVariables; //the number of variables in the expression.  
  char*  inFix;     //pointer to null-terminated string that holds the infix 
                    //  expression 
  char*  postFix;   //pointer to null-terminated string that holds the 
                    // postfix expression.

  symbols* vars;  //Smbol table. vars is a pointer to an array of structs.
                  //There are as many positions as there are varibles
  bool isNotParens(char cur); //true if there is not a parenthesis
  bool isNotOperator(char cur); //true if there is not an operator
  bool isBadToken(char cur); //true if is not correct token
};
#endif 
