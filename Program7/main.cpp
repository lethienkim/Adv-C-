#include "main.h"

int main() {
    processPhoneNumber();

    // Graceful exit
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.clear();
    cout << "\n\n<ENTER> to exit: ";
    cin.get();

    return 0;
}

