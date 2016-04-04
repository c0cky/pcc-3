/*
 *
 * yacc/bison input for simplified C++ parser
 *
 */

%{

#include "defs.h"
#include "types.h"
#include "symtab.h"
#include "bucket.h"
#include "message.h"
#include <stdio.h>
#include "tree.h"

    int yylex();
    int yyerror(char *s);

    int sizeOfType(TYPETAG type);
    void globalDecl(DN dn, TYPE baseType, TYPE derivedType, BOOLEAN shouldDeclare);
	void GLD(DN dn, TYPE baseType, TYPE derivedType, BOOLEAN shouldDeclare);
	BUCKET_PTR buildBucket(BUCKET_PTR bucketPtr, TYPE_SPECIFIER typeSpec);
%}

%union {
	int	y_int;
	double	y_double;
	char *	y_string;
	TYPE_SPECIFIER y_typeSpec;
	BUCKET_PTR y_bucketPtr;
	ST_ID y_stID;
	DN y_DN;
	PARAM_LIST y_PL;
	BOOLEAN y_ref; // Flag for reference type?
};

%token IDENTIFIER INT_CONSTANT DOUBLE_CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token BAD

%start translation_unit
%%

 /*******************************
  * Expressions                 *
  *******************************/

primary_expr
	: identifier 
	| INT_CONSTANT { 
		//msg("INT_CONSTANT is %d", $<y_int>1);
		$<y_int>$ = $<y_int>1;
	}
	| DOUBLE_CONSTANT {
		// msg("DOUBLE CONSTANT is %f", $<y_double>$1);
		$<y_double>$ = $<y_double>1;
	}
	| STRING_LITERAL {
		// msg("STRING LITERAL is %s", $<y_string>$1);
		$<y_string>$ = $<y_string>1;
	}
	| '(' expr ')'
	;

postfix_expr
	: primary_expr
	| postfix_expr '[' expr ']'
	| postfix_expr '(' argument_expr_list_opt ')'
	| postfix_expr '.' identifier
	| postfix_expr PTR_OP identifier
	| postfix_expr INC_OP
	| postfix_expr DEC_OP
	;

argument_expr_list_opt
	: /* null derive */
	| argument_expr_list
	;

argument_expr_list
	: assignment_expr
	| argument_expr_list ',' assignment_expr
	;

unary_expr
	: postfix_expr 
	| INC_OP unary_expr
	| DEC_OP unary_expr
	| unary_operator cast_expr
	| SIZEOF unary_expr
	| SIZEOF '(' type_name ')'
	;

unary_operator
	: '&' | '*' | '+' | '-' | '~' | '!'
	;

cast_expr
	: unary_expr 
	| '(' type_name ')' cast_expr
	;

multiplicative_expr
	: cast_expr
	| multiplicative_expr '*' cast_expr
	| multiplicative_expr '/' cast_expr
	| multiplicative_expr '%' cast_expr
	;

additive_expr
	: multiplicative_expr
	| additive_expr '+' multiplicative_expr
	| additive_expr '-' multiplicative_expr
	;

shift_expr
	: additive_expr
	| shift_expr LEFT_OP additive_expr
	| shift_expr RIGHT_OP additive_expr
	;

relational_expr
	: shift_expr 
	| relational_expr '<' shift_expr
	| relational_expr '>' shift_expr
	| relational_expr LE_OP shift_expr
	| relational_expr GE_OP shift_expr
	;

equality_expr
	: relational_expr
	| equality_expr EQ_OP relational_expr
	| equality_expr NE_OP relational_expr
	;

and_expr
	: equality_expr
	| and_expr '&' equality_expr
	;

exclusive_or_expr
	: and_expr 
	| exclusive_or_expr '^' and_expr
	;

inclusive_or_expr
	: exclusive_or_expr 
	| inclusive_or_expr '|' exclusive_or_expr
	;

logical_and_expr
	: inclusive_or_expr 
	| logical_and_expr AND_OP inclusive_or_expr
	;

logical_or_expr
	: logical_and_expr 
	| logical_or_expr OR_OP logical_and_expr
	;

conditional_expr
	: logical_or_expr
	| logical_or_expr '?' expr ':' conditional_expr 
	;

assignment_expr
	: conditional_expr
	| unary_expr assignment_operator assignment_expr
	;

assignment_operator
	: '=' | MUL_ASSIGN | DIV_ASSIGN | MOD_ASSIGN | ADD_ASSIGN | SUB_ASSIGN
	| LEFT_ASSIGN | RIGHT_ASSIGN | AND_ASSIGN | XOR_ASSIGN | OR_ASSIGN
	;

expr
	: assignment_expr
	| expr ',' assignment_expr
	;

constant_expr
	: conditional_expr
	;

expr_opt
	: /* null derive */
	| expr
	;

 /*******************************
  * Declarations                *
  *******************************/

declaration
	: declaration_specifiers ';' { error("no declarator in declaration");}
	| declaration_specifiers init_declarator_list ';' {
		// Combine the type of declaration_specifiers (held in a bucket)
		// with the type of init_declarator_list HERE!!!!!
	}
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier { 
		$<y_bucketPtr>$ = buildBucket(NULL, $<y_typeSpec>1);
	}
	| type_specifier declaration_specifiers { 
		$<y_bucketPtr>$ = buildBucket($<y_bucketPtr>2, $<y_typeSpec>1);
	}
	| type_qualifier {
		$<y_bucketPtr>$ = buildBucket(NULL, $<y_typeSpec>1);
	}
	| type_qualifier declaration_specifiers {
		$<y_bucketPtr>$ = buildBucket($<y_bucketPtr>2, $<y_typeSpec>1);
	}
	;

init_declarator_list
	: init_declarator { 
		//msg("In init_declarator");
		// print_tree($<y_DN>1);

		TYPE baseType = build_base($<y_bucketPtr>0);
		TYPE derivedType = building_derived_type_and_install_st($<y_DN>1, baseType);
		GLD($<y_DN>1, baseType, derivedType, installSuccessful);
	}
	| init_declarator_list ',' init_declarator {
		//msg("In init_declarator");
		// building_derived_type_and_install_st($<y_DN>3, build_base($<y_bucketPtr>0));
		TYPE baseType = build_base($<y_bucketPtr>0);
		TYPE derivedType = building_derived_type_and_install_st($<y_DN>3, baseType);
		GLD($<y_DN>3, baseType, derivedType, installSuccessful);
	}
	;

init_declarator
	: declarator 
	| declarator '=' initializer
	;

storage_class_specifier	
	: TYPEDEF | EXTERN | STATIC | AUTO | REGISTER
	;

type_specifier
	: VOID { $<y_typeSpec>$ = VOID_SPEC;} 
	| CHAR { $<y_typeSpec>$ = CHAR_SPEC;} 
	| SHORT { $<y_typeSpec>$ = SHORT_SPEC;} 
	| INT { $<y_typeSpec>$ = INT_SPEC;} 
	| LONG { $<y_typeSpec>$ = LONG_SPEC;}
	| FLOAT { $<y_typeSpec>$ = FLOAT_SPEC;} 
	| DOUBLE { $<y_typeSpec>$ = DOUBLE_SPEC;} 
	| SIGNED { $<y_typeSpec>$ = SIGNED_SPEC;} 
	| UNSIGNED { $<y_typeSpec>$ = UNSIGNED_SPEC;}
	| struct_or_union_specifier { $<y_typeSpec>$ = STRUCT_SPEC;}
	| enum_specifier { $<y_typeSpec>$ = ENUM_SPEC;}
	| TYPE_NAME { $<y_typeSpec>$ = TYPENAME_SPEC;}
	;

struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'
	| struct_or_union identifier '{' struct_declaration_list '}'
	| struct_or_union identifier
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list_opt
	| type_qualifier specifier_qualifier_list_opt
	;

specifier_qualifier_list_opt
	: /* null derive */ {
		//msg("Found *");
	}
	| specifier_qualifier_list 
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expr
	| declarator ':' constant_expr
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM identifier '{' enumerator_list '}'
	| ENUM identifier
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: identifier
	| identifier '=' constant_expr
	;

type_qualifier
	: CONST { 
		$<y_typeSpec>$ = CONST_SPEC;
	}
	| VOLATILE {
		$<y_typeSpec>$ = VOLATILE_SPEC;
	}
	;

declarator
	: direct_declarator
	| pointer declarator {
		//if($<y_ref>1 == TRUE)
			//msg("Reference passed");
		//else;
			//msg("Found 'pointer declarator'");
		$<y_DN>$ = makePtrNode($<y_DN>2, $<y_ref>1);
		//}
	}
	;

direct_declarator
	: identifier
	| '(' declarator ')' { 
		//msg("Found ( declarator )");
		$<y_DN>$ = $<y_DN>2;
	}
	| direct_declarator '[' ']'
	| direct_declarator '[' constant_expr ']' { 
		//msg("Found array");
		if($<y_int>3 <= 0)
		{
			$<y_DN>$ = NULL;
			error("illegal array dimension");
		}
		else
			$<y_DN>$ = makeArrayNode($<y_DN>1, $<y_int>3);
	}
	| direct_declarator '(' parameter_type_list ')' {
			if(checkParam($<y_PL>3))
				$<y_DN>$ = makeFnNode($<y_DN>1, $<y_PL>3);
			else
				$<y_DN>$ = NULL;
	}
	| direct_declarator '(' ')' {
		$<y_DN>$ = makeFnNode($<y_DN>1, NULL);
	}
	| direct_declarator '(' identifier_list ')'
	;

pointer
	: '*' specifier_qualifier_list_opt
   	| '&' { $<y_ref>$ = TRUE;}
	;

parameter_type_list
	: parameter_list	{ $<y_PL>$ = $<y_PL>1;}
	| parameter_list ',' ELIPSIS { error("Elipsis not allowed"); }
	;

parameter_list
	: parameter_declaration	{
			$<y_PL>$ = $<y_PL>1;
			$<y_PL>$->prev = $<y_PL>1;
	}
	| parameter_list ',' parameter_declaration {
		if(($<y_PL>3 == NULL) || $<y_PL>1 == NULL)
			$<y_PL>$ = NULL;
		else {
			$<y_PL>$ = linkParams($<y_PL>1, $<y_PL>3);
		}
	}
	;

parameter_declaration
	: declaration_specifiers declarator {
		TYPE baseType = build_base($<y_bucketPtr>1);
		$<y_PL>$ = build_Param($<y_DN>2, baseType, NULL);
	}
	| declaration_specifiers { error("no id in parameter list"); $<y_PL>$ = NULL; }
	| declaration_specifiers abstract_declarator
	;

identifier_list
	: identifier
	| identifier_list ',' identifier
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expr ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expr ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expr
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

 /*******************************
  * Statements                  *
  *******************************/

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: identifier ':' statement
	| CASE constant_expr ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: expr_opt ';'
	;

selection_statement
	: IF '(' expr ')' statement
	| IF '(' expr ')' statement ELSE statement
	| SWITCH '(' expr ')' statement
	;

iteration_statement
	: WHILE '(' expr ')' statement
	| DO statement WHILE '(' expr ')' ';'
	| FOR '(' expr_opt ';' expr_opt ';' expr_opt ')' statement
	;

jump_statement
	: GOTO identifier ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN expr_opt ';'
	;

 /*******************************
  * Top level                   *
  *******************************/

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declarator compound_statement {
		//fprintf(stderr, "inside function_definition w {}\n");
	}
	| declaration_specifiers declarator compound_statement {
		//fprintf(stderr, "inside function_definition w {}\n");
	}
	;

 /*******************************
  * Identifiers                 *
  *******************************/

identifier
	: IDENTIFIER { 
		//msg("Found ID; Enrolling %s",$<y_string>1); 
		ST_ID varName = st_enter_id($<y_string>1);
		$<y_DN>$ = makeIdNode(varName);
	}
	;
%%

extern int column;

int sizeOfType(TYPETAG type)
{
	int returnedSizeOf = -1;

	// switch(type)
	// {
	// 	case TYFLOAT:
	// 		returnedSizeOf = sizeof(float);
	// 		break;
	// 	case TYDOUBLE:
	// 		returnedSizeOf = sizeof(double);
	// 		break;
	// 	case TYLONGDOUBLE:
	// 		returnedSizeOf = sizeof(long double);
	// 		break;
	// 	case TYSIGNEDLONGINT:
	// 		returnedSizeOf = sizeof(signed long int);
	// 		break;
 //    	case TYSIGNEDSHORTINT:
 //    		returnedSizeOf = sizeof(signed short int);
 //    		break;
 //    	case TYSIGNEDINT:
 //    		returnedSizeOf = sizeof(signed int);
 //    		break;
 //    	case TYUNSIGNEDLONGINT:
 //    		returnedSizeOf = sizeof(unsigned long int);
 //    		break;
 //  		case TYUNSIGNEDSHORTINT:
 //  			returnedSizeOf = sizeof(unsigned short int);
 //  			break;
 //  		case TYUNSIGNEDINT:
 //  			returnedSizeOf = sizeof(unsigned int);
 //  			break;
 //  		case TYUNSIGNEDCHAR:
 //  			returnedSizeOf = sizeof(unsigned char);
 //  			break;
 //  		case TYSIGNEDCHAR:
 //  			returnedSizeOf = sizeof(signed char);
 //  			break;
 //  		case TYPTR:
 //  			returnedSizeOf = 4; //4 Bytes
 //  			break;
 //  		default:
	// 	// TYVOID
 //  		// 		TYSTRUCT: TYUNION, TYENUM, TYARRAY, TYSET,
	//  	//    TYFUNC, TYBITFIELD, TYSUBRANGE, TYERROR
	//  		break;
	// }

	returnedSizeOf = get_size_basic(type);

	return returnedSizeOf;
}

void globalDecl(DN dn, TYPE baseType, TYPE derivedType, BOOLEAN shouldDeclare)
{
	if(!shouldDeclare)
		return;

	// fprintf(stderr, "Base | Derived: %d | %d\n", ty_query(baseType), ty_query(derivedType));

	//Get the id from the Symbol Table
	char* id = st_get_id_str( getSTID(dn) );
	// fprintf(stderr, "ID: %s\n", id);

	unsigned int size = 0;
	if(ty_query(derivedType) == TYARRAY)
	{//For Arrays

		//Then we want to create the size in bytes of the base type
		size = sizeOfType(ty_query(baseType));

		//Queries the array to return the size of the array
		unsigned int sizeOfArray;
		DIMFLAG aDimFlag;
		ty_query_array(derivedType, &aDimFlag, &sizeOfArray);

		// fprintf(stderr, "size of the array: %d\n", sizeOfArray);

		//Allocate for arrays
		b_global_decl(id, size, size*sizeOfArray);
		b_skip(size*sizeOfArray); //Only for no Initialization pieces


		//TODO: CHECK FOR MULTIPLE ARRAYS: int x[10][1000];

	}
	else if(ty_query(derivedType) == TYFUNC)
	{//For Functions, Do we even allocate for the back end data?
		//Maybe b_func_epilogue(char *);

	}
	else
	{
		size = sizeOfType(ty_query(derivedType));
		b_global_decl(id, size, size);
		b_skip(size);
		//b_alloc_int, double, etc....;
	}


}
void GLD(DN dn, TYPE baseType, TYPE derivedType, BOOLEAN shouldDeclare)
{
		if(!shouldDeclare)
			return;
		// if very last node is a pointer always will return align 4 size 4
		//BOOLEAN lastptrFlag = FALSE;
		//BOOLEAN ptrFlag = FALSE;
		BOOLEAN funcFlag = FALSE;
		int align = sizeOfType(ty_query(baseType));
		int size = 0;
		int array_total = 1;
		char* id; 
		while(dn != NULL)
		{
			switch(dn->tag) {
			case ARRAY:
				array_total *= dn->u.array_dim.dim;
				break;
			case PTR:
				align = 4;
				size = 4;
				array_total = 1;
				break;
			case FUNC:
				if(dn->n_node->tag == ID)
					funcFlag = TRUE;
				break;
			case REF:
				break;
			case ID:
				if(funcFlag)
					return;
				else
				{
					id = st_get_id_str( getSTID(dn) );
					size = array_total * align;
				}
				break;
			default:
				bug("where's the tag? \"stdr_dump\"");
				
			}
	
		dn = dn->n_node;
		}
		b_global_decl(id, align, size);
		b_skip(size);
}
int yyerror(char *s)
{
	error("%s (column %d)",s,column);
        return 0;  /* never reached */
}

BUCKET_PTR buildBucket(BUCKET_PTR bucketPtr, TYPE_SPECIFIER typeSpec) {
	BUCKET_PTR updatedBucket = update_bucket(bucketPtr, typeSpec, NULL);
	if (is_error_decl(updatedBucket)) {
		//error("Semantic error");
	}

	return updatedBucket;
}
