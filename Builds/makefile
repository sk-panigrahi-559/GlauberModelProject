# Define variables
CXX = g++
CXXFLAGS = -Wall -g

# Directories
BUILD_DIR = ./
LIB_DIR = ../MyLibraries

# Target executable
TARGET = $(BUILD_DIR)/GlauberModel

# Source and object files
SRC = ../main.cpp \
      $(LIB_DIR)/Collision.cpp \
      $(LIB_DIR)/Nucleon.cpp \
      $(LIB_DIR)/Nucleus.cpp \
      $(LIB_DIR)/mathematicalfunctions.cpp

OBJ = $(BUILD_DIR)/main.o \
      $(BUILD_DIR)/Collision.o \
      $(BUILD_DIR)/Nucleon.o \
      $(BUILD_DIR)/Nucleus.o \
      $(BUILD_DIR)/mathematicalfunctions.o

# Default rule to build the target
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Rules to compile each source file into object files
$(BUILD_DIR)/main.o: ../main.cpp
	$(CXX) $(CXXFLAGS) -c ../main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/Collision.o: $(LIB_DIR)/Collision.cpp $(LIB_DIR)/Collision.h
	$(CXX) $(CXXFLAGS) -c $(LIB_DIR)/Collision.cpp -o $(BUILD_DIR)/Collision.o

$(BUILD_DIR)/Nucleon.o: $(LIB_DIR)/Nucleon.cpp $(LIB_DIR)/Nucleon.h
	$(CXX) $(CXXFLAGS) -c $(LIB_DIR)/Nucleon.cpp -o $(BUILD_DIR)/Nucleon.o

$(BUILD_DIR)/Nucleus.o: $(LIB_DIR)/Nucleus.cpp $(LIB_DIR)/Nucleus.h
	$(CXX) $(CXXFLAGS) -c $(LIB_DIR)/Nucleus.cpp -o $(BUILD_DIR)/Nucleus.o

$(BUILD_DIR)/mathematicalfunctions.o: $(LIB_DIR)/mathematicalfunctions.cpp $(LIB_DIR)/mathematicalfunctions.h
	$(CXX) $(CXXFLAGS) -c $(LIB_DIR)/mathematicalfunctions.cpp -o $(BUILD_DIR)/mathematicalfunctions.o

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(TARGET)

