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
    NUM = 259,
    READ = 260,
    ASGN = 261,
    NEWLINE = 262,
    WRITE = 263,
    PLUS = 264,
    MUL = 265,
    EVAL = 266,
    IF = 267,
    THEN = 268,
    ELSE = 269,
    WHILE = 270,
    DO = 271,
    ENDWHILE = 272,
    ENDIF = 273,
    LT = 274,
    GT = 275,
    EQ = 276,
    NEQ = 277,
    SLIST = 278,
    BREAK = 279,
    CONTINUE = 280,
    BEG = 281,
    END = 282,
    INT = 283,
    DECL = 284,
    ENDDECL = 285
  };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define READ 260
#define ASGN 261
#define NEWLINE 262
#define WRITE 263
#define PLUS 264
#define MUL 265
#define EVAL 266
#define IF 267
#define THEN 268
#define ELSE 269
#define WHILE 270
#define DO 271
#define ENDWHILE 272
#define ENDIF 273
#define LT 274
#define GT 275
#define EQ 276
#define NEQ 277
#define SLIST 278
#define BREAK 279
#define CONTINUE 280
#define BEG 281
#define END 282
#define INT 283
#define DECL 284
#define ENDDECL 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
