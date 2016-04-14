#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "symtab.h"
#include "message.h"

// The Declarator's Derived Types Tags for each node in the tree
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
	UNARY_TILDE,		//~ idk what the heck this does
	UNARY_INCREMENT,	//i++ or ++i
	UNARY_DECREMENT,	//i-- or --i
	
	UNARY_NOT,			//!true
	
	UNARY_ASSIGNMENT,	// a = EXPR

	UNARY_DOT,			//a.b()
	UNARY_PTR_OP,		//a->b()

	UNARY_CAST,			// (double) x

	//Might not be needed
	UNARY_PAREN,		// (a)
	UNARY_BRACKETS		//a[10]
} OP_UNARY;

typedef enum
{
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
			ST_ID id;
			PARAM_LIST pl;
		} func;
	} u;
} EXPR_NODE, *EN;

/***************** Create Functions ***************/
EN createConstantIntExpression(const int val);

EN createConstantDoubleExpression(const double val);

EN createVariableExpression(ST_ID varStID);

EN createFunctionExpression(ST_ID funStID, PARAM_LIST pl);

EN createUnaryExpression(OP_UNARY op, EN operand, BOOLEAN prefix);

EN createBinaryExpression(OP_BINARY op, EN left, EN right);
/***************** Create Functions ***************/

#endif