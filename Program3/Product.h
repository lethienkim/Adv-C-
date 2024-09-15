#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product {
private:
    int productNum;
    std::string productName;
    std::string productDescription;
    std::string productCreationTime;
    static int productCount;

public:
    Product(std::string productName, std::string productDescription);

    void setProductNum(int num);
    int getProductNum() const;

    void setProductName(const std::string& name);
    std::string getProductName() const;

    void setProductDescription(const std::string& description);
    std::string getProductDescription() const;

    std::string getProductCreationTime() const;

    static int getProductCount();

    void displayProduct() const;
};

#endif
