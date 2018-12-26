/*
 * CleaningRobot.cpp
 *
 *  Created on: 26 Dec 2018
 *      Author: Johnny
 */

#include "CleaningRobot.hpp"

#include <iostream>

using namespace std;

void static println(string str) {
  cout << str << endl;
}

void CleaningRobot::driveForwards(const char* const speed) {
  if ( speed == NULL || stoi(speed) < 0 || stoi(speed) > 255 ) {
    cout << "Invalid speed " << speed << endl;
    return;
  }

  println("Driving Forwards " + string(speed));
}

void CleaningRobot::driveBackwards(const char* const speed) {
  if ( speed == NULL || stoi(speed) < 0 || stoi(speed) > 255 ) {
	cout << "Invalid speed " << speed << endl;
    return;
  }

  println("Driving Backwards " + string(speed));
}

void CleaningRobot::stop() {
  println("Stopped");
}

void CleaningRobot::rotate(const RotateDirection direction) {
  switch(direction) {
    case RotateDirection::CCW:
      println("Rotating CCW");
      break;
    case RotateDirection::CW:
      println("Rotating CW");
      break;
    default:
      break;
  }
}
