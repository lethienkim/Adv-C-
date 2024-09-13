#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Product {
private:
    int productNum;
    string productName;
    string productDescription;
    string productCreationTime;
    static int productCount;

public:
    Product(string productName, string productDescription);  // Constructor

    // Getters and setters
    void setProductNum(int num);
    int getProductNum() const;

    void setProductName(const string& name);
    string getProductName() const;

    void setProductDescription(const string& description);
    string getProductDescription() const;

    string getProductCreationTime() const;

    static int getProductCount();

    void displayProduct() const;
};

#endif
