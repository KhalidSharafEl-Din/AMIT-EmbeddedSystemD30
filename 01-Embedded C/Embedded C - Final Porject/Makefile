
CC=gcc 
CFLAGS=-I.
RM = rm

DEPS = $(wildcard $(SRC)/*.h)

SRC = src
OBJ = obj
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o,$(SRCS))

BINDIR= bin
BIN = $(BINDIR)/main

LIBDIR=lib
LIB = $(LIBDIR)/simpleDB.a

TEST=tests
TTESTS=$(wildcard $(TESTS)/*.c)
TESTBINS = $(patsubst $(TEST)/%.c, $(TEST)/bin/%.o, $(TEST))


all : $(BIN) $(LIB)

$(BIN) : $(OBJS)
	$(CC)  $^ $(CFLAGS) -o $@

$(OBJ)/%.o:$(SRC)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(LIB) : $(LIBDIR) $(OBJ) $(OBJS)
	ar -cvrs $(LIB) $(OBJS)

$(TEST)/bin/%.o: $(TEST)/%.c
#$(CC) $(CFLAGS) $< $(OBJS) -o $@ 
	$(CC) -c -o $@ $< $(CFLAGS) -lcriterion

test : $(LIB) $(TEST)/bin $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test;	done



$(TEST)/bin:
	mkdir $@

$(OBJ)/bin:
	mkdir $@

$(LIBDIR)/bin:
	mkdir $@


clean : 
	$(RM) $(OBJ)/* $(BINDIR)/* $(LIBDIR)/* $(TEST)/bin/*

