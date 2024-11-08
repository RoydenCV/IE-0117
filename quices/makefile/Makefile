# General variables
CC=gcc
CFLAGS=-Wall
INCLUDE=./include/
SRC=./src/
EXE=exe

# targets
hw:
	$(CC) -o hw.o -I$(INCLUDE) -c $(SRC)hello_world.c

test: hw
	$(CC) -o $(EXE) $(CFLAGS) -I$(INCLUDE) test/main.c hw.o

clean:
	rm -f *.o $(EXE)


# Realmente no entendi como hacer los makefiles para que cumplieran con lo que 
# se nos pide :c