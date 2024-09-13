#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function 1: Calculate discounted price
void calculateDiscount(double listPrice, double discountPercentage, double& discountedPrice);

// Function 2: Determine the larger of two integers
void determineLarger(int intOne, int intTwo, int* larger);

// Function 3: Populate an array with user input
void populateArray(string arr[], int size);

// Function 3: Compare two arrays of strings
bool compareArrays(string arrayOne[], string arrayTwo[], int size);

// Function 4: Sort both built-in array and template array
void sortArrays(string builtInArray[], string templateArray[], int size);

// Function 5: Demonstrate pointer techniques
void demoPtrTechniques(int* num);

// Helper functions for demoPtrTechniques
void modifyValue(int* ptr);
void modifyPointer(int*& ptr);
void printArray(int* array, int size);
void checkNullPointer(int* ptr);

#endif
