CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -DPROGRAM_VERSION=\"$(VERSION_NAME)\"
VERSION_NAME := $(notdir $(CURDIR))

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -DPROGRAM_VERSION=\"$(VERSION_NAME)\"
TARGET = bin/$(VERSION_NAME)_programa

SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:src/%.cpp=obj/%.o)


all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p bin $(@D)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS): obj/%.o: src/%.cpp
	@echo "Compilando $<"
	@mkdir -p obj $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	@if [ ! -f "$(TARGET)" ]; then \
		echo "Executável não encontrado, compilando..."; \
		$(MAKE) $(TARGET); \
	fi
	@./$(TARGET)

clean:
	@rm -rf obj bin
	@echo "Arquivos .o deletados."

.PHONY: all run clean
