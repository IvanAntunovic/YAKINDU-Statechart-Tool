/*
 * VehicleFactory.cpp
 *
 *  Created on: 26 Dec 2018
 *      Author: Johnny
 */

#include "VehicleFactory.hpp"
#include "CleaningRobot.hpp"

#include <stdio.h>

Vehicle* VehicleFactory::create(VehicleType vehicleType) {
  switch (vehicleType) {
    case VehicleType::CleaningRobot:
      //return new CleaningRobot;
      break;
    default:
      return NULL;
  }
  return NULL;
}

