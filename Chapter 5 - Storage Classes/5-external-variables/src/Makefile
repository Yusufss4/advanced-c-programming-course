IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) -ggdb -std=c++11

ODIR=obj
LDIR =../lib

LIBS=-lm

#Add file names in the include folder. 
_DEPS = display.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

#Add file names in the src folder.
_OBJ = display.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#Change the name of "hellomake" to your executible. 
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 