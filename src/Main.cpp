/*
 * Main.cpp
 *
 *  Created on: 26 Dec 2018
 *      Author: Johnny
 */
#include "CleaningRobot.hpp"

int main(void) {

  CleaningRobot cleaningRobot;

  cleaningRobot.driveBackwards("200");
  cleaningRobot.driveForwards("100");
  cleaningRobot.rotate(RotateDirection::CCW);
  cleaningRobot.stop();
  cleaningRobot.rotate(RotateDirection::CW);

  return 0;
}



