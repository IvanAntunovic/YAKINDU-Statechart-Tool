/*
 * Vehicle.h
 *
 *  Created on: 26 Dec 2018
 *      Author: Johnny
 */

#ifndef SRC_VEHICLE_H_
#define SRC_VEHICLE_H_

#include "IDrivable.hpp"

class Vehicle: public virtual IDrivable {
  virtual void driveForwards(const char* const speed);
  virtual void driveBackwards(const char* const speed);
  virtual void stop();
};

#endif /* SRC_VEHICLE_H_ */
