#ifndef SEEDLING_STATE_CMD_H
#define SEEDLING_STATE_CMD_H

/**
 * @file SeedlingStateCmd.h
 * @brief Command to set a plant to SeedlingState.
 */

#include <string>
#include "Commands.h"

/**
 * @class SeedlingStateCmd
 * @brief Applies SeedlingState to a plant.
 */
class SeedlingStateCmd : public Commands {
public:
    SeedlingStateCmd();
    ~SeedlingStateCmd() override = default;

    /// @return Command name
    std::string name() override;

    /**
     * @brief Set seedling state
     * @param plant Target plant
     */
    void execute(Plant* plant) override;

private:
    std::string m_label;
};

#endif // SEEDLING_STATE_CMD_H
