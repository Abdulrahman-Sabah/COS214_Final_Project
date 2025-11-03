
#ifndef GROWING_STATE_CMD_H
#define GROWING_STATE_CMD_H

/**
 * @file GrowingStateCmd.h
 * @brief It defines the GrowingStateCmd class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include "Commands.h"
#include <string>

/**
 * @class GrowingStateCmd
 * @brief Sets a plant to GrowingState.
 * @details Inherits from Commands and implements the execute method to change
 * a plant's lifecycle state to GrowingState.
 */
class GrowingStateCmd : public Commands {
public:
  /**
   * @brief Default Constructor
   */
  GrowingStateCmd();
  /**
   * @brief Default Destructor
   */
  ~GrowingStateCmd() override = default;

  /**
   * @brief Get command name\
   * @return Command name
   */
  std::string name() override;

  /**
   * @brief Change plant to GrowingState
   * @param plant Target plant
   */
  void execute(Plant *plant) override;

private:
  /** @brief Command label */
  std::string m_label;
};

#endif // GROWING_STATE_CMD_H
