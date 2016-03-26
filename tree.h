
#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// The Declarator's Derived Types Tags for each node in the tree
typedef enum {ARRAY, PTR, FUNC, REF, ID} DECL_N_TAG;

// A tree node to hold and build the proper derived types of the declarator given
typedef struct tn{
	DECL_N_TAG tag;
	struct tn *n_node;
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

// Pass the 
DN makeArrayNode(DN dn, unsigned int dimension);

DN makePtrNode(DN dn);

DN makeRefNode(DN dn);

// Pass second parameter for a list of parameters of function node created?
// Is PARAM_LIST correct object for this? From types.h
DN makeFnNode(DN dn, PARAM_LIST pl); 

#endif
