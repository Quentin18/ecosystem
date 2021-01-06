EXEC=ecosystem.out
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
CC=g++ -std=c++11 -g
CLIBS=-lsfml-graphics -lsfml-window -lsfml-system

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) $(CLIBS) -o $(EXEC)

%.o: %.cpp
	$(CC) -Wall $(INCDIR) -c $< -o $@

.depend: $(SOURCES)
	g++ -std=c++11 -MM $(SOURCES) > .depend

-include .depend

clean:
	rm -f $(OBJECTS) $(EXEC)
