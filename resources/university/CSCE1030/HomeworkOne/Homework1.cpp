/*

Author:     Jonathan Lay

Date :      August 26, 2019

Purpose:    Rewrite program.
            Use user-inputted velocity and height to determine the time for
	         the object to hit the ground using the quadratic formula and using
	         a vertex formula to calculate the maximum height of the object.

*/

/* Import Libraries */
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

/* Declare Function Prototypes */
void debugInfo(double velocity, double height);
double quadraticFormula(double a, double b, double c);
double maxHeight(double a, double b, double c);
double maxHeightTime(double a, double b);

/* Define Constants */
const double GRAVITY_ACCELERATION = -16.0;

int main() {

   cout << "\nJonathan Lay\nHomework 1 Reprogram\n" << endl;

   // Initialize Variables
   double* velocity = (double*)calloc(1, sizeof(sizeof(double)));
   double* height = (double*)calloc(1, sizeof(sizeof(double)));
   if (velocity == NULL || height == NULL) {
      cerr << "\nUnable to initialize pointers!" << endl;
   }

   // Read user input
   cout << "\nInput velocity: ";
   cin >> *velocity;
   cout << "\nInput height: ";
   cin >> *height;

   // Calculate
   cout << "\nPosition function of object:\nS(t) = " << GRAVITY_ACCELERATION << "t^2 + " << *velocity << "t + " << *height << endl;
   cout << "\nThe object contacts the ground in " << quadraticFormula(GRAVITY_ACCELERATION, *velocity, *height) << " second(s)." << endl;
   cout << "\nThe object's maximum height is " << maxHeight(GRAVITY_ACCELERATION, *velocity, *height) << " feet in " 
         << maxHeightTime(GRAVITY_ACCELERATION, *velocity) << " second(s)." << endl;
   
   //debugInfo(*velocity, *height);
   
   // Free memory
   free(height);
   free(velocity);
   return 0;

}

/* Debugging Variables */
void debugInfo(double velocity, double height) {

   cout << "\nVelocity: " << velocity << "\nHeight: " << height << endl;


}

/* Calculate quadratic formula */
double quadraticFormula(double a, double b, double c) {

   double xOne = (-b + sqrt((pow(b, 2) - (4 * a * c)))) / (2 * a);
   double xTwo = (-b - sqrt((pow(b, 2) - (4 * a * c)))) / (2 * a);
   if (xOne >= 0.0) {
      return xOne;
   }
   else if (xTwo >= 0.0) {
      return xTwo;
   }
   else
      return NULL;

}

/* Calculate max height */
double maxHeight(double a, double b, double c) {

   return (-pow((b), 2) + (4 * (a) * (c))) / (4 * (a));

}

/* Calculate the time to reach max height */
double maxHeightTime(double a, double b) {

   return -b / (2 * a);

}