#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "symtab.h"
#include "message.h"

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

		// Reference ?? no struct needed? Maybe a check?

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

// Pass the previous node, return new node
DN makePtrNode(DN dn);

// Pass the previous node, return new node
DN makeRefNode(DN dn);

// Pass second parameter for a list of parameters of function node created?
// Is PARAM_LIST correct object for this? From types.h
DN makeFnNode(DN dn, PARAM_LIST pl); 

// Function to Traverse the Declarator's Derived types list, INPUT Top Node of Derived Type Built as First Parameter and Input Type from type_specifiers built from bucket (ty_query) as Second Parameter.
void building_derived_type_and_install_st(DN dn, TYPE type);

void print_tree(DN dn);
char* tagToString(DECL_N_TAG tag);
#endif
