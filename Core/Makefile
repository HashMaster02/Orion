# Core/Makefile
CXX = g++
CC = gcc
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -I./include
CFLAGS = -Wall -Wextra -O2 -I./include

AR = ar
ARFLAGS = rcs

# Platform detection and configuration
ifeq ($(OS),Windows_NT)
    # Windows configuration
    PLATFORM := WIN32
    CFLAGS += -D_GLFW_WIN32
    GLFW_CFLAGS = -O2 -I./include -D_GLFW_WIN32 -Wno-unused-parameter -Wno-unused-function
    
    # File discovery using wildcard (supports up to 3 levels deep)
    CPP_SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*/*.cpp) $(wildcard $(SRC_DIR)/*/*/*.cpp)
    C_SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c) $(wildcard $(SRC_DIR)/*/*/*.c)
    GLFW_C_SRCS = $(wildcard $(SRC_DIR)/GLFW/*.c)
    
    # Directory creation command
    MKDIR = if not exist $(subst /,\,$(1)) mkdir $(subst /,\,$(1))
else
    # Linux/Unix configuration
    PLATFORM := X11
    CFLAGS += -D_GLFW_X11
    GLFW_CFLAGS = -O2 -I./include -D_GLFW_X11 -Wno-unused-parameter -Wno-unused-function
    
    # File discovery using find
    CPP_SRCS = $(shell find $(SRC_DIR) -name '*.cpp')
    C_SRCS = $(shell find $(SRC_DIR) -name '*.c')
    GLFW_C_SRCS = $(shell find $(SRC_DIR)/GLFW -name '*.c')
    
    # Directory creation command
    MKDIR = mkdir -p $(1)
endif

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BUILD_DIR = ../build

# Object files
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
	@$(call MKDIR,$(dir $@))
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile GLFW C files (with warnings suppressed)
$(OBJ_DIR)/GLFW/%.o: $(SRC_DIR)/GLFW/%.c
	@echo "Compiling C (GLFW): $<"
	@$(call MKDIR,$(dir $@))
	@$(CC) $(GLFW_CFLAGS) -c $< -o $@

# Compile other C files (with full warnings)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling C: $<"
	@$(call MKDIR,$(dir $@))
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	@$(call MKDIR,$(BUILD_DIR))

clean:
	@echo "Cleaning Core..."
ifeq ($(OS),Windows_NT)
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(subst /,\,$(TARGET)) del /q $(subst /,\,$(TARGET))
else
	@rm -rf $(OBJ_DIR)
	@rm -f $(TARGET)
endif