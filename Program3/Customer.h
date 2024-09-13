#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream> // For input-output stream
#include <ctime>  // For time-related functions
#include <vector>    // For vector container
#include <string>

using namespace std;

class Customer {
private:
    int custID;
    string name;
    string address;
    vector<int> orderNums;
    string customerCreationTime;
    static int customerCount;

public:
    Customer(string name, string address);  // Constructor

    // Getters and setters
    void setCustID(int id);
    int getCustID() const;  // Declaration of getCustID()

    void setName(const string& name);
    string getName() const;

    void setAddress(const string& address);
    string getAddress() const;

    void addOrder(int orderNum);
    vector<int> getOrderNums() const;

    string getCustomerCreationTime() const;

    static int getCustomerCount();

    void displayCustomer() const;
};

#endif
