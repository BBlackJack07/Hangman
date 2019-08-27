CC=g++
CXXFLAGS= -std=c++17 -Wall -O2 -march=native -I headers -c
DEBUGFLAGS= -std=c++17 -Wall -I headers -g
LDFLAGS=
HEADERS=headers/*.hpp
SOURCES=sources/game.cpp sources/hangman.cpp
EXECUTABLE=pendu
OBJECTS=$(SOURCES:.cpp=.o)


all: $(HEADERS) $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CXXFLAGS) -c $< -o $@

debug : $(HEADERS) $(SOURCES)
	$(CC) $(DEBUGFLAGS) $(SOURCES) -o $(EXECUTABLE)

clean:
	rm $(EXECUTABLE) $(OBJECTS)
