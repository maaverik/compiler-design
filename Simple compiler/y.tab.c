/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "expl.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "exptree.h"
	#include "sym_table.h"
	#include "codegen.h"
	#include "lsym_table.h"
	#include "typetable.h"

	#define YYSTYPE struct tnode*

	int yylex();
	extern FILE *yyin;
	int isGDeclOver = 0;
	int yyerror(char *);
	struct Lsymbol *LST = NULL;
	struct Typetable *var_type;
	int nextLocation = 1;
	extern struct Typetable *VAR_TYPE_INT;
	extern struct Typetable *VAR_TYPE_INTARR;
	extern struct Typetable *VAR_TYPE_BOOLARR;
	extern struct Typetable *VAR_TYPE_BOOL;
	extern struct Typetable *VAR_TYPE_VOID;


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
    ID = 258,
    READ = 259,
    ASGN = 260,
    NEWLINE = 261,
    WRITE = 262,
    PLUS = 263,
    MUL = 264,
    MINUS = 265,
    DIV = 266,
    EVAL = 267,
    IF = 268,
    THEN = 269,
    ELSE = 270,
    WHILE = 271,
    DO = 272,
    ENDWHILE = 273,
    ENDIF = 274,
    LT = 275,
    GT = 276,
    EQ = 277,
    NEQ = 278,
    STMT = 279,
    BREAK = 280,
    CONTINUE = 281,
    BEG = 282,
    END = 283,
    DECL = 284,
    ENDDECL = 285,
    INT = 286,
    BOOL = 287,
    MAIN = 288,
    RET = 289,
    ARGS = 290,
    AND = 291,
    OR = 292,
    NOT = 293,
    LE = 294,
    GE = 295,
    BRKP = 296,
    INIT = 297,
    ALLOC = 298,
    FREE = 299,
    TYP = 300,
    ENDTYPE = 301,
    TNULL = 302
  };
#endif
/* Tokens.  */
#define ID 258
#define READ 259
#define ASGN 260
#define NEWLINE 261
#define WRITE 262
#define PLUS 263
#define MUL 264
#define MINUS 265
#define DIV 266
#define EVAL 267
#define IF 268
#define THEN 269
#define ELSE 270
#define WHILE 271
#define DO 272
#define ENDWHILE 273
#define ENDIF 274
#define LT 275
#define GT 276
#define EQ 277
#define NEQ 278
#define STMT 279
#define BREAK 280
#define CONTINUE 281
#define BEG 282
#define END 283
#define DECL 284
#define ENDDECL 285
#define INT 286
#define BOOL 287
#define MAIN 288
#define RET 289
#define ARGS 290
#define AND 291
#define OR 292
#define NOT 293
#define LE 294
#define GE 295
#define BRKP 296
#define INIT 297
#define ALLOC 298
#define FREE 299
#define TYP 300
#define ENDTYPE 301
#define TNULL 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 238 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   534

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  221

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      54,    55,     2,     2,    51,     2,    56,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    35,    35,    36,    39,    41,    42,    45,    46,    49,
      54,    56,    57,    60,    62,    63,    64,    68,    69,    72,
      73,    76,    79,    80,    81,    84,    85,    87,   101,   108,
     117,   118,   121,   175,   183,   190,   193,   206,   207,   210,
     211,   214,   217,   218,   221,   230,   251,   256,   263,   272,
     288,   296,   312,   316,   332,   344,   356,   360,   364,   375,
     394,   395,   396,   404,   408,   411,   418,   419,   420,   428,
     435,   436,   437,   440,   448,   456,   463,   471,   478,   479,
     480,   481,   492,   510,   517,   524,   531,   538,   545,   552,
     559,   566,   573,   594,   595,   599,   605,   606,   609
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "READ", "ASGN", "NEWLINE", "WRITE",
  "PLUS", "MUL", "MINUS", "DIV", "EVAL", "IF", "THEN", "ELSE", "WHILE",
  "DO", "ENDWHILE", "ENDIF", "LT", "GT", "EQ", "NEQ", "STMT", "BREAK",
  "CONTINUE", "BEG", "END", "DECL", "ENDDECL", "INT", "BOOL", "MAIN",
  "RET", "ARGS", "AND", "OR", "NOT", "LE", "GE", "BRKP", "INIT", "ALLOC",
  "FREE", "TYP", "ENDTYPE", "TNULL", "'{'", "'}'", "';'", "','", "'['",
  "']'", "'('", "')'", "'.'", "$accept", "Program", "TypeInit",
  "TypeDefBlock", "TypeDefList", "TypeDef", "TypeDefHead", "FieldDeclList",
  "FieldDecl", "TypeName", "GDefblock", "decllist", "decl", "type",
  "varlist", "var", "FdefList", "Fdef", "arglist", "arg", "LDefBlock",
  "LDefList", "LDecl", "LIdList", "LId", "Mainblock", "Body", "slist",
  "stmt", "Args", "expr", "field", "RetStmt", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   123,   125,
      59,    44,    91,    93,    40,    41,    46
};
# endif

#define YYPACT_NINF -190

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-190)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -190,    14,   -29,  -190,    30,    20,  -190,    -1,  -190,    -8,
      12,    52,  -190,  -190,    75,  -190,  -190,  -190,  -190,    23,
     147,    53,    39,    71,    52,  -190,  -190,  -190,  -190,  -190,
      72,  -190,    76,  -190,  -190,   -46,   -25,  -190,    44,    45,
    -190,  -190,  -190,  -190,    46,    57,   147,  -190,    53,    47,
     147,  -190,    41,    97,    55,    60,  -190,    65,    59,  -190,
    -190,  -190,   147,    88,    74,  -190,   122,   100,    88,  -190,
     129,   138,  -190,   452,    89,   100,  -190,   -12,  -190,  -190,
    -190,    -2,    92,    93,    94,   101,   107,   116,   121,   118,
     123,   393,  -190,   137,  -190,   131,  -190,   129,    38,   127,
     127,   183,   184,   127,   127,   127,  -190,  -190,  -190,   133,
     188,   127,  -190,   170,    77,  -190,  -190,   -20,   127,  -190,
    -190,   127,   145,  -190,   127,   297,  -190,   237,    40,   489,
     144,  -190,    34,   146,   153,   174,   195,  -190,    -9,   152,
     330,  -190,   148,  -190,   489,   127,   127,  -190,  -190,   154,
     216,   127,   127,   127,   127,   127,   127,   102,   113,   127,
     127,   127,   127,  -190,   207,   127,   169,   127,   171,  -190,
     172,   206,   211,  -190,  -190,  -190,   168,   258,    42,  -190,
    -190,  -190,  -190,  -190,  -190,   494,   494,  -190,   494,  -190,
     494,  -190,  -190,   494,   494,   127,   489,  -190,   292,  -190,
    -190,   452,   452,  -190,  -190,  -190,   351,   175,   379,   425,
    -190,   190,   452,   191,   192,  -190,   445,  -190,  -190,   193,
    -190
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     6,     1,     0,     0,    10,     0,     8,     0,
       0,     0,     5,     7,     0,    24,    18,    22,    23,     0,
      20,     0,    22,     0,     0,    31,     3,    16,    14,    15,
       0,    12,     0,    17,    19,    28,     0,    26,     0,     0,
      30,     2,     9,    11,     0,     0,    35,    21,     0,     0,
      35,    13,     0,     0,     0,    34,    25,     0,     0,    27,
      36,    29,    35,     0,     0,    33,     0,     0,     0,    38,
       0,     0,    40,     0,     0,     0,    44,     0,    43,    37,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,    45,     0,    41,     0,     0,     0,
      72,     0,     0,     0,     0,     0,    56,    57,    60,     0,
       0,     0,    47,     0,     0,    32,    42,    81,     0,    79,
      80,     0,     0,    68,     0,     0,    93,     0,     0,    71,
      96,    97,     0,     0,     0,     0,     0,    61,     0,     0,
       0,    46,     0,    69,    64,     0,    72,    76,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,     0,     0,     0,    67,
       0,     0,     0,    65,    66,    98,     0,     0,     0,    62,
      78,    73,    74,    75,    77,    83,    84,    94,    87,    95,
      88,    89,    90,    86,    85,     0,    70,    59,     0,    50,
      52,     0,     0,    63,    82,    92,     0,     0,     0,     0,
      58,     0,     0,     0,     0,    51,     0,    54,    55,     0,
      53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -190,  -190,  -190,  -190,  -190,   226,  -190,  -190,   214,  -190,
    -190,   229,  -190,    11,  -190,   203,  -190,   230,   -43,  -190,
     194,  -190,   199,  -190,   164,   239,   189,  -189,   -90,   119,
     -94,   -73,  -190
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     7,     8,     9,    30,    31,    32,
      11,    19,    20,    53,    36,    37,    24,    25,    54,    55,
      67,    71,    72,    77,    78,    26,    74,    91,    92,   128,
     129,   126,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      93,   112,     6,    98,   125,   127,    45,    58,    46,   134,
     135,   136,   208,   209,     3,    15,     4,   140,    93,    65,
     144,    21,    23,   216,   147,    47,    48,   148,   131,   133,
     150,    21,   145,     6,   146,    23,   101,   139,    96,    97,
      14,   117,    16,    17,    18,    12,   173,   101,   118,    10,
      99,   177,   100,    33,   101,    15,    35,   181,   182,   183,
     184,   185,   186,   188,   190,   191,   192,   193,   194,   119,
     120,   196,    38,   198,    39,    27,   121,    70,    27,    44,
     117,   122,    70,    22,    18,   123,   167,   118,    52,   168,
     101,   165,   124,   165,    59,   166,    51,   205,    49,    50,
      60,   206,    57,    28,    29,   117,    28,    29,   119,   120,
      61,    62,   118,    63,    64,   121,   117,    66,   112,   112,
     142,    42,    68,   118,   143,    15,   112,    73,    93,    93,
     117,   124,    76,   119,   120,    93,    93,   118,    94,    93,
     121,    15,   114,    93,   119,   120,   102,   103,   104,   187,
      15,   121,    69,    17,    18,   105,   124,   106,   119,   120,
     189,   151,   152,   153,   154,   121,   107,   124,    79,    17,
      18,   108,   109,   155,   156,   157,   158,   110,    17,    18,
     115,   124,   151,   152,   153,   154,   130,   132,   137,   159,
     160,   138,   161,   162,   155,   156,   157,   158,   141,   149,
     101,   169,   176,   151,   152,   153,   154,   174,   170,   179,
     159,   160,   195,   161,   162,   155,   156,   157,   158,   197,
     201,   199,   200,   203,   151,   152,   153,   154,   202,   171,
     211,   159,   160,    13,   161,   162,   155,   156,   157,   158,
     215,   217,   218,   220,    43,   151,   152,   153,   154,    34,
     172,    56,   159,   160,    40,   161,   162,   155,   156,   157,
     158,   116,    75,    41,    95,   178,   151,   152,   153,   154,
      80,   180,     0,   159,   160,     0,   161,   162,   155,   156,
     157,   158,     0,     0,     0,     0,     0,     0,     0,     0,
     164,     0,     0,     0,   159,   160,     0,   161,   162,     0,
     151,   152,   153,   154,     0,   151,   152,   153,   154,     0,
       0,   204,   155,   156,   157,   158,     0,   155,   156,   157,
     158,     0,     0,     0,     0,     0,     0,     0,   159,   160,
       0,   161,   162,   159,   160,     0,   161,   162,   151,   152,
     153,   154,     0,     0,     0,   207,     0,   163,     0,     0,
     155,   156,   157,   158,     0,     0,     0,     0,     0,   151,
     152,   153,   154,     0,     0,     0,   159,   160,     0,   161,
     162,   155,   156,   157,   158,     0,     0,     0,     0,     0,
     175,     0,    81,    82,     0,     0,    83,   159,   160,     0,
     161,   162,    84,     0,   212,    85,    81,    82,   213,     0,
      83,   210,     0,     0,    86,    87,    84,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   111,    81,    82,
       0,     0,    83,     0,    88,    89,     0,    90,    84,     0,
       0,    85,     0,   214,     0,     0,     0,     0,    81,    82,
      86,    87,    83,     0,     0,    81,    82,     0,    84,    83,
       0,    85,     0,     0,   219,    84,    88,    89,    85,    90,
      86,    87,     0,     0,     0,     0,     0,    86,    87,     0,
       0,     0,     0,     0,     0,     0,    88,    89,     0,    90,
       0,     0,     0,    88,    89,     0,    90,   151,   152,   153,
     154,     0,   151,   152,   153,   154,     0,     0,     0,   155,
     156,   157,   158,     0,    -1,    -1,    -1,    -1,     0,     0,
       0,     0,     0,     0,     0,   159,   160,     0,   161,   162,
     159,   160,     0,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      73,    91,     3,     5,    98,    99,    52,    50,    54,   103,
     104,   105,   201,   202,     0,     3,    45,   111,    91,    62,
     114,    10,    11,   212,   118,    50,    51,   121,   101,   102,
     124,    20,    52,     3,    54,    24,    56,   110,    50,    51,
      48,     3,    30,    31,    32,    46,    55,    56,    10,    29,
      52,   145,    54,    30,    56,     3,     3,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,    31,
      32,   165,    33,   167,     3,     3,    38,    66,     3,     3,
       3,    43,    71,    31,    32,    47,    52,    10,    31,    55,
      56,    51,    54,    51,    53,    55,    50,    55,    54,    54,
       3,   195,    55,    31,    32,     3,    31,    32,    31,    32,
      55,    51,    10,    48,    55,    38,     3,    29,   208,   209,
      43,    49,    48,    10,    47,     3,   216,    27,   201,   202,
       3,    54,     3,    31,    32,   208,   209,    10,    49,   212,
      38,     3,     5,   216,    31,    32,    54,    54,    54,    47,
       3,    38,    30,    31,    32,    54,    54,    50,    31,    32,
      47,     8,     9,    10,    11,    38,    50,    54,    30,    31,
      32,    50,    54,    20,    21,    22,    23,    54,    31,    32,
      49,    54,     8,     9,    10,    11,     3,     3,    55,    36,
      37,     3,    39,    40,    20,    21,    22,    23,    28,    54,
      56,    55,    54,     8,     9,    10,    11,    55,    55,    55,
      36,    37,     5,    39,    40,    20,    21,    22,    23,    50,
      14,    50,    50,    55,     8,     9,    10,    11,    17,    55,
      55,    36,    37,     7,    39,    40,    20,    21,    22,    23,
      50,    50,    50,    50,    30,     8,     9,    10,    11,    20,
      55,    48,    36,    37,    24,    39,    40,    20,    21,    22,
      23,    97,    68,    24,    75,   146,     8,     9,    10,    11,
      71,    55,    -1,    36,    37,    -1,    39,    40,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    36,    37,    -1,    39,    40,    -1,
       8,     9,    10,    11,    -1,     8,     9,    10,    11,    -1,
      -1,    53,    20,    21,    22,    23,    -1,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    39,    40,    36,    37,    -1,    39,    40,     8,     9,
      10,    11,    -1,    -1,    -1,    53,    -1,    50,    -1,    -1,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,     8,
       9,    10,    11,    -1,    -1,    -1,    36,    37,    -1,    39,
      40,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      50,    -1,     3,     4,    -1,    -1,     7,    36,    37,    -1,
      39,    40,    13,    -1,    15,    16,     3,     4,    19,    -1,
       7,    50,    -1,    -1,    25,    26,    13,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      41,    42,    -1,    44,    -1,    -1,    -1,    34,     3,     4,
      -1,    -1,     7,    -1,    41,    42,    -1,    44,    13,    -1,
      -1,    16,    -1,    18,    -1,    -1,    -1,    -1,     3,     4,
      25,    26,     7,    -1,    -1,     3,     4,    -1,    13,     7,
      -1,    16,    -1,    -1,    19,    13,    41,    42,    16,    44,
      25,    26,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    -1,    44,
      -1,    -1,    -1,    41,    42,    -1,    44,     8,     9,    10,
      11,    -1,     8,     9,    10,    11,    -1,    -1,    -1,    20,
      21,    22,    23,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    -1,    39,    40,
      36,    37,    -1,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,    59,     0,    45,    60,     3,    61,    62,    63,
      29,    67,    46,    62,    48,     3,    30,    31,    32,    68,
      69,    70,    31,    70,    73,    74,    82,     3,    31,    32,
      64,    65,    66,    30,    68,     3,    71,    72,    33,     3,
      74,    82,    49,    65,     3,    52,    54,    50,    51,    54,
      54,    50,    31,    70,    75,    76,    72,    55,    75,    53,
       3,    55,    51,    48,    55,    75,    29,    77,    48,    30,
      70,    78,    79,    27,    83,    77,     3,    80,    81,    30,
      79,     3,     4,     7,    13,    16,    25,    26,    41,    42,
      44,    84,    85,    88,    49,    83,    50,    51,     5,    52,
      54,    56,    54,    54,    54,    54,    50,    50,    50,    54,
      54,    34,    85,    89,     5,    49,    81,     3,    10,    31,
      32,    38,    43,    47,    54,    87,    88,    87,    86,    87,
       3,    88,     3,    88,    87,    87,    87,    55,     3,    88,
      87,    28,    43,    47,    87,    52,    54,    87,    87,    54,
      87,     8,     9,    10,    11,    20,    21,    22,    23,    36,
      37,    39,    40,    50,    53,    51,    55,    52,    55,    55,
      55,    55,    55,    55,    55,    50,    54,    87,    86,    55,
      55,    87,    87,    87,    87,    87,    87,    47,    87,    47,
      87,    87,    87,    87,    87,     5,    87,    50,    87,    50,
      50,    14,    17,    55,    53,    55,    87,    53,    84,    84,
      50,    55,    15,    19,    18,    50,    84,    50,    50,    19,
      50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    59,    60,    60,    61,    61,    62,
      63,    64,    64,    65,    66,    66,    66,    67,    67,    68,
      68,    69,    70,    70,    70,    71,    71,    72,    72,    72,
      73,    73,    74,    75,    75,    75,    76,    77,    77,    78,
      78,    79,    80,    80,    81,    82,    83,    84,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      86,    86,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    88,    88,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     0,     3,     0,     2,     1,     4,
       1,     2,     1,     3,     1,     1,     1,     3,     2,     2,
       1,     3,     1,     1,     1,     3,     1,     4,     1,     4,
       2,     1,     9,     3,     1,     0,     2,     3,     2,     2,
       1,     3,     3,     1,     1,     8,     4,     2,     1,     4,
       5,     8,     5,    10,     8,     8,     2,     2,     7,     5,
       2,     3,     5,     5,     3,     4,     4,     4,     3,     3,
       3,     1,     0,     3,     3,     3,     2,     3,     3,     1,
       1,     1,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     4,     1,     3,     3,     3,     3,     3
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
#line 35 "expl.y" /* yacc.c:1646  */
    {}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 36 "expl.y" /* yacc.c:1646  */
    {}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 39 "expl.y" /* yacc.c:1646  */
    {TypeTableCreate();}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 41 "expl.y" /* yacc.c:1646  */
    {}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 42 "expl.y" /* yacc.c:1646  */
    {}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 45 "expl.y" /* yacc.c:1646  */
    {}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 46 "expl.y" /* yacc.c:1646  */
    {}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 49 "expl.y" /* yacc.c:1646  */
    {
				int size = findSize((struct Fieldlist*)(yyvsp[-1])); TInstall((yyvsp[-3])->NAME,size,(struct Fieldlist*)(yyvsp[-1]));
				}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 54 "expl.y" /* yacc.c:1646  */
    { TInstallId((yyvsp[0])->NAME); (yyval) = (yyvsp[0]);}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 56 "expl.y" /* yacc.c:1646  */
    {(yyval) = (struct tnode *)(yyvsp[0]); insertField((struct Fieldlist*)(yyvsp[-1]),(struct Fieldlist*)(yyvsp[0]));}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 57 "expl.y" /* yacc.c:1646  */
    {(yyval) = (struct tnode *)(yyvsp[0]);}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 60 "expl.y" /* yacc.c:1646  */
    {(yyval) = (struct tnode *)Finstall((char *)(yyvsp[-2]), (yyvsp[-1])->NAME);}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 62 "expl.y" /* yacc.c:1646  */
    {(yyval) = (struct tnode *)strdup("INT");}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 63 "expl.y" /* yacc.c:1646  */
    {(yyval) = (struct tnode *)strdup("BOOL");}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 64 "expl.y" /* yacc.c:1646  */
    {(yyval) = (struct tnode *)(yyvsp[0])->NAME;}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 68 "expl.y" /* yacc.c:1646  */
    {isGDeclOver = 1;}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 69 "expl.y" /* yacc.c:1646  */
    {isGDeclOver = 1;}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 72 "expl.y" /* yacc.c:1646  */
    {}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 73 "expl.y" /* yacc.c:1646  */
    {}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 76 "expl.y" /* yacc.c:1646  */
    {}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 79 "expl.y" /* yacc.c:1646  */
    { var_type = TLookup(strdup("INT"));}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 80 "expl.y" /* yacc.c:1646  */
    { var_type = TLookup(strdup("BOOL"));}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 81 "expl.y" /* yacc.c:1646  */
    { var_type = TLookup((yyvsp[0])->NAME);}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 84 "expl.y" /* yacc.c:1646  */
    {}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 85 "expl.y" /* yacc.c:1646  */
    {}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 87 "expl.y" /* yacc.c:1646  */
    {
		if (Glookup((yyvsp[-3])->NAME) != NULL){
			printf("Already declared\n");
			exit(-1);
		}
		if ((yyvsp[-1])->TYPE != VAR_TYPE_INT) {
			printf("Type error in int array declaration.\n");
			exit(-1);
		}
		if (var_type == VAR_TYPE_INT)
			Ginstall((yyvsp[-3])->NAME, VAR_TYPE_INTARR, 1*(yyvsp[-1])->VALUE, NULL);
		else
			Ginstall((yyvsp[-3])->NAME, VAR_TYPE_BOOLARR, 1*(yyvsp[-1])->VALUE, NULL);
	}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 101 "expl.y" /* yacc.c:1646  */
    {
		if (Glookup((yyvsp[0])->NAME) != NULL){
			printf("Already declared\n");
			exit(-1);
		}
		Ginstall((yyvsp[0])->NAME, var_type, 1, NULL);
	}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 108 "expl.y" /* yacc.c:1646  */
    {
		if (Glookup((yyvsp[-3])->NAME) != NULL){
			printf("Already declared\n");
			exit(-1);
		}
		Ginstall((yyvsp[-3])->NAME, var_type, -1, (struct Paramstruct*)(yyvsp[-1]));
	}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 117 "expl.y" /* yacc.c:1646  */
    {}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 118 "expl.y" /* yacc.c:1646  */
    {}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 121 "expl.y" /* yacc.c:1646  */
    {
		if (var_type == NULL){
			printf("Type is not defined\n");
			exit(-1);
		}
		if (Glookup((yyvsp[-7])->NAME) == NULL){
			printf("%s not defined\n", (yyvsp[-7])->NAME);
			exit(-1);
		}
		struct Paramstruct *p = Glookup((yyvsp[-7])->NAME)->paramlist;
		struct Paramstruct *t = (struct Paramstruct *)(yyvsp[-5]);
		while (t != NULL && p != NULL){
			if (t->type != p->type){
				printf("Argument types don't match 1\n");
				exit(0);
			}
			if (strcmp(t->name, p->name) != 0){
				printf("Argument names don't match\n");
				exit(0);
			}
			t = t->next;
			p = p->next;
		}
		if (t != NULL || p != NULL){
			printf("Incorrect number of arguments 1\n");
			exit(0);
		}

		int argBinding = -3;
		p = (struct Paramstruct*)(yyvsp[-5]);
		while(p != NULL){		// Adding parameters to local symbol table
			LLookup(p->name)->binding = argBinding;
			argBinding--;
			p = p->next;
		}

		struct Lsymbol *l = LST;
		int size = 0;
		while (l != NULL){
			if (l->binding < 0){
				l = l->next;
				continue;
			}
			size++;
			l = l->next;
		}
		Glookup((yyvsp[-7])->NAME)->size = size;
		Glookup((yyvsp[-7])->NAME)->local = LST;
		codeGenStart((yyvsp[-1]), (yyvsp[-7])->NAME);
		LST = NULL;
		nextLocation = 1;
	}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 175 "expl.y" /* yacc.c:1646  */
    {
		if (isGDeclOver){
			Linstall(((struct Paramstruct*)(yyvsp[-2]))->name, ((struct Paramstruct*)(yyvsp[-2]))->type, 1);
			nextLocation = 1;
		}
		((struct Paramstruct*)(yyvsp[-2]))->next=((struct Paramstruct*)(yyvsp[0]));
		(yyval) = (yyvsp[-2]);
	}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 183 "expl.y" /* yacc.c:1646  */
    {
		if (isGDeclOver){
			Linstall(((struct Paramstruct*)(yyvsp[0]))->name, ((struct Paramstruct*)(yyvsp[0]))->type, 1);
			nextLocation = 1;
		}
		(yyval) = (yyvsp[0]);
	}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 190 "expl.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 193 "expl.y" /* yacc.c:1646  */
    {
		if (var_type == NULL){
			printf("Type is not defined\n");
			exit(-1);
		}
		struct Paramstruct *p = malloc(sizeof(struct Paramstruct));
		p->name = (yyvsp[0])->NAME;
		p->type = var_type;
		p->next = NULL;
		(yyval) = (struct tnode*)p;
	}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 206 "expl.y" /* yacc.c:1646  */
    {}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 207 "expl.y" /* yacc.c:1646  */
    {}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 210 "expl.y" /* yacc.c:1646  */
    {}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 211 "expl.y" /* yacc.c:1646  */
    {}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 214 "expl.y" /* yacc.c:1646  */
    {}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 217 "expl.y" /* yacc.c:1646  */
    {}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 218 "expl.y" /* yacc.c:1646  */
    {}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 221 "expl.y" /* yacc.c:1646  */
    {
		if (LLookup((yyvsp[0])->NAME) != NULL){
			printf("Already declared %s", (yyvsp[0])->NAME);
			exit(-1);
		}
		Linstall((yyvsp[0])->NAME,var_type,1);
	}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 230 "expl.y" /* yacc.c:1646  */
    {
		Ginstall("MAIN", VAR_TYPE_INT, -1, NULL);
		struct Lsymbol *l = LST;
		int size = 0;
		while (l != NULL){
			if (l->binding < 0){
				l = l->next;
				continue;
			}
			size++;
			l = l->next;
		}
		Glookup("MAIN")->size = size;
		Glookup("MAIN")->local = LST;
		codeGenStart((yyvsp[-1]), "MAIN");
		LST = NULL;
		nextLocation = 1;
		exit(0);
	}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 251 "expl.y" /* yacc.c:1646  */
    {
		(yyval) = TreeCreate(VAR_TYPE_VOID, STMT, -1, NULL, NULL, (yyvsp[-2]), (yyvsp[-1]), NULL);
	}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 256 "expl.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1])->TYPE != VAR_TYPE_VOID || (yyvsp[0])->TYPE != VAR_TYPE_VOID){
			printf("Type error\n");
			exit(-1);
		}
		(yyval) = TreeCreate(VAR_TYPE_VOID, STMT, -1, NULL, NULL, (yyvsp[-1]), (yyvsp[0]), NULL);
	}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 263 "expl.y" /* yacc.c:1646  */
    {
     	if((yyvsp[0])->TYPE != VAR_TYPE_VOID){
     		printf("Type error\n");
			exit(-1);
     	}
     	(yyval) = (yyvsp[0]);
    }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 272 "expl.y" /* yacc.c:1646  */
    {
			if(Glookup((yyvsp[-3])->NAME) == NULL && LLookup((yyvsp[-3])->NAME) == NULL){
				printf("Unallocated variable '%s in asgn'\n", (yyvsp[-3])->NAME);
				exit(0);
			}
			if(LLookup((yyvsp[-3])->NAME) == NULL && Glookup((yyvsp[-3])->NAME)->paramlist != NULL){
				printf("Cannot assign to function '%s'\n", (yyvsp[-3])->NAME);
				exit(0);
			}
			if(LLookup((yyvsp[-3])->NAME) == NULL && Glookup((yyvsp[-3])->NAME)->type != (yyvsp[-1])->TYPE){
				printf("type error: =\n");
				exit(0);
			}
			(yyval) = TreeCreate(VAR_TYPE_VOID, ASGN, -1,  (yyvsp[-3])->NAME, NULL, (yyvsp[-3]), (yyvsp[-1]), NULL);
		}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 288 "expl.y" /* yacc.c:1646  */
    {
			if(Glookup((yyvsp[-2])->NAME ) == NULL && LLookup((yyvsp[-2])->NAME) == NULL){
				printf("Unallocated variable '%s' in read\n", (yyvsp[-2])->NAME);
				exit(0);
			}
			(yyval) = TreeCreate(VAR_TYPE_VOID, READ, -1, (yyvsp[-2])->NAME, NULL, (yyvsp[-2]), NULL, NULL);
		}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 296 "expl.y" /* yacc.c:1646  */
    {
			if(Glookup((yyvsp[-5])->NAME) == NULL && LLookup((yyvsp[-5])->NAME) == NULL){
				printf("Unallocated variable '%s' in readarr\n", (yyvsp[-5])->NAME);
				exit(0);
			}
			if((yyvsp[-3])->TYPE != VAR_TYPE_INT) {
				printf("type error: ARRREAD[expr]");
				exit(0);
			}
			if(Glookup((yyvsp[-5])->NAME)->type != VAR_TYPE_INTARR && Glookup((yyvsp[-5])->NAME)->type != VAR_TYPE_BOOLARR)	{
				printf("type error: ARRREAD");
				exit(0);
			}
	 	 	(yyval) = TreeCreate(VAR_TYPE_VOID, ARRREAD, 0, (yyvsp[-5])->NAME, NULL, (yyvsp[-3]), NULL, NULL);
		}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 312 "expl.y" /* yacc.c:1646  */
    {
			(yyval) = TreeCreate(VAR_TYPE_VOID, WRITE, -1, NULL, NULL, (yyvsp[-2]), NULL, NULL);
		}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 316 "expl.y" /* yacc.c:1646  */
    {
			if((yyvsp[-7])->TYPE != VAR_TYPE_BOOL){
				printf("type error: IF\n");
				exit(0);
			}
			if((yyvsp[-4])->TYPE != VAR_TYPE_VOID){
				printf("type error: THEN\n");
				exit(0);
			}
			if((yyvsp[-2])->TYPE != VAR_TYPE_VOID){
				printf("type error: ELSE\n");
				exit(0);
			}
			(yyval) = TreeCreate(VAR_TYPE_VOID, IF, -1, NULL, NULL, (yyvsp[-7]), (yyvsp[-4]), (yyvsp[-2]));
		}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 332 "expl.y" /* yacc.c:1646  */
    {
			if((yyvsp[-5])->TYPE != VAR_TYPE_BOOL){
				printf("type error: IF\n");
				exit(0);
			}
			if((yyvsp[-2])->TYPE != VAR_TYPE_VOID){
				printf("type error: THEN\n");
				exit(0);
			}
			(yyval) = TreeCreate(VAR_TYPE_VOID, IF, -1, NULL, NULL, (yyvsp[-5]), (yyvsp[-2]), NULL);
		}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 344 "expl.y" /* yacc.c:1646  */
    {
			if((yyvsp[-5])->TYPE != VAR_TYPE_BOOL){
				printf("type error: WHILE\n");
				exit(0);
			}
			if((yyvsp[-2])->TYPE != VAR_TYPE_VOID){
				printf("type error: DO\n");
				exit(0);
			}
			(yyval) = TreeCreate(VAR_TYPE_VOID, WHILE, -1, NULL, NULL, (yyvsp[-5]), (yyvsp[-2]), NULL);
		}
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 356 "expl.y" /* yacc.c:1646  */
    {
			(yyval) = TreeCreate(VAR_TYPE_VOID, BREAK, -1, NULL, NULL, NULL, NULL, NULL);
		}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 360 "expl.y" /* yacc.c:1646  */
    {
			(yyval) = TreeCreate(VAR_TYPE_VOID, CONTINUE, -1, NULL, NULL, NULL, NULL, NULL);
		}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 364 "expl.y" /* yacc.c:1646  */
    {
			if(Glookup((yyvsp[-6])->NAME) == NULL && LLookup((yyvsp[-6])->NAME) == NULL){
				printf("Unallocated variable '%s' in asgnarr\n", (yyvsp[-6])->NAME);
				exit(0);
			}
			if(!(Glookup((yyvsp[-6])->NAME)->type == VAR_TYPE_INTARR || (yyvsp[-4])->TYPE == VAR_TYPE_INT || (yyvsp[-1])->TYPE == VAR_TYPE_INT) && !(Glookup((yyvsp[-6])->NAME)->type == VAR_TYPE_BOOLARR || (yyvsp[-4])->TYPE == VAR_TYPE_INT || (yyvsp[-1])->TYPE == VAR_TYPE_BOOL)){
				printf("type error: []=\n");
				exit(0);
	 		}
			(yyval) = TreeCreate(VAR_TYPE_VOID, ARRASGN, -1, (yyvsp[-6])->NAME, NULL, (yyvsp[-4]), (yyvsp[-1]), NULL);
 		}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 375 "expl.y" /* yacc.c:1646  */
    {
 			struct Paramstruct *p = Glookup((yyvsp[-4])->NAME)->paramlist;
			struct tnode *t = (yyvsp[-2]);
			printf("Func: %s\n", (yyvsp[-4])->NAME);
			while (t != NULL && p != NULL){
				printf("Val : %d\n", t->Ptr1->VALUE);
				if (t->TYPE != p->type){
					printf("Argument types don't match 2\n");
					exit(0);
				}
				t = t->Arglist;
				p = p->next;
			}
 			if (t != NULL || p != NULL){
 				printf("Incorrect number of arguments 2\n");
 				exit(0);
 			}
 			(yyval) = TreeCreate(VAR_TYPE_VOID, FUNCCALL, -1, (yyvsp[-4])->NAME, (yyvsp[-2]), NULL, NULL, NULL);
 		}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 394 "expl.y" /* yacc.c:1646  */
    {(yyval) = TreeCreate(VAR_TYPE_VOID, BRKP, -1, NULL, NULL, NULL, NULL, NULL);}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 395 "expl.y" /* yacc.c:1646  */
    {(yyval) = TreeCreate(VAR_TYPE_VOID, INIT, -1, NULL, NULL, NULL, NULL, NULL);}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 396 "expl.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-4])->TYPE == VAR_TYPE_BOOL || (yyvsp[-4])->TYPE == VAR_TYPE_INT){
				printf("Not a user defined type\n");
				exit(-1);
			}
			(yyvsp[-2]) = TreeCreate(VAR_TYPE_VOID, ALLOC, -1, NULL, NULL, NULL, NULL, NULL);
			(yyval) = TreeCreate(VAR_TYPE_VOID, ASGN, -1,  (yyvsp[-4])->NAME, NULL, (yyvsp[-4]), (yyvsp[-2]), NULL);
		}
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 404 "expl.y" /* yacc.c:1646  */
    {
			(yyvsp[-2]) = TreeCreate(VAR_TYPE_VOID, ALLOC, -1, NULL, NULL, NULL, NULL, NULL);
			(yyval) = TreeCreate(VAR_TYPE_VOID, ASGN, -1,  NULL, NULL, (yyvsp[-4]), (yyvsp[-2]), NULL);
		}
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 408 "expl.y" /* yacc.c:1646  */
    {
			(yyval) = TreeCreate(VAR_TYPE_VOID, ASGN, -1,  NULL, NULL, (yyvsp[-2]), (yyvsp[0]), NULL);
		}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 411 "expl.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-1])->TYPE == VAR_TYPE_BOOL || (yyvsp[-1])->TYPE == VAR_TYPE_INT){
				printf("Not a user defined type pointer\n");
				exit(-1);
			}
			(yyval) = TreeCreate(VAR_TYPE_VOID, FREE, -1, NULL, NULL, (yyvsp[-1]), NULL, NULL);
		}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 418 "expl.y" /* yacc.c:1646  */
    {(yyval) = TreeCreate(VAR_TYPE_VOID, FREE, -1, NULL, NULL, (yyvsp[-1]), NULL, NULL);}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 419 "expl.y" /* yacc.c:1646  */
    {TreeCreate(VAR_TYPE_VOID, READ, -1, NULL, NULL, (yyvsp[-1]), NULL, NULL);}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 420 "expl.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-2])->TYPE == VAR_TYPE_INT || (yyvsp[-2])->TYPE == VAR_TYPE_BOOL || (yyvsp[-2])->TYPE == VAR_TYPE_VOID || (yyvsp[-2])->TYPE == VAR_TYPE_BOOLARR || (yyvsp[-2])->TYPE == VAR_TYPE_INTARR){
				printf("Type error: null");
				exit(-1);
			}
			(yyvsp[0]) = TreeCreate(VAR_TYPE_VOID, TNULL, -1, NULL, NULL, NULL, NULL, NULL);
			(yyval) = TreeCreate(VAR_TYPE_VOID, ASGN, -1,  NULL, NULL, (yyvsp[-2]), (yyvsp[0]), NULL);
		}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 428 "expl.y" /* yacc.c:1646  */
    {
			(yyvsp[0]) = TreeCreate(VAR_TYPE_VOID, TNULL, -1, NULL, NULL, NULL, NULL, NULL);
			(yyval) = TreeCreate(VAR_TYPE_VOID, ASGN, -1,  NULL, NULL, (yyvsp[-2]), (yyvsp[0]), NULL);
		}
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 435 "expl.y" /* yacc.c:1646  */
    {(yyval) = TreeCreate((yyvsp[0])->TYPE, ARGS, -1, NULL, (yyvsp[-2]), (yyvsp[0]), NULL, NULL);}
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 436 "expl.y" /* yacc.c:1646  */
    { (yyval) = TreeCreate((yyvsp[0])->TYPE, ARGS, -1, NULL, NULL, (yyvsp[0]), NULL, NULL);}
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 437 "expl.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 440 "expl.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2])->TYPE != VAR_TYPE_INT || (yyvsp[0])->TYPE != VAR_TYPE_INT){
			printf("type error: +\n");
			exit(0);
		}
		(yyval) = makeOperatorNode(PLUS, VAR_TYPE_INT, (yyvsp[-2]), (yyvsp[0]));
	}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 448 "expl.y" /* yacc.c:1646  */
    {
	 	if((yyvsp[-2])->TYPE != VAR_TYPE_INT || (yyvsp[0])->TYPE != VAR_TYPE_INT){
			printf("type error: *\n");
			exit(0);
		}
		(yyval) = makeOperatorNode(MUL, VAR_TYPE_INT, (yyvsp[-2]), (yyvsp[0]));
	}
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 456 "expl.y" /* yacc.c:1646  */
    {
	 	if((yyvsp[-2])->TYPE != VAR_TYPE_INT || (yyvsp[0])->TYPE != VAR_TYPE_INT){
			printf("type error: -\n");
			exit(0);
		}
		(yyval) = makeOperatorNode(MINUS, VAR_TYPE_INT, (yyvsp[-2]), (yyvsp[0]));
	}
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 463 "expl.y" /* yacc.c:1646  */
    {
	 	if((yyvsp[0])->TYPE != VAR_TYPE_INT){
			printf("type error: unary -\n");
			exit(0);
		}
		(yyval) = makeOperatorNode(MINUS, VAR_TYPE_INT, 0, (yyvsp[0]));
	}
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 471 "expl.y" /* yacc.c:1646  */
    {
	 	if((yyvsp[-2])->TYPE != VAR_TYPE_INT || (yyvsp[0])->TYPE != VAR_TYPE_INT){
			printf("type error: /\n");
			exit(0);
		}
		(yyval) = makeOperatorNode(DIV, VAR_TYPE_INT, (yyvsp[-2]), (yyvsp[0]));
	}
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 478 "expl.y" /* yacc.c:1646  */
    {(yyval) = TreeCreate((yyvsp[-1])->TYPE, EVAL, -1, NULL, NULL, (yyvsp[-1]), NULL, NULL);}
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 479 "expl.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 480 "expl.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 481 "expl.y" /* yacc.c:1646  */
    {
	  	if (LLookup((yyvsp[0])->NAME) != NULL)
	 		(yyvsp[0])->TYPE = LLookup((yyvsp[0])->NAME)->type;
	 	else if (Glookup((yyvsp[0])->NAME) != NULL)
	 		(yyvsp[0])->TYPE = Glookup((yyvsp[0])->NAME)->type;
	 	else{
	 		printf("Undeclared variable %s\n", (yyvsp[0])->NAME);
	 		exit(-1);
	 	}
	 	(yyval) = (yyvsp[0]);
	 }
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 492 "expl.y" /* yacc.c:1646  */
    {
	 	if((yyvsp[-1])->TYPE != VAR_TYPE_INT){
	 		printf("type error: []\n");
			exit(0);
	 	}
	 	if (Glookup((yyvsp[-3])->NAME) != NULL){
	 		if(Glookup((yyvsp[-3])->NAME)->type == VAR_TYPE_INTARR){
		 		(yyval) = makeOperatorNode(ARRVAL, VAR_TYPE_INT, (yyvsp[-3]), (yyvsp[-1]));
		 	}
		 	else if(Glookup((yyvsp[-3])->NAME)->type == VAR_TYPE_BOOLARR){
		 		(yyval) = makeOperatorNode(ARRVAL, VAR_TYPE_BOOL, (yyvsp[-3]), (yyvsp[-1]));
	 		}
	 	}
	 	else{
	 		printf("Undeclared array %s\n", (yyvsp[-3])->NAME);
	 		exit(-1);
	 	}
	 }
#line 2334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 510 "expl.y" /* yacc.c:1646  */
    {
	 	if((yyvsp[-2])->TYPE != VAR_TYPE_INT || (yyvsp[0])->TYPE != VAR_TYPE_INT){
			printf("type error: <\n");
			exit(0);
		}
		 (yyval) = makeOperatorNode(LT, VAR_TYPE_BOOL, (yyvsp[-2]), (yyvsp[0]));
	 }
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 517 "expl.y" /* yacc.c:1646  */
    {
	 	if((yyvsp[-2])->TYPE != VAR_TYPE_INT || (yyvsp[0])->TYPE != VAR_TYPE_INT){
			printf("type error: >\n");
			exit(0);
		}
		 (yyval) = makeOperatorNode(GT, VAR_TYPE_BOOL, (yyvsp[-2]), (yyvsp[0]));
	 }
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 524 "expl.y" /* yacc.c:1646  */
    {
	 	if((yyvsp[-2])->TYPE != VAR_TYPE_INT || (yyvsp[0])->TYPE != VAR_TYPE_INT){
			printf("type error: >\n");
			exit(0);
		}
		 (yyval) = makeOperatorNode(GE, VAR_TYPE_BOOL, (yyvsp[-2]), (yyvsp[0]));
	 }
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 531 "expl.y" /* yacc.c:1646  */
    {
	 	if((yyvsp[-2])->TYPE != VAR_TYPE_INT || (yyvsp[0])->TYPE != VAR_TYPE_INT){
			printf("type error: >\n");
			exit(0);
		}
		 (yyval) = makeOperatorNode(LE, VAR_TYPE_BOOL, (yyvsp[-2]), (yyvsp[0]));
	 }
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 538 "expl.y" /* yacc.c:1646  */
    {
	 	if(!(((yyvsp[-2])->TYPE == VAR_TYPE_INT && (yyvsp[0])->TYPE == VAR_TYPE_INT) || ((yyvsp[-2])->TYPE == VAR_TYPE_BOOL && (yyvsp[0])->TYPE == VAR_TYPE_BOOL))){
			printf("type error: ==\n");
			exit(0);
		}
		 (yyval) = makeOperatorNode(EQ, VAR_TYPE_BOOL, (yyvsp[-2]), (yyvsp[0]));
	 }
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 545 "expl.y" /* yacc.c:1646  */
    {
	 	if((yyvsp[-2])->TYPE != VAR_TYPE_INT || (yyvsp[0])->TYPE != VAR_TYPE_INT){
			printf("type error: !=\n");
			exit(0);
		}
		 (yyval) = makeOperatorNode(NEQ, VAR_TYPE_BOOL, (yyvsp[-2]), (yyvsp[0]));
	 }
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 552 "expl.y" /* yacc.c:1646  */
    {
	 	if((yyvsp[-2])->TYPE != VAR_TYPE_BOOL || (yyvsp[0])->TYPE != VAR_TYPE_BOOL){
			printf("type error: &&\n");
			exit(0);
		}
		 (yyval) = makeOperatorNode(AND, VAR_TYPE_BOOL, (yyvsp[-2]), (yyvsp[0]));
	 }
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 559 "expl.y" /* yacc.c:1646  */
    {
	 	if((yyvsp[-2])->TYPE != VAR_TYPE_BOOL || (yyvsp[0])->TYPE != VAR_TYPE_BOOL){
			printf("type error: ||\n");
			exit(0);
		}
		 (yyval) = makeOperatorNode(OR, VAR_TYPE_BOOL, (yyvsp[-2]), (yyvsp[0]));
	 }
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 566 "expl.y" /* yacc.c:1646  */
    {
	 	if((yyvsp[-1])->TYPE != VAR_TYPE_BOOL){
			printf("type error: ||\n");
			exit(0);
		}
		 (yyval) = makeOperatorNode(NOT, VAR_TYPE_BOOL, (yyvsp[-1]), NULL);
	 }
#line 2442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 573 "expl.y" /* yacc.c:1646  */
    {
 			struct Paramstruct *p = Glookup((yyvsp[-3])->NAME)->paramlist;
			struct tnode *t = (yyvsp[-1]);
			while (t != NULL && p != NULL){
				if (t->TYPE != p->type){
					printf("Argument types don't match 3\n");
					exit(0);
				}
				t = t->Arglist;
				p = p->next;
			}
 			if (t != NULL || p != NULL){
 				printf("Incorrect number of arguments 3\n");
 				if (t != NULL)
 					printf("t\n");
 				else
 					printf("p\n");
 				exit(0);
 			}
 			(yyval) = TreeCreate(Glookup((yyvsp[-3])->NAME)->type, FUNCCALL, -1, (yyvsp[-3])->NAME, (yyvsp[-1]), NULL, NULL, NULL);
 		}
#line 2468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 594 "expl.y" /* yacc.c:1646  */
    {(yyval) = TreeCreate(NULL, FIELD, -1, NULL, NULL, (yyvsp[0]), NULL, NULL);}
#line 2474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 595 "expl.y" /* yacc.c:1646  */
    {
 			(yyvsp[0]) = TreeCreate(NULL, TNULL, -1, NULL, NULL, NULL, NULL, NULL);
		 	(yyval) = makeOperatorNode(EQ, VAR_TYPE_BOOL, (yyvsp[-2]), (yyvsp[0]));
	    }
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 599 "expl.y" /* yacc.c:1646  */
    {
		 	(yyvsp[0]) = TreeCreate(NULL, TNULL, -1, NULL, NULL, NULL, NULL, NULL);
			(yyval) = makeOperatorNode(EQ, VAR_TYPE_BOOL, (yyvsp[-2]), (yyvsp[0]));
	    }
#line 2492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 605 "expl.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-2]); (yyvsp[-2])->Ptr1 = (yyvsp[0]); }
#line 2498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 606 "expl.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-2]); (yyvsp[-2])->Ptr1 = (yyvsp[0]);}
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 609 "expl.y" /* yacc.c:1646  */
    { (yyval) = TreeCreate((yyvsp[-1])->TYPE, RET, -1, NULL, NULL, (yyvsp[-1]), NULL, NULL); }
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2514 "y.tab.c" /* yacc.c:1646  */
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
#line 612 "expl.y" /* yacc.c:1906  */


int yyerror(char *s){
	printf("Error: %s\n", s);
	return -1;
}

int main(int argc, char **argv){
	FILE *fp;
	fp = fopen(argv[1],"r");
	yyin = fp;
	yyparse();
	return 1;
}
