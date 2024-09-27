/*
 * File: GameOfThrones.h
 * Description: This header file defines two template classes, `TwoDArray` and `ParallelVectors`,
 *              for handling a 2D array of generic data and parallel vectors for kingdom and army data.
 *              - `TwoDArray`: Manages a fixed-size 2D array for storing character and dragon data.
 *              - `ParallelVectors`: Manages two parallel vectors for storing kingdom names and their respective army sizes.
 */

#ifndef GAMEOFTHRONES_H
#define GAMEOFTHRONES_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Template class for 2D array to handle character and dragon data
template <typename T>
class TwoDArray {
private:
    T data[10][10];
    int rows, cols;

public:
    TwoDArray(int r, int c);
    void set(int row, int col, T value);
    T get(int row, int col) const;
    void display() const;
};

// Template class for parallel vectors to handle kingdom and army data
template <typename T>
class ParallelVectors {
private:
    vector<T> kingdomNames;
    vector<int> armySizes;

public:
    void add(T kingdom, int size);
    void display() const;
};

#endif


