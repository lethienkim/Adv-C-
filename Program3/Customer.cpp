#include "Customer.h"

using namespace std;

// Initialize static member
int Customer::customerCount = 0;

// Constructor
Customer::Customer(string name, string address) : name(name), address(address) {
    custID = ++customerCount;

    // Get current time for customer creation
    time_t now = time(0);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &now);  // Use ctime_s for safer time conversion
    customerCreationTime = buffer;
}

// Setters and Getters
void Customer::setCustID(int id) {
    custID = id;
}

int Customer::getCustID() const {   // Definition of getCustID()
    return custID;
}

void Customer::setName(const string& name) {
    this->name = name;
}

string Customer::getName() const {
    return name;
}

void Customer::setAddress(const string& address) {
    this->address = address;
}

string Customer::getAddress() const {
    return address;
}

void Customer::addOrder(int orderNum) {
    orderNums.push_back(orderNum);
}

vector<int> Customer::getOrderNums() const {
    return orderNums;
}

string Customer::getCustomerCreationTime() const {
    return customerCreationTime;
}

int Customer::getCustomerCount() {
    return customerCount;
}

void Customer::displayCustomer() const {
    cout << "Customer ID: " << custID << "\n"
        << "Name: " << name << "\n"
        << "Address: " << address << "\n"
        << "Orders: ";
    for (int order : orderNums) {
        cout << order << " ";
    }
    cout << "\nCreated: " << customerCreationTime;
}
