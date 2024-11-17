#include "CustomList.h"


// Insert at the beginning
template <typename T>
void CustomList<T>::insertBeginning(const T& value) {
    data.insert(data.begin(), value);
    std::cout << "Inserted " << value << " at the beginning." << std::endl;
}

// Insert at the end
template <typename T>
void CustomList<T>::insertEnd(const T& value) {
    data.push_back(value);
    std::cout << "Inserted " << value << " at the end." << std::endl;
}

// Delete from the beginning
template <typename T>
void CustomList<T>::deleteBeginning() {
    if (data.empty()) throw std::out_of_range("Cannot delete from an empty list.");
    T removedValue = data.front();
    data.erase(data.begin());
    std::cout << "Deleted " << removedValue << " from the beginning." << std::endl;
}

// Delete from the end
template <typename T>
void CustomList<T>::deleteEnd() {
    if (data.empty()) throw std::out_of_range("Cannot delete from an empty list.");
    T removedValue = data.back();
    data.pop_back();
    std::cout << "Deleted " << removedValue << " from the end." << std::endl;
}

// Insert at specified index
template <typename T>
void CustomList<T>::insertAtIndex(int index, const T& value) {
    if (index < 0 || index > data.size()) throw std::out_of_range("Index out of range.");
    data.insert(data.begin() + index, value);
    std::cout << "Inserted " << value << " at index " << index << "." << std::endl;
}

// Delete by value
template <typename T>
void CustomList<T>::deleteByValue(const T& value) {
    auto it = std::find(data.begin(), data.end(), value);
    if (it == data.end()) throw std::invalid_argument("Value not found in the list.");
    data.erase(it);
    std::cout << "Deleted node with value " << value << "." << std::endl;
}

// Display the list
template <typename T>
void CustomList<T>::display() const {
    std::cout << "Current List: ";
    for (const auto& item : data) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

// Explicit template instantiation
template class CustomList<int>;
template class CustomList<std::string>;
