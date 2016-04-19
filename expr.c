#include "expr.h"


/***************** Create Functions ***************/
EN createConstantIntExpression(int val)
{
	//msg("Creating const int expr: %d", val);

	EN expression = (EN)malloc(sizeof(EXPR_NODE));

	expression->tag = TAG_CONST_INTEGER;
	expression->u.valInt = val;

	return expression;
}

EN createConstantDoubleExpression(const double val)
{
	//msg("Creating const double expr: %f", val);

	EN expression = (EN)malloc(sizeof(EXPR_NODE));

	expression->tag = TAG_CONST_DOUBLE;
	expression->u.valDouble = val;

	return expression;
}

EN createVariableExpression(ST_ID varStID)
{
	char* identifier = st_get_id_str(varStID);
	//msg("Creating variable expr %s", identifier);
	int b;
	EN expression = (EN)malloc(sizeof(EXPR_NODE));
	ST_DR stdr = st_lookup(varStID, &b);
	TYPETAG ty_tag = TYERROR;
	if(stdr != NULL)
		ty_tag = ty_query(stdr->u.decl.type);
	//msg("Creating variable expr %s", identifier);
	expression->tag = TAG_VARIABLE;
	if(ty_tag == TYFLOAT || ty_tag == TYDOUBLE)
		expression->isDouble = TRUE;
	else
		expression->isDouble = FALSE;
	expression->u.varStID = varStID;

	return expression;
}

EN createFunctionExpression(EN node, AL arg_l)
{
	//msg("Creating function expr");

	EN expression = (EN)malloc(sizeof(EXPR_NODE));

	expression->tag = TAG_FUNCTION;
	expression->u.func.func_node = node;

	expression->u.func.arg_list = arg_l;

	return expression;
}

EN createUnaryExpression(OP_UNARY op, EN operand, BOOLEAN prefix)
{
	//msg("Creating unary expr");

	EN expression = (EN)malloc(sizeof(EXPR_NODE));

	expression->tag = TAG_UNARY;
	expression->u.unop.op = op;
	expression->u.unop.operand = operand;
	expression->u.unop.prefix = prefix;		//For prefix vs. postfix operators

	// fprintf(stderr, "Creating Unary: %ld\n", evalExpression(expression->u.unop.operand));

	return expression;
}

EN createBinaryExpression(OP_BINARY op, EN left, EN right)
{
	//msg("Creating binary expr OP_BINARY: %d", op);

	EN expression = (EN)malloc(sizeof(EXPR_NODE));

	expression->tag = TAG_BINARY;
	expression->u.binop.op = op;
	expression->u.binop.leftOperand = left;
	expression->u.binop.rightOperand = right;
	//printExpression(left);
	//printExpression(right);
	return expression;
}
AL linkArgList(AL current, AL new_al)
{
	if(new_al == NULL)
	{
		return current;
	}
	else
	{
		while(current->next !=NULL)
			current = current->next;
		current->next = new_al;
		current->size = current->size + new_al->size;
		current->prev->size = current->size;
		new_al->size = current->size;
		new_al->prev = current->prev;
		return new_al->prev;
	}
}

AL buildArg(EN node)
{	
	AL new_al = (AL)malloc(sizeof(ARG_LIST));
	new_al->arg = node;
	new_al->prev = new_al;
	if(node->isDouble == TRUE)
		new_al->size = 8;
	else
		new_al->size = 4;
	return new_al;
}
/***************** Create Functions ***************/

/***************** Eval Expressions ***************/
EN evaluateExpression(EN expr)
{
	//Expr should never be null.

	switch(expr->tag)
	{
		case TAG_CONST_INTEGER:
			//evalIntExpression(expr);
			return expr;
		case TAG_CONST_DOUBLE:
			return expr;

		case TAG_FUNCTION:
		//TODO:	
			//msg("Begin Eval Function");
			//bug("haven't implemented function expressions yet");
			return evalFunctionExpression(expr);

		case TAG_VARIABLE:
		{
			return evalVariableExpression(expr);
		}
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
	//b_push_const_int(node->u.valInt);
	return node->u.valInt;
}

double evalDoubleExpression(EN node)
{
	return node->u.valDouble;
}

EN evalVariableExpression(EN node)
{
	//TODO:
	// int block;
	// ST_DR dR = st_lookup(node->u.varStID, &block);
	//Returns the char* of the id
	char* identifier = st_get_id_str(node->u.varStID);
	ST_DR stdr;
	int b;
	
	stdr = st_lookup(node->u.varStID, &b);
	if(b == 0) // Maybe change to Less than current block
	{	b_push_ext_addr(identifier); }
	else if(stdr)
		b_push_loc_addr(b_get_formal_param_offset(ty_query(stdr->u.decl.type))); // This is not returning the value of 8 for TYSIGNEDINT...?
	else
		error("'%s' is undefined", identifier);
	//msg("Evaluating Variable: %s", identifier);
	return node;


}
TYPETAG returnFuncTypeTag(EN node)
{
	TYPE type;
	int b;
	ST_ID stid = node->u.func.func_node->u.varStID;
	ST_DR stdr = st_lookup(stid, &b);
	PARAMSTYLE ps;
	PARAM_LIST pl;
	//ty_print_type(stdr->u.decl.type);
	if(stdr== NULL || stdr->u.decl.type == NULL) //	if(stdr->u.decl.type == NULL)
		{  error(" why null in returnFuncTypeTag return TYVOID"); 
		return TYVOID;	 }
	
	if (ty_query(stdr->u.decl.type) != TYFUNC)
	{
		error("duplicate or incompatible function declaration '%s'", st_get_id_str(stid));
		return TYVOID;
	}
	else
		{ type = ty_query_func(stdr->u.decl.type, &ps, &pl);
	
	return ty_query(type);}
}

EN evalFunctionExpression(EN node)
{//TODO:
	// get the char string from the node.
	AL arg_l;
	arg_l = node->u.func.arg_list;
	int b;
	char *f = st_get_id_str(node->u.func.func_node->u.varStID);
	//if(ty_query(st_lookup(node->u.func.func_node->u.varStID, &b)->u.decl.type) != TYFUNC)

	if(node->u.func.arg_list != NULL)
	{
		b_alloc_arglist (arg_l->size);
	}
	else
		b_alloc_arglist (0);				
	while(arg_l != NULL )
	{
		evalArgList(arg_l);
		arg_l = arg_l->next;
	}
				
	if(st_lookup(node->u.func.func_node->u.varStID, &b) != NULL )
		b_funcall_by_name(f, returnFuncTypeTag(node));
	else
		error("'%s' is undefined", f);
	return node;
}

void evalArgList(AL arg_list)
{
	EN node;
	int b;
	TYPETAG arg_typetag;
	if(arg_list != NULL)
		node = evaluateExpression(arg_list->arg);
	if(isVariableExpression(node))
	{
		arg_typetag = ty_query(st_lookup(node->u.varStID , &b)->u.decl.type);
		b_deref(arg_typetag);
	}
	else if(node->isDouble)
		arg_typetag = TYDOUBLE;
	else
		arg_typetag = TYSIGNEDINT;
	b_load_arg(arg_typetag);
	//	evalArgList(arg_list->next);
	 // what to do here? Can we return int for Size to allocate?
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
			returnedNode = evaluateExpression(node->u.unop.operand);
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
				b_negate(ifDouble(expr->isDouble));
				returnedNode = expr;
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
			expr = evaluateExpression(node->u.unop.operand);
			if(isIntExpression(expr) == TRUE)
			{
				if(getIntFromExpression(expr) == 0) //!false == true
					expr->u.valInt = TRUE;	
				else								//!true == false
					expr->u.valInt = FALSE;
			}
			else
			{
				error("Cannot Perform !(expr) becuase of invalid type");
			}
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
TYPETAG typeTagEN(EN node)
{
	int b;
	return ty_query(st_lookup(node->u.varStID, &b)->u.decl.type) ;
}
EN evalBinaryExpression(EN node)
{
	EN evaluated = NULL;
	EN evalLeft = NULL;
	EN evalRight = NULL;
	int b;
	TYPETAG typetag = TYSIGNEDINT;
	
	/*if(node->u.binop.op != BINARY_ASSIGNMENT)
	{
			evalLeft = evaluateExpression(node->u.binop.leftOperand);	
			if(isVariableExpression(evalLeft))
				b_deref(getTypeTagFromExpression(evalLeft));	
	}
			evalRight = evaluateExpression(node->u.binop.rightOperand);
			if(isVariableExpression(evalRight))
				b_deref(getTypeTagFromExpression(evalRight));
	*/
	switch(node->u.binop.op)
	{
		case BINARY_ASSIGNMENT:  // a = EXPR
		//TODO: Complete the rest of the logic
		//Set the left operand to be the evlauted expression of the right operand
			evalLeft = evaluateExpression(node->u.binop.leftOperand);

			evalRight = evaluateExpression(node->u.binop.rightOperand);
			// Aaron ADD
			if(isIntExpression(evalRight))
				b_push_const_int(evalRight->u.valInt);
			if(isVariableExpression(evalRight))
				{
					b_deref(getTypeTagFromExpression(evalRight)); 
					
					if(typeTagEN(evalRight) != typeTagEN(evalLeft))
						b_convert(typeTagEN(evalRight), typeTagEN(evalLeft)); 
				}
			if(isDoubleExpression(evalRight))
				b_push_const_double(evalRight->u.valDouble);
			if(st_lookup(evalLeft->u.varStID, &b) != NULL && getTypeTag_STID(evalLeft->u.varStID) != TYFUNC )	
			{	
				b_assign(getTypeTag_STID(evalLeft->u.varStID)); 				
			}
			else
				error("not l-value");
			evaluated = node;
			break;

		case BINARY_MULT: 	// a * b

			evalLeft = evaluateExpression(node->u.binop.leftOperand);	
			if(isVariableExpression(evalLeft))
				b_deref(getTypeTagFromExpression(evalLeft));
			/*if(isVariableExpression(evalRight))
					{	if(typeTagEN(evalRight) != typeTagEN(evalLeft))
						b_convert(typeTagEN(evalLeft), typeTagEN(evalRight)); }*/
			evalRight = evaluateExpression(node->u.binop.rightOperand);
			if(isVariableExpression(evalRight))
				b_deref(getTypeTagFromExpression(evalRight));
	
			if(isDoubleExpression(evalLeft) && isDoubleExpression(evalRight))
			{
				//Make evaluated be Double Expression After Multiplying.
				evalLeft->u.valDouble = getDoubleFromExpression(evalLeft) 
											* getDoubleFromExpression(evalRight);
				evalLeft->tag = TAG_CONST_DOUBLE;
				evaluated = evalLeft;

			}
			else if(isIntExpression(evalLeft) && isIntExpression(evalRight))
			{
				//Make evaluated be Integer Expression after Multiplying.
				evalLeft->u.valInt = getIntFromExpression(evalLeft)
											* getIntFromExpression(evalRight);
				evaluated = evalLeft;

			}
			else if(isVariableExpression(evalLeft) && isVariableExpression(evalRight))
			{
				evaluated = node;
				evaluated->isDouble = (evalLeft->isDouble || evalRight->isDouble);
				b_arith_rel_op(B_MULT, ifDouble(evaluated->isDouble));
			}
			else if(isVariableExpression(evalLeft) || isVariableExpression(evalRight))
			{
				evaluated = node;
				evaluated->isDouble = (evalLeft->isDouble || evalRight->isDouble);
				
				if(isIntExpression(evalLeft))
					b_push_const_int(evalLeft->u.valInt);	
				else if (isIntExpression(evalRight))	
					b_push_const_int(evalRight->u.valInt);	
				b_arith_rel_op(B_MULT, ifDouble(evaluated->isDouble));//ifDouble(evalLeft->isDouble || evalRight->isDouble));

			}
			//else if(
			else
			{
				evaluated = node;
				evaluated->isDouble = (evalLeft->isDouble || evalRight->isDouble);			
				b_arith_rel_op(B_MULT, ifDouble(evaluated->isDouble));
				//error("Cannot add these two expressions");
			}

			break;

		case BINARY_DIV:		// a / 

			evalLeft = evaluateExpression(node->u.binop.leftOperand);	
			if(isVariableExpression(evalLeft))
				b_deref(getTypeTagFromExpression(evalLeft));	
			evalRight = evaluateExpression(node->u.binop.rightOperand);
			if(isVariableExpression(evalRight))
				b_deref(getTypeTagFromExpression(evalRight));
	
			if(isDoubleExpression(evalLeft) && isDoubleExpression(evalRight))
			{
				//Make evaluated be Double Expression After Multiplying.
				error("Both double");
				evalLeft->u.valDouble = getDoubleFromExpression(evalLeft) 
											/ getDoubleFromExpression(evalRight);
				evalLeft->tag = TAG_CONST_DOUBLE;
				evaluated = evalLeft;

			}
			else if(isIntExpression(evalLeft) && isIntExpression(evalRight))
			{
				//Make evaluated be Integer Expression after dividing.
				error("Both int");
				evalLeft->u.valInt = getIntFromExpression(evalLeft)
											/ getIntFromExpression(evalRight);
				evaluated = evalLeft;

			}
			else if(isVariableExpression(evalLeft) && isVariableExpression(evalRight))
			{
				evaluated = node;
				evaluated->isDouble = (evalLeft->isDouble || evalRight->isDouble);
				/*if(isIntExpression(evalLeft))
					b_push_const_int(evalLeft->u.valInt);	
				else if (isIntExpression(evalRight))	
					b_push_const_int(evalRight->u.valInt);	*/
				b_arith_rel_op(B_DIV, ifDouble(evaluated->isDouble));
			}
			else if(isVariableExpression(evalLeft) || isVariableExpression(evalRight))
			{
				evaluated = node;
				evaluated->isDouble = (evalLeft->isDouble || evalRight->isDouble);			
				if(isIntExpression(evalLeft))
					b_push_const_int(evalLeft->u.valInt);	
				else if (isIntExpression(evalRight))	
					b_push_const_int(evalRight->u.valInt);	
				b_arith_rel_op(B_DIV, ifDouble(evaluated->isDouble));//ifDouble(evalLeft->isDouble || evalRight->isDouble));

			}
			//else if(
			else
			{
				evaluated = node;
				evaluated->isDouble = (evalLeft->isDouble || evalRight->isDouble);
				b_arith_rel_op(B_DIV, ifDouble(evaluated->isDouble));
				//error("Cannot add these two expressions");
			}

			break;

		case BINARY_MOD:		// a % b

			evalLeft = evaluateExpression(node->u.binop.leftOperand);
			evalRight = evaluateExpression(node->u.binop.rightOperand);
			

			if(isIntExpression(evalLeft) && isIntExpression(evalRight))
			{
				//Make evaluated be Integer Expression after Modulo Operator.
			}
			else
			{
				error("Cannot mod these two expressions");
			}

			break;

		case BINARY_ADD:		// a + b
			// Moved to top of function
			evalLeft = evaluateExpression(node->u.binop.leftOperand);	
			if(isVariableExpression(evalLeft))
				b_deref(getTypeTagFromExpression(evalLeft));	
			evalRight = evaluateExpression(node->u.binop.rightOperand);
			if(isVariableExpression(evalRight))
				b_deref(getTypeTagFromExpression(evalRight));
	
			if(isDoubleExpression(evalLeft) && isDoubleExpression(evalRight))
			{
				//Make evaluated be Double Expression After Multiplying.
				evalLeft->u.valDouble = getDoubleFromExpression(evalLeft) 
											+ getDoubleFromExpression(evalRight);
				evalLeft->tag = TAG_CONST_DOUBLE;
				evaluated = evalLeft;

			}
			else if(isIntExpression(evalLeft) && isIntExpression(evalRight))
			{
				//Make evaluated be Integer Expression after Multiplying.
				evalLeft->u.valInt = getIntFromExpression(evalLeft)
											+ getIntFromExpression(evalRight);
				evaluated = evalLeft;

			}
			else if(isVariableExpression(evalLeft) && isVariableExpression(evalRight))
			{
				
				evaluated = node;
				
				evaluated->isDouble = (evalLeft->isDouble || evalRight->isDouble);
				//error("isDouble for Add v+v %d", evaluated->isDouble);
				/*if(isIntExpression(evalLeft))
					b_push_const_int(evalLeft->u.valInt);	
				else if (isIntExpression(evalRight))	
					b_push_const_int(evalRight->u.valInt);	*/
				b_arith_rel_op(B_ADD, ifDouble(evaluated->isDouble));
			}
			else if(isVariableExpression(evalLeft) || isVariableExpression(evalRight))
			{
				
				evaluated = node;
				evaluated->isDouble = (evalLeft->isDouble || evalRight->isDouble);
				//error("isDouble for Add v+- %d", evaluated->isDouble);
				if(isIntExpression(evalLeft))
					b_push_const_int(evalLeft->u.valInt);	
				else if (isIntExpression(evalRight))	
					b_push_const_int(evalRight->u.valInt);	
				b_arith_rel_op(B_ADD, ifDouble(evaluated->isDouble));//ifDouble(evalLeft->isDouble || evalRight->isDouble));

			}
			//else if(
			else
			{
				evaluated = node;
				evaluated->isDouble = (evalLeft->isDouble || evalRight->isDouble);			
				b_arith_rel_op(B_ADD, ifDouble(evaluated->isDouble));
				//error("Cannot add these two expressions");
			}

			break;

		case BINARY_SUB:		// a - b

			evalLeft = evaluateExpression(node->u.binop.leftOperand);	
			if(isVariableExpression(evalLeft))
				b_deref(getTypeTagFromExpression(evalLeft));	
			evalRight = evaluateExpression(node->u.binop.rightOperand);
			if(isVariableExpression(evalRight))
				b_deref(getTypeTagFromExpression(evalRight));
	
			if(isDoubleExpression(evalLeft) && isDoubleExpression(evalRight))
			{
				//Make evaluated be Double Expression After Multiplying.
				evalLeft->u.valDouble = getDoubleFromExpression(evalLeft) 
											- getDoubleFromExpression(evalRight);
				evalLeft->tag = TAG_CONST_DOUBLE;
				evaluated = evalLeft;

			}
			else if(isIntExpression(evalLeft) && isIntExpression(evalRight))
			{
				//Make evaluated be Integer Expression after subtracting
				evalLeft->u.valInt = getIntFromExpression(evalLeft)
											- getIntFromExpression(evalRight);
				evaluated = evalLeft;

			}
			else if(isVariableExpression(evalLeft) && isVariableExpression(evalRight))
			{
				evaluated = node;
				evaluated->isDouble = (evalLeft->isDouble || evalRight->isDouble);
				/*if(isIntExpression(evalLeft))
					b_push_const_int(evalLeft->u.valInt);	
				else if (isIntExpression(evalRight))	
					b_push_const_int(evalRight->u.valInt);	*/
				b_arith_rel_op(B_SUB, ifDouble(evaluated->isDouble));
			}
			else if(isVariableExpression(evalLeft) || isVariableExpression(evalRight))
			{
				evaluated = node;
				evaluated->isDouble = (evalLeft->isDouble || evalRight->isDouble);
				if(isIntExpression(evalLeft))
					b_push_const_int(evalLeft->u.valInt);	
				else if (isIntExpression(evalRight))	
					b_push_const_int(evalRight->u.valInt);	
				b_arith_rel_op(B_SUB, ifDouble(evaluated->isDouble));//ifDouble(evalLeft->isDouble || evalRight->isDouble));

			}
			//else if(
			else
			{
				evaluated = node;
				evaluated->isDouble = (evalLeft->isDouble || evalRight->isDouble);			
				b_arith_rel_op(B_SUB, ifDouble(evaluated->isDouble));
				//error("Cannot add these two expressions");
			}

			break;

		case BINARY_SHIFTL:	// a << b
		case BINARY_SHIFTR:	// a >> b
			break;

		//Boolean Comparators
		case BINARY_LT:		// a < b
			
			evalLeft = evaluateExpression(node->u.binop.leftOperand);
			if(isVariableExpression(evalLeft))
				b_deref(getTypeTagFromExpression(evalLeft));	
			evalRight = evaluateExpression(node->u.binop.rightOperand);
			if(isVariableExpression(evalRight))
				b_deref(getTypeTagFromExpression(evalRight));
			//Make evaluated be int Expression After comparing
			if(isDoubleExpression(evalLeft) || isDoubleExpression(evalRight))
			{
				evalLeft->u.valInt = getDoubleFromExpression(evalLeft) 
											< getDoubleFromExpression(evalRight);
				evalLeft->tag = TAG_CONST_INTEGER;
				evaluated = evalLeft;

			}
			else if(isIntExpression(evalLeft) && isIntExpression(evalRight))
			{
				evalLeft->u.valInt = getIntFromExpression(evalLeft)
											< getIntFromExpression(evalRight);
				evaluated = evalLeft;
			}
			else if(isVariableExpression(evalLeft) || isVariableExpression(evalRight))
			{
				evaluated = node;
				evaluated->isDouble = (evalLeft->isDouble || evalRight->isDouble);
				b_arith_rel_op(B_LT, ifDouble(evaluated->isDouble));
			}
			else
			{
				error("Cannot compare '<' with these two expressions");
			}
			break;

		case BINARY_GRT:		// a > b

			evalLeft = evaluateExpression(node->u.binop.leftOperand);
			if(isVariableExpression(evalLeft))
				b_deref(getTypeTagFromExpression(evalLeft));	
			evalRight = evaluateExpression(node->u.binop.rightOperand);
			if(isVariableExpression(evalRight))
				b_deref(getTypeTagFromExpression(evalRight));
			//Make evaluated be int Expression After comparing
			if(isDoubleExpression(evalLeft) || isDoubleExpression(evalRight))
			{
				evalLeft->u.valInt = getDoubleFromExpression(evalLeft) 
											> getDoubleFromExpression(evalRight);
				evalLeft->tag = TAG_CONST_INTEGER;
				evaluated = evalLeft;

			}
			else if(isIntExpression(evalLeft) && isIntExpression(evalRight))
			{
				evalLeft->u.valInt = getIntFromExpression(evalLeft)
											> getIntFromExpression(evalRight);
				evaluated = evalLeft;
			}
			else if(isVariableExpression(evalLeft) || isVariableExpression(evalRight))
			{
				evaluated = node;
				evaluated->isDouble = (evalLeft->isDouble || evalRight->isDouble);
				b_arith_rel_op(B_GT, ifDouble(evaluated->isDouble));
			}
			else
			{
				error("Cannot compare '>' with these two expressions");
			}
			break;

		case BINARY_LTE:		// a <= b

			evalLeft = evaluateExpression(node->u.binop.leftOperand);
			evalRight = evaluateExpression(node->u.binop.rightOperand);

			//Make evaluated be int Expression After comparing
			if(isDoubleExpression(evalLeft) || isDoubleExpression(evalRight))
			{
				evalLeft->u.valInt = getDoubleFromExpression(evalLeft) 
											<= getDoubleFromExpression(evalRight);
				evalLeft->tag = TAG_CONST_INTEGER;
				evaluated = evalLeft;

			}
			else if(isIntExpression(evalLeft) && isIntExpression(evalRight))
			{
				evalLeft->u.valInt = getIntFromExpression(evalLeft)
											<= getIntFromExpression(evalRight);
				evaluated = evalLeft;
			}
			else
			{
				error("Cannot compare '<=' with these two expressions");
			}
			break;

		case BINARY_GRTE: 	// a >= b

			evalLeft = evaluateExpression(node->u.binop.leftOperand);
			evalRight = evaluateExpression(node->u.binop.rightOperand);

			//Make evaluated be int Expression After comparing
			if(isDoubleExpression(evalLeft) || isDoubleExpression(evalRight))
			{
				evalLeft->u.valInt = getDoubleFromExpression(evalLeft) 
											>= getDoubleFromExpression(evalRight);
				evalLeft->tag = TAG_CONST_INTEGER;
				evaluated = evalLeft;

			}
			else if(isIntExpression(evalLeft) && isIntExpression(evalRight))
			{
				evalLeft->u.valInt = getIntFromExpression(evalLeft)
											>= getIntFromExpression(evalRight);
				evaluated = evalLeft;
			}
			else
			{
				error("Cannot compare '>=' with these two expressions");
			}
			break;

		case BINARY_EQUALS:	// a == b

			evalLeft = evaluateExpression(node->u.binop.leftOperand);
			evalRight = evaluateExpression(node->u.binop.rightOperand);

			//Make evaluated be int Expression After comparing
			if(isDoubleExpression(evalLeft) || isDoubleExpression(evalRight))
			{
				evalLeft->u.valInt = getDoubleFromExpression(evalLeft) 
											== getDoubleFromExpression(evalRight);
				evalLeft->tag = TAG_CONST_INTEGER;
				evaluated = evalLeft;

			}
			else if(isIntExpression(evalLeft) && isIntExpression(evalRight))
			{
				evalLeft->u.valInt = getIntFromExpression(evalLeft)
											== getIntFromExpression(evalRight);
				evaluated = evalLeft;
			}
			else
			{
				error("Cannot compare '==' with these two expressions");
			}
			break;

		case BINARY_NE:		// a != b

			evalLeft = evaluateExpression(node->u.binop.leftOperand);
			evalRight = evaluateExpression(node->u.binop.rightOperand);

			//Make evaluated be int Expression After comparing
			if(isDoubleExpression(evalLeft) || isDoubleExpression(evalRight))
			{
				evalLeft->u.valInt = getDoubleFromExpression(evalLeft) 
											!= getDoubleFromExpression(evalRight);
				evalLeft->tag = TAG_CONST_INTEGER;
				evaluated = evalLeft;

			}
			else if(isIntExpression(evalLeft) && isIntExpression(evalRight))
			{
				evalLeft->u.valInt = getIntFromExpression(evalLeft)
											!= getIntFromExpression(evalRight);
				evaluated = evalLeft;
			}
			else
			{
				error("Cannot compare '!=' with these two expressions");
			}
			break;

		case BINARY_AND:		// a && b
		case BINARY_OR:		// a || b
		case BINARY_TERNARY:	// a ? a1 : a2, Technically not a binary op, will we use?
			break;
		//End Boolean Comparators

		case BINARY_XAND:	// a & b
		case BINARY_XOR:		// a | b
		case BINARY_XNOT:		// a ^ b
			break;

		default:
			bug("Where's the binary operator tag in the expression?");

	}

	return evaluated;
}

int getIntFromExpression(EN node)
{
	if(isIntExpression(node))
		return node->u.valInt;
	else
		return (int) node->u.valDouble;
}

double getDoubleFromExpression(EN node)
{
	if(isIntExpression(node))
		return (double) node->u.valInt;
	else
		return node->u.valDouble;
}


ST_ID getIDFromVariableExpression(EN node)
{
	ST_ID id = NULL;

	if(isVariableExpression(node))
		id = node->u.varStID;

	return id;
}
/***************** Eval Expressions ***************/

TYPETAG getTypeTagFromExpression(EN node)
{
	int b;
	ST_ID stid = getIDFromVariableExpression(node);
	ST_DR stdr = st_lookup(node->u.varStID, &b);
	return ty_query(stdr->u.decl.type);
}

TYPETAG ifDouble(BOOLEAN double_)
{
	if(double_)
		return TYDOUBLE;
	else
		return TYSIGNEDINT;
}

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
