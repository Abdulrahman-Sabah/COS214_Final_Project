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
### Short description of project 
Our nursery project is made from various design patterns which models a greenhouse/nursery operations. It simulates how the staff interact with customers, the plant life cycle changes, care strategies, handling of operations such as taking care of plants or getting rid of them whent they die and helping customers and delivering the plants bought etc. It simualtes plant growth and life cycle changes using state desing pattern. It manages the inventory, which is the plants we have available, and when we buy or sell plants. It allows customers to interact with staff members and the staff members assist them in giving them what they need. It handles transactions when plants are bought. It demonstrates the usage of 11 design patterns to make the system work as a whole, correctly and efficiently.
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
