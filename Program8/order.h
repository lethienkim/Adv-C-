#ifndef ORDER_H
#define ORDER_H

#include <string>
#include "customerMaster.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;

// Structure to store order data
struct Order {
    std::string OrderID;
    std::string CustomerID;
    std::string ProductID;
    int Quantity;
    double OrderTotal;
};

// Function declarations related to order operations
void addOrder();
void listOrdersByCustomerID();
void listOrdersByZipCode();

#endif // ORDER_H
