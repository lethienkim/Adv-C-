/*
 * Program: Package Shipping Cost Calculation
 * Description: This program calculates the shipping cost for packages using two shipping methods:
 *              Two-Day Shipping and Overnight Shipping. It gathers sender, receiver, and package
 *              information, then computes and displays the cost for each method.
 */
#include <iostream>
#include <string>
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

int main() {
    // Variables for user input
    std::string senderName, senderAddress, senderCity, senderState, senderZip;
    std::string receiverName, receiverAddress, receiverCity, receiverState, receiverZip;
    double weight, costPerOunce, twoDayFee, overnightRate;

    // Input for sender's details
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

    // Input for receiver's details
    std::cout << "\nEnter receiver's information:\n";
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

    // Input for package details
    std::cout << "\nEnter package details:\n";
    std::cout << "Weight (in ounces): ";
    std::cin >> weight;
    std::cout << "Cost per ounce: ";
    std::cin >> costPerOunce;

    // TwoDayPackage specific details
    std::cout << "\nEnter the flat fee for Two-Day Shipping: ";
    std::cin >> twoDayFee;

    // OvernightPackage specific details
    std::cout << "Enter the additional rate per ounce for Overnight Shipping: ";
    std::cin >> overnightRate;

    // Create TwoDayPackage and OvernightPackage objects
    TwoDayPackage twoDay(senderName, senderAddress, senderCity, senderState, senderZip,
        receiverName, receiverAddress, receiverCity, receiverState, receiverZip,
        weight, costPerOunce, twoDayFee);

    OvernightPackage overnight(senderName, senderAddress, senderCity, senderState, senderZip,
        receiverName, receiverAddress, receiverCity, receiverState, receiverZip,
        weight, costPerOunce, overnightRate);

    // Display calculated costs
    std::cout << "\n--- Shipping Cost Details ---\n";
    std::cout << "Two Day Package Cost: $" << twoDay.calculateCost() << std::endl;
    std::cout << "Overnight Package Cost: $" << overnight.calculateCost() << std::endl;

    return 0;
}
