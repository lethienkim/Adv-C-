#include "main.h"

void getCurrentMonthAndYear(int& month, int& year) {
    time_t epochSeconds = time(NULL);
    tm tm_ptr;
    localtime_s(&tm_ptr, &epochSeconds);  // Safe version of localtime
    month = tm_ptr.tm_mon + 1;  // tm_mon is 0-11, so we add 1
    year = tm_ptr.tm_year + 1900;
}

int main() {
    std::vector<Customer> customers;
    std::vector<Order> orders;
    std::vector<Product> products;

    customers.emplace_back("John Doe", "123 Main St");
    customers.emplace_back("Jane Smith", "456 Oak Ave");

    products.emplace_back("Laptop", "15-inch screen, 8GB RAM");
    products.emplace_back("Smartphone", "5G compatible, 128GB storage");

    Order order1(customers[0].getCustID());
    order1.addProduct(products[0].getProductNum()); // Laptop
    orders.push_back(order1);
    customers[0].addOrder(order1.getOrderNum());

    Order order2(customers[1].getCustID());
    order2.addProduct(products[1].getProductNum()); // Smartphone
    orders.push_back(order2);
    customers[1].addOrder(order2.getOrderNum());

    outputReport(customers, orders, products);

    return 0;
}

void outputReport(const std::vector<Customer>& customers, const std::vector<Order>& orders, const std::vector<Product>& products) {
    std::cout << "\n\n--- Customers Report ---\n";
    for (const auto& customer : customers) {
        customer.displayCustomer();
        std::cout << "\n";
    }

    std::cout << "\n\n--- Orders Report ---\n";
    for (const auto& order : orders) {
        order.displayOrder();
        std::cout << "\n";
    }

    std::cout << "\n\n--- Products Report ---\n";
    for (const auto& product : products) {
        product.displayProduct();
        std::cout << "\n";
    }
}
