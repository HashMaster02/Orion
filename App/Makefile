# App/Makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -I../Core/include
LDFLAGS = -L../build -lcore

# Platform-specific GLFW dependencies
# For Linux:
LDFLAGS += -lm -ldl -lpthread -lX11 -lXrandr -lXi -lXxf86vm -lXcursor -lXinerama

# For Windows (uncomment if on Windows):
# LDFLAGS += -lgdi32 -lopengl32

# For macOS (uncomment if on macOS):
# LDFLAGS += -framework Cocoa -framework IOKit -framework CoreVideo

# Directories
SRC_DIR = src
BUILD_DIR = ../build

# Files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
TARGET = $(BUILD_DIR)/app

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS) | $(BUILD_DIR)
	@echo "Building application: $@"
	@$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

clean:
	@echo "Cleaning App..."
	@rm -f $(TARGET)