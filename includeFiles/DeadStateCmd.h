
#ifndef DEAD_STATE_CMD_H
#define DEAD_STATE_CMD_H

/**
 * @file DeadStateCmd.h
 * @brief It defines the DeadStateCmd class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include <string>
#include "Commands.h"

/**
 * @class DeadStateCmd
 * @brief Applies DeadState to a plant.
 * @details Inherits from Commands and changes a plant's lifecycle state to DeadState when executed.
 */
class DeadStateCmd : public Commands {
public:
    /**
     * @brief Default constructor
     */
    DeadStateCmd();
    /**
     * @brief Default destructor
     */
    ~DeadStateCmd() override = default;

    /**
     * @brief Get the command name
     * @return Command name
     */
    std::string name() override;

    /**
     * @brief Change plant to DeadState
     * @param plant Target plant
     */
    void execute(Plant* plant) override;

private:
    /**
    * @brief Command label
    */
    std::string m_label;
};

#endif // DEAD_STATE_CMD_H
