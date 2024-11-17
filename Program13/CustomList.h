#ifndef CUSTOMLIST_H
#define CUSTOMLIST_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm> // Include this for std::find

template <typename T>
class CustomList {
private:
    std::vector<T> data;

public:
    void insertBeginning(const T& value);
    void insertEnd(const T& value);
    void deleteBeginning();
    void deleteEnd();
    void insertAtIndex(int index, const T& value);
    void deleteByValue(const T& value);
    void display() const;
};

#endif // CUSTOMLIST_H
