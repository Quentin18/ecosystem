EXEC=ecosystem.out
SOURCES=$(wildcard src/pbPlots/*.cpp) $(wildcard src/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
CC=g++ -std=c++11 -g
CLIBS=-lsfml-graphics -lsfml-window -lsfml-system -lm

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) $(CLIBS) -o $(EXEC)

src/pbPlots/%.o: src/pbPlots/%.cpp
	$(CC) $(INCDIR) -c $< -o $@

%.o: %.cpp
	$(CC) -Wall $(INCDIR) -c $< -o $@

.depend: $(SOURCES)
	g++ -std=c++11 -MM $(SOURCES) > .depend

-include .depend

clean:
	rm -f $(OBJECTS) $(EXEC)
