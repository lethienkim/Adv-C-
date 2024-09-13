/*
 * File: GameOfThrones.cpp
 * Description: This implementation file provides the definitions for the methods declared
 *              in the `GameOfThrones.h` header file. The file includes:
 *              - Implementation of `TwoDArray` template class methods.
 *              - Implementation of `ParallelVectors` template class methods.
 *              - Explicit template instantiations for `TwoDArray<string>` and `ParallelVectors<string>`.
 */

#include "GameOfThrones.h"

 // Implementing methods for TwoDArray class
template <typename T>
TwoDArray<T>::TwoDArray(int r, int c) : rows(r), cols(c) {}

template <typename T>
void TwoDArray<T>::set(int row, int col, T value) {
    data[row][col] = value;
}

template <typename T>
T TwoDArray<T>::get(int row, int col) const {
    return data[row][col];
}

template <typename T>
void TwoDArray<T>::display() const {
    for (int i = 0; i < rows; i++) {
        if (!data[i][0].empty()) {
            cout << "Character: " << data[i][0] << endl;
            for (int j = 1; j < cols && !data[i][j].empty(); j++) {
                cout << "  Dragon: " << data[i][j] << endl;
            }
        }
    }
}

// Implementing methods for ParallelVectors class
template <typename T>
void ParallelVectors<T>::add(T kingdom, int size) {
    kingdomNames.push_back(kingdom);
    armySizes.push_back(size);
}

template <typename T>
void ParallelVectors<T>::display() const {
    for (size_t i = 0; i < kingdomNames.size(); i++) {
        cout << "Kingdom: " << kingdomNames[i] << ", Army Size: " << armySizes[i] << endl;
    }
}

// Explicit template instantiations
template class TwoDArray<string>;
template class ParallelVectors<string>;
