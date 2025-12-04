/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     NUM = 259,
     REAL = 260,
     CADENA = 261,
     BOOL = 262,
     INTEGER = 263,
     REAL_TIPO = 264,
     STRING = 265,
     BOOLEAN = 266,
     PROGRAM = 267,
     CONST = 268,
     VAR = 269,
     BEGGIN = 270,
     ENDD = 271,
     ASIGNACION = 272,
     WRITELN = 273,
     READLN = 274,
     IF = 275,
     ELSE = 276,
     FOR = 277,
     WHILE = 278,
     DO = 279,
     THEN = 280,
     TO = 281,
     DOWNTO = 282,
     MAS = 283,
     MENOS = 284,
     POR = 285,
     POTENCIA = 286,
     DIV = 287,
     MOD = 288,
     AND = 289,
     OR = 290,
     NOT = 291,
     MENOR = 292,
     MAYOR = 293,
     MENORIGUAL = 294,
     MAYORIGUAL = 295,
     IGUAL = 296,
     ENTRE = 297,
     AMPERSAND = 298
   };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define REAL 260
#define CADENA 261
#define BOOL 262
#define INTEGER 263
#define REAL_TIPO 264
#define STRING 265
#define BOOLEAN 266
#define PROGRAM 267
#define CONST 268
#define VAR 269
#define BEGGIN 270
#define ENDD 271
#define ASIGNACION 272
#define WRITELN 273
#define READLN 274
#define IF 275
#define ELSE 276
#define FOR 277
#define WHILE 278
#define DO 279
#define THEN 280
#define TO 281
#define DOWNTO 282
#define MAS 283
#define MENOS 284
#define POR 285
#define POTENCIA 286
#define DIV 287
#define MOD 288
#define AND 289
#define OR 290
#define NOT 291
#define MENOR 292
#define MAYOR 293
#define MENORIGUAL 294
#define MAYORIGUAL 295
#define IGUAL 296
#define ENTRE 297
#define AMPERSAND 298




/* Copy the first part of user declarations.  */
#line 1 "sintactico.y"

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

extern int nLineas;
int yylex(void);
FILE *yyin;
int erroresSemanticos = 0;

#define T_INTEGER 1
#define T_REAL    2
#define T_STRING  3
#define T_BOOLEAN 4

struct simbolo {
    char nombre[100];
    int tipo;
    int esConstante;
    int inicializado;
};

struct simbolo tablaSimbolos[200];
int numSimbolos = 0;

void yyerror(const char* msg) {
    fprintf(stderr, "Error sintactico en linea %d: %s\n", nLineas, msg);
}

void errorSemantico(const char* msg) {
    fprintf(stderr, "Error semantico en linea %d: %s\n", nLineas, msg);
    erroresSemanticos++;
}

int buscarSimbolo(char* nombre) {
    for(int i = 0; i < numSimbolos; i++) {
        if(strcmp(tablaSimbolos[i].nombre, nombre) == 0) {
            return i;
        }
    }
    return -1;
}

void insertarSimbolo(char* nombre, int tipo, int esConstante, int inicializado) {
    if(buscarSimbolo(nombre) != -1) {
        char buffer[200];
        sprintf(buffer, "Identificador '%s' ya declarado previamente", nombre);
        errorSemantico(buffer);
    } else {
        strcpy(tablaSimbolos[numSimbolos].nombre, nombre);
        tablaSimbolos[numSimbolos].tipo = tipo;
        tablaSimbolos[numSimbolos].esConstante = esConstante;
        tablaSimbolos[numSimbolos].inicializado = inicializado;
        numSimbolos++;
    }
}

void comprobarTipos(int tipo1, int tipo2) {
    if(tipo1 != tipo2) {
        errorSemantico("Tipos incompatibles en la operacion o asignacion");
    }
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 67 "sintactico.y"
{
    char nombreId[100];
    int tipo;
}
/* Line 193 of yacc.c.  */
#line 253 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 266 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   184

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      47,    48,     2,     2,     2,     2,    44,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    45,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    13,    14,    17,    19,    22,    27,
      32,    37,    42,    45,    46,    49,    51,    54,    59,    62,
      64,    66,    68,    70,    74,    75,    77,    79,    82,    85,
      87,    90,    92,    94,    96,    98,   101,   107,   109,   111,
     115,   120,   126,   128,   130,   132,   136,   140,   143,   145,
     149,   153,   157,   161,   163,   165,   167,   169,   173,   175,
     179,   183,   187,   189,   193,   196,   204,   216,   224,   236,
     248,   250,   252,   254,   256,   258
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    52,    55,    59,    44,    -1,    12,
       3,    45,    -1,    -1,    13,    53,    -1,    54,    -1,    54,
      53,    -1,     3,    41,     4,    45,    -1,     3,    41,     5,
      45,    -1,     3,    41,     6,    45,    -1,     3,    41,     7,
      45,    -1,     1,    45,    -1,    -1,    14,    56,    -1,    57,
      -1,    57,    56,    -1,     3,    46,    58,    45,    -1,     1,
      45,    -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,
      15,    60,    16,    -1,    -1,    61,    -1,    62,    -1,    61,
      62,    -1,    65,    45,    -1,    63,    -1,    66,    45,    -1,
      73,    -1,    74,    -1,    75,    -1,    45,    -1,     1,    45,
      -1,    18,    47,    64,    48,    45,    -1,     6,    -1,     3,
      -1,     3,    17,    67,    -1,    19,    47,     3,    48,    -1,
      19,    47,    43,     3,    48,    -1,    68,    -1,    71,    -1,
      69,    -1,    68,    28,    69,    -1,    68,    29,    69,    -1,
      29,    69,    -1,    70,    -1,    69,    30,    70,    -1,    69,
      32,    70,    -1,    69,    33,    70,    -1,    69,    31,    70,
      -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,    47,
      68,    48,    -1,    72,    -1,    71,    34,    72,    -1,    71,
      35,    72,    -1,    68,    76,    68,    -1,     7,    -1,    47,
      71,    48,    -1,    36,    72,    -1,    20,    47,    71,    48,
      15,    60,    16,    -1,    20,    47,    71,    48,    15,    60,
      16,    21,    15,    60,    16,    -1,    23,    47,    71,    48,
      15,    60,    16,    -1,    22,    47,     3,    17,    68,    26,
      68,    48,    15,    60,    16,    -1,    22,    47,     3,    17,
      68,    27,    68,    48,    15,    60,    16,    -1,    37,    -1,
      38,    -1,    39,    -1,    40,    -1,    41,    -1,    42,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,   100,   103,   105,   109,   111,   115,   117,
     119,   121,   123,   126,   128,   132,   134,   138,   143,   147,
     149,   151,   153,   157,   160,   162,   166,   168,   172,   174,
     176,   178,   180,   182,   184,   186,   190,   195,   197,   215,
     234,   246,   255,   257,   261,   263,   265,   267,   271,   273,
     275,   277,   283,   287,   303,   305,   307,   309,   313,   315,
     317,   321,   327,   329,   331,   335,   337,   341,   345,   363,
     373,   373,   373,   373,   373,   373
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "REAL", "CADENA", "BOOL",
  "INTEGER", "REAL_TIPO", "STRING", "BOOLEAN", "PROGRAM", "CONST", "VAR",
  "BEGGIN", "ENDD", "ASIGNACION", "WRITELN", "READLN", "IF", "ELSE", "FOR",
  "WHILE", "DO", "THEN", "TO", "DOWNTO", "MAS", "MENOS", "POR", "POTENCIA",
  "DIV", "MOD", "AND", "OR", "NOT", "MENOR", "MAYOR", "MENORIGUAL",
  "MAYORIGUAL", "IGUAL", "ENTRE", "AMPERSAND", "'.'", "';'", "':'", "'('",
  "')'", "$accept", "programa", "cabecera", "seccionDeclaracionCtes",
  "declaracionCtes", "declaracionCte", "seccionDeclaracionVars",
  "declaracionVars", "declaracionVar", "tipo", "cuerpo", "instrucciones",
  "lista_instrucciones", "instruccion", "visualizacion", "parametro_write",
  "asignacion", "lectura", "expresion", "expr_aritmetica", "termino",
  "factor", "expr_booleana", "expr_bool_simple", "if", "while", "for",
  "comparador", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    46,    59,    58,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    52,    52,    53,    53,    54,    54,
      54,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    58,    58,    59,    60,    60,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    64,    64,    65,
      66,    66,    67,    67,    68,    68,    68,    68,    69,    69,
      69,    69,    69,    70,    70,    70,    70,    70,    71,    71,
      71,    72,    72,    72,    72,    73,    73,    74,    75,    75,
      76,    76,    76,    76,    76,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     0,     2,     1,     2,     4,     4,
       4,     4,     2,     0,     2,     1,     2,     4,     2,     1,
       1,     1,     1,     3,     0,     1,     1,     2,     2,     1,
       2,     1,     1,     1,     1,     2,     5,     1,     1,     3,
       4,     5,     1,     1,     1,     3,     3,     2,     1,     3,
       3,     3,     3,     1,     1,     1,     1,     3,     1,     3,
       3,     3,     1,     3,     2,     7,    11,     7,    11,    11,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     0,     1,     0,    13,     3,     0,
       0,     5,     0,     0,     0,    12,     0,     7,     0,     0,
      14,     0,     0,     0,     0,     0,     0,     0,    18,     0,
      16,     0,     0,     0,     0,     0,     0,     0,    34,     0,
       0,    26,    29,     0,     0,    31,    32,    33,     2,     8,
       9,    10,    11,    19,    20,    21,    22,     0,    35,     0,
       0,     0,     0,     0,     0,    23,    27,    28,    30,    17,
      53,    54,    55,    56,    62,     0,     0,     0,    39,    42,
      44,    48,    43,    58,    38,    37,     0,     0,     0,     0,
       0,     0,     0,     0,    47,    64,     0,     0,     0,     0,
      70,    71,    72,    73,    74,    75,     0,     0,     0,     0,
       0,     0,     0,     0,    40,     0,     0,     0,     0,     0,
      57,    63,    45,    46,    61,    49,    52,    50,    51,    59,
      60,    36,    41,     0,     0,     0,     0,     0,     0,     0,
      65,     0,     0,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    68,    69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     7,    11,    12,    14,    20,    21,    57,
      23,    39,    40,    41,    42,    86,    43,    44,    78,    89,
      80,    81,    82,    83,    45,    46,    47,   106
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -60
static const yytype_int16 yypact[] =
{
      -3,    19,    26,    32,     7,   -60,     0,    73,   -60,    16,
      48,   -60,    94,    47,    77,   -60,   115,   -60,    51,    80,
     -60,   109,     1,    67,    78,   103,   104,   105,   -60,   124,
     -60,   107,   108,   110,   111,   112,   113,   116,   -60,   135,
       9,   -60,   -60,   117,   119,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,   120,   -60,    33,
      85,     8,    33,   125,    33,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,     2,    33,    33,   -60,    65,
     106,   -60,   -21,   -60,   -60,   -60,    82,   118,   150,    65,
      79,   137,    81,    38,   106,   -60,    35,    83,     2,     2,
     -60,   -60,   -60,   -60,   -60,   -60,    38,     2,     2,     2,
       2,    33,    33,   122,   -60,   121,   140,    38,   141,   -13,
     -60,   -60,   106,   106,    31,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,     1,   114,     1,   145,    38,    38,   152,
     149,    42,    53,   -60,   156,   157,   158,     1,     1,     1,
     159,   160,   161,   -60,   -60,   -60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -60,   -60,   -60,   -60,   162,   -60,   -60,   163,   -60,   -60,
     -60,   -49,   -60,   138,   -60,   -60,   -60,   -60,   -60,   -59,
     -42,    37,    -9,   -46,   -60,   -60,   -60,   -60
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -26
static const yytype_int16 yytable[] =
{
      79,     9,    31,    10,    32,    70,    71,    72,    73,     1,
      31,    87,    32,   111,   112,    98,    99,   -24,    96,    33,
      34,    35,     4,    36,    37,   -25,     5,    33,    34,    35,
      95,    36,    37,    94,   119,   120,    70,    71,    72,    73,
      74,    70,    71,    72,    73,     6,    38,   124,    18,    93,
      19,    88,     8,    90,    38,    92,   122,   123,   134,    98,
      99,    15,    75,    98,    99,   129,   130,    75,    97,    76,
      98,    99,   100,   101,   102,   103,   104,   105,   141,   142,
      77,    98,    99,   120,   136,    93,   139,    13,    84,    16,
     145,    85,    22,    98,    99,     9,    28,    10,   150,   151,
     152,   146,   100,   101,   102,   103,   104,   105,    -6,    -6,
      18,    48,    19,   111,   112,   111,   112,   111,   112,    24,
      25,    26,    27,    49,   -15,    59,    29,   116,    91,   118,
     113,   121,    53,    54,    55,    56,   107,   108,   109,   110,
     137,   138,    98,    99,   125,   126,   127,   128,    50,    51,
      52,    65,    58,   115,   117,   133,   135,    60,    61,    62,
      63,   140,    67,    64,    68,    69,   114,   131,   143,   132,
     144,   147,   148,   149,    17,   153,   154,   155,    66,     0,
       0,     0,     0,     0,    30
};

static const yytype_int16 yycheck[] =
{
      59,     1,     1,     3,     3,     3,     4,     5,     6,    12,
       1,     3,     3,    34,    35,    28,    29,    16,    77,    18,
      19,    20,     3,    22,    23,    16,     0,    18,    19,    20,
      76,    22,    23,    75,    93,    48,     3,     4,     5,     6,
       7,     3,     4,     5,     6,    13,    45,   106,     1,    47,
       3,    43,    45,    62,    45,    64,    98,    99,   117,    28,
      29,    45,    29,    28,    29,   111,   112,    29,    77,    36,
      28,    29,    37,    38,    39,    40,    41,    42,   137,   138,
      47,    28,    29,    48,   133,    47,   135,    14,     3,    41,
      48,     6,    15,    28,    29,     1,    45,     3,   147,   148,
     149,    48,    37,    38,    39,    40,    41,    42,    14,    15,
       1,    44,     3,    34,    35,    34,    35,    34,    35,     4,
       5,     6,     7,    45,    15,    17,    46,    48,     3,    48,
      48,    48,     8,     9,    10,    11,    30,    31,    32,    33,
      26,    27,    28,    29,   107,   108,   109,   110,    45,    45,
      45,    16,    45,     3,    17,    15,    15,    47,    47,    47,
      47,    16,    45,    47,    45,    45,    48,    45,    16,    48,
      21,    15,    15,    15,    12,    16,    16,    16,    40,    -1,
      -1,    -1,    -1,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    50,    51,     3,     0,    13,    52,    45,     1,
       3,    53,    54,    14,    55,    45,    41,    53,     1,     3,
      56,    57,    15,    59,     4,     5,     6,     7,    45,    46,
      56,     1,     3,    18,    19,    20,    22,    23,    45,    60,
      61,    62,    63,    65,    66,    73,    74,    75,    44,    45,
      45,    45,    45,     8,     9,    10,    11,    58,    45,    17,
      47,    47,    47,    47,    47,    16,    62,    45,    45,    45,
       3,     4,     5,     6,     7,    29,    36,    47,    67,    68,
      69,    70,    71,    72,     3,     6,    64,     3,    43,    68,
      71,     3,    71,    47,    69,    72,    68,    71,    28,    29,
      37,    38,    39,    40,    41,    42,    76,    30,    31,    32,
      33,    34,    35,    48,    48,     3,    48,    17,    48,    68,
      48,    48,    69,    69,    68,    70,    70,    70,    70,    72,
      72,    45,    48,    15,    68,    15,    60,    26,    27,    60,
      16,    68,    68,    16,    21,    48,    48,    15,    15,    15,
      60,    60,    60,    16,    16,    16
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 91 "sintactico.y"
    {
                if(erroresSemanticos == 0)
                    printf("\n--- COMPILACION EXITOSA: Sin errores sintacticos ni semanticos. Lineas: %d ---\n", nLineas);
                else
                    printf("\n--- FALLO: Se encontraron %d errores semanticos. ---\n", erroresSemanticos);
            }
    break;

  case 8:
#line 115 "sintactico.y"
    { insertarSimbolo((yyvsp[(1) - (4)].nombreId), T_INTEGER, 1, 1); }
    break;

  case 9:
#line 117 "sintactico.y"
    { insertarSimbolo((yyvsp[(1) - (4)].nombreId), T_REAL, 1, 1); }
    break;

  case 10:
#line 119 "sintactico.y"
    { insertarSimbolo((yyvsp[(1) - (4)].nombreId), T_STRING, 1, 1); }
    break;

  case 11:
#line 121 "sintactico.y"
    { insertarSimbolo((yyvsp[(1) - (4)].nombreId), T_BOOLEAN, 1, 1); }
    break;

  case 12:
#line 123 "sintactico.y"
    { yyerrok; yyclearin; }
    break;

  case 17:
#line 139 "sintactico.y"
    {
                insertarSimbolo((yyvsp[(1) - (4)].nombreId), (yyvsp[(3) - (4)].tipo), 0, 0);
            }
    break;

  case 18:
#line 143 "sintactico.y"
    { yyerrok; yyclearin; }
    break;

  case 19:
#line 147 "sintactico.y"
    { (yyval.tipo) = T_INTEGER; }
    break;

  case 20:
#line 149 "sintactico.y"
    { (yyval.tipo) = T_REAL; }
    break;

  case 21:
#line 151 "sintactico.y"
    { (yyval.tipo) = T_STRING; }
    break;

  case 22:
#line 153 "sintactico.y"
    { (yyval.tipo) = T_BOOLEAN; }
    break;

  case 35:
#line 186 "sintactico.y"
    { yyerrok; yyclearin; }
    break;

  case 36:
#line 191 "sintactico.y"
    { }
    break;

  case 37:
#line 195 "sintactico.y"
    { (yyval.tipo) = T_STRING; }
    break;

  case 38:
#line 198 "sintactico.y"
    {
                int idx = buscarSimbolo((yyvsp[(1) - (1)].nombreId));
                if(idx == -1) {
                    char buf[100]; sprintf(buf, "Variable '%s' no declarada", (yyvsp[(1) - (1)].nombreId));
                    errorSemantico(buf);
                    (yyval.tipo) = 0;
                } else {
                    if(tablaSimbolos[idx].inicializado == 0) {
                        char buf[100]; sprintf(buf, "Variable '%s' usada sin inicializar", (yyvsp[(1) - (1)].nombreId));
                        errorSemantico(buf);
                    }
                    (yyval.tipo) = tablaSimbolos[idx].tipo;
                }
            }
    break;

  case 39:
#line 216 "sintactico.y"
    {
                int idx = buscarSimbolo((yyvsp[(1) - (3)].nombreId));
                if(idx == -1) {
                    char buf[100]; sprintf(buf, "Variable '%s' no declarada", (yyvsp[(1) - (3)].nombreId));
                    errorSemantico(buf);
                } else {
                    if(tablaSimbolos[idx].esConstante) {
                        char buf[100]; sprintf(buf, "No se puede modificar la constante '%s'", (yyvsp[(1) - (3)].nombreId));
                        errorSemantico(buf);
                    } else {
                        comprobarTipos(tablaSimbolos[idx].tipo, (yyvsp[(3) - (3)].tipo));
                        tablaSimbolos[idx].inicializado = 1;
                    }
                }
            }
    break;

  case 40:
#line 235 "sintactico.y"
    {
                 int idx = buscarSimbolo((yyvsp[(3) - (4)].nombreId));
                 if(idx == -1) {
                    errorSemantico("Variable no declarada en readln");
                 } else if(tablaSimbolos[idx].esConstante) {
                    errorSemantico("No se puede leer/modificar una constante");
                 } else {
                    tablaSimbolos[idx].inicializado = 1;
                 }
            }
    break;

  case 41:
#line 247 "sintactico.y"
    {
                 int idx = buscarSimbolo((yyvsp[(4) - (5)].nombreId));
                 if(idx == -1) errorSemantico("Variable no declarada en readln");
                 else { tablaSimbolos[idx].inicializado = 1; }
            }
    break;

  case 42:
#line 255 "sintactico.y"
    { (yyval.tipo) = (yyvsp[(1) - (1)].tipo); }
    break;

  case 43:
#line 257 "sintactico.y"
    { (yyval.tipo) = (yyvsp[(1) - (1)].tipo); }
    break;

  case 44:
#line 261 "sintactico.y"
    { (yyval.tipo) = (yyvsp[(1) - (1)].tipo); }
    break;

  case 45:
#line 263 "sintactico.y"
    { comprobarTipos((yyvsp[(1) - (3)].tipo), (yyvsp[(3) - (3)].tipo)); (yyval.tipo) = (yyvsp[(1) - (3)].tipo); }
    break;

  case 46:
#line 265 "sintactico.y"
    { comprobarTipos((yyvsp[(1) - (3)].tipo), (yyvsp[(3) - (3)].tipo)); (yyval.tipo) = (yyvsp[(1) - (3)].tipo); }
    break;

  case 47:
#line 267 "sintactico.y"
    { (yyval.tipo) = (yyvsp[(2) - (2)].tipo); }
    break;

  case 48:
#line 271 "sintactico.y"
    { (yyval.tipo) = (yyvsp[(1) - (1)].tipo); }
    break;

  case 49:
#line 273 "sintactico.y"
    { comprobarTipos((yyvsp[(1) - (3)].tipo), (yyvsp[(3) - (3)].tipo)); (yyval.tipo) = (yyvsp[(1) - (3)].tipo); }
    break;

  case 50:
#line 275 "sintactico.y"
    { comprobarTipos((yyvsp[(1) - (3)].tipo), (yyvsp[(3) - (3)].tipo)); (yyval.tipo) = (yyvsp[(1) - (3)].tipo); }
    break;

  case 51:
#line 278 "sintactico.y"
    {
                if((yyvsp[(1) - (3)].tipo) != T_INTEGER || (yyvsp[(3) - (3)].tipo) != T_INTEGER) errorSemantico("MOD requiere enteros");
                (yyval.tipo) = T_INTEGER;
            }
    break;

  case 52:
#line 283 "sintactico.y"
    { comprobarTipos((yyvsp[(1) - (3)].tipo), (yyvsp[(3) - (3)].tipo)); (yyval.tipo) = (yyvsp[(1) - (3)].tipo); }
    break;

  case 53:
#line 288 "sintactico.y"
    {
                int idx = buscarSimbolo((yyvsp[(1) - (1)].nombreId));
                if(idx == -1) {
                    char buf[100]; sprintf(buf, "Variable '%s' no declarada", (yyvsp[(1) - (1)].nombreId));
                    errorSemantico(buf);
                    (yyval.tipo) = T_INTEGER;
                } else {
                    if(tablaSimbolos[idx].inicializado == 0) {
                        char buf[100]; sprintf(buf, "Variable '%s' usada sin inicializar", (yyvsp[(1) - (1)].nombreId));
                        errorSemantico(buf);
                    }
                    (yyval.tipo) = tablaSimbolos[idx].tipo;
                }
            }
    break;

  case 54:
#line 303 "sintactico.y"
    { (yyval.tipo) = T_INTEGER; }
    break;

  case 55:
#line 305 "sintactico.y"
    { (yyval.tipo) = T_REAL; }
    break;

  case 56:
#line 307 "sintactico.y"
    { (yyval.tipo) = T_STRING; }
    break;

  case 57:
#line 309 "sintactico.y"
    { (yyval.tipo) = (yyvsp[(2) - (3)].tipo); }
    break;

  case 58:
#line 313 "sintactico.y"
    { (yyval.tipo) = (yyvsp[(1) - (1)].tipo); }
    break;

  case 59:
#line 315 "sintactico.y"
    { (yyval.tipo) = T_BOOLEAN; }
    break;

  case 60:
#line 317 "sintactico.y"
    { (yyval.tipo) = T_BOOLEAN; }
    break;

  case 61:
#line 322 "sintactico.y"
    {
                if((yyvsp[(1) - (3)].tipo) != (yyvsp[(3) - (3)].tipo)) errorSemantico("Comparacion de tipos incompatibles");
                (yyval.tipo) = T_BOOLEAN;
            }
    break;

  case 62:
#line 327 "sintactico.y"
    { (yyval.tipo) = T_BOOLEAN; }
    break;

  case 63:
#line 329 "sintactico.y"
    { (yyval.tipo) = (yyvsp[(2) - (3)].tipo); }
    break;

  case 64:
#line 331 "sintactico.y"
    { (yyval.tipo) = T_BOOLEAN; }
    break;

  case 68:
#line 346 "sintactico.y"
    {
                int idx = buscarSimbolo((yyvsp[(3) - (11)].nombreId));
                if(idx == -1) {
                    errorSemantico("Variable del bucle FOR no declarada");
                } else {
                    if(tablaSimbolos[idx].tipo != T_INTEGER) {
                        errorSemantico("La variable del bucle FOR debe ser INTEGER");
                    }
                
                    tablaSimbolos[idx].inicializado = 1;
                    
                    if((yyvsp[(5) - (11)].tipo) != T_INTEGER || (yyvsp[(7) - (11)].tipo) != T_INTEGER) {
                        errorSemantico("Los limites del bucle FOR deben ser enteros");
                    }
                }
            }
    break;

  case 69:
#line 364 "sintactico.y"
    {
                int idx = buscarSimbolo((yyvsp[(3) - (11)].nombreId));
                if(idx != -1 && tablaSimbolos[idx].tipo != T_INTEGER)
                     errorSemantico("Variable FOR debe ser entera");
            }
    break;


/* Line 1267 of yacc.c.  */
#line 1907 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 376 "sintactico.y"


int main()
{
    yyin = fopen("pruebaErrores.pas","r");
    if(!yyin){
        printf("\nError de apertura de pruebaErrores.pas\n");
        return -1;
    }
    yyparse();
    return 0;
}

