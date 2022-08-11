# MakeFile for creating a Library Archive File. 1 Header 1 File

IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)
LIB_NAME = StringFunctions

ODIR=obj
LDIR =../lib

_DEPS = $(LIB_NAME).h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = $(LIB_NAME).o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(LIB_NAME): $(OBJ)
	ar -rcs $@.a $^
	ar -t $(LIB_NAME).a

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 