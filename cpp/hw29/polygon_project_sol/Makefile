CFLAGS=-c -std=c++11
CC=g++
EXECUTABLE=a.out
INCLUDE_DIR=./include
SOURCE_DIR=./source
OBJECT_DIR=./build
SOURCE_FILES=point.cpp polygon.cpp main.cpp
OBJECT_FILES=$(SOURCE_FILES:.cpp=.o)
OBJECTS_WITH_PATHS=$(addprefix $(OBJECT_DIR)/, $(OBJECT_FILES))

INCLUDES=-I$(INCLUDE_DIR)

.PHONY: all clean

all: $(EXECUTABLE) 

$(EXECUTABLE): $(OBJECTS_WITH_PATHS)
	$(CC) $(OBJECTS_WITH_PATHS) -o $@

build/%.o: source/%.cpp $(OBJECT_DIR)
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

$(OBJECT_DIR):
	mkdir -p build

clean:
	rm -r build a.out
