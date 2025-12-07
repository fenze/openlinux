CC   ?= gcc
LEX  ?= flex
YACC ?= bison

VPATH := $(srctree)/scripts/kconfig

CFLAGS := -Iinclude
LDFLAGS := -lncurses

common-obj := confdata.o expr.o lexer.lex.o menu.o parser.tab.o \
               preprocess.o symbol.o util.o

lxdl-obj := checklist.o inputbox.o menubox.o \
             textbox.o lutil.o yesno.o \
             mnconf-common.o

conf: conf.o $(common-obj)
mconf: mconf.o $(common-obj) $(lxdl-obj)
nconf: nconf.o nconf.gui.o mnconf-common.o $(common-obj)
lexer.lex.c: lexer.l
parser.tab.c parser.tab.h: parser.y

%.lex.c: %.l
	$(LEX) -o $@ $<

parser.tab.c parser.tab.h: parser.y
	$(YACC) -d -o parser.tab.c $<

syncconfig: conf
	scripts/kconfig/conf --syncconfig Kconfig .config

menuconfig: mconf
	scripts/kconfig/mconf Kconfig

clean:
	rm -f *.o lexer.lex.c parser.tab.c parser.tab.h conf mconf nconf

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%: %.o
	$(CC) $(LDFLAGS) -o $@ $?

.PHONY: menuconfig syncconfig clean
