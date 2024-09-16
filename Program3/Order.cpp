#include "order.h"
#include "main.h"

int Order::orderCount = 0;

Order::Order(int customerID) : customerID(customerID) {
    orderNum = ++orderCount;

    int month, year;
    getCurrentMonthAndYear(month, year);
    orderCreationTime = "Created: " + std::to_string(month) + "/" + std::to_string(year);
}

void Order::setOrderNum(int num) {
    orderNum = num;
}

int Order::getOrderNum() const {
    return orderNum;
}

void Order::setCustomerID(int id) {
    customerID = id;
}

int Order::getCustomerID() const {
    return customerID;
}

void Order::addProduct(int productNum) {
    productNums.push_back(productNum);
}

std::vector<int> Order::getProductNums() const {
    return productNums;
}

int Order::getOrderCount() {
    return orderCount;
}

void Order::displayOrder() const {
    std::cout << "Order Number: " << orderNum << "\n"
              << "Customer ID: " << customerID << "\n"
              << "Products: ";
    for (int product : productNums) {
        std::cout << product << " ";
    }
    std::cout << "\n" << orderCreationTime << "\n";
}
