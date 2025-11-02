/**
 * @file PlantIterator.h
 * @brief Abstract iterator interface for the Iterator pattern implementation
 * @author COS214 Students
 * @date 2024
 */

#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

#include "Plant.h"

/**
 * @class PlantIterator
 * @brief Abstract iterator class for traversing collections of Plant objects
 * 
 * This class defines the interface for the Iterator pattern, providing a way
 * to sequentially access elements of a plant collection without exposing
 * the underlying representation.
 */
class PlantIterator {
public:
    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~PlantIterator() {}

    /**
     * @brief Resets the iterator to the first element
     */
    virtual void first() = 0;
    
    /**
     * @brief Moves the iterator to the next element
     */
    virtual void next() = 0;
    
    /**
     * @brief Checks if the iterator has reached the end
     * @return True if no more elements, false otherwise
     */
    virtual bool isDone() = 0;
    
    /**
     * @brief Gets the current plant element
     * @return Pointer to the current Plant object
     */
    virtual Plant* current() = 0;
};

#endif
