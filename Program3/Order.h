#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>

class Order {
private:
    int orderNum;
    int customerID;
    std::vector<int> productNums;
    std::string orderCreationTime;
    static int orderCount;

public:
    Order(int customerID);

    void setOrderNum(int num);
    int getOrderNum() const;

    void setCustomerID(int id);
    int getCustomerID() const;

    void addProduct(int productNum);
    std::vector<int> getProductNums() const;

    static int getOrderCount();

    void displayOrder() const;
};

#endif // ORDER_H
