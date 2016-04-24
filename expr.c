#include "expr.h"


/***************** Create Functions ***************/
EN createConstantIntExpression(int val)
{
	msg("Creating const int expr: %d", val);

	EN expression = (EN)malloc(sizeof(EXPR_NODE));

	expression->tag = TAG_CONST_INTEGER;
	expression->u.valInt = val;

	return expression;
}

EN createStringExpression(char* f)
{
	EN expression = (EN)malloc(sizeof(EXPR_NODE));

	expression->tag = TAG_STRING;
	expression->u.str.s = f;

	return expression;
}
	

EN createConstantDoubleExpression(const double val)
{
	msg("Creating const double expr: %f", val);

	EN expression = (EN)malloc(sizeof(EXPR_NODE));

	expression->tag = TAG_CONST_DOUBLE;
	expression->u.valDouble = val;

	return expression;
}

EN createVariableExpression(ST_ID varStID)
{
	char* identifier = st_get_id_str(varStID);
	
	int b;
	EN expression = (EN)malloc(sizeof(EXPR_NODE));
	ST_DR stdr = st_lookup(varStID, &b);
	TYPETAG ty_tag = TYERROR;

	if(stdr != NULL) {	
		ty_tag = ty_query(stdr->u.decl.type);
	}
	
	msg("Creating variable expr %s", identifier);

	expression->tag = TAG_VARIABLE;

	if(ty_tag == TYFLOAT || ty_tag == TYDOUBLE)
		expression->isDouble = TRUE;
	else
		expression->isDouble = FALSE;

	if (ty_tag == TYPTR) {
		msg("In createVaraibleExpression, type is TYPTR");
	}

	expression->u.varStID = varStID;

	msg("Creating variable expr %s", identifier);

	return expression;
}

EN createFunctionExpression(EN node, AL arg_l)
{
	msg("Creating function expr");

	EN expression = (EN)malloc(sizeof(EXPR_NODE));

	expression->tag = TAG_FUNCTION;
	expression->u.func.func_node = node;

	expression->u.func.arg_list = arg_l;

	return expression;
}

EN createUnaryExpression(OP_UNARY op, EN operand, BOOLEAN prefix)
{
	msg("Creating unary expr");

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
	msg("Creating binary expr OP_BINARY: %d", op);

	EN expression = (EN)malloc(sizeof(EXPR_NODE));

	expression->tag = TAG_BINARY;
	expression->u.binop.op = op;
	expression->u.binop.leftOperand = left;
	expression->u.binop.rightOperand = right;
	printExpression(left);
	printExpression(right);
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
	new_al->size = 8;
	return new_al;
}
/***************** Create Functions ***************/

/***************** Eval Expressions ***************/
EN evaluateExpression(EN expr)
{
	//Expr should never be null.
//error("eval var exp");

	switch(expr->tag)
	{
		case TAG_CONST_INTEGER:
		case TAG_CONST_DOUBLE:
		case TAG_EVAL_INTEGER:
		case TAG_EVAL_DOUBLE:
		case TAG_EVALUATED:
		case TAG_STRING:
			//error("eval eval exp");
			return expr;

		case TAG_FUNCTION:
		//TODO:	
			error("Begin Eval Function");
			//bug("haven't implemented function expressions yet");
			return evalFunctionExpression(expr);

		case TAG_VARIABLE:
			error("eval var exp");
			return evalVariableExpression(expr);
		case TAG_UNARY:
			error("eval un exp");
			return evalUnaryExpression(expr);
		
		case TAG_BINARY:
			error("eval ass exp");
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
	msg("in evalVariableExpression");
	//Returns the char* of the id
	char* identifier = st_get_id_str(node->u.varStID);
	ST_DR stdr;
	int b;
	//error("eval Var");
	stdr = st_lookup(node->u.varStID, &b);
	if(b == 0 && stdr != NULL) // Maybe change to Less than current block
		b_push_ext_addr(identifier); //msg("pushing");}
	else if(stdr)
		;//error("why");//b_push_loc_addr(b_get_formal_param_offset(ty_query(stdr->u.decl.type))); // This is not returning the value of 8 for TYSIGNEDINT...?
	else
	{	error("`%s' is undefined", identifier); return NULL;}
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
	//msg("");
	if(stdr== NULL || stdr->u.decl.type == NULL) //	if(stdr->u.decl.type == NULL)
		{  error(" why null in returnFuncTypeTag return TYVOID"); 
		return TYVOID;	 }
	
	if (ty_query(stdr->u.decl.type) != TYFUNC)
	{
		error("in returnFuncTypeTag");
		error("expression not of function type", st_get_id_str(stid));
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
		error("`%s' is undefined", f);
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

		if (arg_typetag == TYSIGNEDCHAR) {
			b_convert(TYSIGNEDCHAR, TYSIGNEDINT);
			//msg("Found a variable of type char. Converting node to signed int");
			arg_typetag = TYSIGNEDINT;
		}
		if (arg_typetag == TYFLOAT) {
			b_convert(TYFLOAT, TYDOUBLE);
			//msg("Found a variable of type float. Converting node to double");
			arg_typetag = TYSIGNEDINT;
		}
	}
	else if(node->isDouble)
		arg_typetag = TYDOUBLE;

	else
		arg_typetag = TYSIGNEDINT;
	//msg("Calling b_load_arg with arg_typetag of %d", arg_typetag);

	b_load_arg(arg_typetag);
	//	evalArgList(arg_list->next);
	 // what to do here? Can we return int for Size to allocate?
}
EN evalUnaryExpression(EN node)
{
	EN returnedNode = NULL;

	EN expr = NULL;
	char* identifier = NULL;
	switch(node->u.unop.op)
	{
		//TODO:
		case UNARY_DEREF: 		//*ptr
			returnedNode = node->u.unop.operand;
			identifier = st_get_id_str(node->u.unop.operand->u.varStID);
			b_push_ext_addr(identifier);
			
			TYPETAG type = getTypeTagFromExpression(returnedNode);
			msg("De-reffing a UNARY_DEREF");
			b_deref(type);

			msg("TYPETAG after evaluating: %d", type);
			if (type == TYPTR) {
				returnedNode->tag = TAG_POINTER;
				returnedNode->u.eval.type = type;
			}
			break;
		case UNARY_REF:	;		//&identifier
			identifier = st_get_id_str(node->u.unop.operand->u.varStID);
			msg("In evalUnaryExpression UNARY_REF");
			b_push_ext_addr(identifier);
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
				TYPETAG type = getTypeTagFromExpression(expr);

				b_deref(type);
				type = unaryConversion(expr);
				b_negate(type);
				returnedNode = expr;
				returnedNode->tag = TAG_EVALUATED;
				returnedNode->u.eval.type = type;
			}
			else if(isEvaluatedExpression(expr) == TRUE)
			{
				TYPETAG type = getTypeTagFromExpression(expr);

				b_negate(type);
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
	//msg("start evaluating binary expression %d", node->u.binop.op);
	BOOLEAN fold_flag = FALSE;
	TYPETAG type;
	EN evaluated = NULL;
	EN evalLeft = node->u.binop.leftOperand;
	EN evalRight = node->u.binop.rightOperand;
	//error("node is %d, evalLeft is %d and evalRight is %d", node->tag, evalLeft->tag, evalRight->tag);
	int b;
	TYPETAG leftType = evaluateTypeExpression(node->u.binop.leftOperand);
	TYPETAG rightType = evaluateTypeExpression(node->u.binop.rightOperand);
	
	TYPETAG resolvedType = resolveTypeBinaryExpression(leftType, rightType);
	//msg("8w9q48958714289798257894725: %d %d", leftType, rightType);
	
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
		//Set the left operand to be the evlauted expression of the right operand
			//msg("BINARY_ASSIGNMENT evaluating");

			// TYPETAG rightSide = evaluateTypeExpression(node->u.binop.rightOperand);
			//msg("89qe9089wq94uqw909qweri90ewi9riew0r: %d", rightSide);
			//error("before bin assign");
			evalLeft = evaluateExpression(node->u.binop.leftOperand);
			if(evalLeft == NULL)
			{	//evaluated = node;
				//evaluated->tag = TAG_EVALUATED;
				return evalRight; //evaluated->u.eval.type = type;
			}
			if(st_lookup(evalLeft->u.varStID, &b) != NULL && getTypeTag_STID(evalLeft->u.varStID) != TYFUNC )	
			{

				//b_assign(getTypeTag_STID(evalLeft->u.varStID)); 				
			}
			else
				{error("left side of assignment is not an l-value"); return evalRight;}
			evalRight = evaluateExpression(node->u.binop.rightOperand);
			
			if(evalLeft->tag == TAG_FUNCTION)
			{
				error("a function as l-value");
			}
			// Aaron ADD
			TYPETAG type;
			if(isIntExpression(evalRight))
			{
				//error("binary assign push const, %d", evalRight->u.valInt);
				b_push_const_int(evalRight->u.valInt);
				type = TYSIGNEDINT;

				if(type != typeTagEN(evalLeft))
				{
					b_convert(type, typeTagEN(evalLeft)); 
					type = typeTagEN(evalLeft);
				}
			}
			else if(isVariableExpression(evalRight))
			{
				type = getTypeTagFromExpression(evalRight);
				b_deref(type);

				type = unaryConversion(evalRight); 


				if(type != typeTagEN(evalLeft))
				{
					b_convert(type, typeTagEN(evalLeft)); 
					type = typeTagEN(evalLeft);
				}
			}
			else if(isDoubleExpression(evalRight))
			{
				b_push_const_double(evalRight->u.valDouble);
				type = TYDOUBLE;

				if(type != typeTagEN(evalLeft))
				{
					b_convert(type, typeTagEN(evalLeft)); 
					type = typeTagEN(evalLeft);
				}	
			}
			else if(isEvaluatedExpression(evalRight))
			{
				//msg("Evaluated righthand side in ASSIGNMENT!!!!");
				type = getTypeTagFromExpression(evalRight);

				if(type != typeTagEN(evalLeft))
				{
					b_convert(type, typeTagEN(evalLeft)); 
					type = typeTagEN(evalLeft);
				}
			}
			else if(isFunctionExpression(evalRight))
			{
				type = returnFuncTypeTag(evalRight);
				if(type != typeTagEN(evalLeft))
				{
					b_convert(type, typeTagEN(evalLeft));
					type = typeTagEN(evalLeft);
				}
			}
			if(st_lookup(evalLeft->u.varStID, &b) != NULL && getTypeTag_STID(evalLeft->u.varStID) != TYFUNC )	
			{

				b_assign(getTypeTag_STID(evalLeft->u.varStID)); 				
			}
			else
				error("not l-value");
			
			evaluated = node;
			evaluated->tag = TAG_EVALUATED;
			evaluated->u.eval.type = type;

			break;

		case BINARY_MULT: 	// a * b

			//msg("BINARY_MULT is evaluating");
	
			if(isDoubleExpression(evalLeft) && isDoubleExpression(evalRight)
				|| isDoubleExpression(evalLeft) && isIntExpression(evalRight)
				|| isIntExpression(evalLeft) && isDoubleExpression(evalRight))
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
			else if(evalLeft->tag == TAG_FUNCTION && evalRight->tag == TAG_FUNCTION)
			{
				// SHOULD be return Type Convert call might be needed
				evalLeft = evaluateExpression(node->u.binop.leftOperand);
				evalRight = evaluateExpression(node->u.binop.rightOperand);					
				b_arith_rel_op(B_MULT, returnFuncTypeTag(evalLeft)); 
				evaluated = evalLeft;
			}
			else if(evalLeft->tag == TAG_FUNCTION)
			{
				evalLeft = evaluateExpression(node->u.binop.leftOperand);

			//evalRight = evaluateExpression(node->u.binop.rightOperand);

				if(isIntExpression(evalRight))
				{	b_push_const_int(evalRight->u.valInt);
					b_arith_rel_op(B_MULT, TYSIGNEDINT);}
				else
				{	b_push_const_double(evalRight->u.valDouble);
					b_arith_rel_op(B_MULT, TYDOUBLE);}
				evaluated = evalLeft;
			}
			else if(evalRight->tag == TAG_FUNCTION)
			{
				if(isIntExpression(evalLeft))
				{	b_push_const_int(evalLeft->u.valInt);
					b_arith_rel_op(B_MULT, TYSIGNEDINT);}
				else
				{	b_push_const_double(evalLeft->u.valDouble);
					b_arith_rel_op(B_MULT, TYDOUBLE);}
				evaluated = evalRight;
			}
			else
			{
				evalLeft = evaluateExpression(node->u.binop.leftOperand);	
				if(isVariableExpression(evalLeft))
				{
					b_deref(getTypeTagFromExpression(evalLeft));
				}
				else if(isIntExpression(evalLeft))
				{
					b_push_const_int(evalLeft->u.valInt);	
				}
				else if(isDoubleExpression(evalLeft))
				{
					b_push_const_double(evalLeft->u.valDouble);
				}
				leftType = unaryConversion(evalLeft);
				if(leftType != resolvedType)
					b_convert(leftType, resolvedType);

				evalRight = evaluateExpression(node->u.binop.rightOperand);
				if(isVariableExpression(evalRight))
				{
					b_deref(getTypeTagFromExpression(evalRight));
				}
				else if(isIntExpression(evalRight))
				{
					//error("binary MULT removed because of convert push const, %d", evalRight->u.valInt);
					//b_push_const_int(evalRight->u.valInt);	
				}
				else if(isDoubleExpression(evalRight))
				{
					b_push_const_double(evalRight->u.valDouble);
				}
				rightType = unaryConversion(evalRight);
				if(rightType != resolvedType)
					b_convert(rightType, resolvedType);
					
				TYPETAG type = convertExpression(evalLeft, evalRight);
				b_arith_rel_op(B_MULT, type);
				
				evaluated = node;
				evaluated->tag = TAG_EVALUATED;
				evaluated->u.eval.type = type;
			}
			break;

		case BINARY_DIV:		// a / 

			//msg("BINARY_DIV is evaluating");
	
			if(isDoubleExpression(evalLeft) && isDoubleExpression(evalRight)
				|| isDoubleExpression(evalLeft) && isIntExpression(evalRight)
				|| isIntExpression(evalLeft) && isDoubleExpression(evalRight))
			{
				//Make evaluated be Double Expression After Multiplying.
				evalLeft->u.valDouble = getDoubleFromExpression(evalLeft) 
											/ getDoubleFromExpression(evalRight);
				evalLeft->tag = TAG_CONST_DOUBLE;
				evalLeft->isDouble = TRUE;
				evaluated = evalLeft;

			}
			else if(isIntExpression(evalLeft) && isIntExpression(evalRight))
			{
				//Make evaluated be Integer Expression after dividing.
				evalLeft->u.valInt = getIntFromExpression(evalLeft)
											/ getIntFromExpression(evalRight);
				evaluated = evalLeft;

			}else if(evalLeft->tag == TAG_FUNCTION && evalRight->tag == TAG_FUNCTION)
			{
				// SHOULD be return Type Convert call might be needed
					b_arith_rel_op(B_ADD, returnFuncTypeTag(evalLeft)); 
				evaluated = evalLeft;
			}
			else if(evalLeft->tag == TAG_FUNCTION)
			{
				evalLeft = evaluateExpression(node->u.binop.leftOperand);

			//evalRight = evaluateExpression(node->u.binop.rightOperand);

				if(isIntExpression(evalRight))
				{	b_push_const_int(evalRight->u.valInt);
					b_arith_rel_op(B_DIV, TYSIGNEDINT);}
				else
				{	b_push_const_double(evalRight->u.valDouble);
					b_arith_rel_op(B_DIV, TYDOUBLE);}
				evaluated = evalLeft;
			}
			else if(evalRight->tag == TAG_FUNCTION)
			{
				if(isIntExpression(evalLeft))
				{	b_push_const_int(evalLeft->u.valInt);
					b_arith_rel_op(B_DIV, TYSIGNEDINT);}
				else
				{	b_push_const_double(evalLeft->u.valDouble);
					b_arith_rel_op(B_DIV, TYDOUBLE);}
				evaluated = evalRight;
			}
			else
			{
				evalLeft = evaluateExpression(node->u.binop.leftOperand);	
				if(isVariableExpression(evalLeft))
				{
					b_deref(getTypeTagFromExpression(evalLeft));
				}
				else if(isIntExpression(evalLeft))
				{
					b_push_const_int(evalLeft->u.valInt);	
				}
				else if(isDoubleExpression(evalLeft))
				{
					b_push_const_double(evalLeft->u.valDouble);
				}
				leftType = unaryConversion(evalLeft);
				if(leftType != resolvedType)
					b_convert(leftType, resolvedType);

				evalRight = evaluateExpression(node->u.binop.rightOperand);
				if(isVariableExpression(evalRight))
				{
					b_deref(getTypeTagFromExpression(evalRight));
				}
				else if(isIntExpression(evalRight))
				{
					b_push_const_int(evalRight->u.valInt);	
				}
				else if(isDoubleExpression(evalRight))
				{
					b_push_const_double(evalRight->u.valDouble);
				}
				rightType = unaryConversion(evalRight);
				if(rightType != resolvedType)
					b_convert(rightType, resolvedType);

				TYPETAG type = convertExpression(evalLeft, evalRight);
				b_arith_rel_op(B_DIV, type);
				
				evaluated = node;
				evaluated->tag = TAG_EVALUATED;
				evaluated->u.eval.type = type;
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

			//msg("BINARY_ADD is evaluating");
	
			if((isDoubleExpression(evalLeft) && isDoubleExpression(evalRight))
				|| (isDoubleExpression(evalLeft) && isIntExpression(evalRight))
				|| (isIntExpression(evalLeft) && isDoubleExpression(evalRight)))
			{
				msg("Eval + for double + double");
				//Make evaluated be Double Expression After Multiplying.
				evalLeft->u.valDouble = getDoubleFromExpression(evalLeft) 
											+ getDoubleFromExpression(evalRight);
				evalLeft->tag = TAG_CONST_DOUBLE;
				evaluated = evalLeft;
				type = TYDOUBLE;
				fold_flag = TRUE;

			}
			else if(isIntExpression(evalLeft) && isIntExpression(evalRight))
			{
				msg("Eval + for int + int");
				//Make evaluated be Integer Expression after Multiplying.
				evalLeft->u.valInt = getIntFromExpression(evalLeft)
											+ getIntFromExpression(evalRight);			//error("here?");
				evaluated = evalLeft;// evalLeft;
				//evaluated->tag = TAG_CONST_INTEGER;
				return evaluated;
				type = TYSIGNEDINT;
				fold_flag = TRUE;
			}
			else if(evalLeft->tag == TAG_FUNCTION && evalRight->tag == TAG_FUNCTION)
			{
				evalLeft = evaluateExpression(node->u.binop.leftOperand);
				evalRight = evaluateExpression(node->u.binop.rightOperand);
				// SHOULD be return Type Convert call might be needed
					b_arith_rel_op(B_ADD, returnFuncTypeTag(evalLeft)); 
				evaluated = evalLeft;
			}
			else if(evalLeft->tag == TAG_FUNCTION)
			{
				evalLeft = evaluateExpression(node->u.binop.leftOperand);

			//evalRight = evaluateExpression(node->u.binop.rightOperand);

				if(isIntExpression(evalRight))
				{	b_push_const_int(evalRight->u.valInt);
					b_arith_rel_op(B_ADD, TYSIGNEDINT);}
				else
				{	b_push_const_double(evalRight->u.valDouble);
					b_arith_rel_op(B_ADD, TYDOUBLE);}
				evaluated = evalLeft;
			}
			else if(evalRight->tag == TAG_FUNCTION)
			{
				if(isIntExpression(evalLeft))
				{	b_push_const_int(evalLeft->u.valInt);
					b_arith_rel_op(B_ADD, TYSIGNEDINT);}
				else
				{	b_push_const_double(evalLeft->u.valDouble);
					b_arith_rel_op(B_ADD, TYDOUBLE);}
				evaluated = evalRight;
			}
			else
			{
				evalLeft = evaluateExpression(node->u.binop.leftOperand);	
				if(isVariableExpression(evalLeft))
				{
					msg("de-reffing in BINARY_ADD");
					b_deref(getTypeTagFromExpression(evalLeft));
				}
				else if(isIntExpression(evalLeft))
				{
					error("binary add push int eval left removed cuz of convert?, %d", evalLeft->u.valInt );
					//b_push_const_int(evalLeft->u.valInt);	
				}
				else if(isDoubleExpression(evalLeft))
				{
					b_push_const_double(evalLeft->u.valDouble);
				}
				leftType = unaryConversion(evalLeft);
				if(leftType != resolvedType)
					{
					error("binary add push int eval left resolved type, %d", evalLeft->u.valInt );
					//b_convert(leftType, resolvedType);
					}
				evalRight = evaluateExpression(node->u.binop.rightOperand);
				msg("evalRight TYPETAG: %d",getTypeTagFromExpression(node->u.unop.operand));
				if(isVariableExpression(evalRight))
				{
					msg("evalRight is a variable expression");
					b_deref(getTypeTagFromExpression(evalRight));
					//}
				}
				else if(isIntExpression(evalRight))
				{
					msg("evalRight is a int expression");
					//error("binary add push const removed because convert, %d", evalRight->u.valInt);
					//b_push_const_int(evalRight->u.valInt);	
				}
				else if(isDoubleExpression(evalRight))
				{
					msg("evalRight is a double expression");
					b_push_const_double(evalRight->u.valDouble);
				}
				else if (isPointerExpression(evalRight)) {
					msg("****ISSUE: NEED TYPE THAT POINTER evalRight POINTS TO HERE!!! (int, double, float char)****");
					b_deref(getTypeTagFromExpression(evalRight->u.unop.operand));
				}
				rightType = unaryConversion(evalRight);
				//if(rightType != resolvedType)
					//b_convert(rightType, resolvedType);

				
				if(fold_flag == FALSE)	//tried to do more folding than one instance
				{
					type = convertExpression(evalLeft, evalRight);
				}
				if(type != NULL)
				{
					//error("arith add being done, %d", type);
					b_arith_rel_op(B_ADD, type);
				}
				else
				{
					error("type is null? does this happen?");
				}
				
				evaluated = node;
				evaluated->tag = TAG_EVALUATED;
				evaluated->u.eval.type = type;
			}

			break;

		case BINARY_SUB:		// a - b

			//msg("BINARY_SUB is evaluating");
	
			if(isDoubleExpression(evalLeft) && isDoubleExpression(evalRight)
				|| isDoubleExpression(evalLeft) && isIntExpression(evalRight)
				|| isIntExpression(evalLeft) && isDoubleExpression(evalRight))
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
			else if(evalLeft->tag == TAG_FUNCTION && evalRight->tag == TAG_FUNCTION)
			{
				// SHOULD be return Type Convert call might be needed
					b_arith_rel_op(B_SUB, returnFuncTypeTag(evalLeft)); 
				evaluated = evalLeft;
			}
			else if(evalLeft->tag == TAG_FUNCTION)
			{
				evalLeft = evaluateExpression(node->u.binop.leftOperand);

			//evalRight = evaluateExpression(node->u.binop.rightOperand);

				if(isIntExpression(evalRight))
				{	b_push_const_int(evalRight->u.valInt);
					b_arith_rel_op(B_SUB, TYSIGNEDINT);}
				else
				{	b_push_const_double(evalRight->u.valDouble);
					b_arith_rel_op(B_SUB, TYDOUBLE);}
				evaluated = evalLeft;
			}
			else if(evalRight->tag == TAG_FUNCTION)
			{
				if(isIntExpression(evalLeft))
				{	b_push_const_int(evalLeft->u.valInt);
					b_arith_rel_op(B_SUB, TYSIGNEDINT);}
				else
				{	b_push_const_double(evalLeft->u.valDouble);
					b_arith_rel_op(B_SUB, TYDOUBLE);}
				evaluated = evalRight;
			}
			else
			{
				evalLeft = evaluateExpression(node->u.binop.leftOperand);	
				if(isVariableExpression(evalLeft))
				{
					b_deref(getTypeTagFromExpression(evalLeft));
				}
				else if(isIntExpression(evalLeft))
				{
					b_push_const_int(evalLeft->u.valInt);	
				}
				else if(isDoubleExpression(evalLeft))
				{
					b_push_const_double(evalLeft->u.valDouble);
				}
				leftType = unaryConversion(evalLeft);
				if(leftType != resolvedType)
					b_convert(leftType, resolvedType);

				evalRight = evaluateExpression(node->u.binop.rightOperand);
				if(isVariableExpression(evalRight))
				{
					b_deref(getTypeTagFromExpression(evalRight));
				}
				else if(isIntExpression(evalRight))
				{
					//b_push_const_int(evalRight->u.valInt);	
				}
				else if(isDoubleExpression(evalRight))
				{
					b_push_const_double(evalRight->u.valDouble);
				}
				rightType = unaryConversion(evalRight);
				if(rightType != resolvedType)
					b_convert(rightType, resolvedType);

				TYPETAG type = convertExpression(evalLeft, evalRight);
				b_arith_rel_op(B_SUB, type);
				
				evaluated = node;
				evaluated->tag = TAG_EVALUATED;
				evaluated->u.eval.type = type;
			}
			

			break;

		case BINARY_SHIFTL:	// a << b
		case BINARY_SHIFTR:	// a >> b
			break;

		//Boolean Comparators
		case BINARY_LT:		// a < b

			//Make evaluated be int Expression After comparing
			if(isDoubleExpression(evalLeft) && isDoubleExpression(evalRight)
				|| isDoubleExpression(evalLeft) && isIntExpression(evalRight)
				|| isIntExpression(evalLeft) && isDoubleExpression(evalRight))
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
			else
			{
				evalLeft = evaluateExpression(node->u.binop.leftOperand);	
				if(isVariableExpression(evalLeft))
				{
					b_deref(getTypeTagFromExpression(evalLeft));
				}
				else if(isIntExpression(evalLeft))
				{
					b_push_const_int(evalLeft->u.valInt);	
				}
				else if(isDoubleExpression(evalLeft))
				{
					b_push_const_double(evalLeft->u.valDouble);
				}
				leftType = unaryConversion(evalLeft);
				if(leftType != resolvedType)
					;//b_convert(leftType, resolvedType);

				evalRight = evaluateExpression(node->u.binop.rightOperand);
				if(isVariableExpression(evalRight))
				{
					b_deref(getTypeTagFromExpression(evalRight));
				}
				else if(isIntExpression(evalRight))
				{
					//b_push_const_int(evalRight->u.valInt);	
				}
				else if(isDoubleExpression(evalRight))
				{
					b_push_const_double(evalRight->u.valDouble);
				}
				rightType = unaryConversion(evalRight);
				if(rightType != resolvedType)
					;//b_convert(rightType, resolvedType); Found to be a DUPLICATE convert

				TYPETAG type = convertExpression(evalLeft, evalRight);
				b_arith_rel_op(B_LT, type);
				
				evaluated = node;
				evaluated->tag = TAG_EVALUATED;
				evaluated->u.eval.type = TYSIGNEDINT;
			}
			break;

		case BINARY_GRT:		// a > b

			//Make evaluated be int Expression After comparing
			if(isDoubleExpression(evalLeft) && isDoubleExpression(evalRight)
				|| isDoubleExpression(evalLeft) && isIntExpression(evalRight)
				|| isIntExpression(evalLeft) && isDoubleExpression(evalRight))
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
			else
			{
				evalLeft = evaluateExpression(node->u.binop.leftOperand);	
				if(isVariableExpression(evalLeft))
				{
					b_deref(getTypeTagFromExpression(evalLeft));
				}
				else if(isIntExpression(evalLeft))
				{
					b_push_const_int(evalLeft->u.valInt);	
				}
				else if(isDoubleExpression(evalLeft))
				{
					b_push_const_double(evalLeft->u.valDouble);
				}
				leftType = unaryConversion(evalLeft);
				if(leftType != resolvedType)
					b_convert(leftType, resolvedType);

				evalRight = evaluateExpression(node->u.binop.rightOperand);
				if(isVariableExpression(evalRight))
				{
					b_deref(getTypeTagFromExpression(evalRight));
				}
				else if(isIntExpression(evalRight))
				{
					//b_push_const_int(evalRight->u.valInt); Causing duplicate pushes	
				}
				else if(isDoubleExpression(evalRight))
				{
					b_push_const_double(evalRight->u.valDouble);
				}
				rightType = unaryConversion(evalRight);
				if(rightType != resolvedType)
					b_convert(rightType, resolvedType);

				TYPETAG type = convertExpression(evalLeft, evalRight);
				b_arith_rel_op(B_GT, type);
				
				evaluated = node;
				evaluated->tag = TAG_EVALUATED;
				evaluated->u.eval.type = TYSIGNEDINT;
			}
			// else if(isVariableExpression(evalLeft) || isVariableExpression(evalRight))
			// {
			// 	evaluated = node;
			// 	evaluated->isDouble = (evalLeft->isDouble || evalRight->isDouble);
			// 	b_arith_rel_op(B_GT, ifDouble(evaluated->isDouble));
			// }
			// else
			// {
			// 	error("Cannot compare '>' with these two expressions");
			// }
			break;

		case BINARY_LTE:		// a <= b

			//Make evaluated be int Expression After comparing
			if(isDoubleExpression(evalLeft) && isDoubleExpression(evalRight)
				|| isDoubleExpression(evalLeft) && isIntExpression(evalRight)
				|| isIntExpression(evalLeft) && isDoubleExpression(evalRight))
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
				evalLeft = evaluateExpression(node->u.binop.leftOperand);	
				if(isVariableExpression(evalLeft))
				{
					b_deref(getTypeTagFromExpression(evalLeft));
				}
				else if(isIntExpression(evalLeft))
				{
					b_push_const_int(evalLeft->u.valInt);	
				}
				else if(isDoubleExpression(evalLeft))
				{
					b_push_const_double(evalLeft->u.valDouble);
				}
				leftType = unaryConversion(evalLeft);
				if(leftType != resolvedType)
					b_convert(leftType, resolvedType);

				evalRight = evaluateExpression(node->u.binop.rightOperand);
				if(isVariableExpression(evalRight))
				{
					b_deref(getTypeTagFromExpression(evalRight));
				}
				else if(isIntExpression(evalRight))
				{
					b_push_const_int(evalRight->u.valInt);	
				}
				else if(isDoubleExpression(evalRight))
				{
					b_push_const_double(evalRight->u.valDouble);
				}
				rightType = unaryConversion(evalRight);
				if(rightType != resolvedType)
					b_convert(rightType, resolvedType);

				TYPETAG type = convertExpression(evalLeft, evalRight);
				b_arith_rel_op(B_LE, type);
				
				evaluated = node;
				evaluated->tag = TAG_EVALUATED;
				evaluated->u.eval.type = TYSIGNEDINT;
			}
			// else
			// {
			// 	error("Cannot compare '<=' with these two expressions");
			// }
			break;

		case BINARY_GRTE: 	// a >= b

			//Make evaluated be int Expression After comparing
			if(isDoubleExpression(evalLeft) && isDoubleExpression(evalRight)
				|| isDoubleExpression(evalLeft) && isIntExpression(evalRight)
				|| isIntExpression(evalLeft) && isDoubleExpression(evalRight))
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
				evalLeft = evaluateExpression(node->u.binop.leftOperand);	
				if(isVariableExpression(evalLeft))
				{
					b_deref(getTypeTagFromExpression(evalLeft));
				}
				else if(isIntExpression(evalLeft))
				{
					b_push_const_int(evalLeft->u.valInt);	
				}
				else if(isDoubleExpression(evalLeft))
				{
					b_push_const_double(evalLeft->u.valDouble);
				}
				leftType = unaryConversion(evalLeft);
				if(leftType != resolvedType)
					b_convert(leftType, resolvedType);

				evalRight = evaluateExpression(node->u.binop.rightOperand);
				if(isVariableExpression(evalRight))
				{
					b_deref(getTypeTagFromExpression(evalRight));
				}
				else if(isIntExpression(evalRight))
				{
					b_push_const_int(evalRight->u.valInt);	
				}
				else if(isDoubleExpression(evalRight))
				{
					b_push_const_double(evalRight->u.valDouble);
				}
				rightType = unaryConversion(evalRight);
				if(rightType != resolvedType)
					b_convert(rightType, resolvedType);

				TYPETAG type = convertExpression(evalLeft, evalRight);
				b_arith_rel_op(B_GE, type);
				
				evaluated = node;
				evaluated->tag = TAG_EVALUATED;
				evaluated->u.eval.type = TYSIGNEDINT;
			}
			// else
			// {
			// 	error("Cannot compare '>=' with these two expressions");
			// }
			break;

		case BINARY_EQUALS:	// a == b

			//Make evaluated be int Expression After comparing
			if(isDoubleExpression(evalLeft) && isDoubleExpression(evalRight)
				|| isDoubleExpression(evalLeft) && isIntExpression(evalRight)
				|| isIntExpression(evalLeft) && isDoubleExpression(evalRight))
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
				evalLeft = evaluateExpression(node->u.binop.leftOperand);	
				if(isVariableExpression(evalLeft))
				{
					b_deref(getTypeTagFromExpression(evalLeft));
				}
				else if(isIntExpression(evalLeft))
				{
					b_push_const_int(evalLeft->u.valInt);	
				}
				else if(isDoubleExpression(evalLeft))
				{
					b_push_const_double(evalLeft->u.valDouble);
				}
				leftType = unaryConversion(evalLeft);
				if(leftType != resolvedType)
					b_convert(leftType, resolvedType);

				evalRight = evaluateExpression(node->u.binop.rightOperand);
				if(isVariableExpression(evalRight))
				{
					b_deref(getTypeTagFromExpression(evalRight));
				}
				else if(isIntExpression(evalRight))
				{
					//b_push_const_int(evalRight->u.valInt);	
				}
				else if(isDoubleExpression(evalRight))
				{
					b_push_const_double(evalRight->u.valDouble);
				}
				rightType = unaryConversion(evalRight);
				if(rightType != resolvedType)
					b_convert(rightType, resolvedType);

				TYPETAG type = convertExpression(evalLeft, evalRight);
				b_arith_rel_op(B_EQ, type);
				
				evaluated = node;
				evaluated->tag = TAG_EVALUATED;
				evaluated->u.eval.type = TYSIGNEDINT;
			}
			// else
			// {
			// 	error("Cannot compare '==' with these two expressions");
			// }
			break;

		case BINARY_NE:		// a != b

			//Make evaluated be int Expression After comparing
			if(isDoubleExpression(evalLeft) && isDoubleExpression(evalRight)
				|| isDoubleExpression(evalLeft) && isIntExpression(evalRight)
				|| isIntExpression(evalLeft) && isDoubleExpression(evalRight))
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
				evalLeft = evaluateExpression(node->u.binop.leftOperand);	
				if(isVariableExpression(evalLeft))
				{
					b_deref(getTypeTagFromExpression(evalLeft));
				}
				else if(isIntExpression(evalLeft))
				{
					b_push_const_int(evalLeft->u.valInt);	
				}
				else if(isDoubleExpression(evalLeft))
				{
					b_push_const_double(evalLeft->u.valDouble);
				}
				leftType = unaryConversion(evalLeft);
				if(leftType != resolvedType)
					b_convert(leftType, resolvedType);

				evalRight = evaluateExpression(node->u.binop.rightOperand);
				if(isVariableExpression(evalRight))
				{
					b_deref(getTypeTagFromExpression(evalRight));
				}
				else if(isIntExpression(evalRight))
				{
					b_push_const_int(evalRight->u.valInt);	
				}
				else if(isDoubleExpression(evalRight))
				{
					b_push_const_double(evalRight->u.valDouble);
				}
				rightType = unaryConversion(evalRight);
				if(rightType != resolvedType)
					b_convert(rightType, resolvedType);

				TYPETAG type = convertExpression(evalLeft, evalRight);
				b_arith_rel_op(B_NE, type);
				
				evaluated = node;
				evaluated->tag = TAG_EVALUATED;
				evaluated->u.eval.type = TYSIGNEDINT;
			}
			// else
			// {
			// 	error("Cannot compare '!=' with these two expressions");
			// }
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



TYPETAG unaryConversionNoConversion(EN operand)
{
	//msg("Inside Unary Conversion No Conversion");

	TYPETAG returnType, 
			currentType;

	returnType = currentType = getTypeTagFromExpression(operand); 

	// //msg("return type %d", returnType);

	// if(currentType == TYSIGNEDCHAR )
		// //msg("iffffffffffffffffffff");
	switch(currentType)
	{
		case TYSIGNEDLONGINT:
		case TYSIGNEDCHAR:
		case TYSIGNEDSHORTINT:
		case TYUNSIGNEDLONGINT:
		case TYUNSIGNEDSHORTINT:
		case TYUNSIGNEDINT:
		case TYUNSIGNEDCHAR:
			 	//msg("convert %d to %d", currentType, returnType);
			 	returnType = TYSIGNEDINT;
			 	// b_convert(currentType, returnType);
			 	break;
		case TYFLOAT:
		case TYLONGDOUBLE:
			 	//msg("convert %d to %d", currentType, returnType);
			 	returnType = TYDOUBLE;
			 	// b_convert(currentType, returnType);
			 	break;
	}
	
	// //msg("finished switch in unaryConversion");

	return returnType;
}

TYPETAG unaryConversion(EN operand)
{
	//msg("Inside Unary Conversion");

	TYPETAG returnType, 
			currentType;

	returnType = currentType = getTypeTagFromExpression(operand); 

	// //msg("return type %d", returnType);

	// if(currentType == TYSIGNEDCHAR )
		// //msg("iffffffffffffffffffff");
	switch(currentType)
	{
		case TYSIGNEDLONGINT:
		case TYSIGNEDCHAR:
		case TYSIGNEDSHORTINT:
		case TYUNSIGNEDLONGINT:
		case TYUNSIGNEDSHORTINT:
		case TYUNSIGNEDINT:
		case TYUNSIGNEDCHAR:
			 	//msg("convert %d to %d", currentType, returnType);
			 	returnType = TYSIGNEDINT;
			 	b_convert(currentType, returnType);
			 	break;
		case TYFLOAT:
		case TYLONGDOUBLE:
			 	//msg("convert %d to %d", currentType, returnType);
			 	returnType = TYDOUBLE;
			 	b_convert(currentType, returnType);
			 	break;
	}
	
	// //msg("finished switch in unaryConversion");

	return returnType;
}

TYPETAG convertExpression(EN leftOperand, EN rightOperand)
{
	//msg("inside convert expression");
	TYPETAG type;

	if(isEvaluatedExpression(leftOperand))
	{
		TYPETAG leftType = unaryConversionNoConversion(leftOperand);

		if(leftType == TYSIGNEDINT && isIntExpression(rightOperand))
		{
			error("convert if evalEXP... L =INT and R= INT push const, %d", rightOperand->u.valInt);
			b_push_const_int(rightOperand->u.valInt);
			type = TYSIGNEDINT;
		}
		else if(leftType == TYSIGNEDINT && isDoubleExpression(rightOperand))
		{
			// b_convert(leftType, TYDOUBLE);
			b_push_const_double(rightOperand->u.valDouble);
			type = TYDOUBLE;
		}
		else if(leftType == TYDOUBLE && isIntExpression(rightOperand))
		{
			b_push_const_int(rightOperand->u.valInt);
			b_convert(TYSIGNEDINT, TYDOUBLE);
			type = TYDOUBLE;
		}
		else if(leftType == TYDOUBLE && isDoubleExpression(rightOperand))
		{
			b_push_const_double(rightOperand->u.valDouble);
			type = TYDOUBLE;
		}
		else if(isVariableExpression(rightOperand))
		{
			TYPETAG rightType = getTypeTagFromExpression(rightOperand);
			// deref the left operand 
			// b_deref(rightType);
			rightType = unaryConversionNoConversion(rightOperand);


			//msg("rightType %d", rightType);

			if(leftType == TYSIGNEDINT && rightType == TYSIGNEDINT)
			{
				//msg("var op var: both integers");
				// b_push_const_int(rightOperand->u.valInt);
				// b_deref(rightType);
				// unaryConversion(leftOperand);
				// //msg("deref questionable?");
				type = TYSIGNEDINT;
			}
			else if(leftType == TYSIGNEDINT && rightType == TYDOUBLE)
			{
				b_convert(leftType, TYDOUBLE);
				// b_deref(rightType);
				// unaryConversion(leftOperand);
				type = TYDOUBLE;
			}
			else if(leftType == TYDOUBLE && rightType == TYSIGNEDINT)
			{
				// b_deref(rightType);
				// rightType = unaryConversion(leftOperand);
				// b_convert(rightType, TYDOUBLE);
				type = TYDOUBLE;
			}
			else if(leftType == TYDOUBLE && rightType == TYDOUBLE)
			{
				// b_deref(rightType);
				// unaryConversion(leftOperand);
				type = TYDOUBLE;
			}
		}
		else if(isEvaluatedExpression(rightOperand))
		{//both operands have been evaluated (on the stack)
			TYPETAG rightType = unaryConversionNoConversion(rightOperand);
			if(leftType == rightType && leftType == TYSIGNEDINT)
			{
				//msg("int && int");
				type = TYSIGNEDINT;
			}
			else if(leftType == rightType && leftType == TYDOUBLE)
			{
				//msg("double && double");
				type = TYDOUBLE;
			}
			else if(leftType == TYSIGNEDINT && rightType == TYDOUBLE)
			{
				//msg("int && double");
				b_convert(TYSIGNEDINT, TYDOUBLE);
				type = TYDOUBLE;
			}
			else if(leftType == TYDOUBLE && rightType == TYSIGNEDINT)
			{
				//msg("double && int");
				b_convert(TYSIGNEDINT, TYDOUBLE);
				type = TYDOUBLE;
			}
		}
	}
	else if(isVariableExpression(leftOperand))
	{// if the left operand is a variable

		//msg("left operand is variable");
		// leftOperand = evaluateExpression(leftOperand);

		TYPETAG leftType = getTypeTagFromExpression(leftOperand);

		// deref the left operand 
		// b_deref(leftType);
		leftType = unaryConversionNoConversion(leftOperand);

		if(leftType == TYSIGNEDINT && isIntExpression(rightOperand))
		{
			//error("convert push const, %d", rightOperand->u.valInt);
			b_push_const_int(rightOperand->u.valInt);
			type = TYSIGNEDINT;
		}
		else if(leftType == TYSIGNEDINT && isDoubleExpression(rightOperand))
		{
			b_convert(leftType, TYDOUBLE);
			b_push_const_double(rightOperand->u.valDouble);
			type = TYDOUBLE;
		}
		else if(leftType == TYDOUBLE && isIntExpression(rightOperand))
		{
			b_push_const_int(rightOperand->u.valInt);
			b_convert(TYSIGNEDINT, TYDOUBLE);
			type = TYDOUBLE;
		}
		else if(leftType == TYDOUBLE && isDoubleExpression(rightOperand))
		{
			b_push_const_double(rightOperand->u.valDouble);
			type = TYDOUBLE;
		}
		else if(isVariableExpression(rightOperand))
		{

			TYPETAG rightType = typeTagEN(rightOperand);
			rightType = unaryConversionNoConversion(rightOperand);
			//msg("rightType %d", rightType);

			if(leftType == TYSIGNEDINT && rightType == TYSIGNEDINT)
			{
				//msg("var op var: both integers");
				// b_push_const_int(rightOperand->u.valInt);
				// b_deref(rightType);
				// unaryConversion(rightOperand);
				//msg("deref questionable?");
				type = TYSIGNEDINT;
			}
			else if(leftType == TYSIGNEDINT && rightType == TYDOUBLE)
			{
				b_convert(leftType, TYDOUBLE);
				// b_deref(rightType);
				// unaryConversion(leftOperand);
				type = TYDOUBLE;
			}
			else if(leftType == TYDOUBLE && rightType == TYSIGNEDINT)
			{
				// b_deref(rightType);
				// rightType = unaryConversion(leftOperand);
				b_convert(rightType, TYDOUBLE);
				type = TYDOUBLE;
			}
			else if(leftType == TYDOUBLE && rightType == TYDOUBLE)
			{
				// b_deref(rightType);
				// unaryConversion(leftOperand);
				type = TYDOUBLE;
			}
		}
		else if(isEvaluatedExpression(rightOperand))
		{
			//msg("var op evaluated");
			
			TYPETAG rightType = unaryConversionNoConversion(rightOperand);

			if(leftType == rightType && leftType == TYSIGNEDINT)
			{
				type = TYSIGNEDINT;
			}
			else if(leftType == TYSIGNEDINT && rightType == TYDOUBLE)
			{
				//msg("int && double[Evaluated]");
				// b_convert(leftType, TYDOUBLE);
				type = TYDOUBLE;
			}
			else if(leftType == TYDOUBLE && rightType == TYSIGNEDINT)
			{
				// b_convert(rightType, TYDOUBLE);
				type = TYDOUBLE;
			}
			else if(leftType == rightType && leftType == TYDOUBLE)
			{
				type = TYDOUBLE;
			}
		}
	}
	else if(isVariableExpression(rightOperand))
	{// if the right operand is a variable
		TYPETAG rightType = typeTagEN(rightOperand);
		rightType = unaryConversionNoConversion(rightOperand);

		// deref the right operand 
		// b_deref(rightType);

		if(isIntExpression(leftOperand) && rightType == TYSIGNEDINT)
		{
			b_push_const_int(leftOperand->u.valInt);
			// b_deref(rightType);
			type = TYSIGNEDINT;
		}
		else if(isDoubleExpression(leftOperand) && rightType == TYSIGNEDINT)
		{
			b_push_const_double(leftOperand->u.valDouble);
			// b_deref(rightType);
			b_convert(rightType, TYDOUBLE);
			type = TYDOUBLE;
		}
		else if(isIntExpression(leftOperand) && rightType == TYDOUBLE)
		{
			b_push_const_int(leftOperand->u.valInt);
			b_convert(TYSIGNEDINT, TYDOUBLE);
			// b_deref(rightType);
			type = TYDOUBLE;
		}
		else if(isDoubleExpression(leftOperand) && rightType == TYDOUBLE)
		{
			b_push_const_double(leftOperand->u.valDouble);
			// b_deref(rightType);
			type = TYDOUBLE;
		}
	}
	//else if

	return type;
}

TYPETAG evaluateUnaryConversion(TYPETAG type)
{
	TYPETAG returnType, 
			currentType;

	returnType = currentType = type;

	// //msg("return type %d", returnType);

	// if(currentType == TYSIGNEDCHAR )
		// //msg("iffffffffffffffffffff");
	switch(currentType)
	{
		case TYSIGNEDLONGINT:
		case TYSIGNEDCHAR:
		case TYSIGNEDSHORTINT:
		case TYUNSIGNEDLONGINT:
		case TYUNSIGNEDSHORTINT:
		case TYUNSIGNEDINT:
		case TYUNSIGNEDCHAR:
			 	//msg("convert %d to %d", currentType, returnType);
			 	returnType = TYSIGNEDINT;
			 	break;
		case TYFLOAT:
		case TYLONGDOUBLE:
			 	//msg("convert %d to %d", currentType, returnType);
			 	returnType = TYDOUBLE;
			 	break;
	}
	
	// //msg("finished switch in unaryConversion");

	return returnType;
}

TYPETAG evaluateTypeExpression(EN expr)
{
	switch(expr->tag)
	{
		case TAG_CONST_INTEGER:
			return TYSIGNEDINT;
		case TAG_CONST_DOUBLE:
			return TYDOUBLE;

		case TAG_FUNCTION:
			return evalTypeFunctionExpression(expr);
		case TAG_VARIABLE:
			return evalTypeVariableExpression(expr);
		case TAG_UNARY:
			return evalTypeUnaryExpression(expr);
		case TAG_BINARY:
			return evalTypeBinaryExpression(expr);

		default:
			bug("Where's the expression tag in evaluateTypeExpression?");
	}
}

//Return an EN that holds the Integer or Double from the variable's value.
TYPETAG evalTypeVariableExpression(EN node)
{
	return getTypeTagFromExpression(node);
}
TYPETAG evalTypeFunctionExpression(EN node)
{
	return returnFuncTypeTag(node);
}
TYPETAG evalTypeUnaryExpression(EN node)
{
	return evaluateUnaryConversion(evaluateTypeExpression(node->u.unop.operand));
}
TYPETAG evalTypeBinaryExpression(EN node)
{
	TYPETAG leftType = evaluateTypeExpression(node->u.binop.leftOperand);
	TYPETAG rightType = evaluateTypeExpression(node->u.binop.rightOperand);

	return resolveTypeBinaryExpression(leftType, rightType);
}

TYPETAG resolveTypeBinaryExpression(TYPETAG leftType, TYPETAG rightType)
{
	if(leftType == rightType && leftType == TYSIGNEDINT)
		return TYSIGNEDINT;
	else if(leftType == rightType && leftType == TYDOUBLE)
		return TYDOUBLE;
	else if(leftType == TYSIGNEDINT && rightType == TYDOUBLE)
		return TYDOUBLE;
	else if(leftType == TYDOUBLE && rightType == TYSIGNEDINT)
		return TYDOUBLE;
	else if(leftType == TYPTR && rightType == TYSIGNEDINT || leftType == TYSIGNEDINT && rightType == TYPTR)
		return TYSIGNEDINT;
	else if(leftType == TYPTR && rightType == TYDOUBLE || leftType == TYDOUBLE && rightType == TYPTR)
		return TYDOUBLE;
	else if(leftType == rightType & leftType == TYPTR)
		return TYPTR;
	else 
		error("Invalid types passed to resolveTypeBinaryExpression()");
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
	if(isEvaluatedExpression(node))
	{
		msg("here1");
		return node->u.eval.type;
	}
	else if(isIntExpression(node))
	{
		msg("here2");
		return TYSIGNEDINT;
	}
	else if(isPointerExpression(node)) {
		msg("here2.5");
		msg("\tPointer node EXPR_TAG: %d", node->tag);
		//return node->tag;
		return TYPTR;
	}
	else if(isDoubleExpression(node))
	{
		msg("here3");
		return TYDOUBLE;
	}
	else if(isFunctionExpression(node))
	{
		msg("here4");
		return returnFuncTypeTag(node);
	}
	else
	{//if(isVariableExpression(node))
		msg("here5");
		int b;
		ST_ID stid = getIDFromVariableExpression(node);
		msg("here6");
		ST_DR stdr = st_lookup(node->u.varStID, &b);
		msg("here 7");
		if(stdr == NULL)
			return TYVOID;
		return ty_query(stdr->u.decl.type);
	}
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

BOOLEAN isPointerExpression(EN node)
{
	if(node!=NULL && node->tag == TAG_POINTER);
		return TRUE;
	return FALSE;
}

BOOLEAN isEvaluatedExpression(EN node)
{
	if(node!=NULL && node->tag == TAG_EVALUATED)
		return TRUE;
	return FALSE;
}

BOOLEAN isFunctionExpression(EN node)
{
	if(node!=NULL && node->tag == TAG_FUNCTION)
		return TRUE;
	return FALSE;
}

void printExpression(EN node)
{
	switch(node->tag)
	{
		case TAG_CONST_INTEGER:
			//msg("Integer Expression: %d", node->u.valInt);
			break;
		case TAG_CONST_DOUBLE:
			//msg("Double Expression: %f", node->u.valDouble);
			break;

		case TAG_FUNCTION:
			//msg("Function Expression");
			break;

		case TAG_VARIABLE:
			//msg("Variable Expression");
			break;

		case TAG_UNARY:
			//msg("Unary Expression %d", node->u.unop.op);
			break;
		
		case TAG_BINARY:
			//msg("Binary Expression %d", node->u.binop.op);
			break;

		case TAG_EVALUATED:
			//msg("Evaluated Expression");
			break;

			//TODO: REMOVE
		case TAG_EVAL_INTEGER:
			//msg("Evaluated Expression returning Integer");
			break;
		
		case TAG_EVAL_DOUBLE:
			//msg("Evaluated Expression returning Double");
			break;

		default:
			bug("Where's the expression tag in printExpression?");
	}
}

void evaluateSingleNode(EN node)
{
	switch(node->tag)
	{
		case TAG_CONST_INTEGER:
			b_push_const_int(node->u.valInt);
			break;
		case TAG_CONST_DOUBLE:
			b_push_const_double(node->u.valDouble);
			break;

		case TAG_FUNCTION:
			error("Function Expression in EvaluateSingleNode function");// b_func?
			break;

		case TAG_VARIABLE:
			b_deref(getTypeTagFromExpression(node));
			if(getTypeTagFromExpression(node)!= TYSIGNEDINT)
				b_convert(getTypeTagFromExpression(node),TYSIGNEDINT);
			break;
		default:
			;
			//error("Only pass single nodes");
			//evaluateExpression(node);
	}
}
