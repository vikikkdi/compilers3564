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
     TYPE = 258,
     ID = 259,
     VAL = 260,
     AND = 261,
     OR = 262,
     NOT = 263,
     LT = 264,
     GT = 265,
     EQQ = 266,
     LTE = 267,
     GTE = 268,
     PL = 269,
     MI = 270,
     MUL = 271,
     DIV = 272,
     OP = 273,
     CL = 274,
     OCB = 275,
     CCB = 276,
     OSB = 277,
     CSB = 278,
     EQ = 279,
     COMMA = 280,
     SEMICOLON = 281,
     IF = 282,
     ELSE = 283,
     WHILE = 284,
     TRUE = 285,
     FALSE = 286,
     NTE = 287
   };
#endif
/* Tokens.  */
#define TYPE 258
#define ID 259
#define VAL 260
#define AND 261
#define OR 262
#define NOT 263
#define LT 264
#define GT 265
#define EQQ 266
#define LTE 267
#define GTE 268
#define PL 269
#define MI 270
#define MUL 271
#define DIV 272
#define OP 273
#define CL 274
#define OCB 275
#define CCB 276
#define OSB 277
#define CSB 278
#define EQ 279
#define COMMA 280
#define SEMICOLON 281
#define IF 282
#define ELSE 283
#define WHILE 284
#define TRUE 285
#define FALSE 286
#define NTE 287




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 504 "three.y"
{
	char * str;
	struct Node * nn;
	struct NodeDec * nd;
}
/* Line 1529 of yacc.c.  */
#line 119 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

