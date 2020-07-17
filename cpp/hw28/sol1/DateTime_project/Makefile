CC=g++
CFLAGS=-c -std=c++11
EXECUTABLE=a.out
INCLUDE_DIR=./include
OBJECT_DIR=build
SOURCE_FILES=itos.cpp datetime.cpp main.cpp
HEADER_FILES=itos.hpp datetime.hpp
OBJECT_FILES=$(SOURCE_FILES:.cpp=.o)
OBJECTS_WITH_PATHS=$(addprefix $(OBJECT_DIR)/, $(OBJECT_FILES))
SOURSES_WITH_PATHS=$(addprefix $(SOURCE_DIR)/, $(SOURCE_FILES))
INCLUDES=-I$(INCLUDE_DIR)

.PHONY: all clean

all: $(EXECUTABLE)
	echo $(OBJECT_FILES)
	echo $(OBJECTS_WITH_PATHS)

$(EXECUTABLE): $(OBJECTS_WITH_PATHS)
	$(CC) $(OBJECTS_WITH_PATHS) -o $@

build/%.o: source/%.cpp $(OBJECT_DIR)
	$(CC) $(INCLUDES) $(CFLAGS) $< -o  $@


$(OBJECT_DIR):
	mkdir -p $(OBJECT_DIR)

clean:
	rm -r build
