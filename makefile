CXX ?= g++
CXXFLAGS ?= -std=c++11 -Wall -Wextra -g
LDFLAGS ?=

ifdef COVERAGE
CXXFLAGS += -O0 --coverage
LDFLAGS  += --coverage
endif

SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

COMMON_OBJS := $(filter-out DemoMain.o TestingMain.o,$(OBJS))

.PHONY: all DemoMain TestingMain run demo-run clean valgrind clean-coverage coverage state-tests

all: DemoMain TestingMain

DemoMain: DemoMain.o $(COMMON_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

TestingMain: TestingMain.o $(COMMON_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run: TestingMain
	@echo "Running automated tests (TestingMain)..."
	./TestingMain

demo-run: DemoMain
	@echo "Launching interactive demo (DemoMain)..."
	./DemoMain

clean:
	rm -f $(OBJS) DemoMain TestingMain
	@echo "Cleaned object files and executables."

valgrind: TestingMain
	@echo "Running Valgrind on TestingMain..."
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./TestingMain

clean-coverage:
	rm -f *.gcno *.gcda *.gcov coverage.info
	rm -rf coverage-report
	@echo "Cleaned coverage artifacts."

coverage: clean clean-coverage
	$(MAKE) COVERAGE=1 TestingMain
	./TestingMain
	gcov -b -c $(SRCS)


