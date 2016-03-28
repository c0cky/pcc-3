#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "symtab.h"

// Pass the ST_ID that is created from an enrollment; returns a Declarator Type Node
DN makeIdNode(ST_ID stid)
{
	msg("making id node");
	DN d;
	d = (DN)malloc(sizeof(DECL_NODE));
	d->tag = ID;
	d->n_node = NULL;
	d->u.st_id.i = stid;
	return d;
}	

// Pass the dimension for array node, and any previous nodes, return new node
DN makeArrayNode(DN dn, unsigned int dimension)
{
	msg("making array node");
	DN d;
	d = (DN)malloc(sizeof(DECL_NODE));
	d->tag = ARRAY;
	d->n_node = dn;
	d->u.array_dim.dim = dimension;
	return d;
}	

// Pass the previous node, return new node
DN makePtrNode(DN dn)
{
	msg("making ptr node");
	DN d;
	d = (DN)malloc(sizeof(DECL_NODE));
	d->tag = PTR;
	d->n_node = dn;
	return d;
}	

// Pass the previous node, return new node
DN makeRefNode(DN dn)
{
	msg("making ref node");
	DN d;
	d = (DN)malloc(sizeof(DECL_NODE));
	d->tag = REF;
	d->n_node = dn;
	return d;
}	

// Pass second parameter for a list of parameters of function node created?
// Is PARAM_LIST correct object for this? From types.h
DN makeFnNode(DN dn, PARAM_LIST pl) 
{
	msg("making fn node");
	DN d;
	d = (DN)malloc(sizeof(DECL_NODE));
	d->tag = FUNC;
	d->u.param_list.pl = pl;
	d->n_node = dn;
	return d;
}

// Function to Traverse the Declarator's Derived types list, INPUT Top Node of Derived Type Built as 
// First Parameter and Input Type from type_specifiers built from bucket (ty_query) as Second Parameter.

void building_derived_type_and_install_st(DN dn, TYPE type)
{
	msg("building_derived_type");
	while(dn != NULL)
	{
		switch(dn->tag) {
			case ARRAY:
				type = ty_build_array(type, TRUE, dn->u.array_dim.dim);
				break;
			case PTR:
				type = ty_build_ptr(type, NO_QUAL);
				break;
			case FUNC:
				type = ty_build_func(type, OLDSTYLE, NULL);
				break;
			case REF:
				bug("Looking for REF \"stdr_dump\"");
				break;
			case ID: ;
				msg("Installing");
				ST_DR dr = stdr_alloc(); // Allocate space for the symtab data record

				dr->tag = GDECL;
				dr->u.decl.type = type;
				dr->u.decl.sc = NO_SC;
				dr->u.decl.err = FALSE;
				
				BOOLEAN result; 
				result = st_install(dn->u.st_id.i,dr);
				if (!result) {
					error("Error installing into symbol table.");
				}

				break;
			default:
				bug("where's the tag? \"stdr_dump\"");
		}
	
		dn = dn->n_node;
	}
}

void print_tree(DN dn) {
	msg("***PRINTING TREE***");
	int counter = 0;
	while (dn != NULL) {
		msg("\t[%d]:\n\t\tTAG: %s",counter, tagToString(dn->tag));

		counter += 1;
		dn = dn->n_node;
	}
}

char* tagToString(DECL_N_TAG tag) {
	char* strTag;
	switch(tag) {
		case ARRAY: 
			strTag = "ARRAY";
			break;
		case PTR:
			strTag = "PTR";
			break;
		case FUNC:
			strTag = "FUNC";
			break;
		case REF:
			bug("Looking for REF \"stdr_dump\"");
			break;
		case ID:
			strTag = "ID";
			break;
		default:
			bug("No tag found in tagToString");
	}

	return strTag;
}