/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

#ifndef YY_YY_FOR90_TAB_H_INCLUDED
# define YY_YY_FOR90_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     YY_IGNORE_THIS = 258,
     YY_CRLF = 259,
     YY_GT = 260,
     YY_GE = 261,
     YY_EQ = 262,
     YY_LE = 263,
     YY_LT = 264,
     YY_NEQ = 265,
     YY_NEQV = 266,
     YY_EQV = 267,
     YY_ANDAND = 268,
     YY_OROR = 269,
     YY_NOT = 270,
     YY_POWER = 271,
     YY_DOUBLECOLON = 272,
     YY_NEG = 273,
     YY_POS = 274,
     YY_EXPONENT = 275,
     YY_INTEGER = 276,
     YY_FLOAT = 277,
     YY_WORD = 278,
     YY_OPERATOR = 279,
     YY_STRING = 280,
     YY_ILLEGAL = 281,
     YY_COMPLEX = 282,
     YY_TRUE = 283,
     YY_FALSE = 284,
     YY_FORMAT_STMT = 285,
     YY_COMMENT = 286,
     YY_LABEL = 287,
     YY_END = 288,
     YY_IF = 289,
     YY_THEN = 290,
     YY_ELSE = 291,
     YY_ELSEIF = 292,
     YY_ENDIF = 293,
     YY_DO = 294,
     YY_ENDDO = 295,
     YY_CONTINUE = 296,
     YY_BREAK = 297,
     YY_EXIT = 298,
     YY_CYCLE = 299,
     YY_WHILE = 300,
     YY_ENDWHILE = 301,
     YY_WHERE = 302,
     YY_ENDWHERE = 303,
     YY_CASE = 304,
     YY_ENDCASE = 305,
     YY_SELECT = 306,
     YY_ENDSELECT = 307,
     YY_GOTO = 308,
     YY_DOWHILE = 309,
     YY_DEFAULT = 310,
     YY_PROGRAM = 311,
     YY_ENDPROGRAM = 312,
     YY_FUNCTION = 313,
     YY_ENDFUNCTION = 314,
     YY_RECURSIVE = 315,
     YY_RESULT = 316,
     YY_SUBROUTINE = 317,
     YY_ENDSUBROUTINE = 318,
     YY_MODULE = 319,
     YY_ENDMODULE = 320,
     YY_BLOCK = 321,
     YY_ENDBLOCK = 322,
     YY_INTERFACE = 323,
     YY_ENDINTERFACE = 324,
     YY_COMMON = 325,
     YY_DATA = 326,
     YY_IMPLICIT = 327,
     YY_NONE = 328,
     YY_USE = 329,
     YY_PARAMETER = 330,
     YY_ENTRY = 331,
     YY_DIMENSION = 332,
     YY_ARRAYBUILDER_START = 333,
     YY_ARRAYBUILDER_END = 334,
     YY_INTENT = 335,
     YY_IN = 336,
     YY_OUT = 337,
     YY_INOUT = 338,
     YY_OPTIONAL = 339,
     YY_LEN = 340,
     YY_KIND = 341,
     YY_SAVE = 342,
     YY_ALLOCATABLE = 343,
     YY_TARGET = 344,
     YY_POINTER = 345,
     YY_INTEGER_T = 346,
     YY_FLOAT_T = 347,
     YY_STRING_T = 348,
     YY_COMPLEX_T = 349,
     YY_BOOL_T = 350,
     YY_CHARACTER_T = 351,
     YY_DOUBLE_T = 352,
     YY_WRITE = 353,
     YY_READ = 354,
     YY_PRINT = 355,
     YY_CALL = 356,
     YY_STOP = 357,
     YY_PAUSE = 358,
     YY_RETURN = 359,
     YY_CONFIG_IMPLICIT = 360,
     YY_ALLOCATE = 361
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_FOR90_TAB_H_INCLUDED  */
