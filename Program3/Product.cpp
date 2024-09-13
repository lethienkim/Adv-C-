#include "Product.h"

using namespace std;

int Product::productCount = 0;

Product::Product(string name, string description)
    : productName(name), productDescription(description) {
    productNum = ++productCount;

    // Get current time for product creation
    time_t now = time(0);
    char buffer[26];  // Buffer to hold the formatted time string
    ctime_s(buffer, sizeof(buffer), &now);  // Use ctime_s for safer time conversion
    productCreationTime = buffer;
}


void Product::setProductNum(int num) {
    productNum = num;
}

int Product::getProductNum() const {
    return productNum;
}

void Product::setProductName(const string& name) {
    productName = name;
}

string Product::getProductName() const {
    return productName;
}

void Product::setProductDescription(const string& description) {
    productDescription = description;
}

string Product::getProductDescription() const {
    return productDescription;
}

string Product::getProductCreationTime() const {
    return productCreationTime;
}

int Product::getProductCount() {
    return productCount;
}

void Product::displayProduct() const {
    cout << "Product Number: " << productNum << "\n"
        << "Name: " << productName << "\n"
        << "Description: " << productDescription << "\n"
        << "Created: " << productCreationTime;
}
