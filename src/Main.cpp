/*
 * Main.cpp
 *
 *  Created on: 26 Dec 2018
 *      Author: Johnny
 */
#include "CleaningRobot.hpp"
#include "../src-gen/Robot_statechart.h"

void test () {

  CleaningRobot cleaningRobot;

  cleaningRobot.driveBackwards("200");
  cleaningRobot.driveForwards("100");
  cleaningRobot.rotate(RotateDirection::CCW);
  cleaningRobot.stop();
  cleaningRobot.rotate(RotateDirection::CW);
}

int main(void) {

  ControlUnit* ctrlUnit = new ControlUnit();
  Robot_statechart robotFSM;

  // Initialize the state machine:
  robotFSM.init();

  // Enter the state machine and implicitly activate its "Stopped" state:
  robotFSM.enter();

  ctrlUnit->setCommand(Command::Forwards);
  robotFSM.getSCI_Ctrl()->set_controlUnit(*ctrlUnit);
  robotFSM.runCycle();


  return 0;
}



