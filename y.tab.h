/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 66 "sintactico.y"
{
    char nombreId[100];
    int tipo;
}
/* Line 1529 of yacc.c.  */
#line 140 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

