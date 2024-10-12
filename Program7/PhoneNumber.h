#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class PhoneNumber {
    friend ostream& operator<<(ostream&, const PhoneNumber&);
    friend istream& operator>>(istream&, PhoneNumber&);

private:
    char phone[15];    // Holds the entire phone number plus \0
    char areaCode[4];  // Holds area code plus \0
    char exchange[4];  // Holds exchange plus \0
    char line[5];      // Holds line plus \0
};

#endif // PHONENUMBER_H
