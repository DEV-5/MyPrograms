# Define the C++ compiler
CXX = g++

# Define compiler flags (e.g., C++11 standard, all warnings, optimization level 2)
CXXFLAGS = -std=c++11 -Wall -O2

# Define the name of the final executable
TARGET = myprogram


# List the C++ source files
SOURCES = main.cpp classes_shapes.cpp classes_circle.cpp

# Automatically generate object file names from source files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target: builds the executable
all: $(TARGET)

# Rule to link object files into the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Pattern rule to compile .cpp files into .o object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean target: removes generated files
clean:
	rm -f $(TARGET) $(OBJECTS)
