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
#include <iostream>
#include "shapes.h"

int main() 
{
  //Attempt Rectangle Creation
  try
  {
    Rectangle r(4,6);
    std::cout << "Rectangle: " << r.getlength() << " " << r.getwidth() 
    << " " << r.area() << " " << r.perimeter() << std::endl;
    std::cout << r.str() << std::endl;
  }
  //In case a rectangle with same sides are done which means square
  catch(squareNegativeException error1)
  {
    std::cout << "\n" << error1.what() << " : " << error1.getNum() << std::endl;
    //Failure has occurred
    return 1;
  }
  //For normal rectangles
  catch(rectangleNegativeException error2)
  {
    std::cout << "\n" << error2.what() << " : " << error2.getNum() << std::endl;
    //Failure has occurred
    return 1;
  }

  //Attempt Square Creation
  try
  {
    Square s(-5);
    std::cout << "Square: " << s.getlength() << " " << s.getwidth() 
    << " " << s.area() << " " << s.perimeter() << std::endl;
    std::cout << s.str() << std::endl;
  }
  catch(squareNegativeException error3)
  {
    std::cout << "\n" << error3.what() << " : " << error3.getNum() << std::endl;
    //Failure has occurred
    return 1;
  }

  //Attempt Circle Creation
  try
  {
    Circle c(-1);
    std::cout << "Circle: " << c.getradius()
    << " " << c.area() << " " << c.perimeter() << std::endl;
    std::cout << c.str() << std::endl;
  }
  catch(circleNegativeException error4)
  {
    std::cout << "\n" << error4.what() << " : " << error4.getNum() << std::endl;
    //Failure has occurred
    return 1;
  }

  //Upon success
  return 0;
}
