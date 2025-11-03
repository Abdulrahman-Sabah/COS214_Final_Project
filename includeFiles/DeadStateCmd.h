/**
 * @file DeadStateCmd.h
 * @brief Command to set a plant to DeadState.
 */

#ifndef DEAD_STATE_CMD_H
#define DEAD_STATE_CMD_H

#include <string>
#include "Commands.h"

/**
 * @class DeadStateCmd
 * @brief Applies DeadState to a plant.
 */
class DeadStateCmd : public Commands {
public:
    DeadStateCmd();
    ~DeadStateCmd() override = default;

    /// @return Command name
    std::string name() override;

    /**
     * @brief Change plant to DeadState
     * @param plant Target plant
     */
    void execute(Plant* plant) override;

private:
    std::string m_label;
};

#endif // DEAD_STATE_CMD_H
