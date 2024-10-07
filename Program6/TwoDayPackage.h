#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage : public Package {
private:
    double twoDayFee;

public:
    // Constructor: use const references to avoid unnecessary copies
    TwoDayPackage(const std::string& sName, const std::string& sAddress, const std::string& sCity,
        const std::string& sState, const std::string& sZip, const std::string& rName,
        const std::string& rAddress, const std::string& rCity, const std::string& rState,
        const std::string& rZip, double w, double cpo, double fee);

    // Setter and getter for two-day fee
    void setTwoDayFee(double fee);
    double getTwoDayFee() const;

    // Override the calculateCost() to include the two-day fee
    double calculateCost() const override;
};

#endif
