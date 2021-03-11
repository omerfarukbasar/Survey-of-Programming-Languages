/*
 * Author: Omer Basar
 * Filename: temperature_conversion.c
 * Version: 10/20/20
 * Assignment: 4
 */

// appropriate #include statements
#include <stdio.h> // use standard streams
#include <string.h> // allows use of manipulation functions for char arrays
#include <ctype.h> // allows the use of the toupper function which converts 
				  //char from lowercase to uppercase
				 // https://www.educative.io/edpresso/what-is-the-toupper-function-in-c


// you're not expected to understand this.
void clearKeyboardBuffer() 
{
    char ch;
    while ((ch = getchar() != '\n') && (ch != EOF));
}

/* Takes celsius and converts it to fahrenheit
 * Parameters:
 *    input - float
 * Preconditions:
 *    celsius float is provided
 * Return:
 *    fahrenheit - float
 */
float ctof(float input)
{
	float fahrenheit = (input * 1.8) + 32;
	return fahrenheit;
}

/* Takes celsius and converts it to kelvin
 * Parameters:
 *    input - float
 * Preconditions:
 *    celsius float is provided
 * Return:
 *    kelvin - float
 */
float ctok(float input)
{
	float kelvin = input + 273.15;
	return kelvin;
}

/* Takes kelvin and converts it to celsius
 * Parameters:
 *    input - float
 * Preconditions:
 *    kelvin float is provided
 * Return:
 *    celsius - float
 */
float ktoc(float input)
{
	float celsius = input - 273.15;
	return celsius;
}

/* Takes kelvin and converts it to fahrenheit
 * Parameters:
 *    input - float
 * Preconditions:
 *    kelvin float is provided
 * Return:
 *    fahrenheit - float
 */
float ktof(float input)
{
	float fahrenheit = ktoc(input);
	fahrenheit = ctof(fahrenheit);
	return fahrenheit;
}

/* Takes fahrenheit and converts it to celsius
 * Parameters:
 *    input - float
 * Preconditions:
 *    fahrenheit float is provided
 * Return:
 *    celsius - float
 */
float ftoc(float input)
{
	float celsius = (input - 32) / 1.8;
	return celsius;
}

/* Takes fahrenheit and converts it to kelvin
 * Parameters:
 *    input - float
 * Preconditions:
 *    fahrenheit float is provided
 * Return:
 *    kelvin - float
 */
float ftok(float input)
{
	float kelvin = ftoc(input);
	kelvin = ctok(kelvin);
	return kelvin;
}


int main(void) 
{
	// initialize scale char, input float, and returnVal
	char scale = '\0';
	float input = 0.0;
	int returnVal = -1;

	// declare temp variables
	float fahrenheit;
	float celsius;
	float kelvin;


	// loop that asks for input until condition is met
	while(returnVal != 2)
	{
		// asks for user input
		printf("\n\nEnter input temperature: ");

		// separates input into float and char and then returns int value based on success
    	returnVal = scanf("\n%f%c",&input, &scale);

		// clears keyboard to prevent loop bug
    	clearKeyboardBuffer();
    	
    	// converts the scale unit to uppercase if needed
		// recieved guidance from the following link as reference
		// https://www.educative.io/edpresso/what-is-the-toupper-function-in-c
		scale = toupper(scale);

    	// if invalid input
    	if (returnVal != 2)
    	{
    		printf("\ninvalid input!");
    		input = 0.0;
    		scale = '\0';
    	}
    	
    	//if scale is incorrect
    	else if (scale != 'C' && scale != 'F' && scale != 'K' )
    	{
    		printf("\ninvalid temperature scale!");
    		returnVal = -1;
    		input = 0.0;
    		scale = '\0';
    	}

	}


	// print formatted statement
	printf("%.2f %c Converts to:\n", input, scale);
    

    // performs following operations if input scale is celsius
    if (scale == 'C')
    {
    	//call ctof
    	fahrenheit = ctof(input);

    	//cal ctok
    	kelvin = ctok(input);

    	//print formatted statement
    	printf(" %.2f F \n %.2f K", fahrenheit, kelvin);
    }

    // performs following operations if input scale is kelvin
    else if (scale == 'K')
    {
    	//call ktof
    	fahrenheit = ktof(input);

    	//cal ktoc
    	celsius = ktoc(input);

    	//print statement
    	printf(" %.2f F \n %.2f C", fahrenheit, celsius);
    }

    // performs following operations if input scale is fahrenheit
    else if (scale == 'F')
    {
    	//call ftoc
    	celsius = ftoc(input);

    	//call ftok
    	kelvin = ftok(input);

    	//print statement
    	printf(" %.2f C \n %.2f K", celsius, kelvin);
    }

    // returns arbitrary number if program somehow fails
    else
    {
    	return 3241;
    }

    // everything went well; return 0
    return 0;
}