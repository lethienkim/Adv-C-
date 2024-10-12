#include "ProcessPhoneNumber.h"


void processPhoneNumber() {
    PhoneNumber phoneNumber;
    char choice;

    do {
        cout << "Phone Number Input System\n";
        if (!(cin >> phoneNumber)) {
            cin.clear();  // Clear the failbit
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Would you like to try again? (y/n): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (choice == 'n' || choice == 'N') {
                break;
            }
        }
        else {
            // Output the phone number if no errors
            cout << "\nValid phone number entered:\n";
            cout << phoneNumber << "\n";
            break;
        }
    } while (true);
}

