/*
 * Source: TwoDayPackage Class Implementation
 * Description: This file implements the TwoDayPackage class, a derived class from Package, which adds
 *              a two-day shipping fee to the base package cost.
 */

#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(const std::string& sName, const std::string& sAddress, const std::string& sCity,
    const std::string& sState, const std::string& sZip, const std::string& rName,
    const std::string& rAddress, const std::string& rCity, const std::string& rState,
    const std::string& rZip, double w, double cpo, double fee)
    : Package(sName, sAddress, sCity, sState, sZip, rName, rAddress, rCity, rState, rZip, w, cpo),
    twoDayFee(fee) {
}

void TwoDayPackage::setTwoDayFee(double fee) {
    twoDayFee = fee;
}

double TwoDayPackage::getTwoDayFee() const {
    return twoDayFee;
}

double TwoDayPackage::calculateCost() const {
    return Package::calculateCost() + twoDayFee;
}
