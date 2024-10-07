#include "OvernightPackage.h"

OvernightPackage::OvernightPackage(const std::string& sName, const std::string& sAddress, const std::string& sCity,
    const std::string& sState, const std::string& sZip, const std::string& rName,
    const std::string& rAddress, const std::string& rCity, const std::string& rState,
    const std::string& rZip, double w, double cpo, double rate)
    : Package(sName, sAddress, sCity, sState, sZip, rName, rAddress, rCity, rState, rZip, w, cpo), overnightRate(rate) {}

void OvernightPackage::setOvernightRate(double rate) {
    overnightRate = rate;
}

double OvernightPackage::getOvernightRate() const {
    return overnightRate;
}

double OvernightPackage::calculateCost() const {
    return Package::calculateCost() + (overnightRate * weight);
}
