#ifndef CUSTOMERMASTER_H
#define CUSTOMERMASTER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

// Structure to store customer data
struct Customer {
    std::string CustomerID;
    std::string FirstName;
    std::string LastName;
    std::string StreetAddress;
    std::string City;
    std::string State;
    std::string ZipCode;
};

// Function declarations related to customer operations
std::vector<Customer> loadCustomers();
void listCities(const std::vector<Customer>& customers);
void listStates(const std::vector<Customer>& customers);
void listCustomersInCity(const std::vector<Customer>& customers);
void listCustomersInState(const std::vector<Customer>& customers);

#endif // CUSTOMERMASTER_H
