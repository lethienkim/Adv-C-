#include "functions.h"

// Function 1: Calculate discounted price
void calculateDiscount(double listPrice, double discountPercentage, double& discountedPrice) {
    discountedPrice = listPrice - (listPrice * (discountPercentage / 100));
}

// Function 2: Determine the larger of two integers
void determineLarger(int intOne, int intTwo, int* larger) {
    if (intOne > intTwo) {
        *larger = intOne;
    }
    else if (intOne < intTwo) {
        *larger = intTwo;
    }
    else {
        *larger = intOne;  // In case of equality, assign either value
    }
}

// Function 3: 
// Populate an array with user input
void populateArray(string arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter element: ";
        getline(cin, arr[i]);
    }
    cout << endl;
}

// Compare two arrays of strings
bool compareArrays(string arrayOne[], string arrayTwo[], int size) {
    for (int i = 0; i < size; i++) {
        if (arrayOne[i] != arrayTwo[i]) {
            return false;
        }
    }
    return true;
}

// Function 4: Sort both built-in array and template array
void sortArrays(string builtInArray[], string templateArray[], int size) {
    // Sorting built-in array
    sort(builtInArray, builtInArray + size);

    // Sorting template array
    sort(templateArray, templateArray + size);
}

// Function 5: Demonstrate pointer techniques

// 1. Pass by pointer
void modifyValue(int* ptr) {
    *ptr += 10;  // Modify the value pointed to by ptr
}

// 2. Pass by reference to a pointer
void modifyPointer(int*& ptr) {
    static int newValue = 50;
    ptr = &newValue;  // Change the pointer itself to point to a new address
}

// 3. Pass a pointer to an array
void printArray(int* array, int size) {
    cout << "Array contents: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// 4. Pass a null pointer
void checkNullPointer(int* ptr) {
    if (ptr == nullptr) {
        cout << "Null pointer passed!" << endl;
    }
    else {
        cout << "Non-null pointer passed! The value is: " << *ptr << endl;
    }
}

// Function 5: Demonstrate pointer techniques
void demoPtrTechniques(int* num) {
    int value = 20;
    int* ptr = &value;

    // 1. Passing pointer directly
    cout << "Original value: " << *ptr << endl;
    modifyValue(ptr);
    cout << "Value after modifyValue: " << *ptr << endl;

    // 2. Passing pointer by reference
    modifyPointer(ptr);
    cout << "Pointer now points to new value: " << *ptr << endl;

    // 3. Passing a pointer to an array
    int array[3] = { 5, 10, 15 };
    printArray(array, 3);

    // 4. Passing a null pointer
    int* nullPtr = nullptr;
    checkNullPointer(nullPtr);
}
