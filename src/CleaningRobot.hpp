/*
 * CleaningRobot.h
 *
 *  Created on: 26 Dec 2018
 *      Author: Johnny
 */

#ifndef SRC_CLEANINGROBOT_HPP_
#define SRC_CLEANINGROBOT_HPP_

#include "IRotatable.h"
#include "Vehicle.h"

class CleaningRobot: virtual public IRotatable, virtual public IDrivable {
public:
  void driveForwards(const char* const speed) override;
  void driveBackwards(const char* const speed) override;
  void stop() override;
  void rotate(const RotateDirection direction) override;
};

#endif /* SRC_CLEANINGROBOT_HPP_ */
