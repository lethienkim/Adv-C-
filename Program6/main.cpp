/*
 * Program: Package Shipping Cost Calculator
 * Description:
 * This program calculates shipping costs for different types of packages, using polymorphism to handle
 * different shipping methods (Two-Day Shipping and Overnight Shipping). The user provides information
 * about the sender, receiver, package weight, cost per ounce, and either a two-day flat fee or an
 * overnight rate. The program then calculates and displays the shipping cost for each package.
 *
 * The program stores objects of both `TwoDayPackage` and `OvernightPackage` in a vector of `Package*`
 * pointers. By leveraging runtime polymorphism, the program calls the correct `calculateCost()` function
 * depending on the package type. At the end, the total shipping cost for all packages is calculated and displayed.
 */

#include <iostream>
#include <string>
#include <vector>
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

int main() {
    std::vector<Package*> packages; // Vector to store pointers to Package objects
    char choice;
    double totalCost = 0.0;

    // Variables for user input
    std::string senderName, senderAddress, senderCity, senderState, senderZip;
    std::string receiverName, receiverAddress, receiverCity, receiverState, receiverZip;
    double weight, costPerOunce, twoDayFee, overnightRate;

    do {
        std::cout << "Enter sender's information:\n";
        std::cout << "Name: ";
        std::getline(std::cin, senderName);
        std::cout << "Address: ";
        std::getline(std::cin, senderAddress);
        std::cout << "City: ";
        std::getline(std::cin, senderCity);
        std::cout << "State: ";
        std::getline(std::cin, senderState);
        std::cout << "Zip: ";
        std::getline(std::cin, senderZip);

        std::cout << "Enter receiver's information:\n";
        std::cout << "Name: ";
        std::getline(std::cin, receiverName);
        std::cout << "Address: ";
        std::getline(std::cin, receiverAddress);
        std::cout << "City: ";
        std::getline(std::cin, receiverCity);
        std::cout << "State: ";
        std::getline(std::cin, receiverState);

        std::cout << "Zip: ";
        std::getline(std::cin, receiverZip);

        std::cout << "Enter package weight (ounces): ";
        std::cin >> weight;
        std::cout << "Enter cost per ounce: ";
        std::cin >> costPerOunce;

        std::cout << "Choose shipping method (T for TwoDay, O for Overnight): ";
        std::cin >> choice;

        if (choice == 'T' || choice == 't') {
            std::cout << "Enter Two-Day flat fee: ";
            std::cin >> twoDayFee;

            // Create TwoDayPackage dynamically and add to the vector
            packages.push_back(new TwoDayPackage(senderName, senderAddress, senderCity, senderState, senderZip,
                receiverName, receiverAddress, receiverCity, receiverState, receiverZip,
                weight, costPerOunce, twoDayFee));
        }
        else if (choice == 'O' || choice == 'o') {
            std::cout << "Enter Overnight rate per ounce: ";
            std::cin >> overnightRate;

            // Create OvernightPackage dynamically and add to the vector
            packages.push_back(new OvernightPackage(senderName, senderAddress, senderCity, senderState, senderZip,
                receiverName, receiverAddress, receiverCity, receiverState, receiverZip,
                weight, costPerOunce, overnightRate));
        }

        std::cout << "Do you want to add another package (Y/N)? ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline character left in the input buffer
    } while (choice == 'Y' || choice == 'y');

    // Process each package polymorphically
    std::cout << "\nSummary of packages:\n";
    for (Package* pkg : packages) {
        std::cout << "\nSender: " << pkg->getSenderName()
            << "\nReceiver: " << pkg->getReceiverName()
            << "\nCost: $" << pkg->calculateCost() << "\n";
        totalCost += pkg->calculateCost();
    }

    std::cout << "\nTotal shipping cost for all packages: $" << totalCost << std::endl;

    // Clean up dynamic memory
    for (Package* pkg : packages) {
        delete pkg;
    }

    return 0;
}
