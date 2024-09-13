#include "main.h"

int main() {
    // Function 1: Discount Calculation
    cout << "*** Function 1: Discount Calculation ***\n";
    double listPrice, discountPercentage, discountedPrice;
    cout << "Enter the list price: ";
    cin >> listPrice;
    cout << "Enter the discount percentage: ";
    cin >> discountPercentage;

    calculateDiscount(listPrice, discountPercentage, discountedPrice);
    cout << "The discounted price is: " << discountedPrice << endl;

    // Function 2: Determine the larger number
    cout << "\n*** Function 2: Determine the larger number ***\n";
    int intOne, intTwo, larger;
    cout << "Enter the first integer: ";
    cin >> intOne;
    cout << "Enter the second integer: ";
    cin >> intTwo;

    determineLarger(intOne, intTwo, &larger);
    if (intOne != intTwo) {
        cout << "The larger number is: " << larger << endl;
    }
    else {
        cout << "intOne(" << intOne << ") is equal to intTwo(" << intTwo << ")" << endl;
    }

    // Function 3: Compare arrays of strings
    cout << "\n*** Function 3: Compare arrays of strings ***\n";

    string arrayOne[SIZE];
    string arrayTwo[SIZE];

    // Clear the input buffer before calling getline
    cin.ignore();  // This ignores the leftover newline from previous cin

    // Populating first array
    cout << "Populate the first " << SIZE << " element(s) array:\n";
    populateArray(arrayOne, SIZE);

    // Populating second array
    cout << "\nPopulate the second array:\n";
    populateArray(arrayTwo, SIZE);

    // Comparing the two arrays
    if (compareArrays(arrayOne, arrayTwo, SIZE)) {
        cout << "\nThe arrays are identical.\n";
    }
    else {
        cout << "\nThe arrays are not identical.\n";
    }

    // Function 4: Sort arrays of strings
    cout << "\n*** Function 4: Sort arrays of strings ***\n";
    string arrayOneForSorting[SIZE];
    string templateArray[SIZE] = { "cherry", "apple", "banana", "orange" };

    // Clear the input buffer before calling getline again (if needed)
    populateArray(arrayOneForSorting, SIZE);


    cout << "\nOutput the built-in array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << templateArray[i] << " ";
    }
    cout << endl;

    // Sort both arrays
    sortArrays(arrayOneForSorting, templateArray, SIZE);

    // Output sorted template array
    cout << "Sorted template array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << templateArray[i] << " ";
    }
    cout << endl;

    // Output sorted built-in array
    cout << "\nSorted built-in array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arrayOneForSorting[i] << " ";
    }
    cout << endl;

    // Function 5: Demonstrate pointer techniques
    cout << "\n*** Function 5: Demonstrate pointer techniques ***\n";
    int num = 20;
    demoPtrTechniques(&num);

    return 0;
}
