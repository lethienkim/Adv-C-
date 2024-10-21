#include "customerMaster.h"

// Load customer data from CustomerMaster.txt
vector<Customer> loadCustomers() {
    vector<Customer> customers;
    ifstream file("CustomerMaster.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Customer customer;
            stringstream ss(line);
            getline(ss, customer.CustomerID, '%');
            getline(ss, customer.FirstName, '%');
            getline(ss, customer.LastName, '%');
            getline(ss, customer.StreetAddress, '%');
            getline(ss, customer.City, '%');
            getline(ss, customer.State, '%');
            getline(ss, customer.ZipCode, '%');
            customers.push_back(customer);
        }
        file.close();
    }
    else {
        cout << "Error opening CustomerMaster.txt file!" << endl;
    }
    return customers;
}

// List cities from customer data
void listCities(const vector<Customer>& customers) {
    map<string, bool> cities;
    for (const auto& customer : customers) {
        cities[customer.City] = true;
    }
    cout << "Cities in CustomerMaster.txt:\n";
    for (const auto& city : cities) {
        cout << city.first << endl;
    }
}

// List states from customer data
void listStates(const vector<Customer>& customers) {
    map<string, bool> states;
    for (const auto& customer : customers) {
        states[customer.State] = true;
    }
    cout << "States in CustomerMaster.txt:\n";
    for (const auto& state : states) {
        cout << state.first << endl;
    }
}

// List customers by city
void listCustomersInCity(const vector<Customer>& customers) {
    string city;
    cout << "Enter city: ";
    cin.ignore();
    getline(cin, city);
    cout << "Customers in " << city << ":\n";
    for (const auto& customer : customers) {
        if (customer.City == city) {
            cout << customer.FirstName << " " << customer.LastName << ", " << customer.StreetAddress << endl;
        }
    }
}

// List customers by state
void listCustomersInState(const vector<Customer>& customers) {
    string state;
    cout << "Enter state: ";
    cin.ignore();
    getline(cin, state);
    cout << "Customers in " << state << ":\n";
    for (const auto& customer : customers) {
        if (customer.State == state) {
            cout << customer.FirstName << " " << customer.LastName << ", " << customer.StreetAddress << endl;
        }
    }
}
