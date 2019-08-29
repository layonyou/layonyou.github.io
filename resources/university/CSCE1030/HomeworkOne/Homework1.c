/*

Name: Jonathan Lay (JonathanLay@my.unt.edu | LayJonathanC@gmail.com)

Date: September 9, 2014

Instructor: Mark Thompson

Class: CSCE 1030-001

Lab: CSCE 1030-308

Purpose: Use user-inputted velocity and height to determine the time for
	 the object to hit the ground using the quadratic formula and using
	 a vertex formula to calculate the maximum height of the object.

*/

/* Import libraries */
#include <stdio.h>
#include <math.h>

/* Define constants */
#define accelerationDueToGravity -16

/* Declare function prototypes and variables */
float quadraticFormula(float, float, float);
float maxHeight(float, float, float);
float xSolutionOne, xSolutionTwo, validXSolution;
float xCoordinate, yCoordinate;

void main(){
	printf("\nCSCE 1030-001\nJonathan Lay\njcl0200\n"
	       "JonathanLay@my.unt.edu\n");

	/*
	Declaration and initialization of the quadratic
	formula and vertex formula's variables to be
	used later on.
	*/
	float initialVelocity = 0, initialHeight = 0;

	/*
	Prompt the user to input the initial velocity and
	initial height to create the position function.
	*/
	printf("\nInput initial velocity:\n");
	scanf("%f", &initialVelocity);
	printf("Input initial height:\n");
	scanf("%f", &initialHeight);
	printf("Position function of object:\n"
	       "S(t) = %dt^2 + %.2ft + %.2f\n\n",
	       accelerationDueToGravity, initialVelocity,
	       initialHeight);

	/*
	Call-by-value the function prototypes and state
	the answers for the object hitting the ground and
	its maximum height.
	*/
	quadraticFormula(accelerationDueToGravity, initialVelocity, initialHeight);
	maxHeight(accelerationDueToGravity, initialVelocity, initialHeight);
}

/* Code the prototype functions for call-by-value */
float quadraticFormula(float a, float b, float c){
	xSolutionOne = (-b + sqrt((pow(b, 2) - (4*a*c)))) / (2*a);
	xSolutionTwo = (-b - sqrt((pow(b, 2) - (4*a*c)))) / (2*a);
	if(xSolutionOne >= 0)
		validXSolution = xSolutionOne;
	if(xSolutionTwo >= 0)
		validXSolution = xSolutionTwo;
	printf("The object conatacts the ground in %.2f seconds.\n",
	       validXSolution);
	return 0;
}

float maxHeight(float a, float b, float c){
	xCoordinate = -b / (2*a);
	yCoordinate = (-pow(b, 2) + (4*a*c)) / (4*a);
	printf("The object's maximum height is reached in %.2f seconds"
	       " at %.2f feet.\n\n", xCoordinate, yCoordinate);
	return 0;
}
