CXX ?= g++
CXXFLAGS ?= -O2
LDLIBS ?= -lglfw -lGL
LDFLAGS ?=

BACKEND := OPENGL

_CXXFLAGS := -DICOPTR_$(BACKEND) --std=c++17 -Wall -Wextra $(CXXFLAGS)

SRC_DIR := ./src

.PHONY: all clean run

TARGET := ./icoptr-gui.out

SRCS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/imgui/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(SRC_DIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(_CXXFLAGS) -c $< -o $@


clean:
	rm $(OBJS)

run: $(TARGET)
	@ ./$(TARGET) $(RUNFLAGS) 
