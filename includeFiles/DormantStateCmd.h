
#ifndef DORMANTSTATECMD_H
#define DORMANTSTATECMD_H

/**
 * @file DormantStateCmd.h
 * @brief It defines the DormantStateCmd class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include <string>
#include "Commands.h"

/**
 * @class DormantStateCmd
 * @brief Applies DormantState to a plant.
 * @details Inherits from Commands and changes a plant's lifecycle state to DormantState when executed.
 */
class DormantStateCmd : public Commands {
public:
    /**
     * @brief Default constructor
     */
    DormantStateCmd();
    /**
     * @brief Default destructor
     */
    ~DormantStateCmd() override = default;

    /**
     * @brief Get the command name
     * @return Command name
     */
    std::string name() override;

    /**
     * @brief Change plant to DormantState
     * @param plant Target plant
     */
    void execute(Plant* plant) override;

private:
    /**
    * @brief Command label
    */
    std::string m_label;
};

#endif // DORMANTSTATECMD_H
