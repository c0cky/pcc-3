#include "expr.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EXPR make_const_node(long n)
{
	EXPR p;
	p = (EXPR)malloc(sizeof(EXPR_REC));
	p->tag = CONST_EXPR;
	p->u.const_.val = n;	
	return p;
}

EXPR make_var_node(char n)
{
	EXPR p;
	p = (EXPR)malloc(sizeof(EXPR_REC));
	p->tag = VAR_EXPR;
	p->u.var.name = n;	
	return p;
}

EXPR make_unop_node(UNOP_TYPE op, EXPR argument, int l_n)
{
	EXPR p;
	p = (EXPR)malloc(sizeof(EXPR_REC));
	p->tag = UNOP_EXPR;
	p->u.unop.op = op;
	p->u.unop.arg = argument;
	p->u.unop.line_num = l_n;
	return p;
}
EXPR make_binop_node(BINOP_TYPE bp, EXPR left_arg, EXPR right_arg)
{
	EXPR p;
	p = (EXPR)malloc(sizeof(EXPR_REC));
	//p = (EXPR)malloc(sizeof(EXPR_REC));
	p->tag = BINOP_EXPR;
	p->u.binop.op = bp;
	p->u.binop.l_arg = left_arg;
	p->u.binop.r_arg = right_arg;
	return p;
}
