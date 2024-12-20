#include "functions.h"
#include <algorithm>

void CustomList::insert_beginning(int value) {
    list.insert(list.begin(), value);
    is_sorted = false;
}

void CustomList::insert_end(int value) {
    list.push_back(value);
    is_sorted = false;
}

void CustomList::delete_beginning() {
    check_not_empty();
    list.erase(list.begin());
}

void CustomList::delete_end() {
    check_not_empty();
    list.pop_back();
}

void CustomList::insert_at(int index, int value) {
    if (index >= 0 && index <= static_cast<int>(list.size())) {
        list.insert(list.begin() + index, value);
        is_sorted = false;
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

void CustomList::delete_value(int value) {
    auto it = std::find(list.begin(), list.end(), value);
    if (it != list.end()) {
        list.erase(it);
        is_sorted = false;
    }
    else {
        throw std::invalid_argument("Value not found in list");
    }
}

int CustomList::linear_search(int value) {
    for (size_t i = 0; i < list.size(); ++i) {
        if (list[i] == value) {
            return i;
        }
    }
    return -1;
}

void CustomList::selection_sort() {
    for (size_t i = 0; i < list.size(); ++i) {
        size_t min_index = i;
        for (size_t j = i + 1; j < list.size(); ++j) {
            if (list[j] < list[min_index]) {
                min_index = j;
            }
        }
        std::swap(list[i], list[min_index]);
    }
    is_sorted = true;
}

void CustomList::merge_sort() {
    if (list.size() > 1) {
        merge_sort_recursive(0, list.size() - 1);
        is_sorted = true;
    }
}

int CustomList::binary_search(int value) {
    if (!is_sorted) {
        merge_sort();
    }
    int left = 0, right = list.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (list[mid] == value) {
            return mid;
        }
        else if (list[mid] < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

void CustomList::print_list() const {
    for (const auto& val : list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void CustomList::merge_sort_recursive(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_recursive(left, mid);
        merge_sort_recursive(mid + 1, right);
        merge(left, mid, right);
    }
}

void CustomList::merge(int left, int mid, int right) {
    std::vector<int> left_half(list.begin() + left, list.begin() + mid + 1);
    std::vector<int> right_half(list.begin() + mid + 1, list.begin() + right + 1);

    size_t i = 0, j = 0, k = left;
    while (i < left_half.size() && j < right_half.size()) {
        if (left_half[i] < right_half[j]) {
            list[k++] = left_half[i++];
        }
        else {
            list[k++] = right_half[j++];
        }
    }
    while (i < left_half.size()) {
        list[k++] = left_half[i++];
    }
    while (j < right_half.size()) {
        list[k++] = right_half[j++];
    }
}

void CustomList::check_not_empty() const {
    if (list.empty()) {
        throw std::out_of_range("List is empty");
    }
}
