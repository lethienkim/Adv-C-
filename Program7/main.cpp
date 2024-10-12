#include "PhoneNumber.h"
#include <iostream>
#include <limits>

int main() {
    PhoneNumber phoneNumber;
    bool validInput = false;

    while (!validInput) {
        std::cin >> phoneNumber;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid phone number entered! Phone number must be (###) ### - ####.\n";
            std::cout << "Would you like to try again ? (y / n) : ";
            char choice;
            std::cin >> choice;
            if (choice == 'n' || choice == 'N') {
                std::cout << "Exiting the program.\n";
                return 1;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            validInput = true;
            std::cout << phoneNumber << std::endl;
        }
    }

    // Graceful exit
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    std::cout << "\n\n<ENTER> to exit: ";
    std::cin.get();

    return 0;
}
