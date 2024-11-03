#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <iostream>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>

// Functions for handling sequence containers
void handleArray();
void handleDeque();
void handleForwardList();
void handleList();
void handleVector();

// Functions for handling ordered associative containers
void handleSet();
void handleMultiset();
void handleMap();
void handleMultimap();

// Functions for handling unordered associative containers
void handleUnorderedSet();
void handleUnorderedMultiset();
void handleUnorderedMap();
void handleUnorderedMultimap();

// Functions for handling container adapters
void handleStack();
void handleQueue();
void handlePriorityQueue();

#endif // CONTAINERS_H
