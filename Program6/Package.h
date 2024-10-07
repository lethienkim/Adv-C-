/*
 * Header: Package Class Definition
 * Description: This file contains the definition for the base Package class, which
 *              stores information about the sender, receiver, package weight, and cost per ounce.
 */
#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include <iostream>

class Package {
protected:
    // Sender and receiver details
    std::string senderName, senderAddress, senderCity, senderState, senderZip;
    std::string receiverName, receiverAddress, receiverCity, receiverState, receiverZip;

    double weight;
    double costPerOunce;

public:
    // Constructor: use const references to avoid unnecessary copies
    Package(const std::string& sName, const std::string& sAddress, const std::string& sCity,
        const std::string& sState, const std::string& sZip, const std::string& rName,
        const std::string& rAddress, const std::string& rCity, const std::string& rState,
        const std::string& rZip, double w, double cpo);

    // Setters and getters
    void setSenderName(const std::string& name);
    std::string getSenderName() const;

    void setReceiverName(const std::string& name);
    std::string getReceiverName() const;

    // Setters and getters for package details
    void setWeight(double w);
    double getWeight() const;

    void setCostPerOunce(double cpo);
    double getCostPerOunce() const;

    // Calculate the base cost of the package
    virtual double calculateCost() const;
};

#endif
