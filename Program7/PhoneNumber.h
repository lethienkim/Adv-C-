#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>

class PhoneNumber {
private:
    char phone[15];     // Holds the entire phone number plus \0
    char areaCode[4];   // Holds area code plus \0
    char exchange[4];   // Holds exchange plus \0
    char line[5];       // Holds line plus \0

public:
    PhoneNumber();
    friend std::istream& operator>>(std::istream& input, PhoneNumber& number);
    friend std::ostream& operator<<(std::ostream& output, const PhoneNumber& number);
};

#endif
