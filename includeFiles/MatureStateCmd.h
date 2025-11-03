#ifndef MATURE_STATE_CMD_H
#define MATURE_STATE_CMD_H

/**
 * @file MatureStateCmd.h
 * @brief Command to set a plant to MatureState.
 * @author Git it done group members
 * @date 10-2025
 */

#include <string>
#include "Commands.h"

/**
 * @class MatureStateCmd
 * @brief Applies MatureState to a plant.
 * @details Inherits from Commands.
 */
class MatureStateCmd : public Commands {
public:
    /**
     * @brief Constructor
     */
    MatureStateCmd();
    /** 
     * @brief Destructor
     */
    ~MatureStateCmd() override = default;

    /**
     * @brief Get the command name
     * @return Command name
     */
    std::string name() override;

    /**
     * @brief Set mature state
     * @param plant Target plant
     */
    void execute(Plant* plant) override;

private:
    /** Command label */
    std::string m_label;
};

#endif // MATURE_STATE_CMD_H
