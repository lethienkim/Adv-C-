#include "order.h"


// Add order to Orders.txt
void addOrder() {
    Order order;
    cout << "Enter Order ID: ";
    cin >> order.OrderID;
    cout << "Enter Customer ID: ";
    cin >> order.CustomerID;
    cout << "Enter Product ID: ";
    cin >> order.ProductID;
    cout << "Enter Quantity: ";
    cin >> order.Quantity;

    // Assuming we calculate OrderTotal based on product price from Products.txt
    ifstream prodFile("Products.txt");
    string line, productID;
    double price = 0.0;
    if (prodFile.is_open()) {
        while (getline(prodFile, line)) {
            stringstream ss(line);
            getline(ss, productID, '%');
            if (productID == order.ProductID) {
                string desc;
                ss.ignore(numeric_limits<streamsize>::max(), '%');
                ss >> price;
                break;
            }
        }
        prodFile.close();
    }
    order.OrderTotal = price * order.Quantity;

    ofstream file("Orders.txt", ios::app);
    if (file.is_open()) {
        file << order.OrderID << "%" << order.CustomerID << "%" << order.ProductID << "%" << order.Quantity << "%" << order.OrderTotal << endl;
        file.close();
        cout << "Order added successfully!" << endl;
    }
    else {
        cout << "Error opening Orders.txt file!" << endl;
    }
}

// List orders by customer ID
void listOrdersByCustomerID() {
    string customerID;
    cout << "Enter Customer ID: ";
    cin >> customerID;

    ifstream file("Orders.txt");
    if (file.is_open()) {
        string line;
        cout << "Orders for CustomerID " << customerID << ":\n";
        while (getline(file, line)) {
            stringstream ss(line);
            string orderID, custID, productID, quantity, total;
            getline(ss, orderID, '%');
            getline(ss, custID, '%');
            if (custID == customerID) {
                getline(ss, productID, '%');
                getline(ss, quantity, '%');
                getline(ss, total, '%');
                cout << "OrderID: " << orderID << ", ProductID: " << productID << ", Quantity: " << quantity << ", Total: " << total << endl;
            }
        }
        file.close();
    }
    else {
        cout << "Error opening Orders.txt file!" << endl;
    }
}

// List orders by customer ZipCode (loaded from CustomerMaster.txt)
void listOrdersByZipCode() {
    string zipCode;
    cout << "Enter Zip Code: ";
    cin >> zipCode;

    vector<Customer> customers = loadCustomers();
    vector<string> customerIDs;

    for (const auto& customer : customers) {
        if (customer.ZipCode == zipCode) {
            customerIDs.push_back(customer.CustomerID);
        }
    }

    ifstream file("Orders.txt");
    if (file.is_open()) {
        string line;
        cout << "Orders for ZipCode " << zipCode << ":\n";
        while (getline(file, line)) {
            stringstream ss(line);
            string orderID, custID, productID, quantity, total;
            getline(ss, orderID, '%');
            getline(ss, custID, '%');
            if (find(customerIDs.begin(), customerIDs.end(), custID) != customerIDs.end()) {
                getline(ss, productID, '%');
                getline(ss, quantity, '%');
                getline(ss, total, '%');
                cout << "OrderID: " << orderID << ", CustomerID: " << custID << ", ProductID: " << productID << ", Quantity: " << quantity << ", Total: " << total << endl;
            }
        }
        file.close();
    }
    else {
        cout << "Error opening Orders.txt file!" << endl;
    }
}
