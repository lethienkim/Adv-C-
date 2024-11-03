#include "algorithms_demo.h"


// Function to display container contents
template <typename Container>
void displayContainer(const Container& container, const std::string& message) {
    std::cout << message << ": ";
    for (const auto& el : container) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

// Function to populate a vector based on user input
std::vector<int> getUserInputVector() {
    std::vector<int> vec;
    std::string input;
    std::cout << "Enter a series of integers separated by spaces: ";
    std::getline(std::cin, input);
    std::istringstream stream(input);
    int number;
    while (stream >> number) {
        vec.push_back(number);
    }
    return vec;
}


// 1. Modifying sequence algorithms
void demonstrateModifyingAlgorithms(std::vector<int>& vec) {
    std::vector<int> result(vec.size());

    // std::copy
    std::copy(vec.begin(), vec.end(), result.begin());
    displayContainer(result, "After std::copy");

    // std::transform (e.g., multiplying each element by 2)
    std::transform(vec.begin(), vec.end(), result.begin(), [](int n) { return n * 2; });
    displayContainer(result, "After std::transform");

    // std::remove (Prompting the user to input a number to remove)
    int numberToRemove;
    std::cout << "Enter an integer you would like to remove from the vector: ";
    std::cin >> numberToRemove;


    // Removing the specified element
    result.erase(std::remove(result.begin(), result.end(), numberToRemove), result.end());
    displayContainer(result, "After std::remove");


    // std::fill (Prompt the user for a fill value7)
    int fillValue;
    std::cout << "Enter an integer to fill the vector: ";
    std::cin >> fillValue;

    // Apply std::fill with the user's input
    std::fill(result.begin(), result.end(), fillValue);
    displayContainer(result, "After std::fill with user-defined value");

}

// 2. Non-modifying sequence algorithms
void demonstrateNonModifyingAlgorithms(std::vector<int>& vec) {
    // std::find with user input
    int findValue;
    std::cout << "Enter a value to search for in the vector: ";
    std::cin >> findValue;
    auto it = std::find(vec.begin(), vec.end(), findValue);
    if (it != vec.end()) {
        std::cout << "Found " << findValue << " in the vector.\n";
    }
    else {
        std::cout << findValue << " not found in the vector.\n";
    }

    // std::count with user input
    int countValue;
    std::cout << "Enter a value to count in the vector: ";
    std::cin >> countValue;
    int count = std::count(vec.begin(), vec.end(), countValue);
    std::cout << "Number of occurrences of " << countValue << ": " << count << std::endl;

    // std::equal with user-provided comparison vector
    int compareSize;
    std::cout << "Enter the number of elements for comparison vector: ";
    std::cin >> compareSize;
    std::vector<int> compareVec(compareSize);
    std::cout << "Enter " << compareSize << " elements for comparison vector: ";
    for (int& val : compareVec) {
        std::cin >> val;
    }
    if (std::equal(vec.begin(), vec.begin() + std::min(compareSize, static_cast<int>(vec.size())), compareVec.begin())) {
        std::cout << "The first part of the vector matches compareVec.\n";
    }
    else {
        std::cout << "The first part of the vector does not match compareVec.\n";
    }

    // std::search with user-defined subsequence
    int subSeqSize;
    std::cout << "Enter the size of the subsequence to search for: ";
    std::cin >> subSeqSize;
    std::vector<int> subsequence(subSeqSize);
    std::cout << "Enter " << subSeqSize << " elements for subsequence: ";
    for (int& val : subsequence) {
        std::cin >> val;
    }
    it = std::search(vec.begin(), vec.end(), subsequence.begin(), subsequence.end());
    if (it != vec.end()) {
        std::cout << "Subsequence found in the vector.\n";
    }
    else {
        std::cout << "Subsequence not found in the vector.\n";
    }
}

// 3. Sorting and related algorithms
void demonstrateSortingAlgorithms(std::vector<int>& vec) {
    // std::sort
    std::sort(vec.begin(), vec.end());
    displayContainer(vec, "After std::sort");

    // std::stable_sort with user input
    int vec2Size;
    std::cout << "Enter the number of elements for stable sort vector: ";
    std::cin >> vec2Size;
    std::vector<int> vec2(vec2Size);
    std::cout << "Enter " << vec2Size << " elements for stable sort vector: ";
    for (int& val : vec2) {
        std::cin >> val;
    }
    std::stable_sort(vec2.begin(), vec2.end());
    displayContainer(vec2, "After std::stable_sort");

    // std::partial_sort with user input
    int vec3Size;
    std::cout << "Enter the number of elements for partial sort vector: ";
    std::cin >> vec3Size;
    std::vector<int> vec3(vec3Size);
    std::cout << "Enter " << vec3Size << " elements for partial sort vector: ";
    for (int& val : vec3) {
        std::cin >> val;
    }
    std::partial_sort(vec3.begin(), vec3.begin() + std::min(3, vec3Size), vec3.end());
    displayContainer(vec3, "After std::partial_sort");

    // std::nth_element with user input
    int vec4Size;
    std::cout << "Enter the number of elements for nth_element vector: ";
    std::cin >> vec4Size;
    std::vector<int> vec4(vec4Size);
    std::cout << "Enter " << vec4Size << " elements for nth_element vector: ";
    for (int& val : vec4) {
        std::cin >> val;
    }
    std::nth_element(vec4.begin(), vec4.begin() + std::min(2, vec4Size - 1), vec4.end());
    displayContainer(vec4, "After std::nth_element");

    // std::binary_search with user input
    int searchValue;
    std::cout << "Enter a value to search in the sorted vector: ";
    std::cin >> searchValue;
    if (std::binary_search(vec.begin(), vec.end(), searchValue)) {
        std::cout << searchValue << " is present in the sorted vector.\n";
    }
    else {
        std::cout << searchValue << " is not present in the sorted vector.\n";
    }

    // std::merge with user input
    int vec5Size, vec6Size;

    // Prompt for first vector
    std::cout << "Enter the number of elements for the first vector to merge: ";
    std::cin >> vec5Size;
    std::vector<int> vec5(vec5Size);
    std::cout << "Enter " << vec5Size << " elements for the first merge vector: ";
    for (int& val : vec5) {
        std::cin >> val;
    }
    std::sort(vec5.begin(), vec5.end()); // Sort the first vector

    // Prompt for second vector
    std::cout << "Enter the number of elements for the second vector to merge: ";
    std::cin >> vec6Size;
    std::vector<int> vec6(vec6Size);
    std::cout << "Enter " << vec6Size << " elements for the second merge vector: ";
    for (int& val : vec6) {
        std::cin >> val;
    }
    std::sort(vec6.begin(), vec6.end()); // Sort the second vector

    // Merge the sorted vectors
    std::vector<int> merged(vec5Size + vec6Size);
    std::merge(vec5.begin(), vec5.end(), vec6.begin(), vec6.end(), merged.begin());
    displayContainer(merged, "After std::merge");
}

// 4. Numerical algorithms
void demonstrateNumericalAlgorithms(std::vector<int>& vec) {
    // 1. std::accumulate to calculate the sum of elements
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum of elements: " << sum << std::endl;

    // 2. std::inner_product to calculate the inner product of two vectors
    std::vector<int> vec2(vec.size());
    std::cout << "Enter " << vec.size() << " elements for the second vector to compute inner product: ";
    for (int& val : vec2) {
        std::cin >> val;
    }
    int product = std::inner_product(vec.begin(), vec.end(), vec2.begin(), 0);
    std::cout << "Inner product of the two vectors: " << product << std::endl;

    // 3. std::adjacent_difference to calculate the difference between adjacent elements
    std::vector<int> diff(vec.size());
    std::adjacent_difference(vec.begin(), vec.end(), diff.begin());
    std::cout << "Adjacent differences: ";
    for (const int& val : diff) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
