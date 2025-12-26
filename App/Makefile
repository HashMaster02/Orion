# App/Makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -I../Core/include
LDFLAGS = -L../build -lcore

# Platform-specific GLFW dependencies
ifeq ($(OS),Windows_NT)
    # Windows
    LDFLAGS += -lgdi32 -lopengl32 -static-libgcc -static-libstdc++ -static
    EXE_EXT = .exe
else
    # Linux/Unix
    LDFLAGS += -lm -ldl -lpthread -lX11 -lXrandr -lXi -lXxf86vm -lXcursor -lXinerama
    EXE_EXT =
endif

# Uncomment for macOS:
# ifeq ($(shell uname),Darwin)
#     LDFLAGS = -L../build -lcore -framework Cocoa -framework IOKit -framework CoreVideo
# endif

# Directories
SRC_DIR = src
BUILD_DIR = ../build

# Files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
TARGET = $(BUILD_DIR)/app$(EXE_EXT)

# Platform detection for mkdir
ifeq ($(OS),Windows_NT)
    MKDIR = if not exist $(subst /,\,$(1)) mkdir $(subst /,\,$(1))
else
    MKDIR = mkdir -p $(1)
endif

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS) | $(BUILD_DIR)
	@echo "Building application: $@"
	@$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR):
	@$(call MKDIR,$(BUILD_DIR))

clean:
	@echo "Cleaning App..."
	@rm -f $(TARGET)