/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    SUB = 265,
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
    BOOL = 287
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
#define SUB 265
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
