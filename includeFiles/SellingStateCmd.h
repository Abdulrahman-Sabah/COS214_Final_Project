#ifndef SELLING_STATE_CMD_H
#define SELLING_STATE_CMD_H

/**
 * @file SellingStateCmd.h
 * @brief Command to set a plant to SellingState.
 */

#include <string>
#include "Commands.h"

/**
 * @class SellingStateCmd
 * @brief Applies SellingState to a plant.
 */
class SellingStateCmd : public Commands {
public:
    SellingStateCmd();
    ~SellingStateCmd() override = default;

    /// @return Command name
    std::string name() override;

    /**
     * @brief Set selling state
     * @param plant Target plant
     */
    void execute(Plant* plant) override;

private:
    std::string m_label;
};

#endif // SELLING_STATE_CMD_H
