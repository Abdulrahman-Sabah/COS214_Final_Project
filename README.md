# COS214 Final Project — Plant Nursery Simulation
## Team: *Git It Done*
### University of Pretoria
---
## Group Members:
| Name | Student Number |
|------|----------------|
| **Joshua Heath** | u23541475 |
| **Antony Van Straten** | u24590739 |
| **Avuyile Sapula** | u23540282 |
| **Hamdaan Mirz** | u24631494 |
| **Dylan Hebron** | u22503685 |
| **Abdelrahman Ahmed** | u24898008 |
| **Abdulrahman Sabah** | u24566170 |
---
## Design Patterns:
| Type | Patterns Implemented |
|------|----------------------|
| **Creational** | Factory Method, Prototype |
| **Structural** | Decorator, Adapter |
| **Behavioral** | Strategy, State, Observer, Command, Iterator, Chain of Responsibility, Mediator |
---
## Build Options:  
The following commands must be run from root of project folder:
```bash

Run the TestingMain program
make run
(This runs the TestingMain executable)

Run Valgrind on TestingMain
make valgrind
(Checks for memory leaks and errors)

Run code coverage for TestingMain
make coverage
(Generates coverage reports for all tests in TestingMain)

Run the Demo Main
make run-demo
(This runs the Demo executable)

Run the PLant Nursery System
make run-server
Visit http://localhost:8081
This runs the server executable and launches the web GUI

make clean
(Removes all object files, executables, and coverage data for a fresh rebuild)
