#ifndef MATURE_STATE_CMD_H
#define MATURE_STATE_CMD_H

/**
 * @file MatureStateCmd.h
 * @brief Command to set a plant to MatureState.
 */

#include <string>
#include "Commands.h"

/**
 * @class MatureStateCmd
 * @brief Applies MatureState to a plant.
 */
class MatureStateCmd : public Commands {
public:
    MatureStateCmd();
    ~MatureStateCmd() override = default;

    /// @return Command name
    std::string name() override;

    /**
     * @brief Set mature state
     * @param plant Target plant
     */
    void execute(Plant* plant) override;

private:
    std::string m_label;
};

#endif // MATURE_STATE_CMD_H
