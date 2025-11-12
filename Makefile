# Root Makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
AR = ar
ARFLAGS = rcs

# Directories
BUILD_DIR = build
CORE_DIR = Core
APP_DIR = App

# Output
CORE_LIB = $(BUILD_DIR)/libcore.a
APP_EXEC = $(BUILD_DIR)/app

.PHONY: all clean core app

all: core app

core:
	@echo "Building Core library..."
	@$(MAKE) -C $(CORE_DIR)

app: core
	@echo "Building App..."
	@$(MAKE) -C $(APP_DIR)

clean:
	@echo "Cleaning..."
	@$(MAKE) -C $(CORE_DIR) clean
	@$(MAKE) -C $(APP_DIR) clean
	@rm -rf $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
