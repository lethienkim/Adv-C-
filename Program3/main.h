#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include <ctime>
#include "customer.h"
#include "order.h"
#include "product.h"

void getCurrentMonthAndYear(int& month, int& year);
void outputReport(const std::vector<Customer>& customers, const std::vector<Order>& orders, const std::vector<Product>& products);
void getTime(int& day, int& month, int& year, int& hour, int& minute, int& second);

#endif // MAIN_H
