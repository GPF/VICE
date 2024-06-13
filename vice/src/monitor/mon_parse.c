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
#line 1 "mon_parse.y"

/* -*- C -*-
 *
 * mon_parse.y - Parser for the VICE built-in monitor.
 *
 * Written by
 *  Daniel Sladic <sladic@eecg.toronto.edu>
 *  Andreas Boose <viceteam@t-online.de>
 *  Thomas Giesel <skoe@directbox.com>
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */

#include "vice.h"

#ifdef __GNUC__
#undef alloca
#define        alloca(n)       __builtin_alloca (n)
#else /* not __GNUC__ */
#ifdef HAVE_ALLOCA_H
#include <alloca.h>
#else  /* Not HAVE_ALLOCA_H  */
char *alloca();
#endif /* HAVE_ALLOCA_H.  */
#endif /* __GNUC__ */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "asm.h"
#include "console.h"
#include "drive.h"
#include "interrupt.h"
#include "lib.h"
#include "machine.h"
#include "mon_breakpoint.h"
#include "mon_command.h"
#include "mon_disassemble.h"
#include "mon_drive.h"
#include "mon_file.h"
#include "mon_memmap.h"
#include "mon_memory.h"
#include "mon_register.h"
#include "mon_util.h"
#include "montypes.h"
#include "tapeport.h"
#include "resources.h"
#include "types.h"
#include "uimon.h"
#include "vsync.h"
#include "mon_profile.h"

#define join_ints(x,y) (LO16_TO_HI16(x)|y)
#define separate_int1(x) (HI16_TO_LO16(x))
#define separate_int2(x) (LO16(x))

static int yyerror(char *s);
static int temp;
static int resolve_datatype(unsigned guess_type, const char *num);
static int resolve_range(enum t_memspace memspace, MON_ADDR range[2],
                         const char *num);

/* Defined in the lexer */
extern int new_cmd, opt_asm;
extern int cur_len, last_len;

void free_buffer(void);
void make_buffer(char *str);
int yylex(void);

void set_yydebug(int val);

#define ERR_ILLEGAL_INPUT 1     /* Generic error as returned by yacc.  */
#define ERR_RANGE_BAD_START 2
#define ERR_RANGE_BAD_END 3
#define ERR_BAD_CMD 4
#define ERR_EXPECT_CHECKNUM 5
#define ERR_EXPECT_END_CMD 6
#define ERR_MISSING_CLOSE_PAREN 7
#define ERR_INCOMPLETE_COND_OP 8
#define ERR_EXPECT_FILENAME 9
#define ERR_ADDR_TOO_BIG 10
#define ERR_IMM_TOO_BIG 11
#define ERR_EXPECT_STRING 12
#define ERR_UNDEFINED_LABEL 13
#define ERR_EXPECT_DEVICE_NUM 14
#define ERR_EXPECT_ADDRESS 15
#define ERR_INVALID_REGISTER 16

#define BAD_ADDR (new_addr(e_invalid_space, 0))
#define CHECK_ADDR(x) ((x) == addr_mask(x))

/* set to YYDEBUG 1 to get parser debugging via "yydebug" command, requires to
   set_yydebug(1) in monitor.c:monitor_init */
#ifdef DEBUG
#define YYDEBUG 1
#else
#define YYDEBUG 0
#endif


#line 193 "mon_parse.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_MON_PARSE_H_INCLUDED
# define YY_YY_MON_PARSE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    H_NUMBER = 258,                /* H_NUMBER  */
    D_NUMBER = 259,                /* D_NUMBER  */
    O_NUMBER = 260,                /* O_NUMBER  */
    B_NUMBER = 261,                /* B_NUMBER  */
    CONVERT_OP = 262,              /* CONVERT_OP  */
    B_DATA = 263,                  /* B_DATA  */
    H_RANGE_GUESS = 264,           /* H_RANGE_GUESS  */
    D_NUMBER_GUESS = 265,          /* D_NUMBER_GUESS  */
    O_NUMBER_GUESS = 266,          /* O_NUMBER_GUESS  */
    B_NUMBER_GUESS = 267,          /* B_NUMBER_GUESS  */
    BAD_CMD = 268,                 /* BAD_CMD  */
    MEM_OP = 269,                  /* MEM_OP  */
    IF = 270,                      /* IF  */
    MEM_COMP = 271,                /* MEM_COMP  */
    MEM_DISK8 = 272,               /* MEM_DISK8  */
    MEM_DISK9 = 273,               /* MEM_DISK9  */
    MEM_DISK10 = 274,              /* MEM_DISK10  */
    MEM_DISK11 = 275,              /* MEM_DISK11  */
    EQUALS = 276,                  /* EQUALS  */
    TRAIL = 277,                   /* TRAIL  */
    CMD_SEP = 278,                 /* CMD_SEP  */
    LABEL_ASGN_COMMENT = 279,      /* LABEL_ASGN_COMMENT  */
    CMD_LOG = 280,                 /* CMD_LOG  */
    CMD_LOGNAME = 281,             /* CMD_LOGNAME  */
    CMD_SIDEFX = 282,              /* CMD_SIDEFX  */
    CMD_DUMMY = 283,               /* CMD_DUMMY  */
    CMD_RETURN = 284,              /* CMD_RETURN  */
    CMD_BLOCK_READ = 285,          /* CMD_BLOCK_READ  */
    CMD_BLOCK_WRITE = 286,         /* CMD_BLOCK_WRITE  */
    CMD_UP = 287,                  /* CMD_UP  */
    CMD_DOWN = 288,                /* CMD_DOWN  */
    CMD_LOAD = 289,                /* CMD_LOAD  */
    CMD_BASICLOAD = 290,           /* CMD_BASICLOAD  */
    CMD_SAVE = 291,                /* CMD_SAVE  */
    CMD_VERIFY = 292,              /* CMD_VERIFY  */
    CMD_BVERIFY = 293,             /* CMD_BVERIFY  */
    CMD_IGNORE = 294,              /* CMD_IGNORE  */
    CMD_HUNT = 295,                /* CMD_HUNT  */
    CMD_FILL = 296,                /* CMD_FILL  */
    CMD_MOVE = 297,                /* CMD_MOVE  */
    CMD_GOTO = 298,                /* CMD_GOTO  */
    CMD_REGISTERS = 299,           /* CMD_REGISTERS  */
    CMD_READSPACE = 300,           /* CMD_READSPACE  */
    CMD_WRITESPACE = 301,          /* CMD_WRITESPACE  */
    CMD_RADIX = 302,               /* CMD_RADIX  */
    CMD_MEM_DISPLAY = 303,         /* CMD_MEM_DISPLAY  */
    CMD_BREAK = 304,               /* CMD_BREAK  */
    CMD_TRACE = 305,               /* CMD_TRACE  */
    CMD_IO = 306,                  /* CMD_IO  */
    CMD_BRMON = 307,               /* CMD_BRMON  */
    CMD_COMPARE = 308,             /* CMD_COMPARE  */
    CMD_DUMP = 309,                /* CMD_DUMP  */
    CMD_UNDUMP = 310,              /* CMD_UNDUMP  */
    CMD_EXIT = 311,                /* CMD_EXIT  */
    CMD_DELETE = 312,              /* CMD_DELETE  */
    CMD_CONDITION = 313,           /* CMD_CONDITION  */
    CMD_COMMAND = 314,             /* CMD_COMMAND  */
    CMD_ASSEMBLE = 315,            /* CMD_ASSEMBLE  */
    CMD_DISASSEMBLE = 316,         /* CMD_DISASSEMBLE  */
    CMD_NEXT = 317,                /* CMD_NEXT  */
    CMD_STEP = 318,                /* CMD_STEP  */
    CMD_PRINT = 319,               /* CMD_PRINT  */
    CMD_DEVICE = 320,              /* CMD_DEVICE  */
    CMD_HELP = 321,                /* CMD_HELP  */
    CMD_WATCH = 322,               /* CMD_WATCH  */
    CMD_DISK = 323,                /* CMD_DISK  */
    CMD_QUIT = 324,                /* CMD_QUIT  */
    CMD_CHDIR = 325,               /* CMD_CHDIR  */
    CMD_BANK = 326,                /* CMD_BANK  */
    CMD_LOAD_LABELS = 327,         /* CMD_LOAD_LABELS  */
    CMD_SAVE_LABELS = 328,         /* CMD_SAVE_LABELS  */
    CMD_ADD_LABEL = 329,           /* CMD_ADD_LABEL  */
    CMD_DEL_LABEL = 330,           /* CMD_DEL_LABEL  */
    CMD_SHOW_LABELS = 331,         /* CMD_SHOW_LABELS  */
    CMD_CLEAR_LABELS = 332,        /* CMD_CLEAR_LABELS  */
    CMD_RECORD = 333,              /* CMD_RECORD  */
    CMD_MON_STOP = 334,            /* CMD_MON_STOP  */
    CMD_PLAYBACK = 335,            /* CMD_PLAYBACK  */
    CMD_CHAR_DISPLAY = 336,        /* CMD_CHAR_DISPLAY  */
    CMD_SPRITE_DISPLAY = 337,      /* CMD_SPRITE_DISPLAY  */
    CMD_TEXT_DISPLAY = 338,        /* CMD_TEXT_DISPLAY  */
    CMD_SCREENCODE_DISPLAY = 339,  /* CMD_SCREENCODE_DISPLAY  */
    CMD_ENTER_DATA = 340,          /* CMD_ENTER_DATA  */
    CMD_ENTER_BIN_DATA = 341,      /* CMD_ENTER_BIN_DATA  */
    CMD_KEYBUF = 342,              /* CMD_KEYBUF  */
    CMD_BLOAD = 343,               /* CMD_BLOAD  */
    CMD_BSAVE = 344,               /* CMD_BSAVE  */
    CMD_SCREEN = 345,              /* CMD_SCREEN  */
    CMD_UNTIL = 346,               /* CMD_UNTIL  */
    CMD_CPU = 347,                 /* CMD_CPU  */
    CMD_YYDEBUG = 348,             /* CMD_YYDEBUG  */
    CMD_BACKTRACE = 349,           /* CMD_BACKTRACE  */
    CMD_SCREENSHOT = 350,          /* CMD_SCREENSHOT  */
    CMD_PWD = 351,                 /* CMD_PWD  */
    CMD_DIR = 352,                 /* CMD_DIR  */
    CMD_MKDIR = 353,               /* CMD_MKDIR  */
    CMD_RMDIR = 354,               /* CMD_RMDIR  */
    CMD_RESOURCE_GET = 355,        /* CMD_RESOURCE_GET  */
    CMD_RESOURCE_SET = 356,        /* CMD_RESOURCE_SET  */
    CMD_LOAD_RESOURCES = 357,      /* CMD_LOAD_RESOURCES  */
    CMD_SAVE_RESOURCES = 358,      /* CMD_SAVE_RESOURCES  */
    CMD_ATTACH = 359,              /* CMD_ATTACH  */
    CMD_DETACH = 360,              /* CMD_DETACH  */
    CMD_MON_RESET = 361,           /* CMD_MON_RESET  */
    CMD_TAPECTRL = 362,            /* CMD_TAPECTRL  */
    CMD_TAPEOFFS = 363,            /* CMD_TAPEOFFS  */
    CMD_CARTFREEZE = 364,          /* CMD_CARTFREEZE  */
    CMD_UPDB = 365,                /* CMD_UPDB  */
    CMD_JPDB = 366,                /* CMD_JPDB  */
    CMD_CPUHISTORY = 367,          /* CMD_CPUHISTORY  */
    CMD_MEMMAPZAP = 368,           /* CMD_MEMMAPZAP  */
    CMD_MEMMAPSHOW = 369,          /* CMD_MEMMAPSHOW  */
    CMD_MEMMAPSAVE = 370,          /* CMD_MEMMAPSAVE  */
    CMD_COMMENT = 371,             /* CMD_COMMENT  */
    CMD_LIST = 372,                /* CMD_LIST  */
    CMD_STOPWATCH = 373,           /* CMD_STOPWATCH  */
    RESET = 374,                   /* RESET  */
    CMD_EXPORT = 375,              /* CMD_EXPORT  */
    CMD_AUTOSTART = 376,           /* CMD_AUTOSTART  */
    CMD_AUTOLOAD = 377,            /* CMD_AUTOLOAD  */
    CMD_MAINCPU_TRACE = 378,       /* CMD_MAINCPU_TRACE  */
    CMD_WARP = 379,                /* CMD_WARP  */
    CMD_PROFILE = 380,             /* CMD_PROFILE  */
    FLAT = 381,                    /* FLAT  */
    GRAPH = 382,                   /* GRAPH  */
    FUNC = 383,                    /* FUNC  */
    DEPTH = 384,                   /* DEPTH  */
    DISASS = 385,                  /* DISASS  */
    PROFILE_CONTEXT = 386,         /* PROFILE_CONTEXT  */
    CLEAR = 387,                   /* CLEAR  */
    CMD_LABEL_ASGN = 388,          /* CMD_LABEL_ASGN  */
    L_PAREN = 389,                 /* L_PAREN  */
    R_PAREN = 390,                 /* R_PAREN  */
    ARG_IMMEDIATE = 391,           /* ARG_IMMEDIATE  */
    REG_A = 392,                   /* REG_A  */
    REG_X = 393,                   /* REG_X  */
    REG_Y = 394,                   /* REG_Y  */
    COMMA = 395,                   /* COMMA  */
    INST_SEP = 396,                /* INST_SEP  */
    L_BRACKET = 397,               /* L_BRACKET  */
    R_BRACKET = 398,               /* R_BRACKET  */
    LESS_THAN = 399,               /* LESS_THAN  */
    REG_U = 400,                   /* REG_U  */
    REG_S = 401,                   /* REG_S  */
    REG_PC = 402,                  /* REG_PC  */
    REG_PCR = 403,                 /* REG_PCR  */
    REG_B = 404,                   /* REG_B  */
    REG_C = 405,                   /* REG_C  */
    REG_D = 406,                   /* REG_D  */
    REG_E = 407,                   /* REG_E  */
    REG_H = 408,                   /* REG_H  */
    REG_L = 409,                   /* REG_L  */
    REG_AF = 410,                  /* REG_AF  */
    REG_BC = 411,                  /* REG_BC  */
    REG_DE = 412,                  /* REG_DE  */
    REG_HL = 413,                  /* REG_HL  */
    REG_IX = 414,                  /* REG_IX  */
    REG_IY = 415,                  /* REG_IY  */
    REG_SP = 416,                  /* REG_SP  */
    REG_IXH = 417,                 /* REG_IXH  */
    REG_IXL = 418,                 /* REG_IXL  */
    REG_IYH = 419,                 /* REG_IYH  */
    REG_IYL = 420,                 /* REG_IYL  */
    PLUS = 421,                    /* PLUS  */
    MINUS = 422,                   /* MINUS  */
    STRING = 423,                  /* STRING  */
    FILENAME = 424,                /* FILENAME  */
    R_O_L = 425,                   /* R_O_L  */
    R_O_L_Q = 426,                 /* R_O_L_Q  */
    OPCODE = 427,                  /* OPCODE  */
    LABEL = 428,                   /* LABEL  */
    BANKNAME = 429,                /* BANKNAME  */
    CPUTYPE = 430,                 /* CPUTYPE  */
    MON_REGISTER = 431,            /* MON_REGISTER  */
    COND_OP = 432,                 /* COND_OP  */
    RADIX_TYPE = 433,              /* RADIX_TYPE  */
    INPUT_SPEC = 434,              /* INPUT_SPEC  */
    CMD_CHECKPT_ON = 435,          /* CMD_CHECKPT_ON  */
    CMD_CHECKPT_OFF = 436,         /* CMD_CHECKPT_OFF  */
    TOGGLE = 437,                  /* TOGGLE  */
    MASK = 438                     /* MASK  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define H_NUMBER 258
#define D_NUMBER 259
#define O_NUMBER 260
#define B_NUMBER 261
#define CONVERT_OP 262
#define B_DATA 263
#define H_RANGE_GUESS 264
#define D_NUMBER_GUESS 265
#define O_NUMBER_GUESS 266
#define B_NUMBER_GUESS 267
#define BAD_CMD 268
#define MEM_OP 269
#define IF 270
#define MEM_COMP 271
#define MEM_DISK8 272
#define MEM_DISK9 273
#define MEM_DISK10 274
#define MEM_DISK11 275
#define EQUALS 276
#define TRAIL 277
#define CMD_SEP 278
#define LABEL_ASGN_COMMENT 279
#define CMD_LOG 280
#define CMD_LOGNAME 281
#define CMD_SIDEFX 282
#define CMD_DUMMY 283
#define CMD_RETURN 284
#define CMD_BLOCK_READ 285
#define CMD_BLOCK_WRITE 286
#define CMD_UP 287
#define CMD_DOWN 288
#define CMD_LOAD 289
#define CMD_BASICLOAD 290
#define CMD_SAVE 291
#define CMD_VERIFY 292
#define CMD_BVERIFY 293
#define CMD_IGNORE 294
#define CMD_HUNT 295
#define CMD_FILL 296
#define CMD_MOVE 297
#define CMD_GOTO 298
#define CMD_REGISTERS 299
#define CMD_READSPACE 300
#define CMD_WRITESPACE 301
#define CMD_RADIX 302
#define CMD_MEM_DISPLAY 303
#define CMD_BREAK 304
#define CMD_TRACE 305
#define CMD_IO 306
#define CMD_BRMON 307
#define CMD_COMPARE 308
#define CMD_DUMP 309
#define CMD_UNDUMP 310
#define CMD_EXIT 311
#define CMD_DELETE 312
#define CMD_CONDITION 313
#define CMD_COMMAND 314
#define CMD_ASSEMBLE 315
#define CMD_DISASSEMBLE 316
#define CMD_NEXT 317
#define CMD_STEP 318
#define CMD_PRINT 319
#define CMD_DEVICE 320
#define CMD_HELP 321
#define CMD_WATCH 322
#define CMD_DISK 323
#define CMD_QUIT 324
#define CMD_CHDIR 325
#define CMD_BANK 326
#define CMD_LOAD_LABELS 327
#define CMD_SAVE_LABELS 328
#define CMD_ADD_LABEL 329
#define CMD_DEL_LABEL 330
#define CMD_SHOW_LABELS 331
#define CMD_CLEAR_LABELS 332
#define CMD_RECORD 333
#define CMD_MON_STOP 334
#define CMD_PLAYBACK 335
#define CMD_CHAR_DISPLAY 336
#define CMD_SPRITE_DISPLAY 337
#define CMD_TEXT_DISPLAY 338
#define CMD_SCREENCODE_DISPLAY 339
#define CMD_ENTER_DATA 340
#define CMD_ENTER_BIN_DATA 341
#define CMD_KEYBUF 342
#define CMD_BLOAD 343
#define CMD_BSAVE 344
#define CMD_SCREEN 345
#define CMD_UNTIL 346
#define CMD_CPU 347
#define CMD_YYDEBUG 348
#define CMD_BACKTRACE 349
#define CMD_SCREENSHOT 350
#define CMD_PWD 351
#define CMD_DIR 352
#define CMD_MKDIR 353
#define CMD_RMDIR 354
#define CMD_RESOURCE_GET 355
#define CMD_RESOURCE_SET 356
#define CMD_LOAD_RESOURCES 357
#define CMD_SAVE_RESOURCES 358
#define CMD_ATTACH 359
#define CMD_DETACH 360
#define CMD_MON_RESET 361
#define CMD_TAPECTRL 362
#define CMD_TAPEOFFS 363
#define CMD_CARTFREEZE 364
#define CMD_UPDB 365
#define CMD_JPDB 366
#define CMD_CPUHISTORY 367
#define CMD_MEMMAPZAP 368
#define CMD_MEMMAPSHOW 369
#define CMD_MEMMAPSAVE 370
#define CMD_COMMENT 371
#define CMD_LIST 372
#define CMD_STOPWATCH 373
#define RESET 374
#define CMD_EXPORT 375
#define CMD_AUTOSTART 376
#define CMD_AUTOLOAD 377
#define CMD_MAINCPU_TRACE 378
#define CMD_WARP 379
#define CMD_PROFILE 380
#define FLAT 381
#define GRAPH 382
#define FUNC 383
#define DEPTH 384
#define DISASS 385
#define PROFILE_CONTEXT 386
#define CLEAR 387
#define CMD_LABEL_ASGN 388
#define L_PAREN 389
#define R_PAREN 390
#define ARG_IMMEDIATE 391
#define REG_A 392
#define REG_X 393
#define REG_Y 394
#define COMMA 395
#define INST_SEP 396
#define L_BRACKET 397
#define R_BRACKET 398
#define LESS_THAN 399
#define REG_U 400
#define REG_S 401
#define REG_PC 402
#define REG_PCR 403
#define REG_B 404
#define REG_C 405
#define REG_D 406
#define REG_E 407
#define REG_H 408
#define REG_L 409
#define REG_AF 410
#define REG_BC 411
#define REG_DE 412
#define REG_HL 413
#define REG_IX 414
#define REG_IY 415
#define REG_SP 416
#define REG_IXH 417
#define REG_IXL 418
#define REG_IYH 419
#define REG_IYL 420
#define PLUS 421
#define MINUS 422
#define STRING 423
#define FILENAME 424
#define R_O_L 425
#define R_O_L_Q 426
#define OPCODE 427
#define LABEL 428
#define BANKNAME 429
#define CPUTYPE 430
#define MON_REGISTER 431
#define COND_OP 432
#define RADIX_TYPE 433
#define INPUT_SPEC 434
#define CMD_CHECKPT_ON 435
#define CMD_CHECKPT_OFF 436
#define TOGGLE 437
#define MASK 438

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 123 "mon_parse.y"

    MON_ADDR a;
    MON_ADDR range[2];
    int i;
    REG_ID reg;
    CONDITIONAL cond_op;
    cond_node_t *cond_node;
    RADIXTYPE rt;
    ACTION action;
    char *str;
    asm_mode_addr_info_t mode;

#line 625 "mon_parse.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MON_PARSE_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_H_NUMBER = 3,                   /* H_NUMBER  */
  YYSYMBOL_D_NUMBER = 4,                   /* D_NUMBER  */
  YYSYMBOL_O_NUMBER = 5,                   /* O_NUMBER  */
  YYSYMBOL_B_NUMBER = 6,                   /* B_NUMBER  */
  YYSYMBOL_CONVERT_OP = 7,                 /* CONVERT_OP  */
  YYSYMBOL_B_DATA = 8,                     /* B_DATA  */
  YYSYMBOL_H_RANGE_GUESS = 9,              /* H_RANGE_GUESS  */
  YYSYMBOL_D_NUMBER_GUESS = 10,            /* D_NUMBER_GUESS  */
  YYSYMBOL_O_NUMBER_GUESS = 11,            /* O_NUMBER_GUESS  */
  YYSYMBOL_B_NUMBER_GUESS = 12,            /* B_NUMBER_GUESS  */
  YYSYMBOL_BAD_CMD = 13,                   /* BAD_CMD  */
  YYSYMBOL_MEM_OP = 14,                    /* MEM_OP  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_MEM_COMP = 16,                  /* MEM_COMP  */
  YYSYMBOL_MEM_DISK8 = 17,                 /* MEM_DISK8  */
  YYSYMBOL_MEM_DISK9 = 18,                 /* MEM_DISK9  */
  YYSYMBOL_MEM_DISK10 = 19,                /* MEM_DISK10  */
  YYSYMBOL_MEM_DISK11 = 20,                /* MEM_DISK11  */
  YYSYMBOL_EQUALS = 21,                    /* EQUALS  */
  YYSYMBOL_TRAIL = 22,                     /* TRAIL  */
  YYSYMBOL_CMD_SEP = 23,                   /* CMD_SEP  */
  YYSYMBOL_LABEL_ASGN_COMMENT = 24,        /* LABEL_ASGN_COMMENT  */
  YYSYMBOL_CMD_LOG = 25,                   /* CMD_LOG  */
  YYSYMBOL_CMD_LOGNAME = 26,               /* CMD_LOGNAME  */
  YYSYMBOL_CMD_SIDEFX = 27,                /* CMD_SIDEFX  */
  YYSYMBOL_CMD_DUMMY = 28,                 /* CMD_DUMMY  */
  YYSYMBOL_CMD_RETURN = 29,                /* CMD_RETURN  */
  YYSYMBOL_CMD_BLOCK_READ = 30,            /* CMD_BLOCK_READ  */
  YYSYMBOL_CMD_BLOCK_WRITE = 31,           /* CMD_BLOCK_WRITE  */
  YYSYMBOL_CMD_UP = 32,                    /* CMD_UP  */
  YYSYMBOL_CMD_DOWN = 33,                  /* CMD_DOWN  */
  YYSYMBOL_CMD_LOAD = 34,                  /* CMD_LOAD  */
  YYSYMBOL_CMD_BASICLOAD = 35,             /* CMD_BASICLOAD  */
  YYSYMBOL_CMD_SAVE = 36,                  /* CMD_SAVE  */
  YYSYMBOL_CMD_VERIFY = 37,                /* CMD_VERIFY  */
  YYSYMBOL_CMD_BVERIFY = 38,               /* CMD_BVERIFY  */
  YYSYMBOL_CMD_IGNORE = 39,                /* CMD_IGNORE  */
  YYSYMBOL_CMD_HUNT = 40,                  /* CMD_HUNT  */
  YYSYMBOL_CMD_FILL = 41,                  /* CMD_FILL  */
  YYSYMBOL_CMD_MOVE = 42,                  /* CMD_MOVE  */
  YYSYMBOL_CMD_GOTO = 43,                  /* CMD_GOTO  */
  YYSYMBOL_CMD_REGISTERS = 44,             /* CMD_REGISTERS  */
  YYSYMBOL_CMD_READSPACE = 45,             /* CMD_READSPACE  */
  YYSYMBOL_CMD_WRITESPACE = 46,            /* CMD_WRITESPACE  */
  YYSYMBOL_CMD_RADIX = 47,                 /* CMD_RADIX  */
  YYSYMBOL_CMD_MEM_DISPLAY = 48,           /* CMD_MEM_DISPLAY  */
  YYSYMBOL_CMD_BREAK = 49,                 /* CMD_BREAK  */
  YYSYMBOL_CMD_TRACE = 50,                 /* CMD_TRACE  */
  YYSYMBOL_CMD_IO = 51,                    /* CMD_IO  */
  YYSYMBOL_CMD_BRMON = 52,                 /* CMD_BRMON  */
  YYSYMBOL_CMD_COMPARE = 53,               /* CMD_COMPARE  */
  YYSYMBOL_CMD_DUMP = 54,                  /* CMD_DUMP  */
  YYSYMBOL_CMD_UNDUMP = 55,                /* CMD_UNDUMP  */
  YYSYMBOL_CMD_EXIT = 56,                  /* CMD_EXIT  */
  YYSYMBOL_CMD_DELETE = 57,                /* CMD_DELETE  */
  YYSYMBOL_CMD_CONDITION = 58,             /* CMD_CONDITION  */
  YYSYMBOL_CMD_COMMAND = 59,               /* CMD_COMMAND  */
  YYSYMBOL_CMD_ASSEMBLE = 60,              /* CMD_ASSEMBLE  */
  YYSYMBOL_CMD_DISASSEMBLE = 61,           /* CMD_DISASSEMBLE  */
  YYSYMBOL_CMD_NEXT = 62,                  /* CMD_NEXT  */
  YYSYMBOL_CMD_STEP = 63,                  /* CMD_STEP  */
  YYSYMBOL_CMD_PRINT = 64,                 /* CMD_PRINT  */
  YYSYMBOL_CMD_DEVICE = 65,                /* CMD_DEVICE  */
  YYSYMBOL_CMD_HELP = 66,                  /* CMD_HELP  */
  YYSYMBOL_CMD_WATCH = 67,                 /* CMD_WATCH  */
  YYSYMBOL_CMD_DISK = 68,                  /* CMD_DISK  */
  YYSYMBOL_CMD_QUIT = 69,                  /* CMD_QUIT  */
  YYSYMBOL_CMD_CHDIR = 70,                 /* CMD_CHDIR  */
  YYSYMBOL_CMD_BANK = 71,                  /* CMD_BANK  */
  YYSYMBOL_CMD_LOAD_LABELS = 72,           /* CMD_LOAD_LABELS  */
  YYSYMBOL_CMD_SAVE_LABELS = 73,           /* CMD_SAVE_LABELS  */
  YYSYMBOL_CMD_ADD_LABEL = 74,             /* CMD_ADD_LABEL  */
  YYSYMBOL_CMD_DEL_LABEL = 75,             /* CMD_DEL_LABEL  */
  YYSYMBOL_CMD_SHOW_LABELS = 76,           /* CMD_SHOW_LABELS  */
  YYSYMBOL_CMD_CLEAR_LABELS = 77,          /* CMD_CLEAR_LABELS  */
  YYSYMBOL_CMD_RECORD = 78,                /* CMD_RECORD  */
  YYSYMBOL_CMD_MON_STOP = 79,              /* CMD_MON_STOP  */
  YYSYMBOL_CMD_PLAYBACK = 80,              /* CMD_PLAYBACK  */
  YYSYMBOL_CMD_CHAR_DISPLAY = 81,          /* CMD_CHAR_DISPLAY  */
  YYSYMBOL_CMD_SPRITE_DISPLAY = 82,        /* CMD_SPRITE_DISPLAY  */
  YYSYMBOL_CMD_TEXT_DISPLAY = 83,          /* CMD_TEXT_DISPLAY  */
  YYSYMBOL_CMD_SCREENCODE_DISPLAY = 84,    /* CMD_SCREENCODE_DISPLAY  */
  YYSYMBOL_CMD_ENTER_DATA = 85,            /* CMD_ENTER_DATA  */
  YYSYMBOL_CMD_ENTER_BIN_DATA = 86,        /* CMD_ENTER_BIN_DATA  */
  YYSYMBOL_CMD_KEYBUF = 87,                /* CMD_KEYBUF  */
  YYSYMBOL_CMD_BLOAD = 88,                 /* CMD_BLOAD  */
  YYSYMBOL_CMD_BSAVE = 89,                 /* CMD_BSAVE  */
  YYSYMBOL_CMD_SCREEN = 90,                /* CMD_SCREEN  */
  YYSYMBOL_CMD_UNTIL = 91,                 /* CMD_UNTIL  */
  YYSYMBOL_CMD_CPU = 92,                   /* CMD_CPU  */
  YYSYMBOL_CMD_YYDEBUG = 93,               /* CMD_YYDEBUG  */
  YYSYMBOL_CMD_BACKTRACE = 94,             /* CMD_BACKTRACE  */
  YYSYMBOL_CMD_SCREENSHOT = 95,            /* CMD_SCREENSHOT  */
  YYSYMBOL_CMD_PWD = 96,                   /* CMD_PWD  */
  YYSYMBOL_CMD_DIR = 97,                   /* CMD_DIR  */
  YYSYMBOL_CMD_MKDIR = 98,                 /* CMD_MKDIR  */
  YYSYMBOL_CMD_RMDIR = 99,                 /* CMD_RMDIR  */
  YYSYMBOL_CMD_RESOURCE_GET = 100,         /* CMD_RESOURCE_GET  */
  YYSYMBOL_CMD_RESOURCE_SET = 101,         /* CMD_RESOURCE_SET  */
  YYSYMBOL_CMD_LOAD_RESOURCES = 102,       /* CMD_LOAD_RESOURCES  */
  YYSYMBOL_CMD_SAVE_RESOURCES = 103,       /* CMD_SAVE_RESOURCES  */
  YYSYMBOL_CMD_ATTACH = 104,               /* CMD_ATTACH  */
  YYSYMBOL_CMD_DETACH = 105,               /* CMD_DETACH  */
  YYSYMBOL_CMD_MON_RESET = 106,            /* CMD_MON_RESET  */
  YYSYMBOL_CMD_TAPECTRL = 107,             /* CMD_TAPECTRL  */
  YYSYMBOL_CMD_TAPEOFFS = 108,             /* CMD_TAPEOFFS  */
  YYSYMBOL_CMD_CARTFREEZE = 109,           /* CMD_CARTFREEZE  */
  YYSYMBOL_CMD_UPDB = 110,                 /* CMD_UPDB  */
  YYSYMBOL_CMD_JPDB = 111,                 /* CMD_JPDB  */
  YYSYMBOL_CMD_CPUHISTORY = 112,           /* CMD_CPUHISTORY  */
  YYSYMBOL_CMD_MEMMAPZAP = 113,            /* CMD_MEMMAPZAP  */
  YYSYMBOL_CMD_MEMMAPSHOW = 114,           /* CMD_MEMMAPSHOW  */
  YYSYMBOL_CMD_MEMMAPSAVE = 115,           /* CMD_MEMMAPSAVE  */
  YYSYMBOL_CMD_COMMENT = 116,              /* CMD_COMMENT  */
  YYSYMBOL_CMD_LIST = 117,                 /* CMD_LIST  */
  YYSYMBOL_CMD_STOPWATCH = 118,            /* CMD_STOPWATCH  */
  YYSYMBOL_RESET = 119,                    /* RESET  */
  YYSYMBOL_CMD_EXPORT = 120,               /* CMD_EXPORT  */
  YYSYMBOL_CMD_AUTOSTART = 121,            /* CMD_AUTOSTART  */
  YYSYMBOL_CMD_AUTOLOAD = 122,             /* CMD_AUTOLOAD  */
  YYSYMBOL_CMD_MAINCPU_TRACE = 123,        /* CMD_MAINCPU_TRACE  */
  YYSYMBOL_CMD_WARP = 124,                 /* CMD_WARP  */
  YYSYMBOL_CMD_PROFILE = 125,              /* CMD_PROFILE  */
  YYSYMBOL_FLAT = 126,                     /* FLAT  */
  YYSYMBOL_GRAPH = 127,                    /* GRAPH  */
  YYSYMBOL_FUNC = 128,                     /* FUNC  */
  YYSYMBOL_DEPTH = 129,                    /* DEPTH  */
  YYSYMBOL_DISASS = 130,                   /* DISASS  */
  YYSYMBOL_PROFILE_CONTEXT = 131,          /* PROFILE_CONTEXT  */
  YYSYMBOL_CLEAR = 132,                    /* CLEAR  */
  YYSYMBOL_CMD_LABEL_ASGN = 133,           /* CMD_LABEL_ASGN  */
  YYSYMBOL_L_PAREN = 134,                  /* L_PAREN  */
  YYSYMBOL_R_PAREN = 135,                  /* R_PAREN  */
  YYSYMBOL_ARG_IMMEDIATE = 136,            /* ARG_IMMEDIATE  */
  YYSYMBOL_REG_A = 137,                    /* REG_A  */
  YYSYMBOL_REG_X = 138,                    /* REG_X  */
  YYSYMBOL_REG_Y = 139,                    /* REG_Y  */
  YYSYMBOL_COMMA = 140,                    /* COMMA  */
  YYSYMBOL_INST_SEP = 141,                 /* INST_SEP  */
  YYSYMBOL_L_BRACKET = 142,                /* L_BRACKET  */
  YYSYMBOL_R_BRACKET = 143,                /* R_BRACKET  */
  YYSYMBOL_LESS_THAN = 144,                /* LESS_THAN  */
  YYSYMBOL_REG_U = 145,                    /* REG_U  */
  YYSYMBOL_REG_S = 146,                    /* REG_S  */
  YYSYMBOL_REG_PC = 147,                   /* REG_PC  */
  YYSYMBOL_REG_PCR = 148,                  /* REG_PCR  */
  YYSYMBOL_REG_B = 149,                    /* REG_B  */
  YYSYMBOL_REG_C = 150,                    /* REG_C  */
  YYSYMBOL_REG_D = 151,                    /* REG_D  */
  YYSYMBOL_REG_E = 152,                    /* REG_E  */
  YYSYMBOL_REG_H = 153,                    /* REG_H  */
  YYSYMBOL_REG_L = 154,                    /* REG_L  */
  YYSYMBOL_REG_AF = 155,                   /* REG_AF  */
  YYSYMBOL_REG_BC = 156,                   /* REG_BC  */
  YYSYMBOL_REG_DE = 157,                   /* REG_DE  */
  YYSYMBOL_REG_HL = 158,                   /* REG_HL  */
  YYSYMBOL_REG_IX = 159,                   /* REG_IX  */
  YYSYMBOL_REG_IY = 160,                   /* REG_IY  */
  YYSYMBOL_REG_SP = 161,                   /* REG_SP  */
  YYSYMBOL_REG_IXH = 162,                  /* REG_IXH  */
  YYSYMBOL_REG_IXL = 163,                  /* REG_IXL  */
  YYSYMBOL_REG_IYH = 164,                  /* REG_IYH  */
  YYSYMBOL_REG_IYL = 165,                  /* REG_IYL  */
  YYSYMBOL_PLUS = 166,                     /* PLUS  */
  YYSYMBOL_MINUS = 167,                    /* MINUS  */
  YYSYMBOL_STRING = 168,                   /* STRING  */
  YYSYMBOL_FILENAME = 169,                 /* FILENAME  */
  YYSYMBOL_R_O_L = 170,                    /* R_O_L  */
  YYSYMBOL_R_O_L_Q = 171,                  /* R_O_L_Q  */
  YYSYMBOL_OPCODE = 172,                   /* OPCODE  */
  YYSYMBOL_LABEL = 173,                    /* LABEL  */
  YYSYMBOL_BANKNAME = 174,                 /* BANKNAME  */
  YYSYMBOL_CPUTYPE = 175,                  /* CPUTYPE  */
  YYSYMBOL_MON_REGISTER = 176,             /* MON_REGISTER  */
  YYSYMBOL_COND_OP = 177,                  /* COND_OP  */
  YYSYMBOL_RADIX_TYPE = 178,               /* RADIX_TYPE  */
  YYSYMBOL_INPUT_SPEC = 179,               /* INPUT_SPEC  */
  YYSYMBOL_CMD_CHECKPT_ON = 180,           /* CMD_CHECKPT_ON  */
  YYSYMBOL_CMD_CHECKPT_OFF = 181,          /* CMD_CHECKPT_OFF  */
  YYSYMBOL_TOGGLE = 182,                   /* TOGGLE  */
  YYSYMBOL_MASK = 183,                     /* MASK  */
  YYSYMBOL_184_ = 184,                     /* '+'  */
  YYSYMBOL_185_ = 185,                     /* '-'  */
  YYSYMBOL_186_ = 186,                     /* '*'  */
  YYSYMBOL_187_ = 187,                     /* '/'  */
  YYSYMBOL_188_ = 188,                     /* '('  */
  YYSYMBOL_189_ = 189,                     /* ')'  */
  YYSYMBOL_190_ = 190,                     /* '@'  */
  YYSYMBOL_191_ = 191,                     /* ':'  */
  YYSYMBOL_YYACCEPT = 192,                 /* $accept  */
  YYSYMBOL_top_level = 193,                /* top_level  */
  YYSYMBOL_command_list = 194,             /* command_list  */
  YYSYMBOL_end_cmd = 195,                  /* end_cmd  */
  YYSYMBOL_command = 196,                  /* command  */
  YYSYMBOL_machine_state_rules = 197,      /* machine_state_rules  */
  YYSYMBOL_register_mod = 198,             /* register_mod  */
  YYSYMBOL_symbol_table_rules = 199,       /* symbol_table_rules  */
  YYSYMBOL_asm_rules = 200,                /* asm_rules  */
  YYSYMBOL_201_1 = 201,                    /* $@1  */
  YYSYMBOL_memory_rules = 202,             /* memory_rules  */
  YYSYMBOL_checkpoint_rules = 203,         /* checkpoint_rules  */
  YYSYMBOL_checkpoint_control_rules = 204, /* checkpoint_control_rules  */
  YYSYMBOL_monitor_state_rules = 205,      /* monitor_state_rules  */
  YYSYMBOL_monitor_misc_rules = 206,       /* monitor_misc_rules  */
  YYSYMBOL_disk_rules = 207,               /* disk_rules  */
  YYSYMBOL_cmd_file_rules = 208,           /* cmd_file_rules  */
  YYSYMBOL_data_entry_rules = 209,         /* data_entry_rules  */
  YYSYMBOL_monitor_debug_rules = 210,      /* monitor_debug_rules  */
  YYSYMBOL_rest_of_line = 211,             /* rest_of_line  */
  YYSYMBOL_opt_rest_of_line = 212,         /* opt_rest_of_line  */
  YYSYMBOL_rest_of_line_or_quoted = 213,   /* rest_of_line_or_quoted  */
  YYSYMBOL_filename = 214,                 /* filename  */
  YYSYMBOL_device_num = 215,               /* device_num  */
  YYSYMBOL_mem_op = 216,                   /* mem_op  */
  YYSYMBOL_opt_mem_op = 217,               /* opt_mem_op  */
  YYSYMBOL_register = 218,                 /* register  */
  YYSYMBOL_reg_list = 219,                 /* reg_list  */
  YYSYMBOL_reg_asgn = 220,                 /* reg_asgn  */
  YYSYMBOL_checkpt_num = 221,              /* checkpt_num  */
  YYSYMBOL_opt_context_num = 222,          /* opt_context_num  */
  YYSYMBOL_address_opt_range = 223,        /* address_opt_range  */
  YYSYMBOL_address_range = 224,            /* address_range  */
  YYSYMBOL_opt_address = 225,              /* opt_address  */
  YYSYMBOL_address = 226,                  /* address  */
  YYSYMBOL_opt_sep = 227,                  /* opt_sep  */
  YYSYMBOL_memspace = 228,                 /* memspace  */
  YYSYMBOL_memloc = 229,                   /* memloc  */
  YYSYMBOL_memaddr = 230,                  /* memaddr  */
  YYSYMBOL_expression = 231,               /* expression  */
  YYSYMBOL_opt_if_cond_expr = 232,         /* opt_if_cond_expr  */
  YYSYMBOL_cond_expr = 233,                /* cond_expr  */
  YYSYMBOL_cond_operand = 234,             /* cond_operand  */
  YYSYMBOL_data_list = 235,                /* data_list  */
  YYSYMBOL_data_element = 236,             /* data_element  */
  YYSYMBOL_hunt_list = 237,                /* hunt_list  */
  YYSYMBOL_hunt_element = 238,             /* hunt_element  */
  YYSYMBOL_value = 239,                    /* value  */
  YYSYMBOL_d_number = 240,                 /* d_number  */
  YYSYMBOL_opt_d_number = 241,             /* opt_d_number  */
  YYSYMBOL_guess_default = 242,            /* guess_default  */
  YYSYMBOL_number = 243,                   /* number  */
  YYSYMBOL_assembly_instr_list = 244,      /* assembly_instr_list  */
  YYSYMBOL_assembly_instruction = 245,     /* assembly_instruction  */
  YYSYMBOL_post_assemble = 246,            /* post_assemble  */
  YYSYMBOL_asm_operand_mode = 247,         /* asm_operand_mode  */
  YYSYMBOL_index_reg = 248,                /* index_reg  */
  YYSYMBOL_index_ureg = 249                /* index_ureg  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  351
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1941

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  192
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  358
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  736

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   438


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     188,   189,   186,   184,     2,   185,     2,   187,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   191,     2,
       2,     2,     2,     2,   190,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   189,   189,   190,   191,   194,   195,   198,   199,   200,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   218,   220,   222,   224,   226,   228,   230,
     232,   234,   236,   238,   240,   242,   244,   246,   248,   250,
     252,   254,   256,   258,   260,   262,   264,   266,   268,   270,
     272,   274,   276,   278,   280,   282,   284,   286,   288,   293,
     297,   300,   302,   304,   307,   312,   317,   319,   321,   323,
     325,   327,   329,   331,   333,   335,   339,   346,   345,   348,
     350,   352,   356,   358,   360,   362,   364,   366,   368,   370,
     372,   374,   376,   378,   380,   382,   384,   386,   388,   390,
     392,   394,   398,   407,   410,   414,   417,   426,   429,   438,
     443,   445,   447,   449,   451,   453,   455,   457,   459,   461,
     463,   467,   469,   474,   481,   489,   496,   508,   512,   514,
     532,   534,   536,   538,   540,   542,   544,   548,   550,   552,
     554,   556,   558,   560,   562,   564,   566,   568,   570,   572,
     574,   576,   578,   580,   582,   584,   586,   588,   590,   592,
     594,   596,   598,   600,   602,   604,   606,   608,   610,   612,
     614,   616,   618,   620,   622,   626,   628,   630,   632,   634,
     636,   638,   640,   642,   644,   646,   648,   650,   652,   654,
     656,   658,   660,   662,   664,   666,   668,   672,   674,   676,
     680,   682,   686,   694,   697,   698,   701,   704,   705,   708,
     709,   712,   713,   716,   717,   720,   726,   734,   735,   738,
     742,   743,   746,   747,   750,   751,   754,   755,   757,   761,
     762,   765,   770,   775,   785,   786,   789,   790,   791,   792,
     793,   796,   798,   800,   801,   802,   803,   804,   805,   806,
     809,   810,   812,   817,   819,   821,   823,   827,   833,   840,
     853,   867,   868,   871,   872,   875,   876,   879,   880,   881,
     884,   885,   888,   889,   890,   891,   894,   895,   898,   899,
     900,   903,   904,   905,   906,   907,   910,   911,   912,   915,
     925,   926,   929,   936,   947,   958,   966,   985,   991,   999,
    1007,  1009,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1019,
    1021,  1023,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,
    1033,  1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,
    1043,  1045,  1046,  1061,  1065,  1069,  1073,  1077,  1081,  1085,
    1089,  1093,  1105,  1120,  1124,  1128,  1132,  1136,  1140,  1144,
    1148,  1152,  1164,  1169,  1177,  1178,  1179,  1180,  1184
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
  "\"end of file\"", "error", "\"invalid token\"", "H_NUMBER", "D_NUMBER",
  "O_NUMBER", "B_NUMBER", "CONVERT_OP", "B_DATA", "H_RANGE_GUESS",
  "D_NUMBER_GUESS", "O_NUMBER_GUESS", "B_NUMBER_GUESS", "BAD_CMD",
  "MEM_OP", "IF", "MEM_COMP", "MEM_DISK8", "MEM_DISK9", "MEM_DISK10",
  "MEM_DISK11", "EQUALS", "TRAIL", "CMD_SEP", "LABEL_ASGN_COMMENT",
  "CMD_LOG", "CMD_LOGNAME", "CMD_SIDEFX", "CMD_DUMMY", "CMD_RETURN",
  "CMD_BLOCK_READ", "CMD_BLOCK_WRITE", "CMD_UP", "CMD_DOWN", "CMD_LOAD",
  "CMD_BASICLOAD", "CMD_SAVE", "CMD_VERIFY", "CMD_BVERIFY", "CMD_IGNORE",
  "CMD_HUNT", "CMD_FILL", "CMD_MOVE", "CMD_GOTO", "CMD_REGISTERS",
  "CMD_READSPACE", "CMD_WRITESPACE", "CMD_RADIX", "CMD_MEM_DISPLAY",
  "CMD_BREAK", "CMD_TRACE", "CMD_IO", "CMD_BRMON", "CMD_COMPARE",
  "CMD_DUMP", "CMD_UNDUMP", "CMD_EXIT", "CMD_DELETE", "CMD_CONDITION",
  "CMD_COMMAND", "CMD_ASSEMBLE", "CMD_DISASSEMBLE", "CMD_NEXT", "CMD_STEP",
  "CMD_PRINT", "CMD_DEVICE", "CMD_HELP", "CMD_WATCH", "CMD_DISK",
  "CMD_QUIT", "CMD_CHDIR", "CMD_BANK", "CMD_LOAD_LABELS",
  "CMD_SAVE_LABELS", "CMD_ADD_LABEL", "CMD_DEL_LABEL", "CMD_SHOW_LABELS",
  "CMD_CLEAR_LABELS", "CMD_RECORD", "CMD_MON_STOP", "CMD_PLAYBACK",
  "CMD_CHAR_DISPLAY", "CMD_SPRITE_DISPLAY", "CMD_TEXT_DISPLAY",
  "CMD_SCREENCODE_DISPLAY", "CMD_ENTER_DATA", "CMD_ENTER_BIN_DATA",
  "CMD_KEYBUF", "CMD_BLOAD", "CMD_BSAVE", "CMD_SCREEN", "CMD_UNTIL",
  "CMD_CPU", "CMD_YYDEBUG", "CMD_BACKTRACE", "CMD_SCREENSHOT", "CMD_PWD",
  "CMD_DIR", "CMD_MKDIR", "CMD_RMDIR", "CMD_RESOURCE_GET",
  "CMD_RESOURCE_SET", "CMD_LOAD_RESOURCES", "CMD_SAVE_RESOURCES",
  "CMD_ATTACH", "CMD_DETACH", "CMD_MON_RESET", "CMD_TAPECTRL",
  "CMD_TAPEOFFS", "CMD_CARTFREEZE", "CMD_UPDB", "CMD_JPDB",
  "CMD_CPUHISTORY", "CMD_MEMMAPZAP", "CMD_MEMMAPSHOW", "CMD_MEMMAPSAVE",
  "CMD_COMMENT", "CMD_LIST", "CMD_STOPWATCH", "RESET", "CMD_EXPORT",
  "CMD_AUTOSTART", "CMD_AUTOLOAD", "CMD_MAINCPU_TRACE", "CMD_WARP",
  "CMD_PROFILE", "FLAT", "GRAPH", "FUNC", "DEPTH", "DISASS",
  "PROFILE_CONTEXT", "CLEAR", "CMD_LABEL_ASGN", "L_PAREN", "R_PAREN",
  "ARG_IMMEDIATE", "REG_A", "REG_X", "REG_Y", "COMMA", "INST_SEP",
  "L_BRACKET", "R_BRACKET", "LESS_THAN", "REG_U", "REG_S", "REG_PC",
  "REG_PCR", "REG_B", "REG_C", "REG_D", "REG_E", "REG_H", "REG_L",
  "REG_AF", "REG_BC", "REG_DE", "REG_HL", "REG_IX", "REG_IY", "REG_SP",
  "REG_IXH", "REG_IXL", "REG_IYH", "REG_IYL", "PLUS", "MINUS", "STRING",
  "FILENAME", "R_O_L", "R_O_L_Q", "OPCODE", "LABEL", "BANKNAME", "CPUTYPE",
  "MON_REGISTER", "COND_OP", "RADIX_TYPE", "INPUT_SPEC", "CMD_CHECKPT_ON",
  "CMD_CHECKPT_OFF", "TOGGLE", "MASK", "'+'", "'-'", "'*'", "'/'", "'('",
  "')'", "'@'", "':'", "$accept", "top_level", "command_list", "end_cmd",
  "command", "machine_state_rules", "register_mod", "symbol_table_rules",
  "asm_rules", "$@1", "memory_rules", "checkpoint_rules",
  "checkpoint_control_rules", "monitor_state_rules", "monitor_misc_rules",
  "disk_rules", "cmd_file_rules", "data_entry_rules",
  "monitor_debug_rules", "rest_of_line", "opt_rest_of_line",
  "rest_of_line_or_quoted", "filename", "device_num", "mem_op",
  "opt_mem_op", "register", "reg_list", "reg_asgn", "checkpt_num",
  "opt_context_num", "address_opt_range", "address_range", "opt_address",
  "address", "opt_sep", "memspace", "memloc", "memaddr", "expression",
  "opt_if_cond_expr", "cond_expr", "cond_operand", "data_list",
  "data_element", "hunt_list", "hunt_element", "value", "d_number",
  "opt_d_number", "guess_default", "number", "assembly_instr_list",
  "assembly_instruction", "post_assemble", "asm_operand_mode", "index_reg",
  "index_ureg", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-530)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-236)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1360,   776,  -530,  -530,     2,     6,    68,    84,   159,   776,
     776,   118,   118,     6,     6,     6,     6,     6,   799,  1683,
    1683,  1683,  1306,   439,    49,  1088,  1113,  1113,  1306,  1683,
       6,     6,   159,   698,   799,   799,  1719,  1169,   118,   118,
     776,  1125,   198,  1113,  -161,   159,  -131,   548,   672,   672,
    1719,   386,  1125,  1125,     6,   159,     6,  1169,  1169,  1169,
    1169,  1719,   159,  -161,     6,     6,  1306,  1169,   298,   159,
     159,     6,   159,  -128,  -131,  -131,   -98,   -93,     6,     6,
       6,   776,   118,   -60,   118,   159,  1253,  1253,  1801,   159,
     118,     6,  -128,   971,   499,   159,     6,     6,   130,   154,
     875,    74,  1760,   698,   698,   108,  1517,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,    88,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,   776,  -530,   -56,   104,  -530,
    -530,  -530,  -530,  -530,  -530,   159,  -530,  -530,  -530,   159,
     159,  -530,   159,  -530,  -530,   742,   742,  -530,  -530,   776,
    -530,   776,  1224,  1224,  1238,  1224,  1224,  -530,  -530,  -530,
    -530,  -530,   118,  -530,  -530,  -530,   -60,   -60,   -60,  -530,
    -530,  -530,   -60,   -60,  -530,   159,   -60,  -530,   112,   459,
    -530,   329,   159,  -530,   -60,  -530,   159,  -530,   421,  -530,
    -530,   102,  1683,  -530,  1683,  -530,   159,   -60,   159,   159,
    -530,   398,  -530,   159,   110,    73,   315,  -530,   159,  -530,
     776,  -530,   776,   104,  -530,   159,  -530,  -530,   159,  -530,
    1683,   159,  -530,  -530,   159,   159,  -530,   369,   159,   -60,
     159,   -60,   -60,   159,   -60,  -530,   159,  -530,   159,   159,
    -530,   159,  -530,   159,  -530,   159,  -530,   159,  -530,   159,
     631,  -530,   159,  1224,  1224,  -530,   159,  -530,   159,   159,
    -530,  -530,  -530,   118,  -530,  -530,   159,   159,   159,   159,
     -23,   159,   159,   776,   104,  -530,   776,   776,  -530,   776,
    -530,   159,  1253,  -530,  1186,  -530,  -530,   776,   -60,   159,
     652,  -530,   159,  -530,   159,  -530,  -530,   938,   938,   159,
    -530,   159,  -530,   138,   138,  1719,  1719,   138,  1719,   159,
    -530,  1719,  1060,  1253,    11,    59,  1789,  1253,    34,  -530,
      48,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,    55,  -530,  -530,   159,  -530,
     159,  -530,  -530,  -530,     7,  -530,   776,   776,   776,   776,
    -530,  -530,  -530,  -530,  -530,    95,   812,   104,   104,  -530,
     557,   557,  1329,  1352,   557,  1642,  -530,   776,   374,  1719,
    1265,   631,  1719,  -530,  1253,  1253,   748,  -530,  -530,  -530,
    1683,  -530,  -530,   163,   163,  -530,  1719,  -530,  -530,  -530,
     413,   159,    33,  -530,    39,  -530,   104,   104,  -530,  -530,
    -530,   163,  -530,  -530,  -530,  -530,    32,  -530,     6,  -530,
       6,    43,  -530,    50,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,  -530,  1739,  -530,  -530,  -530,  1665,  1494,  -530,
    -530,  -530,  -530,   776,  -530,  -530,  -530,  -530,   159,  -530,
    -530,   104,  -530,   104,   104,   104,  -530,   159,  1023,  1023,
     474,   776,  -530,  -530,  -530,  -530,  1253,  -530,  1253,  -530,
    -530,  -530,   159,   626,  -530,   159,   159,   159,   159,  -530,
     502,    89,   101,   103,   109,   117,   122,   -67,  -530,   219,
    -530,  -530,  -530,  -530,   208,    98,  -530,    99,   675,   119,
     121,    90,  -530,   219,   219,  1150,  -530,  -530,  -530,  -530,
     -25,   -25,  -530,  -530,   159,  1719,   159,  -530,  -530,   159,
     159,  -530,   159,   159,  -530,   159,   104,  -530,  -530,   869,
    -530,  -530,  -530,  -530,  -530,  1739,   159,  -530,  -530,   159,
     413,   159,   159,   159,   413,    91,  -530,   186,  -530,  -530,
    -530,   159,   127,   128,   159,  -530,  -530,   159,   159,   159,
     159,   159,   159,  -530,   631,  -530,   159,  -530,   159,   104,
    -530,  -530,  -530,  -530,  -530,  -530,  -530,   866,  -530,   866,
    -530,   159,   104,   159,   159,  -530,   138,  -530,  -530,  -530,
    -530,  -530,   159,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
     137,  -134,  -530,   219,  -530,   120,   219,   710,   -66,   219,
     219,   722,   143,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,   107,  -530,  -530,  -530,    12,
     106,   153,  -530,  -530,    39,    39,  -530,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,  -530,  -530,  1023,  1023,  -530,
    -530,  -530,  -530,   159,  -530,   507,   157,   160,  -530,  -530,
     164,   219,   171,  -530,   -57,   172,   176,   179,   183,   161,
    -530,  -530,  1701,  -530,  -530,  -530,  -530,  -530,   866,  -530,
     866,  -530,  -530,  -530,  -530,  -530,  -530,  -530,   188,  -530,
     197,  -530,  -530,   202,  -530,  -530,  -530,  -530,  -530,   413,
    -530,  1023,  1023,   217,  -530,  -530,  -112,  -530,   866,  -530,
     866,  -530,  -530,  1023,  1023,  -530,   866,  -530,   866,   159,
    1023,  -530,  -530,   866,   159,  -530
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,    22,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,   205,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   312,     0,     0,     0,     2,     5,    10,    60,
      11,    13,    12,    14,    15,    16,    17,    18,    19,    20,
      21,     0,   281,   283,   284,   282,   279,   280,   278,   236,
     237,   238,   239,   240,   215,     0,   271,     0,     0,   249,
     285,   270,     9,     8,     7,     0,   126,   208,   207,     0,
       0,   122,     0,   124,    45,     0,     0,   234,    52,     0,
      54,     0,     0,     0,     0,     0,     0,   221,   272,   274,
     275,   273,     0,   220,   227,   233,   235,   235,   235,   231,
     241,   242,   235,   235,    28,     0,   235,    61,     0,     0,
     218,     0,     0,   129,   235,    88,     0,   224,   235,   212,
     103,   213,     0,   109,     0,    29,     0,   235,     0,     0,
     134,     9,   117,     0,     0,     0,     0,    81,     0,    50,
       0,    48,     0,     0,   130,     0,   203,   139,     0,   107,
       0,     0,   133,   206,     0,     0,    23,     0,     0,   235,
       0,   235,   235,     0,   235,    72,     0,    74,     0,     0,
     198,     0,    90,     0,    92,     0,    94,     0,    96,     0,
       0,   201,     0,     0,     0,    56,     0,   105,     0,     0,
      31,   202,   144,     0,   146,   204,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   155,     0,     0,   158,     0,
     160,     0,     0,    33,     0,    97,    98,     0,   235,     0,
       9,   189,     0,   209,     0,   165,   132,     0,     0,     0,
     135,     0,    58,   277,   223,     0,     0,     0,     0,     0,
     167,     0,     0,     0,   313,     0,     0,     0,   314,   315,
     316,   317,   318,   321,   324,   325,   326,   327,   328,   329,
     330,   319,   322,   320,   323,   293,   289,   111,     0,   113,
       0,     1,     6,     3,     0,   216,     0,     0,     0,     0,
     141,   125,   127,   121,   123,   235,     0,     0,     0,   210,
     235,   235,   180,     0,   235,     0,   114,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,    63,    62,   128,
       0,    87,   211,   251,   251,    30,     0,    46,    47,   116,
       0,     0,     0,    79,     0,    80,     0,     0,   138,   131,
     140,   251,   137,   142,    25,    24,     0,    65,     0,    67,
       0,     0,    69,     0,    71,    73,   197,   199,    89,    91,
      93,    95,   264,     0,   262,   263,   143,     0,     0,    57,
     104,    32,   149,     0,   145,   147,   148,   151,     0,   153,
     154,     0,   192,     0,     0,     0,   161,     0,     0,     0,
       0,     0,   163,   190,   164,   193,     0,   195,     0,   136,
      59,   276,     0,     0,   222,     0,     0,     0,     0,   166,
       0,     0,     0,     0,     0,     0,     0,     0,   292,     0,
     354,   355,   358,   357,     0,   337,   356,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   110,   112,   248,   247,
     243,   244,   245,   246,     0,     0,     0,    53,    55,     0,
       0,   181,     0,     0,   186,     0,     0,   269,   268,     0,
     266,   267,   226,   228,   232,     0,     0,   219,   217,     0,
       0,     0,     0,     0,     0,     0,   257,     0,   256,   258,
     120,     0,   291,   290,     0,    51,    49,     0,     0,     0,
       0,     0,     0,   200,     0,   178,     0,   183,     0,     0,
     152,   191,   156,   157,   159,   162,    34,     0,    39,     0,
      99,     0,     0,     0,     0,   168,     0,   169,   171,   172,
     174,   173,     0,    75,   302,   303,   304,   305,   306,   307,
     298,     0,   339,     0,   335,   333,     0,     0,     0,     0,
       0,     0,   352,   338,   340,   294,   295,   296,   341,   297,
     332,   187,   229,   188,   175,   176,   179,   184,   185,   115,
      85,   265,    84,    82,    86,   250,   102,   108,    83,     0,
       0,     0,   118,   119,     0,   288,    78,   106,    26,    64,
      66,    68,    70,   261,   177,   182,   150,     0,     0,   100,
     101,   194,   196,     0,    76,     0,     0,     0,   336,   334,
       0,     0,     0,   347,     0,     0,     0,     0,     0,     0,
     255,   254,     0,   253,   252,   286,   287,    35,     0,    40,
       0,   170,   308,   301,   309,   310,   311,   299,     0,   349,
       0,   345,   343,     0,   348,   350,   351,   342,   353,     0,
     260,     0,     0,     0,   346,   344,     0,    36,     0,    41,
       0,   300,   259,     0,     0,    37,     0,    42,     0,     0,
       0,    38,    43,     0,     0,    44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -530,  -530,  -530,    -6,   235,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,   -15,
     267,    93,   318,   671,  -530,    72,   -13,  -530,   -26,   646,
    -530,    44,    38,  -156,   289,   500,   572,  -350,  -530,   691,
    -356,  -529,  -530,   -12,  -193,  -530,  -153,  -530,    10,  -530,
    -530,   703,  -530,  -390,  -530,  -530,   405,  -124
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   105,   106,   146,   107,   108,   109,   110,   111,   404,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   228,
     276,   234,   149,   302,   201,   202,   136,   189,   190,   172,
     473,   196,   197,   514,   198,   515,   137,   179,   180,   138,
     541,   547,   548,   433,   434,   529,   530,   139,   303,   472,
     140,   181,   552,   121,   554,   346,   495,   496
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     151,   153,   154,   142,   666,   158,   160,   147,   508,   226,
     188,   635,   667,   680,   553,   639,   184,   187,   193,   195,
     200,   203,   205,   722,   143,   144,   210,   212,   173,   231,
     534,   217,   219,   221,   534,   224,   227,   229,   542,   232,
     233,   236,   275,   173,   173,   173,   245,   247,   262,   250,
     142,   252,   254,   256,   258,   557,   261,   176,   182,   183,
     265,   267,   270,   271,   272,   641,   274,   207,   600,   142,
     279,   143,   144,   601,   401,   280,   285,   673,   288,   290,
     157,   218,   293,   295,   296,   142,   702,   301,   305,   306,
     143,   144,   310,   312,   320,   321,  -230,   347,   349,   204,
     674,   253,   255,   257,   259,   142,   143,   144,   351,   703,
     353,   268,   684,   173,   173,   230,   392,  -230,  -230,   142,
     355,  -235,  -235,  -235,  -235,   400,   143,   144,  -235,  -235,
    -235,   142,   360,   385,  -235,  -235,  -235,  -235,  -235,   361,
     143,   144,   168,   362,   363,   448,   364,   681,   169,   170,
     171,   489,   143,   144,   683,   142,   122,   123,   124,   125,
     142,   358,   359,   126,   127,   128,   376,   277,   278,   129,
     130,   131,   132,   133,   503,   148,   143,   144,   540,   383,
     716,   143,   144,   387,   145,   388,   389,   142,   504,   641,
     391,   356,   357,   358,   359,   505,   509,   490,   491,   142,
     395,   551,   397,   398,   492,   493,   558,   399,   143,   144,
     403,   102,   405,   157,   519,   520,   561,   408,   523,   409,
     143,   144,   410,   562,   594,   412,   494,   192,   413,   414,
     611,   415,   417,   612,   419,   157,   595,   422,   596,   606,
     424,  -235,   425,   426,   597,   427,   393,   428,   394,   429,
     150,   430,   598,   431,   685,   686,   436,   599,   157,   609,
     439,   610,   440,   441,   605,   640,   152,   442,   644,   645,
     444,   445,   446,   447,   411,   449,   450,   665,   452,   356,
     357,   358,   359,   679,   641,   456,   669,   544,   356,   357,
     358,   359,   697,   462,  -235,   698,   463,   682,   464,   142,
     708,   465,   467,   469,   459,   470,  -235,   699,   177,   177,
     177,   185,   309,   479,   701,   704,   142,   206,   177,   705,
     143,   144,   706,   471,   474,   216,   707,   477,   713,   134,
     142,   162,   163,   164,   165,   166,   311,   143,   144,   242,
     714,   352,   506,   545,   507,   715,   490,   491,   208,   209,
     260,   143,   144,   492,   493,   266,   721,   490,   491,   299,
     538,   517,   518,   641,   492,   493,   238,   240,   226,   535,
     142,   653,   249,   188,   251,   603,   631,   122,   123,   124,
     125,   620,   263,   264,   126,   127,   128,   546,     0,   273,
       0,   143,   144,     0,     0,   550,   281,   282,   283,  -221,
     555,   556,   129,   130,   131,   132,   133,     0,     0,   298,
       0,   522,     0,     0,   307,   308,   122,   123,   124,   125,
    -221,  -221,  -225,   126,   127,   128,     0,   563,     0,   129,
     130,   131,   132,   133,   539,     0,  -225,     0,     0,     0,
     142,     0,   570,  -225,  -225,   571,     0,   572,   573,   574,
       0,   575,   576,   578,   580,   129,   130,   131,   132,   133,
     142,   143,   144,     0,     0,     0,   585,   587,     0,   588,
     589,   590,   591,   269,   593,   142,   568,   122,   123,   124,
     125,   143,   144,   174,   126,   127,   128,   -77,     0,     0,
     129,   130,   131,   132,   133,     0,   143,   144,     0,     0,
     142,     0,     0,   142,   581,   355,     0,     0,   621,   157,
     623,   159,   161,   624,   625,     0,   626,   627,     0,   628,
     629,   143,   144,   630,   143,   144,   592,   546,     0,   632,
     633,   546,     0,   634,     0,   636,   637,   638,   220,   222,
       0,   642,   527,  -235,     0,   643,     0,   544,   646,   142,
       0,   647,   648,   649,   650,   651,   652,   528,  -230,   243,
     654,   157,   655,   656,   129,   130,   131,   132,   133,     0,
     143,   144,     0,     0,     0,   659,   660,   661,   662,  -230,
    -230,     0,   286,   287,   289,     0,   664,     0,   294,   134,
     297,   178,   178,   178,   186,   191,   663,   178,     0,   386,
     186,   178,     0,   545,   475,   476,     0,   478,   186,   178,
     480,     0,     0,   225,     0,   134,     0,     0,   304,   237,
     239,   241,   186,   244,   246,   248,     0,   142,   546,   178,
     178,   178,   178,   186,   122,   123,   124,   125,   186,   178,
       0,   126,   127,   128,   692,     0,   693,   175,   143,   144,
       0,   687,   689,  -210,     0,   516,     0,   691,   356,   357,
     358,   359,   177,     0,   525,   694,   695,   696,   532,     0,
       0,   536,   377,   147,  -210,  -210,   378,   379,   380,   213,
     214,   215,   381,   382,     0,   543,   384,     0,   129,   130,
     131,   132,   133,     0,   390,     0,   546,   157,   379,   211,
     155,   156,   168,     0,   141,   717,   719,   396,   169,   170,
     171,     0,   141,   141,     0,   402,     0,   725,   727,     0,
     143,   144,   235,   731,   732,     0,   566,   177,   735,     0,
       0,   223,     0,     0,     0,     0,   559,   416,   560,   418,
       0,   420,   421,   141,   423,   122,   123,   124,   125,   348,
     350,     0,   126,   127,   128,   586,     0,     0,   129,   130,
     131,   132,   133,     0,   129,   130,   131,   132,   133,     0,
       0,     0,   284,   443,   178,     0,   178,     0,     0,   122,
     123,   124,   125,     0,   141,     0,   126,   127,   128,   291,
     292,     0,   129,   130,   131,   132,   133,     0,   461,   432,
     167,     0,   178,   168,   622,   345,     0,   466,   468,   169,
     170,   171,     0,   490,   491,   122,   123,   124,   125,     0,
     492,   493,   126,   127,   128,     0,   354,     0,   129,   130,
     131,   132,   133,   370,   371,   373,   374,   375,   141,     0,
       0,   148,   607,     0,     0,     0,   365,   366,   490,   491,
     367,     0,   368,     0,     0,   492,   493,     0,   141,   141,
     490,   491,   141,     0,   141,     0,   458,   492,   493,   677,
     142,     0,   122,   123,   124,   125,   142,   671,     0,   126,
     127,   128,   129,   130,   131,   132,   133,   186,   186,     0,
     186,   143,   144,   186,   602,     0,     0,   143,   144,   604,
       0,     0,     0,   608,     0,     0,     0,     0,   613,   614,
       0,   406,     0,   407,     0,     0,     0,     0,   134,     0,
       0,     0,     0,   141,   134,   141,   356,   357,   358,   359,
     135,     0,     0,   564,   437,   438,     0,     0,   186,   142,
       0,  -235,  -235,  -235,  -235,   178,     0,   186,  -235,  -235,
    -235,   186,   134,     0,   186,     0,     0,     0,   577,   579,
     143,   144,   178,   435,   135,     0,     0,     0,   186,     0,
       0,   710,   300,     0,   451,   168,     0,   453,   454,     0,
     455,   169,   170,   171,     0,   175,   141,     0,   460,   141,
     141,     0,   141,   143,   144,   457,   356,   357,   358,   359,
     141,   313,   314,   315,     0,   316,   317,   318,   668,   186,
     178,   670,   672,     0,   675,   676,   678,     0,     0,     0,
       0,     0,     0,     0,   142,   487,   488,     0,     0,   501,
     502,     0,   178,     0,     0,   564,     0,   527,     0,  -235,
    -235,  -235,  -235,  -235,     0,   143,   144,   510,   511,   512,
     513,     0,   528,     0,     0,     0,     0,   319,     0,   141,
     141,   141,   141,   122,   123,   124,   125,     0,   526,     0,
     126,   127,   128,     0,     0,     0,   700,     0,   157,     0,
     141,   531,     0,     0,   435,     0,     0,   186,   537,   142,
       0,   122,   123,   124,   125,     0,     0,   174,   126,   127,
     128,     0,     0,   549,   129,   130,   131,   132,   133,     0,
     143,   144,     0,     0,   142,     0,  -214,  -214,  -214,  -214,
       0,     0,  -214,  -214,  -214,  -214,   142,   199,     0,  -214,
    -214,  -214,  -214,  -214,   569,   143,   144,     0,     0,     0,
       0,   129,   130,   131,   132,   133,   141,   143,   144,   657,
       0,   658,   582,   122,   123,   124,   125,   688,   690,     0,
     126,   127,   128,   157,   141,     0,     0,     0,     0,   583,
     142,   584,   122,   123,   124,   125,     0,     0,   174,   126,
     127,   128,     0,     0,     0,   129,   130,   131,   132,   133,
     168,   143,   144,     0,     0,     0,   169,   170,   171,     0,
       0,     0,   129,   130,   131,   132,   133,     0,   619,     0,
       0,   718,   720,     0,     0,     0,   481,   482,   483,   484,
     485,   486,     0,   726,   728,   369,     0,     0,   168,     0,
     733,     0,   531,     0,   169,   170,   171,     0,     0,   372,
       0,     0,   168,   549,     0,     0,     0,   549,   169,   170,
     171,     0,     0,     0,   186,     0,   122,   123,   124,   125,
     711,   175,   712,   126,   127,   128,   194,   435,   122,   123,
     124,   125,     0,     0,   533,   126,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,  -214,     0,   615,   616,
     723,     0,   724,     0,     0,   492,   617,   618,   729,     0,
     730,     0,     0,     0,     0,   734,     0,   142,     0,   122,
     123,   124,   125,     0,     0,     0,   126,   127,   128,     0,
       0,     0,   129,   130,   131,   132,   133,     0,   143,   144,
    -210,     0,  -210,  -210,  -210,  -210,     0,     0,  -210,  -210,
    -210,  -210,   175,     0,   549,  -210,  -210,  -210,  -210,  -210,
       0,     0,     0,   521,     0,   122,   123,   124,   125,     0,
       0,   174,   126,   127,   128,     0,     0,     1,   129,   130,
     131,   132,   133,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,     0,    24,    25,    26,
      27,    28,   549,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,   175,
      95,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,     0,   101,     0,   567,     0,   122,   123,   124,
     125,     0,  -210,   174,   126,   127,   128,     0,     0,     0,
     129,   130,   131,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,   175,     0,     0,     0,     0,
       2,     0,   102,     0,     0,     0,     0,     0,     0,     0,
     103,   104,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     0,     0,    24,    25,    26,    27,    28,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,     0,    95,    96,    97,
      98,    99,   100,   524,     0,   122,   123,   124,   125,     0,
     101,     0,   126,   127,   128,     0,     0,     0,   129,   130,
     131,   132,   133,     0,     0,     0,   565,   175,   122,   123,
     124,   125,     0,     0,     0,   126,   127,   128,     0,     0,
       0,   129,   130,   131,   132,   133,   122,   123,   124,   125,
       0,     0,   174,   126,   127,   128,     0,   103,   104,   129,
     130,   131,   132,   133,   122,   123,   124,   125,     0,     0,
       0,   126,   127,   128,     0,     0,     0,   129,   130,   131,
     132,   133,   122,   123,   124,   125,     0,     0,     0,   126,
     127,   128,     0,     0,     0,   129,   130,   131,   132,   133,
     142,     0,  -235,  -235,  -235,  -235,     0,     0,     0,  -235,
    -235,  -235,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   122,   123,   124,   125,     0,     0,     0,
     126,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,   123,   124,   125,     0,     0,     0,   126,
     127,   128,   142,     0,     0,  -235,     0,     0,     0,     0,
       0,  -235,  -235,  -235,     0,   175,     0,  -235,  -235,  -235,
    -235,  -235,     0,   143,   144,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   709,     0,     0,   175,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   175,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   175,     0,     0,     0,     0,   157,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   175,     0,   322,     0,   323,   324,     0,     0,
     325,     0,   326,     0,   327,     0,     0,  -235,     0,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   497,     0,     0,   498,
       0,     0,     0,     0,     0,     0,     0,     0,   499,     0,
     500,   157
};

static const yytype_int16 yycheck[] =
{
       6,     7,     8,     1,   138,    11,    12,     1,     1,   170,
      23,   540,   146,     1,   404,   544,    22,    23,    24,    25,
      26,    27,    28,   135,    22,    23,    32,    33,    18,    44,
     380,    37,    38,    39,   384,    41,    42,    43,   394,    45,
     171,    47,   170,    33,    34,    35,    52,    53,    63,    55,
       1,    57,    58,    59,    60,   411,    62,    19,    20,    21,
      66,    67,    68,    69,    70,   177,    72,    29,   135,     1,
     168,    22,    23,   140,     1,   168,    82,   143,    84,    85,
     140,    37,    88,    89,    90,     1,   143,    93,    94,    95,
      22,    23,    98,    99,   100,    21,     1,   103,   104,    27,
     166,    57,    58,    59,    60,     1,    22,    23,     0,   166,
      22,    67,   641,   103,   104,    43,    14,    22,    23,     1,
     176,     3,     4,     5,     6,    15,    22,    23,    10,    11,
      12,     1,   138,    21,    16,    17,    18,    19,    20,   145,
      22,    23,     4,   149,   150,   168,   152,   135,    10,    11,
      12,   140,    22,    23,     1,     1,     3,     4,     5,     6,
       1,   186,   187,    10,    11,    12,   172,    74,    75,    16,
      17,    18,    19,    20,   140,   169,    22,    23,    15,   185,
     709,    22,    23,   189,   182,   191,   192,     1,   140,   177,
     196,   184,   185,   186,   187,   140,   189,   138,   139,     1,
     206,   168,   208,   209,   145,   146,   174,   213,    22,    23,
     216,   172,   218,   140,   370,   371,   173,   223,   374,   225,
      22,    23,   228,   173,   135,   231,   167,   178,   234,   235,
     140,   237,   238,   143,   240,   140,   135,   243,   135,   140,
     246,   168,   248,   249,   135,   251,   202,   253,   204,   255,
     182,   257,   135,   259,   644,   645,   262,   135,   140,   140,
     266,   140,   268,   269,   166,   174,   182,   273,   141,   141,
     276,   277,   278,   279,   230,   281,   282,   140,   284,   184,
     185,   186,   187,   140,   177,   291,   166,   134,   184,   185,
     186,   187,   135,   299,   176,   135,   302,   191,   304,     1,
     139,   307,   308,   309,   294,   311,   188,   143,    19,    20,
      21,    22,   182,   319,   143,   143,     1,    28,    29,   143,
      22,    23,   143,   313,   314,    36,   143,   317,   140,   176,
       1,    13,    14,    15,    16,    17,   182,    22,    23,    50,
     143,   106,   348,   190,   350,   143,   138,   139,    30,    31,
      61,    22,    23,   145,   146,    66,   139,   138,   139,    92,
     386,   367,   368,   177,   145,   146,    48,    49,   170,   381,
       1,   564,    54,   386,    56,   167,   529,     3,     4,     5,
       6,   505,    64,    65,    10,    11,    12,   400,    -1,    71,
      -1,    22,    23,    -1,    -1,   401,    78,    79,    80,     1,
     406,   407,    16,    17,    18,    19,    20,    -1,    -1,    91,
      -1,   373,    -1,    -1,    96,    97,     3,     4,     5,     6,
      22,    23,     1,    10,    11,    12,    -1,   433,    -1,    16,
      17,    18,    19,    20,   390,    -1,    15,    -1,    -1,    -1,
       1,    -1,   448,    22,    23,   451,    -1,   453,   454,   455,
      -1,   457,   458,   459,   460,    16,    17,    18,    19,    20,
       1,    22,    23,    -1,    -1,    -1,   472,   473,    -1,   475,
     476,   477,   478,   175,   480,     1,   438,     3,     4,     5,
       6,    22,    23,     9,    10,    11,    12,   172,    -1,    -1,
      16,    17,    18,    19,    20,    -1,    22,    23,    -1,    -1,
       1,    -1,    -1,     1,   460,   176,    -1,    -1,   514,   140,
     516,    11,    12,   519,   520,    -1,   522,   523,    -1,   525,
     526,    22,    23,   529,    22,    23,    24,   540,    -1,   535,
     536,   544,    -1,   539,    -1,   541,   542,   543,    38,    39,
      -1,   547,   168,   174,    -1,   551,    -1,   134,   554,     1,
      -1,   557,   558,   559,   560,   561,   562,   183,     1,   173,
     566,   140,   568,   569,    16,    17,    18,    19,    20,    -1,
      22,    23,    -1,    -1,    -1,   581,   582,   583,   584,    22,
      23,    -1,    82,    83,    84,    -1,   592,    -1,    88,   176,
      90,    19,    20,    21,    22,    23,   586,    25,    -1,   140,
      28,    29,    -1,   190,   315,   316,    -1,   318,    36,    37,
     321,    -1,    -1,    41,    -1,   176,    -1,    -1,   119,    47,
      48,    49,    50,    51,    52,    53,    -1,     1,   641,    57,
      58,    59,    60,    61,     3,     4,     5,     6,    66,    67,
      -1,    10,    11,    12,   137,    -1,   139,   173,    22,    23,
      -1,   657,   658,     1,    -1,   366,    -1,   663,   184,   185,
     186,   187,   373,    -1,   375,   158,   159,   160,   379,    -1,
      -1,   382,   172,     1,    22,    23,   176,   177,   178,    33,
      34,    35,   182,   183,    -1,   396,   186,    -1,    16,    17,
      18,    19,    20,    -1,   194,    -1,   709,   140,   198,     1,
       9,    10,     4,    -1,     1,   711,   712,   207,    10,    11,
      12,    -1,     9,    10,    -1,   215,    -1,   723,   724,    -1,
      22,    23,   174,   729,   730,    -1,   437,   438,   734,    -1,
      -1,    40,    -1,    -1,    -1,    -1,   418,   237,   420,   239,
      -1,   241,   242,    40,   244,     3,     4,     5,     6,   103,
     104,    -1,    10,    11,    12,   129,    -1,    -1,    16,    17,
      18,    19,    20,    -1,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    81,   273,   202,    -1,   204,    -1,    -1,     3,
       4,     5,     6,    -1,    81,    -1,    10,    11,    12,    86,
      87,    -1,    16,    17,    18,    19,    20,    -1,   298,   168,
       1,    -1,   230,     4,   515,   102,    -1,   307,   308,    10,
      11,    12,    -1,   138,   139,     3,     4,     5,     6,    -1,
     145,   146,    10,    11,    12,    -1,   135,    -1,    16,    17,
      18,    19,    20,   162,   163,   164,   165,   166,   135,    -1,
      -1,   169,   167,    -1,    -1,    -1,   155,   156,   138,   139,
     159,    -1,   161,    -1,    -1,   145,   146,    -1,   155,   156,
     138,   139,   159,    -1,   161,    -1,   294,   145,   146,   147,
       1,    -1,     3,     4,     5,     6,     1,   167,    -1,    10,
      11,    12,    16,    17,    18,    19,    20,   315,   316,    -1,
     318,    22,    23,   321,   489,    -1,    -1,    22,    23,   494,
      -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,   503,   504,
      -1,   220,    -1,   222,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,    -1,   220,   176,   222,   184,   185,   186,   187,
     188,    -1,    -1,   433,   263,   264,    -1,    -1,   366,     1,
      -1,     3,     4,     5,     6,   373,    -1,   375,    10,    11,
      12,   379,   176,    -1,   382,    -1,    -1,    -1,   458,   459,
      22,    23,   390,   260,   188,    -1,    -1,    -1,   396,    -1,
      -1,   682,     1,    -1,   283,     4,    -1,   286,   287,    -1,
     289,    10,    11,    12,    -1,   173,   283,    -1,   297,   286,
     287,    -1,   289,    22,    23,   292,   184,   185,   186,   187,
     297,   126,   127,   128,    -1,   130,   131,   132,   603,   437,
     438,   606,   607,    -1,   609,   610,   611,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,   322,   323,    -1,    -1,   326,
     327,    -1,   460,    -1,    -1,   535,    -1,   168,    -1,    16,
      17,    18,    19,    20,    -1,    22,    23,   356,   357,   358,
     359,    -1,   183,    -1,    -1,    -1,    -1,   182,    -1,   356,
     357,   358,   359,     3,     4,     5,     6,    -1,   377,    -1,
      10,    11,    12,    -1,    -1,    -1,   671,    -1,   140,    -1,
     377,   378,    -1,    -1,   381,    -1,    -1,   515,   385,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    10,    11,
      12,    -1,    -1,   400,    16,    17,    18,    19,    20,    -1,
      22,    23,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    10,    11,    12,     1,    14,    -1,    16,
      17,    18,    19,    20,   443,    22,    23,    -1,    -1,    -1,
      -1,    16,    17,    18,    19,    20,   443,    22,    23,   577,
      -1,   579,   461,     3,     4,     5,     6,   657,   658,    -1,
      10,    11,    12,   140,   461,    -1,    -1,    -1,    -1,   466,
       1,   468,     3,     4,     5,     6,    -1,    -1,     9,    10,
      11,    12,    -1,    -1,    -1,    16,    17,    18,    19,    20,
       4,    22,    23,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    -1,   505,    -1,
      -1,   711,   712,    -1,    -1,    -1,   156,   157,   158,   159,
     160,   161,    -1,   723,   724,     1,    -1,    -1,     4,    -1,
     730,    -1,   529,    -1,    10,    11,    12,    -1,    -1,     1,
      -1,    -1,     4,   540,    -1,    -1,    -1,   544,    10,    11,
      12,    -1,    -1,    -1,   682,    -1,     3,     4,     5,     6,
     688,   173,   690,    10,    11,    12,   178,   564,     3,     4,
       5,     6,    -1,    -1,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,   138,   139,
     718,    -1,   720,    -1,    -1,   145,   146,   147,   726,    -1,
     728,    -1,    -1,    -1,    -1,   733,    -1,     1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    -1,    22,    23,
       1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    10,
      11,    12,   173,    -1,   641,    16,    17,    18,    19,    20,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    10,    11,    12,    -1,    -1,     7,    16,    17,
      18,    19,    20,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,   709,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   173,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   133,    -1,     1,    -1,     3,     4,     5,
       6,    -1,   173,     9,    10,    11,    12,    -1,    -1,    -1,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,   173,    -1,    -1,    -1,    -1,
      13,    -1,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,   120,   121,   122,
     123,   124,   125,     1,    -1,     3,     4,     5,     6,    -1,
     133,    -1,    10,    11,    12,    -1,    -1,    -1,    16,    17,
      18,    19,    20,    -1,    -1,    -1,     1,   173,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      -1,    16,    17,    18,    19,    20,     3,     4,     5,     6,
      -1,    -1,     9,    10,    11,    12,    -1,   180,   181,    16,
      17,    18,    19,    20,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    -1,    16,    17,    18,
      19,    20,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    -1,    16,    17,    18,    19,    20,
       1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,     3,     4,     5,     6,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      11,    12,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,   173,    -1,    16,    17,    18,
      19,    20,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   173,    -1,   134,    -1,   136,   137,    -1,    -1,
     140,    -1,   142,    -1,   144,    -1,    -1,   168,    -1,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   137,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
     151,   140
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    13,    22,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    47,    48,    49,    50,    51,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   120,   121,   122,   123,   124,
     125,   133,   172,   180,   181,   193,   194,   196,   197,   198,
     199,   200,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   245,     3,     4,     5,     6,    10,    11,    12,    16,
      17,    18,    19,    20,   176,   188,   218,   228,   231,   239,
     242,   243,     1,    22,    23,   182,   195,     1,   169,   214,
     182,   195,   182,   195,   195,   231,   231,   140,   195,   227,
     195,   227,   214,   214,   214,   214,   214,     1,     4,    10,
      11,    12,   221,   240,     9,   173,   224,   226,   228,   229,
     230,   243,   224,   224,   195,   226,   228,   195,   218,   219,
     220,   228,   178,   195,   178,   195,   223,   224,   226,    14,
     195,   216,   217,   195,   217,   195,   226,   224,   214,   214,
     195,     1,   195,   221,   221,   221,   226,   195,   223,   195,
     227,   195,   227,   231,   195,   228,   170,   195,   211,   195,
     217,   211,   195,   171,   213,   174,   195,   228,   214,   228,
     214,   228,   226,   173,   228,   195,   228,   195,   228,   214,
     195,   214,   195,   223,   195,   223,   195,   223,   195,   223,
     226,   195,   211,   214,   214,   195,   226,   195,   223,   175,
     195,   195,   195,   214,   195,   170,   212,   213,   213,   168,
     168,   214,   214,   214,   231,   195,   227,   227,   195,   227,
     195,   243,   243,   195,   227,   195,   195,   227,   214,   212,
       1,   195,   215,   240,   119,   195,   195,   214,   214,   182,
     195,   182,   195,   126,   127,   128,   130,   131,   132,   182,
     195,    21,   134,   136,   137,   140,   142,   144,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   243,   247,   195,   221,   195,
     221,     0,   196,    22,   231,   176,   184,   185,   186,   187,
     195,   195,   195,   195,   195,   231,   231,   231,   231,     1,
     215,   215,     1,   215,   215,   215,   195,   227,   227,   227,
     227,   227,   227,   195,   227,    21,   140,   195,   195,   195,
     227,   195,    14,   223,   223,   195,   227,   195,   195,   195,
      15,     1,   227,   195,   201,   195,   231,   231,   195,   195,
     195,   223,   195,   195,   195,   195,   227,   195,   227,   195,
     227,   227,   195,   227,   195,   195,   195,   195,   195,   195,
     195,   195,   168,   235,   236,   243,   195,   215,   215,   195,
     195,   195,   195,   227,   195,   195,   195,   195,   168,   195,
     195,   231,   195,   231,   231,   231,   195,   243,   228,   240,
     231,   227,   195,   195,   195,   195,   227,   195,   227,   195,
     195,   240,   241,   222,   240,   226,   226,   240,   226,   195,
     226,   156,   157,   158,   159,   160,   161,   243,   243,   140,
     138,   139,   145,   146,   167,   248,   249,   137,   140,   149,
     151,   243,   243,   140,   140,   140,   195,   195,     1,   189,
     231,   231,   231,   231,   225,   227,   226,   195,   195,   225,
     225,     1,   224,   225,     1,   226,   231,   168,   183,   237,
     238,   243,   226,     9,   229,   235,   226,   243,   220,   223,
      15,   232,   232,   226,   134,   190,   218,   233,   234,   243,
     195,   168,   244,   245,   246,   195,   195,   232,   174,   214,
     214,   173,   173,   195,   227,     1,   226,     1,   224,   231,
     195,   195,   195,   195,   195,   195,   195,   227,   195,   227,
     195,   223,   231,   243,   243,   195,   129,   195,   195,   195,
     195,   195,    24,   195,   135,   135,   135,   135,   135,   135,
     135,   140,   248,   167,   248,   166,   140,   167,   248,   140,
     140,   140,   143,   248,   248,   138,   139,   146,   147,   243,
     249,   195,   226,   195,   195,   195,   195,   195,   195,   195,
     195,   238,   195,   195,   195,   233,   195,   195,   195,   233,
     174,   177,   195,   195,   141,   141,   195,   195,   195,   195,
     195,   195,   195,   236,   195,   195,   195,   228,   228,   195,
     195,   195,   195,   240,   195,   140,   138,   146,   248,   166,
     248,   167,   248,   143,   166,   248,   248,   147,   248,   140,
       1,   135,   191,     1,   233,   245,   245,   195,   227,   195,
     227,   195,   137,   139,   158,   159,   160,   135,   135,   143,
     248,   143,   143,   166,   143,   143,   143,   143,   139,   134,
     226,   228,   228,   140,   143,   143,   233,   195,   227,   195,
     227,   139,   135,   228,   228,   195,   227,   195,   227,   228,
     228,   195,   195,   227,   228,   195
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   192,   193,   193,   193,   194,   194,   195,   195,   195,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   198,   198,   198,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   201,   200,   200,
     200,   200,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   203,   203,   203,   203,   203,   203,   203,   203,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   208,   208,   208,
     209,   209,   210,   211,   212,   212,   213,   214,   214,   215,
     215,   216,   216,   217,   217,   218,   218,   219,   219,   220,
     221,   221,   222,   222,   223,   223,   224,   224,   224,   225,
     225,   226,   226,   226,   227,   227,   228,   228,   228,   228,
     228,   229,   230,   231,   231,   231,   231,   231,   231,   231,
     232,   232,   233,   233,   233,   233,   233,   234,   234,   234,
     234,   235,   235,   236,   236,   237,   237,   238,   238,   238,
     239,   239,   240,   240,   240,   240,   241,   241,   242,   242,
     242,   243,   243,   243,   243,   243,   244,   244,   244,   245,
     246,   246,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   248,   248,   248,   248,   249
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     5,     3,     2,     2,
       3,     2,     3,     2,     4,     6,     8,    10,    12,     4,
       6,     8,    10,    12,    14,     2,     3,     3,     2,     4,
       2,     4,     2,     4,     2,     4,     2,     3,     2,     3,
       1,     2,     3,     3,     5,     3,     5,     3,     5,     3,
       5,     3,     2,     3,     2,     4,     5,     0,     5,     3,
       3,     2,     5,     5,     5,     5,     5,     3,     2,     3,
       2,     3,     2,     3,     2,     3,     2,     2,     2,     4,
       5,     5,     5,     2,     3,     2,     5,     2,     5,     2,
       3,     2,     3,     2,     3,     5,     3,     2,     5,     5,
       4,     3,     2,     3,     2,     3,     2,     3,     3,     2,
       2,     3,     2,     2,     2,     2,     3,     3,     3,     2,
       3,     3,     3,     3,     2,     3,     2,     3,     3,     3,
       5,     3,     4,     3,     3,     2,     4,     4,     2,     4,
       2,     3,     4,     3,     3,     2,     3,     2,     4,     4,
       6,     4,     4,     4,     4,     5,     5,     5,     4,     5,
       3,     4,     5,     4,     5,     5,     4,     5,     5,     2,
       3,     4,     3,     3,     5,     3,     5,     3,     2,     3,
       4,     2,     2,     1,     1,     0,     1,     1,     1,     1,
       1,     2,     1,     1,     0,     1,     2,     3,     1,     3,
       1,     1,     1,     0,     1,     1,     3,     1,     3,     2,
       0,     1,     3,     1,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     1,
       2,     0,     3,     3,     3,     3,     1,     1,     1,     6,
       4,     3,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     2,     2,
       1,     1,     2,     1,     3,     3,     3,     3,     3,     5,
       7,     5,     3,     3,     3,     3,     3,     3,     5,     5,
       5,     5,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     4,     3,     4,     2,     3,     3,
       3,     3,     5,     5,     6,     5,     6,     4,     5,     5,
       5,     5,     3,     5,     1,     1,     1,     1,     1
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
  case 2: /* top_level: command_list  */
#line 189 "mon_parse.y"
                        { (yyval.i) = 0; }
#line 2630 "mon_parse.c"
    break;

  case 3: /* top_level: assembly_instruction TRAIL  */
#line 190 "mon_parse.y"
                                      { (yyval.i) = 0; }
#line 2636 "mon_parse.c"
    break;

  case 4: /* top_level: TRAIL  */
#line 191 "mon_parse.y"
                 { new_cmd = 1; asm_mode = 0;  (yyval.i) = 0; }
#line 2642 "mon_parse.c"
    break;

  case 9: /* end_cmd: error  */
#line 200 "mon_parse.y"
               { return ERR_EXPECT_END_CMD; }
#line 2648 "mon_parse.c"
    break;

  case 22: /* command: BAD_CMD  */
#line 215 "mon_parse.y"
                 { return ERR_BAD_CMD; }
#line 2654 "mon_parse.c"
    break;

  case 23: /* machine_state_rules: CMD_BANK end_cmd  */
#line 219 "mon_parse.y"
                     { mon_bank(e_default_space, NULL); }
#line 2660 "mon_parse.c"
    break;

  case 24: /* machine_state_rules: CMD_BANK memspace end_cmd  */
#line 221 "mon_parse.y"
                     { mon_bank((yyvsp[-1].i), NULL); }
#line 2666 "mon_parse.c"
    break;

  case 25: /* machine_state_rules: CMD_BANK BANKNAME end_cmd  */
#line 223 "mon_parse.y"
                     { mon_bank(e_default_space, (yyvsp[-1].str)); }
#line 2672 "mon_parse.c"
    break;

  case 26: /* machine_state_rules: CMD_BANK memspace opt_sep BANKNAME end_cmd  */
#line 225 "mon_parse.y"
                     { mon_bank((yyvsp[-3].i), (yyvsp[-1].str)); }
#line 2678 "mon_parse.c"
    break;

  case 27: /* machine_state_rules: CMD_GOTO address end_cmd  */
#line 227 "mon_parse.y"
                     { mon_jump((yyvsp[-1].a)); }
#line 2684 "mon_parse.c"
    break;

  case 28: /* machine_state_rules: CMD_GOTO end_cmd  */
#line 229 "mon_parse.y"
                     { mon_go(); }
#line 2690 "mon_parse.c"
    break;

  case 29: /* machine_state_rules: CMD_IO end_cmd  */
#line 231 "mon_parse.y"
                     { mon_display_io_regs(0); }
#line 2696 "mon_parse.c"
    break;

  case 30: /* machine_state_rules: CMD_IO address end_cmd  */
#line 233 "mon_parse.y"
                     { mon_display_io_regs((yyvsp[-1].a)); }
#line 2702 "mon_parse.c"
    break;

  case 31: /* machine_state_rules: CMD_CPU end_cmd  */
#line 235 "mon_parse.y"
                     { monitor_cpu_type_set(""); }
#line 2708 "mon_parse.c"
    break;

  case 32: /* machine_state_rules: CMD_CPU CPUTYPE end_cmd  */
#line 237 "mon_parse.y"
                     { monitor_cpu_type_set((yyvsp[-1].str)); }
#line 2714 "mon_parse.c"
    break;

  case 33: /* machine_state_rules: CMD_CPUHISTORY end_cmd  */
#line 239 "mon_parse.y"
                     { mon_cpuhistory(-1, e_invalid_space,  e_invalid_space, e_invalid_space, e_invalid_space, e_invalid_space); }
#line 2720 "mon_parse.c"
    break;

  case 34: /* machine_state_rules: CMD_CPUHISTORY opt_sep memspace end_cmd  */
#line 241 "mon_parse.y"
                     { mon_cpuhistory(-1, (yyvsp[-1].i), e_invalid_space, e_invalid_space, e_invalid_space, e_invalid_space); }
#line 2726 "mon_parse.c"
    break;

  case 35: /* machine_state_rules: CMD_CPUHISTORY opt_sep memspace opt_sep memspace end_cmd  */
#line 243 "mon_parse.y"
                     { mon_cpuhistory(-1, (yyvsp[-3].i), (yyvsp[-1].i), e_invalid_space, e_invalid_space, e_invalid_space); }
#line 2732 "mon_parse.c"
    break;

  case 36: /* machine_state_rules: CMD_CPUHISTORY opt_sep memspace opt_sep memspace opt_sep memspace end_cmd  */
#line 245 "mon_parse.y"
                     { mon_cpuhistory(-1, (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].i), e_invalid_space, e_invalid_space); }
#line 2738 "mon_parse.c"
    break;

  case 37: /* machine_state_rules: CMD_CPUHISTORY opt_sep memspace opt_sep memspace opt_sep memspace opt_sep memspace end_cmd  */
#line 247 "mon_parse.y"
                     { mon_cpuhistory(-1, (yyvsp[-7].i), (yyvsp[-5].i), (yyvsp[-3].i),  (yyvsp[-1].i), e_invalid_space); }
#line 2744 "mon_parse.c"
    break;

  case 38: /* machine_state_rules: CMD_CPUHISTORY opt_sep memspace opt_sep memspace opt_sep memspace opt_sep memspace opt_sep memspace end_cmd  */
#line 249 "mon_parse.y"
                     { mon_cpuhistory(-1, (yyvsp[-9].i), (yyvsp[-7].i), (yyvsp[-5].i),  (yyvsp[-3].i), (yyvsp[-1].i)); }
#line 2750 "mon_parse.c"
    break;

  case 39: /* machine_state_rules: CMD_CPUHISTORY opt_sep d_number end_cmd  */
#line 251 "mon_parse.y"
                     { mon_cpuhistory((yyvsp[-1].i), e_invalid_space, e_invalid_space, e_invalid_space, e_invalid_space, e_invalid_space); }
#line 2756 "mon_parse.c"
    break;

  case 40: /* machine_state_rules: CMD_CPUHISTORY opt_sep d_number opt_sep memspace end_cmd  */
#line 253 "mon_parse.y"
                     { mon_cpuhistory((yyvsp[-3].i), (yyvsp[-1].i), e_invalid_space, e_invalid_space, e_invalid_space, e_invalid_space); }
#line 2762 "mon_parse.c"
    break;

  case 41: /* machine_state_rules: CMD_CPUHISTORY opt_sep d_number opt_sep memspace opt_sep memspace end_cmd  */
#line 255 "mon_parse.y"
                     { mon_cpuhistory((yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].i), e_invalid_space, e_invalid_space, e_invalid_space); }
#line 2768 "mon_parse.c"
    break;

  case 42: /* machine_state_rules: CMD_CPUHISTORY opt_sep d_number opt_sep memspace opt_sep memspace opt_sep memspace end_cmd  */
#line 257 "mon_parse.y"
                     { mon_cpuhistory((yyvsp[-7].i), (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].i), e_invalid_space, e_invalid_space); }
#line 2774 "mon_parse.c"
    break;

  case 43: /* machine_state_rules: CMD_CPUHISTORY opt_sep d_number opt_sep memspace opt_sep memspace opt_sep memspace opt_sep memspace end_cmd  */
#line 259 "mon_parse.y"
                     { mon_cpuhistory((yyvsp[-9].i), (yyvsp[-7].i), (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].i), e_invalid_space); }
#line 2780 "mon_parse.c"
    break;

  case 44: /* machine_state_rules: CMD_CPUHISTORY opt_sep d_number opt_sep memspace opt_sep memspace opt_sep memspace opt_sep memspace opt_sep memspace end_cmd  */
#line 261 "mon_parse.y"
                     { mon_cpuhistory((yyvsp[-11].i), (yyvsp[-9].i), (yyvsp[-7].i), (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].i)); }
#line 2786 "mon_parse.c"
    break;

  case 45: /* machine_state_rules: CMD_RETURN end_cmd  */
#line 263 "mon_parse.y"
                     { mon_instruction_return(); }
#line 2792 "mon_parse.c"
    break;

  case 46: /* machine_state_rules: CMD_DUMP filename end_cmd  */
#line 265 "mon_parse.y"
                     { mon_write_snapshot((yyvsp[-1].str),0,0,0); /* FIXME */ }
#line 2798 "mon_parse.c"
    break;

  case 47: /* machine_state_rules: CMD_UNDUMP filename end_cmd  */
#line 267 "mon_parse.y"
                     { mon_read_snapshot((yyvsp[-1].str), 0); }
#line 2804 "mon_parse.c"
    break;

  case 48: /* machine_state_rules: CMD_STEP end_cmd  */
#line 269 "mon_parse.y"
                     { mon_instructions_step(-1); }
#line 2810 "mon_parse.c"
    break;

  case 49: /* machine_state_rules: CMD_STEP opt_sep expression end_cmd  */
#line 271 "mon_parse.y"
                     { mon_instructions_step((yyvsp[-1].i)); }
#line 2816 "mon_parse.c"
    break;

  case 50: /* machine_state_rules: CMD_NEXT end_cmd  */
#line 273 "mon_parse.y"
                     { mon_instructions_next(-1); }
#line 2822 "mon_parse.c"
    break;

  case 51: /* machine_state_rules: CMD_NEXT opt_sep expression end_cmd  */
#line 275 "mon_parse.y"
                     { mon_instructions_next((yyvsp[-1].i)); }
#line 2828 "mon_parse.c"
    break;

  case 52: /* machine_state_rules: CMD_UP end_cmd  */
#line 277 "mon_parse.y"
                     { mon_stack_up(-1); }
#line 2834 "mon_parse.c"
    break;

  case 53: /* machine_state_rules: CMD_UP opt_sep expression end_cmd  */
#line 279 "mon_parse.y"
                     { mon_stack_up((yyvsp[-1].i)); }
#line 2840 "mon_parse.c"
    break;

  case 54: /* machine_state_rules: CMD_DOWN end_cmd  */
#line 281 "mon_parse.y"
                     { mon_stack_down(-1); }
#line 2846 "mon_parse.c"
    break;

  case 55: /* machine_state_rules: CMD_DOWN opt_sep expression end_cmd  */
#line 283 "mon_parse.y"
                     { mon_stack_down((yyvsp[-1].i)); }
#line 2852 "mon_parse.c"
    break;

  case 56: /* machine_state_rules: CMD_SCREEN end_cmd  */
#line 285 "mon_parse.y"
                     { mon_display_screen(-1); }
#line 2858 "mon_parse.c"
    break;

  case 57: /* machine_state_rules: CMD_SCREEN address end_cmd  */
#line 287 "mon_parse.y"
                     { mon_display_screen((yyvsp[-1].a)); }
#line 2864 "mon_parse.c"
    break;

  case 58: /* machine_state_rules: CMD_WARP end_cmd  */
#line 289 "mon_parse.y"
                     {
                        mon_out("Warp mode is %s.\n",
                                vsync_get_warp_mode() ? "on" : "off");
                     }
#line 2873 "mon_parse.c"
    break;

  case 59: /* machine_state_rules: CMD_WARP TOGGLE end_cmd  */
#line 294 "mon_parse.y"
                     {
                        vsync_set_warp_mode((((yyvsp[-1].action) == e_TOGGLE) ? (vsync_get_warp_mode() ^ 1) : (yyvsp[-1].action)));
                     }
#line 2881 "mon_parse.c"
    break;

  case 61: /* register_mod: CMD_REGISTERS end_cmd  */
#line 301 "mon_parse.y"
              { (monitor_cpu_for_memspace[default_memspace]->mon_register_print)(default_memspace); }
#line 2887 "mon_parse.c"
    break;

  case 62: /* register_mod: CMD_REGISTERS memspace end_cmd  */
#line 303 "mon_parse.y"
              { (monitor_cpu_for_memspace[(yyvsp[-1].i)]->mon_register_print)((yyvsp[-1].i)); }
#line 2893 "mon_parse.c"
    break;

  case 64: /* symbol_table_rules: CMD_LOAD_LABELS memspace opt_sep filename end_cmd  */
#line 308 "mon_parse.y"
                    {
                        /* What about the memspace? */
                        mon_playback_commands((yyvsp[-1].str),true);
                    }
#line 2902 "mon_parse.c"
    break;

  case 65: /* symbol_table_rules: CMD_LOAD_LABELS filename end_cmd  */
#line 313 "mon_parse.y"
                    {
                        /* What about the memspace? */
                        mon_playback_commands((yyvsp[-1].str),true);
                    }
#line 2911 "mon_parse.c"
    break;

  case 66: /* symbol_table_rules: CMD_SAVE_LABELS memspace opt_sep filename end_cmd  */
#line 318 "mon_parse.y"
                    { mon_save_symbols((yyvsp[-3].i), (yyvsp[-1].str)); }
#line 2917 "mon_parse.c"
    break;

  case 67: /* symbol_table_rules: CMD_SAVE_LABELS filename end_cmd  */
#line 320 "mon_parse.y"
                    { mon_save_symbols(e_default_space, (yyvsp[-1].str)); }
#line 2923 "mon_parse.c"
    break;

  case 68: /* symbol_table_rules: CMD_ADD_LABEL address opt_sep LABEL end_cmd  */
#line 322 "mon_parse.y"
                    { mon_add_name_to_symbol_table((yyvsp[-3].a), (yyvsp[-1].str)); }
#line 2929 "mon_parse.c"
    break;

  case 69: /* symbol_table_rules: CMD_DEL_LABEL LABEL end_cmd  */
#line 324 "mon_parse.y"
                    { mon_remove_name_from_symbol_table(e_default_space, (yyvsp[-1].str)); }
#line 2935 "mon_parse.c"
    break;

  case 70: /* symbol_table_rules: CMD_DEL_LABEL memspace opt_sep LABEL end_cmd  */
#line 326 "mon_parse.y"
                    { mon_remove_name_from_symbol_table((yyvsp[-3].i), (yyvsp[-1].str)); }
#line 2941 "mon_parse.c"
    break;

  case 71: /* symbol_table_rules: CMD_SHOW_LABELS memspace end_cmd  */
#line 328 "mon_parse.y"
                    { mon_print_symbol_table((yyvsp[-1].i)); }
#line 2947 "mon_parse.c"
    break;

  case 72: /* symbol_table_rules: CMD_SHOW_LABELS end_cmd  */
#line 330 "mon_parse.y"
                    { mon_print_symbol_table(e_default_space); }
#line 2953 "mon_parse.c"
    break;

  case 73: /* symbol_table_rules: CMD_CLEAR_LABELS memspace end_cmd  */
#line 332 "mon_parse.y"
                    { mon_clear_symbol_table((yyvsp[-1].i)); }
#line 2959 "mon_parse.c"
    break;

  case 74: /* symbol_table_rules: CMD_CLEAR_LABELS end_cmd  */
#line 334 "mon_parse.y"
                    { mon_clear_symbol_table(e_default_space); }
#line 2965 "mon_parse.c"
    break;

  case 75: /* symbol_table_rules: CMD_LABEL_ASGN EQUALS address end_cmd  */
#line 336 "mon_parse.y"
                    {
                        mon_add_name_to_symbol_table((yyvsp[-1].a), mon_prepend_dot_to_name((yyvsp[-3].str)));
                    }
#line 2973 "mon_parse.c"
    break;

  case 76: /* symbol_table_rules: CMD_LABEL_ASGN EQUALS address LABEL_ASGN_COMMENT end_cmd  */
#line 340 "mon_parse.y"
                    {
                        mon_add_name_to_symbol_table((yyvsp[-2].a), mon_prepend_dot_to_name((yyvsp[-4].str)));
                    }
#line 2981 "mon_parse.c"
    break;

  case 77: /* $@1: %empty  */
#line 346 "mon_parse.y"
           { mon_start_assemble_mode((yyvsp[0].a), NULL); }
#line 2987 "mon_parse.c"
    break;

  case 78: /* asm_rules: CMD_ASSEMBLE address $@1 post_assemble end_cmd  */
#line 347 "mon_parse.y"
           { }
#line 2993 "mon_parse.c"
    break;

  case 79: /* asm_rules: CMD_ASSEMBLE address end_cmd  */
#line 349 "mon_parse.y"
           { mon_start_assemble_mode((yyvsp[-1].a), NULL); }
#line 2999 "mon_parse.c"
    break;

  case 80: /* asm_rules: CMD_DISASSEMBLE address_opt_range end_cmd  */
#line 351 "mon_parse.y"
           { mon_disassemble_lines((yyvsp[-1].range)[0], (yyvsp[-1].range)[1]); }
#line 3005 "mon_parse.c"
    break;

  case 81: /* asm_rules: CMD_DISASSEMBLE end_cmd  */
#line 353 "mon_parse.y"
           { mon_disassemble_lines(BAD_ADDR, BAD_ADDR); }
#line 3011 "mon_parse.c"
    break;

  case 82: /* memory_rules: CMD_MOVE address_range opt_sep address end_cmd  */
#line 357 "mon_parse.y"
              { mon_memory_move((yyvsp[-3].range)[0], (yyvsp[-3].range)[1], (yyvsp[-1].a)); }
#line 3017 "mon_parse.c"
    break;

  case 83: /* memory_rules: CMD_COMPARE address_range opt_sep address end_cmd  */
#line 359 "mon_parse.y"
              { mon_memory_compare((yyvsp[-3].range)[0], (yyvsp[-3].range)[1], (yyvsp[-1].a)); }
#line 3023 "mon_parse.c"
    break;

  case 84: /* memory_rules: CMD_FILL address_range opt_sep data_list end_cmd  */
#line 361 "mon_parse.y"
              { mon_memory_fill((yyvsp[-3].range)[0], (yyvsp[-3].range)[1],(unsigned char *)(yyvsp[-1].str)); }
#line 3029 "mon_parse.c"
    break;

  case 85: /* memory_rules: CMD_HUNT address_range opt_sep hunt_list end_cmd  */
#line 363 "mon_parse.y"
              { mon_memory_hunt((yyvsp[-3].range)[0], (yyvsp[-3].range)[1],(unsigned char *)(yyvsp[-1].str)); }
#line 3035 "mon_parse.c"
    break;

  case 86: /* memory_rules: CMD_MEM_DISPLAY RADIX_TYPE opt_sep address_opt_range end_cmd  */
#line 365 "mon_parse.y"
              { mon_memory_display((yyvsp[-3].rt), (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], DF_PETSCII); }
#line 3041 "mon_parse.c"
    break;

  case 87: /* memory_rules: CMD_MEM_DISPLAY address_opt_range end_cmd  */
#line 367 "mon_parse.y"
              { mon_memory_display(default_radix, (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], DF_PETSCII); }
#line 3047 "mon_parse.c"
    break;

  case 88: /* memory_rules: CMD_MEM_DISPLAY end_cmd  */
#line 369 "mon_parse.y"
              { mon_memory_display(default_radix, BAD_ADDR, BAD_ADDR, DF_PETSCII); }
#line 3053 "mon_parse.c"
    break;

  case 89: /* memory_rules: CMD_CHAR_DISPLAY address_opt_range end_cmd  */
#line 371 "mon_parse.y"
              { mon_memory_display_data((yyvsp[-1].range)[0], (yyvsp[-1].range)[1], 8, 8); }
#line 3059 "mon_parse.c"
    break;

  case 90: /* memory_rules: CMD_CHAR_DISPLAY end_cmd  */
#line 373 "mon_parse.y"
              { mon_memory_display_data(BAD_ADDR, BAD_ADDR, 8, 8); }
#line 3065 "mon_parse.c"
    break;

  case 91: /* memory_rules: CMD_SPRITE_DISPLAY address_opt_range end_cmd  */
#line 375 "mon_parse.y"
              { mon_memory_display_data((yyvsp[-1].range)[0], (yyvsp[-1].range)[1], 24, 21); }
#line 3071 "mon_parse.c"
    break;

  case 92: /* memory_rules: CMD_SPRITE_DISPLAY end_cmd  */
#line 377 "mon_parse.y"
              { mon_memory_display_data(BAD_ADDR, BAD_ADDR, 24, 21); }
#line 3077 "mon_parse.c"
    break;

  case 93: /* memory_rules: CMD_TEXT_DISPLAY address_opt_range end_cmd  */
#line 379 "mon_parse.y"
              { mon_memory_display(e_text, (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], DF_PETSCII); }
#line 3083 "mon_parse.c"
    break;

  case 94: /* memory_rules: CMD_TEXT_DISPLAY end_cmd  */
#line 381 "mon_parse.y"
              { mon_memory_display(e_text, BAD_ADDR, BAD_ADDR, DF_PETSCII); }
#line 3089 "mon_parse.c"
    break;

  case 95: /* memory_rules: CMD_SCREENCODE_DISPLAY address_opt_range end_cmd  */
#line 383 "mon_parse.y"
              { mon_memory_display(e_text, (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], DF_SCREEN_CODE); }
#line 3095 "mon_parse.c"
    break;

  case 96: /* memory_rules: CMD_SCREENCODE_DISPLAY end_cmd  */
#line 385 "mon_parse.y"
              { mon_memory_display(e_text, BAD_ADDR, BAD_ADDR, DF_SCREEN_CODE); }
#line 3101 "mon_parse.c"
    break;

  case 97: /* memory_rules: CMD_MEMMAPZAP end_cmd  */
#line 387 "mon_parse.y"
              { mon_memmap_zap(); }
#line 3107 "mon_parse.c"
    break;

  case 98: /* memory_rules: CMD_MEMMAPSHOW end_cmd  */
#line 389 "mon_parse.y"
              { mon_memmap_show(-1,BAD_ADDR,BAD_ADDR); }
#line 3113 "mon_parse.c"
    break;

  case 99: /* memory_rules: CMD_MEMMAPSHOW opt_sep expression end_cmd  */
#line 391 "mon_parse.y"
              { mon_memmap_show((yyvsp[-1].i),BAD_ADDR,BAD_ADDR); }
#line 3119 "mon_parse.c"
    break;

  case 100: /* memory_rules: CMD_MEMMAPSHOW opt_sep expression address_opt_range end_cmd  */
#line 393 "mon_parse.y"
              { mon_memmap_show((yyvsp[-2].i),(yyvsp[-1].range)[0],(yyvsp[-1].range)[1]); }
#line 3125 "mon_parse.c"
    break;

  case 101: /* memory_rules: CMD_MEMMAPSAVE filename opt_sep expression end_cmd  */
#line 395 "mon_parse.y"
              { mon_memmap_save((yyvsp[-3].str),(yyvsp[-1].i)); }
#line 3131 "mon_parse.c"
    break;

  case 102: /* checkpoint_rules: CMD_BREAK opt_mem_op address_opt_range opt_if_cond_expr end_cmd  */
#line 399 "mon_parse.y"
                  {
                      if ((yyvsp[-3].i)) {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], TRUE, (yyvsp[-3].i), FALSE, TRUE);
                      } else {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], TRUE, e_exec, FALSE, TRUE);
                      }
                      mon_breakpoint_set_checkpoint_condition(temp, (yyvsp[-1].cond_node));
                  }
#line 3144 "mon_parse.c"
    break;

  case 103: /* checkpoint_rules: CMD_BREAK end_cmd  */
#line 408 "mon_parse.y"
                  { mon_breakpoint_print_checkpoints(); }
#line 3150 "mon_parse.c"
    break;

  case 104: /* checkpoint_rules: CMD_UNTIL address_opt_range end_cmd  */
#line 411 "mon_parse.y"
                  {
                      mon_breakpoint_add_checkpoint((yyvsp[-1].range)[0], (yyvsp[-1].range)[1], TRUE, e_exec, TRUE, TRUE);
                  }
#line 3158 "mon_parse.c"
    break;

  case 105: /* checkpoint_rules: CMD_UNTIL end_cmd  */
#line 415 "mon_parse.y"
                  { mon_breakpoint_print_checkpoints(); }
#line 3164 "mon_parse.c"
    break;

  case 106: /* checkpoint_rules: CMD_WATCH opt_mem_op address_opt_range opt_if_cond_expr end_cmd  */
#line 418 "mon_parse.y"
                  {
                      if ((yyvsp[-3].i)) {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], TRUE, (yyvsp[-3].i), FALSE, TRUE);
                      } else {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], TRUE, e_load | e_store, FALSE, TRUE);
                      }
                      mon_breakpoint_set_checkpoint_condition(temp, (yyvsp[-1].cond_node));
                  }
#line 3177 "mon_parse.c"
    break;

  case 107: /* checkpoint_rules: CMD_WATCH end_cmd  */
#line 427 "mon_parse.y"
                  { mon_breakpoint_print_checkpoints(); }
#line 3183 "mon_parse.c"
    break;

  case 108: /* checkpoint_rules: CMD_TRACE opt_mem_op address_opt_range opt_if_cond_expr end_cmd  */
#line 430 "mon_parse.y"
                  {
                      if ((yyvsp[-3].i)) {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], FALSE, (yyvsp[-3].i), FALSE, TRUE);
                      } else {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], FALSE, e_exec | e_load | e_store, FALSE, TRUE);
                      }
                      mon_breakpoint_set_checkpoint_condition(temp, (yyvsp[-1].cond_node));
                  }
#line 3196 "mon_parse.c"
    break;

  case 109: /* checkpoint_rules: CMD_TRACE end_cmd  */
#line 439 "mon_parse.y"
                  { mon_breakpoint_print_checkpoints(); }
#line 3202 "mon_parse.c"
    break;

  case 110: /* checkpoint_control_rules: CMD_CHECKPT_ON checkpt_num end_cmd  */
#line 444 "mon_parse.y"
                          { mon_breakpoint_switch_checkpoint(e_ON, (yyvsp[-1].i)); }
#line 3208 "mon_parse.c"
    break;

  case 111: /* checkpoint_control_rules: CMD_CHECKPT_ON end_cmd  */
#line 446 "mon_parse.y"
                          { mon_breakpoint_switch_checkpoint(e_ON, -1); }
#line 3214 "mon_parse.c"
    break;

  case 112: /* checkpoint_control_rules: CMD_CHECKPT_OFF checkpt_num end_cmd  */
#line 448 "mon_parse.y"
                          { mon_breakpoint_switch_checkpoint(e_OFF, (yyvsp[-1].i)); }
#line 3220 "mon_parse.c"
    break;

  case 113: /* checkpoint_control_rules: CMD_CHECKPT_OFF end_cmd  */
#line 450 "mon_parse.y"
                          { mon_breakpoint_switch_checkpoint(e_OFF, -1); }
#line 3226 "mon_parse.c"
    break;

  case 114: /* checkpoint_control_rules: CMD_IGNORE checkpt_num end_cmd  */
#line 452 "mon_parse.y"
                          { mon_breakpoint_set_ignore_count((yyvsp[-1].i), -1); }
#line 3232 "mon_parse.c"
    break;

  case 115: /* checkpoint_control_rules: CMD_IGNORE checkpt_num opt_sep expression end_cmd  */
#line 454 "mon_parse.y"
                          { mon_breakpoint_set_ignore_count((yyvsp[-3].i), (yyvsp[-1].i)); }
#line 3238 "mon_parse.c"
    break;

  case 116: /* checkpoint_control_rules: CMD_DELETE checkpt_num end_cmd  */
#line 456 "mon_parse.y"
                          { mon_breakpoint_delete_checkpoint((yyvsp[-1].i)); }
#line 3244 "mon_parse.c"
    break;

  case 117: /* checkpoint_control_rules: CMD_DELETE end_cmd  */
#line 458 "mon_parse.y"
                          { mon_breakpoint_delete_checkpoint(-1); }
#line 3250 "mon_parse.c"
    break;

  case 118: /* checkpoint_control_rules: CMD_CONDITION checkpt_num IF cond_expr end_cmd  */
#line 460 "mon_parse.y"
                          { mon_breakpoint_set_checkpoint_condition((yyvsp[-3].i), (yyvsp[-1].cond_node)); }
#line 3256 "mon_parse.c"
    break;

  case 119: /* checkpoint_control_rules: CMD_COMMAND checkpt_num opt_sep STRING end_cmd  */
#line 462 "mon_parse.y"
                          { mon_breakpoint_set_checkpoint_command((yyvsp[-3].i), (yyvsp[-1].str)); }
#line 3262 "mon_parse.c"
    break;

  case 120: /* checkpoint_control_rules: CMD_COMMAND checkpt_num error end_cmd  */
#line 464 "mon_parse.y"
                          { return ERR_EXPECT_STRING; }
#line 3268 "mon_parse.c"
    break;

  case 121: /* monitor_state_rules: CMD_SIDEFX TOGGLE end_cmd  */
#line 468 "mon_parse.y"
                     { sidefx = (((yyvsp[-1].action) == e_TOGGLE) ? (sidefx ^ 1) : (yyvsp[-1].action)); }
#line 3274 "mon_parse.c"
    break;

  case 122: /* monitor_state_rules: CMD_SIDEFX end_cmd  */
#line 470 "mon_parse.y"
                     {
                         mon_out("I/O side effects are %s\n",
                                   sidefx ? "enabled" : "disabled");
                     }
#line 3283 "mon_parse.c"
    break;

  case 123: /* monitor_state_rules: CMD_DUMMY TOGGLE end_cmd  */
#line 475 "mon_parse.y"
                     { 
                         break_on_dummy_access = (((yyvsp[-1].action) == e_TOGGLE) ? (break_on_dummy_access ^ 1) : (yyvsp[-1].action)); 
                         /* FIXME: some day we might want to toggle the break-on-dummy-access 
                                   per MEMSPACE, for now its a global option */                         
                         mon_breakpoint_set_dummy_state(e_default_space, break_on_dummy_access);
                     }
#line 3294 "mon_parse.c"
    break;

  case 124: /* monitor_state_rules: CMD_DUMMY end_cmd  */
#line 482 "mon_parse.y"
                     {
                         mon_out("Checkpoints will %strigger on dummy accesses.\n",
                                   break_on_dummy_access ? "" : "not ");
                         /* FIXME: some day we might want to toggle the break-on-dummy-access 
                                   per MEMSPACE, for now its a global option */                         
                         mon_breakpoint_set_dummy_state(e_default_space, break_on_dummy_access);
                     }
#line 3306 "mon_parse.c"
    break;

  case 125: /* monitor_state_rules: CMD_LOG TOGGLE end_cmd  */
#line 490 "mon_parse.y"
                     { 
                        int logenabled;
                        resources_get_int("MonitorLogEnabled", &logenabled);
                        logenabled = (((yyvsp[-1].action) == e_TOGGLE) ? (logenabled ^ 1) : (yyvsp[-1].action));
                        resources_set_int("MonitorLogEnabled", logenabled);
                     }
#line 3317 "mon_parse.c"
    break;

  case 126: /* monitor_state_rules: CMD_LOG end_cmd  */
#line 497 "mon_parse.y"
                     {
                         int logenabled;
                         const char *logfilename;
                         resources_get_int("MonitorLogEnabled", &logenabled);
                         resources_get_string("MonitorLogFileName", &logfilename);
                         if (logenabled) {
                            mon_out("Logging to '%s' is enabled.\n", logfilename);
                         } else {
                            mon_out("Logging is disabled.\n");
                         }
                     }
#line 3333 "mon_parse.c"
    break;

  case 127: /* monitor_state_rules: CMD_LOGNAME filename end_cmd  */
#line 509 "mon_parse.y"
                     { 
                        resources_set_string("MonitorLogFileName", (yyvsp[-1].str));
                     }
#line 3341 "mon_parse.c"
    break;

  case 128: /* monitor_state_rules: CMD_RADIX RADIX_TYPE end_cmd  */
#line 513 "mon_parse.y"
                     { default_radix = (yyvsp[-1].rt); }
#line 3347 "mon_parse.c"
    break;

  case 129: /* monitor_state_rules: CMD_RADIX end_cmd  */
#line 515 "mon_parse.y"
                     {
                         const char *p;

                         if (default_radix == e_hexadecimal)
                             p = "Hexadecimal";
                         else if (default_radix == e_decimal)
                             p = "Decimal";
                         else if (default_radix == e_octal)
                             p = "Octal";
                         else if (default_radix == e_binary)
                             p = "Binary";
                         else
                             p = "Unknown";

                         mon_out("Default radix is %s\n", p);
                     }
#line 3368 "mon_parse.c"
    break;

  case 130: /* monitor_state_rules: CMD_DEVICE end_cmd  */
#line 533 "mon_parse.y"
                     { monitor_change_device(e_default_space); }
#line 3374 "mon_parse.c"
    break;

  case 131: /* monitor_state_rules: CMD_DEVICE memspace end_cmd  */
#line 535 "mon_parse.y"
                     { monitor_change_device((yyvsp[-1].i)); }
#line 3380 "mon_parse.c"
    break;

  case 132: /* monitor_state_rules: CMD_EXPORT end_cmd  */
#line 537 "mon_parse.y"
                     { mon_export(); }
#line 3386 "mon_parse.c"
    break;

  case 133: /* monitor_state_rules: CMD_QUIT end_cmd  */
#line 539 "mon_parse.y"
                     { mon_quit(); YYACCEPT; }
#line 3392 "mon_parse.c"
    break;

  case 134: /* monitor_state_rules: CMD_EXIT end_cmd  */
#line 541 "mon_parse.y"
                     { mon_exit(); YYACCEPT; }
#line 3398 "mon_parse.c"
    break;

  case 135: /* monitor_state_rules: CMD_MAINCPU_TRACE end_cmd  */
#line 543 "mon_parse.y"
                     { mon_maincpu_trace(); }
#line 3404 "mon_parse.c"
    break;

  case 136: /* monitor_state_rules: CMD_MAINCPU_TRACE TOGGLE end_cmd  */
#line 545 "mon_parse.y"
                     { mon_maincpu_toggle_trace((yyvsp[-1].action)); }
#line 3410 "mon_parse.c"
    break;

  case 137: /* monitor_misc_rules: CMD_DISK rest_of_line end_cmd  */
#line 549 "mon_parse.y"
                    { mon_drive_execute_disk_cmd((yyvsp[-1].str)); }
#line 3416 "mon_parse.c"
    break;

  case 138: /* monitor_misc_rules: CMD_PRINT expression end_cmd  */
#line 551 "mon_parse.y"
                    { mon_out("\t%d\n",(yyvsp[-1].i)); }
#line 3422 "mon_parse.c"
    break;

  case 139: /* monitor_misc_rules: CMD_HELP end_cmd  */
#line 553 "mon_parse.y"
                    { mon_command_print_help(NULL); }
#line 3428 "mon_parse.c"
    break;

  case 140: /* monitor_misc_rules: CMD_HELP rest_of_line end_cmd  */
#line 555 "mon_parse.y"
                    { mon_command_print_help((yyvsp[-1].str)); }
#line 3434 "mon_parse.c"
    break;

  case 141: /* monitor_misc_rules: CONVERT_OP expression end_cmd  */
#line 557 "mon_parse.y"
                    { mon_print_convert((yyvsp[-1].i)); }
#line 3440 "mon_parse.c"
    break;

  case 142: /* monitor_misc_rules: CMD_CHDIR rest_of_line_or_quoted end_cmd  */
#line 559 "mon_parse.y"
                    { mon_change_dir((yyvsp[-1].str)); }
#line 3446 "mon_parse.c"
    break;

  case 143: /* monitor_misc_rules: CMD_KEYBUF rest_of_line end_cmd  */
#line 561 "mon_parse.y"
                    { mon_keyboard_feed((yyvsp[-1].str)); }
#line 3452 "mon_parse.c"
    break;

  case 144: /* monitor_misc_rules: CMD_BACKTRACE end_cmd  */
#line 563 "mon_parse.y"
                    { mon_backtrace(); }
#line 3458 "mon_parse.c"
    break;

  case 145: /* monitor_misc_rules: CMD_DIR opt_rest_of_line end_cmd  */
#line 565 "mon_parse.y"
                     { mon_show_dir((yyvsp[-1].str)); }
#line 3464 "mon_parse.c"
    break;

  case 146: /* monitor_misc_rules: CMD_PWD end_cmd  */
#line 567 "mon_parse.y"
                     { mon_show_pwd(); }
#line 3470 "mon_parse.c"
    break;

  case 147: /* monitor_misc_rules: CMD_MKDIR rest_of_line_or_quoted end_cmd  */
#line 569 "mon_parse.y"
                    { mon_make_dir((yyvsp[-1].str)); }
#line 3476 "mon_parse.c"
    break;

  case 148: /* monitor_misc_rules: CMD_RMDIR rest_of_line_or_quoted end_cmd  */
#line 571 "mon_parse.y"
                    { mon_remove_dir((yyvsp[-1].str)); }
#line 3482 "mon_parse.c"
    break;

  case 149: /* monitor_misc_rules: CMD_SCREENSHOT filename end_cmd  */
#line 573 "mon_parse.y"
                    { mon_screenshot_save((yyvsp[-1].str),-1); }
#line 3488 "mon_parse.c"
    break;

  case 150: /* monitor_misc_rules: CMD_SCREENSHOT filename opt_sep expression end_cmd  */
#line 575 "mon_parse.y"
                    { mon_screenshot_save((yyvsp[-3].str),(yyvsp[-1].i)); }
#line 3494 "mon_parse.c"
    break;

  case 151: /* monitor_misc_rules: CMD_RESOURCE_GET STRING end_cmd  */
#line 577 "mon_parse.y"
                    { mon_resource_get((yyvsp[-1].str)); }
#line 3500 "mon_parse.c"
    break;

  case 152: /* monitor_misc_rules: CMD_RESOURCE_SET STRING STRING end_cmd  */
#line 579 "mon_parse.y"
                    { mon_resource_set((yyvsp[-2].str),(yyvsp[-1].str)); }
#line 3506 "mon_parse.c"
    break;

  case 153: /* monitor_misc_rules: CMD_LOAD_RESOURCES filename end_cmd  */
#line 581 "mon_parse.y"
                    { resources_load((yyvsp[-1].str)); }
#line 3512 "mon_parse.c"
    break;

  case 154: /* monitor_misc_rules: CMD_SAVE_RESOURCES filename end_cmd  */
#line 583 "mon_parse.y"
                    { resources_save((yyvsp[-1].str)); }
#line 3518 "mon_parse.c"
    break;

  case 155: /* monitor_misc_rules: CMD_MON_RESET end_cmd  */
#line 585 "mon_parse.y"
                    { mon_reset_machine(-1); }
#line 3524 "mon_parse.c"
    break;

  case 156: /* monitor_misc_rules: CMD_MON_RESET opt_sep expression end_cmd  */
#line 587 "mon_parse.y"
                    { mon_reset_machine((yyvsp[-1].i)); }
#line 3530 "mon_parse.c"
    break;

  case 157: /* monitor_misc_rules: CMD_TAPECTRL opt_sep expression end_cmd  */
#line 589 "mon_parse.y"
                    { mon_tape_ctrl(TAPEPORT_PORT_1, (yyvsp[-1].i)); }
#line 3536 "mon_parse.c"
    break;

  case 158: /* monitor_misc_rules: CMD_TAPEOFFS end_cmd  */
#line 591 "mon_parse.y"
                    { mon_tape_offs(TAPEPORT_PORT_1, -1); }
#line 3542 "mon_parse.c"
    break;

  case 159: /* monitor_misc_rules: CMD_TAPEOFFS opt_sep expression end_cmd  */
#line 593 "mon_parse.y"
                    { mon_tape_offs(TAPEPORT_PORT_1, (yyvsp[-1].i)); }
#line 3548 "mon_parse.c"
    break;

  case 160: /* monitor_misc_rules: CMD_CARTFREEZE end_cmd  */
#line 595 "mon_parse.y"
                    { mon_cart_freeze(); }
#line 3554 "mon_parse.c"
    break;

  case 161: /* monitor_misc_rules: CMD_UPDB number end_cmd  */
#line 597 "mon_parse.y"
                    { mon_userport_set_output((yyvsp[-1].i)); }
#line 3560 "mon_parse.c"
    break;

  case 162: /* monitor_misc_rules: CMD_JPDB number number end_cmd  */
#line 599 "mon_parse.y"
                    { mon_joyport_set_output((yyvsp[-2].i), (yyvsp[-1].i)); }
#line 3566 "mon_parse.c"
    break;

  case 163: /* monitor_misc_rules: CMD_COMMENT opt_rest_of_line end_cmd  */
#line 601 "mon_parse.y"
                     { }
#line 3572 "mon_parse.c"
    break;

  case 164: /* monitor_misc_rules: CMD_STOPWATCH RESET end_cmd  */
#line 603 "mon_parse.y"
                     { mon_stopwatch_reset(); }
#line 3578 "mon_parse.c"
    break;

  case 165: /* monitor_misc_rules: CMD_STOPWATCH end_cmd  */
#line 605 "mon_parse.y"
                     { mon_stopwatch_show("Stopwatch: ", "\n"); }
#line 3584 "mon_parse.c"
    break;

  case 166: /* monitor_misc_rules: CMD_PROFILE TOGGLE end_cmd  */
#line 607 "mon_parse.y"
                     { mon_profile_action((yyvsp[-1].action)); }
#line 3590 "mon_parse.c"
    break;

  case 167: /* monitor_misc_rules: CMD_PROFILE end_cmd  */
#line 609 "mon_parse.y"
                     { mon_profile(); }
#line 3596 "mon_parse.c"
    break;

  case 168: /* monitor_misc_rules: CMD_PROFILE FLAT opt_d_number end_cmd  */
#line 611 "mon_parse.y"
                     { mon_profile_flat((yyvsp[-1].i)); }
#line 3602 "mon_parse.c"
    break;

  case 169: /* monitor_misc_rules: CMD_PROFILE GRAPH opt_context_num end_cmd  */
#line 613 "mon_parse.y"
                     { mon_profile_graph((yyvsp[-1].i), -1); }
#line 3608 "mon_parse.c"
    break;

  case 170: /* monitor_misc_rules: CMD_PROFILE GRAPH opt_context_num DEPTH d_number end_cmd  */
#line 615 "mon_parse.y"
                     { mon_profile_graph((yyvsp[-3].i), (yyvsp[-1].i)); }
#line 3614 "mon_parse.c"
    break;

  case 171: /* monitor_misc_rules: CMD_PROFILE FUNC address end_cmd  */
#line 617 "mon_parse.y"
                     { mon_profile_func((yyvsp[-1].a)); }
#line 3620 "mon_parse.c"
    break;

  case 172: /* monitor_misc_rules: CMD_PROFILE DISASS address end_cmd  */
#line 619 "mon_parse.y"
                     { mon_profile_disass((yyvsp[-1].a)); }
#line 3626 "mon_parse.c"
    break;

  case 173: /* monitor_misc_rules: CMD_PROFILE CLEAR address end_cmd  */
#line 621 "mon_parse.y"
                     { mon_profile_clear((yyvsp[-1].a)); }
#line 3632 "mon_parse.c"
    break;

  case 174: /* monitor_misc_rules: CMD_PROFILE PROFILE_CONTEXT d_number end_cmd  */
#line 623 "mon_parse.y"
                     { mon_profile_disass_context((yyvsp[-1].i)); }
#line 3638 "mon_parse.c"
    break;

  case 175: /* disk_rules: CMD_LOAD filename device_num opt_address end_cmd  */
#line 627 "mon_parse.y"
            { mon_file_load((yyvsp[-3].str), (yyvsp[-2].i), (yyvsp[-1].a), FALSE, FALSE); }
#line 3644 "mon_parse.c"
    break;

  case 176: /* disk_rules: CMD_BASICLOAD filename device_num opt_address end_cmd  */
#line 629 "mon_parse.y"
            { mon_file_load((yyvsp[-3].str), (yyvsp[-2].i), (yyvsp[-1].a), FALSE, TRUE); }
#line 3650 "mon_parse.c"
    break;

  case 177: /* disk_rules: CMD_BLOAD filename device_num address end_cmd  */
#line 631 "mon_parse.y"
            { mon_file_load((yyvsp[-3].str), (yyvsp[-2].i), (yyvsp[-1].a), TRUE, FALSE); }
#line 3656 "mon_parse.c"
    break;

  case 178: /* disk_rules: CMD_BLOAD filename device_num error  */
#line 633 "mon_parse.y"
            { return ERR_EXPECT_ADDRESS; }
#line 3662 "mon_parse.c"
    break;

  case 179: /* disk_rules: CMD_SAVE filename device_num address_range end_cmd  */
#line 635 "mon_parse.y"
            { mon_file_save((yyvsp[-3].str), (yyvsp[-2].i), (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], FALSE); }
#line 3668 "mon_parse.c"
    break;

  case 180: /* disk_rules: CMD_SAVE filename error  */
#line 637 "mon_parse.y"
            { return ERR_EXPECT_DEVICE_NUM; }
#line 3674 "mon_parse.c"
    break;

  case 181: /* disk_rules: CMD_SAVE filename device_num error  */
#line 639 "mon_parse.y"
            { return ERR_EXPECT_ADDRESS; }
#line 3680 "mon_parse.c"
    break;

  case 182: /* disk_rules: CMD_BSAVE filename device_num address_range end_cmd  */
#line 641 "mon_parse.y"
            { mon_file_save((yyvsp[-3].str), (yyvsp[-2].i), (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], TRUE); }
#line 3686 "mon_parse.c"
    break;

  case 183: /* disk_rules: CMD_BSAVE filename device_num error  */
#line 643 "mon_parse.y"
            { return ERR_EXPECT_ADDRESS; }
#line 3692 "mon_parse.c"
    break;

  case 184: /* disk_rules: CMD_VERIFY filename device_num opt_address end_cmd  */
#line 645 "mon_parse.y"
            { mon_file_verify((yyvsp[-3].str),(yyvsp[-2].i),(yyvsp[-1].a),FALSE); }
#line 3698 "mon_parse.c"
    break;

  case 185: /* disk_rules: CMD_BVERIFY filename device_num address end_cmd  */
#line 647 "mon_parse.y"
            { mon_file_verify((yyvsp[-3].str),(yyvsp[-2].i),(yyvsp[-1].a),TRUE); }
#line 3704 "mon_parse.c"
    break;

  case 186: /* disk_rules: CMD_BVERIFY filename device_num error  */
#line 649 "mon_parse.y"
            { return ERR_EXPECT_ADDRESS; }
#line 3710 "mon_parse.c"
    break;

  case 187: /* disk_rules: CMD_BLOCK_READ expression expression opt_address end_cmd  */
#line 651 "mon_parse.y"
            { mon_drive_block_cmd(0,(yyvsp[-3].i),(yyvsp[-2].i),(yyvsp[-1].a)); }
#line 3716 "mon_parse.c"
    break;

  case 188: /* disk_rules: CMD_BLOCK_WRITE expression expression address end_cmd  */
#line 653 "mon_parse.y"
            { mon_drive_block_cmd(1,(yyvsp[-3].i),(yyvsp[-2].i),(yyvsp[-1].a)); }
#line 3722 "mon_parse.c"
    break;

  case 189: /* disk_rules: CMD_LIST end_cmd  */
#line 655 "mon_parse.y"
            { mon_drive_list(-1); }
#line 3728 "mon_parse.c"
    break;

  case 190: /* disk_rules: CMD_LIST device_num end_cmd  */
#line 657 "mon_parse.y"
            { mon_drive_list((yyvsp[-1].i)); }
#line 3734 "mon_parse.c"
    break;

  case 191: /* disk_rules: CMD_ATTACH filename expression end_cmd  */
#line 659 "mon_parse.y"
            { mon_attach((yyvsp[-2].str),(yyvsp[-1].i)); }
#line 3740 "mon_parse.c"
    break;

  case 192: /* disk_rules: CMD_DETACH expression end_cmd  */
#line 661 "mon_parse.y"
            { mon_detach((yyvsp[-1].i)); }
#line 3746 "mon_parse.c"
    break;

  case 193: /* disk_rules: CMD_AUTOSTART filename end_cmd  */
#line 663 "mon_parse.y"
            { mon_autostart((yyvsp[-1].str),0,1); }
#line 3752 "mon_parse.c"
    break;

  case 194: /* disk_rules: CMD_AUTOSTART filename opt_sep number end_cmd  */
#line 665 "mon_parse.y"
            { mon_autostart((yyvsp[-3].str),(yyvsp[-1].i),1); }
#line 3758 "mon_parse.c"
    break;

  case 195: /* disk_rules: CMD_AUTOLOAD filename end_cmd  */
#line 667 "mon_parse.y"
            { mon_autostart((yyvsp[-1].str),0,0); }
#line 3764 "mon_parse.c"
    break;

  case 196: /* disk_rules: CMD_AUTOLOAD filename opt_sep number end_cmd  */
#line 669 "mon_parse.y"
            { mon_autostart((yyvsp[-3].str),(yyvsp[-1].i),0); }
#line 3770 "mon_parse.c"
    break;

  case 197: /* cmd_file_rules: CMD_RECORD filename end_cmd  */
#line 673 "mon_parse.y"
                { mon_record_commands((yyvsp[-1].str)); }
#line 3776 "mon_parse.c"
    break;

  case 198: /* cmd_file_rules: CMD_MON_STOP end_cmd  */
#line 675 "mon_parse.y"
                { mon_end_recording(); }
#line 3782 "mon_parse.c"
    break;

  case 199: /* cmd_file_rules: CMD_PLAYBACK filename end_cmd  */
#line 677 "mon_parse.y"
                { mon_playback_commands((yyvsp[-1].str),true); }
#line 3788 "mon_parse.c"
    break;

  case 200: /* data_entry_rules: CMD_ENTER_DATA address data_list end_cmd  */
#line 681 "mon_parse.y"
                  { mon_memory_fill((yyvsp[-2].a), BAD_ADDR, (unsigned char *)(yyvsp[-1].str)); }
#line 3794 "mon_parse.c"
    break;

  case 201: /* data_entry_rules: CMD_ENTER_BIN_DATA end_cmd  */
#line 683 "mon_parse.y"
                  { printf("Not yet.\n"); }
#line 3800 "mon_parse.c"
    break;

  case 202: /* monitor_debug_rules: CMD_YYDEBUG end_cmd  */
#line 687 "mon_parse.y"
                     {
#if YYDEBUG
                     yydebug = 1;
#endif
                     }
#line 3810 "mon_parse.c"
    break;

  case 203: /* rest_of_line: R_O_L  */
#line 694 "mon_parse.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 3816 "mon_parse.c"
    break;

  case 204: /* opt_rest_of_line: R_O_L  */
#line 697 "mon_parse.y"
                        { (yyval.str) = (yyvsp[0].str); }
#line 3822 "mon_parse.c"
    break;

  case 205: /* opt_rest_of_line: %empty  */
#line 698 "mon_parse.y"
                    { (yyval.str) = NULL; }
#line 3828 "mon_parse.c"
    break;

  case 206: /* rest_of_line_or_quoted: R_O_L_Q  */
#line 701 "mon_parse.y"
                                { (yyval.str) = (yyvsp[0].str); }
#line 3834 "mon_parse.c"
    break;

  case 208: /* filename: error  */
#line 705 "mon_parse.y"
                { return ERR_EXPECT_FILENAME; }
#line 3840 "mon_parse.c"
    break;

  case 210: /* device_num: error  */
#line 709 "mon_parse.y"
              { return ERR_EXPECT_DEVICE_NUM; }
#line 3846 "mon_parse.c"
    break;

  case 211: /* mem_op: mem_op MEM_OP  */
#line 712 "mon_parse.y"
                      { (yyval.i) = (yyvsp[-1].i) | (yyvsp[0].i); }
#line 3852 "mon_parse.c"
    break;

  case 212: /* mem_op: MEM_OP  */
#line 713 "mon_parse.y"
               { (yyval.i) = (yyvsp[0].i); }
#line 3858 "mon_parse.c"
    break;

  case 213: /* opt_mem_op: mem_op  */
#line 716 "mon_parse.y"
                   { (yyval.i) = (yyvsp[0].i); }
#line 3864 "mon_parse.c"
    break;

  case 214: /* opt_mem_op: %empty  */
#line 717 "mon_parse.y"
            { (yyval.i) = 0; }
#line 3870 "mon_parse.c"
    break;

  case 215: /* register: MON_REGISTER  */
#line 720 "mon_parse.y"
                                {
                                    if (!mon_register_valid(default_memspace, (yyvsp[0].reg))) {
                                        return ERR_INVALID_REGISTER;
                                    }
                                    (yyval.i) = new_reg(default_memspace, (yyvsp[0].reg));
                                }
#line 3881 "mon_parse.c"
    break;

  case 216: /* register: memspace MON_REGISTER  */
#line 726 "mon_parse.y"
                                {
                                    if (!mon_register_valid((yyvsp[-1].i), (yyvsp[0].reg))) {
                                        return ERR_INVALID_REGISTER;
                                    }
                                    (yyval.i) = new_reg((yyvsp[-1].i), (yyvsp[0].reg));
                                }
#line 3892 "mon_parse.c"
    break;

  case 219: /* reg_asgn: register EQUALS number  */
#line 739 "mon_parse.y"
          { (monitor_cpu_for_memspace[reg_memspace((yyvsp[-2].i))]->mon_register_set_val)(reg_memspace((yyvsp[-2].i)), reg_regid((yyvsp[-2].i)), (uint16_t) (yyvsp[0].i)); }
#line 3898 "mon_parse.c"
    break;

  case 220: /* checkpt_num: d_number  */
#line 742 "mon_parse.y"
                      { (yyval.i) = (yyvsp[0].i); }
#line 3904 "mon_parse.c"
    break;

  case 221: /* checkpt_num: error  */
#line 743 "mon_parse.y"
                   { return ERR_EXPECT_CHECKNUM; }
#line 3910 "mon_parse.c"
    break;

  case 222: /* opt_context_num: d_number  */
#line 746 "mon_parse.y"
                          { (yyval.i) = (yyvsp[0].i); }
#line 3916 "mon_parse.c"
    break;

  case 223: /* opt_context_num: %empty  */
#line 747 "mon_parse.y"
                 { (yyval.i) = -1; }
#line 3922 "mon_parse.c"
    break;

  case 225: /* address_opt_range: address  */
#line 751 "mon_parse.y"
                           { (yyval.range)[0] = (yyvsp[0].a); (yyval.range)[1] = BAD_ADDR; }
#line 3928 "mon_parse.c"
    break;

  case 226: /* address_range: address opt_sep address  */
#line 754 "mon_parse.y"
                                       { (yyval.range)[0] = (yyvsp[-2].a); (yyval.range)[1] = (yyvsp[0].a); }
#line 3934 "mon_parse.c"
    break;

  case 227: /* address_range: H_RANGE_GUESS  */
#line 756 "mon_parse.y"
               { if (resolve_range(e_default_space, (yyval.range), (yyvsp[0].str))) return ERR_ADDR_TOO_BIG; }
#line 3940 "mon_parse.c"
    break;

  case 228: /* address_range: memspace opt_sep H_RANGE_GUESS  */
#line 758 "mon_parse.y"
               { if (resolve_range((yyvsp[-2].i), (yyval.range), (yyvsp[0].str))) return ERR_ADDR_TOO_BIG; }
#line 3946 "mon_parse.c"
    break;

  case 229: /* opt_address: opt_sep address  */
#line 761 "mon_parse.y"
                             { (yyval.a) = (yyvsp[0].a); }
#line 3952 "mon_parse.c"
    break;

  case 230: /* opt_address: %empty  */
#line 762 "mon_parse.y"
             { (yyval.a) = BAD_ADDR; }
#line 3958 "mon_parse.c"
    break;

  case 231: /* address: memloc  */
#line 766 "mon_parse.y"
         {
             (yyval.a) = new_addr(e_default_space,(yyvsp[0].i));
             if (opt_asm) new_cmd = asm_mode = 1;
         }
#line 3967 "mon_parse.c"
    break;

  case 232: /* address: memspace opt_sep memloc  */
#line 771 "mon_parse.y"
         {
             (yyval.a) = new_addr((yyvsp[-2].i), (yyvsp[0].i));
             if (opt_asm) new_cmd = asm_mode = 1;
         }
#line 3976 "mon_parse.c"
    break;

  case 233: /* address: LABEL  */
#line 776 "mon_parse.y"
         {
             temp = mon_symbol_table_lookup_addr(e_default_space, (yyvsp[0].str));
             if (temp >= 0)
                 (yyval.a) = new_addr(e_default_space, temp);
             else
                 return ERR_UNDEFINED_LABEL;
         }
#line 3988 "mon_parse.c"
    break;

  case 236: /* memspace: MEM_COMP  */
#line 789 "mon_parse.y"
                   { (yyval.i) = e_comp_space; }
#line 3994 "mon_parse.c"
    break;

  case 237: /* memspace: MEM_DISK8  */
#line 790 "mon_parse.y"
                    { (yyval.i) = e_disk8_space; }
#line 4000 "mon_parse.c"
    break;

  case 238: /* memspace: MEM_DISK9  */
#line 791 "mon_parse.y"
                    { (yyval.i) = e_disk9_space; }
#line 4006 "mon_parse.c"
    break;

  case 239: /* memspace: MEM_DISK10  */
#line 792 "mon_parse.y"
                     { (yyval.i) = e_disk10_space; }
#line 4012 "mon_parse.c"
    break;

  case 240: /* memspace: MEM_DISK11  */
#line 793 "mon_parse.y"
                     { (yyval.i) = e_disk11_space; }
#line 4018 "mon_parse.c"
    break;

  case 241: /* memloc: memaddr  */
#line 796 "mon_parse.y"
                { (yyval.i) = (yyvsp[0].i); if (!CHECK_ADDR((yyvsp[0].i))) return ERR_ADDR_TOO_BIG; }
#line 4024 "mon_parse.c"
    break;

  case 242: /* memaddr: number  */
#line 798 "mon_parse.y"
                { (yyval.i) = (yyvsp[0].i); }
#line 4030 "mon_parse.c"
    break;

  case 243: /* expression: expression '+' expression  */
#line 800 "mon_parse.y"
                                      { (yyval.i) = (yyvsp[-2].i) + (yyvsp[0].i); }
#line 4036 "mon_parse.c"
    break;

  case 244: /* expression: expression '-' expression  */
#line 801 "mon_parse.y"
                                      { (yyval.i) = (yyvsp[-2].i) - (yyvsp[0].i); }
#line 4042 "mon_parse.c"
    break;

  case 245: /* expression: expression '*' expression  */
#line 802 "mon_parse.y"
                                      { (yyval.i) = (yyvsp[-2].i) * (yyvsp[0].i); }
#line 4048 "mon_parse.c"
    break;

  case 246: /* expression: expression '/' expression  */
#line 803 "mon_parse.y"
                                      { (yyval.i) = ((yyvsp[0].i)) ? ((yyvsp[-2].i) / (yyvsp[0].i)) : 1; }
#line 4054 "mon_parse.c"
    break;

  case 247: /* expression: '(' expression ')'  */
#line 804 "mon_parse.y"
                               { (yyval.i) = (yyvsp[-1].i); }
#line 4060 "mon_parse.c"
    break;

  case 248: /* expression: '(' expression error  */
#line 805 "mon_parse.y"
                                 { return ERR_MISSING_CLOSE_PAREN; }
#line 4066 "mon_parse.c"
    break;

  case 249: /* expression: value  */
#line 806 "mon_parse.y"
                  { (yyval.i) = (yyvsp[0].i); }
#line 4072 "mon_parse.c"
    break;

  case 250: /* opt_if_cond_expr: IF cond_expr  */
#line 809 "mon_parse.y"
                               { (yyval.cond_node) = (yyvsp[0].cond_node); }
#line 4078 "mon_parse.c"
    break;

  case 251: /* opt_if_cond_expr: %empty  */
#line 810 "mon_parse.y"
                  { (yyval.cond_node) = 0; }
#line 4084 "mon_parse.c"
    break;

  case 252: /* cond_expr: cond_expr COND_OP cond_expr  */
#line 813 "mon_parse.y"
           {
               (yyval.cond_node) = new_cond; (yyval.cond_node)->is_parenthized = FALSE;
               (yyval.cond_node)->child1 = (yyvsp[-2].cond_node); (yyval.cond_node)->child2 = (yyvsp[0].cond_node); (yyval.cond_node)->operation = (yyvsp[-1].cond_op);
           }
#line 4093 "mon_parse.c"
    break;

  case 253: /* cond_expr: cond_expr COND_OP error  */
#line 818 "mon_parse.y"
           { return ERR_INCOMPLETE_COND_OP; }
#line 4099 "mon_parse.c"
    break;

  case 254: /* cond_expr: L_PAREN cond_expr R_PAREN  */
#line 820 "mon_parse.y"
           { (yyval.cond_node) = (yyvsp[-1].cond_node); (yyval.cond_node)->is_parenthized = TRUE; }
#line 4105 "mon_parse.c"
    break;

  case 255: /* cond_expr: L_PAREN cond_expr error  */
#line 822 "mon_parse.y"
           { return ERR_MISSING_CLOSE_PAREN; }
#line 4111 "mon_parse.c"
    break;

  case 256: /* cond_expr: cond_operand  */
#line 824 "mon_parse.y"
           { (yyval.cond_node) = (yyvsp[0].cond_node); }
#line 4117 "mon_parse.c"
    break;

  case 257: /* cond_operand: register  */
#line 827 "mon_parse.y"
                          { (yyval.cond_node) = new_cond;
                            (yyval.cond_node)->operation = e_INV;
                            (yyval.cond_node)->is_parenthized = FALSE;
                            (yyval.cond_node)->reg_num = (yyvsp[0].i); (yyval.cond_node)->is_reg = TRUE; (yyval.cond_node)->banknum=-1;
                            (yyval.cond_node)->child1 = NULL; (yyval.cond_node)->child2 = NULL;
                          }
#line 4128 "mon_parse.c"
    break;

  case 258: /* cond_operand: number  */
#line 833 "mon_parse.y"
                          { (yyval.cond_node) = new_cond;
                            (yyval.cond_node)->operation = e_INV;
                            (yyval.cond_node)->is_parenthized = FALSE;
                            (yyval.cond_node)->value = (yyvsp[0].i); (yyval.cond_node)->is_reg = FALSE; (yyval.cond_node)->banknum=-1;
                            (yyval.cond_node)->child1 = NULL; (yyval.cond_node)->child2 = NULL;
                          }
#line 4139 "mon_parse.c"
    break;

  case 259: /* cond_operand: '@' BANKNAME ':' L_PAREN cond_expr R_PAREN  */
#line 840 "mon_parse.y"
                                                             {
                            (yyval.cond_node) = new_cond;
                            (yyval.cond_node)->operation = e_INV;
                            (yyval.cond_node)->is_parenthized = FALSE;
                            (yyval.cond_node)->banknum = mon_banknum_from_bank(e_default_space, (yyvsp[-4].str));
                            if ((yyval.cond_node)->banknum < 0) {
                                return ERR_ILLEGAL_INPUT;
                            }
                            (yyval.cond_node)->value = 0;
                            (yyval.cond_node)->is_reg = FALSE;
                            (yyval.cond_node)->child1 = (yyvsp[-1].cond_node);
                            (yyval.cond_node)->child2 = NULL;
                        }
#line 4157 "mon_parse.c"
    break;

  case 260: /* cond_operand: '@' BANKNAME ':' address  */
#line 853 "mon_parse.y"
                                           {
                            (yyval.cond_node) = new_cond;
                            (yyval.cond_node)->operation = e_INV;
                            (yyval.cond_node)->is_parenthized = FALSE;
                            (yyval.cond_node)->banknum = mon_banknum_from_bank(e_default_space, (yyvsp[-2].str));
                            if ((yyval.cond_node)->banknum < 0) {
                                return ERR_ILLEGAL_INPUT;
                            }
                            (yyval.cond_node)->value = (yyvsp[0].a);
                            (yyval.cond_node)->is_reg = FALSE;
                            (yyval.cond_node)->child1 = NULL; (yyval.cond_node)->child2 = NULL;  
                        }
#line 4174 "mon_parse.c"
    break;

  case 263: /* data_element: number  */
#line 871 "mon_parse.y"
                     { mon_add_number_to_buffer((yyvsp[0].i)); }
#line 4180 "mon_parse.c"
    break;

  case 264: /* data_element: STRING  */
#line 872 "mon_parse.y"
                     { mon_add_string_to_buffer((yyvsp[0].str)); }
#line 4186 "mon_parse.c"
    break;

  case 267: /* hunt_element: number  */
#line 879 "mon_parse.y"
                     { mon_add_number_to_buffer((yyvsp[0].i)); }
#line 4192 "mon_parse.c"
    break;

  case 268: /* hunt_element: MASK  */
#line 880 "mon_parse.y"
                     { mon_add_number_masked_to_buffer((yyvsp[0].i), 0x00); }
#line 4198 "mon_parse.c"
    break;

  case 269: /* hunt_element: STRING  */
#line 881 "mon_parse.y"
                     { mon_add_string_to_buffer((yyvsp[0].str)); }
#line 4204 "mon_parse.c"
    break;

  case 270: /* value: number  */
#line 884 "mon_parse.y"
              { (yyval.i) = (yyvsp[0].i); }
#line 4210 "mon_parse.c"
    break;

  case 271: /* value: register  */
#line 885 "mon_parse.y"
                { (yyval.i) = (monitor_cpu_for_memspace[reg_memspace((yyvsp[0].i))]->mon_register_get_val)(reg_memspace((yyvsp[0].i)), reg_regid((yyvsp[0].i))); }
#line 4216 "mon_parse.c"
    break;

  case 272: /* d_number: D_NUMBER  */
#line 888 "mon_parse.y"
                   { (yyval.i) = (yyvsp[0].i); }
#line 4222 "mon_parse.c"
    break;

  case 273: /* d_number: B_NUMBER_GUESS  */
#line 889 "mon_parse.y"
                         { (yyval.i) = (int)strtol((yyvsp[0].str), NULL, 10); }
#line 4228 "mon_parse.c"
    break;

  case 274: /* d_number: D_NUMBER_GUESS  */
#line 890 "mon_parse.y"
                         { (yyval.i) = (int)strtol((yyvsp[0].str), NULL, 10); }
#line 4234 "mon_parse.c"
    break;

  case 275: /* d_number: O_NUMBER_GUESS  */
#line 891 "mon_parse.y"
                         { (yyval.i) = (int)strtol((yyvsp[0].str), NULL, 10); }
#line 4240 "mon_parse.c"
    break;

  case 276: /* opt_d_number: d_number  */
#line 894 "mon_parse.y"
                       { (yyval.i) = (yyvsp[0].i); }
#line 4246 "mon_parse.c"
    break;

  case 277: /* opt_d_number: %empty  */
#line 895 "mon_parse.y"
              { (yyval.i) = -1; }
#line 4252 "mon_parse.c"
    break;

  case 278: /* guess_default: B_NUMBER_GUESS  */
#line 898 "mon_parse.y"
                              { (yyval.i) = resolve_datatype(B_NUMBER,(yyvsp[0].str)); }
#line 4258 "mon_parse.c"
    break;

  case 279: /* guess_default: D_NUMBER_GUESS  */
#line 899 "mon_parse.y"
                              { (yyval.i) = resolve_datatype(D_NUMBER,(yyvsp[0].str)); }
#line 4264 "mon_parse.c"
    break;

  case 280: /* guess_default: O_NUMBER_GUESS  */
#line 900 "mon_parse.y"
                              { (yyval.i) = resolve_datatype(O_NUMBER,(yyvsp[0].str)); }
#line 4270 "mon_parse.c"
    break;

  case 281: /* number: H_NUMBER  */
#line 903 "mon_parse.y"
                 { (yyval.i) = (yyvsp[0].i); }
#line 4276 "mon_parse.c"
    break;

  case 282: /* number: B_NUMBER  */
#line 904 "mon_parse.y"
                 { (yyval.i) = (yyvsp[0].i); }
#line 4282 "mon_parse.c"
    break;

  case 283: /* number: D_NUMBER  */
#line 905 "mon_parse.y"
                 { (yyval.i) = (yyvsp[0].i); }
#line 4288 "mon_parse.c"
    break;

  case 284: /* number: O_NUMBER  */
#line 906 "mon_parse.y"
                 { (yyval.i) = (yyvsp[0].i); }
#line 4294 "mon_parse.c"
    break;

  case 285: /* number: guess_default  */
#line 907 "mon_parse.y"
                      { (yyval.i) = (yyvsp[0].i); }
#line 4300 "mon_parse.c"
    break;

  case 289: /* assembly_instruction: OPCODE asm_operand_mode  */
#line 915 "mon_parse.y"
                                              { (yyval.i) = 0;
                                                if ((yyvsp[-1].str)) {
                                                    (monitor_cpu_for_memspace[default_memspace]->mon_assemble_instr)((yyvsp[-1].str), (yyvsp[0].mode));
                                                } else {
                                                    new_cmd = 1;
                                                    asm_mode = 0;
                                                }
                                                opt_asm = 0;
                                              }
#line 4314 "mon_parse.c"
    break;

  case 291: /* post_assemble: assembly_instr_list  */
#line 926 "mon_parse.y"
                                   { asm_mode = 0; }
#line 4320 "mon_parse.c"
    break;

  case 292: /* asm_operand_mode: ARG_IMMEDIATE number  */
#line 929 "mon_parse.y"
                                       { if ((yyvsp[0].i) > 0xff) {
                          (yyval.mode).addr_mode = ASM_ADDR_MODE_IMMEDIATE_16;
                          (yyval.mode).param = (yyvsp[0].i);
                        } else {
                          (yyval.mode).addr_mode = ASM_ADDR_MODE_IMMEDIATE;
                          (yyval.mode).param = (yyvsp[0].i);
                        } }
#line 4332 "mon_parse.c"
    break;

  case 293: /* asm_operand_mode: number  */
#line 936 "mon_parse.y"
           { if ((yyvsp[0].i) >= 0x10000) {
               (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_LONG;
               (yyval.mode).param = (yyvsp[0].i);
             } else if ((yyvsp[0].i) < 0x100) {
               (yyval.mode).addr_mode = ASM_ADDR_MODE_ZERO_PAGE;
               (yyval.mode).param = (yyvsp[0].i);
             } else {
               (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE;
               (yyval.mode).param = (yyvsp[0].i);
             }
           }
#line 4348 "mon_parse.c"
    break;

  case 294: /* asm_operand_mode: number COMMA REG_X  */
#line 947 "mon_parse.y"
                        { if ((yyvsp[-2].i) >= 0x10000) {
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_LONG_X;
                            (yyval.mode).param = (yyvsp[-2].i);
                          } else if ((yyvsp[-2].i) < 0x100) { 
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_ZERO_PAGE_X;
                            (yyval.mode).param = (yyvsp[-2].i);
                          } else {
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_X;
                            (yyval.mode).param = (yyvsp[-2].i);
                          }
                        }
#line 4364 "mon_parse.c"
    break;

  case 295: /* asm_operand_mode: number COMMA REG_Y  */
#line 958 "mon_parse.y"
                        { if ((yyvsp[-2].i) < 0x100) {
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_ZERO_PAGE_Y;
                            (yyval.mode).param = (yyvsp[-2].i);
                          } else {
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_Y;
                            (yyval.mode).param = (yyvsp[-2].i);
                          }
                        }
#line 4377 "mon_parse.c"
    break;

  case 296: /* asm_operand_mode: number COMMA REG_S  */
#line 966 "mon_parse.y"
                        { if ((yyvsp[-2].i) < 0x100) {
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_STACK_RELATIVE;
                            (yyval.mode).param = (yyvsp[-2].i);
                          } else { /* 6809 */
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
                            if ((yyvsp[-2].i) >= -16 && (yyvsp[-2].i) < 16) {
                                (yyval.mode).addr_submode = (yyvsp[0].i) | ((yyvsp[-2].i) & 0x1F);
                            } else if ((yyvsp[-2].i) >= -128 && (yyvsp[-2].i) < 128) {
                                (yyval.mode).addr_submode = 0x80 | (yyvsp[0].i) | ASM_ADDR_MODE_INDEXED_OFF8;
                                (yyval.mode).param = (yyvsp[-2].i);
                            } else if ((yyvsp[-2].i) >= -32768 && (yyvsp[-2].i) < 32768) {
                                (yyval.mode).addr_submode = 0x80 | (yyvsp[0].i) | ASM_ADDR_MODE_INDEXED_OFF16;
                                (yyval.mode).param = (yyvsp[-2].i);
                            } else {
                                (yyval.mode).addr_mode = ASM_ADDR_MODE_ILLEGAL;
                                mon_out("offset too large even for 16 bits (signed)\n");
                            }
                          }
                        }
#line 4401 "mon_parse.c"
    break;

  case 297: /* asm_operand_mode: number COMMA number  */
#line 985 "mon_parse.y"
                        { if ((yyvsp[-2].i) < 0x100) {
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_DOUBLE;
                            (yyval.mode).param = (yyvsp[0].i);
                            (yyval.mode).addr_submode = (yyvsp[-2].i);
                          }
                        }
#line 4412 "mon_parse.c"
    break;

  case 298: /* asm_operand_mode: L_PAREN number R_PAREN  */
#line 991 "mon_parse.y"
                           { if ((yyvsp[-1].i) < 0x100) {
                               (yyval.mode).addr_mode = ASM_ADDR_MODE_INDIRECT;
                               (yyval.mode).param = (yyvsp[-1].i);
                             } else {
                               (yyval.mode).addr_mode = ASM_ADDR_MODE_ABS_INDIRECT;
                               (yyval.mode).param = (yyvsp[-1].i);
                             }
                           }
#line 4425 "mon_parse.c"
    break;

  case 299: /* asm_operand_mode: L_PAREN number COMMA REG_X R_PAREN  */
#line 999 "mon_parse.y"
                                       { if ((yyvsp[-3].i) < 0x100) {
                                           (yyval.mode).addr_mode = ASM_ADDR_MODE_INDIRECT_X;
                                           (yyval.mode).param = (yyvsp[-3].i);
                                         } else {
                                           (yyval.mode).addr_mode = ASM_ADDR_MODE_ABS_INDIRECT_X;
                                           (yyval.mode).param = (yyvsp[-3].i);
                                         }
                                       }
#line 4438 "mon_parse.c"
    break;

  case 300: /* asm_operand_mode: L_PAREN number COMMA REG_S R_PAREN COMMA REG_Y  */
#line 1008 "mon_parse.y"
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_STACK_RELATIVE_Y; (yyval.mode).param = (yyvsp[-5].i); }
#line 4444 "mon_parse.c"
    break;

  case 301: /* asm_operand_mode: L_PAREN number R_PAREN COMMA REG_Y  */
#line 1010 "mon_parse.y"
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_INDIRECT_Y; (yyval.mode).param = (yyvsp[-3].i); }
#line 4450 "mon_parse.c"
    break;

  case 302: /* asm_operand_mode: L_PAREN REG_BC R_PAREN  */
#line 1011 "mon_parse.y"
                           { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_BC; }
#line 4456 "mon_parse.c"
    break;

  case 303: /* asm_operand_mode: L_PAREN REG_DE R_PAREN  */
#line 1012 "mon_parse.y"
                           { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_DE; }
#line 4462 "mon_parse.c"
    break;

  case 304: /* asm_operand_mode: L_PAREN REG_HL R_PAREN  */
#line 1013 "mon_parse.y"
                           { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_HL; }
#line 4468 "mon_parse.c"
    break;

  case 305: /* asm_operand_mode: L_PAREN REG_IX R_PAREN  */
#line 1014 "mon_parse.y"
                           { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_IX; }
#line 4474 "mon_parse.c"
    break;

  case 306: /* asm_operand_mode: L_PAREN REG_IY R_PAREN  */
#line 1015 "mon_parse.y"
                           { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_IY; }
#line 4480 "mon_parse.c"
    break;

  case 307: /* asm_operand_mode: L_PAREN REG_SP R_PAREN  */
#line 1016 "mon_parse.y"
                           { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_SP; }
#line 4486 "mon_parse.c"
    break;

  case 308: /* asm_operand_mode: L_PAREN number R_PAREN COMMA REG_A  */
#line 1018 "mon_parse.y"
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_A; (yyval.mode).param = (yyvsp[-3].i); }
#line 4492 "mon_parse.c"
    break;

  case 309: /* asm_operand_mode: L_PAREN number R_PAREN COMMA REG_HL  */
#line 1020 "mon_parse.y"
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_HL; (yyval.mode).param = (yyvsp[-3].i); }
#line 4498 "mon_parse.c"
    break;

  case 310: /* asm_operand_mode: L_PAREN number R_PAREN COMMA REG_IX  */
#line 1022 "mon_parse.y"
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_IX; (yyval.mode).param = (yyvsp[-3].i); }
#line 4504 "mon_parse.c"
    break;

  case 311: /* asm_operand_mode: L_PAREN number R_PAREN COMMA REG_IY  */
#line 1024 "mon_parse.y"
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_IY; (yyval.mode).param = (yyvsp[-3].i); }
#line 4510 "mon_parse.c"
    break;

  case 312: /* asm_operand_mode: %empty  */
#line 1025 "mon_parse.y"
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_IMPLIED; }
#line 4516 "mon_parse.c"
    break;

  case 313: /* asm_operand_mode: REG_A  */
#line 1026 "mon_parse.y"
          { (yyval.mode).addr_mode = ASM_ADDR_MODE_ACCUMULATOR; }
#line 4522 "mon_parse.c"
    break;

  case 314: /* asm_operand_mode: REG_B  */
#line 1027 "mon_parse.y"
          { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_B; }
#line 4528 "mon_parse.c"
    break;

  case 315: /* asm_operand_mode: REG_C  */
#line 1028 "mon_parse.y"
          { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_C; }
#line 4534 "mon_parse.c"
    break;

  case 316: /* asm_operand_mode: REG_D  */
#line 1029 "mon_parse.y"
          { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_D; }
#line 4540 "mon_parse.c"
    break;

  case 317: /* asm_operand_mode: REG_E  */
#line 1030 "mon_parse.y"
          { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_E; }
#line 4546 "mon_parse.c"
    break;

  case 318: /* asm_operand_mode: REG_H  */
#line 1031 "mon_parse.y"
          { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_H; }
#line 4552 "mon_parse.c"
    break;

  case 319: /* asm_operand_mode: REG_IXH  */
#line 1032 "mon_parse.y"
            { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IXH; }
#line 4558 "mon_parse.c"
    break;

  case 320: /* asm_operand_mode: REG_IYH  */
#line 1033 "mon_parse.y"
            { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IYH; }
#line 4564 "mon_parse.c"
    break;

  case 321: /* asm_operand_mode: REG_L  */
#line 1034 "mon_parse.y"
          { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_L; }
#line 4570 "mon_parse.c"
    break;

  case 322: /* asm_operand_mode: REG_IXL  */
#line 1035 "mon_parse.y"
            { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IXL; }
#line 4576 "mon_parse.c"
    break;

  case 323: /* asm_operand_mode: REG_IYL  */
#line 1036 "mon_parse.y"
            { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IYL; }
#line 4582 "mon_parse.c"
    break;

  case 324: /* asm_operand_mode: REG_AF  */
#line 1037 "mon_parse.y"
           { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_AF; }
#line 4588 "mon_parse.c"
    break;

  case 325: /* asm_operand_mode: REG_BC  */
#line 1038 "mon_parse.y"
           { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_BC; }
#line 4594 "mon_parse.c"
    break;

  case 326: /* asm_operand_mode: REG_DE  */
#line 1039 "mon_parse.y"
           { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_DE; }
#line 4600 "mon_parse.c"
    break;

  case 327: /* asm_operand_mode: REG_HL  */
#line 1040 "mon_parse.y"
           { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_HL; }
#line 4606 "mon_parse.c"
    break;

  case 328: /* asm_operand_mode: REG_IX  */
#line 1041 "mon_parse.y"
           { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IX; }
#line 4612 "mon_parse.c"
    break;

  case 329: /* asm_operand_mode: REG_IY  */
#line 1042 "mon_parse.y"
           { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IY; }
#line 4618 "mon_parse.c"
    break;

  case 330: /* asm_operand_mode: REG_SP  */
#line 1043 "mon_parse.y"
           { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_SP; }
#line 4624 "mon_parse.c"
    break;

  case 331: /* asm_operand_mode: LESS_THAN number  */
#line 1045 "mon_parse.y"
                     { (yyval.mode).addr_mode = ASM_ADDR_MODE_DIRECT; (yyval.mode).param = (yyvsp[0].i); }
#line 4630 "mon_parse.c"
    break;

  case 332: /* asm_operand_mode: number COMMA index_ureg  */
#line 1046 "mon_parse.y"
                            {    /* Clash with addr,x addr,y addr,s modes! */
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        if ((yyvsp[-2].i) >= -16 && (yyvsp[-2].i) < 16) {
            (yyval.mode).addr_submode = (3 << 5) | ((yyvsp[-2].i) & 0x1F);
        } else if ((yyvsp[-2].i) >= -128 && (yyvsp[-2].i) < 128) {
            (yyval.mode).addr_submode = 0x80 | (3 << 5) | ASM_ADDR_MODE_INDEXED_OFF8;
            (yyval.mode).param = (yyvsp[-2].i);
        } else if ((yyvsp[-2].i) >= -32768 && (yyvsp[-2].i) < 32768) {
            (yyval.mode).addr_submode = 0x80 | (3 << 5) | ASM_ADDR_MODE_INDEXED_OFF16;
            (yyval.mode).param = (yyvsp[-2].i);
        } else {
            (yyval.mode).addr_mode = ASM_ADDR_MODE_ILLEGAL;
            mon_out("offset too large even for 16 bits (signed)\n");
        }
    }
#line 4650 "mon_parse.c"
    break;

  case 333: /* asm_operand_mode: COMMA index_reg PLUS  */
#line 1061 "mon_parse.y"
                         {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_INC1;
        }
#line 4659 "mon_parse.c"
    break;

  case 334: /* asm_operand_mode: COMMA index_reg PLUS PLUS  */
#line 1065 "mon_parse.y"
                              {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-2].i) | ASM_ADDR_MODE_INDEXED_INC2;
        }
#line 4668 "mon_parse.c"
    break;

  case 335: /* asm_operand_mode: COMMA MINUS index_reg  */
#line 1069 "mon_parse.y"
                          {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[0].i) | ASM_ADDR_MODE_INDEXED_DEC1;
        }
#line 4677 "mon_parse.c"
    break;

  case 336: /* asm_operand_mode: COMMA MINUS MINUS index_reg  */
#line 1073 "mon_parse.y"
                                {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[0].i) | ASM_ADDR_MODE_INDEXED_DEC2;
        }
#line 4686 "mon_parse.c"
    break;

  case 337: /* asm_operand_mode: COMMA index_reg  */
#line 1077 "mon_parse.y"
                    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[0].i) | ASM_ADDR_MODE_INDEXED_OFF0;
        }
#line 4695 "mon_parse.c"
    break;

  case 338: /* asm_operand_mode: REG_B COMMA index_reg  */
#line 1081 "mon_parse.y"
                          {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_OFFB;
        }
#line 4704 "mon_parse.c"
    break;

  case 339: /* asm_operand_mode: REG_A COMMA index_reg  */
#line 1085 "mon_parse.y"
                          {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_OFFA;
        }
#line 4713 "mon_parse.c"
    break;

  case 340: /* asm_operand_mode: REG_D COMMA index_reg  */
#line 1089 "mon_parse.y"
                          {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_OFFD;
        }
#line 4722 "mon_parse.c"
    break;

  case 341: /* asm_operand_mode: number COMMA REG_PC  */
#line 1093 "mon_parse.y"
                        {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).param = (yyvsp[-2].i);
        if ((yyvsp[-2].i) >= -128 && (yyvsp[-2].i) < 128) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFFPC8;
        } else if ((yyvsp[-2].i) >= -32768 && (yyvsp[-2].i) < 32768) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFFPC16;
        } else {
            (yyval.mode).addr_mode = ASM_ADDR_MODE_ILLEGAL;
            mon_out("offset too large even for 16 bits (signed)\n");
        }
    }
#line 4739 "mon_parse.c"
    break;

  case 342: /* asm_operand_mode: L_BRACKET number COMMA index_reg R_BRACKET  */
#line 1105 "mon_parse.y"
                                               {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        if ((yyvsp[-3].i) >= -16 && (yyvsp[-3].i) < 16) {
            (yyval.mode).addr_submode = (yyvsp[-3].i) & 0x1F;
        } else if ((yyvsp[-4].i) >= -128 && (yyvsp[-4].i) < 128) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFF8;
            (yyval.mode).param = (yyvsp[-3].i);
        } else if ((yyvsp[-3].i) >= -32768 && (yyvsp[-3].i) < 32768) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFF16;
            (yyval.mode).param = (yyvsp[-3].i);
        } else {
            (yyval.mode).addr_mode = ASM_ADDR_MODE_ILLEGAL;
            mon_out("offset too large even for 16 bits (signed)\n");
        }
    }
#line 4759 "mon_parse.c"
    break;

  case 343: /* asm_operand_mode: L_BRACKET COMMA index_reg PLUS R_BRACKET  */
#line 1120 "mon_parse.y"
                                             {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-2].i) | ASM_ADDR_MODE_INDEXED_INC1;
        }
#line 4768 "mon_parse.c"
    break;

  case 344: /* asm_operand_mode: L_BRACKET COMMA index_reg PLUS PLUS R_BRACKET  */
#line 1124 "mon_parse.y"
                                                  {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-3].i) | ASM_ADDR_MODE_INDEXED_INC2;
        }
#line 4777 "mon_parse.c"
    break;

  case 345: /* asm_operand_mode: L_BRACKET COMMA MINUS index_reg R_BRACKET  */
#line 1128 "mon_parse.y"
                                              {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_DEC1;
        }
#line 4786 "mon_parse.c"
    break;

  case 346: /* asm_operand_mode: L_BRACKET COMMA MINUS MINUS index_reg R_BRACKET  */
#line 1132 "mon_parse.y"
                                                    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_DEC2;
        }
#line 4795 "mon_parse.c"
    break;

  case 347: /* asm_operand_mode: L_BRACKET COMMA index_reg R_BRACKET  */
#line 1136 "mon_parse.y"
                                        {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_OFF0;
        }
#line 4804 "mon_parse.c"
    break;

  case 348: /* asm_operand_mode: L_BRACKET REG_B COMMA index_reg R_BRACKET  */
#line 1140 "mon_parse.y"
                                              {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-2].i) | ASM_ADDR_MODE_INDEXED_OFFB;
        }
#line 4813 "mon_parse.c"
    break;

  case 349: /* asm_operand_mode: L_BRACKET REG_A COMMA index_reg R_BRACKET  */
#line 1144 "mon_parse.y"
                                              {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-2].i) | ASM_ADDR_MODE_INDEXED_OFFA;
        }
#line 4822 "mon_parse.c"
    break;

  case 350: /* asm_operand_mode: L_BRACKET REG_D COMMA index_reg R_BRACKET  */
#line 1148 "mon_parse.y"
                                              {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-2].i) | ASM_ADDR_MODE_INDEXED_OFFD;
        }
#line 4831 "mon_parse.c"
    break;

  case 351: /* asm_operand_mode: L_BRACKET number COMMA REG_PC R_BRACKET  */
#line 1152 "mon_parse.y"
                                            {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).param = (yyvsp[-3].i);
        if ((yyvsp[-3].i) >= -128 && (yyvsp[-3].i) < 128) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFFPC8_IND;
        } else if ((yyvsp[-3].i) >= -32768 && (yyvsp[-3].i) < 32768) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFFPC16_IND;
        } else {
            (yyval.mode).addr_mode = ASM_ADDR_MODE_ILLEGAL;
            mon_out("offset too large even for 16 bits (signed)\n");
        }
    }
#line 4848 "mon_parse.c"
    break;

  case 352: /* asm_operand_mode: L_BRACKET number R_BRACKET  */
#line 1164 "mon_parse.y"
                               {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | ASM_ADDR_MODE_EXTENDED_INDIRECT;
        (yyval.mode).param = (yyvsp[-1].i);
        }
#line 4858 "mon_parse.c"
    break;

  case 353: /* asm_operand_mode: L_BRACKET number R_BRACKET COMMA REG_Y  */
#line 1169 "mon_parse.y"
                                           {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDIRECT_LONG_Y;
        (yyval.mode).param = (yyvsp[-3].i);
        }
#line 4867 "mon_parse.c"
    break;

  case 354: /* index_reg: REG_X  */
#line 1177 "mon_parse.y"
          { (yyval.i) = (0 << 5); printf("reg_x\n"); }
#line 4873 "mon_parse.c"
    break;

  case 355: /* index_reg: REG_Y  */
#line 1178 "mon_parse.y"
          { (yyval.i) = (1 << 5); printf("reg_y\n"); }
#line 4879 "mon_parse.c"
    break;

  case 356: /* index_reg: index_ureg  */
#line 1179 "mon_parse.y"
               { (yyval.i) = (yyvsp[0].i); }
#line 4885 "mon_parse.c"
    break;

  case 357: /* index_reg: REG_S  */
#line 1180 "mon_parse.y"
          { (yyval.i) = (3 << 5); printf("reg_s\n"); }
#line 4891 "mon_parse.c"
    break;

  case 358: /* index_ureg: REG_U  */
#line 1184 "mon_parse.y"
          { (yyval.i) = (2 << 5); printf("reg_u\n"); }
#line 4897 "mon_parse.c"
    break;


#line 4901 "mon_parse.c"

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

#line 1188 "mon_parse.y"


int parse_and_execute_line(char *input)
{
   char *temp_buf;
   int i, rc;

   if (default_memspace == e_comp_space) {
       /*
        * If the command is to be executed when the default address space is the main cpu,
        * Ensure drive CPU emulation is up to date with main cpu CLOCK.
        */
       drive_cpu_execute_all(maincpu_clk);
   }

   temp_buf = lib_malloc(strlen(input) + 3);
   strcpy(temp_buf,input);
   i = (int)strlen(input);
   temp_buf[i++] = '\n';
   temp_buf[i++] = '\0';
   temp_buf[i++] = '\0';

   make_buffer(temp_buf);
   mon_clear_buffer();
   if ( (rc =yyparse()) != 0) {
       mon_out("ERROR -- ");
       switch(rc) {
         case ERR_BAD_CMD:
           mon_out("Bad command:\n");
           break;
         case ERR_RANGE_BAD_START:
           mon_out("Bad first address in range:\n");
           break;
         case ERR_RANGE_BAD_END:
           mon_out("Bad second address in range:\n");
           break;
         case ERR_EXPECT_CHECKNUM:
           mon_out("Checkpoint number expected:\n");
           break;
         case ERR_EXPECT_END_CMD:
           mon_out("Unexpected token:\n");
           break;
         case ERR_MISSING_CLOSE_PAREN:
           mon_out("')' expected:\n");
           break;
         case ERR_INCOMPLETE_COND_OP:
           mon_out("Conditional operation missing an operand:\n");
           break;
         case ERR_EXPECT_FILENAME:
           mon_out("Expecting a filename:\n");
           break;
         case ERR_ADDR_TOO_BIG:
           mon_out("Address too large:\n");
           break;
         case ERR_IMM_TOO_BIG:
           mon_out("Immediate argument too large:\n");
           break;
         case ERR_EXPECT_STRING:
           mon_out("Expecting a string.\n");
           break;
         case ERR_UNDEFINED_LABEL:
           mon_out("Found an undefined label.\n");
           break;
         case ERR_EXPECT_DEVICE_NUM:
           mon_out("Expecting a device number.\n");
           break;
         case ERR_EXPECT_ADDRESS:
           mon_out("Expecting an address.\n");
           break;
         case ERR_INVALID_REGISTER:
           mon_out("Invalid register.\n");
           break;
         case ERR_ILLEGAL_INPUT:
         default:
           mon_out("Wrong syntax:\n");
       }
       mon_out("  %s\n", input);
       for (i = 0; i < last_len; i++)
           mon_out(" ");
       mon_out("  ^\n");
       asm_mode = 0;
       new_cmd = 1;
   }
   lib_free(temp_buf);
   free_buffer();

   return rc;
}

void set_yydebug(int val)
{
#if YYDEBUG
    yydebug = val;
#else
#endif
}

static int yyerror(char *s)
{
#if 0
   fprintf(stderr, "ERR:%s\n", s);
#endif
   return 0;
}

/* convert the string in "num" to a numeric value, depending on radix. this 
   function does some magic conversion on addresses when radix is not hex.
*/
static int resolve_datatype(unsigned guess_type, const char *num)
{
    int binary = 1, hex = 0, octal = 0, decimal = 1;
    const char *c;

    /* FIXME: Handle cases when default type is non-numerical */
    if (default_radix == e_hexadecimal) {
        return (int)strtol(num, NULL, 16);
    }

    /* we do some educated guessing on what type of number we have here */
    if (num[0] == '0') {
        /* might be octal with leading zero */
        octal = 1;
    }
    /* a string containing any digits not 0 or 1 can't be a binary number */
    c = num;
    while (*c) {
        if ((*c != '0') && (*c != '1')) {
            binary = 0;
            break;
        }
        c++;
    }
    /* a string containing 8 or 9 can't be an octal number */
    c = num;
    while (*c) {
        if ((*c == '8') && (*c == '9')) {
            octal = 0;
            break;
        }
        c++;
    }
    /* a string containing any of A-F can only be a hex number */
    c = num;
    while (*c) {
        if ((tolower((unsigned char)*c) >= 'a') && (tolower((unsigned char)*c) <= 'f')) {
            hex = 1;
            octal = 0;
            binary = 0;
            decimal = 0;
            break;
        }
        c++;
    }

    /* a hex number can only be hex no matter what */
    if (hex) {
        return (int)strtol(num, NULL, 16);
    }

    /* first, if default radix and detected number matches, just do it */
    if (binary && (default_radix == e_binary)) {
        return (int)strtol(num, NULL, 2);
    }
    if (decimal && (default_radix == e_decimal)) {
        return (int)strtol(num, NULL, 10);
    }
    if (octal && (default_radix == e_octal)) {
        return (int)strtol(num, NULL, 8);
    }

    /* second, if detected number matches guess type, do it */
    if (binary && (guess_type == B_NUMBER)) {
        return (int)strtol(num, NULL, 2);
    }
    if (decimal && (guess_type == D_NUMBER)) {
        return (int)strtol(num, NULL, 10);
    }
    if (octal && (guess_type == O_NUMBER)) {
        return (int)strtol(num, NULL, 8);
    }

    /* third only use the detected type */
    if (binary) {
        return (int)strtol(num, NULL, 2);
    }
    if (decimal) {
        return (int)strtol(num, NULL, 10);
    }
    if (octal) {
        return (int)strtol(num, NULL, 8);
    }

    /* use hex as default, should we ever come here */
    return (int)strtol(num, NULL, 16);
}

/*
 * Resolve a character sequence containing 8 hex digits like "08001000".
 * This could be a lazy version of "0800 1000". If the default radix is not
 * hexadecimal, we handle it like a ordinary number, in the latter case there
 * is only one number in the range.
 */
static int resolve_range(enum t_memspace memspace, MON_ADDR range[2],
                         const char *num)
{
    char start[5];
    char end[5];
    long sa;

    range[1] = BAD_ADDR;

    switch (default_radix)
    {
    case e_hexadecimal:
        /* checked twice, but as the code must have exactly 8 digits: */
        if (strlen(num) == 8) {
            memcpy(start, num, 4);
            start[4] = '\0';
            memcpy(end, num + 4, 4);
            end[4] = '\0';
            sa = strtol(start, NULL, 16);
            range[1] = (int)new_addr(memspace, strtol(end, NULL, 16));
        }
        else
            sa = strtol(num, NULL, 16);
        break;

    case e_decimal:
       sa = strtol(num, NULL, 10);
       break;

    case e_octal:
       sa = strtol(num, NULL, 8);
       break;

    default:
       sa = strtol(num, NULL, 2);
    }

    if (!CHECK_ADDR(sa))
        return ERR_ADDR_TOO_BIG;

    range[0] = (int)new_addr(memspace, sa);
    return 0;
}
