#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include <string>

class Customer {
private:
    int custID;
    std::string name;
    std::string address;
    std::vector<int> orderNums;
    std::string customerCreationTime;
    static int customerCount;

public:
    Customer(std::string name, std::string address);

    void setCustID(int id);
    int getCustID() const;

    void setName(const std::string& name);
    std::string getName() const;

    void setAddress(const std::string& address);
    std::string getAddress() const;

    void addOrder(int orderNum);
    std::vector<int> getOrderNums() const;

    std::string getCustomerCreationTime() const;

    static int getCustomerCount();

    void displayCustomer() const;
};

#endif
