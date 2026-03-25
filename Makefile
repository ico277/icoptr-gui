CXX ?= g++
CXXFLAGS ?= -O2
LDLIBS ?= -limgui
LDFLAGS ?=

_CXXFLAGS := --std=c++17 -Wall -Wextra $(CXXFLAGS)

SRC_DIR := src
BUILD_DIR := build

.PHONY: all clean run

TARGET := $(BUILD_DIR)/meowinfo

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(_CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

run: $(TARGET)
	$(TARGET) $(RUNFLAGS) 
