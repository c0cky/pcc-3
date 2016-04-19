#ifndef EXPR_H
#define EXPR_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "symtab.h"
#include "message.h"
#include "backend-x86.h"

// All the expression types we can have
typedef enum 
{
	//All Expressions get typecasted to int or double
	TAG_CONST_INTEGER,
	TAG_CONST_DOUBLE,

	TAG_FUNCTION,		//Function Call f(3) returns 5
	TAG_VARIABLE,

	TAG_UNARY,
	TAG_BINARY
} EXPR_TAG;

typedef enum
{
	UNARY_DEREF, 		//*ptr
	UNARY_REF,			//&identifier
	UNARY_PLUS,			//+3
	UNARY_MINUS,		//-1
	UNARY_TILDE,		//~ bitwise not
	UNARY_INCREMENT,	//i++ or ++i
	UNARY_DECREMENT,	//i-- or --i
	
	UNARY_NOT,			//!true

	UNARY_DOT,			//a.b()
	UNARY_PTR_OP,		//a->b()

	UNARY_CAST,			// (double) x

	//Might not be needed
	UNARY_PAREN,		// (a)
	UNARY_BRACKETS		//a[10]
} OP_UNARY;

typedef enum
{
	BINARY_ASSIGNMENT,	
					// a = EXPR

	BINARY_MULT, 	// a * b
	BINARY_DIV,		// a / b
	BINARY_MOD,		// a % b

	BINARY_ADD,		// a + b
	BINARY_SUB,		// a - b
	
	BINARY_SHIFTL,	// a << b
	BINARY_SHIFTR,	// a >> b
	
	//Boolean Comparators
	BINARY_LT,		// a < b
	BINARY_GRT,		// a > b
	BINARY_LTE,		// a <= b
	BINARY_GRTE, 	// a >= b
	BINARY_EQUALS,	// a == b
	BINARY_NE,		// a != b

	BINARY_AND,		// a && b
	BINARY_OR,		// a || b
	BINARY_TERNARY,	// a ? a1 : a2, Technically not a binary op, will we use?
	//End Boolean Comparators

	BINARY_XAND,	// a & b
	BINARY_XOR,		// a | b
	BINARY_XNOT		// a ^ b
} OP_BINARY;

// A tree node to hold and build the proper derived types of the declarator given
typedef struct en 
{
	EXPR_TAG tag;	//Tag of the Union
	BOOLEAN isDouble; // A tag to know if node is a Double
	union
	{
		//Constants
		int valInt;
		double valDouble;

		ST_ID varStID;	//Used for variables

		//Unary Operators
		struct
		{
			OP_UNARY op;

			//if true, prefix operator, otherwise postfix operator
			BOOLEAN prefix;

			struct en* operand;
		} unop;

		//Binary Operators
		struct
		{
			OP_BINARY op;

			//leftOperand OPERATOR rightOperand
			struct en* leftOperand;
			struct en* rightOperand;
		} binop;

		 //For Functions: TODO:
		struct 
		{
			struct en* func_node;
			struct al* arg_list;
		} func;
	} u;
} EXPR_NODE, *EN;

// Aaron Add
typedef struct al 
{
	int size;
	struct en* arg;
	struct al* prev;
	struct al* next;
} ARG_LIST, *AL;
/***************** Create Functions ***************/
EN createConstantIntExpression(const int val);

EN createConstantDoubleExpression(const double val);

EN createVariableExpression(ST_ID varStID);

// AARON Change parameters of function to EN nodes
// orig: EN createFunctionExpression(ST_ID, PARAM_LIST pl);
EN createFunctionExpression(EN node, AL arg_l);

EN createUnaryExpression(OP_UNARY op, EN operand, BOOLEAN prefix);

EN createBinaryExpression(OP_BINARY op, EN left, EN right);
/***************** Create Functions ***************/

/***************** Eval Expressions ***************/

//Main Evaluation Function
EN evaluateExpression(EN expr);

//Helper Evaluating Functions
int evalIntExpression(EN node);
double evalDoubleExpression(EN node);
//Return an EN that holds the Integer or Double from the variable's value.
EN evalVariableExpression(EN node);
EN evalFunctionExpression(EN node);
EN evalUnaryExpression(EN node);
EN evalBinaryExpression(EN node);

ST_ID getIDFromVariableExpression(EN node);

//Returns the casted int from the integer or double part of the expression
int getIntFromExpression(EN node);
//Returns the casted double from the integer or double part of the expression
double getDoubleFromExpression(EN node);
/***************** Eval Expressions ***************/


//Returns true if this expression is a constant integer expression
BOOLEAN isIntExpression(EN node);

//Returns true if this expression is a constant double expression
BOOLEAN isDoubleExpression(EN node);

//Returns true if this expression is a variable expression
BOOLEAN isVariableExpression(EN node);

void printExpression(EN node);
void evalArgList(AL arg_list);
AL buildArg(EN node);
AL linkArgList(AL current, AL new_al);
TYPETAG getTypeTagFromExpression(EN node);
TYPETAG ifDouble(BOOLEAN b);
#endif
