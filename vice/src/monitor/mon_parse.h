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

#line 446 "mon_parse.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MON_PARSE_H_INCLUDED  */
