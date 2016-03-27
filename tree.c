#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Pass the ST_ID that is created from an enrollment; returns a Declarator Type Node
DN makeIdNode(ST_ID stid)
{
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
	DN d;
	d = (DN)malloc(sizeof(DECL_NODE));
	d->tag = PTR;
	d->n_node = dn;
	return d;
}	

// Pass the previous node, return new node
DN makeRefNode(DN dn)
{
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
	DN d;
	d = (DN)malloc(sizeof(DECL_NODE));
	d->tag = FUNC;
	d->u.param_list.pl = pl;
	d->n_node = dn;
	return d;
}

// Function to Traverse the Declarator's Derived types list, INPUT Top Node of Derived Type Built as First Parameter and Input Type from type_specifiers built from bucket (ty_query) as Second Parameter.

TYPE build_derived_type(DN dn, TYPE type)
{
	//fprintf(stderr, "\n Begin!\n");
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
		case ID:
			return type;
			break;
	default:
		bug("where's the tag? \"stdr_dump\"");
	}
	dn = dn->n_node;
	}
	bug("NULL Ptr but not ID");
	//return type;
}
