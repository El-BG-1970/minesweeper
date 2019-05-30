IDIR =./source
CC=g++
CFLAGS=-I$(IDIR)

ODIR=./build
LDIR =./lib
SOURCE=./source
BINDIR=./bin

LIBS=-lm

_DEPS = grid.cpp game.cpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o grid.o game.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SOURCE)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BINDIR)/minesweeper: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~     
