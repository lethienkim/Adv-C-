#include "product.h"
#include "main.h"  // For getCurrentMonthAndYear function

int Product::productCount = 0;

Product::Product(const std::string& name, const std::string& description)
    : productName(name), productDescription(description) {
    productNum = ++productCount;

    int month, year;
    getCurrentMonthAndYear(month, year);
    productCreationTime = "Created: " + std::to_string(month) + "/" + std::to_string(year);
}

void Product::setProductNum(int num) {
    productNum = num;
}

int Product::getProductNum() const {
    return productNum;
}

void Product::setProductName(const std::string& name) {
    productName = name;
}

std::string Product::getProductName() const {
    return productName;
}

void Product::setProductDescription(const std::string& description) {
    productDescription = description;
}

std::string Product::getProductDescription() const {
    return productDescription;
}

std::string Product::getProductCreationTime() const {
    return productCreationTime;
}

int Product::getProductCount() {
    return productCount;
}

void Product::displayProduct() const {
    std::cout << "Product Number: " << productNum << "\n"
              << "Name: " << productName << "\n"
              << "Description: " << productDescription << "\n"
              << productCreationTime << "\n";
}
