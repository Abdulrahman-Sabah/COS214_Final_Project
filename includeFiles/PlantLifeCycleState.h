#ifndef PLANTLIFECYCLESTATE_H
#define PLANTLIFECYCLESTATE_H

/**
 * @file PlantLifeCycleState.h
 * @brief Abstract lifecycle state interface.
 * @author Git it done group members
 * @date 10-2025
 */

#include <iostream>
#include <string>
#include <vector>
#include "Plant.h"

/**
 * @class PlantLifeCycleState
 * @brief Abstract base class for plant lifecycle states.
 */
class PlantLifeCycleState {
protected:
    /** @brief Dead flag */
    bool dead;
    /** @brief Attention flag */
    bool attention;

public:
    /**
     * @brief Constructor
     */
    PlantLifeCycleState();
    /** 
     * @brief Destructor
     */
    virtual ~PlantLifeCycleState() = default;

    /**
     * @brief Move to next state
     * @param plant Target plant
     */
    virtual void advance(Plant* plant) = 0;

    /**
     * @brief Get the state name
     * @return State name
     */
    virtual std::string name() = 0;

    /**
     * @brief Get dead flag
     *  @return True if state is dead, false otherwise
     */ 
    bool getDead();

    /**
     * @brief Get attention flag
     * @return True if needs care
     */
    bool getAttention();

    /**
     * @brief Set dead flag
     * @param d Value to set
     * @return New value
     */
    bool setDead(bool d);

    /**
     * @brief Set attention flag
     * @param a Value to set
     * @return New value
     */
    bool setAttention(bool a);

    /**
     * @brief Check if plant is dead    
     * @return True if dead (override in subclass)
     */
    virtual bool isDead() = 0;

    /**
     * @brief Check if plant needs attention
     * @return True if needs attention (override)
     */
    virtual bool needsAttention() = 0;
};

#endif
