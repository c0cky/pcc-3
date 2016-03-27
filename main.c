#include "defs.h"
#include "types.h"
#include "symtab.h"
#include "bucket.h"

#include <stdio.h>
// ADD
#include "tree.h"

FILE *errfp;		/* file to which message.c will write */

/* For debugging purposes only */
#ifdef YYDEBUG
extern int yydebug;
#endif

int main()
{
	int status, yyparse();

	errfp = stderr;
	ty_types_init();
	st_init_symtab();
	init_bucket_module();
	// ADD
	ST_ID new;
	ST_DR stdr;
	BUCKET_PTR bp;
	DN dn;
	TYPE type;
	char *id = "a";
	// END ADD
	st_establish_data_dump_func(stdr_dump);
	st_establish_tdata_dump_func(stdr_dump);
	// ADD
	stdr = stdr_alloc();
	printf("int (*a[10])()");
	bp = update_bucket (NULL, INT_SPEC, NULL);
	type = build_base(bp);
	new = st_enter_id(id);
	dn = makeIdNode(new);
	dn = makeArrayNode(dn, 10);
	type = ty_build_basic(TYSIGNEDINT);
	type = ty_build_func(type, OLDSTYLE, NULL);
	type = ty_build_ptr(type, NO_QUAL);
	type = ty_build_array(type, TRUE, 10);
	stdr->tag = GDECL;
	stdr->u.decl.type = type;
	stdr->u.decl.sc = NO_SC;
	stdr->u.decl.err = FALSE;
	st_install(new, stdr);
	// END ADD
	
#ifdef YYDEBUG
	yydebug = 1;		/* DEBUG */
#endif
// REMOVED ->	status = yyparse();     /* Parse and translate the source */
#if 1
        if (status == 0)        /* If parse was successful */
            st_dump();          /* Dump the symbol table */
#endif
	return status;
}

