#ifndef PLANTLIFECYCLESTATE_H
#define PLANTLIFECYCLESTATE_H

/**
 * @file PlantLifeCycleState.h
 * @brief Abstract lifecycle state interface.
 */

#include <iostream>
#include <string>
#include <vector>
#include "Plant.h"

class PlantLifeCycleState {
protected:
    bool dead;
    bool attention;

public:
    PlantLifeCycleState();
    virtual ~PlantLifeCycleState() = default;

    /**
     * @brief Move to next state
     * @param plant Target plant
     */
    virtual void advance(Plant* plant) = 0;

    /// @return State name
    virtual std::string name() = 0;

    /// @return True if state is dead
    bool getDead();

    /// @return True if needs care
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

    /// @return True if dead (override in subclass)
    virtual bool isDead() = 0;

    /// @return True if needs attention (override)
    virtual bool needsAttention() = 0;
};

#endif
