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
#line 1 "synt.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdbool.h>
#include "T.h"



extern FILE* yyin ;
extern int count ;
extern int line;
int yylex();
// bool recherche_syn(char * name);
//void wrap();
int yyerror(char * msg);
int num = 0;

char current_type[10];
char current_entity[10];

tableau * pointer;
tableau * tab = NULL;

bool process = false;
bool loops = false;
bool arrays = false;
bool division = false;


typedef struct tab_type{

	char ptr[10];
	struct tableau * next;

}tab_type;

tab_type * tableau_type = NULL;
tab_type *tmp_type_pointer;
char tmp_type[10];
char tmp_value[10];


#line 108 "synt.tab.c" /* yacc.c:339  */

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
   by #include "synt.tab.h".  */
#ifndef YY_YY_SYNT_TAB_H_INCLUDED
# define YY_YY_SYNT_TAB_H_INCLUDED
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
    mc_proc = 258,
    mc_prog = 259,
    mc_loop = 260,
    mc_arr = 261,
    mc_const = 262,
    mc_integer = 263,
    mc_real = 264,
    mc_car = 265,
    mc_string = 266,
    mc_read = 267,
    mc_write = 268,
    mc_while = 269,
    mc_execut = 270,
    mc_if = 271,
    mc_endif = 272,
    mc_else = 273,
    mc_arithOp = 274,
    mc_logiqOp = 275,
    mc_sep = 276,
    mc_idf = 277,
    mc_signeForma = 278,
    var_sep = 279,
    SEP_READ = 280,
    mc_var = 281,
    integer = 282,
    real = 283,
    string = 284,
    car = 285,
    ADD_OP = 286,
    MUL_OP = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 43 "synt.y" /* yacc.c:355  */

	int  entier;
	char * chaine;
	float real ;
	char chars[10];

#line 188 "synt.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNT_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 205 "synt.tab.c" /* yacc.c:358  */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    37,    33,    34,     2,     2,     2,
      40,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,     2,
       2,     2,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    43,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    65,    65,    67,    67,    68,    69,    70,
      72,    72,    74,    74,    76,    77,    79,    80,    81,    82,
      84,    84,    84,    85,    85,    85,    87,    96,   105,   112,
     117,   121,   125,   130,   143,   157,   163,   163,   163,   164,
     170,   171,   177,   179,   185,   189,   191,   200,   206,   236,
     238,   245,   253,   254,   256,   259,   284,   285,   286,   289,
     290,   290,   292,   292,   293,   293,   293,   293,   293,   295
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mc_proc", "mc_prog", "mc_loop",
  "mc_arr", "mc_const", "mc_integer", "mc_real", "mc_car", "mc_string",
  "mc_read", "mc_write", "mc_while", "mc_execut", "mc_if", "mc_endif",
  "mc_else", "mc_arithOp", "mc_logiqOp", "mc_sep", "mc_idf",
  "mc_signeForma", "var_sep", "SEP_READ", "mc_var", "integer", "real",
  "string", "car", "ADD_OP", "MUL_OP", "'#'", "'$'", "'{'", "':'", "'\"'",
  "'['", "']'", "'('", "')'", "'@'", "'}'", "$accept", "S", "header",
  "Bib_dec", "bib", "begin", "var_dec", "variable_type", "type",
  "constante_list_var", "list_var", "constante_affectation",
  "direct_value", "variable", "affectation", "opera", "express", "operand",
  "constante", "read", "write", "write_var", "write_string", "forma",
  "loop", "loop_keyword", "condition", "if_statement", "else_statement",
  "body", "instruction", "End", YY_NULLPTR
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
     285,   286,   287,    35,    36,   123,    58,    34,    91,    93,
      40,    41,    64,   125
};
# endif

#define YYPACT_NINF -64

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-64)))

#define YYTABLE_NINF -46

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -2,    -1,   -25,    30,     2,    39,   -64,    58,   -64,    -4,
      37,    12,   -64,   -64,   -64,     6,   -64,   -64,   -64,    45,
      18,    22,   -64,    37,   -15,    41,   -64,   -64,   -64,    43,
     -64,    33,    37,   -64,    44,   -64,   -64,   -64,   -64,    46,
      47,    49,    63,   -11,    53,   -64,   -11,   -64,   -64,   -64,
     -64,    51,    62,   -17,    50,    54,   -64,   -64,   -64,    52,
     -11,   -18,   -64,   -64,    55,    16,    56,    66,    59,   -64,
     -17,   -64,    64,   -17,   -11,    68,    61,   -18,    60,   -64,
     -64,   -11,    72,   -11,    65,   -14,   -64,   -64,    -9,     4,
      74,   -64,    71,   -64,    67,    70,   -64,   -64,   -18,   -11,
     -18,    37,     5,    75,    81,    -4,    82,    -4,    69,    80,
      73,    48,   -64,   -18,    76,    36,    38,    40,    77,   -64,
     -18,    79,    88,   -64,   -64,    78,   -64,   -64,    90,    71,
      86,   -64,    95,   -64,   -64,    84,   -64,    83,   -64,   -64,
      37,    42,    89,    96,   -64,   -64
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     4,     0,     1,    11,
       0,     0,     8,     9,     7,     0,    15,    14,    10,     0,
       0,     0,    57,     0,     0,     0,    65,    66,    67,     0,
      68,     0,    62,     3,     6,    18,    19,    17,    16,     0,
       0,     0,     0,     0,     0,    64,     0,    69,     2,    63,
       5,     0,     0,     0,     0,    47,    43,    44,    45,     0,
       0,    35,    37,    36,     0,     0,     0,     0,     0,    55,
       0,    53,     0,     0,     0,     0,     0,     0,    37,    40,
      41,     0,     0,     0,     0,    32,    13,    12,     0,     0,
       0,    52,     0,    54,     0,     0,    42,    38,    39,     0,
      58,     0,     0,     0,     0,    22,     0,    25,     0,    50,
       0,     0,    46,    34,     0,    28,    29,    30,     0,    26,
      27,     0,     0,    21,    20,    32,    24,    23,     0,     0,
       0,    60,     0,    59,    56,     0,    33,     0,    51,    49,
       0,    31,     0,     0,    48,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -64,   -64,    91,   -64,   -64,   -61,   -64,   -64,    11,
      20,   -64,   -64,   -64,   -64,   -42,    85,   -64,   -64,   -64,
     -64,    -7,   -63,   -64,   -64,   -64,    57,   -64,   -64,   -23,
     -64,   -64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    15,    10,    18,    19,    39,    86,
      87,    88,   119,    89,    25,    65,    62,    81,    63,    26,
      27,   110,    72,    73,    28,    29,    66,    30,   133,    31,
      32,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    61,     1,    16,    43,   102,    69,    91,     7,    49,
      93,    55,    70,    79,    80,   104,    56,    57,    77,    58,
      71,     6,    17,    44,   103,   105,    59,    55,   106,    60,
       8,     2,   115,   116,    33,   117,    83,     9,   107,    98,
      34,   100,   118,    11,   124,    60,   127,    79,    80,    20,
      21,    22,    23,    35,    36,    37,    38,   113,    40,    24,
     120,    12,    41,    13,    14,   131,   132,   -43,   -43,   -44,
     -44,   -45,   -45,   -42,   -42,    45,    47,     2,   114,    54,
      64,    76,    51,    46,    52,    68,    53,    67,    85,    92,
      74,    99,    75,   109,    82,    95,    90,    84,    96,   108,
     101,    97,   121,   122,   125,   129,   135,   102,   111,   112,
     140,   128,   137,   145,   130,   123,   103,   143,   136,   134,
     139,   141,   138,   144,   142,    50,   126,     0,     0,     0,
       0,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78
};

static const yytype_int16 yycheck[] =
{
      23,    43,     4,     7,    19,    19,    23,    70,    33,    32,
      73,    22,    29,    31,    32,    24,    27,    28,    60,    30,
      37,    22,    26,    38,    38,    34,    37,    22,    24,    40,
       0,    33,    27,    28,    22,    30,    20,    35,    34,    81,
      34,    83,    37,     4,   105,    40,   107,    31,    32,    12,
      13,    14,    15,     8,     9,    10,    11,    99,    40,    22,
     102,     3,    40,     5,     6,    17,    18,    31,    32,    31,
      32,    31,    32,    31,    32,    34,    43,    33,   101,    16,
      27,    29,    36,    40,    37,    23,    37,    36,    22,    25,
      40,    19,    38,    22,    39,    27,    37,    41,    37,    25,
      35,    41,    27,    22,    22,    25,    29,    19,    41,    39,
      15,    42,    22,    17,    41,   104,    38,   140,    39,    43,
      34,    37,   129,    34,    41,    34,   106,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    33,    45,    46,    47,    22,    33,     0,    35,
      49,     4,     3,     5,     6,    48,     7,    26,    50,    51,
      12,    13,    14,    15,    22,    58,    63,    64,    68,    69,
      71,    73,    74,    22,    34,     8,     9,    10,    11,    52,
      40,    40,    73,    19,    38,    34,    40,    43,    75,    73,
      47,    36,    37,    37,    16,    22,    27,    28,    30,    37,
      40,    59,    60,    62,    27,    59,    70,    36,    23,    23,
      29,    37,    66,    67,    40,    38,    29,    59,    60,    31,
      32,    61,    39,    20,    41,    22,    53,    54,    55,    57,
      37,    66,    25,    66,    70,    27,    37,    41,    59,    19,
      59,    35,    19,    38,    24,    34,    24,    34,    25,    22,
      65,    41,    39,    59,    73,    27,    28,    30,    37,    56,
      59,    27,    22,    53,    50,    22,    54,    50,    42,    25,
      41,    17,    18,    72,    43,    29,    39,    22,    65,    34,
      15,    37,    41,    73,    34,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    48,    48,    48,
      49,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      53,    53,    53,    54,    54,    54,    55,    55,    56,    56,
      56,    56,    57,    57,    58,    58,    59,    59,    59,    60,
      61,    61,    62,    62,    62,    62,    62,    62,    63,    64,
      65,    65,    66,    66,    66,    67,    68,    69,    70,    71,
      72,    72,    73,    73,    74,    74,    74,    74,    74,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     2,     5,     4,     1,     1,     1,
       2,     1,     5,     5,     1,     1,     1,     1,     1,     1,
       3,     3,     2,     3,     3,     2,     3,     3,     1,     1,
       1,     3,     1,     4,     6,     3,     1,     1,     3,     3,
       1,     1,     3,     1,     1,     1,     4,     1,    10,     8,
       1,     3,     2,     1,     2,     1,     7,     1,     3,     7,
       1,     4,     1,     2,     2,     1,     1,     1,     1,     1
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
#line 64 "synt.y" /* yacc.c:1646  */
    {printf("programme juste\n");affich(); YYACCEPT;}
#line 1382 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 68 "synt.y" /* yacc.c:1646  */
    {if(loops){printf("\033[31m warning \033[0m array already included\n");}else{arrays = true;}}
#line 1388 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 69 "synt.y" /* yacc.c:1646  */
    {if(loops){printf("\033[31m warning \033[0m process already included\n");}else{process = true;}}
#line 1394 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 70 "synt.y" /* yacc.c:1646  */
    {if(loops){printf("\033[31m warning \033[0m loop already included\n");}else{loops = true;}}
#line 1400 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 76 "synt.y" /* yacc.c:1646  */
    {strcpy(current_entity,"IDF");}
#line 1406 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 77 "synt.y" /* yacc.c:1646  */
    {strcpy(current_entity,"CONST");}
#line 1412 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 79 "synt.y" /* yacc.c:1646  */
    {strcpy(current_type,"STRING");}
#line 1418 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 80 "synt.y" /* yacc.c:1646  */
    {strcpy(current_type,"CHAR");}
#line 1424 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 81 "synt.y" /* yacc.c:1646  */
    {strcpy(current_type,"INT");}
#line 1430 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 82 "synt.y" /* yacc.c:1646  */
    {strcpy(current_type,"FLOAT");}
#line 1436 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 88 "synt.y" /* yacc.c:1646  */
    {
	if(recherche_syn((yyvsp[-2].chaine))){printf("\033[31m Error \033[0m double declaration for %s",(yyvsp[-2].chaine));affich();YYACCEPT;}else{insert((yyvsp[-2].chaine),current_type,current_entity);}

	if(strcmp(tableau_type->ptr,current_type) != 0){printf("\033[31m Error \033[0m type non compatible!!last type was %s while idf type is %s\n",tableau_type->ptr,current_type);}

	tableau_type = NULL;
	update((yyvsp[-2].chaine),tmp_value);
}
#line 1449 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 97 "synt.y" /* yacc.c:1646  */
    {
if(recherche_syn((yyvsp[-2].chaine))){printf("\033[31m Error \033[0m double declaration for %s",(yyvsp[-2].chaine));affich();YYACCEPT;}else{insert((yyvsp[-2].chaine),current_type,current_entity);}

if(strcmp(tableau_type->ptr,current_type) != 0){printf("\033[31m Error \033[0m type non compatible!!last type was %s while idf type is %s\n",tableau_type->ptr,current_type);}

tableau_type = NULL;
}
#line 1461 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 105 "synt.y" /* yacc.c:1646  */
    {if(atoi((yyvsp[0].chaine))<-32768 & atoi((yyvsp[0].chaine))> 32767){printf("\033[31m Error \033[0m integer either bigger than 32767 or lower than (-32768)\n");affich();YYACCEPT;}

tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"INT"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
strcpy(tmp_value,(yyvsp[0].chaine));

}
#line 1472 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 112 "synt.y" /* yacc.c:1646  */
    {if(division && (atoi((yyvsp[0].chaine)) == 0)){printf("\033[31m Error \033[0m devision per 0\n");affich();YYACCEPT;}
tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"FLOAT"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
strcpy(tmp_value,(yyvsp[0].chaine));
}
#line 1481 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 117 "synt.y" /* yacc.c:1646  */
    {tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"CHAR"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
strcpy(tmp_value,(yyvsp[0].chaine));
}
#line 1489 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 121 "synt.y" /* yacc.c:1646  */
    {tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"STRING"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
strcpy(tmp_value,(yyvsp[-1].chaine));
}
#line 1497 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 126 "synt.y" /* yacc.c:1646  */
    {
	if(recherche_syn((yyvsp[0].chaine))){printf("\033[31m Error \033[0m double declaration for %s\n",(yyvsp[0].chaine));affich();YYACCEPT;}
	else{insert((yyvsp[0].chaine),current_type,current_entity);}}
#line 1505 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 131 "synt.y" /* yacc.c:1646  */
    {
	if(!arrays){printf("\033[31m Error \033[0m library arrays wasn't included\n");affich();YYACCEPT;}
	
	if(atoi((yyvsp[-1].chaine))<0){printf("\033[31m Error \033[0m Can't have a negative interger as index for an array\n");affich();YYACCEPT;}

	if(recherche_syn((yyvsp[-3].chaine))){printf("\033[31m Error \033[0m double declaration for %s\n",(yyvsp[-3].chaine));affich();YYACCEPT;}
	else{insert_tab((yyvsp[-3].chaine),current_type,"TAB",atoi((yyvsp[-1].chaine)));}

	
}
#line 1520 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 144 "synt.y" /* yacc.c:1646  */
    {
	if(!recherche_syn((yyvsp[-5].chaine))){printf("\033[31m Error \033[0m not declared %s\n",(yyvsp[-5].chaine));affich();YYACCEPT;}  
	if(strcmp(tableau_type->ptr,recherche_type((yyvsp[-5].chaine))) != 0)
	{printf("\033[31m Error \033[0m type non compatible!!last type was %s while idf type is %s\n",tableau_type->ptr,recherche_type((yyvsp[-5].chaine)));affich();YYACCEPT;}

	tableau_type = NULL;
	if(atoi((yyvsp[-3].chaine))<0){printf("\033[31m Error \033[0m Can't have a negative interger as index for an array\n");affich();YYACCEPT;}

	if(atoi((yyvsp[-3].chaine)) > recherche_max_index((yyvsp[-5].chaine))) {printf("\033[31m Error \033[0m index > max_index for this array\n");affich();YYACCEPT;}
	

}
#line 1537 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 157 "synt.y" /* yacc.c:1646  */
    {if(!recherche_syn((yyvsp[-2].chaine))){printf("\033[31m Error \033[0m not declared %s\n",(yyvsp[-2].chaine));affich();YYACCEPT;}  
if(strcmp(tableau_type->ptr,recherche_type((yyvsp[-2].chaine))) != 0){printf("\033[31m Error \033[0mtype non compatible!!last type was %s while idf type is %s\n",tableau_type->ptr,recherche_type((yyvsp[-2].chaine)));affich();YYACCEPT;}
tableau_type = NULL;
}
#line 1546 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 164 "synt.y" /* yacc.c:1646  */
    {strcpy(tmp_type,tableau_type->ptr); tableau_type = tableau_type->next; 
if(strcmp(tableau_type->ptr,tmp_type) != 0){printf("type non compatible!!first type was %s while second type is %s\n",tmp_type,tableau_type->ptr);affich();YYACCEPT;}

 }
#line 1555 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 170 "synt.y" /* yacc.c:1646  */
    {if(!process){printf("\033[31m Error \033[0m library process for arithmetique operation wasn't included\n");affich();YYACCEPT;}  division = false;}
#line 1561 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 172 "synt.y" /* yacc.c:1646  */
    {
	if(!process){printf("\033[31m Error \033[0m library process for arithmetique operation wasn't included\n");affich();YYACCEPT;}
	if((yyvsp[0].chaine)[0]== '/'){division = true;}else{division = false;}
}
#line 1570 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 177 "synt.y" /* yacc.c:1646  */
    {tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"STRING"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;}
#line 1576 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 179 "synt.y" /* yacc.c:1646  */
    {if(atoi((yyvsp[0].chaine))<-32768 & atoi((yyvsp[0].chaine))> 32767){printf("\033[31m Error \033[0m integer either bigger than 32767 or lower than (-32768)\n");affich();YYACCEPT;}

	if(division && (atoi((yyvsp[0].chaine)) == 0)){printf("\033[31m Error \033[0m devision per 0\n");affich();YYACCEPT;}

tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"INT"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;}
#line 1586 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 185 "synt.y" /* yacc.c:1646  */
    {if(division && (atoi((yyvsp[0].chaine)) == 0)){printf("\033[31m Error \033[0m devision per 0\n");affich();YYACCEPT;}

tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"FLOAT"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;}
#line 1594 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 189 "synt.y" /* yacc.c:1646  */
    {tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"CHAR"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;}
#line 1600 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 191 "synt.y" /* yacc.c:1646  */
    {
	
	if(!recherche_syn((yyvsp[-3].chaine))){printf("\033[31m Error \033[0m not declared %s",(yyvsp[-3].chaine));affich();YYACCEPT;}
	if(atoi((yyvsp[-1].chaine))<0){printf("\033[31m Error \033[0m Can't have a negative interger as index for an array\n");affich();YYACCEPT;}
	tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,recherche_type((yyvsp[-3].chaine))); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
	if(atoi((yyvsp[-1].chaine)) > recherche_max_index((yyvsp[-3].chaine))) {printf("\033[31m Error \033[0m index > max_index for this array\n");affich();YYACCEPT;}

}
#line 1613 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 200 "synt.y" /* yacc.c:1646  */
    { 
	if(!recherche_syn((yyvsp[0].chaine))){printf("not declared %s",(yyvsp[0].chaine));affich();YYACCEPT;}
	tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,recherche_type((yyvsp[0].chaine))); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;}
#line 1621 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 207 "synt.y" /* yacc.c:1646  */
    {
	switch((yyvsp[-6].chaine)[0])
	{
		case ';':
		strcpy(tmp_type,"INT");
		break;
		case '%':
		strcpy(tmp_type,"FLOAT");
		break;
		case '?':
		strcpy(tmp_type,"STRING");
		break;
		case '&':
		strcpy(tmp_type,"CHAR");
		break;

		default:
		printf("Erreur signe formatage non reconnue\n");YYACCEPT;
		break;
	}
	if(!recherche_syn((yyvsp[-2].chaine)))  {printf("not declared %s",(yyvsp[-2].chaine));affich();YYACCEPT;}  

	if(strcmp(tmp_type,recherche_type((yyvsp[-2].chaine))) != 0)   {printf("type non compatible!! signe type is %s while idf type is %s\n",tmp_type,recherche_type((yyvsp[-2].chaine)));affich();YYACCEPT;}
	
	
}
#line 1652 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 236 "synt.y" /* yacc.c:1646  */
    { if(num != 0){printf("error signe de formatage is not equale to idf %d\n",num);}}
#line 1658 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 239 "synt.y" /* yacc.c:1646  */
    {
	if(!recherche_syn((yyvsp[0].chaine)))  {printf("not declared %s",(yyvsp[0].chaine));affich();YYACCEPT;} 
	if(strcmp(tableau_type->ptr,recherche_type((yyvsp[0].chaine))) != 0)   {printf("type non compatible!! signe type is %s while idf %s type is %s\n",tableau_type->ptr,(yyvsp[0].chaine),recherche_type((yyvsp[0].chaine)));affich();YYACCEPT;}
	tableau_type = tableau_type->next;
}
#line 1668 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 246 "synt.y" /* yacc.c:1646  */
    {
	if(!recherche_syn((yyvsp[-2].chaine)))  {printf("not declared %s",(yyvsp[-2].chaine));affich();YYACCEPT;} 
	if(strcmp(tableau_type->ptr,recherche_type((yyvsp[-2].chaine))) != 0)   {printf("type non compatible!! signe type is %s while idf %s type is %s\n",tableau_type->ptr,(yyvsp[-2].chaine),recherche_type((yyvsp[-2].chaine)));affich();YYACCEPT;}
	tableau_type = tableau_type->next;
}
#line 1678 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 260 "synt.y" /* yacc.c:1646  */
    {
	switch((yyvsp[0].chaine)[0])
	{
		case ';':
		tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"INT"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
		break;
		case '%':
		tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"FLOAT"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
		break;
		case '?':
		tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"STRING"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
		break;
		case '&':
		tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"CHAR"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
		break;

		default:
		printf("Erreur signe formatage non reconnue\n");YYACCEPT;
		break;
	}
	

}
#line 1706 "synt.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 285 "synt.y" /* yacc.c:1646  */
    {if(!loops){printf("\033[31m Error \033[0m library loop wasn't included\n");affich();YYACCEPT;} }
#line 1712 "synt.tab.c" /* yacc.c:1646  */
    break;


#line 1716 "synt.tab.c" /* yacc.c:1646  */
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
#line 300 "synt.y" /* yacc.c:1906  */


int yyerror(char *msg)
{

printf("%s syntaxic error line %d cologne %d\n",msg,line,count);

return 1;
}


int main(int argc , char **argv)
{	
	if(argc != 2)
	{
		printf("Error need missing file argument");
	}
	else
	{
		yyin = fopen(argv[1],"r");
		yyparse();
	}
	//printf("Count = %d \n",count);
	
}

int yywrap(void)
{
}
