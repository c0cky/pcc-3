#include "expr.h"


/***************** Create Functions ***************/
EN createConstantIntExpression(const int val)
{
	msg("Creating const int expr: %d", val);

	EN expression = malloc(sizeof(EN));

	expression->tag = TAG_CONST_INTEGER;
	expression->u.valInt = val;

	return expression;
}

EN createConstantDoubleExpression(const double val)
{
	msg("Creating const double expr: %f", val);

	EN expression = malloc(sizeof(EN));

	expression->tag = TAG_CONST_DOUBLE;
	expression->u.valDouble = val;

	return expression;
}

EN createVariableExpression(ST_ID varStID)
{
	msg("Creating variable expr");

	EN expression = malloc(sizeof(EN));

	expression->tag = TAG_VARIABLE;
	expression->u.varStID = varStID;

	return expression;
}

EN createFunctionExpression(ST_ID funStID, PARAM_LIST pl)
{
	msg("Creating function expr");

	EN expression = malloc(sizeof(EN));

	expression->tag = TAG_FUNCTION;
	expression->u.func.id = funStID;
	expression->u.func.pl = pl;

	return expression;
}

EN createUnaryExpression(OP_UNARY op, EN operand, BOOLEAN prefix)
{
	msg("Creating unary expr");

	EN expression = malloc(sizeof(EN));

	expression->tag = TAG_UNARY;
	expression->u.unop.op = op;
	expression->u.unop.operand = operand;
	expression->u.unop.prefix = prefix;		//For prefix vs. postfix operators

	// fprintf(stderr, "Creating Unary: %ld\n", evalExpression(expression->u.unop.operand));

	return expression;
}

EN createBinaryExpression(OP_BINARY op, EN left, EN right)
{
	msg("Creating binary expr");

	EN expression = malloc(sizeof(EN));

	expression->tag = TAG_BINARY;
	expression->u.binop.op = op;
	expression->u.binop.leftOperand = left;
	expression->u.binop.rightOperand = right;

	return expression;
}
/***************** Create Functions ***************/

/***************** Eval Expressions ***************/
EN evaluateExpression(EN expr)
{
	//Expr should never be null.

	switch(expr->tag)
	{
		case TAG_CONST_INTEGER:
		case TAG_CONST_DOUBLE:
			return expr;

		case TAG_FUNCTION:
		//TODO:
			bug("haven't implemented function expressions yet");
			break;

		case TAG_VARIABLE:
			return evalVariableExpression(expr);

		case TAG_UNARY:
			return evalUnaryExpression(expr);
		
		case TAG_BINARY:
			return evalBinaryExpression(expr);

		default:
			bug("Where's the expression tag in evaluateExpression?");
	}
	//For Default
	return NULL;
}

int evalIntExpression(EN node)
{
	return node->u.valInt;
}

double evalDoubleExpression(EN node)
{
	return node->u.valDouble;
}

EN evalVariableExpression(EN node)
{
	//Returns the char* of the id
	char* identifier = st_get_id_str(node->u.varStID);
	msg("Evaluating Variable: %s", identifier);

	//TODO:
	// int block;
	// ST_DR dR = st_lookup(node->u.varStID, &block);



}

EN evalFunctionExpression(EN node)
{//TODO:
	return node;
}

EN evalUnaryExpression(EN node)
{
	EN returnedNode = NULL;

	EN expr = NULL;

	switch(node->u.unop.op)
	{
		//TODO:
		case UNARY_DEREF: 		//*ptr
			break;
		case UNARY_REF:			//&identifier
			break;

		case UNARY_PLUS:		//+3
			returnedNode = evaluateExpression(node);
			break;

		case UNARY_MINUS:		//-1
			expr = evaluateExpression(node->u.unop.operand);
			if(isIntExpression(expr) == TRUE)
			{
				expr->u.valInt = -1 * expr->u.valInt;
				returnedNode = expr;
			}
			else if(isDoubleExpression(expr) == TRUE)
			{
				expr->u.valDouble = -1 * expr->u.valDouble;
				returnedNode = expr;
			}
			else if(isVariableExpression(expr) == TRUE)
			{
				//TODO:
			}
			else
				error("Illegal Unary Minus in expression");
			break;

		//TODO:
		case UNARY_INCREMENT:	//i++ or ++i
			break;
		case UNARY_DECREMENT:	//i-- or --i
			break;
		
		case UNARY_NOT:			//!true
			break;

		case UNARY_TILDE:		//~ bitwise not
			break;
		case UNARY_DOT:			//a.b()
			break;
		case UNARY_PTR_OP:		//a->b()
			break;

		case UNARY_CAST:		// (double) x
			break;

		//Might not be needed
		case UNARY_PAREN:		// (a)
			break;
		case UNARY_BRACKETS:	//a[10]
			break;

		default:
			bug("Wheres the unary operator in the expression?");
	}
	
	return returnedNode;
}

EN evalBinaryExpression(EN node)
{
	switch(node->u.binop.op)
	{
		default:
			bug("Where the binary operator in the expression?");

	}

	return NULL;
}

ST_ID getIDFromVariableExpression(EN node)
{
	ST_ID id = NULL;

	if(isVariableExpression(node))
		id = node->u.varStID;

	return id;
}
/***************** Eval Expressions ***************/

BOOLEAN isIntExpression(EN node)
{
	if(node!=NULL && node->tag == TAG_CONST_INTEGER)
		return TRUE;
	return FALSE;
}

BOOLEAN isDoubleExpression(EN node)
{
	if(node!=NULL && node->tag == TAG_CONST_DOUBLE)
		return TRUE;
	return FALSE;
}

BOOLEAN isVariableExpression(EN node)
{
	if(node!=NULL && node->tag == TAG_VARIABLE)
		return TRUE;
	return FALSE;
}

void printExpression(EN node)
{
	switch(node->tag)
	{
		case TAG_CONST_INTEGER:
			msg("Integer Expression: %d", node->u.valInt);
			break;
		case TAG_CONST_DOUBLE:
			msg("Double Expression: %f", node->u.valDouble);
			break;

		case TAG_FUNCTION:
			msg("Function Expression");
			break;

		case TAG_VARIABLE:
			msg("Variable Expression");
			break;

		case TAG_UNARY:
			msg("Unary Expression");
			break;
		
		case TAG_BINARY:
			msg("Binary Expression");
			break;

		default:
			bug("Where's the expression tag in evaluateExpression?");
	}
}