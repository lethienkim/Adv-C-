#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage : public Package {
private:
    double overnightRate;

public:
    // Constructor
    OvernightPackage(const std::string& sName, const std::string& sAddress, const std::string& sCity,
        const std::string& sState, const std::string& sZip, const std::string& rName,
        const std::string& rAddress, const std::string& rCity, const std::string& rState,
        const std::string& rZip, double w, double cpo, double rate);

    // Setter and getter for overnight rate
    void setOvernightRate(double rate);
    double getOvernightRate() const;

    // Override the calculateCost() to include the overnight rate
    double calculateCost() const override;
};

#endif

