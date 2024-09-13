#ifndef ORDER_H
#define ORDER_H

#include <iostream>  // For input-output stream
#include <ctime>  // For time-related functions
#include <vector>    // For vector container
#include <string>

using namespace std;

class Order {
private:
    int orderNum;
    int custID;
    vector<int> productNums;
    string orderCreationTime;
    static int orderCount;

public:
    Order(int custID);

    // Setters and Getters
    void setOrderNum(int num);
    int getOrderNum() const;

    void setCustID(int id);
    int getCustID() const;

    void addProduct(int productNum);
    vector<int> getProductNums() const;

    string getOrderCreationTime() const;

    static int getOrderCount();

    void displayOrder() const;
};

#endif

