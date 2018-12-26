/*
 * ControlUnit.h
 *
 *  Created on: 26 Dec 2018
 *      Author: Johnny
 */

#ifndef SRC_CONTROLUNIT_HPP_
#define SRC_CONTROLUNIT_HPP_

typedef enum {Forwards,Backwards,Rotate,Stop, RotateCCW, RotateCW} Command;

class ControlUnit {
public:
  Command getCommand() const;
  void setCommand(Command command);
  Command getRotationDir() const;
  void setRotationDir(Command rotationDir);

private:
  Command mCommand;
  Command mRotationDir;
};

#endif /* SRC_CONTROLUNIT_HPP_ */
