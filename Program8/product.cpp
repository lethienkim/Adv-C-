#include "product.h"

// Add product to Products.txt
void addProduct() {
    Product product;
    cout << "Enter Product ID: ";
    cin >> product.ProductID;
    cin.ignore();
    cout << "Enter Description: ";
    getline(cin, product.Description);
    cout << "Enter Price: ";
    cin >> product.Price;

    ofstream file("Products.txt", ios::app);
    if (file.is_open()) {
        file << product.ProductID << "%" << product.Description << "%" << product.Price << endl;
        file.close();
        cout << "Product added successfully!" << endl;
    }
    else {
        cout << "Error opening Products.txt file!" << endl;
    }
}
