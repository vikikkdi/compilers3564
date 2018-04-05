/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
    TYPE = 258,
    VAL = 259,
    AND = 260,
    OR = 261,
    NOT = 262,
    LT = 263,
    GT = 264,
    EQQ = 265,
    LTE = 266,
    GTE = 267,
    PL = 268,
    MI = 269,
    MUL = 270,
    DIV = 271,
    OP = 272,
    CL = 273,
    OCB = 274,
    CCB = 275,
    OSB = 276,
    CSB = 277,
    EQ = 278,
    COMMA = 279,
    SEMICOLON = 280,
    IF = 281,
    ELSE = 282,
    WHILE = 283,
    TRUE = 284,
    FALSE = 285,
    NTE = 286,
    INIT = 287,
    AT = 288,
    HASH = 289,
    QN = 290,
    ID = 291
  };
#endif
/* Tokens.  */
#define TYPE 258
#define VAL 259
#define AND 260
#define OR 261
#define NOT 262
#define LT 263
#define GT 264
#define EQQ 265
#define LTE 266
#define GTE 267
#define PL 268
#define MI 269
#define MUL 270
#define DIV 271
#define OP 272
#define CL 273
#define OCB 274
#define CCB 275
#define OSB 276
#define CSB 277
#define EQ 278
#define COMMA 279
#define SEMICOLON 280
#define IF 281
#define ELSE 282
#define WHILE 283
#define TRUE 284
#define FALSE 285
#define NTE 286
#define INIT 287
#define AT 288
#define HASH 289
#define QN 290
#define ID 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 18 "three.y" /* yacc.c:1909  */

	char * str;

#line 130 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
