#ifndef EXPR_H
#define EXPR_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum {CONST_EXPR, VAR_EXPR, UNOP_EXPR, BINOP_EXPR} EXPR_TAG_TYPE;

// Unary operators - , #
typedef enum {UN_MINUS, UN_PLUS, UN_LINE_REF} UNOP_TYPE;

// Binary operators + - * / %
typedef enum {PLUS, MINUS, MUL, DIV, MOD} BINOP_TYPE;

typedef struct tn{
	EXPR_TAG_TYPE tag;
	union{
		struct{
			long val;
		} const_;

		struct{
			char name;
		} var;	
		 // Unary op has one child
		struct {
			UNOP_TYPE op;
			int line_num;
			struct tn *arg;
		} unop;
		// Binary Op has 2 children
		struct{
			BINOP_TYPE op;
			struct tn *l_arg, *r_arg;
		} binop;
	} u;
} EXPR_REC, *EXPR;

// will EXPR be a void*?
EXPR make_const_node(long n);

EXPR make_var_node(char n);

EXPR make_unop_node(UNOP_TYPE op, EXPR argument, int l_n);

EXPR make_binop_node(BINOP_TYPE bp, EXPR left_arg, EXPR right_arg);

long traverse(EXPR);
#endif
