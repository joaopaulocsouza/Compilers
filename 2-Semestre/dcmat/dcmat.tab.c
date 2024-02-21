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

    bool isLexico = false;
    extern int yylex();
    extern char* yytext;
    extern int yychar;
    extern int yyleng;
    void yyerror(const void *s);

#line 102 "dcmat.tab.c"

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
  YYSYMBOL_Set = 57,                       /* Set  */
  YYSYMBOL_Expressao = 58,                 /* Expressao  */
  YYSYMBOL_ExpressionSumSub = 59,          /* ExpressionSumSub  */
  YYSYMBOL_ExpressionMulDiv = 60,          /* ExpressionMulDiv  */
  YYSYMBOL_ExpressionPowRem = 61,          /* ExpressionPowRem  */
  YYSYMBOL_Signal = 62,                    /* Signal  */
  YYSYMBOL_Termo = 63,                     /* Termo  */
  YYSYMBOL_Value = 64,                     /* Value  */
  YYSYMBOL_NumInt = 65,                    /* NumInt  */
  YYSYMBOL_NumFloat = 66,                  /* NumFloat  */
  YYSYMBOL_Bool = 67                       /* Bool  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   120

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  112

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
       0,   111,   111,   112,   113,   115,   116,   117,   118,   126,
     127,   139,   143,   144,   147,   155,   164,   171,   179,   187,
     190,   193,   198,   200,   203,   206,   208,   211,   214,   216,
     219,   222,   224,   225,   226,   232,   239,   240,   246,   252,
     258,   265,   266,   267,   270,   271,   272,   276,   280,   282,
     283
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
  "EOL", "$accept", "Dcmat", "Command", "Set", "Expressao",
  "ExpressionSumSub", "ExpressionMulDiv", "ExpressionPowRem", "Signal",
  "Termo", "Value", "NumInt", "NumFloat", "Bool", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-46)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      25,    61,    61,    -2,    -5,     7,    10,    14,   -46,   -46,
     -46,    -6,   -32,   -13,    36,   -12,   -38,    42,   -46,   -46,
       6,   -46,    57,     9,   -46,   -46,    20,    21,    33,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,    55,   -46,    -2,    -2,
      54,    -2,   -46,   -46,    58,    -2,    40,    43,    53,    -2,
      41,    -2,   -46,    76,    77,    -2,    -2,   -46,   -46,   -46,
      -2,    -2,    -2,    -2,    -2,    -2,   -46,    88,    89,    90,
      91,   -46,    93,   -46,   -46,    81,    40,    56,    92,    94,
      95,   -46,   -46,    97,    98,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,    99,   100,   -46,   -46,   101,   102,    -2,
     -46,    -2,   -46,   -46,   -46,   -46,   -46,   -46,   103,   104,
     -46,   -46
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    45,    46,
      44,     0,     0,     0,     0,     0,     0,     0,    47,    48,
      35,     2,     0,     0,    13,    22,    25,    28,    31,    32,
      36,    41,    42,    35,    33,    34,     0,     8,     0,     0,
       0,     0,    15,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,     0,     0,     0,    10,     1,     4,
       0,     0,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     7,     0,    50,    49,     0,     0,     0,     0,     0,
       0,     6,     5,     0,     0,    23,    24,    26,    27,    29,
      30,    40,    38,     0,     0,    37,    19,     0,     0,     0,
      21,     0,    39,    11,    12,    14,    20,    16,     0,     0,
      17,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -46,   -46,   -46,   -46,    -3,    24,    19,    22,   -45,    87,
     -46,   -46,   -46,    28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    22,    23,    52,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    75
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,     1,     2,    41,    78,    53,    80,     3,    46,    54,
      42,    37,    47,    48,    49,    50,    38,     5,    56,    39,
       6,    43,    57,    60,    61,    40,    62,    63,     1,     2,
      44,     8,     9,    10,     3,    67,    68,    51,    70,    14,
      64,    65,    72,     4,     5,    45,    17,     6,    18,    19,
      33,    55,    83,    84,   108,     7,   109,    58,     8,     9,
      10,    11,    59,    12,    13,    66,    14,    15,    69,    16,
       3,    73,    74,    17,    71,    18,    19,    20,    21,    76,
       5,    87,    88,     6,    85,    86,    89,    90,    34,    35,
      77,    79,    81,    82,     8,     9,    10,    96,    91,    92,
      93,    94,    14,    95,    97,    99,    98,   102,   101,    17,
     100,    18,    19,    33,   103,   104,   105,   106,   107,   110,
     111
};

static const yytype_int8 yycheck[] =
{
       3,     3,     4,     9,    49,    43,    51,     9,    20,    47,
      16,    16,    24,    25,    26,    27,     9,    19,    12,     9,
      22,    53,    16,     3,     4,    11,     5,     6,     3,     4,
      43,    33,    34,    35,     9,    38,    39,    49,    41,    41,
       7,     8,    45,    18,    19,     9,    48,    22,    50,    51,
      52,     9,    55,    56,    99,    30,   101,     0,    33,    34,
      35,    36,    53,    38,    39,    10,    41,    42,    14,    44,
       9,    31,    32,    48,    16,    50,    51,    52,    53,    36,
      19,    62,    63,    22,    60,    61,    64,    65,     1,     2,
      37,    50,    16,    16,    33,    34,    35,    16,    10,    10,
      10,    10,    41,    10,    76,    13,    50,    10,    13,    48,
      16,    50,    51,    52,    16,    16,    16,    16,    16,    16,
      16
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     9,    18,    19,    22,    30,    33,    34,
      35,    36,    38,    39,    41,    42,    44,    48,    50,    51,
      52,    53,    55,    56,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    52,    63,    63,    58,    16,     9,     9,
      11,     9,    16,    53,    43,     9,    20,    24,    25,    26,
      27,    49,    57,    43,    47,     9,    12,    16,     0,    53,
       3,     4,     5,     6,     7,     8,    10,    58,    58,    14,
      58,    16,    58,    31,    32,    67,    36,    37,    62,    50,
      62,    16,    16,    58,    58,    59,    59,    60,    60,    61,
      61,    10,    10,    10,    10,    10,    16,    67,    50,    13,
      16,    13,    10,    16,    16,    16,    16,    16,    62,    62,
      16,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    57,    57,    57,    57,
      57,    57,    58,    59,    59,    59,    60,    60,    60,    61,
      61,    61,    62,    62,    62,    63,    63,    63,    63,    63,
      63,    64,    64,    64,    64,    64,    64,    65,    66,    67,
      67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     3,     3,     3,     2,     2,
       2,     4,     5,     1,     5,     2,     4,     5,     5,     3,
       4,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     1,     2,     2,     1,     1,     4,     4,     4,
       4,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1
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
#line 111 "dcmat.y"
           {return 0;}
#line 1230 "dcmat.tab.c"
    break;

  case 3: /* Dcmat: QUIT EOL  */
#line 112 "dcmat.y"
               {exit(0);}
#line 1236 "dcmat.tab.c"
    break;

  case 4: /* Dcmat: Command EOL  */
#line 113 "dcmat.y"
                  {return 0;}
#line 1242 "dcmat.tab.c"
    break;

  case 5: /* Command: SHOW SYMBOLS SEMICOLON  */
#line 115 "dcmat.y"
                                {dcmat.ShowSymbols();}
#line 1248 "dcmat.tab.c"
    break;

  case 6: /* Command: SHOW SETTINGS SEMICOLON  */
#line 116 "dcmat.y"
                              {dcmat.ShowSettings();}
#line 1254 "dcmat.tab.c"
    break;

  case 7: /* Command: RESET SETTINGS SEMICOLON  */
#line 117 "dcmat.y"
                               {dcmat.ResetSettings();}
#line 1260 "dcmat.tab.c"
    break;

  case 8: /* Command: ABOUT SEMICOLON  */
#line 118 "dcmat.y"
                      {
        printf("+----------------------------------------------+\n");
        printf("|"); for(int i = 0; i < 46; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(int i = 0; i < 17; i++) {printf(" ");};  printf("201800560120"); for(int i = 0; i < 17; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(int i = 0; i < 9; i++) {printf(" ");};  printf("João Paulo Cardoso de Souza"); for(int i = 0; i < 10; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(int i = 0; i < 46; i++) {printf(" ");}; printf("|\n");
        printf("+----------------------------------------------+\n\n");
    }
#line 1273 "dcmat.tab.c"
    break;

  case 10: /* Command: IDENTIFIER SEMICOLON  */
#line 127 "dcmat.y"
                           {
        result = dcmat.FindHashItem((yyvsp[-1].stringValue));
        if(result.exists){
            if(result.type == INT_KEY){
                std::cout << (yyvsp[-1].stringValue) << " = " << result.value->value << "\n";
            }else if(result.type == FLOAT_KEY){
                printf("%s = %.*f\n", (yyvsp[-1].stringValue), precision, result.value->value);
            }
        }else{
            std::cout << "Undefined symbol\n";
        }
    }
#line 1290 "dcmat.tab.c"
    break;

  case 11: /* Command: IDENTIFIER ASSIGN Expressao SEMICOLON  */
#line 139 "dcmat.y"
                                            {
         Expressao *exp = (yyvsp[-1].expValue);
         dcmat.CreateHashItem((yyvsp[-3].stringValue), exp, exp->type);
    }
#line 1299 "dcmat.tab.c"
    break;

  case 13: /* Command: Expressao  */
#line 144 "dcmat.y"
                { Expressao *exp = (yyvsp[0].expValue); 
        if(exp->element != FUNCTION_KEY){std::cout << std::fixed << std::setprecision(precision) << exp->value << "\n"; }
        else{ std::cout << "funcao: "<< expressao.CalcFunctionValue(5, exp) << std::endl;}}
#line 1307 "dcmat.tab.c"
    break;

  case 14: /* Command: PLOT L_PAREN Expressao R_PAREN SEMICOLON  */
#line 147 "dcmat.y"
                                               {
        if((yyvsp[-2].expValue)->element == FUNCTION_KEY){
            function = (yyvsp[-2].expValue);
            dcmat.PlotChart(function);
        }else{
            std::cout << "No Function defined!\n";
        }
    }
#line 1320 "dcmat.tab.c"
    break;

  case 15: /* Command: PLOT SEMICOLON  */
#line 155 "dcmat.y"
                     {
        if(function){
            dcmat.PlotChart(function);
        }else{
            std::cout << "No Function defined!\n";
        }
    }
#line 1332 "dcmat.tab.c"
    break;

  case 16: /* Set: FLOAT PRECISION INT SEMICOLON  */
#line 164 "dcmat.y"
                                          {
        if((yyvsp[-1].integerValue) <= 8 && (yyvsp[-1].integerValue) >= 0){
            precision = (yyvsp[-1].integerValue);
        }else{
            printf("ERROR: float precision must be from 0 to 8\n");
        }
        }
#line 1344 "dcmat.tab.c"
    break;

  case 17: /* Set: H_VIEW Signal COLON Signal SEMICOLON  */
#line 171 "dcmat.y"
                                           {
            if((yyvsp[-3].expValue)->value < (yyvsp[-1].expValue)->value){
                h_view_lo = (yyvsp[-3].expValue)->value;
                h_view_hi = (yyvsp[-1].expValue)->value;
            }else{
                printf("ERROR: h_view_lo must be smaller than h_view_hi\n");
            }
        }
#line 1357 "dcmat.tab.c"
    break;

  case 18: /* Set: V_VIEW Signal COLON Signal SEMICOLON  */
#line 179 "dcmat.y"
                                           {
            if((yyvsp[-3].expValue)->value < (yyvsp[-1].expValue)->value){
                v_view_lo = (yyvsp[-3].expValue)->value;
                v_view_hi = (yyvsp[-1].expValue)->value;
            }else{
                printf("ERROR: v_view_lo must be smaller than v_view_hi\n");
            }
        }
#line 1370 "dcmat.tab.c"
    break;

  case 19: /* Set: AXIS Bool SEMICOLON  */
#line 187 "dcmat.y"
                          {
            Axis = (yyvsp[-1].boolValue);
        }
#line 1378 "dcmat.tab.c"
    break;

  case 20: /* Set: ERASE PLOT Bool SEMICOLON  */
#line 190 "dcmat.y"
                                {
            Erase_Plot = (yyvsp[-1].boolValue);
        }
#line 1386 "dcmat.tab.c"
    break;

  case 21: /* Set: INTEGRAL_STEPS INT SEMICOLON  */
#line 193 "dcmat.y"
                                   {
            integral_steps = (yyvsp[-1].integerValue);
        }
#line 1394 "dcmat.tab.c"
    break;

  case 22: /* Expressao: ExpressionSumSub  */
#line 198 "dcmat.y"
                            {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1400 "dcmat.tab.c"
    break;

  case 23: /* ExpressionSumSub: ExpressionMulDiv ADD ExpressionSumSub  */
#line 200 "dcmat.y"
                                                        {
                        (yyval.expValue) = expressao.CreateExp(ADD_KEY, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1408 "dcmat.tab.c"
    break;

  case 24: /* ExpressionSumSub: ExpressionMulDiv SUBTRACT ExpressionSumSub  */
#line 203 "dcmat.y"
                                                             {
                        (yyval.expValue) = expressao.CreateExp(SUB_KEY, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1416 "dcmat.tab.c"
    break;

  case 25: /* ExpressionSumSub: ExpressionMulDiv  */
#line 206 "dcmat.y"
                                   {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1422 "dcmat.tab.c"
    break;

  case 26: /* ExpressionMulDiv: ExpressionPowRem MULTIPLY ExpressionMulDiv  */
#line 208 "dcmat.y"
                                                             {
                        (yyval.expValue) = expressao.CreateExp(MULTIPLY_KEY, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1430 "dcmat.tab.c"
    break;

  case 27: /* ExpressionMulDiv: ExpressionPowRem DIV ExpressionMulDiv  */
#line 211 "dcmat.y"
                                                        {
                        (yyval.expValue) = expressao.CreateExp(DIV_KEY, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1438 "dcmat.tab.c"
    break;

  case 28: /* ExpressionMulDiv: ExpressionPowRem  */
#line 214 "dcmat.y"
                                   {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1444 "dcmat.tab.c"
    break;

  case 29: /* ExpressionPowRem: Signal POW ExpressionPowRem  */
#line 216 "dcmat.y"
                                              {
                        (yyval.expValue) = expressao.CreateExp(POW_KEY, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1452 "dcmat.tab.c"
    break;

  case 30: /* ExpressionPowRem: Signal REST ExpressionPowRem  */
#line 219 "dcmat.y"
                                               {
                        (yyval.expValue) = expressao.CreateExp(REST, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1460 "dcmat.tab.c"
    break;

  case 31: /* ExpressionPowRem: Signal  */
#line 222 "dcmat.y"
                         {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1466 "dcmat.tab.c"
    break;

  case 32: /* Signal: Termo  */
#line 224 "dcmat.y"
              {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1472 "dcmat.tab.c"
    break;

  case 33: /* Signal: ADD Termo  */
#line 225 "dcmat.y"
                    {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1478 "dcmat.tab.c"
    break;

  case 34: /* Signal: SUBTRACT Termo  */
#line 226 "dcmat.y"
                         {
            if((yyvsp[0].expValue)->type == VAR_KEY) (yyvsp[0].expValue)->type = SUBVAR_KEY;
            if((yyvsp[0].expValue)->element != FUNCTION_KEY) (yyvsp[0].expValue)->value = -(yyvsp[0].expValue)->value;
            (yyval.expValue) = (yyvsp[0].expValue);
        }
#line 1488 "dcmat.tab.c"
    break;

  case 35: /* Termo: IDENTIFIER  */
#line 232 "dcmat.y"
                  {
            result = dcmat.FindHashItem((yyvsp[0].stringValue));
            if(result.exists){
               (yyval.expValue) = result.value;
            }else{
                std::cout << "Undefined symbol [" << (yyvsp[0].stringValue) << "]\n";
            }}
#line 1500 "dcmat.tab.c"
    break;

  case 36: /* Termo: Value  */
#line 239 "dcmat.y"
                {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1506 "dcmat.tab.c"
    break;

  case 37: /* Termo: SEN L_PAREN Expressao R_PAREN  */
#line 240 "dcmat.y"
                                        { 
                float value = 0;
                int element = (yyvsp[-1].expValue)->element;
                if((yyvsp[-1].expValue)->element != FUNCTION_KEY)value = sin((yyvsp[-1].expValue)->value);
                (yyval.expValue) = expressao.CreateSheet((yyvsp[-1].expValue)->type, SEN_KEY, value, (yyvsp[-1].expValue), element);
            }
#line 1517 "dcmat.tab.c"
    break;

  case 38: /* Termo: COS L_PAREN Expressao R_PAREN  */
#line 246 "dcmat.y"
                                         { 
                float value = 0;
                int element = (yyvsp[-1].expValue)->element;
                if((yyvsp[-1].expValue)->element != FUNCTION_KEY) value = cos((yyvsp[-1].expValue)->value);
                (yyval.expValue) = expressao.CreateSheet((yyvsp[-1].expValue)->type, COS_KEY, value, (yyvsp[-1].expValue), element);
            }
#line 1528 "dcmat.tab.c"
    break;

  case 39: /* Termo: TAN L_PAREN Expressao R_PAREN  */
#line 252 "dcmat.y"
                                         { 
                float value = 0;
                int element = (yyvsp[-1].expValue)->element;
                if((yyvsp[-1].expValue)->element != FUNCTION_KEY) value = tan((yyvsp[-1].expValue)->value);
                (yyval.expValue) = expressao.CreateSheet((yyvsp[-1].expValue)->type, TAN_KEY, value, (yyvsp[-1].expValue), element);
            }
#line 1539 "dcmat.tab.c"
    break;

  case 40: /* Termo: ABS L_PAREN Expressao R_PAREN  */
#line 258 "dcmat.y"
                                        { 
                float value = 0;
                int element = (yyvsp[-1].expValue)->element;
                if((yyvsp[-1].expValue)->element != FUNCTION_KEY) value = abs((yyvsp[-1].expValue)->value);
                (yyval.expValue) = expressao.CreateSheet((yyvsp[-1].expValue)->type, ABS_KEY, value, (yyvsp[-1].expValue), element);
            }
#line 1550 "dcmat.tab.c"
    break;

  case 41: /* Value: NumInt  */
#line 265 "dcmat.y"
              { (yyval.expValue) = expressao.CreateSheet(INT_KEY, OP, (yyvsp[0].integerValue), nullptr); }
#line 1556 "dcmat.tab.c"
    break;

  case 42: /* Value: NumFloat  */
#line 266 "dcmat.y"
               { (yyval.expValue) = expressao.CreateSheet(FLOAT_KEY, OP, (yyvsp[0].floatValue), nullptr); }
#line 1562 "dcmat.tab.c"
    break;

  case 43: /* Value: L_PAREN Expressao R_PAREN  */
#line 267 "dcmat.y"
                                { 
        int element = (yyvsp[-1].expValue)->element;
        (yyval.expValue) = expressao.CreateSheet((yyvsp[-1].expValue)->type, EXP_KEY, (yyvsp[-1].expValue)->value, (yyvsp[-1].expValue), element) ;}
#line 1570 "dcmat.tab.c"
    break;

  case 44: /* Value: VAR  */
#line 270 "dcmat.y"
          {(yyval.expValue) = expressao.CreateSheet(VAR_KEY, OP, 0, nullptr); }
#line 1576 "dcmat.tab.c"
    break;

  case 45: /* Value: PI  */
#line 271 "dcmat.y"
         { (yyval.expValue) = expressao.CreateSheet(FLOAT_KEY, OP, pi, nullptr); }
#line 1582 "dcmat.tab.c"
    break;

  case 46: /* Value: E  */
#line 272 "dcmat.y"
         { (yyval.expValue) = expressao.CreateSheet(FLOAT_KEY, OP, euler, nullptr); }
#line 1588 "dcmat.tab.c"
    break;

  case 47: /* NumInt: INT  */
#line 276 "dcmat.y"
              {
            (yyval.integerValue) = (yyvsp[0].integerValue);
        }
#line 1596 "dcmat.tab.c"
    break;

  case 48: /* NumFloat: REAL  */
#line 280 "dcmat.y"
               { (yyval.floatValue) = (yyvsp[0].floatValue); }
#line 1602 "dcmat.tab.c"
    break;

  case 49: /* Bool: ON  */
#line 282 "dcmat.y"
         { (yyval.boolValue) = true; }
#line 1608 "dcmat.tab.c"
    break;

  case 50: /* Bool: OFF  */
#line 283 "dcmat.y"
          { (yyval.boolValue) = false; }
#line 1614 "dcmat.tab.c"
    break;


#line 1618 "dcmat.tab.c"

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

#line 285 "dcmat.y"


void expectedDelaration(){
     std::cout << "SYNTAX ERROR: Incomplete Command\n";
    return;
}

void syntaxError(){
    std::cout << "SYNTAX ERROR: " << yytext << "\n";
}

void yyerror(const void *s) {

    if(!isLexico){
        (yychar == 0)?expectedDelaration():syntaxError(); 
    }
    else{
        isLexico = false;
    }

    return;
}

int main(int argc, char **argv) {
    while(1){
        printf("> ");
        yyparse();
    }
    return 0;
}
