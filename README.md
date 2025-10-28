do# COS214 Final Project - Greenhouse Management System

## Overview
This project implements a comprehensive greenhouse management system using multiple design patterns. The system manages plant inventory, care scheduling, delivery processes, and sales operations through a well-architected object-oriented design.

## Design Patterns Implemented

### 1. Chain of Responsibility Pattern
- **Classes**: `Handler`, `DeliveryStaff`, `GreenhouseManager`, `Landscaper`
- **Purpose**: Handles different types of requests (delivery scheduling, plant care, sales operations) by passing them through a chain of handlers

### 2. Command Pattern
- **Classes**: `Commands`, `ScheduleDelivery`, `MoveToSales`, `AddWater`, `ApplyFertilizer`
- **Purpose**: Encapsulates requests as objects, allowing for parameterization and queuing of operations

### 3. Strategy Pattern
- **Classes**: `CareStrategy`, `RoseCare`, `CactusCare`, `LavenderCare`
- **Purpose**: Defines different care strategies for different plant types

### 4. State Pattern
- **Classes**: `PlantLifeCycleState`, `SeedlingState`, `GrowingState`, `MatureState`, `DormantState`, `DeadState`
- **Purpose**: Manages plant lifecycle transitions and state-dependent behavior

### 5. Factory Method Pattern
- **Classes**: `Creator`, `RoseCreator`, `CactusCreator`, `LavenderCreator`
- **Purpose**: Creates plant objects without specifying their exact classes

### 6. Builder Pattern
- **Classes**: `PlantBuilder`, `RoseBuilder`, `CactusBuilder`, `LavenderBuilder`
- **Purpose**: Constructs complex plant objects step by step

### 7. Decorator Pattern
- **Classes**: `PlantDecorations`, `PotDecorator`, `CardDecorator`, `WrapDecorator`
- **Purpose**: Adds additional features/decorations to plants dynamically

### 8. Observer Pattern
- **Classes**: `PlantObserver`, `CareSchedulerObserver`
- **Purpose**: Notifies observers when plant states change

## Key Features
- Plant inventory management
- Automated care scheduling based on plant types
- Delivery and sales process handling
- State-aware plant lifecycle management
- Extensible decorator system for plant accessories

## Building and Running
```bash
# Compile the project
clang++ -o greenhouse main.cpp Handler.cpp DeliveryStaff.cpp GreenhouseManager.cpp Landscaper.cpp ScheduleDelivery.cpp MoveToSales.cpp AddWater.cpp ApplyFertilizer.cpp Commands.cpp

# Run the application
./greenhouse
```

## Documentation
This documentation was generated using Doxygen. The system demonstrates advanced object-oriented design principles and design pattern implementation in C++.