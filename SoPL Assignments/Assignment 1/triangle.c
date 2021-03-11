/**
Author: Omer Basar
Filename: triangle.c
Version: 9/17/20
Assignment: 1
**/

#include <stdio.h>  // use standard streams
#define HEIGHT 15  // HAS NO TYPE! (not a variable)


int main(void)
{

  // define an int called 'triangleHeight' and initialize it to HEIGHT
  int triangleHeight = HEIGHT;

  // define a character called shapeChar and initialize it to an asterisk
  char shapeChar = '*';

  // define a character array called myString to make a String with a size of triangleHeight
  char myString[triangleHeight];

  // for loop from x = 0 to 14 to print each row of asterisks to form the right triangle
  for (int x = 0; x < triangleHeight; x++)
  {

      // for loop from y = 0 to x that "builds" the row with x + 1 amount of asterisks
      for (int y = 0; y <= x; y++)
      {

          // sets the value at index y to be shapeChar
          myString[y] = shapeChar;
      }

      // sets the value in the array after index x to be null terminator
      myString[x + 1] = '\0';

      // print formatted myString array with newline character
      printf("%s\n", myString);
  }

  // everything went well; return 0
  return 0;
}
