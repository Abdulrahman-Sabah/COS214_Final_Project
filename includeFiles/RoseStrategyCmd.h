#ifndef ROSE_STRATEGY_CMD_H
#define ROSE_STRATEGY_CMD_H

/**
 * @file RoseStrategyCmd.h
 * @brief Command to set plant care to RoseCare.
 */

#include <string>
#include "Commands.h"

/**
 * @class RoseStrategyCmd
 * @brief Applies RoseCare strategy to a plant.
 */
class RoseStrategyCmd : public Commands {
public:
    RoseStrategyCmd();
    ~RoseStrategyCmd() override = default;

    /// @return Command name
    std::string name() override;

    /**
     * @brief Set rose care
     * @param plant Target plant
     */
    void execute(Plant* plant) override;

private:
    std::string m_label;
};

#endif // ROSE_STRATEGY_CMD_H
