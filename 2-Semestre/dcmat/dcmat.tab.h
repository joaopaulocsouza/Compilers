/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_DCMAT_TAB_H_INCLUDED
# define YY_YY_DCMAT_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 35 "dcmat.y"

    class Expressao;
    class MatrixClass;

#line 54 "dcmat.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ADD = 258,                     /* ADD  */
    SUBTRACT = 259,                /* SUBTRACT  */
    MULTIPLY = 260,                /* MULTIPLY  */
    DIV = 261,                     /* DIV  */
    POW = 262,                     /* POW  */
    REST = 263,                    /* REST  */
    L_PAREN = 264,                 /* L_PAREN  */
    R_PAREN = 265,                 /* R_PAREN  */
    EQUAL = 266,                   /* EQUAL  */
    ASSIGN = 267,                  /* ASSIGN  */
    COLON = 268,                   /* COLON  */
    L_SQUARE_BRACKET = 269,        /* L_SQUARE_BRACKET  */
    R_SQUARE_BRACKET = 270,        /* R_SQUARE_BRACKET  */
    SEMICOLON = 271,               /* SEMICOLON  */
    COMMA = 272,                   /* COMMA  */
    ABOUT = 273,                   /* ABOUT  */
    ABS = 274,                     /* ABS  */
    AXIS = 275,                    /* AXIS  */
    CONNECT_DOTS = 276,            /* CONNECT_DOTS  */
    COS = 277,                     /* COS  */
    DETERMINANT = 278,             /* DETERMINANT  */
    ERASE = 279,                   /* ERASE  */
    FLOAT = 280,                   /* FLOAT  */
    H_VIEW = 281,                  /* H_VIEW  */
    INTEGRAL_STEPS = 282,          /* INTEGRAL_STEPS  */
    INTEGRATE = 283,               /* INTEGRATE  */
    LINEAR_SYSTEM = 284,           /* LINEAR_SYSTEM  */
    MATRIX = 285,                  /* MATRIX  */
    OFF = 286,                     /* OFF  */
    ON = 287,                      /* ON  */
    PI = 288,                      /* PI  */
    E = 289,                       /* E  */
    VAR = 290,                     /* VAR  */
    PLOT = 291,                    /* PLOT  */
    PRECISION = 292,               /* PRECISION  */
    QUIT = 293,                    /* QUIT  */
    RESET = 294,                   /* RESET  */
    RPN = 295,                     /* RPN  */
    SEN = 296,                     /* SEN  */
    SET = 297,                     /* SET  */
    SETTINGS = 298,                /* SETTINGS  */
    SHOW = 299,                    /* SHOW  */
    SOLVE = 300,                   /* SOLVE  */
    SUM = 301,                     /* SUM  */
    SYMBOLS = 302,                 /* SYMBOLS  */
    TAN = 303,                     /* TAN  */
    V_VIEW = 304,                  /* V_VIEW  */
    INT = 305,                     /* INT  */
    REAL = 306,                    /* REAL  */
    IDENTIFIER = 307,              /* IDENTIFIER  */
    EOL = 308                      /* EOL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 40 "dcmat.y"

    int integerValue;
    float floatValue;
    bool boolValue;
    char *stringValue;
    Expressao *expValue;
    MatrixClass *matrixValue;

#line 133 "dcmat.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_DCMAT_TAB_H_INCLUDED  */
