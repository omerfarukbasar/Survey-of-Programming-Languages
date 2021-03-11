/*
 * Author: Omer Basar
 * Filename: numeric_palindrome.c
 * Version: 10/6/20
 * Assignment: 3
 */

// appropriate #include statements
#include <stdio.h> // use standard streams
#include <string.h> // allows use of manipulation functions for char arrays

// appropriate #define statements
#define LOWER_BOUND 100 // smallest 3 digit number possible
#define UPPER_BOUND 1000 // smallest 4 digit number possible
#define SIZE 7 // Largest possible product has 6 digits, reserve additional space for null terminator

/* Takes a char array, reverses it and then
 * checks if it is a palindrome
 * Parameters:
 *    buffer
 * Preconditions:
 *    a number based char array exists
 * Return:
 *    int 0 if it's a palindrome
 *    Otherwise returns int 1
 */
int reverseAndPalCheck(char buffer[]) 
{
  // initialize a char array to be used as a copy for reversing
  char copyArray[SIZE]; 
  // initialize chars for temporarily holding chars to be switched
  char tempOne;

  // loop used to copy original char array to another for reversing
  for (int i = 0; i < SIZE - 1; i++)
  {
    copyArray[i] = buffer[i];
  }

  // sets the array's last index to null terminator to avoid memory issues
  copyArray[SIZE - 1] = '\0';

  // loop for reversing the char array
  for (int i = 0, j = SIZE - 2; i < j; i++, j--) 
  {
    tempOne = copyArray[i];
    copyArray[i] = copyArray[j];
    copyArray[j] = tempOne;
  }

  // loop for comparing the original char array to the reversed one
  for(int i = 0; i < SIZE - 1; i ++)
  {
    // checks if values between arrays don't match
    if(buffer[i] != copyArray[i])
    {
      // returns 1 when values do not match, confirming that it's not a palindrome
      return 1;
    }
  }

  // returns 0 when it's confirmed to be a palindrome after no errors arise
  return 0;
  
}

/* Searches for factors to multiply and determine the largest palindrome
 * Parameters:
 *    N/A
 * Preconditions:
 *    Main function exists so it can be used
 * Return:
 *    int 0 if the operation was successful
 */
int factorSearch() 
{
  // initialize a char array to be used as a copy for reversing
  char buffer[SIZE];
  
  // initialize ints to keep travk of largest palindrome and its factors
    int currentLargest = 0;
    int currentX = 0;
    int currentY = 0;

  // loops from 100 to 999 to initialize the first factor to be multiplied
  for (int x = LOWER_BOUND; x < UPPER_BOUND; x++)
  {

    // loops from 100 to 999 to initialize the second factor to be multiplied
    for (int y = LOWER_BOUND; y < UPPER_BOUND; y++)
    {
      // initializes an int containing the product of the two factors
      int productValue = x * y;

      // converts the int into chars to be stored in a char array
      sprintf(buffer, "%d", productValue);

      // sets the array's last index to null terminator to avoid memory issues
      buffer[SIZE - 1] = '\0';

      // calls the functions and checks if it's 0 to confirm that the number was a palindrome
      if(reverseAndPalCheck(buffer) == 0)
      {

        // checks if the current largest palindrome is smaller than the one calculated
        if (currentLargest < productValue)
        {
          // sets the values accordingly
          currentLargest = productValue;
          currentX = x;
          currentY = y;
        }
      }
    }
  }

  // print formatted the factors of the largest palindrome and the palindrome itself
  printf("%d, %d, %d\n", currentX, currentY,currentLargest);

  // everything went well; return 0
  return 0;  
}

int main(void) 
{
    // returns 0 if no issues arise
    return factorSearch();
}