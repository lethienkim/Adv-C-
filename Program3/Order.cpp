#include "Order.h"

using namespace std;

// Initialize static member
int Order::orderCount = 0;

// Constructor
Order::Order(int custID) : custID(custID) {
    orderNum = ++orderCount;

    // Get current time for order creation
    time_t now = time(0);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &now);
    orderCreationTime = buffer;
}


// Setters and Getters
void Order::setOrderNum(int num) {
    orderNum = num;
}

int Order::getOrderNum() const {
    return orderNum;   // Ensure this function returns the correct orderNum
}

void Order::setCustID(int id) {
    custID = id;
}

int Order::getCustID() const {
    return custID;
}

void Order::addProduct(int productNum) {
    productNums.push_back(productNum);
}

vector<int> Order::getProductNums() const {
    return productNums;
}

string Order::getOrderCreationTime() const {
    return orderCreationTime;
}

int Order::getOrderCount() {
    return orderCount;
}

void Order::displayOrder() const {
    cout << "Order Number: " << orderNum << "\n"
        << "Customer ID: " << custID << "\n"
        << "Products: ";
    for (int product : productNums) {
        cout << product << " ";
    }
    cout << "\nCreated: " << orderCreationTime;
}
