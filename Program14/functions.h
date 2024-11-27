#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <stdexcept>

class CustomList {
public:
    void insert_beginning(int value);
    void insert_end(int value);
    void delete_beginning();
    void delete_end();
    void insert_at(int index, int value);
    void delete_value(int value);
    int linear_search(int value);
    void selection_sort();
    void merge_sort();
    int binary_search(int value);
    void print_list() const;

private:
    std::vector<int> list;

    void merge_sort_recursive(int left, int right);
    void merge(int left, int mid, int right);
};

#endif // FUNCTIONS_H
