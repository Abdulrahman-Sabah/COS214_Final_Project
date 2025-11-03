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
| **Hamdaan Mirza** | u24631494 |
| **Dylan Hebron** | u22503685 |
| **Abdelrahman Ahmed** | u24898008 |
| **Abdulrahman Sabah** | u24566170 |
---
** Requirements **
1. Working in WSL
2. Have C++17 or higher
3. Have clang format installed.
4. Make sure you are in the correct folder i.e.COS214_Project/ , there should not be another COS214_Project within the first one
---
**Short Description**
---
Our nursery project is made from various design patterns which models a greenhouse/nursery operations. 
It simulates how the staff interact with customers, the plant life cycle changes, care strategies, handling of operations such as taking care of plants or getting rid of them whent they die and helping customers and delivering the plants bought etc. 
It simualtes plant growth and life cycle changes using state desing pattern. It manages the inventory, which is the plants we have available, and when we buy or sell plants. 
It allows customers to interact with staff members and the staff members assist them in giving them what they need. It handles transactions when plants are bought. It demonstrates the usage of 11 design patterns to make the system work as a whole, correctly and efficiently.

##  Link to the report in Google Docs:  
https://docs.google.com/document/d/1vor777XFPyVh4oTEEA_yd9F96e1kfakO/edit

##  Build Options:  
The following commands must be run from root of project folder:
```bash

Build all the files
make all

Run the TestingMain program(This runs the TestingMain executable)
make run

Run Valgrind on TestingMain(Checks for memory leaks and errors)
make valgrind

Run code coverage for TestingMain(Generates coverage reports for all tests in TestingMain)
make coverage

Run clean coverage to clean gcna files
make clean-coverage 

Run the Demo Main (This runs the Demo executable)
make run-demo

Run Unit Tests (This runs the unit-tests)
make run-tests

(Check Memory leaks in Unit_Tests)
make valgrind-tests

Visit http://localhost:8081 (This runs the server executable and launches the web GUI)
make run-server 

(Removes all object files, executables, and coverage data for a fresh rebuild)
make clean


