/*
 * VehicleFactory.hpp
 *
 *  Created on: 26 Dec 2018
 *      Author: Johnny
 */

#ifndef SRC_VEHICLEFACTORY_HPP_
#define SRC_VEHICLEFACTORY_HPP_

#include "Vehicle.h"

typedef enum {CleaningRobot} VehicleType;

class VehicleFactory {
public:
  Vehicle* create(VehicleType);
};

#endif /* SRC_VEHICLEFACTORY_HPP_ */
