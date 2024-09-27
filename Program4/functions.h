#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
using namespace std;

class OverloadDemo {
private:
    int intOne;
    double doubleOne;
    string stringOne;

public:
    // Constructor
    OverloadDemo(int i = 0, double d = 0.0, string s = "");

    // Setters
    void setIntOne(int value);
    void setDoubleOne(double value);
    void setStringOne(string value);

    // Getters
    int getIntOne() const;
    double getDoubleOne() const;
    string getStringOne() const;

    // Operator overloading
    OverloadDemo operator+(const OverloadDemo& obj) const;
    OverloadDemo operator-(const OverloadDemo& obj) const;
    OverloadDemo operator*(const OverloadDemo& obj) const;
    OverloadDemo operator/(const OverloadDemo& obj) const;

    // Prefix and Postfix increment and decrement
    OverloadDemo& operator++();    // Prefix ++
    OverloadDemo operator++(int);  // Postfix ++
    OverloadDemo& operator--();    // Prefix --
    OverloadDemo operator--(int);  // Postfix --

    // Display function to show current values
    void display() const;

    // Input function to get user input
    void input();
};

#endif
