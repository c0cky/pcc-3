/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "gram.y" /* yacc.c:339  */


	#include "types.h"
	#include "symtab.h"
	#include "bucket.h"
	#include "message.h"
	#include "tree.h"
	#include "expr.h"
	#include <stdio.h>
	#include "defs.h"

    int yylex();
    int yyerror(char *s);

    int sizeOfType(TYPETAG type);
    void globalDecl(DN dn, TYPE baseType, TYPE derivedType, BOOLEAN shouldDeclare);
	void GLD(DN dn, TYPE baseType, TYPE derivedType, BOOLEAN shouldDeclare);
	BUCKET_PTR buildBucket(BUCKET_PTR bucketPtr, TYPE_SPECIFIER typeSpec);
	
	// Added for Proj 2
	BOOLEAN funcDeclCheck(DN dn);
	BOOLEAN st_IDCheck(ST_ID stid);
	TYPETAG getTypeTag_STID(ST_ID stid);
	void funcDefBuildParams(DN node);
	//

#line 93 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    INT_CONSTANT = 259,
    DOUBLE_CONSTANT = 260,
    STRING_LITERAL = 261,
    SIZEOF = 262,
    PTR_OP = 263,
    INC_OP = 264,
    DEC_OP = 265,
    LEFT_OP = 266,
    RIGHT_OP = 267,
    LE_OP = 268,
    GE_OP = 269,
    EQ_OP = 270,
    NE_OP = 271,
    AND_OP = 272,
    OR_OP = 273,
    MUL_ASSIGN = 274,
    DIV_ASSIGN = 275,
    MOD_ASSIGN = 276,
    ADD_ASSIGN = 277,
    SUB_ASSIGN = 278,
    LEFT_ASSIGN = 279,
    RIGHT_ASSIGN = 280,
    AND_ASSIGN = 281,
    XOR_ASSIGN = 282,
    OR_ASSIGN = 283,
    TYPE_NAME = 284,
    TYPEDEF = 285,
    EXTERN = 286,
    STATIC = 287,
    AUTO = 288,
    REGISTER = 289,
    CHAR = 290,
    SHORT = 291,
    INT = 292,
    LONG = 293,
    SIGNED = 294,
    UNSIGNED = 295,
    FLOAT = 296,
    DOUBLE = 297,
    CONST = 298,
    VOLATILE = 299,
    VOID = 300,
    STRUCT = 301,
    UNION = 302,
    ENUM = 303,
    ELIPSIS = 304,
    CASE = 305,
    DEFAULT = 306,
    IF = 307,
    ELSE = 308,
    SWITCH = 309,
    WHILE = 310,
    DO = 311,
    FOR = 312,
    GOTO = 313,
    CONTINUE = 314,
    BREAK = 315,
    RETURN = 316,
    BAD = 317
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INT_CONSTANT 259
#define DOUBLE_CONSTANT 260
#define STRING_LITERAL 261
#define SIZEOF 262
#define PTR_OP 263
#define INC_OP 264
#define DEC_OP 265
#define LEFT_OP 266
#define RIGHT_OP 267
#define LE_OP 268
#define GE_OP 269
#define EQ_OP 270
#define NE_OP 271
#define AND_OP 272
#define OR_OP 273
#define MUL_ASSIGN 274
#define DIV_ASSIGN 275
#define MOD_ASSIGN 276
#define ADD_ASSIGN 277
#define SUB_ASSIGN 278
#define LEFT_ASSIGN 279
#define RIGHT_ASSIGN 280
#define AND_ASSIGN 281
#define XOR_ASSIGN 282
#define OR_ASSIGN 283
#define TYPE_NAME 284
#define TYPEDEF 285
#define EXTERN 286
#define STATIC 287
#define AUTO 288
#define REGISTER 289
#define CHAR 290
#define SHORT 291
#define INT 292
#define LONG 293
#define SIGNED 294
#define UNSIGNED 295
#define FLOAT 296
#define DOUBLE 297
#define CONST 298
#define VOLATILE 299
#define VOID 300
#define STRUCT 301
#define UNION 302
#define ENUM 303
#define ELIPSIS 304
#define CASE 305
#define DEFAULT 306
#define IF 307
#define ELSE 308
#define SWITCH 309
#define WHILE 310
#define DO 311
#define FOR 312
#define GOTO 313
#define CONTINUE 314
#define BREAK 315
#define RETURN 316
#define BAD 317

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 34 "gram.y" /* yacc.c:355  */

	int	y_int;
	double	y_double;
	char *	y_string;
	TYPE_SPECIFIER y_typeSpec;
	BUCKET_PTR y_bucketPtr;
	ST_ID y_stID;
	DN y_DN;
	PARAM_LIST y_PL;
	BOOLEAN y_ref; // Flag for reference type?

	//Expressions
	OP_UNARY y_unop;
	OP_BINARY y_binop;
	EN y_EN;
	AL y_arg_list;


#line 276 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 291 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  211
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  347

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,     2,     2,     2,    76,    69,     2,
      63,    64,    70,    71,    68,    72,    67,    75,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    82,    84,
      77,    83,    78,    81,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,    79,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    85,    80,    86,    73,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    80,    88,    98,   103,   109,   110,   111,
     112,   113,   114,   115,   119,   120,   124,   125,   131,   132,
     133,   134,   137,   138,   142,   144,   146,   148,   150,   152,
     157,   158,   162,   163,   167,   171,   178,   179,   183,   190,
     191,   195,   202,   203,   207,   211,   215,   222,   223,   227,
     234,   235,   242,   243,   250,   251,   258,   259,   266,   267,
     274,   275,   279,   280,   288,   289,   289,   289,   289,   289,
     290,   290,   290,   290,   290,   294,   295,   299,   302,   304,
     312,   313,   320,   321,   322,   325,   328,   331,   337,   345,
     355,   356,   360,   360,   360,   360,   360,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   379,
     380,   381,   385,   386,   390,   391,   395,   399,   400,   404,
     407,   411,   412,   416,   417,   418,   422,   423,   424,   428,
     429,   433,   434,   438,   441,   447,   448,   459,   460,   464,
     465,   468,   474,   477,   481,   483,   487,   488,   492,   496,
     506,   510,   511,   515,   516,   520,   521,   525,   526,   527,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   543,
     544,   547,   549,   553,   554,   562,   563,   564,   565,   566,
     567,   571,   572,   573,   577,   578,   579,   580,   584,   585,
     589,   590,   594,   604,   605,   606,   610,   611,   612,   616,
     617,   618,   619,   627,   628,   632,   633,   638,   637,   665,
     664,   716
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INT_CONSTANT",
  "DOUBLE_CONSTANT", "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP",
  "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC",
  "AUTO", "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT", "UNION",
  "ENUM", "ELIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "BAD", "'('", "')'",
  "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'",
  "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'",
  "'{'", "'}'", "$accept", "primary_expr", "postfix_expr",
  "argument_expr_list_opt", "argument_expr_list", "unary_expr",
  "unary_operator", "cast_expr", "multiplicative_expr", "additive_expr",
  "shift_expr", "relational_expr", "equality_expr", "and_expr",
  "exclusive_or_expr", "inclusive_or_expr", "logical_and_expr",
  "logical_or_expr", "conditional_expr", "assignment_expr",
  "assignment_operator", "expr", "constant_expr", "expr_opt",
  "declaration", "declaration_specifiers", "init_declarator_list",
  "init_declarator", "storage_class_specifier", "type_specifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "specifier_qualifier_list_opt",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "type_qualifier", "declarator",
  "direct_declarator", "pointer", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "comma_opt", "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "@1", "@2", "identifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    40,    41,    91,    93,    46,    44,    38,
      42,    43,    45,   126,    33,    47,    37,    60,    62,    94,
     124,    63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -123

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-123)))

#define YYTABLE_NINF -210

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     891,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,     4,   109,  -123,  1066,  -123,     3,  1046,  1046,  -123,
      11,  -123,  1046,  -123,    -1,   109,   799,  -123,  -123,  -123,
       5,   -69,   -22,  1066,  -123,  -123,  1066,  -123,   -37,  -123,
      80,  -123,  -123,  1066,   -35,  -123,    35,   477,   296,  -123,
    -123,  -123,   -48,  -123,    -5,     5,  -123,  -123,  -123,   109,
    -123,   597,    35,   732,  -123,    67,  1066,   344,  -123,  -123,
     214,    38,    55,  -123,   -31,  -123,  -123,  -123,  -123,   720,
     741,   741,   648,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,   251,  -123,   753,  -123,   -24,   117,    13,   -10,   169,
      57,    53,    91,   118,    -7,  -123,    81,  -123,     5,  -123,
     753,   -45,  -123,    72,   597,   413,  -123,  -123,  -123,  -123,
    -123,  -123,   753,   -36,  -123,    86,   927,   753,   133,   157,
     160,   162,   562,   166,     5,   147,   149,   753,  -123,  -123,
     171,   161,  -123,     3,  -123,  -123,  -123,   416,   488,  -123,
    -123,  -123,  -123,   170,   845,   634,  -123,   214,  -123,    21,
    -123,  1025,  -123,     5,   648,  -123,   753,  -123,  -123,    61,
      -9,   190,     5,  -123,  -123,   753,   753,     5,  -123,   753,
     753,   753,   753,   753,   753,   753,   753,   753,   753,   753,
     753,   753,   753,   753,   753,   753,   753,   753,  -123,  -123,
    -123,  -123,  -123,   188,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,   753,  -123,    67,  -123,   753,
    -123,   175,   562,   753,   753,   753,   210,   753,   182,  -123,
    -123,   184,   753,  -123,  -123,  -123,   525,  -123,  -123,   562,
    -123,   205,   211,  -123,   212,  -123,   989,   669,  -123,  -123,
    -123,   216,  -123,   947,    -9,  -123,   753,  -123,   217,   218,
    -123,    88,  -123,  -123,  -123,  -123,   -24,   -24,   117,   117,
      13,    13,    13,    13,   -10,   -10,   169,    57,    53,    91,
     118,   -39,   597,   199,  -123,  -123,  -123,   562,  -123,    75,
      77,    84,   224,   204,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,   227,  -123,   226,  -123,  -123,  -123,   753,
    -123,   753,  -123,  -123,  -123,   562,   562,   562,   753,   753,
    -123,  -123,  -123,  -123,   240,  -123,  -123,   113,   220,   562,
     223,   753,  -123,  -123,   230,   562,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   211,   108,    92,    93,    94,    95,    96,    98,    99,
     100,   101,   104,   105,   102,   103,   133,   134,    97,   112,
     113,     0,     0,   145,   119,   206,     0,    82,    84,   106,
       0,   107,    86,   207,   135,     0,     0,   203,   205,   137,
       0,   128,     0,   119,   120,   144,   119,    80,     0,    88,
      90,    83,    85,     0,   111,    87,     0,     0,     0,   136,
       1,   204,     0,   129,   131,     0,   138,   117,   118,     0,
      81,     0,     0,     0,   114,     0,     0,    78,   208,   142,
     151,     0,   146,   148,     0,   153,     3,     4,     5,     0,
       0,     0,     0,   139,    24,    25,    26,    27,    28,    29,
       7,    18,    30,     0,    32,    36,    39,    42,    47,    50,
      52,    54,    56,    58,    60,    77,     0,     2,     0,   126,
       0,     0,    89,    90,     0,    30,    62,   169,    91,   210,
     109,   115,     0,     0,   121,   123,     0,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     0,    78,   184,    75,
      79,     0,   188,     0,   190,   175,   176,    78,    78,   177,
     178,   179,   180,     2,     0,     0,   150,   157,   152,   158,
     141,     0,   143,     0,     0,    22,     0,    19,    20,     0,
     155,     0,     0,    12,    13,    14,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   140,   130,
     132,   127,   173,   171,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    64,     0,   124,     0,   116,     0,
     110,     0,    78,     0,     0,     0,     0,    78,     0,   200,
     201,     0,     0,   192,   186,   189,    78,   185,   191,    78,
     165,     0,     0,   161,     0,   159,     0,     0,   147,   149,
     154,     0,     6,     0,   157,   156,     0,    11,     0,    15,
      16,     0,    10,    33,    34,    35,    37,    38,    40,    41,
      45,    46,    43,    44,    48,    49,    51,    53,    55,    57,
      59,     0,   172,     0,    63,   122,   125,    78,   183,     0,
       0,     0,     0,     0,   199,   202,    76,   187,   181,   166,
     160,   162,   167,     0,   163,     0,    23,    31,     9,     0,
       8,     0,   174,   170,   182,    78,    78,    78,     0,    78,
     168,   164,    17,    61,   193,   195,   196,     0,     0,    78,
       0,    78,   194,   197,     0,    78,   198
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,  -123,  -123,  -123,     1,  -123,   -91,    26,    42,
     -89,    47,    93,   105,    92,   104,   106,  -123,   -49,   -66,
    -123,   -73,   -15,  -113,   -76,    17,  -123,   241,  -123,   197,
    -123,  -123,   235,   -60,    39,   -28,  -123,    90,  -123,   248,
     201,   198,    71,  -123,   -53,   -47,  -123,   144,  -123,   146,
     -52,  -123,  -122,  -123,  -123,   -63,  -123,   -17,  -123,   164,
    -123,  -123,  -123,  -123,  -123,   287,  -123,  -123,  -123,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   100,   101,   268,   269,   125,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   126,   149,
     225,   150,   116,   151,    25,    80,    48,    49,    27,    28,
      29,    30,    73,    74,    75,    45,   133,   134,    31,    62,
      63,    32,    33,    34,    35,   251,    82,    83,    84,   181,
     252,   169,   128,   293,   213,   154,   155,   156,   157,   158,
     159,   160,   161,   162,    36,    37,    38,    56,    72,   117
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,   152,   212,   196,   197,   127,     1,     1,     1,   115,
      81,   206,   188,   131,     1,    67,    65,    26,    68,   179,
     118,    41,    39,   118,   194,   195,    39,   167,   168,   242,
      54,    69,   227,   172,   241,    39,    39,   173,   119,    78,
      64,   211,    66,   321,    51,    52,   189,    70,   228,    55,
      76,   190,   191,    26,   263,   129,   165,    85,   127,   102,
      23,    24,    57,    44,    58,    64,    22,   198,   199,    39,
       1,   115,    23,    24,   207,    39,   131,   163,   120,   236,
      39,   245,    44,   115,   256,    44,   257,    47,   115,    40,
     175,   177,   178,    42,   153,   248,    53,    50,   273,   274,
     275,   179,   170,   179,   102,   210,    59,   280,   281,   282,
     283,   167,     1,   271,   167,   255,   115,   226,    64,   270,
      77,   102,   231,   171,   303,   262,   202,   264,   265,   242,
      22,   180,   203,   102,   291,   205,    23,    24,   102,   325,
     123,   326,   163,   242,   238,   242,   135,   208,   327,   132,
     254,   166,   242,    39,   320,    71,   242,   163,   163,   294,
     299,   300,   301,    71,    39,  -209,   102,    39,   229,   298,
     322,   204,    22,   260,   153,   317,   306,   340,    23,    24,
     115,   242,   267,   248,   200,   201,   308,   272,   192,   193,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   115,   313,
     264,   264,   255,   180,   296,   232,   338,     1,   276,   277,
     233,    43,    46,   234,   123,   235,   127,    39,   344,   237,
     102,   239,   163,   240,   324,    42,   278,   279,    59,   242,
      43,    46,   315,    43,    46,   243,   163,   284,   285,   163,
      43,    46,   249,   332,   266,   337,   292,   297,   102,   182,
     183,   184,   334,   335,   336,   302,   304,   102,   305,   309,
      43,    46,   333,    43,    46,   310,   342,   164,   311,   165,
     316,   318,   346,    23,    24,   323,   319,   328,   329,    43,
      46,   330,   331,   339,   345,   286,   288,   163,   135,     1,
      86,    87,    88,    89,   341,    90,    91,   343,   287,   289,
     122,   136,   290,   121,   185,   259,   186,   295,   187,   209,
     261,   246,   102,    61,     0,   163,   163,   163,     0,     0,
       0,     0,     0,    43,    46,     0,     0,     0,     0,   163,
       0,     0,     0,     0,     0,   163,     0,     1,    86,    87,
      88,    89,     0,    90,    91,     0,     0,     0,     0,    92,
       0,     0,    93,     0,     0,    94,    95,    96,    97,    98,
      99,    43,    46,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,   137,   138,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,     0,    92,     0,     0,
       0,     0,     0,    94,    95,    96,    97,    98,    99,     1,
      86,    87,    88,    89,     0,    90,    91,     0,     0,    77,
     148,     0,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,   137,   138,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,     0,    92,
       1,     0,     0,     0,     0,    94,    95,    96,    97,    98,
      99,     1,    86,    87,    88,    89,   224,    90,    91,     0,
       0,    77,   244,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     0,     1,    86,
      87,    88,    89,     0,    90,    91,     0,     0,   137,   138,
     139,    79,   140,   141,   142,   143,   144,   145,   146,   147,
       0,    92,     0,     0,     0,     0,     0,    94,    95,    96,
      97,    98,    99,     0,     0,     1,    86,    87,    88,    89,
       0,    90,    91,    77,   247,   137,   138,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,     0,    92,     0,
       0,     0,     0,     0,    94,    95,    96,    97,    98,    99,
       1,    86,    87,    88,    89,     0,    90,    91,     0,     0,
      77,   307,   137,   138,   139,     0,   140,   141,   142,   143,
     144,   145,   146,   147,     0,    92,     0,     0,     0,     0,
       0,    94,    95,    96,    97,    98,    99,     1,    86,    87,
      88,    89,     0,    90,    91,     0,     0,    77,     0,     0,
       0,     1,    86,    87,    88,    89,     0,    90,    91,     0,
      92,     0,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,     1,    86,    87,    88,    89,     2,    90,    91,
       0,     0,   124,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    92,     0,     0,
     253,     0,     0,    94,    95,    96,    97,    98,    99,     0,
       0,    92,     0,     0,     0,     0,     0,    94,    95,    96,
      97,    98,    99,     1,    86,    87,    88,    89,     0,    90,
      91,     0,    92,     0,     0,   314,     0,     0,    94,    95,
      96,    97,    98,    99,     1,    86,    87,    88,    89,     0,
      90,    91,     0,     0,     0,     0,     1,    86,    87,    88,
      89,     2,    90,    91,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,     0,   174,     0,     0,     0,     0,     0,    94,
      95,    96,    97,    98,    99,     0,     0,     0,     0,    60,
       0,     0,     1,     0,   176,     0,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,    92,     0,   130,     0,
       0,     0,    94,    95,    96,    97,    98,    99,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,     0,     0,     0,     0,     0,    23,    24,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,   250,
     165,     0,     0,     0,    23,    24,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     2,     0,     0,     0,
      23,    24,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     263,   250,   165,   230,     0,     0,    23,    24,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   312,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,   258,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     2,     0,     0,     0,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
       0,    77,   124,    13,    14,    71,     3,     3,     3,    58,
      57,    18,   103,    73,     3,    43,    85,     0,    46,    92,
      68,    21,    22,    68,    11,    12,    26,    80,    80,    68,
      30,    68,    68,    64,   147,    35,    36,    68,    86,    56,
      40,    86,    64,    82,    27,    28,    70,    84,    84,    32,
      85,    75,    76,    36,    63,    72,    65,    57,   124,    58,
      69,    70,    63,    24,    65,    65,    63,    77,    78,    69,
       3,   120,    69,    70,    81,    75,   136,    77,    83,   142,
      80,   157,    43,   132,    63,    46,    65,    84,   137,    85,
      89,    90,    91,    22,    77,   158,    85,    26,   189,   190,
     191,   174,    64,   176,   103,   120,    35,   196,   197,   198,
     199,   164,     3,   186,   167,   167,   165,   132,   118,   185,
      85,   120,   137,    68,   237,    64,    69,   180,   180,    68,
      63,    92,    79,   132,   207,    17,    69,    70,   137,    64,
      69,    64,   142,    68,   144,    68,    75,    66,    64,    82,
     165,    80,    68,   153,    66,    83,    68,   157,   158,   225,
     233,   234,   235,    83,   164,    85,   165,   167,    82,   232,
     292,    80,    63,   173,   157,   266,   242,    64,    69,    70,
     229,    68,   182,   246,    15,    16,   249,   187,    71,    72,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   257,   256,
     263,   264,   264,   174,   229,    82,   329,     3,   192,   193,
      63,    24,    24,    63,   153,    63,   292,   227,   341,    63,
     229,    84,   232,    84,   297,   164,   194,   195,   167,    68,
      43,    43,   257,    46,    46,    84,   246,   200,   201,   249,
      53,    53,    82,   319,    64,   328,    68,    82,   257,     8,
       9,    10,   325,   326,   327,    55,    84,   266,    84,    64,
      73,    73,   321,    76,    76,    64,   339,    63,    66,    65,
      64,    64,   345,    69,    70,    86,    68,    63,    84,    92,
      92,    64,    66,    53,    64,   202,   204,   297,   227,     3,
       4,     5,     6,     7,    84,     9,    10,    84,   203,   205,
      69,    76,   206,    65,    63,   171,    65,   227,    67,   118,
     174,   157,   321,    36,    -1,   325,   326,   327,    -1,    -1,
      -1,    -1,    -1,   136,   136,    -1,    -1,    -1,    -1,   339,
      -1,    -1,    -1,    -1,    -1,   345,    -1,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    66,    -1,    -1,    69,    70,    71,    72,    73,
      74,   174,   174,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,     3,
       4,     5,     6,     7,    -1,     9,    10,    -1,    -1,    85,
      86,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    63,
       3,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,     3,     4,     5,     6,     7,    83,     9,    10,    -1,
      -1,    85,    86,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    -1,    50,    51,
      52,    64,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    -1,    -1,     3,     4,     5,     6,     7,
      -1,     9,    10,    85,    86,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    -1,
      85,    86,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    85,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,     9,    10,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,     3,     4,     5,     6,     7,    29,     9,    10,
      -1,    -1,    85,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    63,    -1,    -1,
      66,    -1,    -1,    69,    70,    71,    72,    73,    74,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    63,    -1,    -1,    66,    -1,    -1,    69,    70,
      71,    72,    73,    74,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    29,     9,    10,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,     0,
      -1,    -1,     3,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    63,    -1,    86,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    -1,    -1,    -1,    69,    70,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    29,    -1,    -1,    -1,
      69,    70,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    86,    -1,    -1,    69,    70,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    29,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    63,    69,    70,   111,   112,   115,   116,   117,
     118,   125,   128,   129,   130,   131,   151,   152,   153,   156,
      85,   156,   129,   116,   121,   122,   128,    84,   113,   114,
     129,   112,   112,    85,   156,   112,   154,    63,    65,   129,
       0,   152,   126,   127,   156,    85,    64,   122,   122,    68,
      84,    83,   155,   119,   120,   121,    85,    85,   144,    64,
     112,   132,   133,   134,   135,   156,     4,     5,     6,     7,
       9,    10,    63,    66,    69,    70,    71,    72,    73,    74,
      88,    89,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   109,   156,    68,    86,
      83,   126,   114,   129,    85,    92,   105,   106,   139,   144,
      86,   120,    82,   123,   124,   129,   119,    50,    51,    52,
      54,    55,    56,    57,    58,    59,    60,    61,    86,   106,
     108,   110,   111,   112,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   156,    63,    65,   129,   131,   137,   138,
      64,    68,    64,    68,    63,    92,    63,    92,    92,   108,
     121,   136,     8,     9,    10,    63,    65,    67,    94,    70,
      75,    76,    71,    72,    11,    12,    13,    14,    77,    78,
      15,    16,    69,    79,    80,    17,    18,    81,    66,   127,
     109,    86,   139,   141,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    83,   107,   109,    68,    84,    82,
      86,   109,    82,    63,    63,    63,   142,    63,   156,    84,
      84,   110,    68,    84,    86,   111,   146,    86,   142,    82,
      64,   132,   137,    66,   109,   137,    63,    65,    49,   134,
     156,   136,    64,    63,   131,   137,    64,   156,    90,    91,
     106,   108,   156,    94,    94,    94,    95,    95,    96,    96,
      97,    97,    97,    97,    98,    98,    99,   100,   101,   102,
     103,   108,    68,   140,   106,   124,   109,    82,   142,   108,
     108,   108,    55,   110,    84,    84,   106,    86,   142,    64,
      64,    66,    64,   132,    66,   109,    64,    94,    64,    68,
      66,    82,   139,    86,   142,    64,    64,    64,    63,    84,
      64,    66,   106,   105,   142,   142,   142,   108,   110,    53,
      64,    84,   142,    84,   110,    64,   142
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    88,    88,    88,    89,    89,    89,
      89,    89,    89,    89,    90,    90,    91,    91,    92,    92,
      92,    92,    92,    92,    93,    93,    93,    93,    93,    93,
      94,    94,    95,    95,    95,    95,    96,    96,    96,    97,
      97,    97,    98,    98,    98,    98,    98,    99,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   108,   108,   109,   110,   110,
     111,   111,   112,   112,   112,   112,   112,   112,   113,   113,
     114,   114,   115,   115,   115,   115,   115,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   117,
     117,   117,   118,   118,   119,   119,   120,   121,   121,   122,
     122,   123,   123,   124,   124,   124,   125,   125,   125,   126,
     126,   127,   127,   128,   128,   129,   129,   130,   130,   130,
     130,   130,   130,   130,   131,   131,   132,   132,   133,   133,
     134,   134,   134,   135,   135,   136,   136,   137,   137,   137,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   139,
     139,   140,   140,   141,   141,   142,   142,   142,   142,   142,
     142,   143,   143,   143,   144,   144,   144,   144,   145,   145,
     146,   146,   147,   148,   148,   148,   149,   149,   149,   150,
     150,   150,   150,   151,   151,   152,   152,   154,   153,   155,
     153,   156
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     4,     4,
       3,     3,     2,     2,     0,     1,     1,     3,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     0,     1,
       2,     3,     1,     2,     1,     2,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       5,     2,     1,     1,     1,     2,     3,     2,     2,     0,
       1,     1,     3,     1,     2,     3,     4,     5,     2,     1,
       3,     1,     3,     1,     1,     1,     2,     1,     3,     3,
       4,     4,     3,     4,     2,     1,     1,     3,     1,     3,
       2,     1,     2,     1,     3,     1,     2,     1,     1,     2,
       3,     2,     3,     3,     4,     2,     3,     3,     4,     1,
       4,     0,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     3,     3,     4,     1,     2,
       1,     2,     2,     5,     7,     5,     5,     7,     9,     3,
       2,     2,     3,     1,     2,     1,     1,     0,     3,     0,
       4,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 75 "gram.y" /* yacc.c:1646  */
    { int b; 
			//if(!st_lookup(getSTID($<y_DN>1), &b))
			//{error("undefined"); $<y_EN>$ = NULL;}
			//else
			(yyval.y_EN) = createVariableExpression(getSTID((yyvsp[0].y_DN))); }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 80 "gram.y" /* yacc.c:1646  */
    { 
		EN node = createConstantIntExpression((yyvsp[0].y_int));
		(yyval.y_EN) = node;

		// printExpression(node);

		// $<y_int>$ = $<y_int>1;
	}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 88 "gram.y" /* yacc.c:1646  */
    {
		// msg("DOUBLE CONSTANT is %f", $<y_double>$1);
		
		EN node = createConstantDoubleExpression((yyvsp[0].y_double));
		(yyval.y_EN) = node;

		// printExpression(node);

		// $<y_double>$ = $<y_double>1;
	}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 98 "gram.y" /* yacc.c:1646  */
    {
		// msg("STRING LITERAL is %s", $<y_string>$1);

		(yyval.y_string) = (yyvsp[0].y_string);
	}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 103 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = (yyvsp[-1].y_EN);
	}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 111 "gram.y" /* yacc.c:1646  */
    { (yyval.y_EN) = createFunctionExpression((yyvsp[-3].y_EN), (yyvsp[-1].y_arg_list));}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 119 "gram.y" /* yacc.c:1646  */
    { (yyval.y_arg_list) = NULL; }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 124 "gram.y" /* yacc.c:1646  */
    { (yyval.y_arg_list) = buildArg( (yyvsp[0].y_EN) );	}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 125 "gram.y" /* yacc.c:1646  */
    { 
			(yyval.y_arg_list) = linkArgList((yyvsp[-2].y_arg_list), buildArg( (yyvsp[0].y_EN) ));
	}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 134 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createUnaryExpression((yyvsp[-1].y_unop), (yyvsp[0].y_EN), TRUE);
	}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 142 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = UNARY_REF; 
	}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 144 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = UNARY_DEREF; 
	}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 146 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = UNARY_PLUS; 
	}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 148 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = UNARY_MINUS; 
	}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 150 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = UNARY_TILDE; 
	}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 152 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = UNARY_NOT; 
	}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 164 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_MULT, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 168 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_DIV, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 172 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_MOD, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 180 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_ADD, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 184 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_SUB, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 192 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_SHIFTL, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 196 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_SHIFTR, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 204 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_LT, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 208 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_GRT, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 212 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_LTE, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 216 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_GRTE, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 224 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_EQUALS, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 228 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_NE, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 236 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_XAND, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 244 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_XNOT, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 252 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_XOR, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 260 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_AND, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 268 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_OR, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 280 "gram.y" /* yacc.c:1646  */
    { 	
		
		(yyval.y_EN) = createBinaryExpression((yyvsp[-1].y_binop), (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
		
	}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 288 "gram.y" /* yacc.c:1646  */
    { (yyval.y_binop) = BINARY_ASSIGNMENT; }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 312 "gram.y" /* yacc.c:1646  */
    { error("no declarator in declaration");}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 313 "gram.y" /* yacc.c:1646  */
    {
		// Combine the type of declaration_specifiers (held in a bucket)
		// with the type of init_declarator_list HERE!!!!!
	}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 322 "gram.y" /* yacc.c:1646  */
    { 
		(yyval.y_bucketPtr) = buildBucket(NULL, (yyvsp[0].y_typeSpec));
	}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 325 "gram.y" /* yacc.c:1646  */
    { 
		(yyval.y_bucketPtr) = buildBucket((yyvsp[0].y_bucketPtr), (yyvsp[-1].y_typeSpec));
	}
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 328 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_bucketPtr) = buildBucket(NULL, (yyvsp[0].y_typeSpec));
	}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 331 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_bucketPtr) = buildBucket((yyvsp[0].y_bucketPtr), (yyvsp[-1].y_typeSpec));
	}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 337 "gram.y" /* yacc.c:1646  */
    { 
		//msg("In init_declarator");
		// print_tree($<y_DN>1);

		TYPE baseType = build_base((yyvsp[-1].y_bucketPtr));
		TYPE derivedType = building_derived_type_and_install_st((yyvsp[0].y_DN), baseType);
		GLD((yyvsp[0].y_DN), baseType, derivedType, installSuccessful);
	}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 345 "gram.y" /* yacc.c:1646  */
    {
		//msg("In init_declarator");
		// building_derived_type_and_install_st($<y_DN>3, build_base($<y_bucketPtr>0));
		TYPE baseType = build_base((yyvsp[-3].y_bucketPtr));
		TYPE derivedType = building_derived_type_and_install_st((yyvsp[0].y_DN), baseType);
		GLD((yyvsp[0].y_DN), baseType, derivedType, installSuccessful);
	}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 364 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = VOID_SPEC;}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 365 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = CHAR_SPEC;}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 366 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = SHORT_SPEC;}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 367 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = INT_SPEC;}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 368 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = LONG_SPEC;}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 369 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = FLOAT_SPEC;}
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 370 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = DOUBLE_SPEC;}
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 371 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = SIGNED_SPEC;}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 372 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = UNSIGNED_SPEC;}
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 373 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = STRUCT_SPEC;}
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 374 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = ENUM_SPEC;}
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 375 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = TYPENAME_SPEC;}
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 404 "gram.y" /* yacc.c:1646  */
    {
		//msg("Found *");
	}
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 438 "gram.y" /* yacc.c:1646  */
    { 
		(yyval.y_typeSpec) = CONST_SPEC;
	}
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 441 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_typeSpec) = VOLATILE_SPEC;
	}
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 448 "gram.y" /* yacc.c:1646  */
    {
		//if($<y_ref>1 == TRUE)
			//msg("Reference passed");
		//else;
			//msg("Found 'pointer declarator'");
		(yyval.y_DN) = makePtrNode((yyvsp[0].y_DN), (yyvsp[-1].y_ref));
		//}
	}
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 460 "gram.y" /* yacc.c:1646  */
    { 
		//msg("Found ( declarator )");
		(yyval.y_DN) = (yyvsp[-1].y_DN);
	}
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 465 "gram.y" /* yacc.c:1646  */
    { 
			(yyval.y_DN) = makeArrayNode((yyvsp[-3].y_DN), getIntFromExpression(evaluateExpression((yyvsp[-1].y_EN))));
	}
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 468 "gram.y" /* yacc.c:1646  */
    {
			if(checkParam((yyvsp[-1].y_PL)))
				(yyval.y_DN) = makeFnNode((yyvsp[-3].y_DN), (yyvsp[-1].y_PL));
			else
				(yyval.y_DN) = NULL;
	}
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 474 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_DN) = makeFnNode((yyvsp[-2].y_DN), NULL);
	}
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 482 "gram.y" /* yacc.c:1646  */
    { (yyval.y_ref) = FALSE; }
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 483 "gram.y" /* yacc.c:1646  */
    { (yyval.y_ref) = TRUE;}
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 487 "gram.y" /* yacc.c:1646  */
    { (yyval.y_PL) = (yyvsp[0].y_PL);}
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 488 "gram.y" /* yacc.c:1646  */
    { error("Elipsis not allowed"); }
#line 2328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 492 "gram.y" /* yacc.c:1646  */
    {
			(yyval.y_PL) = (yyvsp[0].y_PL);
			(yyval.y_PL)->prev = (yyvsp[0].y_PL);
	}
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 496 "gram.y" /* yacc.c:1646  */
    {
		if(((yyvsp[0].y_PL) == NULL) || (yyvsp[-2].y_PL) == NULL)
			(yyval.y_PL) = NULL;
		else {
			(yyval.y_PL) = linkParams((yyvsp[-2].y_PL), (yyvsp[0].y_PL));
		}
	}
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 506 "gram.y" /* yacc.c:1646  */
    {
		TYPE baseType = build_base((yyvsp[-1].y_bucketPtr));
		(yyval.y_PL) = build_Param((yyvsp[0].y_DN), baseType, NULL);
	}
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 510 "gram.y" /* yacc.c:1646  */
    { error("no id in parameter list"); (yyval.y_PL) = NULL; }
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 595 "gram.y" /* yacc.c:1646  */
    { 
		(yyval.y_EN) = evaluateExpression((yyvsp[-1].y_EN)); 
		//msg("Done evaluating Expression");
		if((yyvsp[-1].y_EN)->tag != TAG_FUNCTION)
			b_pop();
	}
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 638 "gram.y" /* yacc.c:1646  */
    { 
			// Get the name of the function, declarator is a Declarator Node $<y_DN>1
		char *f = st_get_id_str(getSTID((yyvsp[0].y_DN)));
			// send in node to check stuff
		BOOLEAN result = funcDeclCheck((yyvsp[0].y_DN));
			// Prologue into function and enter block (Back_end and Symbol Table stuff)
		if(result)
			{
				b_func_prologue (f); 
				st_enter_block();
			}
		(yyval.y_ref) = result;
		}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 652 "gram.y" /* yacc.c:1646  */
    { 
			char *f = st_get_id_str(getSTID((yyvsp[-2].y_DN)));
// Actions for Compound_statement here! then exit block and epilogue function
			if((yyvsp[-1].y_ref))
			{
				st_exit_block();
				b_func_epilogue (f);

				funcDefBuildParams((yyvsp[-2].y_DN));
			}
//			printf("'$2 is %s'\n", $<y_string>2);
		}
#line 2410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 665 "gram.y" /* yacc.c:1646  */
    { 
// In case of intitial function declaration and definition this production is called
		int b;
		ST_ID stid = getSTID((yyvsp[0].y_DN));
		char *f = st_get_id_str(stid);
		ST_DR stdr;
		PARAMSTYLE ps;
		PARAM_LIST pl;
		BOOLEAN result = FALSE;
		TYPE baseType = build_base((yyvsp[-1].y_bucketPtr));
		stdr = st_lookup(stid, &b);
		if(!stdr)
		{
			//error("in check if stdr");
			TYPE derivedType = building_derived_type_and_install_st((yyvsp[0].y_DN), baseType);
			GLD((yyvsp[0].y_DN), baseType, derivedType, installSuccessful);
			result = funcDeclCheck((yyvsp[0].y_DN));
		}
		else if (ty_query(stdr->u.decl.type) != TYFUNC)
			error("duplicate or incompatible function declaration '%s'", f);
		else if (ty_query(ty_query_func(stdr->u.decl.type, &ps, &pl)) == ty_query(baseType))
		{
			result = funcDeclCheck((yyvsp[0].y_DN));
		}
		else
			error("duplicate or incompatible function declaration '%s'", f);
		if(result)
			{
				b_func_prologue (f); 
				st_enter_block();

				funcDefBuildParams((yyvsp[0].y_DN));
			}
		(yyval.y_ref) = result;
	}
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 700 "gram.y" /* yacc.c:1646  */
    {
// Actions for Compound_statement here! then exit block and epilogue function
		char *f = st_get_id_str(getSTID((yyvsp[-2].y_DN)));
			if((yyvsp[-1].y_ref))
			{
				st_exit_block();
				b_func_epilogue (f);
			}
	}
#line 2464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 716 "gram.y" /* yacc.c:1646  */
    { 
		//msg("Found ID; Enrolling %s",$<y_string>1); 
		
		ST_ID varName = st_enter_id((yyvsp[0].y_string));
		(yyval.y_DN) = makeIdNode(varName);
	}
#line 2475 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2479 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 723 "gram.y" /* yacc.c:1906  */


extern int column;
// PROJ 2
// Used as intermediate action in function_definition production
BOOLEAN funcDeclCheck(DN dn)
{
	int b;
	ST_ID stid = getSTID(dn);
	char * id = st_get_id_str(stid);
	//error("Function %s\n", id);
	BOOLEAN result = FALSE;
	
	ST_DR stdr;
	stdr = st_lookup(stid, &b);
	// if STDR is NULL then we build it
	if(stdr == NULL)			
	{
		stdr = stdr_alloc(); // Allocate space for the symtab data record
		stdr->tag = FDECL;
				//stdr->u.decl.type = ty_build_basic(TYSIGNEDINT);
		stdr->u.decl.type = ty_build_func(ty_build_basic(TYSIGNEDINT), PROTOTYPE, NULL);
		stdr->u.decl.sc = NO_SC;
		stdr->u.decl.err = FALSE;
				
		result = st_install(stid,stdr);
		if (!result) 
		{
			error("duplicate declaration for %s in Function Decl Check", st_get_id_str(dn->u.st_id.i));
			error("duplicate definition of '%s' Function Decl Check", st_get_id_str(dn->u.st_id.i));
			return FALSE;
		}
		return TRUE;
	}
// ELSE it is in the Symbol Table, check to make sure it is a Function first, if so check tags.
	else
	{
	//ty_print_typetag(ty_query(stdr->u.decl.type));

		if(ty_query(stdr->u.decl.type) != TYFUNC)
		{ error("duplicate or incompatible function declaration '%s' FuncDeclCheck not TYFUNC", id);  
			return FALSE;		//bug("error not a function"); 
		}
		else
		{
			if(stdr->tag == GDECL)
			{
				//error("Is GDECL switch to FDECL");
				stdr->tag = FDECL;
				return TRUE;
			}
			else if(stdr->tag == FDECL && !result)
			{
				error("duplicate or incompatible function declaration '%s'", id);
				return FALSE;
			}
			else
			{	error("Wrong type(not a function ID)"); return FALSE; }
			//stdr->u.decl.type = type;
		}
	}
	//else
		error("How did we get here in FuncDeclCheck not built, need to build?");
}

void funcDefBuildParams(DN node)
{
	int offset;
	ST_DR dr;
	BOOLEAN result;
	//error("Building parameters");
	if(node->tag != FUNC) 
		error("Not a Function\n");
	else
	{
		PARAM_LIST pl = node->u.param_list.pl;
		while(pl != NULL)
		{
			dr = stdr_alloc(); // Allocate space for the symtab data record
			dr->tag = PDECL;
			dr->u.decl.type = pl->type;
			dr->u.decl.sc = NO_SC;
			dr->u.decl.err = FALSE;
			result = st_install(pl->id, dr);
			if (!result)
			{
			error("param install, duplicate declaration for %s", st_get_id_str(pl->id));
			error("param, install duplicate definition of '%s'", st_get_id_str(pl->id));
			}
			offset = b_store_formal_param(ty_query(pl->type));
			pl = pl->next;
		}
	}
		

}
// stID check, TRUE if it does exist in current block or global, or FALSE it does not exist
BOOLEAN st_IDCheck(ST_ID stid)
{
	int b;
	int cur_b = st_get_cur_block();
	ST_DR stdr;
	stdr = st_lookup(stid, &b);
	if(stdr)
		if( b == cur_b || b == 0)
			return TRUE;
	else
		return FALSE;
}

TYPETAG getTypeTag_STID(ST_ID stid)
{
	int b;
	ST_DR stdr = st_lookup(stid, &b);
	return ty_query(stdr->u.decl.type);
}

// PROJ2 End

int sizeOfType(TYPETAG type)
{
	int returnedSizeOf = -1;

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
		BOOLEAN funcFlag = FALSE;
		int align = sizeOfType(ty_query(baseType));
		int size = 0;
		int array_total = 1;
		char* id; 
		while(dn != NULL)
		{
			switch(dn->tag) {
			case ARRAY:
				if(dn->u.array_dim.dim <= 0)
				{
					return;
				}
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
