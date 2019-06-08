IDIR =./source
CC=g++
CFLAGS=-I$(IDIR) -Wall -Wextra #-Werror

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
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BINDIR)/minesweeper: $(OBJ)
	@mkdir -p $(@D)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~     


