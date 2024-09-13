#include <iostream>
#include <vector>
#include "Customer.h"
#include "Order.h"
#include "Product.h"

using namespace std;

void outputReport(const vector<Customer>& customers, const vector<Order>& orders, const vector<Product>& products);

int main() {
    vector<Customer> customers;
    vector<Order> orders;
    vector<Product> products;

    // Adding new customers
    customers.emplace_back("John Doe", "123 Main St");
    customers.emplace_back("Jane Smith", "456 Oak Ave");

    // Adding new products
    products.emplace_back("Laptop", "15-inch screen, 8GB RAM");
    products.emplace_back("Smartphone", "5G compatible, 128GB storage");

    // Creating an order for John Doe (customerID 1)
    Order order1(customers[0].getCustID());
    order1.addProduct(products[0].getProductNum()); // Laptop
    orders.push_back(order1);
    customers[0].addOrder(order1.getOrderNum());

    // Creating an order for Jane Smith (customerID 2)
    Order order2(customers[1].getCustID());
    order2.addProduct(products[1].getProductNum()); // Smartphone
    orders.push_back(order2);
    customers[1].addOrder(order2.getOrderNum());

    outputReport(customers, orders, products);

    return 0;
}

void outputReport(const vector<Customer>& customers, const vector<Order>& orders, const vector<Product>& products) {
    cout << "\n\n--- Customers Report ---\n";
    for (const auto& customer : customers) {
        customer.displayCustomer();
        cout << "\n";
    }

    cout << "\n\n--- Orders Report ---\n";
    for (const auto& order : orders) {
        order.displayOrder();
        cout << "\n";
    }

    cout << "\n\n--- Products Report ---\n";
    for (const auto& product : products) {
        product.displayProduct();
        cout << "\n";
    }
}
