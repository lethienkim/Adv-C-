#include "main.h"

void getCurrentMonthAndYear(int& month, int& year) {
    time_t epochSeconds = time(NULL);
    tm tm_ptr;
    localtime_s(&tm_ptr, &epochSeconds);  // Safe version of localtime
    month = tm_ptr.tm_mon + 1;  // tm_mon is 0-11, so we add 1
    year = tm_ptr.tm_year + 1900;
}

void getTime(int& day, int& month, int& year, int& hour, int& minute, int& second) {
    time_t epochSeconds = time(NULL);
    tm tm_ptr;
    localtime_s(&tm_ptr, &epochSeconds);  // Safe version of localtime
    day = tm_ptr.tm_mday;
    month = tm_ptr.tm_mon + 1;  // tm_mon is 0-11, so we add 1
    year = tm_ptr.tm_year + 1900;
    hour = tm_ptr.tm_hour;
    minute = tm_ptr.tm_min;
    second = tm_ptr.tm_sec;
}

void outputReport(const std::vector<Customer>& customers, const std::vector<Order>& orders, const std::vector<Product>& products) {
    std::cout << "\n\n--- Customers Report ---\n";
    for (const auto& customer : customers) {
        customer.displayCustomer();
    }

    std::cout << "\n\n--- Orders Report ---\n";
    for (const auto& order : orders) {
        order.displayOrder();
    }

    std::cout << "\n\n--- Products Report ---\n";
    for (const auto& product : products) {
        product.displayProduct();
    }
}

int main() {
    std::vector<Customer> customers;
    std::vector<Order> orders;
    std::vector<Product> products;

    bool running = true;
    while (running) {
        std::cout << "Please enter the number:\n";
        std::cout << "1. Add Customer\n2. Add Product\n3. Add Order\n4. View Reports\n5. Exit\n";
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // To ignore newline character left in the buffer

        switch (choice) {
            case 1: {
                std::string name, address;
                std::cout << "Enter customer name: ";
                std::getline(std::cin, name);
                std::cout << "Enter customer address: ";
                std::getline(std::cin, address);
                customers.emplace_back(name, address);
                std::cout << "Customer added successfully.\n";
                break;
            }
            case 2: {
                std::string name, description;
                std::cout << "Enter product name: ";
                std::getline(std::cin, name);
                std::cout << "Enter product description: ";
                std::getline(std::cin, description);
                products.emplace_back(name, description);
                std::cout << "Product added successfully.\n";
                break;
            }
            case 3: {
                int customerID;
                std::cout << "Enter customer ID: ";
                std::cin >> customerID;
                std::cin.ignore(); // To ignore newline character left in the buffer

                // Check if customerID is valid
                bool customerExists = false;
                for (const auto& customer : customers) {
                    if (customer.getCustID() == customerID) {
                        customerExists = true;
                        break;
                    }
                }

                if (!customerExists) {
                    std::cout << "Invalid customer ID.\n";
                    break;
                }

                Order order(customerID);
                int productID;
                std::cout << "Enter product IDs (0 to stop): ";
                while (true) {
                    std::cin >> productID;
                    if (productID == 0) break;
                    order.addProduct(productID);
                }
                std::cin.ignore(); // To ignore newline character left in the buffer
                orders.push_back(order);
                for (auto& customer : customers) {
                    if (customer.getCustID() == customerID) {
                        customer.addOrder(order.getOrderNum());
                        break;
                    }
                }
                std::cout << "Order added successfully.\n";
                break;
            }
            case 4:
                outputReport(customers, orders, products);
                break;
            case 5:
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
