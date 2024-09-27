#include "functions.h"

// Constructor
OverloadDemo::OverloadDemo(int i, double d, string s) : intOne(i), doubleOne(d), stringOne(s) {}

// Setters
void OverloadDemo::setIntOne(int value) { intOne = value; }
void OverloadDemo::setDoubleOne(double value) { doubleOne = value; }
void OverloadDemo::setStringOne(string value) { stringOne = value; }

// Getters
int OverloadDemo::getIntOne() const { return intOne; }
double OverloadDemo::getDoubleOne() const { return doubleOne; }
string OverloadDemo::getStringOne() const { return stringOne; }

// Operator overloading for +
OverloadDemo OverloadDemo::operator+(const OverloadDemo& obj) const {
    return OverloadDemo(intOne + obj.intOne, doubleOne + obj.doubleOne, stringOne + " " + obj.stringOne);
}

// Operator overloading for -
OverloadDemo OverloadDemo::operator-(const OverloadDemo& obj) const {
    return OverloadDemo(intOne - obj.intOne, doubleOne - obj.doubleOne, stringOne);
}

// Operator overloading for *
OverloadDemo OverloadDemo::operator*(const OverloadDemo& obj) const {
    return OverloadDemo(intOne * obj.intOne, doubleOne * obj.doubleOne, stringOne + " " + stringOne);
}

// Operator overloading for /
OverloadDemo OverloadDemo::operator/(const OverloadDemo& obj) const {
    if (obj.intOne == 0 || obj.doubleOne == 0) {
        cout << "Error: Division by zero!" << endl;
        return *this;
    }
    return OverloadDemo(intOne / obj.intOne, doubleOne / obj.doubleOne, stringOne);
}

// Prefix ++ (does not modify stringOne)
OverloadDemo& OverloadDemo::operator++() {
    ++intOne;
    ++doubleOne;
    // stringOne remains unchanged
    return *this;
}

// Postfix ++ (does not modify stringOne)
OverloadDemo OverloadDemo::operator++(int) {
    OverloadDemo temp = *this; // Save current state
    ++intOne;
    ++doubleOne;
    // stringOne remains unchanged
    return temp; // Return original state
}

// Prefix -- (does not modify stringOne)
OverloadDemo& OverloadDemo::operator--() {
    --intOne;
    --doubleOne;
    // stringOne remains unchanged
    return *this;
}

// Postfix -- (does not modify stringOne)
OverloadDemo OverloadDemo::operator--(int) {
    OverloadDemo temp = *this; // Save current state
    --intOne;
    --doubleOne;
    // stringOne remains unchanged
    return temp; // Return original state
}

// Display current values of the object
void OverloadDemo::display() const {
    cout << "intOne: " << intOne << ", doubleOne: " << doubleOne << ", stringOne: '" << stringOne << "'" << endl;
}

// Input function for user to input values
void OverloadDemo::input() {
    cout << "Enter integer value: ";
    cin >> intOne;
    cout << "Enter double value: ";
    cin >> doubleOne;
    cout << "Enter string value: ";
    cin.ignore();  // Ignore leftover newline
    getline(cin, stringOne);
}
