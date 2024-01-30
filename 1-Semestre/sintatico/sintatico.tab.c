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
#line 1 "sintatico.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    extern int yylex();
    extern int currentColumn;
    extern int commentLine;
    extern int commentColumn;
    extern int currentSizeWord;
    extern int line;
    extern char* yytext;
    extern int yychar;
    extern void attInput(int line);
    extern int yyleng;
    extern char currentInput[2048];
    void yyerror(char *s);
    bool eof = false;


#line 92 "sintatico.tab.c"

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

#include "sintatico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VOID = 3,                       /* VOID  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_BREAK = 7,                      /* BREAK  */
  YYSYMBOL_SWITCH = 8,                     /* SWITCH  */
  YYSYMBOL_CASE = 9,                       /* CASE  */
  YYSYMBOL_DEFAULT = 10,                   /* DEFAULT  */
  YYSYMBOL_DO = 11,                        /* DO  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_TYPEDEF = 16,                   /* TYPEDEF  */
  YYSYMBOL_STRUCT = 17,                    /* STRUCT  */
  YYSYMBOL_PLUS = 18,                      /* PLUS  */
  YYSYMBOL_MINUS = 19,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 20,                  /* MULTIPLY  */
  YYSYMBOL_DIV = 21,                       /* DIV  */
  YYSYMBOL_REMAINDER = 22,                 /* REMAINDER  */
  YYSYMBOL_INC = 23,                       /* INC  */
  YYSYMBOL_DEC = 24,                       /* DEC  */
  YYSYMBOL_BITWISE_AND = 25,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 26,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_NOT = 27,               /* BITWISE_NOT  */
  YYSYMBOL_BITWISE_XOR = 28,               /* BITWISE_XOR  */
  YYSYMBOL_NOT = 29,                       /* NOT  */
  YYSYMBOL_LOGICAL_AND = 30,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 31,                /* LOGICAL_OR  */
  YYSYMBOL_EQUAL = 32,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 33,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS_THAN = 34,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 35,              /* GREATER_THAN  */
  YYSYMBOL_LESS_EQUAL = 36,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER_EQUAL = 37,             /* GREATER_EQUAL  */
  YYSYMBOL_R_SHIFT = 38,                   /* R_SHIFT  */
  YYSYMBOL_L_SHIFT = 39,                   /* L_SHIFT  */
  YYSYMBOL_ASSIGN = 40,                    /* ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 41,                /* ADD_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 42,              /* MINUS_ASSIGN  */
  YYSYMBOL_SEMICOLON = 43,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 44,                     /* COMMA  */
  YYSYMBOL_COLON = 45,                     /* COLON  */
  YYSYMBOL_L_PAREN = 46,                   /* L_PAREN  */
  YYSYMBOL_R_PAREN = 47,                   /* R_PAREN  */
  YYSYMBOL_L_CURLY_BRACKET = 48,           /* L_CURLY_BRACKET  */
  YYSYMBOL_R_CURLY_BRACKET = 49,           /* R_CURLY_BRACKET  */
  YYSYMBOL_L_SQUARE_BRACKET = 50,          /* L_SQUARE_BRACKET  */
  YYSYMBOL_R_SQUARE_BRACKET = 51,          /* R_SQUARE_BRACKET  */
  YYSYMBOL_TERNARY_CONDITIONAL = 52,       /* TERNARY_CONDITIONAL  */
  YYSYMBOL_NUMBER_SIGN = 53,               /* NUMBER_SIGN  */
  YYSYMBOL_POINTER = 54,                   /* POINTER  */
  YYSYMBOL_PRINTF = 55,                    /* PRINTF  */
  YYSYMBOL_SCANF = 56,                     /* SCANF  */
  YYSYMBOL_DEFINE = 57,                    /* DEFINE  */
  YYSYMBOL_EXIT = 58,                      /* EXIT  */
  YYSYMBOL_IDENTIFIER = 59,                /* IDENTIFIER  */
  YYSYMBOL_NUM_OCTAL = 60,                 /* NUM_OCTAL  */
  YYSYMBOL_NUM_INTEGER = 61,               /* NUM_INTEGER  */
  YYSYMBOL_NUM_HEXA = 62,                  /* NUM_HEXA  */
  YYSYMBOL_STRING = 63,                    /* STRING  */
  YYSYMBOL_CHARACTER = 64,                 /* CHARACTER  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_Programa = 66,                  /* Programa  */
  YYSYMBOL_ProgramaLinha = 67,             /* ProgramaLinha  */
  YYSYMBOL_Declaracoes = 68,               /* Declaracoes  */
  YYSYMBOL_Funcao = 69,                    /* Funcao  */
  YYSYMBOL_FuncaoLinha = 70,               /* FuncaoLinha  */
  YYSYMBOL_DeclaracoesVaraveis = 71,       /* DeclaracoesVaraveis  */
  YYSYMBOL_DeclaracoesVaraveisLinha = 72,  /* DeclaracoesVaraveisLinha  */
  YYSYMBOL_DeclaracoesDePrototipos = 73,   /* DeclaracoesDePrototipos  */
  YYSYMBOL_Parametros = 74,                /* Parametros  */
  YYSYMBOL_ParametrosLinha = 75,           /* ParametrosLinha  */
  YYSYMBOL_Tipo = 76,                      /* Tipo  */
  YYSYMBOL_Bloco = 77,                     /* Bloco  */
  YYSYMBOL_Comandos = 78,                  /* Comandos  */
  YYSYMBOL_ComandosLinha = 79,             /* ComandosLinha  */
  YYSYMBOL_ListaComandos = 80,             /* ListaComandos  */
  YYSYMBOL_Expressao = 81,                 /* Expressao  */
  YYSYMBOL_ExpressaoDeAtribuicao = 82,     /* ExpressaoDeAtribuicao  */
  YYSYMBOL_ExpressaoCondicional = 83,      /* ExpressaoCondicional  */
  YYSYMBOL_ExpressaoORLogico = 84,         /* ExpressaoORLogico  */
  YYSYMBOL_ExpressaoANDLogico = 85,        /* ExpressaoANDLogico  */
  YYSYMBOL_ExpressaoOR = 86,               /* ExpressaoOR  */
  YYSYMBOL_ExpressaoXOR = 87,              /* ExpressaoXOR  */
  YYSYMBOL_ExpressaoAND = 88,              /* ExpressaoAND  */
  YYSYMBOL_ExpressaoDeIgualdade = 89,      /* ExpressaoDeIgualdade  */
  YYSYMBOL_ExpressaoRelacional = 90,       /* ExpressaoRelacional  */
  YYSYMBOL_ExpressaoShift = 91,            /* ExpressaoShift  */
  YYSYMBOL_ExpressaoAditiva = 92,          /* ExpressaoAditiva  */
  YYSYMBOL_ExpressaoMultiplicativa = 93,   /* ExpressaoMultiplicativa  */
  YYSYMBOL_ExpressaoCast = 94,             /* ExpressaoCast  */
  YYSYMBOL_ExpressaoUnaria = 95,           /* ExpressaoUnaria  */
  YYSYMBOL_ExpressaoPosFixa = 96,          /* ExpressaoPosFixa  */
  YYSYMBOL_ExpressaoPosFixaLinha = 97,     /* ExpressaoPosFixaLinha  */
  YYSYMBOL_ExpressaoPrimaria = 98,         /* ExpressaoPrimaria  */
  YYSYMBOL_Numero = 99,                    /* Numero  */
  YYSYMBOL_ExpressaoLinha = 100,           /* ExpressaoLinha  */
  YYSYMBOL_Estrela = 101                   /* Estrela  */
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   398

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    88,    88,    89,    91,    91,    93,    94,    95,    97,
      99,   100,   102,   104,   105,   106,   107,   109,   111,   113,
     114,   115,   116,   118,   119,   120,   122,   124,   126,   126,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   142,   143,   145,   146,   147,   148,   150,
     151,   153,   154,   156,   157,   159,   160,   162,   163,   165,
     166,   168,   169,   170,   172,   173,   174,   175,   176,   178,
     179,   180,   182,   183,   184,   186,   187,   188,   189,   191,
     192,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     204,   205,   206,   207,   208,   209,   211,   211,   213,   214,
     215,   216,   217,   219,   220,   221,   223,   224,   226,   226
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
  "\"end of file\"", "error", "\"invalid token\"", "VOID", "INT", "CHAR",
  "RETURN", "BREAK", "SWITCH", "CASE", "DEFAULT", "DO", "WHILE", "FOR",
  "IF", "ELSE", "TYPEDEF", "STRUCT", "PLUS", "MINUS", "MULTIPLY", "DIV",
  "REMAINDER", "INC", "DEC", "BITWISE_AND", "BITWISE_OR", "BITWISE_NOT",
  "BITWISE_XOR", "NOT", "LOGICAL_AND", "LOGICAL_OR", "EQUAL", "NOT_EQUAL",
  "LESS_THAN", "GREATER_THAN", "LESS_EQUAL", "GREATER_EQUAL", "R_SHIFT",
  "L_SHIFT", "ASSIGN", "ADD_ASSIGN", "MINUS_ASSIGN", "SEMICOLON", "COMMA",
  "COLON", "L_PAREN", "R_PAREN", "L_CURLY_BRACKET", "R_CURLY_BRACKET",
  "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "TERNARY_CONDITIONAL",
  "NUMBER_SIGN", "POINTER", "PRINTF", "SCANF", "DEFINE", "EXIT",
  "IDENTIFIER", "NUM_OCTAL", "NUM_INTEGER", "NUM_HEXA", "STRING",
  "CHARACTER", "$accept", "Programa", "ProgramaLinha", "Declaracoes",
  "Funcao", "FuncaoLinha", "DeclaracoesVaraveis",
  "DeclaracoesVaraveisLinha", "DeclaracoesDePrototipos", "Parametros",
  "ParametrosLinha", "Tipo", "Bloco", "Comandos", "ComandosLinha",
  "ListaComandos", "Expressao", "ExpressaoDeAtribuicao",
  "ExpressaoCondicional", "ExpressaoORLogico", "ExpressaoANDLogico",
  "ExpressaoOR", "ExpressaoXOR", "ExpressaoAND", "ExpressaoDeIgualdade",
  "ExpressaoRelacional", "ExpressaoShift", "ExpressaoAditiva",
  "ExpressaoMultiplicativa", "ExpressaoCast", "ExpressaoUnaria",
  "ExpressaoPosFixa", "ExpressaoPosFixaLinha", "ExpressaoPrimaria",
  "Numero", "ExpressaoLinha", "Estrela", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-177)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,  -177,  -177,  -177,   -15,    45,     9,     9,  -177,  -177,
      46,    12,  -177,  -177,  -177,  -177,    46,    33,   287,  -177,
      24,   287,   287,   287,   334,   334,   287,   287,   287,   204,
    -177,  -177,  -177,  -177,  -177,  -177,    43,  -177,  -177,     8,
      77,    99,   101,   118,    47,    48,    75,   109,    96,  -177,
      79,    13,  -177,  -177,   287,  -177,    46,    28,   287,  -177,
       3,  -177,  -177,  -177,  -177,   287,  -177,  -177,  -177,  -177,
    -177,    46,   -29,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,  -177,  -177,   275,   287,
      51,    90,    28,  -177,   287,  -177,    46,   -34,  -177,   119,
     108,  -177,  -177,    77,    87,    99,   101,   118,    47,    48,
      48,    75,    75,    75,    75,   109,   109,    96,    96,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,   112,   -28,  -177,    51,
    -177,   -17,   100,    51,   228,   119,    46,   287,   287,   287,
     113,  -177,  -177,    28,    28,  -177,   287,    86,   115,   116,
     120,  -177,   228,   121,   122,   124,  -177,   123,   228,   104,
    -177,   105,  -177,    43,   112,  -177,  -177,  -177,    43,   128,
     161,   287,   287,   287,   125,   117,   147,   287,  -177,  -177,
    -177,  -177,    51,  -177,  -177,   129,    29,   133,    56,  -177,
      58,   134,    62,   287,    86,   287,    86,   287,   136,   152,
     138,    64,  -177,   139,   168,    68,  -177,   127,  -177,   141,
     287,    86,   144,   164,  -177,   165,  -177,  -177,   170,    86,
    -177,  -177
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    23,    25,    24,     0,     0,     5,     5,     6,     7,
     109,     0,     1,     4,     2,     3,   109,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,   105,   104,   103,   101,   100,     8,    43,    45,    50,
      52,    53,    55,    57,    59,    61,    64,    69,    72,    75,
      80,    89,    90,    99,     0,    16,   109,     0,     0,    12,
       0,    87,    80,    88,    86,     0,    81,    82,    85,    83,
      84,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,    93,     0,     0,
       0,     0,     0,    22,     0,    18,   109,     0,    17,    11,
       0,   102,    44,    51,     0,    54,    56,    58,    60,    63,
      62,    65,    68,    66,    67,    70,    71,    74,    73,    76,
      77,    78,    46,    48,    47,    95,    97,     0,    14,     0,
      21,     0,     0,     0,     0,    11,   109,     0,     0,     0,
       0,    91,    15,     0,     0,    13,   107,     0,     0,     0,
       0,    41,     0,     0,     0,     0,    42,     0,    29,     0,
      10,     0,    79,    49,    97,    94,    20,    19,   106,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     9,    28,
      27,    40,     0,    96,    39,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,    33,     0,    32,     0,    36,     0,    38,     0,
     107,     0,     0,     0,    30,     0,    31,    35,     0,     0,
      37,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -177,   214,   208,  -177,  -177,    72,  -107,   -78,  -177,  -177,
     -98,     1,  -152,  -127,  -177,  -177,   -18,   -45,  -177,  -177,
     142,   143,   148,   140,   151,    71,    14,    67,    69,    -2,
     114,  -177,    52,  -177,  -177,  -176,   -13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    13,    14,     6,     7,   144,     8,    59,     9,    60,
     105,   106,   166,   167,   190,   168,   178,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,   150,    52,    53,   179,    17
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    10,   145,    19,   140,   180,   197,    10,    10,   100,
      73,    72,     1,     2,     3,    73,    73,   143,   111,    61,
      63,    64,   138,   151,    68,    69,    70,    73,   112,   213,
      71,     1,     2,     3,   153,   184,    96,    97,   145,    74,
     107,   189,    11,   101,   225,    12,   108,    72,   132,   133,
     134,   109,   212,   136,   214,   176,   177,   114,   110,    98,
      75,   152,     4,    99,    54,   155,    16,    55,    56,   226,
      57,    18,   102,    73,    58,   103,   204,   231,   104,    80,
      81,   137,    82,    83,    84,    85,   141,    73,   129,   130,
     131,    54,    20,   142,    55,    56,   121,   122,   123,   124,
      73,    58,   207,   206,   174,   208,    73,    76,    73,   210,
     146,   219,    73,    86,    87,   222,    90,    91,    92,    93,
      94,    95,     1,     2,     3,    77,   169,    88,    89,    78,
     173,    73,   148,   171,   162,    62,    62,    62,    66,    67,
      62,    62,    62,    79,   169,   172,   146,   191,    73,   139,
     169,   119,   120,   125,   126,   147,   149,   127,   128,   154,
     175,   181,   182,   196,   192,   198,   183,   185,   186,   202,
     187,   194,   188,   195,   199,   203,   205,   217,   209,   216,
     200,   218,   220,   221,   224,   211,   223,   227,    62,   215,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,     1,     2,     3,
     201,   228,   229,   230,     5,    15,   113,   170,   117,   115,
       0,     0,    21,    22,    23,   116,   193,    24,    25,    26,
     118,    27,     0,    28,   156,     0,     0,     0,     0,   157,
     158,   159,   160,     0,     0,     0,    21,    22,    23,     0,
      29,    24,    25,    26,     0,    27,     0,    28,     0,     0,
       0,    62,     0,    30,    31,    32,    33,    34,    35,     0,
       0,   161,     0,     0,    29,     0,   162,     0,     0,     0,
       0,     0,     0,   163,   164,     0,   165,    30,    31,    32,
      33,    34,    35,    21,    22,    23,     0,     0,    24,    25,
      26,     0,    27,     0,    28,    21,    22,    23,     0,     0,
      24,    25,    26,     0,    27,     0,    28,     0,     0,     0,
       0,    29,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,    30,    31,    32,    33,
      34,    35,    21,    22,    23,     0,     0,    24,    25,    26,
       0,    27,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    31,    32,    33,    34,    35
};

static const yytype_int16 yycheck[] =
{
      18,     0,   109,    16,   102,   157,   182,     6,     7,    54,
      44,    29,     3,     4,     5,    44,    44,    51,    47,    21,
      22,    23,   100,    51,    26,    27,    28,    44,    73,   205,
      29,     3,     4,     5,    51,   162,    23,    24,   145,    31,
      58,   168,    57,    56,   220,     0,    43,    65,    93,    94,
      95,    48,   204,    98,   206,   153,   154,    75,    71,    46,
      52,   139,    53,    50,    40,   143,    20,    43,    44,   221,
      46,    59,    44,    44,    50,    47,    47,   229,    50,    32,
      33,    99,    34,    35,    36,    37,   104,    44,    90,    91,
      92,    40,    59,   106,    43,    44,    82,    83,    84,    85,
      44,    50,    44,    47,   149,    47,    44,    30,    44,    47,
     109,    47,    44,    38,    39,    47,    20,    21,    22,    40,
      41,    42,     3,     4,     5,    26,   144,    18,    19,    28,
     148,    44,    45,   146,    48,    21,    22,    23,    24,    25,
      26,    27,    28,    25,   162,   147,   145,    43,    44,    59,
     168,    80,    81,    86,    87,    47,    44,    88,    89,    59,
      47,    46,    46,   181,    59,   183,    46,    46,    46,   187,
      46,    43,    49,    12,    49,    46,    43,    25,    44,    43,
      63,    43,    43,    15,    43,   203,    59,    43,    74,   207,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     3,     4,     5,
      63,    47,    47,    43,     0,     7,    74,   145,    78,    76,
      -1,    -1,    18,    19,    20,    77,   174,    23,    24,    25,
      79,    27,    -1,    29,     6,    -1,    -1,    -1,    -1,    11,
      12,    13,    14,    -1,    -1,    -1,    18,    19,    20,    -1,
      46,    23,    24,    25,    -1,    27,    -1,    29,    -1,    -1,
      -1,   147,    -1,    59,    60,    61,    62,    63,    64,    -1,
      -1,    43,    -1,    -1,    46,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    18,    19,    20,    -1,    -1,    23,    24,
      25,    -1,    27,    -1,    29,    18,    19,    20,    -1,    -1,
      23,    24,    25,    -1,    27,    -1,    29,    -1,    -1,    -1,
      -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    18,    19,    20,    -1,    -1,    23,    24,    25,
      -1,    27,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    53,    66,    68,    69,    71,    73,
      76,    57,     0,    66,    67,    67,    20,   101,    59,   101,
      59,    18,    19,    20,    23,    24,    25,    27,    29,    46,
      59,    60,    61,    62,    63,    64,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    98,    99,    40,    43,    44,    46,    50,    72,
      74,    94,    95,    94,    94,    46,    95,    95,    94,    94,
      94,    76,    81,    44,    31,    52,    30,    26,    28,    25,
      32,    33,    34,    35,    36,    37,    38,    39,    18,    19,
      20,    21,    22,    40,    41,    42,    23,    24,    46,    50,
      82,   101,    44,    47,    50,    75,    76,    81,    43,    48,
     101,    47,    82,    85,    81,    86,    87,    88,    89,    90,
      90,    91,    91,    91,    91,    92,    92,    93,    93,    94,
      94,    94,    82,    82,    82,    47,    82,    81,    72,    59,
      75,    81,   101,    51,    70,    71,    76,    47,    45,    44,
      97,    51,    72,    51,    59,    72,     6,    11,    12,    13,
      14,    43,    48,    55,    56,    58,    77,    78,    80,    81,
      70,   101,    94,    81,    82,    47,    75,    75,    81,   100,
      77,    46,    46,    46,    78,    46,    46,    46,    49,    78,
      79,    43,    59,    97,    43,    12,    81,   100,    81,    49,
      63,    63,    81,    46,    47,    43,    47,    44,    47,    44,
      47,    81,    77,   100,    77,    81,    43,    25,    43,    47,
      43,    15,    47,    59,    43,   100,    77,    43,    47,    47,
      43,    77
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    68,    68,    68,    69,
      70,    70,    71,    72,    72,    72,    72,    73,    74,    75,
      75,    75,    75,    76,    76,    76,    77,    78,    79,    79,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    81,    81,    82,    82,    82,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    89,    89,    90,    90,    90,    90,    90,    91,
      91,    91,    92,    92,    92,    93,    93,    93,    93,    94,
      94,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      96,    96,    96,    96,    96,    96,    97,    97,    98,    98,
      98,    98,    98,    99,    99,    99,   100,   100,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     0,     1,     1,     4,     8,
       2,     0,     4,     4,     3,     4,     1,     5,     2,     4,
       4,     2,     1,     1,     1,     1,     3,     2,     1,     0,
       7,     7,     5,     5,     9,     7,     5,     8,     5,     3,
       2,     1,     1,     1,     3,     1,     3,     3,     3,     5,
       1,     3,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     5,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     4,     2,     2,     5,     3,     3,     0,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     0,     2,     0
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

#line 1373 "sintatico.tab.c"

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

#line 228 "sintatico.y"


void expectedDelaration(){
    printf("error:syntax:%d:%d: expected declaration or statement at end of input\n%s\n", line, currentColumn, currentInput);
    exit(0);
}

void syntaxError(){
    int sizeLineBeforeError = currentColumn - currentSizeWord;
    printf("error:syntax:%d:%d: %s\n%s", line, sizeLineBeforeError, yytext, currentInput);
    while(sizeLineBeforeError > 1){
        printf(" ");
        sizeLineBeforeError--;
    };
    printf("^");
    exit(0);
}

void yyerror(char *s) {

    attInput(line);

    (yychar == 0)?expectedDelaration():syntaxError();
}

int main(int argc, char **argv) {
    yyparse();
	printf("SUCCESSFUL COMPILATION.");
    return 0;
}
