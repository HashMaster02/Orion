# Core/Makefile
CXX = g++
CC = gcc
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -I./include
CFLAGS = -Wall -Wextra -O2 -I./include

# GLFW platform definition
CFLAGS += -D_GLFW_X11

# Flags for GLFW files only (suppresses warnings)
GLFW_CFLAGS = -O2 -I./include -D_GLFW_X11 -Wno-unused-parameter -Wno-unused-function

AR = ar
ARFLAGS = rcs

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BUILD_DIR = ../build

# Files
CPP_SRCS = $(shell find $(SRC_DIR) -name '*.cpp')
C_SRCS = $(shell find $(SRC_DIR) -name '*.c')
GLFW_C_SRCS = $(shell find $(SRC_DIR)/GLFW -name '*.c')
NON_GLFW_C_SRCS = $(filter-out $(GLFW_C_SRCS), $(C_SRCS))

CPP_OBJS = $(CPP_SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
GLFW_OBJS = $(GLFW_C_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
NON_GLFW_C_OBJS = $(NON_GLFW_C_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS = $(CPP_OBJS) $(GLFW_OBJS) $(NON_GLFW_C_OBJS)

TARGET = $(BUILD_DIR)/libcore.a

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS) | $(BUILD_DIR)
	@echo "Creating static library: $@"
	@$(AR) $(ARFLAGS) $@ $^

# Compile C++ files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compiling C++: $<"
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile GLFW C files (with warnings suppressed)
$(OBJ_DIR)/GLFW/%.o: $(SRC_DIR)/GLFW/%.c
	@echo "Compiling C (GLFW): $<"
	@mkdir -p $(dir $@)
	@$(CC) $(GLFW_CFLAGS) -c $< -o $@

# Compile other C files (with full warnings)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling C: $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

clean:
	@echo "Cleaning Core..."
	@rm -rf $(OBJ_DIR)
	@rm -f $(TARGET)