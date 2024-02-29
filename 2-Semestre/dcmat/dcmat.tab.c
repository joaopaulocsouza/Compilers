/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "dcmat.y"

    #include "dcmat.hpp"
    #include "includes.hpp"
    #include <dcmat.tab.h>

    DCMAT dcmat;
    Expressao expressao;
    Expressao *function = nullptr; 
    Expressao *matrix = nullptr;

    DeclaredVar result;

    extern float h_view_lo;
    extern float h_view_hi;
    extern float v_view_lo;
    extern float v_view_hi;
    extern int precision;
    extern int integral_steps;
    extern bool Axis;
    extern bool Erase_Plot;

    float euler = 2.71828182;
    float pi = 3.14159265;

    bool hasError = false;
    bool hasUndeclared = false;
    Vetor *undeclared = new Vetor();

    bool isLexico = false;
    extern int yylex();
    extern char* yytext;
    extern int yychar;
    extern int yyleng;
    void yyerror(const void *s);
    void PrintUndeclareds();
    bool stopPrint = false;

#line 109 "dcmat.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "dcmat.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ADD = 3,                        /* ADD  */
  YYSYMBOL_SUBTRACT = 4,                   /* SUBTRACT  */
  YYSYMBOL_MULTIPLY = 5,                   /* MULTIPLY  */
  YYSYMBOL_DIV = 6,                        /* DIV  */
  YYSYMBOL_POW = 7,                        /* POW  */
  YYSYMBOL_REST = 8,                       /* REST  */
  YYSYMBOL_L_PAREN = 9,                    /* L_PAREN  */
  YYSYMBOL_R_PAREN = 10,                   /* R_PAREN  */
  YYSYMBOL_EQUAL = 11,                     /* EQUAL  */
  YYSYMBOL_ASSIGN = 12,                    /* ASSIGN  */
  YYSYMBOL_COLON = 13,                     /* COLON  */
  YYSYMBOL_L_SQUARE_BRACKET = 14,          /* L_SQUARE_BRACKET  */
  YYSYMBOL_R_SQUARE_BRACKET = 15,          /* R_SQUARE_BRACKET  */
  YYSYMBOL_SEMICOLON = 16,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 17,                     /* COMMA  */
  YYSYMBOL_ABOUT = 18,                     /* ABOUT  */
  YYSYMBOL_ABS = 19,                       /* ABS  */
  YYSYMBOL_AXIS = 20,                      /* AXIS  */
  YYSYMBOL_CONNECT_DOTS = 21,              /* CONNECT_DOTS  */
  YYSYMBOL_COS = 22,                       /* COS  */
  YYSYMBOL_DETERMINANT = 23,               /* DETERMINANT  */
  YYSYMBOL_ERASE = 24,                     /* ERASE  */
  YYSYMBOL_FLOAT = 25,                     /* FLOAT  */
  YYSYMBOL_H_VIEW = 26,                    /* H_VIEW  */
  YYSYMBOL_INTEGRAL_STEPS = 27,            /* INTEGRAL_STEPS  */
  YYSYMBOL_INTEGRATE = 28,                 /* INTEGRATE  */
  YYSYMBOL_LINEAR_SYSTEM = 29,             /* LINEAR_SYSTEM  */
  YYSYMBOL_MATRIX = 30,                    /* MATRIX  */
  YYSYMBOL_OFF = 31,                       /* OFF  */
  YYSYMBOL_ON = 32,                        /* ON  */
  YYSYMBOL_PI = 33,                        /* PI  */
  YYSYMBOL_E = 34,                         /* E  */
  YYSYMBOL_VAR = 35,                       /* VAR  */
  YYSYMBOL_PLOT = 36,                      /* PLOT  */
  YYSYMBOL_PRECISION = 37,                 /* PRECISION  */
  YYSYMBOL_QUIT = 38,                      /* QUIT  */
  YYSYMBOL_RESET = 39,                     /* RESET  */
  YYSYMBOL_RPN = 40,                       /* RPN  */
  YYSYMBOL_SEN = 41,                       /* SEN  */
  YYSYMBOL_SET = 42,                       /* SET  */
  YYSYMBOL_SETTINGS = 43,                  /* SETTINGS  */
  YYSYMBOL_SHOW = 44,                      /* SHOW  */
  YYSYMBOL_SOLVE = 45,                     /* SOLVE  */
  YYSYMBOL_SUM = 46,                       /* SUM  */
  YYSYMBOL_SYMBOLS = 47,                   /* SYMBOLS  */
  YYSYMBOL_TAN = 48,                       /* TAN  */
  YYSYMBOL_V_VIEW = 49,                    /* V_VIEW  */
  YYSYMBOL_INT = 50,                       /* INT  */
  YYSYMBOL_REAL = 51,                      /* REAL  */
  YYSYMBOL_IDENTIFIER = 52,                /* IDENTIFIER  */
  YYSYMBOL_EOL = 53,                       /* EOL  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_Dcmat = 55,                     /* Dcmat  */
  YYSYMBOL_Command = 56,                   /* Command  */
  YYSYMBOL_Matrix = 57,                    /* Matrix  */
  YYSYMBOL_MatrixColum = 58,               /* MatrixColum  */
  YYSYMBOL_MatrixLine = 59,                /* MatrixLine  */
  YYSYMBOL_MatrixValue = 60,               /* MatrixValue  */
  YYSYMBOL_Set = 61,                       /* Set  */
  YYSYMBOL_Expressao = 62,                 /* Expressao  */
  YYSYMBOL_ExpressionSumSub = 63,          /* ExpressionSumSub  */
  YYSYMBOL_ExpressionMulDiv = 64,          /* ExpressionMulDiv  */
  YYSYMBOL_ExpressionPowRem = 65,          /* ExpressionPowRem  */
  YYSYMBOL_Signal = 66,                    /* Signal  */
  YYSYMBOL_Termo = 67,                     /* Termo  */
  YYSYMBOL_Limit = 68,                     /* Limit  */
  YYSYMBOL_Value = 69,                     /* Value  */
  YYSYMBOL_NumInt = 70,                    /* NumInt  */
  YYSYMBOL_NumFloat = 71,                  /* NumFloat  */
  YYSYMBOL_Bool = 72                       /* Bool  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   263

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   126,   126,   127,   128,   130,   131,   132,   138,   139,
     147,   148,   163,   176,   187,   199,   211,   222,   239,   249,
     256,   265,   276,   282,   298,   309,   311,   322,   333,   336,
     343,   351,   359,   362,   365,   374,   376,   379,   382,   384,
     387,   390,   392,   395,   398,   400,   401,   402,   424,   435,
     436,   447,   458,   469,   481,   482,   483,   484,   485,   486,
     488,   489,   490,   493,   494,   495,   499,   503,   505,   506
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ADD", "SUBTRACT",
  "MULTIPLY", "DIV", "POW", "REST", "L_PAREN", "R_PAREN", "EQUAL",
  "ASSIGN", "COLON", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "SEMICOLON",
  "COMMA", "ABOUT", "ABS", "AXIS", "CONNECT_DOTS", "COS", "DETERMINANT",
  "ERASE", "FLOAT", "H_VIEW", "INTEGRAL_STEPS", "INTEGRATE",
  "LINEAR_SYSTEM", "MATRIX", "OFF", "ON", "PI", "E", "VAR", "PLOT",
  "PRECISION", "QUIT", "RESET", "RPN", "SEN", "SET", "SETTINGS", "SHOW",
  "SOLVE", "SUM", "SYMBOLS", "TAN", "V_VIEW", "INT", "REAL", "IDENTIFIER",
  "EOL", "$accept", "Dcmat", "Command", "Matrix", "MatrixColum",
  "MatrixLine", "MatrixValue", "Set", "Expressao", "ExpressionSumSub",
  "ExpressionMulDiv", "ExpressionPowRem", "Signal", "Termo", "Limit",
  "Value", "NumInt", "NumFloat", "Bool", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-44)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     120,   211,   211,   191,    19,     1,    52,    55,    27,   -44,
     -44,   -44,    18,    14,    30,    65,    66,    -4,   -19,   -14,
      69,    71,   -44,   -44,    -8,   -44,    79,    31,   -44,    22,
      24,    45,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
      73,   -44,   191,   191,    -1,    76,   191,   -44,   -44,    81,
     191,   191,    23,    49,    50,    -1,    -1,    -1,   -44,    82,
      83,    84,    85,    86,    40,   191,   171,   -44,   -44,   -44,
     191,   191,   191,   191,   191,   191,   -44,    93,    94,     7,
       7,    97,   -44,   -44,    92,    95,   103,   -44,   105,   106,
     -44,   -44,   102,    23,    -1,   107,   109,   108,   -44,   -44,
     -44,   -44,   -44,   110,   112,   114,   116,    24,    24,    45,
      45,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,    -1,
      -1,   -44,   -44,   117,   118,   -44,   -44,   119,   121,    -1,
     -44,    -1,    -1,   -44,   -44,   -44,   123,   -44,   -10,   -44,
     -44,   -44,   -44,   125,   128,   113,   191,    29,   -44,    92,
     -44,   -44,    -1,   126,   -44,    -1,   -44,   129,   131,   -44,
     191,   -44,   135,   133,   -44
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      65,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,    67,    48,     2,     0,     0,    17,    35,
      38,    41,    44,    45,    49,    60,    61,    48,    46,    47,
       0,     9,     0,     0,     0,     0,     0,    19,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     1,     4,
       0,     0,     0,     0,     0,     0,    62,     0,     0,     0,
       0,     0,    57,    54,     0,     0,     0,     8,     0,     0,
      69,    68,     0,     0,     0,     0,     0,     0,     7,     6,
       5,    15,    16,     0,     0,     0,     0,    36,    37,    39,
      40,    42,    43,    53,    51,    58,    55,    59,    56,     0,
       0,    25,    14,     0,     0,    50,    32,     0,     0,     0,
      34,     0,     0,    52,    13,    12,     0,    28,     0,    18,
      22,    33,    29,     0,     0,     0,     0,     0,    23,     0,
      30,    31,     0,     0,    26,     0,    24,     0,     0,    27,
       0,    20,     0,     0,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -44,   -44,   -44,    53,   -44,     2,   -44,   -44,    -3,   -44,
     -11,    -7,    -6,    70,   -24,   -44,   -43,   -38,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    26,    27,    85,   138,   121,   147,    58,    28,    29,
      30,    31,    32,    33,    81,    34,    35,    36,    92
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,    82,    79,    80,    66,   148,    83,   149,    67,    62,
      42,    59,    82,    82,    82,    63,    52,    83,    83,    83,
      53,    54,    55,    56,    60,    70,    71,    46,    61,    72,
      73,    95,    96,    97,    47,    41,   115,   117,    45,    77,
      78,   116,   118,    86,   154,    57,   155,    88,    89,    22,
      23,    82,    74,    75,    90,    91,    83,    22,    23,   107,
     108,    43,   104,   106,    44,   109,   110,    48,   111,   112,
     128,    38,    39,    49,    50,    51,    82,    82,    64,    68,
      65,    83,    83,    76,    69,    93,    82,    94,    82,    82,
      84,    83,   103,    83,    83,   136,   137,    87,    98,    99,
     100,   101,   102,   113,   114,   143,   120,   144,   145,    82,
     119,   122,    82,   123,    83,   124,   125,    83,   126,   105,
     129,   131,   133,     1,     2,   130,   152,   132,   157,     3,
     134,   159,   135,   139,   140,   141,   158,   142,     4,     5,
     146,   150,     6,   153,   151,   163,   160,   161,     7,   164,
       8,   156,   127,     9,    10,    11,    12,   162,    13,    14,
      15,    16,    17,     0,    18,    19,    20,     0,    21,     0,
      22,    23,    24,    25,     1,     2,     0,     0,     0,     0,
       3,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       5,     0,     0,     6,     1,     2,     0,     0,     0,     0,
       3,     0,     0,     0,     9,    10,    11,     0,     0,     0,
       5,     0,    16,     6,     0,     0,     0,     0,     0,    21,
       3,    22,    23,    37,     9,    10,    11,     0,     0,     0,
       5,     0,    16,     6,     0,     0,     0,     0,     0,    21,
       0,    22,    23,    37,     9,    10,    11,     0,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,     0,    21,
       0,    22,    23,    37
};

static const yytype_int16 yycheck[] =
{
       3,    44,     3,     4,    12,    15,    44,    17,    16,    23,
       9,    30,    55,    56,    57,    29,    20,    55,    56,    57,
      24,    25,    26,    27,    43,     3,     4,     9,    47,     5,
       6,    55,    56,    57,    16,    16,    79,    80,    11,    42,
      43,    79,    80,    46,    15,    49,    17,    50,    51,    50,
      51,    94,     7,     8,    31,    32,    94,    50,    51,    70,
      71,     9,    65,    66,     9,    72,    73,    53,    74,    75,
      94,     1,     2,    43,     9,     9,   119,   120,     9,     0,
       9,   119,   120,    10,    53,    36,   129,    37,   131,   132,
      14,   129,    52,   131,   132,   119,   120,    16,    16,    16,
      16,    16,    16,    10,    10,   129,    14,   131,   132,   152,
      13,    16,   155,    10,   152,    10,    10,   155,    16,    66,
      13,    13,    10,     3,     4,    16,    13,    17,   152,     9,
      16,   155,    16,    16,    16,    16,    10,    16,    18,    19,
      17,    16,    22,   146,    16,    10,    17,    16,    28,    16,
      30,   149,    93,    33,    34,    35,    36,   160,    38,    39,
      40,    41,    42,    -1,    44,    45,    46,    -1,    48,    -1,
      50,    51,    52,    53,     3,     4,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    22,     3,     4,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,
      19,    -1,    41,    22,    -1,    -1,    -1,    -1,    -1,    48,
       9,    50,    51,    52,    33,    34,    35,    -1,    -1,    -1,
      19,    -1,    41,    22,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     9,    18,    19,    22,    28,    30,    33,
      34,    35,    36,    38,    39,    40,    41,    42,    44,    45,
      46,    48,    50,    51,    52,    53,    55,    56,    62,    63,
      64,    65,    66,    67,    69,    70,    71,    52,    67,    67,
      62,    16,     9,     9,     9,    11,     9,    16,    53,    43,
       9,     9,    20,    24,    25,    26,    27,    49,    61,    30,
      43,    47,    23,    29,     9,     9,    12,    16,     0,    53,
       3,     4,     5,     6,     7,     8,    10,    62,    62,     3,
       4,    68,    70,    71,    14,    57,    62,    16,    62,    62,
      31,    32,    72,    36,    37,    68,    68,    68,    16,    16,
      16,    16,    16,    52,    62,    57,    62,    64,    64,    65,
      65,    66,    66,    10,    10,    70,    71,    70,    71,    13,
      14,    59,    16,    10,    10,    10,    16,    72,    68,    13,
      16,    13,    17,    10,    16,    16,    68,    68,    58,    16,
      16,    16,    16,    68,    68,    68,    17,    60,    15,    17,
      16,    16,    13,    62,    15,    17,    59,    68,    10,    68,
      17,    16,    62,    10,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    58,    58,    59,    60,    60,    61,
      61,    61,    61,    61,    61,    62,    63,    63,    63,    64,
      64,    64,    65,    65,    65,    66,    66,    66,    67,    67,
      67,    67,    67,    67,    68,    68,    68,    68,    68,    68,
      69,    69,    69,    69,    69,    69,    70,    71,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     3,     3,     3,     3,     2,
       2,     2,     4,     4,     4,     3,     3,     1,     5,     2,
       9,    11,     5,     4,     3,     0,     4,     3,     0,     4,
       5,     5,     3,     4,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     1,     2,     2,     1,     1,
       4,     4,     4,     4,     1,     2,     2,     1,     2,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Dcmat: EOL  */
#line 126 "dcmat.y"
           {stopPrint = false; return 0;}
#line 1289 "dcmat.tab.c"
    break;

  case 3: /* Dcmat: QUIT EOL  */
#line 127 "dcmat.y"
               {exit(0);}
#line 1295 "dcmat.tab.c"
    break;

  case 4: /* Dcmat: Command EOL  */
#line 128 "dcmat.y"
                  {stopPrint = false; hasUndeclared = false; undeclared->vetor.clear() ;return 0;}
#line 1301 "dcmat.tab.c"
    break;

  case 5: /* Command: SHOW SYMBOLS SEMICOLON  */
#line 130 "dcmat.y"
                                {dcmat.ShowSymbols();}
#line 1307 "dcmat.tab.c"
    break;

  case 6: /* Command: SHOW SETTINGS SEMICOLON  */
#line 131 "dcmat.y"
                              {dcmat.ShowSettings();}
#line 1313 "dcmat.tab.c"
    break;

  case 7: /* Command: SHOW MATRIX SEMICOLON  */
#line 132 "dcmat.y"
                            {
        if(matrix != nullptr){
            dcmat.ShowMatrix(matrix->matrix);}
        else {
            std::cout << "\nNo Matrix defined!\n\n";
            }}
#line 1324 "dcmat.tab.c"
    break;

  case 8: /* Command: RESET SETTINGS SEMICOLON  */
#line 138 "dcmat.y"
                               {dcmat.ResetSettings();}
#line 1330 "dcmat.tab.c"
    break;

  case 9: /* Command: ABOUT SEMICOLON  */
#line 139 "dcmat.y"
                      {
        printf("\n+----------------------------------------------+\n");
        printf("|"); for(int i = 0; i < 46; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(int i = 0; i < 17; i++) {printf(" ");};  printf("201800560120"); for(int i = 0; i < 17; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(int i = 0; i < 9; i++) {printf(" ");};  printf("João Paulo Cardoso de Souza"); for(int i = 0; i < 10; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(int i = 0; i < 46; i++) {printf(" ");}; printf("|\n");
        printf("+----------------------------------------------+\n\n");
    }
#line 1343 "dcmat.tab.c"
    break;

  case 11: /* Command: IDENTIFIER SEMICOLON  */
#line 148 "dcmat.y"
                           {
        result = dcmat.FindHashItem((yyvsp[-1].stringValue));
        if(result.exists){
            if(result.type == MATRIX_KEY){
                dcmat.ShowMatrix(result.value->matrix);
            }
            else if(result.type == INT_KEY){
                std::cout << "\n" << (yyvsp[-1].stringValue) << " = " << result.value->value << "\n\n";
            }else if(result.type == FLOAT_KEY){
                std::cout << "\n" << std::fixed << std::setprecision(precision) << (yyvsp[-1].stringValue) << " = " << result.value->value << "\n\n";
            }
        }else{
            std::cout << "\nUndefined symbol\n\n";
        }
    }
#line 1363 "dcmat.tab.c"
    break;

  case 12: /* Command: IDENTIFIER ASSIGN Expressao SEMICOLON  */
#line 163 "dcmat.y"
                                            {
        if(hasUndeclared){
            PrintUndeclareds();
        }else if((yyvsp[-1].expValue) != nullptr){
            Expressao *exp = (yyvsp[-1].expValue);
            dcmat.CreateHashItem((yyvsp[-3].stringValue), exp, exp->type);
            if(exp->type == FLOAT_KEY || exp->type == INT_KEY) {
                std::cout << "\n" << std::fixed << std::setprecision(precision) << (float)exp->value << "\n\n" ;
            } else if(exp->type == MATRIX_KEY){
                dcmat.ShowMatrix((yyvsp[-1].expValue)->matrix);
            }
        };
    }
#line 1381 "dcmat.tab.c"
    break;

  case 13: /* Command: IDENTIFIER ASSIGN Matrix SEMICOLON  */
#line 176 "dcmat.y"
                                        {
        if((yyvsp[-1].matrixValue) != nullptr){
            if((yyvsp[-1].matrixValue)->lines > 10 || (yyvsp[-1].matrixValue)->columns > 10){
                std::cout << "\nERROR: Matrix limits out of boundaries.\n" << std::endl;
            }else{
                Expressao *exp = expressao.CreateMatrix((yyvsp[-1].matrixValue));
                dcmat.CreateHashItem((yyvsp[-3].stringValue), exp, MATRIX_KEY);
                dcmat.ShowMatrix((yyvsp[-1].matrixValue));
            }
        }
    }
#line 1397 "dcmat.tab.c"
    break;

  case 14: /* Command: MATRIX EQUAL Matrix SEMICOLON  */
#line 187 "dcmat.y"
                                   {
        if((yyvsp[-1].matrixValue)->lines > 10 || (yyvsp[-1].matrixValue)->columns > 10){
            std::cout << "\nERROR: Matrix limits out of boundaries.\n" << std::endl;
        }else{
            if(matrix){
                matrix->matrix = (yyvsp[-1].matrixValue);
            }else{
                Expressao *exp = expressao.CreateMatrix((yyvsp[-1].matrixValue));
                matrix = exp;
            }
        }
    }
#line 1414 "dcmat.tab.c"
    break;

  case 15: /* Command: SOLVE DETERMINANT SEMICOLON  */
#line 199 "dcmat.y"
                                  {
        if(matrix){
            if(matrix->matrix->lines != matrix->matrix->columns){
                std::cout << "Matrix format incorrect!\n";
            }else{
                float det = dcmat.SolveDeterminant(matrix->matrix);
                std::cout << "\n" << std::fixed << std::setprecision(precision) << det << "\n\n";
            }
        }else{
            std::cout << "\nNo Function defined!\n\n";
        }
    }
#line 1431 "dcmat.tab.c"
    break;

  case 16: /* Command: SOLVE LINEAR_SYSTEM SEMICOLON  */
#line 211 "dcmat.y"
                                    {
        if(matrix){
            if(matrix->matrix->lines != matrix->matrix->columns-1){
                std::cout << "\nMatrix format incorrect!\n\n";
            }else{
                dcmat.SolveLinearSystem(matrix->matrix);
            }
        }else{
            std::cout << "\nNo Function defined!\n\n";
        }
    }
#line 1447 "dcmat.tab.c"
    break;

  case 17: /* Command: Expressao  */
#line 222 "dcmat.y"
                { 
        if((yyvsp[0].expValue) != nullptr){
            Expressao *exp = (yyvsp[0].expValue); 
            if(hasUndeclared){
                PrintUndeclareds();
            }else if(exp->element != FUNCTION_KEY){
                if(exp->type == MATRIX_KEY){
                    dcmat.ShowMatrix(exp->matrix);
                }else{

                std::cout << "\n" << std::fixed << std::setprecision(precision) << exp->value << "\n\n"; 
                }
            }
            else{ 
                std::cout << "\nThe x variable cannot be present on expressions.\n" << std::endl;}
            }
        }
#line 1469 "dcmat.tab.c"
    break;

  case 18: /* Command: PLOT L_PAREN Expressao R_PAREN SEMICOLON  */
#line 239 "dcmat.y"
                                               {
        if(hasUndeclared){
            PrintUndeclareds();
        }else if((yyvsp[-2].expValue)->element == FUNCTION_KEY){
            function = (yyvsp[-2].expValue);
            dcmat.PlotChart(function);
        }else{
            std::cout << "\nNo Function defined!\n\n";
        }
    }
#line 1484 "dcmat.tab.c"
    break;

  case 19: /* Command: PLOT SEMICOLON  */
#line 249 "dcmat.y"
                     {
        if(function){
            dcmat.PlotChart(function);
        }else{
            std::cout << "\nNo Function defined!\n\n";
        }
    }
#line 1496 "dcmat.tab.c"
    break;

  case 20: /* Command: INTEGRATE L_PAREN Limit COLON Limit COMMA Expressao R_PAREN SEMICOLON  */
#line 256 "dcmat.y"
                                                                            {
        if(hasUndeclared){
            PrintUndeclareds();
        }else if((yyvsp[-4].floatValue) <= (yyvsp[-6].floatValue)){
            std::cout << "\nERROR: lower limit must be smaller than upper limit\n\n";
        }else{
            dcmat.Integrate((yyvsp[-4].floatValue), (yyvsp[-6].floatValue), (yyvsp[-2].expValue));
        }
    }
#line 1510 "dcmat.tab.c"
    break;

  case 21: /* Command: SUM L_PAREN IDENTIFIER COMMA Limit COLON Limit COMMA Expressao R_PAREN SEMICOLON  */
#line 265 "dcmat.y"
                                                                                       {
         if(hasUndeclared){
            for(int i = 0; i < undeclared->vetor.size(); i++){
                if(undeclared->vetor[i] == (yyvsp[-8].stringValue)){
                    undeclared->vetor.erase(undeclared->vetor.begin() + i);
                }
            }
        }

        undeclared->vetor.size() > 0 ?PrintUndeclareds():dcmat.Sum((yyvsp[-6].floatValue), (yyvsp[-4].floatValue), (yyvsp[-2].expValue));
    }
#line 1526 "dcmat.tab.c"
    break;

  case 22: /* Command: RPN L_PAREN Expressao R_PAREN SEMICOLON  */
#line 276 "dcmat.y"
                                              {
        std::cout << "\nExpression in RPN format:\n\n";
        dcmat.ReversePolishNotation((yyvsp[-2].expValue));
        std::cout << "\n\n";
    }
#line 1536 "dcmat.tab.c"
    break;

  case 23: /* Matrix: L_SQUARE_BRACKET MatrixLine MatrixColum R_SQUARE_BRACKET  */
#line 283 "dcmat.y"
    {
        (yyvsp[-2].matrixValue)->matrix.push_back((yyvsp[-2].matrixValue)->line);
        if((yyvsp[-1].matrixValue) != nullptr){
            for(int i = 0; i < (yyvsp[-1].matrixValue)->matrix.size(); i++){
                (yyvsp[-2].matrixValue)->matrix.push_back((yyvsp[-1].matrixValue)->matrix[i]);
            }
        }
        (yyvsp[-2].matrixValue)->lines = (yyvsp[-2].matrixValue)->matrix.size();
        (yyvsp[-2].matrixValue)->columns = (yyvsp[-2].matrixValue)->matrix[0].size();
        for(int i = 0; i < (yyvsp[-2].matrixValue)->matrix.size(); i++){
            if((yyvsp[-2].matrixValue)->columns < (yyvsp[-2].matrixValue)->matrix[i].size()) (yyvsp[-2].matrixValue)->columns = (yyvsp[-2].matrixValue)->matrix[i].size();
        }
        (yyval.matrixValue) = (yyvsp[-2].matrixValue);
    }
#line 1555 "dcmat.tab.c"
    break;

  case 24: /* MatrixColum: MatrixColum COMMA MatrixLine  */
#line 298 "dcmat.y"
                                          {
            MatrixClass *line = nullptr;
                if((yyvsp[-2].matrixValue) != nullptr){
                    (yyvsp[-2].matrixValue)->matrix.push_back((yyvsp[0].matrixValue)->line);
                    line = (yyvsp[-2].matrixValue);
                }else{
                    line = new MatrixClass();
                    line->matrix.push_back((yyvsp[0].matrixValue)->line);
                }
            (yyval.matrixValue) = line;
        }
#line 1571 "dcmat.tab.c"
    break;

  case 25: /* MatrixColum: %empty  */
#line 309 "dcmat.y"
          {(yyval.matrixValue) = nullptr;}
#line 1577 "dcmat.tab.c"
    break;

  case 26: /* MatrixLine: L_SQUARE_BRACKET Limit MatrixValue R_SQUARE_BRACKET  */
#line 311 "dcmat.y"
                                                                {
        MatrixClass *line = new MatrixClass();
        line->line.push_back((yyvsp[-2].floatValue));
        if((yyvsp[-1].matrixValue) != nullptr){
            for(int i = 0; i < (yyvsp[-1].matrixValue)->line.size(); i++){
                line->line.push_back((yyvsp[-1].matrixValue)->line[i]);
            }
        }
        (yyval.matrixValue) = line;
    }
#line 1592 "dcmat.tab.c"
    break;

  case 27: /* MatrixValue: MatrixValue COMMA Limit  */
#line 322 "dcmat.y"
                                     { 
        MatrixClass *line = nullptr;
            if((yyvsp[-2].matrixValue) != nullptr){
                (yyvsp[-2].matrixValue)->line.push_back((yyvsp[0].floatValue));
                line = (yyvsp[-2].matrixValue);
            }else{
                line = new MatrixClass();
                line->line.push_back((yyvsp[0].floatValue));
            }
            (yyval.matrixValue) = line;
        }
#line 1608 "dcmat.tab.c"
    break;

  case 28: /* MatrixValue: %empty  */
#line 333 "dcmat.y"
          {(yyval.matrixValue) = nullptr;}
#line 1614 "dcmat.tab.c"
    break;

  case 29: /* Set: FLOAT PRECISION Limit SEMICOLON  */
#line 336 "dcmat.y"
                                            {
        if((yyvsp[-1].floatValue) <= 8 && (yyvsp[-1].floatValue) >= 0){
            precision = (yyvsp[-1].floatValue);
        }else{
            printf("\nERROR: float precision must be from 0 to 8\n\n");
        }
        }
#line 1626 "dcmat.tab.c"
    break;

  case 30: /* Set: H_VIEW Limit COLON Limit SEMICOLON  */
#line 343 "dcmat.y"
                                         {
            if((yyvsp[-3].floatValue) < (yyvsp[-1].floatValue)){
                h_view_lo = (yyvsp[-3].floatValue);
                h_view_hi = (yyvsp[-1].floatValue);
            }else{
                printf("\nERROR: h_view_lo must be smaller than h_view_hi\n\n");
            }
        }
#line 1639 "dcmat.tab.c"
    break;

  case 31: /* Set: V_VIEW Limit COLON Limit SEMICOLON  */
#line 351 "dcmat.y"
                                         {
            if((yyvsp[-3].floatValue) < (yyvsp[-1].floatValue)){
                v_view_lo = (yyvsp[-3].floatValue);
                v_view_hi = (yyvsp[-1].floatValue);
            }else{
                printf("\nERROR: v_view_lo must be smaller than v_view_hi\n\n");
            }
        }
#line 1652 "dcmat.tab.c"
    break;

  case 32: /* Set: AXIS Bool SEMICOLON  */
#line 359 "dcmat.y"
                          {
            Axis = (yyvsp[-1].boolValue);
        }
#line 1660 "dcmat.tab.c"
    break;

  case 33: /* Set: ERASE PLOT Bool SEMICOLON  */
#line 362 "dcmat.y"
                                {
            Erase_Plot = (yyvsp[-1].boolValue);
        }
#line 1668 "dcmat.tab.c"
    break;

  case 34: /* Set: INTEGRAL_STEPS Limit SEMICOLON  */
#line 365 "dcmat.y"
                                     {
        if((yyvsp[-1].floatValue) <= 0){
            std::cout << "\nERROR: integral_steps must be a positive non-zero integer\n\n";
        }else{
            integral_steps = (int)(yyvsp[-1].floatValue);
        }
    }
#line 1680 "dcmat.tab.c"
    break;

  case 35: /* Expressao: ExpressionSumSub  */
#line 374 "dcmat.y"
                            {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1686 "dcmat.tab.c"
    break;

  case 36: /* ExpressionSumSub: ExpressionSumSub ADD ExpressionMulDiv  */
#line 376 "dcmat.y"
                                                        {
                        (yyval.expValue) = ((yyvsp[-2].expValue) == nullptr || (yyvsp[0].expValue) == nullptr)? nullptr:expressao.CreateExp(ADD_KEY, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1694 "dcmat.tab.c"
    break;

  case 37: /* ExpressionSumSub: ExpressionSumSub SUBTRACT ExpressionMulDiv  */
#line 379 "dcmat.y"
                                                             {
                        (yyval.expValue) = ((yyvsp[-2].expValue) == nullptr || (yyvsp[0].expValue) == nullptr)? nullptr:expressao.CreateExp(SUB_KEY, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1702 "dcmat.tab.c"
    break;

  case 38: /* ExpressionSumSub: ExpressionMulDiv  */
#line 382 "dcmat.y"
                                   {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1708 "dcmat.tab.c"
    break;

  case 39: /* ExpressionMulDiv: ExpressionMulDiv MULTIPLY ExpressionPowRem  */
#line 384 "dcmat.y"
                                                             {
                        (yyval.expValue) = ((yyvsp[-2].expValue) == nullptr || (yyvsp[0].expValue) == nullptr)? nullptr:expressao.CreateExp(MULTIPLY_KEY, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1716 "dcmat.tab.c"
    break;

  case 40: /* ExpressionMulDiv: ExpressionMulDiv DIV ExpressionPowRem  */
#line 387 "dcmat.y"
                                                        {
                        (yyval.expValue) = ((yyvsp[-2].expValue) == nullptr || (yyvsp[0].expValue) == nullptr)? nullptr:expressao.CreateExp(DIV_KEY, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1724 "dcmat.tab.c"
    break;

  case 41: /* ExpressionMulDiv: ExpressionPowRem  */
#line 390 "dcmat.y"
                                   {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1730 "dcmat.tab.c"
    break;

  case 42: /* ExpressionPowRem: ExpressionPowRem POW Signal  */
#line 392 "dcmat.y"
                                              {
                        (yyval.expValue) = ((yyvsp[-2].expValue) == nullptr || (yyvsp[0].expValue) == nullptr)? nullptr:expressao.CreateExp(POW_KEY, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1738 "dcmat.tab.c"
    break;

  case 43: /* ExpressionPowRem: ExpressionPowRem REST Signal  */
#line 395 "dcmat.y"
                                               {
                        (yyval.expValue) = ((yyvsp[-2].expValue) == nullptr || (yyvsp[0].expValue) == nullptr)? nullptr:expressao.CreateExp(REST, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1746 "dcmat.tab.c"
    break;

  case 44: /* ExpressionPowRem: Signal  */
#line 398 "dcmat.y"
                         {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1752 "dcmat.tab.c"
    break;

  case 45: /* Signal: Termo  */
#line 400 "dcmat.y"
              {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1758 "dcmat.tab.c"
    break;

  case 46: /* Signal: ADD Termo  */
#line 401 "dcmat.y"
                    {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1764 "dcmat.tab.c"
    break;

  case 47: /* Signal: SUBTRACT Termo  */
#line 402 "dcmat.y"
                         {
            if((yyvsp[0].expValue)->type == MATRIX_KEY){
                Expressao *exp = expressao.CreateMatrix((yyvsp[0].expValue)->matrix);
                for(int i = 0; i < exp->matrix->lines; i++){
                    for(int j = 0; j < exp->matrix->columns; j++){
                        exp->matrix->matrix[i][j] *= -1; 
                    }
                }
                (yyval.expValue) = exp;
            }else{
                switch((yyvsp[0].expValue)->type){
                    case VAR_KEY:
                        (yyvsp[0].expValue)->type = SUBVAR_KEY;
                        break;
                    default:
                        if((yyvsp[0].expValue)->element != FUNCTION_KEY) (yyvsp[0].expValue)->value = -(yyvsp[0].expValue)->value;
                        break;
                }
                (yyval.expValue) = (yyvsp[0].expValue);
            }
        }
#line 1790 "dcmat.tab.c"
    break;

  case 48: /* Termo: IDENTIFIER  */
#line 424 "dcmat.y"
                  {
            result = dcmat.FindHashItem((yyvsp[0].stringValue));
            if(result.exists){
                result.value->id = (yyvsp[0].stringValue);
               (yyval.expValue) = result.value;
            }else{
                Expressao *exp = expressao.CreateSheet(ID_KEY, OP, 0, nullptr, EXPRESSION_KEY, (yyvsp[0].stringValue));
                (yyval.expValue) = exp;
                hasUndeclared = true;
                undeclared->vetor.push_back((yyvsp[0].stringValue));
            }}
#line 1806 "dcmat.tab.c"
    break;

  case 49: /* Termo: Value  */
#line 435 "dcmat.y"
                {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1812 "dcmat.tab.c"
    break;

  case 50: /* Termo: SEN L_PAREN Expressao R_PAREN  */
#line 436 "dcmat.y"
                                        { 
                if((yyvsp[-1].expValue)->type == MATRIX_KEY){
                    std::cout << "\nIncorrect type for operator ’SEN’ - have MATRIX\n\n";
                    (yyval.expValue) = nullptr;
                }else{
                    float value = 0;
                    int element = (yyvsp[-1].expValue)->element;
                    if((yyvsp[-1].expValue)->element != FUNCTION_KEY)value = sin((yyvsp[-1].expValue)->value);
                    (yyval.expValue) = expressao.CreateSheet((yyvsp[-1].expValue)->type, SEN_KEY, value, (yyvsp[-1].expValue), element);
                }
            }
#line 1828 "dcmat.tab.c"
    break;

  case 51: /* Termo: COS L_PAREN Expressao R_PAREN  */
#line 447 "dcmat.y"
                                         { 
                if((yyvsp[-1].expValue)->type == MATRIX_KEY){
                    std::cout << "\nIncorrect type for operator ’COS’ - have MATRIX\n\n";
                    (yyval.expValue) = nullptr;
                }else{
                    float value = 0;
                    int element = (yyvsp[-1].expValue)->element;
                    if((yyvsp[-1].expValue)->element != FUNCTION_KEY) value = cos((yyvsp[-1].expValue)->value);
                    (yyval.expValue) = expressao.CreateSheet((yyvsp[-1].expValue)->type, COS_KEY, value, (yyvsp[-1].expValue), element);
                }
            }
#line 1844 "dcmat.tab.c"
    break;

  case 52: /* Termo: TAN L_PAREN Expressao R_PAREN  */
#line 458 "dcmat.y"
                                         { 
                if((yyvsp[-1].expValue)->type == MATRIX_KEY){
                    std::cout << "\nIncorrect type for operator ’TAN’ - have MATRIX\n\n";
                    (yyval.expValue) = nullptr;
                }else{
                    float value = 0;
                    int element = (yyvsp[-1].expValue)->element;
                    if((yyvsp[-1].expValue)->element != FUNCTION_KEY) value = tan((yyvsp[-1].expValue)->value);
                    (yyval.expValue) = expressao.CreateSheet((yyvsp[-1].expValue)->type, TAN_KEY, value, (yyvsp[-1].expValue), element);
                }
            }
#line 1860 "dcmat.tab.c"
    break;

  case 53: /* Termo: ABS L_PAREN Expressao R_PAREN  */
#line 469 "dcmat.y"
                                        { 
                if((yyvsp[-1].expValue)->type == MATRIX_KEY){
                    std::cout << "\nIncorrect type for operator ’ABS’ - have MATRIX\n\n";
                    (yyval.expValue) = nullptr;
                }else{
                    float value = 0;
                    int element = (yyvsp[-1].expValue)->element;
                    if((yyvsp[-1].expValue)->element != FUNCTION_KEY) value = abs((yyvsp[-1].expValue)->value);
                    (yyval.expValue) = expressao.CreateSheet((yyvsp[-1].expValue)->type, ABS_KEY, value, (yyvsp[-1].expValue), element);
                }
            }
#line 1876 "dcmat.tab.c"
    break;

  case 54: /* Limit: NumFloat  */
#line 481 "dcmat.y"
                {(yyval.floatValue) = (yyvsp[0].floatValue);}
#line 1882 "dcmat.tab.c"
    break;

  case 55: /* Limit: ADD NumFloat  */
#line 482 "dcmat.y"
                       {(yyval.floatValue) = (yyvsp[0].floatValue);}
#line 1888 "dcmat.tab.c"
    break;

  case 56: /* Limit: SUBTRACT NumFloat  */
#line 483 "dcmat.y"
                            { (yyval.floatValue) = -(yyvsp[0].floatValue); }
#line 1894 "dcmat.tab.c"
    break;

  case 57: /* Limit: NumInt  */
#line 484 "dcmat.y"
                 {(yyval.floatValue) = (yyvsp[0].integerValue);}
#line 1900 "dcmat.tab.c"
    break;

  case 58: /* Limit: ADD NumInt  */
#line 485 "dcmat.y"
                     {(yyval.floatValue) = (yyvsp[0].integerValue);}
#line 1906 "dcmat.tab.c"
    break;

  case 59: /* Limit: SUBTRACT NumInt  */
#line 486 "dcmat.y"
                          {(yyval.floatValue) = -(yyvsp[0].integerValue);}
#line 1912 "dcmat.tab.c"
    break;

  case 60: /* Value: NumInt  */
#line 488 "dcmat.y"
              { (yyval.expValue) = expressao.CreateSheet(INT_KEY, OP, (yyvsp[0].integerValue), nullptr); }
#line 1918 "dcmat.tab.c"
    break;

  case 61: /* Value: NumFloat  */
#line 489 "dcmat.y"
               { (yyval.expValue) = expressao.CreateSheet(FLOAT_KEY, OP, (yyvsp[0].floatValue), nullptr); }
#line 1924 "dcmat.tab.c"
    break;

  case 62: /* Value: L_PAREN Expressao R_PAREN  */
#line 490 "dcmat.y"
                                { 
        int element = (yyvsp[-1].expValue)->element;
        (yyval.expValue) = expressao.CreateSheet((yyvsp[-1].expValue)->type, EXP_KEY, (yyvsp[-1].expValue)->value, (yyvsp[-1].expValue), element) ;}
#line 1932 "dcmat.tab.c"
    break;

  case 63: /* Value: VAR  */
#line 493 "dcmat.y"
          {(yyval.expValue) = expressao.CreateSheet(VAR_KEY, OP, 0, nullptr); }
#line 1938 "dcmat.tab.c"
    break;

  case 64: /* Value: PI  */
#line 494 "dcmat.y"
         { (yyval.expValue) = expressao.CreateSheet(FLOAT_KEY, OP, pi, nullptr); }
#line 1944 "dcmat.tab.c"
    break;

  case 65: /* Value: E  */
#line 495 "dcmat.y"
         { (yyval.expValue) = expressao.CreateSheet(FLOAT_KEY, OP, euler, nullptr); }
#line 1950 "dcmat.tab.c"
    break;

  case 66: /* NumInt: INT  */
#line 499 "dcmat.y"
              {
            (yyval.integerValue) = (yyvsp[0].integerValue);
        }
#line 1958 "dcmat.tab.c"
    break;

  case 67: /* NumFloat: REAL  */
#line 503 "dcmat.y"
               { (yyval.floatValue) = (yyvsp[0].floatValue); }
#line 1964 "dcmat.tab.c"
    break;

  case 68: /* Bool: ON  */
#line 505 "dcmat.y"
         { (yyval.boolValue) = true; }
#line 1970 "dcmat.tab.c"
    break;

  case 69: /* Bool: OFF  */
#line 506 "dcmat.y"
          { (yyval.boolValue) = false; }
#line 1976 "dcmat.tab.c"
    break;


#line 1980 "dcmat.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 508 "dcmat.y"


void expectedDelaration(){
    std::cout << "\nSYNTAX ERROR: Incomplete Command.\n\n";
    stopPrint = true;
}

void syntaxError(){
    std::cout << "\nSYNTAX ERROR: [" << yytext << "]\n\n";   
    stopPrint = true;
}

void yyerror(const void *s) {
    if(!stopPrint){
        if(!isLexico){
            (yychar == EOL)?expectedDelaration():syntaxError(); 
        }
        else{
            isLexico = false;
        }
    }
}

void PrintUndeclareds(){
    std::cout << "\n";
    for(int i = 0; i < undeclared->vetor.size(); i++){
        std::cout << "Undefined symbol [" << undeclared->vetor[i] << "]\n";
    }
    std::cout << "\n";
    undeclared->vetor.clear(); hasUndeclared = false;
};

int main(int argc, char **argv) {
    while(1){
        if(!stopPrint)printf("> ");
        yyparse();
    }
    return 0;
}
