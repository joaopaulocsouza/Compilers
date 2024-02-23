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

    bool isLexico = false;
    extern int yylex();
    extern char* yytext;
    extern int yychar;
    extern int yyleng;
    void yyerror(const void *s);

#line 103 "dcmat.tab.c"

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
#define YYFINAL  62
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   216

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

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
       0,   119,   119,   120,   121,   123,   124,   125,   131,   132,
     140,   141,   156,   160,   165,   177,   189,   200,   210,   218,
     226,   242,   253,   255,   266,   277,   280,   287,   295,   303,
     306,   309,   314,   316,   319,   322,   324,   327,   330,   332,
     335,   338,   340,   341,   342,   348,   355,   356,   362,   368,
     374,   381,   382,   383,   384,   385,   386,   388,   389,   390,
     393,   394,   395,   399,   403,   405,   406
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

#define YYPACT_NINF (-52)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      73,   164,   164,   144,     6,    10,    18,    28,   -52,   -52,
     -52,     2,   -18,    -1,    37,   -11,   -22,    -6,    43,   -52,
     -52,     8,   -52,    64,    19,   -52,    26,    39,    24,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,    65,   -52,   144,
     144,    60,   144,   -52,   -52,    67,   144,    17,    44,    47,
       3,    31,     3,   -52,    69,    72,    78,    80,    81,   144,
     124,   -52,   -52,   -52,   144,   144,   144,   144,   144,   144,
     -52,    79,    83,    84,    85,    89,   -52,    90,   -52,   -52,
      86,    17,    54,     0,     0,    92,   -52,   -52,    94,   100,
     -52,   -52,   -52,   -52,   -52,   106,   103,   104,    39,    39,
      24,    24,   -52,   -52,   -52,   -52,     3,   -52,   -52,   113,
     -52,   -52,   114,   115,   -52,   -52,   -52,   -52,     3,   -52,
       3,   -52,   -52,   -52,   -52,    -5,   -52,   -52,   -52,   116,
     118,    11,   -52,    84,   -52,   -52,   -52,     3,   -52,   -52
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    61,    62,
      60,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    45,     2,     0,     0,    17,    32,    35,    38,    41,
      42,    46,    57,    58,    45,    43,    44,     0,     9,     0,
       0,     0,     0,    19,     3,     0,     0,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,    11,     1,     4,     0,     0,     0,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     8,     0,    66,    65,
       0,     0,     0,     0,     0,     0,    54,    51,     0,     0,
       7,     6,     5,    15,    16,     0,     0,     0,    33,    34,
      36,    37,    39,    40,    50,    48,     0,    22,    14,     0,
      47,    29,     0,     0,    55,    52,    56,    53,     0,    31,
       0,    49,    13,    12,    25,     0,    18,    30,    26,     0,
       0,     0,    20,     0,    27,    28,    23,     0,    21,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,   -52,    62,   -52,     4,   -52,   -52,     1,   -52,
      -7,    -4,    -3,    77,   -51,   -52,   -50,   -47,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    23,    24,    74,   125,   107,   131,    53,    25,    26,
      27,    28,    29,    30,    85,    31,    32,    33,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      86,    89,    86,    87,    37,    87,    83,    84,    54,    47,
     132,    42,   133,    48,    49,    50,    51,    57,    43,    39,
      60,    55,    38,    58,    61,    56,   136,    40,   137,    64,
      65,    68,    69,   114,   116,    44,   115,   117,    52,    41,
      71,    72,    45,    75,    66,    67,    46,    77,    78,    79,
      19,    20,    59,    19,    20,   124,    86,    98,    99,    87,
      95,    97,   100,   101,    62,   102,   103,   129,    86,   130,
      86,    87,    63,    87,    73,    70,     1,     2,    35,    36,
      81,    88,     3,    76,    82,    90,   139,    86,    91,   104,
      87,     4,     5,   105,    92,     6,    93,    94,   106,   109,
     110,   108,   111,     7,   113,   118,     8,     9,    10,    11,
     119,    12,    13,   120,    14,    15,   121,    16,    17,   122,
     123,    18,    96,    19,    20,    21,    22,     1,     2,   126,
     127,   128,   134,     3,   135,     0,   112,   138,    73,     0,
       0,     0,     0,     5,     0,     0,     6,     1,     2,     0,
       0,     0,     0,     3,     0,     0,     0,     8,     9,    10,
       0,     0,     0,     5,     0,    14,     6,     0,     0,     0,
       0,     0,    18,     3,    19,    20,    34,     8,     9,    10,
       0,     0,     0,     5,     0,    14,     6,     0,     0,     0,
       0,     0,    18,     0,    19,    20,    34,     8,     9,    10,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
       0,     0,    18,     0,    19,    20,    34
};

static const yytype_int16 yycheck[] =
{
      50,    52,    52,    50,     3,    52,     3,     4,    30,    20,
      15,     9,    17,    24,    25,    26,    27,    23,    16,     9,
      12,    43,    16,    29,    16,    47,    15,     9,    17,     3,
       4,     7,     8,    83,    84,    53,    83,    84,    49,    11,
      39,    40,    43,    42,     5,     6,     9,    46,    31,    32,
      50,    51,     9,    50,    51,   106,   106,    64,    65,   106,
      59,    60,    66,    67,     0,    68,    69,   118,   118,   120,
     120,   118,    53,   120,    14,    10,     3,     4,     1,     2,
      36,    50,     9,    16,    37,    16,   137,   137,    16,    10,
     137,    18,    19,    10,    16,    22,    16,    16,    14,    10,
      10,    16,    16,    30,    50,    13,    33,    34,    35,    36,
      16,    38,    39,    13,    41,    42,    10,    44,    45,    16,
      16,    48,    60,    50,    51,    52,    53,     3,     4,    16,
      16,    16,    16,     9,    16,    -1,    81,   133,    14,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    22,     3,     4,    -1,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    19,    -1,    41,    22,    -1,    -1,    -1,
      -1,    -1,    48,     9,    50,    51,    52,    33,    34,    35,
      -1,    -1,    -1,    19,    -1,    41,    22,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     9,    18,    19,    22,    30,    33,    34,
      35,    36,    38,    39,    41,    42,    44,    45,    48,    50,
      51,    52,    53,    55,    56,    62,    63,    64,    65,    66,
      67,    69,    70,    71,    52,    67,    67,    62,    16,     9,
       9,    11,     9,    16,    53,    43,     9,    20,    24,    25,
      26,    27,    49,    61,    30,    43,    47,    23,    29,     9,
      12,    16,     0,    53,     3,     4,     5,     6,     7,     8,
      10,    62,    62,    14,    57,    62,    16,    62,    31,    32,
      72,    36,    37,     3,     4,    68,    70,    71,    50,    68,
      16,    16,    16,    16,    16,    62,    57,    62,    64,    64,
      65,    65,    66,    66,    10,    10,    14,    59,    16,    10,
      10,    16,    72,    50,    70,    71,    70,    71,    13,    16,
      13,    10,    16,    16,    68,    58,    16,    16,    16,    68,
      68,    60,    15,    17,    16,    16,    15,    17,    59,    68
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    58,    58,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    62,    63,    63,    63,    64,    64,    64,    65,
      65,    65,    66,    66,    66,    67,    67,    67,    67,    67,
      67,    68,    68,    68,    68,    68,    68,    69,    69,    69,
      69,    69,    69,    70,    71,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     3,     3,     3,     3,     2,
       2,     2,     4,     4,     4,     3,     3,     1,     5,     2,
       4,     3,     0,     4,     3,     0,     4,     5,     5,     3,
       4,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     1,     2,     2,     1,     1,     4,     4,     4,
       4,     1,     2,     2,     1,     2,     2,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1
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
#line 119 "dcmat.y"
           {return 0;}
#line 1264 "dcmat.tab.c"
    break;

  case 3: /* Dcmat: QUIT EOL  */
#line 120 "dcmat.y"
               {exit(0);}
#line 1270 "dcmat.tab.c"
    break;

  case 4: /* Dcmat: Command EOL  */
#line 121 "dcmat.y"
                  {return 0;}
#line 1276 "dcmat.tab.c"
    break;

  case 5: /* Command: SHOW SYMBOLS SEMICOLON  */
#line 123 "dcmat.y"
                                {dcmat.ShowSymbols();}
#line 1282 "dcmat.tab.c"
    break;

  case 6: /* Command: SHOW SETTINGS SEMICOLON  */
#line 124 "dcmat.y"
                              {dcmat.ShowSettings();}
#line 1288 "dcmat.tab.c"
    break;

  case 7: /* Command: SHOW MATRIX SEMICOLON  */
#line 125 "dcmat.y"
                            {
        if(matrix != nullptr){
            dcmat.ShowMatrix(matrix->matrix);}
        else {
            std::cout << "No Matrix defined!\n";
            }}
#line 1299 "dcmat.tab.c"
    break;

  case 8: /* Command: RESET SETTINGS SEMICOLON  */
#line 131 "dcmat.y"
                               {dcmat.ResetSettings();}
#line 1305 "dcmat.tab.c"
    break;

  case 9: /* Command: ABOUT SEMICOLON  */
#line 132 "dcmat.y"
                      {
        printf("+----------------------------------------------+\n");
        printf("|"); for(int i = 0; i < 46; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(int i = 0; i < 17; i++) {printf(" ");};  printf("201800560120"); for(int i = 0; i < 17; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(int i = 0; i < 9; i++) {printf(" ");};  printf("João Paulo Cardoso de Souza"); for(int i = 0; i < 10; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(int i = 0; i < 46; i++) {printf(" ");}; printf("|\n");
        printf("+----------------------------------------------+\n\n");
    }
#line 1318 "dcmat.tab.c"
    break;

  case 11: /* Command: IDENTIFIER SEMICOLON  */
#line 141 "dcmat.y"
                           {
        result = dcmat.FindHashItem((yyvsp[-1].stringValue));
        if(result.exists){
            if(result.type == MATRIX_KEY){
                dcmat.ShowMatrix(result.value->matrix);
            }
            else if(result.type == INT_KEY){
                std::cout << (yyvsp[-1].stringValue) << " = " << result.value->value << "\n";
            }else if(result.type == FLOAT_KEY){
                printf("%s = %.*f\n", (yyvsp[-1].stringValue), precision, result.value->value);
            }
        }else{
            std::cout << "Undefined symbol\n";
        }
    }
#line 1338 "dcmat.tab.c"
    break;

  case 12: /* Command: IDENTIFIER ASSIGN Expressao SEMICOLON  */
#line 156 "dcmat.y"
                                            {
         Expressao *exp = (yyvsp[-1].expValue);
         dcmat.CreateHashItem((yyvsp[-3].stringValue), exp, exp->type);
    }
#line 1347 "dcmat.tab.c"
    break;

  case 13: /* Command: IDENTIFIER ASSIGN Matrix SEMICOLON  */
#line 160 "dcmat.y"
                                        {
        Expressao *exp = expressao.CreateMatrix((yyvsp[-1].matrixValue));
        dcmat.CreateHashItem((yyvsp[-3].stringValue), exp, MATRIX_KEY);
        dcmat.ShowMatrix((yyvsp[-1].matrixValue));
    }
#line 1357 "dcmat.tab.c"
    break;

  case 14: /* Command: MATRIX EQUAL Matrix SEMICOLON  */
#line 165 "dcmat.y"
                                   {
        if((yyvsp[-1].matrixValue)->lines > 10 || (yyvsp[-1].matrixValue)->columns > 10){
            std::cout << "ERROR: Matrix limits out of boundaries." << std::endl;
        }else{
            if(matrix){
                matrix->matrix = (yyvsp[-1].matrixValue);
            }else{
                Expressao *exp = expressao.CreateMatrix((yyvsp[-1].matrixValue));
                matrix = exp;
            }
        }
    }
#line 1374 "dcmat.tab.c"
    break;

  case 15: /* Command: SOLVE DETERMINANT SEMICOLON  */
#line 177 "dcmat.y"
                                  {
        if(matrix){
            if(matrix->matrix->lines != matrix->matrix->columns){
                std::cout << "Matrix format incorrect!\n";
            }else{
                float det = dcmat.SolveDeterminant(matrix->matrix);
                std::cout << std::fixed << std::setprecision(precision) << det << std::endl;
            }
        }else{
            std::cout << "No Function defined!\n";
        }
    }
#line 1391 "dcmat.tab.c"
    break;

  case 16: /* Command: SOLVE LINEAR_SYSTEM SEMICOLON  */
#line 189 "dcmat.y"
                                    {
        if(matrix){
            if(matrix->matrix->lines != matrix->matrix->columns-1){
                std::cout << "Matrix format incorrect!\n";
            }else{
                dcmat.SolveLinearSystem(matrix->matrix);
            }
        }else{
            std::cout << "No Function defined!\n";
        }
    }
#line 1407 "dcmat.tab.c"
    break;

  case 17: /* Command: Expressao  */
#line 200 "dcmat.y"
                { Expressao *exp = (yyvsp[0].expValue); 
        if(exp->element != FUNCTION_KEY){
            if(exp->type == MATRIX_KEY){
                dcmat.ShowMatrix(exp->matrix);
            }else{

            std::cout << std::fixed << std::setprecision(precision) << exp->value << "\n"; 
            }
        }
        else{ std::cout << "funcao: "<< expressao.CalcFunctionValue(5, exp) << std::endl;}}
#line 1422 "dcmat.tab.c"
    break;

  case 18: /* Command: PLOT L_PAREN Expressao R_PAREN SEMICOLON  */
#line 210 "dcmat.y"
                                               {
        if((yyvsp[-2].expValue)->element == FUNCTION_KEY){
            function = (yyvsp[-2].expValue);
            dcmat.PlotChart(function);
        }else{
            std::cout << "No Function defined!\n";
        }
    }
#line 1435 "dcmat.tab.c"
    break;

  case 19: /* Command: PLOT SEMICOLON  */
#line 218 "dcmat.y"
                     {
        if(function){
            dcmat.PlotChart(function);
        }else{
            std::cout << "No Function defined!\n";
        }
    }
#line 1447 "dcmat.tab.c"
    break;

  case 20: /* Matrix: L_SQUARE_BRACKET MatrixLine MatrixColum R_SQUARE_BRACKET  */
#line 227 "dcmat.y"
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
#line 1466 "dcmat.tab.c"
    break;

  case 21: /* MatrixColum: MatrixColum COMMA MatrixLine  */
#line 242 "dcmat.y"
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
#line 1482 "dcmat.tab.c"
    break;

  case 22: /* MatrixColum: %empty  */
#line 253 "dcmat.y"
          {(yyval.matrixValue) = nullptr;}
#line 1488 "dcmat.tab.c"
    break;

  case 23: /* MatrixLine: L_SQUARE_BRACKET Limit MatrixValue R_SQUARE_BRACKET  */
#line 255 "dcmat.y"
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
#line 1503 "dcmat.tab.c"
    break;

  case 24: /* MatrixValue: MatrixValue COMMA Limit  */
#line 266 "dcmat.y"
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
#line 1519 "dcmat.tab.c"
    break;

  case 25: /* MatrixValue: %empty  */
#line 277 "dcmat.y"
          {(yyval.matrixValue) = nullptr;}
#line 1525 "dcmat.tab.c"
    break;

  case 26: /* Set: FLOAT PRECISION INT SEMICOLON  */
#line 280 "dcmat.y"
                                          {
        if((yyvsp[-1].integerValue) <= 8 && (yyvsp[-1].integerValue) >= 0){
            precision = (yyvsp[-1].integerValue);
        }else{
            printf("ERROR: float precision must be from 0 to 8\n");
        }
        }
#line 1537 "dcmat.tab.c"
    break;

  case 27: /* Set: H_VIEW Limit COLON Limit SEMICOLON  */
#line 287 "dcmat.y"
                                         {
            if((yyvsp[-3].floatValue) < (yyvsp[-1].floatValue)){
                h_view_lo = (yyvsp[-3].floatValue);
                h_view_hi = (yyvsp[-1].floatValue);
            }else{
                printf("ERROR: h_view_lo must be smaller than h_view_hi\n");
            }
        }
#line 1550 "dcmat.tab.c"
    break;

  case 28: /* Set: V_VIEW Limit COLON Limit SEMICOLON  */
#line 295 "dcmat.y"
                                         {
            if((yyvsp[-3].floatValue) < (yyvsp[-1].floatValue)){
                v_view_lo = (yyvsp[-3].floatValue);
                v_view_hi = (yyvsp[-1].floatValue);
            }else{
                printf("ERROR: v_view_lo must be smaller than v_view_hi\n");
            }
        }
#line 1563 "dcmat.tab.c"
    break;

  case 29: /* Set: AXIS Bool SEMICOLON  */
#line 303 "dcmat.y"
                          {
            Axis = (yyvsp[-1].boolValue);
        }
#line 1571 "dcmat.tab.c"
    break;

  case 30: /* Set: ERASE PLOT Bool SEMICOLON  */
#line 306 "dcmat.y"
                                {
            Erase_Plot = (yyvsp[-1].boolValue);
        }
#line 1579 "dcmat.tab.c"
    break;

  case 31: /* Set: INTEGRAL_STEPS INT SEMICOLON  */
#line 309 "dcmat.y"
                                   {
            integral_steps = (yyvsp[-1].integerValue);
        }
#line 1587 "dcmat.tab.c"
    break;

  case 32: /* Expressao: ExpressionSumSub  */
#line 314 "dcmat.y"
                            {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1593 "dcmat.tab.c"
    break;

  case 33: /* ExpressionSumSub: ExpressionSumSub ADD ExpressionMulDiv  */
#line 316 "dcmat.y"
                                                        {
                        (yyval.expValue) = expressao.CreateExp(ADD_KEY, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1601 "dcmat.tab.c"
    break;

  case 34: /* ExpressionSumSub: ExpressionSumSub SUBTRACT ExpressionMulDiv  */
#line 319 "dcmat.y"
                                                             {
                        (yyval.expValue) = expressao.CreateExp(SUB_KEY, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1609 "dcmat.tab.c"
    break;

  case 35: /* ExpressionSumSub: ExpressionMulDiv  */
#line 322 "dcmat.y"
                                   {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1615 "dcmat.tab.c"
    break;

  case 36: /* ExpressionMulDiv: ExpressionMulDiv MULTIPLY ExpressionPowRem  */
#line 324 "dcmat.y"
                                                             {
                        (yyval.expValue) = expressao.CreateExp(MULTIPLY_KEY, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1623 "dcmat.tab.c"
    break;

  case 37: /* ExpressionMulDiv: ExpressionMulDiv DIV ExpressionPowRem  */
#line 327 "dcmat.y"
                                                        {
                        (yyval.expValue) = expressao.CreateExp(DIV_KEY, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1631 "dcmat.tab.c"
    break;

  case 38: /* ExpressionMulDiv: ExpressionPowRem  */
#line 330 "dcmat.y"
                                   {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1637 "dcmat.tab.c"
    break;

  case 39: /* ExpressionPowRem: ExpressionPowRem POW Signal  */
#line 332 "dcmat.y"
                                              {
                        (yyval.expValue) = expressao.CreateExp(POW_KEY, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1645 "dcmat.tab.c"
    break;

  case 40: /* ExpressionPowRem: ExpressionPowRem REST Signal  */
#line 335 "dcmat.y"
                                               {
                        (yyval.expValue) = expressao.CreateExp(REST, (yyvsp[-2].expValue), (yyvsp[0].expValue));    
                }
#line 1653 "dcmat.tab.c"
    break;

  case 41: /* ExpressionPowRem: Signal  */
#line 338 "dcmat.y"
                         {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1659 "dcmat.tab.c"
    break;

  case 42: /* Signal: Termo  */
#line 340 "dcmat.y"
              {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1665 "dcmat.tab.c"
    break;

  case 43: /* Signal: ADD Termo  */
#line 341 "dcmat.y"
                    {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1671 "dcmat.tab.c"
    break;

  case 44: /* Signal: SUBTRACT Termo  */
#line 342 "dcmat.y"
                         {
            if((yyvsp[0].expValue)->type == VAR_KEY) (yyvsp[0].expValue)->type = SUBVAR_KEY;
            if((yyvsp[0].expValue)->element != FUNCTION_KEY) (yyvsp[0].expValue)->value = -(yyvsp[0].expValue)->value;
            (yyval.expValue) = (yyvsp[0].expValue);
        }
#line 1681 "dcmat.tab.c"
    break;

  case 45: /* Termo: IDENTIFIER  */
#line 348 "dcmat.y"
                  {
            result = dcmat.FindHashItem((yyvsp[0].stringValue));
            if(result.exists){
               (yyval.expValue) = result.value;
            }else{
                std::cout << "Undefined symbol [" << (yyvsp[0].stringValue) << "]\n";
            }}
#line 1693 "dcmat.tab.c"
    break;

  case 46: /* Termo: Value  */
#line 355 "dcmat.y"
                {(yyval.expValue) = (yyvsp[0].expValue);}
#line 1699 "dcmat.tab.c"
    break;

  case 47: /* Termo: SEN L_PAREN Expressao R_PAREN  */
#line 356 "dcmat.y"
                                        { 
                float value = 0;
                int element = (yyvsp[-1].expValue)->element;
                if((yyvsp[-1].expValue)->element != FUNCTION_KEY)value = sin((yyvsp[-1].expValue)->value);
                (yyval.expValue) = expressao.CreateSheet((yyvsp[-1].expValue)->type, SEN_KEY, value, (yyvsp[-1].expValue), element);
            }
#line 1710 "dcmat.tab.c"
    break;

  case 48: /* Termo: COS L_PAREN Expressao R_PAREN  */
#line 362 "dcmat.y"
                                         { 
                float value = 0;
                int element = (yyvsp[-1].expValue)->element;
                if((yyvsp[-1].expValue)->element != FUNCTION_KEY) value = cos((yyvsp[-1].expValue)->value);
                (yyval.expValue) = expressao.CreateSheet((yyvsp[-1].expValue)->type, COS_KEY, value, (yyvsp[-1].expValue), element);
            }
#line 1721 "dcmat.tab.c"
    break;

  case 49: /* Termo: TAN L_PAREN Expressao R_PAREN  */
#line 368 "dcmat.y"
                                         { 
                float value = 0;
                int element = (yyvsp[-1].expValue)->element;
                if((yyvsp[-1].expValue)->element != FUNCTION_KEY) value = tan((yyvsp[-1].expValue)->value);
                (yyval.expValue) = expressao.CreateSheet((yyvsp[-1].expValue)->type, TAN_KEY, value, (yyvsp[-1].expValue), element);
            }
#line 1732 "dcmat.tab.c"
    break;

  case 50: /* Termo: ABS L_PAREN Expressao R_PAREN  */
#line 374 "dcmat.y"
                                        { 
                float value = 0;
                int element = (yyvsp[-1].expValue)->element;
                if((yyvsp[-1].expValue)->element != FUNCTION_KEY) value = abs((yyvsp[-1].expValue)->value);
                (yyval.expValue) = expressao.CreateSheet((yyvsp[-1].expValue)->type, ABS_KEY, value, (yyvsp[-1].expValue), element);
            }
#line 1743 "dcmat.tab.c"
    break;

  case 51: /* Limit: NumFloat  */
#line 381 "dcmat.y"
                {(yyval.floatValue) = (yyvsp[0].floatValue);}
#line 1749 "dcmat.tab.c"
    break;

  case 52: /* Limit: ADD NumFloat  */
#line 382 "dcmat.y"
                       {(yyval.floatValue) = (yyvsp[0].floatValue);}
#line 1755 "dcmat.tab.c"
    break;

  case 53: /* Limit: SUBTRACT NumFloat  */
#line 383 "dcmat.y"
                            { (yyval.floatValue) = -(yyvsp[0].floatValue); }
#line 1761 "dcmat.tab.c"
    break;

  case 54: /* Limit: NumInt  */
#line 384 "dcmat.y"
                 {(yyval.floatValue) = (yyvsp[0].integerValue);}
#line 1767 "dcmat.tab.c"
    break;

  case 55: /* Limit: ADD NumInt  */
#line 385 "dcmat.y"
                     {(yyval.floatValue) = (yyvsp[0].integerValue);}
#line 1773 "dcmat.tab.c"
    break;

  case 56: /* Limit: SUBTRACT NumInt  */
#line 386 "dcmat.y"
                          {(yyval.floatValue) = -(yyvsp[0].integerValue);}
#line 1779 "dcmat.tab.c"
    break;

  case 57: /* Value: NumInt  */
#line 388 "dcmat.y"
              { (yyval.expValue) = expressao.CreateSheet(INT_KEY, OP, (yyvsp[0].integerValue), nullptr); }
#line 1785 "dcmat.tab.c"
    break;

  case 58: /* Value: NumFloat  */
#line 389 "dcmat.y"
               { (yyval.expValue) = expressao.CreateSheet(FLOAT_KEY, OP, (yyvsp[0].floatValue), nullptr); }
#line 1791 "dcmat.tab.c"
    break;

  case 59: /* Value: L_PAREN Expressao R_PAREN  */
#line 390 "dcmat.y"
                                { 
        int element = (yyvsp[-1].expValue)->element;
        (yyval.expValue) = expressao.CreateSheet((yyvsp[-1].expValue)->type, EXP_KEY, (yyvsp[-1].expValue)->value, (yyvsp[-1].expValue), element) ;}
#line 1799 "dcmat.tab.c"
    break;

  case 60: /* Value: VAR  */
#line 393 "dcmat.y"
          {(yyval.expValue) = expressao.CreateSheet(VAR_KEY, OP, 0, nullptr); }
#line 1805 "dcmat.tab.c"
    break;

  case 61: /* Value: PI  */
#line 394 "dcmat.y"
         { (yyval.expValue) = expressao.CreateSheet(FLOAT_KEY, OP, pi, nullptr); }
#line 1811 "dcmat.tab.c"
    break;

  case 62: /* Value: E  */
#line 395 "dcmat.y"
         { (yyval.expValue) = expressao.CreateSheet(FLOAT_KEY, OP, euler, nullptr); }
#line 1817 "dcmat.tab.c"
    break;

  case 63: /* NumInt: INT  */
#line 399 "dcmat.y"
              {
            (yyval.integerValue) = (yyvsp[0].integerValue);
        }
#line 1825 "dcmat.tab.c"
    break;

  case 64: /* NumFloat: REAL  */
#line 403 "dcmat.y"
               { (yyval.floatValue) = (yyvsp[0].floatValue); }
#line 1831 "dcmat.tab.c"
    break;

  case 65: /* Bool: ON  */
#line 405 "dcmat.y"
         { (yyval.boolValue) = true; }
#line 1837 "dcmat.tab.c"
    break;

  case 66: /* Bool: OFF  */
#line 406 "dcmat.y"
          { (yyval.boolValue) = false; }
#line 1843 "dcmat.tab.c"
    break;


#line 1847 "dcmat.tab.c"

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

#line 408 "dcmat.y"


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
