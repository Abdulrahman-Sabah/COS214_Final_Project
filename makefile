# Cross-platform Makefile with TestingMain, unit-tests, and server
CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -g -Isrc -IincludeFiles
LDFLAGS ?=

ifdef COVERAGE
CXXFLAGS += -O0 --coverage 
LDFLAGS  += --coverage
endif

# Detect OS and set commands
ifeq ($(OS),Windows_NT)
    LDFLAGS ?= -lws2_32
    RM = del /Q
    SERVER_EXE = greenhouse_server.exe
    TEST_EXE = TestingMain.exe
    UNIT_EXE = unit-tests.exe
else
    LDFLAGS ?=
    RM = rm -f
    SERVER_EXE = greenhouse_server
    TEST_EXE = TestingMain
    UNIT_EXE = unit-tests
endif

# SRCS := $(wildcard src/*.cpp)
# OBJS := $(patsubst src/%.cpp,src/%.o,$(SRCS))
# COMMON_OBJS := $(filter-out src/TestingMain.o src/server.o,$(OBJS))

SRCS := $(wildcard src/*.cpp)
OBJS := $(patsubst src/%.cpp,src/%.o,$(SRCS))
COMMON_OBJS := $(filter-out src/TestingMain.o src/DemoMain.o src/server.o,$(OBJS))


TEST_SRCS := $(wildcard testFile/*.cpp)
TEST_OBJS := $(patsubst testFile/%.cpp,testFile/%.o,$(TEST_SRCS))

.PHONY: all server test format clean clean-coverage run run-tests run-server valgrind valgrind-tests coverage

all: format $(SERVER_EXE) $(TEST_EXE) $(UNIT_EXE)

# Server executable
server: $(SERVER_EXE)

$(SERVER_EXE): src/server.o $(COMMON_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

# TestingMain executable
$(TEST_EXE): src/TestingMain.o $(COMMON_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

# Unit tests
$(UNIT_EXE): $(TEST_OBJS) $(COMMON_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

# Compile objects
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

testFile/%.o: testFile/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Run targets
run-server: $(SERVER_EXE)
	@echo "Launching greenhouse server..."
	./$(SERVER_EXE)

run: $(TEST_EXE)
	@echo "Running TestingMain..."
	./$(TEST_EXE)

run-tests: $(UNIT_EXE)
	@echo "Running all doctest unit-tests..."
	./$(UNIT_EXE)

run-demo: src/DemoMain.o $(COMMON_OBJS)
	@echo "Running DemoMain..."
	$(CXX) $(CXXFLAGS) -o DemoMain src/DemoMain.o $(COMMON_OBJS)
	./DemoMain


# Valgrind checks
valgrind: $(TEST_EXE)
	@echo "Running Valgrind on TestingMain..."
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_EXE)

valgrind-tests: $(UNIT_EXE)
	@echo "Running Valgrind on unit-tests..."
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(UNIT_EXE)

# Code coverage
coverage: clean clean-coverage
	$(MAKE) COVERAGE=1 $(TEST_EXE)
	./$(TEST_EXE)
	gcov -b -c $(SRCS)

# Format all code
format:
	@echo "Formatting all C++ source and header files..."
	@git ls-files '*.cpp' '*.h' | xargs clang-format -i
	@echo "Code formatted successfully."

# Clean targets
clean:
	$(RM) $(OBJS) $(TEST_OBJS) $(SERVER_EXE) $(TEST_EXE) $(UNIT_EXE)
	@echo "Cleaned object files and executables."

clean-coverage:
ifeq ($(OS),Windows_NT)
	$(RM) src\*.gcno src\*.gcda src\*.gcov
	$(RM) testFile\*.gcno testFile\*.gcda testFile\*.gcov
	$(RM) *.gcno *.gcda *.gcov coverage.info
else
	find . -type f \( -name "*.gcno" -o -name "*.gcda" -o -name "*.gcov" \) -delete
	$(RM) coverage.info
endif
	@echo "Cleaned coverage files."
