/**
 * @file DormantStateCmd.h
 * @brief Command to put a plant in DormantState.
 */

#ifndef DORMANTSTATECMD_H
#define DORMANTSTATECMD_H

#include <string>
#include "Commands.h"

/**
 * @class DormantStateCmd
 * @brief Applies DormantState to a plant.
 */
class DormantStateCmd : public Commands {
public:
    DormantStateCmd();
    ~DormantStateCmd() override = default;

    /// @return Command name
    std::string name() override;

    /**
     * @brief Change plant to DormantState
     * @param plant Target plant
     */
    void execute(Plant* plant) override;

private:
    std::string m_label;
};

#endif // DORMANTSTATECMD_H
