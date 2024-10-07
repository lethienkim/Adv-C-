#include "Package.h"


Package::Package(const std::string& sName, const std::string& sAddress, const std::string& sCity,
    const std::string& sState, const std::string& sZip, const std::string& rName,
    const std::string& rAddress, const std::string& rCity, const std::string& rState,
    const std::string& rZip, double w, double cpo)
    : senderName(sName), senderAddress(sAddress), senderCity(sCity), senderState(sState), senderZip(sZip),
    receiverName(rName), receiverAddress(rAddress), receiverCity(rCity), receiverState(rState), receiverZip(rZip),
    weight(w), costPerOunce(cpo) {
    // Ensure weight and cost per ounce are greater than 0
    if (weight <= 0 || costPerOunce <= 0) {
        std::cerr << "Error: Weight and cost per ounce must be greater than 0. Setting default values." << std::endl;
        weight = 1;
        costPerOunce = 1;
    }
}

void Package::setSenderName(const std::string& name) {
    senderName = name;
}

std::string Package::getSenderName() const {
    return senderName;
}

void Package::setReceiverName(const std::string& name) {
    receiverName = name;
}

std::string Package::getReceiverName() const {
    return receiverName;
}

void Package::setWeight(double w) {
    if (w > 0) weight = w;
}

double Package::getWeight() const {
    return weight;
}

void Package::setCostPerOunce(double cpo) {
    if (cpo > 0) costPerOunce = cpo;
}

double Package::getCostPerOunce() const {
    return costPerOunce;
}

double Package::calculateCost() const {
    return weight * costPerOunce;
}
