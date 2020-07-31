CC=g++
INCLUDE_DIR=./include
SOURCES_DIR=./source
OBJECTS_DIR=./build
EXECUTABLE=a.out
SOURCE_FILES=itos.cpp datetime.cpp main.cpp
HEADER_FILES=itos.hpp datetime.hpp
OBJECT_FILES=$(SOURCE_FILES:.cpp=.o)
OBJECTS_WITH_PATHS=$(addprefix $(OBJECTS_DIR)/, $(OBJECT_FILES))
SOURCES_WITH_PATHS=$(addprefix $(SOURCES_DIR)/, $(SOURCE_FILES)) 

CFLAGS=-c
INCLUDES=-I$(INCLUDE_DIR)

.PHONY: clean all

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS_DIR) $(OBJECTS_WITH_PATHS)
	$(CC) $(OBJECTS_WITH_PATHS) -o $@

$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)

build/%.o: source/%.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

clean:
	rm -r build
