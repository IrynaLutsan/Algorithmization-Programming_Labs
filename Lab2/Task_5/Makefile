# Compiler settings
CC      = gcc
CFLAGS  = -Wall -Wextra -Iinclude

# Project folders
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Target program name
TARGET  = $(BIN_DIR)/program

# Collect all .c files in src/
SRC     = $(wildcard $(SRC_DIR)/*.c)
# Replace src/ with obj/ and .c with .o for object files
OBJ     = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Default rule
all: $(TARGET)

# Link object files into final binary
$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c into .o in obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create directories if they don't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean rule
.PHONY: clean
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
