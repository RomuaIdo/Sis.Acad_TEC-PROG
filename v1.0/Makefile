CC = gcc
CFLAGS = -Wall -Wextra -std=c11

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = bin/v1.0

SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:src/%.cpp=obj/%.o)


all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p bin $(@D)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS): obj/%.o: src/%.cpp
	@mkdir -p obj $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf obj bin
	@echo "Arquivos .o deletados."

.PHONY: all clean
