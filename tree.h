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
TYPE building_derived_type_and_install_st(DN dn, TYPE initialType);

// Build PArameter list, pass the DN, the bucket type, and parameter list, if first param, then NULL)
// Builds the next parameter and returns it (if null, returns 1st parameter) previous node of all
// parameter nodes returns the head node of list
PARAM_LIST build_Param(DN dn, TYPE initialType, PARAM_LIST pl);

PARAM_LIST linkParams(PARAM_LIST pl1, PARAM_LIST new_pl);
//Returns the ST_ID from the list or 0 if it does not exist.
ST_ID getSTID(DN dn);

void print_tree(DN dn);
char* tagToString(DECL_N_TAG tag);

#endif
