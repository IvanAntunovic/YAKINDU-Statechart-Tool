/*
 * IDrivable.hpp
 *
 *  Created on: 26.12.2018
 *      Author: Johnny
 */

#ifndef IDRIVABLE_HPP_
#define IDRIVABLE_HPP_

class IDrivable {
public:
  virtual void driveForwards(const char* const speed) = 0;
  virtual void driveBackwards(const char* const speed) = 0;
  virtual void stop() = 0;
  virtual ~IDrivable() {};
};

#endif /* IDRIVABLE_HPP_ */
