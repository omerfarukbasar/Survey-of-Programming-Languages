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

/* Shape class */
#include <string>
#define PI 3.14159

/* Exception for Rectangles with negative sides */
class rectangleNegativeException: public std::exception
{
  public:
    //Constructor
    rectangleNegativeException(int n);
    //Returns static message, is const and implements throw
    const char* what() const throw();
    //Returns the given integer from the parameter
    int getNum() const;
  
  private:
    int num;
};

/* Exception for Squares with negative sides */
class squareNegativeException: public std::exception
{
  public:
    //Constructor
    squareNegativeException(int n);
    //Returns static message, is const and implements throw
    const char* what() const throw();
    //Returns the given integer from the parameter
    int getNum() const;
  
  private:
    int num;
};

/* Exception for Circles with negative radius */
class circleNegativeException: public std::exception
{
  public:
    //Constructor
    circleNegativeException(int n);
    //Returns static message, is const and implements throw
    const char* what() const throw();
    //Returns the given integer from the parameter
    int getNum() const;
  
  private:
    int num;
};

/* Shape class */
class Shape 
{
  public:
    virtual float area() const = 0;
    virtual float perimeter() const = 0;
    virtual std::string str() const = 0;
};

/* Rectangle class */
class Rectangle : public Shape 
{
  public:
    Rectangle(float length, float width);
    float getlength() const;
    float getwidth() const;
    float area() const;
    float perimeter() const;
    std::string str() const;
  private:
    float length;
    float width;
};

/* Square class */
class Square : public Rectangle 
{
  public:
    Square(float side);
    std::string str() const;
};

/* Circle class*/
class Circle : public Shape 
{
  public: 
    Circle(float radius);
    float getradius() const;
    float area() const;
    float perimeter() const;
    std::string str() const;

  private:
    float radius;
};