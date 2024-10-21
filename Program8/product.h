#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;


// Structure to store product data
struct Product {
    std::string ProductID;
    std::string Description;
    double Price;
};

// Function declarations related to product operations
void addProduct();

#endif // PRODUCT_H
