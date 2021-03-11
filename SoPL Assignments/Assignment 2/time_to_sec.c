/*
 * Author: Omer Basar
 * Filename: time_to_sec.c
 * Version: 9/22/20
 * Assignment: 2
 */

// appropriate #include statements
#include <stdio.h> // use standard streams

/* Convert a time interval specified in hours, minutes and seconds to
 * seconds.
 * Parameters:
 *     hours, minutes, seconds: input time elements
 * Preconditions:
 *     0 <= minutes < 60
 *     0 <= seconds < 60 
 * Return:
 *     number of seconds in the interval
 */
unsigned int time_to_sec(unsigned int hours, unsigned int minutes,
        unsigned int seconds) 
{
    // define an unsigned integer that converts the given hours to minutes
    unsigned int hours_to_minutes = hours * 60;
    // updates minutes by adding the value from hours_to_minutes to it
    minutes = hours_to_minutes + minutes;
    // define an unsigned integer that converts the minutes to seconds
    unsigned int minutes_to_seconds = minutes * 60;
    // updates seconds by adding the value from minutes_to_seconds to it
    seconds = minutes_to_seconds + seconds;

    // returns the time interval converted into the total amount of seconds
    return seconds;
}

/* Print a formatted representation of the calculation
 * Parameters:
 *     hours, minutes, seconds: input time elements
 * Postcondition:
 *     Function will write the calculation to standard output.
 */
void format_seconds(unsigned int hours, unsigned int minutes,
        unsigned int seconds) 
{
    // define an unsigned integer that contains the time interval converted to seconds
    unsigned int formatted_time = time_to_sec(hours, minutes, seconds);
    // print formatted the hours, minutes, seconds, and the time interval in seconds with a newline character
    printf("%d hours, %d minutes, and %d seconds is equal to %d seconds.\n", hours, minutes, seconds, formatted_time);
}

int main(void) 
{
    format_seconds(4, 13, 20);
    format_seconds(8, 0, 0);
    format_seconds(1, 30, 0);

    // everything went well; return 0
    return 0;
}