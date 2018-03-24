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
     VAL = 259,
     PL = 260,
     MI = 261,
     MUL = 262,
     DIV = 263,
     POW = 264,
     EQ = 265,
     OP = 266,
     CL = 267,
     OSB = 268,
     CSB = 269,
     AND = 270,
     OR = 271,
     NOT = 272,
     LT = 273,
     GT = 274,
     EQQ = 275,
     LTE = 276,
     GTE = 277,
     TYPE = 278,
     COMMA = 279,
     SEMICOLON = 280,
     OCB = 281,
     CCB = 282
   };
#endif
/* Tokens.  */
#define ID 258
#define VAL 259
#define PL 260
#define MI 261
#define MUL 262
#define DIV 263
#define POW 264
#define EQ 265
#define OP 266
#define CL 267
#define OSB 268
#define CSB 269
#define AND 270
#define OR 271
#define NOT 272
#define LT 273
#define GT 274
#define EQQ 275
#define LTE 276
#define GTE 277
#define TYPE 278
#define COMMA 279
#define SEMICOLON 280
#define OCB 281
#define CCB 282




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 100 "three.y"
{
	char * str;
	struct NodeDec* n;
	struct ENode * e;
}
/* Line 1529 of yacc.c.  */
#line 109 "three.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

