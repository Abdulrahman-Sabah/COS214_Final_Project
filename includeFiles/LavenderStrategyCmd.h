#ifndef LAVENDER_STRATEGY_CMD_H
#define LAVENDER_STRATEGY_CMD_H

/**
 * @file LavenderStrategyCmd.h
 * @brief Command to set plant care to LavenderCare.
 */

#include <string>
#include "Commands.h"

/**
 * @class LavenderStrategyCmd
 * @brief Applies LavenderCare strategy to a plant.
 */
class LavenderStrategyCmd : public Commands {
public:
    LavenderStrategyCmd();
    ~LavenderStrategyCmd() override = default;

    /// @return Command name
    std::string name() override;

    /**
     * @brief Set lavender care
     * @param plant Target plant
     */
    void execute(Plant* plant) override;

private:
    std::string m_label;
};

#endif // LAVENDER_STRATEGY_CMD_H
