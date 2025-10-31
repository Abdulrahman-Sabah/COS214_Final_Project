# Cross-platform Makefile for separate executables
CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -g -Isrc -IincludeFiles

# Detect OS and set appropriate commands
ifeq ($(OS),Windows_NT)
    # Windows settings
    LDFLAGS ?= -lws2_32
    SERVER_LDFLAGS ?= -lws2_32
    RM = del /Q
    SERVER_EXE = greenhouse_server.exe
    TEST_EXE = TestingMain.exe
else
    # Linux/Unix settings
    LDFLAGS ?=
    SERVER_LDFLAGS ?=
    RM = rm -f
    SERVER_EXE = greenhouse_server
    TEST_EXE = TestingMain
endif

# Source files
ALL_SRCS = $(wildcard src/*.cpp)
SERVER_OBJS = $(filter-out src/TestingMain.o, $(ALL_SRCS:src/%.cpp=src/%.o))
TEST_OBJS = $(filter-out src/server.o, $(ALL_SRCS:src/%.cpp=src/%.o))

.PHONY: all server test clean run-server run-test format

# Default target
all: server test

# Server executable
server: $(SERVER_EXE)

$(SERVER_EXE): $(SERVER_OBJS)
	$(CXX) -o $@ $^ $(SERVER_LDFLAGS)

# Test executable
test: $(TEST_EXE)

$(TEST_EXE): $(TEST_OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Object files
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Run targets
run-server: $(SERVER_EXE)
	./$(SERVER_EXE)

run-test: $(TEST_EXE)
	./$(TEST_EXE)

# Format source code using clang-format
format:
	@echo "Formatting C++ source files..."
	@find . -name "*.cpp" -o -name "*.h" | grep -v "./html" | grep -v "./latex" | xargs clang-format -i -style=Google
	@echo "Formatting complete"

# Cross-platform clean
clean:
ifeq ($(OS),Windows_NT)
	@if exist src\*.o $(RM) src\*.o 2>nul
	@if exist $(SERVER_EXE) $(RM) $(SERVER_EXE) 2>nul
	@if exist $(TEST_EXE) $(RM) $(TEST_EXE) 2>nul
else
	$(RM) src/*.o $(SERVER_EXE) $(TEST_EXE)
endif
	@echo Clean complete