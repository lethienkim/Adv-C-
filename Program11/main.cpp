#include "ExceptionDemo.h"

using namespace std;

int main() {
    int choice;

    cout << "Exception Handling Demo\n";
    cout << "Select an operation from the list below:\n";
    cout << "1. Division by zero\n";
    cout << "2. Rethrowing exceptions\n";
    cout << "3. Stack unwinding\n";
    cout << "4. Bad allocation exception\n";
    cout << "5. Set new handler exception\n";
    cout << "6. Exit\n";

    while (true) {
        cout << "\nEnter your choice (1-6): ";
        cin >> choice;

        try {
            switch (choice) {
            case 1:
                divisionByZero();
                break;
            case 2:
                rethrowException();
                break;
            case 3:
                stackUnwinding();
                break;
            case 4:
                badAllocException();
                break;
            case 5:
                setNewHandlerException();
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please select a number from 1 to 6.\n";
            }
        }
        catch (const exception& e) {
            cout << "Caught an exception: " << e.what() << endl;
        }
        catch (...) {
            cout << "Caught an unknown exception.\n";
        }
    }
    return 0;
}
