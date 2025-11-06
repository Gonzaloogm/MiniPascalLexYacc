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
     PROGRAM = 259,
     CONST = 260,
     VAR = 261,
     NUM = 262,
     REAL = 263,
     CADENA = 264,
     BOOL = 265,
     INTEGER = 266,
     REAL_TIPO = 267,
     STRING = 268,
     BOOLEAN = 269,
     BEGGIN = 270,
     ENDD = 271,
     ASIGNACION = 272,
     WRITELN = 273,
     READLN = 274,
     IF = 275,
     ELSE = 276,
     FOR = 277,
     WHILE = 278,
     THEN = 279,
     TO = 280,
     DOWNTO = 281,
     MAS = 282,
     MENOS = 283,
     POR = 284,
     POTENCIA = 285,
     DIV = 286,
     MOD = 287,
     AND = 288,
     OR = 289,
     NOT = 290,
     MENOR = 291,
     MAYOR = 292,
     MENORIGUAL = 293,
     MAYORIGUAL = 294,
     IGUAL = 295,
     ENTRE = 296,
     AMPERSAND = 297
   };
#endif
/* Tokens.  */
#define ID 258
#define PROGRAM 259
#define CONST 260
#define VAR 261
#define NUM 262
#define REAL 263
#define CADENA 264
#define BOOL 265
#define INTEGER 266
#define REAL_TIPO 267
#define STRING 268
#define BOOLEAN 269
#define BEGGIN 270
#define ENDD 271
#define ASIGNACION 272
#define WRITELN 273
#define READLN 274
#define IF 275
#define ELSE 276
#define FOR 277
#define WHILE 278
#define THEN 279
#define TO 280
#define DOWNTO 281
#define MAS 282
#define MENOS 283
#define POR 284
#define POTENCIA 285
#define DIV 286
#define MOD 287
#define AND 288
#define OR 289
#define NOT 290
#define MENOR 291
#define MAYOR 292
#define MENORIGUAL 293
#define MAYORIGUAL 294
#define IGUAL 295
#define ENTRE 296
#define AMPERSAND 297




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

