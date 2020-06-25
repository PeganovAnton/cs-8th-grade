CC=g++
INCLUDE_DIR=include
SOURCES_DIR=source
OBJECTS_DIR=build
CFLAGS=-C
EXECUTABLE=a.out
SOURCE_FILES=itos.cpp datetime.cpp main.cpp
HEADER_FILES=itos.hpp datetime.hpp
OBJECT_FILES=$(SOURCE_FILES:.cpp=.o)
OBJECTS_WITH_PATHS=$(addprefix $(OBJECTS_DIR)/, $(OBJECT_FILES))
SOURCES_WITH_PATHS=$(addprefix $(SOURCES_DIR)/, $(SOURCE_FILES)) 

.PHONY: clean all

all: $(EXECUTABLE)
	echo $(OBJECTS_WITH_PATHS)

$(EXECUTABLE): $(OBJECTS_DIR) $(OBJECTS_WITH_PATHS)
	$(CC) -o $@ $(OBJECTS_WITH_PATHS)

$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)

$(OBJECTS_WITH_PATHS): $(SOURCES_WITH_PATHS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -r build
