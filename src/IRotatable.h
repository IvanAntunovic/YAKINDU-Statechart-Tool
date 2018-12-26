/*
 * IRotatable.h
 *
 *  Created on: 26.12.2018
 *      Author: Johnny
 */

#ifndef IROTATABLE_H_
#define IROTATABLE_H_

typedef enum {CCW, CW} RotateDirection;

class IRotatable {
public:
  virtual void rotate(const RotateDirection direction) = 0;
  virtual ~IRotatable() {};
};

#endif /* IROTATABLE_H_ */
