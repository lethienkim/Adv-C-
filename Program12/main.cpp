#include <iostream>
#include "function.h"
using namespace std;

int main() {
    int choice;

    cout << "Stack Template Demo\n";
    cout << "Select the type of stack:\n";
    cout << "1. Integer\n";
    cout << "2. Double\n";
    cout << "3. String\n";
    cout << "4. Exit\n";

    while (true) {
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Stack<int> intStack;
            performStackOperations(intStack);
            break;
        }
        case 2: {
            Stack<double> doubleStack;
            performStackOperations(doubleStack);
            break;
        }
        case 3: {
            Stack<string> stringStack;
            performStackOperations(stringStack);
            break;
        }
        case 4:
            cout << "Exiting program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please select a number from 1 to 4.\n";
        }
    }
}

