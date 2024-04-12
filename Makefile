# Compiler
CC := g++
# Compiler flags
CFLAGS := -Wall -Wextra -std=c++23
# Source directory
SRC_DIR := src
# Header directory
INC_DIR := include
# Build directory
BUILD_DIR := build
# Executable name
EXEC := ConsoleCollection

# Files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
TPPS := $(wildcard $(SRC_DIR)/*.tpp)
OBJS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SRCS:.cpp=.o)) $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(TPPS:.tpp=.o))

all: $(EXEC)

# Clean
clean:
	rm -rf $(BUILD_DIR) $(EXEC).exe

run: $(EXEC)
	./$(EXEC)
	
# Main target
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule for compiling .cpp files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Rule for compiling .tpp files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.tpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Phony target
.PHONY: clean
