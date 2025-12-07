/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_HELPTEXT = 258,
     T_WORD = 259,
     T_WORD_QUOTE = 260,
     T_BOOL = 261,
     T_CHOICE = 262,
     T_CLOSE_PAREN = 263,
     T_COLON_EQUAL = 264,
     T_COMMENT = 265,
     T_CONFIG = 266,
     T_DEFAULT = 267,
     T_DEF_BOOL = 268,
     T_DEF_TRISTATE = 269,
     T_DEPENDS = 270,
     T_ENDCHOICE = 271,
     T_ENDIF = 272,
     T_ENDMENU = 273,
     T_HELP = 274,
     T_HEX = 275,
     T_IF = 276,
     T_IMPLY = 277,
     T_INT = 278,
     T_MAINMENU = 279,
     T_MENU = 280,
     T_MENUCONFIG = 281,
     T_MODULES = 282,
     T_ON = 283,
     T_OPEN_PAREN = 284,
     T_PLUS_EQUAL = 285,
     T_PROMPT = 286,
     T_RANGE = 287,
     T_SELECT = 288,
     T_SOURCE = 289,
     T_STRING = 290,
     T_TRANSITIONAL = 291,
     T_TRISTATE = 292,
     T_VISIBLE = 293,
     T_EOL = 294,
     T_ASSIGN_VAL = 295,
     T_OR = 296,
     T_AND = 297,
     T_UNEQUAL = 298,
     T_EQUAL = 299,
     T_GREATER_EQUAL = 300,
     T_GREATER = 301,
     T_LESS_EQUAL = 302,
     T_LESS = 303,
     T_NOT = 304
   };
#endif
/* Tokens.  */
#define T_HELPTEXT 258
#define T_WORD 259
#define T_WORD_QUOTE 260
#define T_BOOL 261
#define T_CHOICE 262
#define T_CLOSE_PAREN 263
#define T_COLON_EQUAL 264
#define T_COMMENT 265
#define T_CONFIG 266
#define T_DEFAULT 267
#define T_DEF_BOOL 268
#define T_DEF_TRISTATE 269
#define T_DEPENDS 270
#define T_ENDCHOICE 271
#define T_ENDIF 272
#define T_ENDMENU 273
#define T_HELP 274
#define T_HEX 275
#define T_IF 276
#define T_IMPLY 277
#define T_INT 278
#define T_MAINMENU 279
#define T_MENU 280
#define T_MENUCONFIG 281
#define T_MODULES 282
#define T_ON 283
#define T_OPEN_PAREN 284
#define T_PLUS_EQUAL 285
#define T_PROMPT 286
#define T_RANGE 287
#define T_SELECT 288
#define T_SOURCE 289
#define T_STRING 290
#define T_TRANSITIONAL 291
#define T_TRISTATE 292
#define T_VISIBLE 293
#define T_EOL 294
#define T_ASSIGN_VAL 295
#define T_OR 296
#define T_AND 297
#define T_UNEQUAL 298
#define T_EQUAL 299
#define T_GREATER_EQUAL 300
#define T_GREATER 301
#define T_LESS_EQUAL 302
#define T_LESS 303
#define T_NOT 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 36 "parser.y"
{
	char *string;
	struct symbol *symbol;
	struct expr *expr;
	struct menu *menu;
	enum symbol_type type;
	enum variable_flavor flavor;
}
/* Line 1529 of yacc.c.  */
#line 156 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

