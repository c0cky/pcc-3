#include "expr.h"

/***************** Create Functions ***************/
EN createConstantIntExpression(const int val)
{
	// fprintf(stderr, "Creating CONST: %ld\n", val);

	EN expression = malloc(sizeof(EN));

	expression->tag = TAG_CONST_INTEGER;
	expression->u.valInt = val;

	// fprintf(stderr, "Creating CONST: %ld\n", expression->u.valConst);

	return expression;
}

EN createConstantDoubleExpression(const double val)
{
	// fprintf(stderr, "Creating CONST: %ld\n", val);

	EN expression = malloc(sizeof(EN));

	expression->tag = TAG_CONST_DOUBLE;
	expression->u.valDouble = val;

	// fprintf(stderr, "Creating CONST: %ld\n", expression->u.valConst);

	return expression;
}

EN createVariableExpression(ST_ID varStID)
{
	// fprintf(stderr, "Creating variable: %c\n", variable);

	EN expression = malloc(sizeof(EN));

	expression->tag = TAG_VARIABLE;
	expression->u.varStID = varStID;

	return expression;
}

EN createFunctionExpression(ST_ID funStID, PARAM_LIST pl)
{
	// fprintf(stderr, "Creating variable: %c\n", variable);

	EN expression = malloc(sizeof(EN));

	expression->tag = TAG_FUNCTION;
	expression->u.func.id = funStID;
	expression->u.func.pl = pl;

	return expression;
}

EN createUnaryExpression(OP_UNARY op, EN operand, BOOLEAN prefix)
{
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
	EN expression = malloc(sizeof(EN));

	expression->tag = TAG_BINARY;
	expression->u.binop.op = op;
	expression->u.binop.leftOperand = left;
	expression->u.binop.rightOperand = right;

	return expression;
}
/***************** Create Functions ***************/