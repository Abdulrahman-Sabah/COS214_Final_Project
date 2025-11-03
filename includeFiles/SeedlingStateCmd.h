#ifndef SEEDLING_STATE_CMD_H
#define SEEDLING_STATE_CMD_H

/**
 * @file SeedlingStateCmd.h
 * @brief Command to set a plant to SeedlingState.
 * @author Git it done group members
 * @date 10-2025
 */

#include <string>
#include "Commands.h"

/**
 * @class SeedlingStateCmd
 * @brief Applies SeedlingState to a plant.
 */
class SeedlingStateCmd : public Commands {
public:
    /** @brief Constructor */
    SeedlingStateCmd();
    /** @brief Destructor */
    ~SeedlingStateCmd() override = default;

    /**
     * @brief Get the command name
     * @return Command name
     */
    std::string name() override;

    /**
     * @brief Set seedling state
     * @param plant Target plant
     */
    void execute(Plant* plant) override;

private:
    /** @brief Label for the command */
    std::string m_label;
};

#endif // SEEDLING_STATE_CMD_H
