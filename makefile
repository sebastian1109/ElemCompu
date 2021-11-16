FLAGS0 = -O0
FLAGS1 = -O2
FLAGS2 = -O3
FLAGS3 = -Og

OBJECTS = heat.c tools.c 

BIN1 = solheat
BIN2 = soldebug
BIN3 = solprof

all: $(BIN1)

solheat: $(OBJECTS)
	gcc -o $(BIN1) $(FLAGS1) $(OBJECTS) -lm
	
soldebug: $(OBJECTS) 
	gcc -g -o $(BIN2) $(FLAGS0) $(OBJECTS) -lm
  
solprof: $(OBJECTS)
	gcc -pg -o $(BIN3) $(FLAGS3) $(OBJECTS) -lm


