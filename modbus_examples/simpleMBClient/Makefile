SHELL = /bin/sh
CC = gcc
AR = ar ruvs
RANLIB = ranlib
LEX = lex
YACC = yacc
OFLAGS = -o

LIBMODBUS_INC_HOME = /usr/local/include
LIBMODBUS_LIB_HOME = /usr/local/lib
LIBMODBUS_INCLUDE = -I$(LIBMODBUS_INC_HOME)
#LIBMODBUS_LIBS = -Wl,-rpath, $(LIBMODBUS_LIB_HOME)/libmodbus.dylib -L$(LIBMODBUS_LIB_HOME) -lmodbus
LIBMODBUS_LIBS = -Wl,-L$(LIBMODBUS_LIB_HOME) -lmodbus

INCLUDE = -I. $(GW_ALL_INC) $(LIBMODBUS_INCLUDE)
LIB = $(GW_BASE_LIB) $(LIBMODBUS_LIBS)

CFLAGS = -c -O3 -fno-strict-aliasing -fPIC -Wall -Wno-pointer-sign -DLINUX

PRODUCT = MODBUS_C

C_SOURCE = \
	modbus_c.c

C_OBJECT = \
	modbus_c.o

.SUFFIXES: .o .c

all: $(PRODUCT)

.c.o: $(C_SOURCE)
	$(CC) $(CFLAGS) $(INCLUDE) $*.c

$(PRODUCT): $(C_OBJECT)
	$(CC) $(OFLAGS) $(PRODUCT) $(C_OBJECT) $(LIB)

clean: $(C_SOURCE)
	rm *.o $(PRODUCT)
