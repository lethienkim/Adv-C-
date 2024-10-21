#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include "customerMaster.h"
#include "product.h"
#include "order.h"

using namespace std;

// Function declarations for menu operations
void addProduct();
void addOrder();
void listCities(const std::vector<Customer>& customers);
void listStates(const std::vector<Customer>& customers);
void listCustomersInCity(const std::vector<Customer>& customers);
void listCustomersInState(const std::vector<Customer>& customers);
void listOrdersByCustomerID();
void listOrdersByZipCode();
std::vector<Customer> loadCustomers();

#endif // MAIN_H
