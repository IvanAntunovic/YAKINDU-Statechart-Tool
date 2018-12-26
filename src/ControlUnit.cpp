/*
 * ControlUnit.cpp
 *
 *  Created on: 26 Dec 2018
 *      Author: Johnny
 */

#include "ControlUnit.hpp"

Command ControlUnit::getCommand() const {
	return mCommand;
}

void ControlUnit::setCommand(Command command) {
	mCommand = command;
}

Command ControlUnit::getRotationDir() const {
	return mRotationDir;
}

void ControlUnit::setRotationDir(Command rotationDir) {
	mRotationDir = rotationDir;
}
