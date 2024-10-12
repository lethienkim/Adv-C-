#include "PhoneNumber.h"
#include <iostream>
#include <cstring>
#include <limits>

PhoneNumber::PhoneNumber() {
    strcpy_s(phone, sizeof(phone), "");
    strcpy_s(areaCode, sizeof(areaCode), "");
    strcpy_s(exchange, sizeof(exchange), "");
    strcpy_s(line, sizeof(line), "");
}

std::istream& operator>>(std::istream& input, PhoneNumber& number) {
    char temp[15];
    std::cout << "Enter phone number in the form (888) 555-1234: ";
    input.getline(temp, 15);

    // Validate length (14 characters) and structure
    if (std::strlen(temp) != 14 ||
        temp[0] != '(' || temp[4] != ')' || temp[5] != ' ' ||
        temp[9] != '-') {
        input.setstate(std::ios::failbit);
        return input;
    }

    // Extract area code, exchange, and line from the input
    strncpy_s(number.areaCode, sizeof(number.areaCode), temp + 1, 3);
    strncpy_s(number.exchange, sizeof(number.exchange), temp + 6, 3);
    strncpy_s(number.line, sizeof(number.line), temp + 10, 4);

    // Check that area code and exchange do not start with '0' or '1'
    if (number.areaCode[0] == '0' || number.areaCode[0] == '1' ||
        number.exchange[0] == '0' || number.exchange[0] == '1') {
        std::cerr << "Area code and exchange cannot start with '0' or '1'.\n";
        input.setstate(std::ios::failbit);
        return input;
    }

    // Store the full phone number if valid
    strcpy_s(number.phone, sizeof(number.phone), temp);

    return input;
}

std::ostream& operator<<(std::ostream& output, const PhoneNumber& number) {
    output << "Full phone number: " << number.phone << "\n";
    output << "Area Code: " << number.areaCode << "\n";
    output << "Exchange: " << number.exchange << "\n";
    output << "Line: " << number.line;
    return output;
}
