#include "customer.h"
#include "main.h"  // Ensure this is included

int Customer::customerCount = 0;

// Constructor
Customer::Customer(std::string name, std::string address) : name(name), address(address) {
    custID = ++customerCount;

    // Get current month and year for customer creation
    int month, year;
    getCurrentMonthAndYear(month, year);
    customerCreationTime = "Created: " + std::to_string(month) + "/" + std::to_string(year);
}

// Setters and Getters
void Customer::setCustID(int id) {
    custID = id;
}

int Customer::getCustID() const {
    return custID;
}

void Customer::setName(const std::string& name) {
    this->name = name;
}

std::string Customer::getName() const {
    return name;
}

void Customer::setAddress(const std::string& address) {
    this->address = address;
}

std::string Customer::getAddress() const {
    return address;
}

void Customer::addOrder(int orderNum) {
    orderNums.push_back(orderNum);
}

std::vector<int> Customer::getOrderNums() const {
    return orderNums;
}

std::string Customer::getCustomerCreationTime() const {
    return customerCreationTime;
}

int Customer::getCustomerCount() {
    return customerCount;
}

void Customer::displayCustomer() const {
    std::cout << "Customer ID: " << custID << "\n"
              << "Name: " << name << "\n"
              << "Address: " << address << "\n"
              << "Orders: ";
    for (int order : orderNums) {
        std::cout << order << " ";
    }
    std::cout << "\n" << customerCreationTime;
}
