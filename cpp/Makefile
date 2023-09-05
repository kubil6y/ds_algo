################################################################################
# Declare some Makefile variables
################################################################################
CC = g++
LANG_STD = -std=c++17
COMPILER_FLAGS = -Wall -Wfatal-errors
SRC_FILES = ./src/*.cpp \
			./src/LinkedList/*.cpp \
			./src/DoublyLinkedList/*.cpp \
			./src/StacksAndQueues/*.cpp \
			./src/BinarySearchTree/*.cpp \
			./src/HashTable/*.cpp \
			./src/Graph/*.cpp 

OBJ_NAME = main

################################################################################
# Declare some Makefile rules
################################################################################
build:
	@$(CC) $(COMPILER_FLAGS) $(LANG_STD) $(SRC_FILES) -o $(OBJ_NAME)

run:
	@./$(OBJ_NAME)

dev: build run

clean:
	rm $(OBJ_NAME)
