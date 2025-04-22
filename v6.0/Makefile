CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -DPROGRAM_VERSION=\"$(VERSION_NAME)\"
VERSION_NAME := $(notdir $(CURDIR))

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -DPROGRAM_VERSION=\"$(VERSION_NAME)\"
TARGET = bin/$(VERSION_NAME)_programa

ifeq ($(OS),Windows_NT)
    SRCS = $(shell powershell -Command "Get-ChildItem -Path src -Recurse -Filter *.cpp | ForEach-Object { $$_.FullName }")
else
    SRCS = $(shell find src -name '*.cpp')
endif
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
