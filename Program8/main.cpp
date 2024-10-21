#include "main.h"

int main() {
    vector<Customer> customers = loadCustomers();
    bool running = true;
    while (running) {
        int choice;
        cout << "\nMenu:\n";
        cout << "1. Add Product\n";
        cout << "2. Add Order\n";
        cout << "3. List Cities\n";
        cout << "4. List States\n";
        cout << "5. List Customers in a City\n";
        cout << "6. List Customers in a State\n";
        cout << "7. List Orders by Customer ID\n";
        cout << "8. List Orders by ZipCode\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            addOrder();
            break;
        case 3:
            listCities(customers);
            break;
        case 4:
            listStates(customers);
            break;
        case 5:
            listCustomersInCity(customers);
            break;
        case 6:
            listCustomersInState(customers);
            break;
        case 7:
            listOrdersByCustomerID();
            break;
        case 8:
            listOrdersByZipCode();
            break;
        case 0:
            running = false;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

        if (running) {
            char anotherRequest;
            cout << "Do you have another request? (y/n): ";
            cin >> anotherRequest;
            if (anotherRequest == 'n' || anotherRequest == 'N') {
                running = false;
            }
        }
    }

    return 0;
}
