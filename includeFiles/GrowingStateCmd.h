/**
 * @file GrowingStateCmd.h
 * @brief Command to apply GrowingState to a plant.
 */

#ifndef GROWING_STATE_CMD_H
#define GROWING_STATE_CMD_H

#include <string>
#include "Commands.h"

/**
 * @class GrowingStateCmd
 * @brief Sets a plant to GrowingState.
 */
class GrowingStateCmd : public Commands {
public:
    GrowingStateCmd();
    ~GrowingStateCmd() override = default;

    /// @return Command name
    std::string name() override;

    /**
     * @brief Change plant to GrowingState
     * @param plant Target plant
     */
    void execute(Plant* plant) override;

private:
    std::string m_label;
};

#endif // GROWING_STATE_CMD_H
