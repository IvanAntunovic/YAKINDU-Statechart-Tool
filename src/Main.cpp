/*
 * Main.cpp
 *
 *  Created on: 26 Dec 2018
 *      Author: Johnny
 */

#include <conio.h>

#include "CleaningRobot.hpp"
#include "../src-gen/Robot_statechart.h"

#define SPACE 32

void test () {

  CleaningRobot cleaningRobot;

  cleaningRobot.driveBackwards("200");
  cleaningRobot.driveForwards("100");
  cleaningRobot.rotate(RotateDirection::CCW);
  cleaningRobot.stop();
  cleaningRobot.rotate(RotateDirection::CW);
}

void cleaningRobotFSM() {

  Robot_statechart robotFSM;

  ControlUnit* ctrlUnit = new ControlUnit();
  robotFSM.getSCI_Ctrl()->set_ctrlUnit(ctrlUnit);

  // Initialize the state machine:
  robotFSM.init();

  // Enter the state machine and implicitly activate its "Stopped" state:
  robotFSM.enter();

  ctrlUnit->setCommand(Command::Rotate);
  robotFSM.runCycle();

  ctrlUnit->setCommand(Command::Forwards);
  robotFSM.runCycle();

  ctrlUnit->setCommand(Command::Backwards);
  robotFSM.runCycle();

  ctrlUnit->setCommand(Command::Forwards);
  robotFSM.runCycle();

  ctrlUnit->setCommand(Command::Rotate);
  robotFSM.runCycle();
  robotFSM.runCycle();
}

void readInput() {

	Robot_statechart robotFSM;

    ControlUnit* ctrlUnit = new ControlUnit();
    robotFSM.getSCI_Ctrl()->set_ctrlUnit(ctrlUnit);

    // Initialize the state machine:
    robotFSM.init();

    // Enter the state machine and implicitly activate its "Stopped" state:
    robotFSM.enter();

    while (robotFSM.isActive()) {
      char input = getch();

      switch (input) {
        case 'W' || 'w':
		  ctrlUnit->setCommand(Command::Forwards);
		  robotFSM.runCycle();
		  break;
      }
    }

}

int main(void) {

  cout << "hey";
  return 0;
}



