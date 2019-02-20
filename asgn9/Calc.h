#ifndef CALC_H
#define CALC_H

//see MakeSymbolTable below
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
  post:symbol table is created and loaded with values.
  Use: This function is called after infix has been converted to postfix
  Create an array of structs of type pointer to symbols.  The size is the
  number of operands, i.e. numVariables.  Go through the postfix expression.
  Each time you find an operand, ask the user the value of that operand.
  Make an entry for the operand and the value in the symbol table.   
 */
  void MakeSymbolTable();

 /*
  pre: instance of calculator exists. Symbol table has been loaded
  post: returns the value of the input expression using the values
        stored in the symbol table
 */
  void EvalPostFix();

 private:
  int numVariables; //the number of variables in the expression. 
  int numOperators; //the number of operators in the expression. 
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
