#include "tree.h"

EXPR expr_list[3000]; // TODO: make dynamic
int expr_index = 1;

/******************************************************************************
* TREE EVALUATION
******************************************************************************/

int evaluate_tree(EXPR root_node) {
	//Initiation of recursion
	return eval(root_node);
}

int eval(EXPR node) {
	int nodeVal;

	// Check to see if we can return an already evaluated expr
	if (node->is_evaluated == 1 && node->is_line == 1) {
		if (node->tag == UNOP_EXPR) { // Always evaluate 
			if (node->u.unop.op != LINE_REF) { // a line reference
				return node->evaluated_val;
			}
		}
		else {
			if (node->tag != VAR_EXPR) { // Always evaluate a variable
				return node->evaluated_val;
			}
		}
	}

	if (node->tag == VAR_EXPR) {
		char alpha = node->u.var.name;
		nodeVal = get_val(alpha);
	}
	else if (node->tag == CONST_EXPR) {
		nodeVal = node->u.constant.val;
	}
	else if (node->tag == BINOP_EXPR) {
		int l = eval(node->u.binop.left_arg);
		int r =	eval(node->u.binop.right_arg);

		switch(node->u.binop.op) {
			case MINUS:
				nodeVal = l - r;
				break;
			case PLUS:
				nodeVal = l + r;
				break;
			case MULT:
				nodeVal = l * r;
				break;
			case DIV:
				nodeVal = l / r;
				break;
			case MOD:
				nodeVal = l % r;
				break;
		}
	}
	else if (node->tag == UNOP_EXPR) {
		int i = eval(node->u.unop.arg);

		switch(node->u.unop.op) {
			case UMINUS:
				nodeVal = -i;
				break;
			case LINE_REF:
				nodeVal = evaluate_tree(node->u.unop.arg);
				break;
		}
	}
	
	set_node_as_evaluated(node, nodeVal);
	
	return nodeVal;
}

void set_node_as_evaluated(EXPR node, int eval_val) {
    /*//fprintf(stderr,"\tSetting node ");
	print_expr(node);
	//fprintf(stderr," as evaluated = %d\n", eval_val);*/
	node->is_evaluated = 1;
	node->evaluated_val = eval_val;
}

void set_all_nodes_unevaluated() {
    //fprintf(stderr,"\tSETTING NODES (",(expr_index - 1));
	for (int x = 1; x < expr_index; x++) {
		//fprintf(stderr,", %d",x);
		(expr_list[x])->is_evaluated = 0;
	}
	//fprintf(stderr,") TO UNEVALUATED\n");
}

/******************************************************************************
* NODE CREATION
******************************************************************************/

EXPR make_const_node (int value) {
	EXPR node;
	node = (EXPR) malloc(sizeof(TREE_NODE)); // Allocate space for the node
	node->tag = CONST_EXPR;
	node->u.constant.val = value;
	node->is_evaluated = 0;
	return node;
}

EXPR make_var_node (char var) {
	EXPR node;
	node = (EXPR) malloc(sizeof(TREE_NODE)); // Allocate space for the node
	node->tag = VAR_EXPR;
	node->u.var.name = var;
	node->is_evaluated = 0;
	return node;
}

EXPR make_binop_node(BINOP_TYPE op_type, EXPR l_arg_node, EXPR r_arg_node) {
	EXPR node;
	node = (EXPR) malloc(sizeof(TREE_NODE)); // Allocate space for the node
	node->tag = BINOP_EXPR;
	node->is_evaluated = 0;
	switch (op_type) {
		case PLUS:
			node->u.binop.op = PLUS;
			break;
		case MINUS:
			node->u.binop.op = MINUS;
			break;
		case MULT:
			node->u.binop.op = MULT;
			break;
		case DIV:
			node->u.binop.op = DIV;
			break;
		case MOD:
			node->u.binop.op = MOD;
			break;
	}
		
	node->u.binop.left_arg = l_arg_node;
	node->u.binop.right_arg = r_arg_node;

	return node;
}

EXPR make_unop_node(UNOP_TYPE op_type, EXPR arg_node) {
	EXPR node;
	node = (EXPR) malloc(sizeof(TREE_NODE)); // Allocate space for the node
	node->tag = UNOP_EXPR;
	node->is_evaluated = 0;
	switch (op_type) {
		case UMINUS:
			node->u.unop.op = UMINUS;
			break;
		case LINE_REF:
			node->u.unop.op = LINE_REF;
			break;
	}
		
	node->u.unop.arg = arg_node;

	return node;
}

void add_to_expr_list(EXPR node) {
    expr_list[expr_index] = node;
    expr_index += 1;
}

EXPR get_from_expr_list(int index) {
    if (index <= 0) {
        char *error_msg = "ERROR: attempting to access an out-of-bounds line (attempted line access <= 0. Must be >= 1).";
        yyerror(error_msg);
    }
    else if (index >= expr_index) {
        // OUT OF BOUNDS ERROR
        char *error_msg = "ERROR: attempting to access out of bounds line (attempted line access > number of lines).";
        yyerror(error_msg);
    }
    else {
    	if (expr_list[index]->is_evaluated == 1) {
    		//fprintf(stderr,"\t#%d IS evaluated\n", index);
    	}
    	else {
			//fprintf(stderr,"\t#%d is NOT evaluated\n", index);
    	}
    	return expr_list[index];
    }
    
}

/******************************************************************************
* DEV HELPERS
******************************************************************************/
void print_expr(EXPR root_node) {
	//Initiation of recursion
	fprintf(stderr,"[ ");
	print_expr_recur(root_node);
	fprintf(stderr," ] ");
}

void print_expr_recur(EXPR node) {

	if (node->tag == VAR_EXPR) {
		char alpha = node->u.var.name;
		fprintf(stderr," %c ", alpha);
	}
	else if (node->tag == CONST_EXPR) {
		fprintf(stderr," %d ",node->u.constant.val);
	}
	else if (node->tag == BINOP_EXPR) {
		switch(node->u.binop.op) {
			case MINUS:
				fprintf(stderr," l - r");
				break;
			case PLUS:
				fprintf(stderr," l + r");
				break;
			case MULT:
				fprintf(stderr," l * r");
				break;
			case DIV:
				fprintf(stderr," l / r");
				break;
			case MOD:
				fprintf(stderr," l \% r");
				break;
		}
	}
	else if (node->tag == UNOP_EXPR) {
		switch(node->u.unop.op) {
			case UMINUS:
				fprintf(stderr," -arg");
				break;
			case LINE_REF:
				fprintf(stderr," #arg "); 
				break;
		}
	}
}