CXX ?= g++
CXXFLAGS ?= -std=c++11 -Wall -Wextra -g
LDFLAGS ?= -lws2_32

ifdef COVERAGE
    CXXFLAGS += -O0 --coverage
    LDFLAGS  += --coverage
endif

# Get all source files except DemoMain.cpp and main.cpp
SRCS := $(filter-out DemoMain.cpp main.cpp,$(wildcard *.cpp))
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

# Common objects (all except TestingMain and server-specific files)
COMMON_OBJS := $(filter-out TestingMain.o server.o,$(OBJS))

# Server-specific objects
SERVER_OBJS := server.o InventorySerializer.o $(COMMON_OBJS)

# TestingMain-specific objects
TESTING_OBJS := TestingMain.o InventorySerializer.o $(COMMON_OBJS)

.PHONY: all TestingMain server run demo-run run-server clean clean-coverage coverage

# Default target - build TestingMain
all: TestingMain

# Testing executable - FIXED: Use TESTING_OBJS instead of undefined COMMON_OBJS
TestingMain: $(TESTING_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

# Server executable
server: $(SERVER_OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) -lws2_32
	@echo 🌿 Plant Nursery Server built successfully!
	@echo Run with: ./server then open http://localhost:8081

# Server object file
server.o: server.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# InventoryManager object file
InventoryManager.o: InventoryManager.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Compile other .cpp files to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Run automated tests
run: TestingMain
	@echo Running automated tests (TestingMain)...
	./TestingMain

# Run the server
run-server: server
	@echo Starting Plant Nursery Server...
	@echo 🌿 GUI available at: http://localhost:8081
	@echo Press Ctrl+C to stop the server
	./server

# Demo target
demo-run: 
	@echo Use 'make run-server' for the GUI demo

# Clean everything - WINDOWS VERSION
clean:
	-del /Q *.o 2>nul
	-del /Q *.exe 2>nul
	-del /Q TestingMain 2>nul
	-del /Q server 2>nul
	@echo Cleaned all build files and executables

# Coverage targets - simplified for Windows
clean-coverage:
	-del /Q *.gcno 2>nul
	-del /Q *.gcda 2>nul
	-del /Q *.gcov 2>nul
	-del /Q coverage.info 2>nul
	-rmdir /Q /S coverage-report 2>nul
	@echo Cleaned coverage artifacts

coverage: clean clean-coverage
	$(MAKE) COVERAGE=1 TestingMain
	./TestingMain
	gcov -b -c $(SRCS)