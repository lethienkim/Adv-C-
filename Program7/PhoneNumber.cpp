#include "PhoneNumber.h"

istream& operator>>(istream& input, PhoneNumber& number) {
    cout << "Enter phone number in the form (888) 555-1234: ";
    input.getline(number.phone, 15);

    // Validate the input length and format
    if (strlen(number.phone) != 14 ||
        number.phone[0] != '(' || number.phone[4] != ')' ||
        number.phone[5] != ' ' || number.phone[9] != '-') {
        input.setstate(ios::failbit);
        cout << "Invalid format! Phone number must be (###) ###-####.\n";
    }
    else if (number.phone[1] == '0' || number.phone[1] == '1' ||
        number.phone[6] == '0' || number.phone[6] == '1') {
        input.setstate(ios::failbit);
        cout << "Area code and exchange must not begin with 0 or 1.\n";
    }
    else {
        // Extract and copy parts of the phone number
        strncpy(number.areaCode, number.phone + 1, 3);
        number.areaCode[3] = '\0';

        strncpy(number.exchange, number.phone + 6, 3);
        number.exchange[3] = '\0';

        strncpy(number.line, number.phone + 10, 4);
        number.line[4] = '\0';
    }

    return input;
}

ostream& operator<<(ostream& output, const PhoneNumber& number) {
    output << "Phone Number: (" << number.areaCode << ") "
        << number.exchange << "-" << number.line;
    return output;
}
