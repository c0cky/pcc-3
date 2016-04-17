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

#line 86 "y.tab.c" /* yacc.c:339  */

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
#line 27 "gram.y" /* yacc.c:355  */

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
	EN y_EN;


#line 267 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 282 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1178

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  210
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  346

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
       0,    66,    66,    67,    78,    89,    93,   100,   101,   102,
     103,   104,   105,   106,   109,   111,   115,   116,   120,   121,
     122,   123,   127,   128,   132,   134,   136,   138,   140,   142,
     147,   148,   152,   153,   157,   161,   168,   169,   173,   180,
     181,   185,   192,   193,   197,   201,   205,   212,   213,   217,
     224,   225,   232,   233,   240,   241,   248,   249,   256,   257,
     264,   265,   269,   274,   288,   288,   288,   288,   288,   288,
     289,   289,   289,   289,   289,   293,   294,   298,   301,   303,
     311,   312,   319,   320,   321,   325,   329,   333,   340,   349,
     360,   361,   367,   367,   367,   367,   367,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   386,
     387,   388,   392,   393,   397,   398,   402,   406,   407,   411,
     414,   418,   419,   423,   424,   425,   429,   430,   431,   435,
     436,   440,   441,   447,   450,   456,   457,   469,   470,   474,
     475,   478,   484,   487,   491,   493,   497,   498,   502,   506,
     516,   520,   521,   525,   526,   530,   531,   535,   536,   537,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   553,
     554,   557,   559,   563,   564,   572,   573,   573,   574,   575,
     576,   577,   581,   582,   583,   587,   588,   589,   590,   594,
     595,   599,   600,   604,   610,   611,   612,   616,   617,   618,
     622,   623,   624,   625,   633,   634,   638,   639,   643,   646,
     656
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
  "comma_opt", "initializer_list", "statement", "$@1", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "identifier", YY_NULLPTR
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

#define YYPACT_NINF -147

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-147)))

#define YYTABLE_NINF -177

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     917,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,     5,   114,  -147,  1005,  -147,    30,  1130,  1130,  -147,
      10,  -147,  1130,   -33,   -12,   114,   825,  -147,  -147,  -147,
      61,     1,    45,  1005,  -147,  -147,  1005,  -147,   -43,  -147,
     -69,  -147,  -147,  1005,    44,  -147,   352,  -147,   485,   642,
    -147,  -147,  -147,   -59,  -147,    32,    61,  -147,  -147,  -147,
     114,  -147,   605,  -147,   953,  -147,   220,  1005,  -147,  -147,
    -147,   749,   761,   761,   773,    67,    84,    96,    99,   570,
     113,    61,    98,   101,   773,   656,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,   260,   421,   773,  -147,    -8,    49,
     154,   112,   156,   111,   115,   135,   175,    16,  -147,  -147,
     127,   132,  -147,    30,  -147,   -33,  -147,   424,   496,  -147,
    -147,  -147,  -147,   136,  -147,    85,   155,   153,  -147,    19,
    -147,  -147,  -147,  -147,   160,  -147,    61,  -147,   773,   -49,
    -147,   146,   605,  -147,  -147,  -147,  -147,   773,   -37,  -147,
     148,   973,   656,  -147,   773,  -147,  -147,   151,   570,   773,
     773,   773,   180,   773,   157,  -147,  -147,   167,    54,   -21,
     176,    61,  -147,  -147,   773,   773,    61,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,   773,  -147,
     773,   773,   773,   773,   773,   773,   773,   773,   773,   773,
     773,   773,   773,   773,   773,   773,   773,   773,   773,   773,
    -147,  -147,  -147,  -147,   533,  -147,  -147,   570,   871,   677,
    -147,    85,  -147,    75,  -147,  1109,  -147,    61,  -147,  -147,
    -147,  -147,  -147,   171,  -147,   220,  -147,   773,  -147,   188,
     570,  -147,    68,    73,    92,   193,   174,  -147,  -147,  -147,
    1031,   -21,  -147,   773,  -147,   198,   197,  -147,     7,  -147,
    -147,  -147,  -147,  -147,    -8,    -8,    49,    49,   154,   154,
     154,   154,   112,   112,   156,   111,   115,   135,   175,   -25,
    -147,  -147,  -147,  -147,   202,   212,  -147,   211,  -147,  1073,
     728,  -147,  -147,  -147,   605,   192,  -147,  -147,  -147,  -147,
     570,   570,   570,   773,   773,  -147,  -147,   773,  -147,   773,
    -147,  -147,  -147,  -147,   215,  -147,   216,  -147,  -147,   227,
    -147,  -147,    93,   200,  -147,  -147,  -147,  -147,   570,   209,
     773,  -147,  -147,   222,   570,  -147
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   210,   108,    92,    93,    94,    95,    96,    98,    99,
     100,   101,   104,   105,   102,   103,   133,   134,    97,   112,
     113,     0,     0,   145,   119,   207,     0,    82,    84,   106,
       0,   107,    86,     0,   135,     0,     0,   204,   206,   137,
       0,   128,     0,   119,   120,   144,   119,    80,     0,    88,
      90,    83,    85,     0,   111,    87,    78,   208,     0,     0,
     136,     1,   205,     0,   129,   131,     0,   138,   117,   118,
       0,    81,     0,   209,     0,   114,     0,     0,     3,     4,
       5,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,    78,     0,    24,    25,    26,    27,
      28,    29,   185,     7,    18,    30,     0,    32,    36,    39,
      42,    47,    50,    52,    54,    56,    58,    60,    62,    75,
      79,     0,   189,     0,   191,     0,   175,    78,    78,   178,
     179,   180,   181,     2,   142,   151,     0,   146,   148,     0,
     153,   139,    30,    77,     0,     2,     0,   126,     0,     0,
      89,    90,     0,   169,    91,   109,   115,     0,     0,   121,
     123,     0,     0,    22,     0,    19,    20,     0,    78,     0,
       0,     0,     0,    78,     0,   201,   202,     0,     0,   155,
       0,     0,    12,    13,    14,     0,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    64,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     193,   177,   187,   190,    78,   186,   192,    78,     0,     0,
     150,   157,   152,   158,   141,     0,   143,     0,   140,   130,
     132,   127,   173,   171,   124,     0,   116,     0,   110,     0,
      78,   184,     0,     0,     0,     0,     0,   200,   203,     6,
       0,   157,   156,     0,    11,     0,    15,    16,     0,    10,
      63,    33,    34,    35,    37,    38,    40,    41,    45,    46,
      43,    44,    48,    49,    51,    53,    55,    57,    59,     0,
      76,   188,   182,   165,     0,     0,   161,     0,   159,     0,
       0,   147,   149,   154,   172,     0,   122,   125,    23,   183,
      78,    78,    78,     0,    78,    31,     9,     0,     8,     0,
     166,   160,   162,   167,     0,   163,     0,   174,   170,   194,
     196,   197,     0,     0,    17,    61,   168,   164,    78,     0,
      78,   195,   198,     0,    78,   199
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,  -147,  -147,  -147,    -4,  -147,   -94,   -29,   -27,
      65,   -24,    81,    83,    86,    82,    87,  -147,   -56,   -68,
    -147,   -66,   -15,   -92,   -17,    18,  -147,   229,  -147,   214,
    -147,  -147,   223,   -67,   -23,    17,  -147,    58,  -147,   239,
     161,   218,   -11,  -147,   -97,   -53,  -147,    71,  -147,   152,
    -118,  -147,  -146,  -147,  -147,   -57,  -147,  -147,   -40,  -147,
     181,  -147,  -147,  -147,  -147,  -147,   280,  -147,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   103,   104,   265,   266,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     198,   120,   144,   121,    25,   135,    48,    49,    27,    28,
      29,    30,    74,    75,    76,    45,   158,   159,    31,    63,
      64,    32,    33,    34,    35,   294,   137,   138,   139,   180,
     295,   233,   154,   305,   243,   124,   125,   126,    57,   127,
     128,   129,   130,   131,   132,    36,    37,    38,   145
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    44,   177,   143,   153,   136,   242,   156,     1,   146,
      73,    42,   199,     1,    72,    50,    56,   232,    26,   146,
      44,    41,    39,    44,    60,    70,    39,   147,   143,   178,
      54,   245,   172,     1,   217,    39,    39,   241,   231,   122,
      65,    71,   260,   219,   229,    51,    52,   246,    23,    24,
      55,    58,    56,    59,    26,   142,   133,   319,   140,   151,
      68,   262,   200,    69,     1,   160,    65,   201,   202,   167,
      39,   226,   179,   318,   123,   219,    39,   163,   165,   166,
     142,   256,   261,   236,   153,   221,    66,   237,     1,   133,
      40,   174,   143,    22,   156,    53,   178,   218,   178,    23,
      24,   143,   142,   252,   253,   254,   271,   272,   273,    67,
     223,   251,   151,   298,    47,   148,   267,     1,   259,   268,
     203,   204,   219,    39,   230,   207,   208,   133,   133,    77,
     270,   231,   310,   240,   231,    39,   219,   311,   299,   179,
     300,   219,   244,   298,   142,   123,    65,   169,   228,   168,
     229,   290,   289,   142,    23,    24,   312,   339,   327,   170,
     219,   219,   171,   261,   261,   205,   206,   226,   133,   315,
     292,   211,   212,   143,   274,   275,   173,    22,   276,   277,
     213,   264,   175,    23,    24,   176,   269,   282,   283,   209,
     210,   143,   216,   309,   214,   219,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   297,   215,   220,    42,   227,   234,
      60,   235,   333,     1,   133,   142,   238,   133,    39,    72,
     247,    39,   307,   250,   160,   255,   153,   303,    43,   304,
     263,   257,    46,   142,   143,    39,   324,   332,   343,   334,
     133,   258,   308,   329,   330,   331,   313,    43,   314,   142,
      43,    46,   316,   335,    46,   317,   320,    43,   181,   182,
     183,    46,   278,   279,   280,   281,   321,   322,   328,   336,
     338,   341,   337,    22,   340,   326,   344,   345,    43,    23,
      24,    43,    46,   342,   284,    46,   142,   285,   287,   150,
     161,   286,   157,   306,   288,   149,   302,   239,   224,    43,
     133,   133,   133,    46,   249,   142,    62,     0,     0,     0,
       0,     0,     0,   184,     0,   185,     0,   186,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,     0,
       0,     0,     0,     0,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,    78,    79,    80,    81,
       0,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    43,    43,     0,     0,    46,
      46,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,    84,    85,    86,     0,    87,    88,    89,    90,
      91,    92,    93,    94,     0,    95,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,     1,    78,    79,
      80,    81,     0,    82,    83,     0,     0,  -176,   102,     0,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,    84,    85,    86,     0,    87,    88,
      89,    90,    91,    92,    93,    94,     0,    95,     1,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,     1,
      78,    79,    80,    81,   197,    82,    83,     0,     0,  -176,
     222,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,     1,    78,    79,    80,
      81,     0,    82,    83,     0,     0,    84,    85,    86,   134,
      87,    88,    89,    90,    91,    92,    93,    94,     0,    95,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,     0,     0,     1,    78,    79,    80,    81,     0,    82,
      83,  -176,   225,    84,    85,    86,     0,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    95,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,     1,    78,
      79,    80,    81,     0,    82,    83,     0,     0,  -176,   291,
      84,    85,    86,     0,    87,    88,    89,    90,    91,    92,
      93,    94,     0,    95,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,     1,    78,    79,    80,    81,
       0,    82,    83,     0,     0,  -176,     0,     0,     0,     1,
      78,    79,    80,    81,     0,    82,    83,     0,    95,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
       1,    78,    79,    80,    81,     2,    82,    83,     0,     0,
     152,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    95,     0,     0,   141,     0,
       0,    96,    97,    98,    99,   100,   101,     0,     0,    95,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,     1,    78,    79,    80,    81,     0,    82,    83,     0,
      95,     0,     0,   296,     0,     0,    96,    97,    98,    99,
     100,   101,     1,    78,    79,    80,    81,     0,    82,    83,
       0,     0,     0,     0,     1,    78,    79,    80,    81,     0,
      82,    83,     0,     0,     0,     0,     1,    78,    79,    80,
      81,     0,    82,    83,     0,     0,     0,     0,     0,     0,
       0,    95,     0,     0,   325,     0,     0,    96,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   164,    61,     0,     0,     1,     0,
      96,    97,    98,    99,   100,   101,    95,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,     0,
       0,     0,     0,     0,    23,    24,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   228,   293,   229,     0,     0,     0,
      23,    24,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     2,     0,     0,     0,    23,    24,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     2,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,   155,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,   248,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   260,   293,   229,     0,     0,     0,
      23,    24,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   323,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   301,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
       0,    24,    94,    59,    72,    58,   152,    74,     3,    68,
      50,    22,   106,     3,    83,    26,    85,   135,     0,    68,
      43,    21,    22,    46,    35,    68,    26,    86,    84,    95,
      30,    68,    89,     3,    18,    35,    36,    86,   135,    56,
      40,    84,    63,    68,    65,    27,    28,    84,    69,    70,
      32,    63,    85,    65,    36,    59,    56,    82,    58,    70,
      43,   179,    70,    46,     3,    76,    66,    75,    76,    84,
      70,   128,    95,    66,    56,    68,    76,    81,    82,    83,
      84,   173,   179,    64,   152,   125,    85,    68,     3,    89,
      85,    91,   148,    63,   161,    85,   162,    81,   164,    69,
      70,   157,   106,   169,   170,   171,   200,   201,   202,    64,
     127,   168,   123,   231,    84,    83,   184,     3,    64,   185,
      71,    72,    68,   123,   135,    13,    14,   127,   128,    85,
     198,   228,    64,   148,   231,   135,    68,    64,    63,   162,
      65,    68,   157,   261,   148,   127,   146,    63,    63,    82,
      65,   219,   218,   157,    69,    70,    64,    64,   304,    63,
      68,    68,    63,   260,   261,    11,    12,   224,   168,   263,
     227,    15,    16,   229,   203,   204,    63,    63,   205,   206,
      69,   181,    84,    69,    70,    84,   186,   211,   212,    77,
      78,   247,    17,   250,    79,    68,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   229,    80,    84,   228,    82,    64,
     231,    68,   314,     3,   224,   229,    66,   227,   228,    83,
      82,   231,   247,    82,   245,    55,   304,   237,    24,    68,
      64,    84,    24,   247,   300,   245,   299,   313,   340,   317,
     250,    84,    64,   310,   311,   312,    63,    43,    84,   263,
      46,    43,    64,   319,    46,    68,    64,    53,     8,     9,
      10,    53,   207,   208,   209,   210,    64,    66,    86,    64,
      53,   338,    66,    63,    84,   300,    64,   344,    74,    69,
      70,    77,    74,    84,   213,    77,   300,   214,   216,    70,
      77,   215,    82,   245,   217,    66,   235,   146,   127,    95,
     310,   311,   312,    95,   162,   319,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    65,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   338,    -1,
      -1,    -1,    -1,    -1,   344,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,   161,
     162,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    85,    86,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    63,     3,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,     3,
       4,     5,     6,     7,    83,     9,    10,    -1,    -1,    85,
      86,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    -1,    50,    51,    52,    64,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    -1,    -1,     3,     4,     5,     6,     7,    -1,     9,
      10,    85,    86,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    -1,    85,    86,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    -1,    85,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,     9,    10,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
       3,     4,     5,     6,     7,    29,     9,    10,    -1,    -1,
      85,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    63,    -1,    -1,    66,    -1,
      -1,    69,    70,    71,    72,    73,    74,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,     3,     4,     5,     6,     7,    -1,     9,    10,    -1,
      63,    -1,    -1,    66,    -1,    -1,    69,    70,    71,    72,
      73,    74,     3,     4,     5,     6,     7,    -1,     9,    10,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    66,    -1,    -1,    69,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    63,     0,    -1,    -1,     3,    -1,
      69,    70,    71,    72,    73,    74,    63,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,    -1,
      69,    70,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    29,    -1,    -1,    -1,    69,    70,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    29,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    86,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    86,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,    -1,
      69,    70,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    63,    69,    70,   111,   112,   115,   116,   117,
     118,   125,   128,   129,   130,   131,   152,   153,   154,   155,
      85,   155,   129,   116,   121,   122,   128,    84,   113,   114,
     129,   112,   112,    85,   155,   112,    85,   145,    63,    65,
     129,     0,   153,   126,   127,   155,    85,    64,   122,   122,
      68,    84,    83,   145,   119,   120,   121,    85,     4,     5,
       6,     7,     9,    10,    50,    51,    52,    54,    55,    56,
      57,    58,    59,    60,    61,    63,    69,    70,    71,    72,
      73,    74,    86,    88,    89,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     108,   110,   111,   112,   142,   143,   144,   146,   147,   148,
     149,   150,   151,   155,    64,   112,   132,   133,   134,   135,
     155,    66,    92,   105,   109,   155,    68,    86,    83,   126,
     114,   129,    85,   106,   139,    86,   120,    82,   123,   124,
     129,   119,    63,    92,    63,    92,    92,   109,    82,    63,
      63,    63,   142,    63,   155,    84,    84,   110,   108,   121,
     136,     8,     9,    10,    63,    65,    67,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    83,   107,    94,
      70,    75,    76,    71,    72,    11,    12,    13,    14,    77,
      78,    15,    16,    69,    79,    80,    17,    18,    81,    68,
      84,   145,    86,   111,   147,    86,   142,    82,    63,    65,
     129,   131,   137,   138,    64,    68,    64,    68,    66,   127,
     109,    86,   139,   141,   109,    68,    84,    82,    86,   136,
      82,   142,   108,   108,   108,    55,   110,    84,    84,    64,
      63,   131,   137,    64,   155,    90,    91,   106,   108,   155,
     106,    94,    94,    94,    95,    95,    96,    96,    97,    97,
      97,    97,    98,    98,    99,   100,   101,   102,   103,   108,
     106,    86,   142,    64,   132,   137,    66,   109,   137,    63,
      65,    49,   134,   155,    68,   140,   124,   109,    64,   142,
      64,    64,    64,    63,    84,    94,    64,    68,    66,    82,
      64,    64,    66,    64,   132,    66,   109,   139,    86,   142,
     142,   142,   108,   110,   106,   105,    64,    66,    53,    64,
      84,   142,    84,   110,    64,   142
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
     139,   140,   140,   141,   141,   142,   143,   142,   142,   142,
     142,   142,   144,   144,   144,   145,   145,   145,   145,   146,
     146,   147,   147,   148,   149,   149,   149,   150,   150,   150,
     151,   151,   151,   151,   152,   152,   153,   153,   154,   154,
     155
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
       4,     0,     1,     1,     3,     1,     0,     2,     1,     1,
       1,     1,     3,     4,     3,     2,     3,     3,     4,     1,
       2,     1,     2,     2,     5,     7,     5,     5,     7,     9,
       3,     2,     2,     3,     1,     2,     1,     1,     2,     3,
       1
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
#line 66 "gram.y" /* yacc.c:1646  */
    { msg("primary_expr 1"); }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "gram.y" /* yacc.c:1646  */
    { 
		msg("primary_expr 2");
		//msg("INT_CONSTANT is %d", $<y_int>1);
		
		EN node = createConstantIntExpression((yyvsp[0].y_int));
		(yyval.y_EN) = node;

		// printExpression(node);

		// $<y_int>$ = $<y_int>1;
	}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 78 "gram.y" /* yacc.c:1646  */
    {
		msg("primary_expr 3");
		// msg("DOUBLE CONSTANT is %f", $<y_double>$1);
		
		EN node = createConstantDoubleExpression((yyvsp[0].y_double));
		(yyval.y_EN) = node;

		// printExpression(node);

		// $<y_double>$ = $<y_double>1;
	}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 89 "gram.y" /* yacc.c:1646  */
    {
		msg("primary_expr 4");
		// msg("STRING LITERAL is %s", $<y_string>$1);
	}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 93 "gram.y" /* yacc.c:1646  */
    {
		msg("primary_expr 5");
		(yyval.y_EN) = (yyvsp[-1].y_EN);
	}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 100 "gram.y" /* yacc.c:1646  */
    { msg("postfix_expr 1"); }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 101 "gram.y" /* yacc.c:1646  */
    { msg("postfix_expr 2"); }
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 102 "gram.y" /* yacc.c:1646  */
    { msg("postfix_expr 3"); }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 103 "gram.y" /* yacc.c:1646  */
    { msg("postfix_expr 4"); }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 104 "gram.y" /* yacc.c:1646  */
    { msg("postfix_expr 5"); }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 105 "gram.y" /* yacc.c:1646  */
    { msg("postfix_expr 6"); }
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 106 "gram.y" /* yacc.c:1646  */
    { msg("postfix_expr 7"); }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 120 "gram.y" /* yacc.c:1646  */
    { msg("unary_expr 1"); }
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 121 "gram.y" /* yacc.c:1646  */
    { msg("unary_expr 2"); }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 122 "gram.y" /* yacc.c:1646  */
    { msg("unary_expr 3"); }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 123 "gram.y" /* yacc.c:1646  */
    {
		msg("unary_expr 4"); 
		(yyval.y_EN) = createUnaryExpression((yyvsp[-1].y_unop), (yyvsp[0].y_EN), TRUE);
	}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 127 "gram.y" /* yacc.c:1646  */
    { msg("unary_expr 5"); }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 128 "gram.y" /* yacc.c:1646  */
    { msg("unary_expr 6"); }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 132 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = UNARY_REF; 
	}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 134 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = UNARY_DEREF; 
	}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 136 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = UNARY_PLUS; 
	}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 138 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = UNARY_MINUS; 
	}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 140 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = UNARY_TILDE; 
	}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 142 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = UNARY_NOT; 
	}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 154 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_MULT, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 158 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_DIV, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 162 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_MOD, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 170 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_ADD, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 174 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_SUB, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 182 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_SHIFTL, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 186 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_SHIFTR, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 194 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_LT, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 198 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_GRT, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 202 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_LTE, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 206 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_GRTE, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 214 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_EQUALS, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 218 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_NE, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 226 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_XAND, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 234 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_XNOT, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 242 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_XOR, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 250 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_AND, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 258 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_EN) = createBinaryExpression(BINARY_OR, (yyvsp[-2].y_EN), (yyvsp[0].y_EN));
	}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 269 "gram.y" /* yacc.c:1646  */
    { 
		msg("assignment_expr expr 1");
		(yyval.y_EN) = evaluateExpression((yyvsp[0].y_EN)); 
		printExpression((yyval.y_EN));
					   }
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 274 "gram.y" /* yacc.c:1646  */
    {
		// Note: for x=5, unary_expr is $<y_DN>1, operator is '=', and assignment_expr should be a $<y_EN>3.
		// Convert $<y_DN>1 to $<y_EN>1 ?


		// Do a symbol table lookup to ensure x has already been defined
		char* s = st_get_id_str((yyvsp[-2].y_DN)->u.st_id.i);

		//st_lookup_id(st_get_id_str($<y_DN>1
		msg("Found assignment_expr 2. variable is %s",s);
	}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 293 "gram.y" /* yacc.c:1646  */
    {msg("found expr 1");}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 294 "gram.y" /* yacc.c:1646  */
    {msg("found expr 2");}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 311 "gram.y" /* yacc.c:1646  */
    { error("no declarator in declaration");}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 312 "gram.y" /* yacc.c:1646  */
    {
		// Combine the type of declaration_specifiers (held in a bucket)
		// with the type of init_declarator_list HERE!!!!!
	}
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 321 "gram.y" /* yacc.c:1646  */
    { 
		
		(yyval.y_bucketPtr) = buildBucket(NULL, (yyvsp[0].y_typeSpec));
	}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 325 "gram.y" /* yacc.c:1646  */
    { 
		
		(yyval.y_bucketPtr) = buildBucket((yyvsp[0].y_bucketPtr), (yyvsp[-1].y_typeSpec));
	}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 329 "gram.y" /* yacc.c:1646  */
    {
		
		(yyval.y_bucketPtr) = buildBucket(NULL, (yyvsp[0].y_typeSpec));
	}
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 333 "gram.y" /* yacc.c:1646  */
    {
		
		(yyval.y_bucketPtr) = buildBucket((yyvsp[0].y_bucketPtr), (yyvsp[-1].y_typeSpec));
	}
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 340 "gram.y" /* yacc.c:1646  */
    { 
		
		//msg("In init_declarator");
		// print_tree($<y_DN>1);

		TYPE baseType = build_base((yyvsp[-1].y_bucketPtr));
		TYPE derivedType = building_derived_type_and_install_st((yyvsp[0].y_DN), baseType);
		GLD((yyvsp[0].y_DN), baseType, derivedType, installSuccessful);
	}
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 349 "gram.y" /* yacc.c:1646  */
    {
		
		//msg("In init_declarator");
		// building_derived_type_and_install_st($<y_DN>3, build_base($<y_bucketPtr>0));
		TYPE baseType = build_base((yyvsp[-3].y_bucketPtr));
		TYPE derivedType = building_derived_type_and_install_st((yyvsp[0].y_DN), baseType);
		GLD((yyvsp[0].y_DN), baseType, derivedType, installSuccessful);
	}
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 361 "gram.y" /* yacc.c:1646  */
    {
		msg("here1");
	}
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 371 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = VOID_SPEC;}
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 372 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = CHAR_SPEC;}
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 373 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = SHORT_SPEC;}
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 374 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = INT_SPEC;}
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 375 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = LONG_SPEC;}
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 376 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = FLOAT_SPEC;}
#line 2281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 377 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = DOUBLE_SPEC;}
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 378 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = SIGNED_SPEC;}
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 379 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = UNSIGNED_SPEC;}
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 380 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = STRUCT_SPEC;}
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 381 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = ENUM_SPEC;}
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 382 "gram.y" /* yacc.c:1646  */
    { (yyval.y_typeSpec) = TYPENAME_SPEC;}
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 411 "gram.y" /* yacc.c:1646  */
    {
		//msg("Found *");
	}
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 441 "gram.y" /* yacc.c:1646  */
    {
		msg("here2");
	}
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 447 "gram.y" /* yacc.c:1646  */
    { 
		(yyval.y_typeSpec) = CONST_SPEC;
	}
#line 2341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 450 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_typeSpec) = VOLATILE_SPEC;
	}
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 457 "gram.y" /* yacc.c:1646  */
    {
		
		//if($<y_ref>1 == TRUE)
			//msg("Reference passed");
		//else;
			//msg("Found 'pointer declarator'");
		(yyval.y_DN) = makePtrNode((yyvsp[0].y_DN), (yyvsp[-1].y_ref));
		//}
	}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 470 "gram.y" /* yacc.c:1646  */
    { 
		//msg("Found ( declarator )");
		(yyval.y_DN) = (yyvsp[-1].y_DN);
	}
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 475 "gram.y" /* yacc.c:1646  */
    { 
			(yyval.y_DN) = makeArrayNode((yyvsp[-3].y_DN), (yyvsp[-1].y_int));
	}
#line 2380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 478 "gram.y" /* yacc.c:1646  */
    {
			if(checkParam((yyvsp[-1].y_PL)))
				(yyval.y_DN) = makeFnNode((yyvsp[-3].y_DN), (yyvsp[-1].y_PL));
			else
				(yyval.y_DN) = NULL;
	}
#line 2391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 484 "gram.y" /* yacc.c:1646  */
    {
		(yyval.y_DN) = makeFnNode((yyvsp[-2].y_DN), NULL);
	}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 492 "gram.y" /* yacc.c:1646  */
    { (yyval.y_ref) = FALSE; }
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 493 "gram.y" /* yacc.c:1646  */
    { (yyval.y_ref) = TRUE;}
#line 2411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 497 "gram.y" /* yacc.c:1646  */
    { (yyval.y_PL) = (yyvsp[0].y_PL);}
#line 2417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 498 "gram.y" /* yacc.c:1646  */
    { error("Elipsis not allowed"); }
#line 2423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 502 "gram.y" /* yacc.c:1646  */
    {
			(yyval.y_PL) = (yyvsp[0].y_PL);
			(yyval.y_PL)->prev = (yyvsp[0].y_PL);
	}
#line 2432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 506 "gram.y" /* yacc.c:1646  */
    {
		if(((yyvsp[0].y_PL) == NULL) || (yyvsp[-2].y_PL) == NULL)
			(yyval.y_PL) = NULL;
		else {
			(yyval.y_PL) = linkParams((yyvsp[-2].y_PL), (yyvsp[0].y_PL));
		}
	}
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 516 "gram.y" /* yacc.c:1646  */
    {
		TYPE baseType = build_base((yyvsp[-1].y_bucketPtr));
		(yyval.y_PL) = build_Param((yyvsp[0].y_DN), baseType, NULL);
	}
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 520 "gram.y" /* yacc.c:1646  */
    { error("no id in parameter list"); (yyval.y_PL) = NULL; }
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 572 "gram.y" /* yacc.c:1646  */
    {msg("found statement 6");}
#line 2465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 573 "gram.y" /* yacc.c:1646  */
    { st_enter_block(); }
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 573 "gram.y" /* yacc.c:1646  */
    {msg("found statement 1"); st_exit_block();}
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 574 "gram.y" /* yacc.c:1646  */
    {msg("found statement 2");}
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 575 "gram.y" /* yacc.c:1646  */
    {msg("found statement 3");}
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 576 "gram.y" /* yacc.c:1646  */
    {msg("found statement 4");}
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 577 "gram.y" /* yacc.c:1646  */
    {msg("found statement 5");}
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 588 "gram.y" /* yacc.c:1646  */
    {msg("found compound_statement 1");}
#line 2507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 589 "gram.y" /* yacc.c:1646  */
    {msg("found compound_statement 2");}
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 590 "gram.y" /* yacc.c:1646  */
    {msg("found compound_statement 3");}
#line 2519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 599 "gram.y" /* yacc.c:1646  */
    { msg("found statement_list 1");}
#line 2525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 600 "gram.y" /* yacc.c:1646  */
    { msg("found statement_list 2");}
#line 2531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 604 "gram.y" /* yacc.c:1646  */
    {
		msg("expr_opt ';'");
	}
#line 2539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 643 "gram.y" /* yacc.c:1646  */
    {
		//fprintf(stderr, "inside function_definition w {}\n");
	}
#line 2547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 646 "gram.y" /* yacc.c:1646  */
    {
		//fprintf(stderr, "inside function_definition w {}\n");
	}
#line 2555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 656 "gram.y" /* yacc.c:1646  */
    { 

		
		
		// Do a symbol table lookup to see if identifier has already been defined
		ST_ID s = st_lookup_id((yyvsp[0].y_string));
		if (s != NULL) {
			// identifier has already been defined in symtab.
			// Thus simply return a constant expr node
			msg("Found INDENTIFIER; %s already exists in symtab!", (yyvsp[0].y_string));
			(yyval.y_EN) = createVariableExpression(s);
		} 
		else {
			msg("Found IDENTIFIER; Enrolling %s",(yyvsp[0].y_string)); 
			ST_ID varName = st_enter_id((yyvsp[0].y_string));
			(yyval.y_DN) = makeIdNode(varName);
		}
		


	}
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2585 "y.tab.c" /* yacc.c:1646  */
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
#line 678 "gram.y" /* yacc.c:1906  */


extern int column;

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
