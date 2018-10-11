IDIR =../include
CC=g++
CFLAGS=-I $(IDIR)
ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = contador.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = testa_contador.o funcoes_contador.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
