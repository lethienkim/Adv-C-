#include "containers.h"


// Function to handle array container
void handleArray() {
    std::array<int, 5> arr;

    // Interactive input for the array
    std::cout << "Enter 5 integers for the array:\n";
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Enter element " << (i + 1) << ": ";
        std::cin >> arr[i];
    }

    // Display the array contents
    std::cout << "Array contents: ";
    for (const auto& el : arr) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    // Asking user for sorting or reversing the array
    std::cout << "Choose an operation:\n1. Sort\n2. Reverse\n3. No operation\n";
    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::sort(arr.begin(), arr.end());
        std::cout << "Array after sorting: ";
        break;

    case 2:
        std::reverse(arr.begin(), arr.end());
        std::cout << "Array after reversing: ";
        break;

    case 3:
        std::cout << "No operation chosen. Array remains the same: ";
        break;

    default:
        std::cout << "Invalid choice. Array remains the same: ";
        break;
    }

    // Display array after operation
    for (const auto& el : arr) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}
// Function to handle deque container
void handleDeque() {
    std::deque<int> dq;
    int value;
    char choice;

    do {
        std::cout << "Enter an integer to add to the deque: ";
        std::cin >> value;
        dq.push_back(value);
        std::cout << "Deque contents: ";
        for (const auto& el : dq) {
            std::cout << el << " ";
        }
        std::cout << std::endl;

        std::cout << "Do you want to add more (y/n)? ";
        std::cin >> choice;
    } while (choice == 'y');

    std::cout << "Choose an operation: \n1. Pop front\n2. Pop back\n";
    int op;
    std::cin >> op;
    if (op == 1) {
        dq.pop_front();
    }
    else if (op == 2) {
        dq.pop_back();
    }

    std::cout << "Deque after operation: ";
    for (const auto& el : dq) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

// Function to handle forward_list container
void handleForwardList() {
    std::forward_list<int> flist = { 1, 2, 3, 4, 5 };
    std::cout << "Forward List contents: ";
    for (const auto& el : flist) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

void handleList() {
    std::list<int> lst1, lst2;
    int value;
    char choice;

    // Populating lst1
    std::cout << "Populating List 1:\n";
    do {
        std::cout << "Enter an integer to add to the list: ";
        std::cin >> value;
        lst1.push_back(value);
        std::cout << "List 1 contents: ";
        for (const auto& el : lst1) {
            std::cout << el << " ";
        }
        std::cout << std::endl;

        std::cout << "Do you want to add more to List 1 (y/n)? ";
        std::cin >> choice;
    } while (choice == 'y');

    // Provide additional list operations
    std::cout << "Choose an operation:\n"
        << "1. Sort\n"
        << "2. Reverse\n"
        << "3. Merge another list\n"
        << "4. Remove duplicates\n"
        << "5. Splice from another list\n"
        << "6. Swap with another list\n";
    int op;
    std::cin >> op;

    switch (op) {
    case 1:
        lst1.sort();
        std::cout << "List after sorting: ";
        break;

    case 2:
        lst1.reverse();
        std::cout << "List after reversing: ";
        break;

    case 3:
        std::cout << "Populating List 2 for merge operation:\n";
        do {
            std::cout << "Enter an integer to add to List 2: ";
            std::cin >> value;
            lst2.push_back(value);
            std::cout << "List 2 contents: ";
            for (const auto& el : lst2) {
                std::cout << el << " ";
            }
            std::cout << std::endl;

            std::cout << "Do you want to add more to List 2 (y/n)? ";
            std::cin >> choice;
        } while (choice == 'y');

        lst1.sort();  // Ensure lists are sorted for merge
        lst2.sort();
        lst1.merge(lst2);
        std::cout << "List after merging with List 2: ";
        break;

    case 4:
        lst1.unique();
        std::cout << "List after removing duplicates: ";
        break;

    case 5:
        std::cout << "Populating List 2 for splice operation:\n";
        do {
            std::cout << "Enter an integer to add to List 2: ";
            std::cin >> value;
            lst2.push_back(value);
            std::cout << "List 2 contents: ";
            for (const auto& el : lst2) {
                std::cout << el << " ";
            }
            std::cout << std::endl;

            std::cout << "Do you want to add more to List 2 (y/n)? ";
            std::cin >> choice;
        } while (choice == 'y');

        lst1.splice(lst1.end(), lst2);  // Splice elements from lst2 to lst1
        std::cout << "List after splicing with List 2: ";
        break;

    case 6:
        std::cout << "Populating List 2 for swap operation:\n";
        do {
            std::cout << "Enter an integer to add to List 2: ";
            std::cin >> value;
            lst2.push_back(value);
            std::cout << "List 2 contents: ";
            for (const auto& el : lst2) {
                std::cout << el << " ";
            }
            std::cout << std::endl;

            std::cout << "Do you want to add more to List 2 (y/n)? ";
            std::cin >> choice;
        } while (choice == 'y');

        lst1.swap(lst2);  // Swap elements between lst1 and lst2
        std::cout << "List 1 after swapping with List 2: ";
        break;

    default:
        std::cout << "Invalid operation.\n";
        return;
    }

    for (const auto& el : lst1) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}


// Function to handle vector container
void handleVector() {
    std::vector<int> vec;
    int value;
    char choice;

    // Populating the vector
    do {
        std::cout << "Enter an integer to add to the vector: ";
        std::cin >> value;
        vec.push_back(value);
        std::cout << "Vector contents: ";
        for (const auto& el : vec) {
            std::cout << el << " ";
        }
        std::cout << std::endl;

        std::cout << "Do you want to add more (y/n)? ";
        std::cin >> choice;
    } while (choice == 'y');

    // Present options for operations
    std::cout << "Choose an operation: \n1. Sort\n2. Reverse\n";
    int op;
    std::cin >> op;

    if (op == 1) {
        std::sort(vec.begin(), vec.end());
        std::cout << "Vector after sorting: ";
    }
    else if (op == 2) {
        std::reverse(vec.begin(), vec.end());
        std::cout << "Vector after reversing: ";
    }

    for (const auto& el : vec) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

void handleSet() {
    std::set<int> mySet;
    int value;
    char choice;

    // Interactive input for the set
    do {
        std::cout << "Enter an integer to add to the set: ";
        std::cin >> value;
        mySet.insert(value);  // Insert value (duplicates will be ignored automatically)

        // Display current contents of the set
        std::cout << "Set contents: ";
        for (const auto& el : mySet) {
            std::cout << el << " ";
        }
        std::cout << std::endl;

        std::cout << "Do you want to add more to the set (y/n)? ";
        std::cin >> choice;
    } while (choice == 'y');

    // Final display after user has finished adding
    std::cout << "Final Set contents: ";
    for (const auto& el : mySet) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

void handleMultiset() {
    std::multiset<int> myMultiset;
    int value;
    char choice;

    // Interactive input for the multiset
    do {
        std::cout << "Enter an integer to add to the multiset: ";
        std::cin >> value;
        myMultiset.insert(value);  // Insert value (duplicates are allowed)

        // Display current contents of the multiset
        std::cout << "Multiset contents: ";
        for (const auto& el : myMultiset) {
            std::cout << el << " ";
        }
        std::cout << std::endl;

        std::cout << "Do you want to add more to the multiset (y/n)? ";
        std::cin >> choice;
    } while (choice == 'y');

    // Final display after user has finished adding
    std::cout << "Final Multiset contents: ";
    for (const auto& el : myMultiset) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

// Function to handle map container
void handleMap() {
    std::map<int, std::string> myMap;
    int key;
    std::string value;
    char choice;

    // Interactive input for the map
    do {
        std::cout << "Enter a key-value pair (int, string) to add to the map: ";
        std::cin >> key >> value;
        myMap[key] = value;

        // Display current contents of the map
        std::cout << "Map contents:\n";
        for (const auto& pair : myMap) {
            std::cout << pair.first << " -> " << pair.second << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Do you want to add more (y/n)? \n";
        std::cin >> choice;
    } while (choice == 'y');

    // Provide map operations11
    std::cout << "Choose an operation:\n1. Erase by key\n2. Clear map\n";
    int op;
    std::cin >> op;

    if (op == 1) {
        std::cout << "Enter key to erase: ";
        std::cin >> key;
        auto erased = myMap.erase(key);
        if (erased) {
            std::cout << "Key " << key << " erased successfully.\n";
        }
        else {
            std::cout << "Key " << key << " not found.\n";
        }
    }
    else if (op == 2) {
        myMap.clear();
        std::cout << "Map has been cleared.\n";
    }
    else {
        std::cout << "Invalid operation.\n";
    }

    // Final display of map contents
    std::cout << "Map after operation:\n";
    if (myMap.empty()) {
        std::cout << "Map is empty.\n";
    }
    else {
        for (const auto& pair : myMap) {
            std::cout << pair.first << " -> " << pair.second << std::endl;
        }
    }
}

// Function to handle multimap container
void handleMultimap() {
    std::multimap<int, std::string> myMultimap;
    myMultimap.insert({ 1, "One" });
    myMultimap.insert({ 2, "Two" });
    myMultimap.insert({ 1, "Another One" });

    std::cout << "Multimap contents:\n";
    for (const auto& pair : myMultimap) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
}

// Function to handle unordered_set container
void handleUnorderedSet() {
    std::unordered_set<int> uset = { 1, 2, 3, 4, 5 };
    std::cout << "Unordered Set contents: ";
    for (const auto& el : uset) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

// Function to handle unordered_multiset container
void handleUnorderedMultiset() {
    std::unordered_multiset<int> umset = { 1, 2, 3, 4, 5, 5 };
    std::cout << "Unordered Multiset contents: ";
    for (const auto& el : umset) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

// Function to handle unordered_map container
void handleUnorderedMap() {
    std::unordered_map<int, std::string> umap;
    umap[1] = "One";
    umap[2] = "Two";
    std::cout << "Unordered Map contents:\n";
    for (const auto& pair : umap) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
}

// Function to handle unordered_multimap container
void handleUnorderedMultimap() {
    std::unordered_multimap<int, std::string> ummap;
    ummap.insert({ 1, "One" });
    ummap.insert({ 2, "Two" });
    ummap.insert({ 1, "Another One" });

    std::cout << "Unordered Multimap contents:\n";
    for (const auto& pair : ummap) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
}

// Function to handle stack container
void handleStack() {
    std::stack<int> stk;
    int value;
    char choice;

    // Populating the stack
    do {
        std::cout << "Enter an integer to push to the stack: ";
        std::cin >> value;
        stk.push(value);
        std::cout << "Stack top: " << stk.top() << std::endl;

        std::cout << "Do you want to add more (y/n)? ";
        std::cin >> choice;
    } while (choice == 'y');

    // Present options for operations
    std::cout << "Choose an operation: \n1. Pop\n2. Clear stack\n";
    int op;
    std::cin >> op;

    if (op == 1) {
        stk.pop();
        std::cout << "Stack after pop, top: ";
        if (!stk.empty()) std::cout << stk.top();
        else std::cout << "Stack is empty";
        std::cout << std::endl;
    }
    else if (op == 2) {
        while (!stk.empty()) stk.pop();
        std::cout << "Stack is cleared." << std::endl;
    }
}

// Function to handle queue container adapter
void handleQueue() {
    std::queue<int> que;
    int value;
    char choice;

    // Populating the queue interactively
    do {
        std::cout << "Enter an integer to add to the queue: ";
        std::cin >> value;
        que.push(value);

        // Display current contents of the queue
        std::cout << "Queue contents (front to back): ";
        std::queue<int> tempQueue = que; // Copy the queue to display without modifying it
        while (!tempQueue.empty()) {
            std::cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        std::cout << std::endl;

        std::cout << "Do you want to add more to the queue (y/n)? ";
        std::cin >> choice;
    } while (choice == 'y');

    // Final display after user has finished adding
    std::cout << "Final Queue contents (front to back): ";
    while (!que.empty()) {
        std::cout << que.front() << " ";
        que.pop();
    }
    std::cout << std::endl;
}

// Function to handle priority_queue container adapter
void handlePriorityQueue() {
    std::priority_queue<int> pq;
    int value;
    char choice;

    // Populating the priority queue interactively
    do {
        std::cout << "Enter an integer to add to the priority queue: ";
        std::cin >> value;
        pq.push(value);

        // Display current contents of the priority queue by priority
        std::cout << "Priority Queue contents (highest priority first): ";
        std::priority_queue<int> tempQueue = pq; // Copy to display without modifying
        while (!tempQueue.empty()) {
            std::cout << tempQueue.top() << " ";
            tempQueue.pop();
        }
        std::cout << std::endl;

        std::cout << "Do you want to add more to the priority queue (y/n)? ";
        std::cin >> choice;
    } while (choice == 'y');

    // Final display after user has finished adding
    std::cout << "Final Priority Queue contents (highest priority first): ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;
}

