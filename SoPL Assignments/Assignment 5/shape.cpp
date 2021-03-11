/*
 * Author: Omer Basar
 * Filename: shape.cpp
 * Version: 11/19/20
 * Assignment: 5
 * Additional Note:
 * I utilized the tutorial from this website to learn
 * about how to make exceptions in c++ 
 * https://www.cplusplus.com/doc/tutorial/exceptions/
 */

//Appropriate include statements
#include <strstream>
#include "shapes.h"

/******************************/
/*Rectangle Exception Operations*/

rectangleNegativeException::rectangleNegativeException(int n)
{
  num = n;
}
const char* rectangleNegativeException::what() const throw()
{
  return "Negative side in rectangle construction detected";
}
int rectangleNegativeException::getNum() const
{
  return num;
}

/******************************/
/*Square Exception Operations*/

squareNegativeException::squareNegativeException(int n)
{
  num = n;
}
const char* squareNegativeException::what() const throw()
{
  return "Negative side in square construction detected";
}
int squareNegativeException::getNum() const
{
  return num;
}

/******************************/
/*Circle Exception Operations*/

circleNegativeException::circleNegativeException(int n)
{
  num = n;
}
const char* circleNegativeException::what() const throw()
{
  return "Negative radius in circle construction detected";
}
int circleNegativeException::getNum() const
{
  return num;
}

/******************************/
/*Rectangle Operations*/

Rectangle::Rectangle(float length, float width) 
{
  //Negative side check for square since they are a variant of rectangle
  if (length == width && length < 0)
  {
    throw squareNegativeException(length);
  }
  //Checks if sides are negative for rectangles, throws exception if they are negative
  if (length < 0)
  {
    throw rectangleNegativeException(length);
  }
  if(width < 0)
  {
    throw rectangleNegativeException(width);
  }
  //Perform these operations once sides are confirmed non-negative
  this->length = length;
  this->width = width;
}

float Rectangle::getlength() const 
{
  return length;
}

float Rectangle::getwidth() const 
{
  return width;
}

float Rectangle::perimeter() const 
{
  return 2 * length + 2 * width;
}

float Rectangle::area() const 
{
  return length * width;
}

std::string Rectangle::str() const 
{
  std::strstream out;
  // "A rectangle width sides (3,4)"

  out << "A rectangle width sides (" << length << "," << width << ")";
  return out.str();
}

/******************************/
/*Square Operations*/

Square::Square(float side) : Rectangle(side, side) {}

std::string Square::str() const 
{
  std::strstream out;
  // "A square width sides (3)"

  out << "A square width sides (" << getlength() << ")";
  return out.str();
}

/******************************/
/*Circle Operations*/

Circle::Circle(float radius) 
{
  //Checks if sides are negative, throws exception if they are negative
  if (radius < 0)
  {
    throw circleNegativeException(radius);
  }
  //Perform this operation once radius is confirmed non-negative
  this->radius = radius;
}

float Circle::getradius() const 
{
  return radius;
}

float Circle::perimeter() const 
{
  return 2 * radius * PI;
}

float Circle::area() const 
{
  return PI * radius * radius;
}

std::string Circle::str() const 
{
  std::strstream out;
  // "A circle width radius (3)"

  out << "A circle width radius (" << radius << ")";
  return out.str();
}
