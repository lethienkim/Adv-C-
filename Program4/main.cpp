#include "functions.h"

int main() {
    OverloadDemo obj1, obj2;

    // Get user input for the first object
    cout << "Input values for the first object (obj1):" << endl;
    obj1.input();

    // Get user input for the second object
    cout << "\nInput values for the second object (obj2):" << endl;
    obj2.input();

    cout << "\nInitial values:" << endl;
    cout << "Object 1: ";
    obj1.display();
    cout << "Object 2: ";
    obj2.display();

    // Demonstrating overloaded +
    cout << "\nPerforming addition (obj1 + obj2):" << endl;
    OverloadDemo obj3 = obj1 + obj2;
    obj3.display();

    // Demonstrating overloaded -
    cout << "\nPerforming subtraction (obj1 - obj2):" << endl;
    obj3 = obj1 - obj2;
    obj3.display();

    // Demonstrating overloaded *
    cout << "\nPerforming multiplication (obj1 * obj2):" << endl;
    obj3 = obj1 * obj2;
    obj3.display();

    // Demonstrating overloaded /
    cout << "\nPerforming division (obj1 / obj2):" << endl;
    obj3 = obj1 / obj2;
    obj3.display();

    // Demonstrating prefix ++ with assignment
    cout << "\nPrefix incrementing obj1 and assigning (obj1 = ++obj1):" << endl;
    obj1 = ++obj1;
    obj1.display();

    // Demonstrating postfix ++ with assignment
    cout << "\nPostfix incrementing obj1 and assigning (obj1 = obj1++):" << endl;
    obj1 = obj1++;
    obj1.display();

    // Demonstrating prefix -- with assignment
    cout << "\nPrefix decrementing obj1 and assigning (obj1 = --obj1):" << endl;
    obj1 = --obj1;
    obj1.display();

    // Demonstrating postfix -- with assignment
    cout << "\nPostfix decrementing obj1 and assigning (obj1 = obj1--):" << endl;
    obj1 = obj1--;
    obj1.display();

    return 0;
}
