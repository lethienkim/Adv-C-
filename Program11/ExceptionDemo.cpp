#include "ExceptionDemo.h"

void divisionByZero() {
    try {
        int a, b;
        cout << "Enter numerator: ";
        cin >> a;
        cout << "Enter denominator: ";
        cin >> b;

        if (b == 0) throw runtime_error("Division by zero error");

        cout << "Result: " << a / b << endl;
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void rethrowException() {
    try {
        try {
            throw runtime_error("Initial exception for rethrowing");
        }
        catch (const runtime_error& e) {
            cout << "Caught in inner try-catch block: " << e.what() << endl;
            cout << "Rethrowing exception...\n";
            throw; // Rethrow the exception to outer catch block
        }
    }
    catch (const runtime_error& e) {
        cout << "Caught rethrown exception in outer block: " << e.what() << endl;
    }
}

void stackUnwinding() {
    struct Helper {
        Helper() { cout << "Helper constructor\n"; }
        ~Helper() { cout << "Helper destructor\n"; }
    };

    try {
        Helper h;
        throw runtime_error("Stack unwinding in process");
    }
    catch (const runtime_error& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
}

void badAllocException() {
    try {
        cout << "Attempting to allocate a large amount of memory...\n";
        int* ptr = new int[1000000000000]; // Large allocation to force bad_alloc
        delete[] ptr;
    }
    catch (const bad_alloc& e) {
        cout << "Caught bad_alloc exception: " << e.what() << endl;
    }
}

void setNewHandlerException() {
    set_new_handler(myNewHandler);
    try {
        cout << "Attempting to allocate a large amount of memory...\n";
        int* ptr = new int[1000000000000]; // Force bad_alloc with a custom handler
        delete[] ptr;
    }
    catch (const bad_alloc& e) {
        cout << "Caught bad_alloc exception: " << e.what() << endl;
    }
}

void myNewHandler() {
    cout << "Custom new handler: Memory allocation failed. No memory left!\n";
    throw bad_alloc();
}
