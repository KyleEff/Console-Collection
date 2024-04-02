# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source files
SRCS := $(wildcard *.cpp)

# Object files
OBJS := $(SRCS:.cpp=.o)

# Output executable
EXEC = ConsoleCollection

# Default target
all: $(EXEC)
	rm -f $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Link object files into executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

run: $(EXEC)
	./$(EXEC)
	rm -f $(OBJS) $(EXEC).exe

# Clean up generated files
clean:
	rm -f $(OBJS) $(EXEC).exe
