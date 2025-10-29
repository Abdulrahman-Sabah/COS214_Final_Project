CXX ?= g++
CXXFLAGS ?= -std=c++11 -Wall -Wextra -g -Isrc -IincludeFiles
LDFLAGS ?=

ifdef COVERAGE
CXXFLAGS += -O0 --coverage
LDFLAGS  += --coverage
endif

SRCS := $(wildcard src/*.cpp)
OBJS := $(patsubst src/%.cpp,src/%.o,$(SRCS))

COMMON_OBJS := $(filter-out src/TestingMain.o,$(OBJS))

TEST_SRCS := $(wildcard testFile/*.cpp)
TEST_OBJS := $(patsubst testFile/%.cpp,testFile/%.o,$(TEST_SRCS))

.PHONY: all  TestingMain unit-tests run demo-run run-tests clean valgrind clean-coverage coverage

all: TestingMain unit-tests

# DemoMain: src/DemoMain.o $(COMMON_OBJS)
# 	$(CXX) $(LDFLAGS) -o $@ $^

TestingMain: src/TestingMain.o $(COMMON_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

unit-tests: $(TEST_OBJS) $(COMMON_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

testFile/%.o: testFile/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run: TestingMain
	@echo "Running automated tests (TestingMain)..."
	./TestingMain

# demo-run: DemoMain
# 	@echo "Launching interactive demo (DemoMain)..."
# 	./DemoMain

run-tests: unit-tests
	@echo "Running all doctest unit-tests..."
	./unit-tests


valgrind: TestingMain
	@echo "Running Valgrind on TestingMain..."
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./TestingMain

valgrind-tests: unit-tests
	@echo "Running Valgrind on unit-tests..."
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./unit-tests

coverage: clean clean-coverage
	$(MAKE) COVERAGE=1 TestingMain
	./TestingMain
	gcov -b -c $(SRCS)

clean:
	rm -f $(OBJS) $(TEST_OBJS) TestingMain unit-tests
	@echo "Cleaned object files and executables."

clean-coverage:
	rm -f *.gcno *.gcda *.gcov coverage.info
	rm -rf coverage-report
	@echo "Cleaned coverage artifacts."
