#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "symtab.h"

// Pass the ST_ID that is created from an enrollment; returns a Declarator Type Node
DN makeIdNode(ST_ID stid)
{
	//msg("making id node");
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
	//msg("making array node");
	if(dn->tag == FUNC)
		error("cannot have function returning array");
	DN d;
	d = (DN)malloc(sizeof(DECL_NODE));
	d->tag = ARRAY;
	d->n_node = dn;
	d->u.array_dim.dim = dimension;
	return d;
}	

// Pass the previous node, return new node
DN makePtrNode(DN dn, BOOLEAN is_ref)
{
	//msg("making ptr node");
	DN d;
	d = (DN)malloc(sizeof(DECL_NODE));
	d->tag = PTR;
	if(is_ref == TRUE)
		d->tag = REF;
	d->n_node = dn;
	return d;
}	

// Pass the previous node, return new node
DN makeRefNode(DN dn)
{
	//msg("making ref node");
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
	//msg("making fn node");
	if(dn->tag == FUNC)
		error("cannot have function returning function");
	if(dn->tag == ARRAY)
		error("cannot have array of functions");
	DN d;
	d = (DN)malloc(sizeof(DECL_NODE));
	d->tag = FUNC;
	d->u.param_list.pl = pl;
	d->n_node = dn;
	return d;
}

// Function to Traverse the Declarator's Derived types list, INPUT Top Node of Derived Type Built as 
// First Parameter and Input Type from type_specifiers built from bucket (ty_query) as Second Parameter.
TYPE building_derived_type_and_install_st(DN dn, TYPE initialType)
{
	TYPE type = initialType;
	//BOOLEAN val_array = TRUE;
	installSuccessful = FALSE;

	//msg("building_derived_type");
	while(dn != NULL)
	{
		switch(dn->tag) {
			case ARRAY:
				if(dn->u.array_dim.dim <= 0)
				{
					error("illegal array dimension");
					return;
				}
				else
				type = ty_build_array(type, TRUE, dn->u.array_dim.dim);
				break;
			case PTR:
				//fprintf(stderr, "Inside of PTR Switch\n");
				type = ty_build_ptr(type, NO_QUAL);
				break;
			case FUNC:
				if(dn->u.param_list.pl == NULL)
				type = ty_build_func(type, OLDSTYLE, NULL);
				else
				type = ty_build_func(type, OLDSTYLE, dn->u.param_list.pl->prev);
				break;
			case REF:
				bug("Looking for REF \"stdr_dump\"");
				break;
			case ID: ;
				//msg("Installing");
				ST_DR dr = stdr_alloc(); // Allocate space for the symtab data record

				dr->tag = GDECL;
				dr->u.decl.type = type;
				dr->u.decl.sc = NO_SC;
				dr->u.decl.err = FALSE;
				
				BOOLEAN result; 
				result = st_install(dn->u.st_id.i,dr);
				if (!result) {
					error("duplicate declaration for %s", st_get_id_str(dn->u.st_id.i));
					error("duplicate definition of '%s'", st_get_id_str(dn->u.st_id.i));
				}
				else
				{
					installSuccessful = TRUE;
				}

				break;
			default:
				bug("where's the tag? \"stdr_dump\"");
		}
	
		dn = dn->n_node;
	}

	return type;
}
// For function_defintion production NOT USED
void building_checkFunction(DN dn, TYPE initialType)
{
				//error("Function %s\n", id);
		ST_ID stid = getSTID(dn);		
		if (initialType == NULL)
			initialType = ty_build_basic(TYSIGNEDINT);		
		TYPE type;
		int b;
		BOOLEAN result = FALSE;
		char *f = st_get_id_str(stid);
		ST_DR stdr = st_lookup(stid, &b);
		if(stdr == NULL) // if STDR is NULL then we build it
		{		if(dn->u.param_list.pl == NULL)
				type = ty_build_func(initialType, OLDSTYLE, NULL);
				else
				type = ty_build_func(initialType, OLDSTYLE, dn->u.param_list.pl->prev);
			// send in node to check stuff
		//BOOLEAN result = funcDeclCheck($<y_DN>1);
			// Prologue into function and enter block (Back_end and Symbol Table stuff)
		
				ST_DR dr = stdr_alloc(); // Allocate space for the symtab data record

				dr->tag = FDECL;
				dr->u.decl.type = type;
				dr->u.decl.sc = NO_SC;
				dr->u.decl.err = FALSE;
				
				BOOLEAN result; 
				result = st_install(dn->u.st_id.i,dr);
				if (!result) {
					error("This should not happen,duplicate declaration for %s", f);
					error("duplicate definition of '%s'", f);
		}
		else
		{
				if(ty_query(stdr->u.decl.type) != TYFUNC)
				{ error("duplicate or incompatible function declaration '%s' FuncDeclCheck not TYFUNC", f);  
					//return FALSE;		//bug("error not a function"); 
				}
				else
				{
					if(stdr->tag == GDECL)
					{
						//error("Is GDECL switch to FDECL");
						stdr->tag = FDECL;
						//return TRUE;
					}
					else if(stdr->tag == FDECL)
					{
						error("duplicate or incompatible function declaration '%s'", f);
						//return FALSE;
					}
					else
					{	error("Wrong type(not a function ID)"); 
						//return FALSE;
					 }
					//stdr->u.decl.type = type;
				}
		
		}
		if(result)
			{
				b_func_prologue (f); 
				st_enter_block();
				funcDefBuildParams(dn);
			}
		//$<y_ref>$ = result;
		}
}

// Build Parameter type, PARAM_LIST pl not used (only if parameter has its own param list)
PARAM_LIST build_Param(DN dn, TYPE initialType, PARAM_LIST pl)
{
	if(dn == NULL)
	{
		error("no id in declaration");
		return NULL;
	}
	TYPE type = initialType;
	PARAM_LIST pl1 = plist_alloc();
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
				// this will have to be fixed
				type = ty_build_func(type, PROTOTYPE, dn->u.param_list.pl);
				break;
			case REF:
				pl1->is_ref = TRUE;
				break;
			case ID: 
				pl1->id = dn->u.st_id.i;
				pl1->type = type;
				pl1->sc = NO_SC;
				pl1->err = FALSE;

				break;
			default:
				bug("where's the tag? in Param\"stdr_dump\"");
		}
	
		dn = dn->n_node;
	}
	
	return pl1;
}

// Links all Parameters to create PARAM_LIST object, all prev ptrs are head ptr.
PARAM_LIST linkParams(PARAM_LIST pl1, PARAM_LIST new_pl)
{
	while(pl1->next != NULL)
		pl1 = pl1->next;
	new_pl->prev = pl1->prev;	
	pl1->next = new_pl;
	
	return pl1->prev; 
}

BOOLEAN checkParam(PARAM_LIST pl)
{
	PARAM_LIST plc = pl;
	while(pl)
	{	
		plc = pl->next;
		while(plc)
		{
			if(pl->id == plc->id)
			{				
				error("duplicate parameter declaration for '%s'", st_get_id_str(pl->id));
				return FALSE;
			}			
			plc = plc->next;
		}
		pl = pl->next;
	}
	return TRUE;
}
			
		
//Returns the ST_ID from the list or 0 if it does not exist.
ST_ID getSTID(DN dn)
{
	ST_ID stId = NULL;

	while(dn != NULL)
	{
		if(dn->tag == ID) 
		{
			stId = dn->u.st_id.i;
			break;
		}
	
		dn = dn->n_node;
	}

	return stId;
}

void print_tree(DN dn) {
	//msg("***PRINTING TREE***");
	int counter = 0;
	while (dn != NULL) {
		//msg("\t[%d]:\n\t\tTAG: %s",counter, tagToString(dn->tag));

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
