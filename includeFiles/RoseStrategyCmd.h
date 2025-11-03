#ifndef ROSE_STRATEGY_CMD_H
#define ROSE_STRATEGY_CMD_H

/**
 * @file RoseStrategyCmd.h
 * @brief Command to set plant care to RoseCare.
 * @author Git it done group members
 * @date 10-2025
 */

#include <string>
#include "Commands.h"

/**
 * @class RoseStrategyCmd
 * @brief Applies RoseCare strategy to a plant.
 */
class RoseStrategyCmd : public Commands {
public:
    /** @brief Constructor */
    RoseStrategyCmd();
    /** @brief Destructor */
    ~RoseStrategyCmd() override = default;

    /**
     * @brief Get the command name
     * @return Command name
     */
    std::string name() override;

    /**
     * @brief Set rose care
     * @param plant Target plant
     */
    void execute(Plant* plant) override;

private:
    /** @brief Label for the command */
    std::string m_label;
};

#endif // ROSE_STRATEGY_CMD_H
