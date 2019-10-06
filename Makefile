CC=g++
CXXFLAGS= -std=c++17 -Wall -O2 -march=native -I includes -c
DEBUGFLAGS= -std=c++17 -Wall -I includes -g
LDFLAGS=
HEADERS=includes/*.hpp
SOURCES=srcs/game.cpp srcs/hangman.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hangman


all: $(HEADERS) $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CXXFLAGS) -c $< -o $@

debug : $(HEADERS) $(SOURCES)
	$(CC) $(DEBUGFLAGS) $(SOURCES) -o $(EXECUTABLE)

clean:
	rm $(EXECUTABLE) $(OBJECTS)
