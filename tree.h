#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "symtab.h"
#include "message.h"


//CHECKING FOR ERRORS After Installing in the Symbol Table.
BOOLEAN installSuccessful;

// The Declarator's Derived Types Tags for each node in the tree
typedef enum {ARRAY, PTR, FUNC, REF, ID} DECL_N_TAG;

// A tree node to hold and build the proper derived types of the declarator given
typedef struct dn {
	DECL_N_TAG tag;
	struct dn *n_node;
	union{
		// Dimension of array
		struct{
			unsigned int dim;
		} array_dim;

		 // Pointer ?? no struct needed?
		 
		 // For parameters of function, from types.h (unsure if correct)
		struct {
			PARAM_LIST pl;
		} param_list;

		// ST_ID for the bottom node of list after enrolled.
		struct{
			ST_ID i;
		} st_id;	
	} u;
} DECL_NODE, *DN;

// Pass the ST_ID that is created from an enrollment; returns a Declarator Type Node
DN makeIdNode(ST_ID stid);

// Pass the 
DN makeArrayNode(DN dn, unsigned int dimension);

// DN makePtrNode(DN dn);

DN makeRefNode(DN dn);

// Pass the dimension for array node, and any previous nodes, return new node
DN makeArrayNode(DN dn, unsigned int dimension);

// Pass the previous node, return new node, Also used for reference
DN makePtrNode(DN dn, BOOLEAN is_ref);

// Pass the previous node, return new node NOT USED, use makePtrNode instead
// DN makeRefNode(DN dn);

// Pass second parameter for a list of parameters of function node created?
// Is PARAM_LIST correct object for this? From types.h
DN makeFnNode(DN dn, PARAM_LIST pl); 

// Function to Traverse the Declarator's Derived types list, INPUT Top Node of Derived Type Built as First Parameter and Input Type from type_specifiers built from bucket (ty_query) as Second Parameter.
TYPE building_derived_type_and_install_st(DN dn, TYPE initialType, STDR_TAG stdr_tag);

// Build PArameter list, pass the DN, the bucket type, and parameter list, if first param, then NULL)
// Builds the next parameter and returns it (if null, returns 1st parameter) previous node of all
// parameter nodes returns the head node of list
PARAM_LIST build_Param(DN dn, TYPE initialType, PARAM_LIST pl);

PARAM_LIST linkParams(PARAM_LIST pl1, PARAM_LIST new_pl);

// Check Params for duplicate IDs
BOOLEAN checkParam(PARAM_LIST pl);
//Returns the ST_ID from the list or 0 if it does not exist.
ST_ID getSTID(DN dn);

void print_tree(DN dn);
char* tagToString(DECL_N_TAG tag);

// ******************* PROJ 2 ADD
// typedef enum {CONST_EXPR, VAR_EXPR, UNOP_EXPR, BINOP_EXPR} EXPR_TAG_TYPE;

// // Unary operators - , #
// typedef enum {UN_MINUS, UN_PLUS, UN_LINE_REF} UNOP_TYPE;

// // Binary operators + - * / %
// typedef enum {PLUS, MINUS, MUL, DIV, MOD} BINOP_TYPE;

// // Expression Node (en)
// typedef struct en{
// 	EXPR_TAG_TYPE tag;
// 	union{
// 		struct{
// 			long val;
// 		} const_;

// 		struct{
// 			ST_ID st_id;
// 		} var;	
// 		 // Unary op has one child
// 		struct {
// 			UNOP_TYPE op;
// 			int line_num;
// 			struct en *arg;
// 		} unop;
// 		// Binary Op has 2 children
// 		struct{
// 			BINOP_TYPE op;
// 			struct en *l_arg, *r_arg;
// 		} binop;
// 	} u;
// } EXPR_REC, *EXPR;

// EXPR makeID_ExprN(ST_ID);

// long traverse(EXPR e);
// ***********************END OF PROJ2 ADD

#endif
