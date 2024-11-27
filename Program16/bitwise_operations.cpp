#include "operations.h"

void demonstrateBitwiseOperations() {
    unsigned int num1, num2;

    std::cout << "\n--- Bitwise Operations ---\n";
    std::cout << "Enter two non-negative integers: ";
    std::cin >> num1 >> num2;

    std::cout << "Binary representation:\n";
    std::cout << "num1: " << std::bitset<16>(num1) << "\n";
    std::cout << "num2: " << std::bitset<16>(num2) << "\n";

    std::cout << "\nBitwise AND: " << (num1 & num2) << " (" << std::bitset<16>(num1 & num2) << ")\n";
    std::cout << "Bitwise OR: " << (num1 | num2) << " (" << std::bitset<16>(num1 | num2) << ")\n";
    std::cout << "Bitwise XOR: " << (num1 ^ num2) << " (" << std::bitset<16>(num1 ^ num2) << ")\n";
    std::cout << "Bitwise NOT of num1: " << (~num1) << " (" << std::bitset<16>(~num1) << ")\n";
    std::cout << "Bitwise NOT of num2: " << (~num2) << " (" << std::bitset<16>(~num2) << ")\n";

    int shift;
    std::cout << "Enter the number of positions to shift num1 left: ";
    std::cin >> shift;
    std::cout << "Left shift (num1 << " << shift << "): " << (num1 << shift) << " (" << std::bitset<16>(num1 << shift) << ")\n";

    std::cout << "Enter the number of positions to shift num2 right: ";
    std::cin >> shift;
    std::cout << "Right shift (num2 >> " << shift << "): " << (num2 >> shift) << " (" << std::bitset<16>(num2 >> shift) << ")\n";
}
