CXXFLAGS  = -g -Wall -Wwrite-strings
EXEC      = generator

all:
	g++ $(CXXFLAGS) main.cpp -o $(EXEC)

clean: 
	rm -f *.o *.bak core $(EXEC)
