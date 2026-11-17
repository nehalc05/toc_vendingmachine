
#include "Product.h"
#include <iostream>
using namespace std;

ProductManager::ProductManager() {

    products[0] = {1, "Chips", 20, 5};
    products[1] = {2, "Chocolate", 30, 5};
    products[2] = {3, "Cold Drink", 40, 5};
    products[3] = {4, "Nachos", 25, 5};

}

void ProductManager::displayProducts() {

    cout << "\n===== VENDING MACHINE =====\n";

    for (int i = 0; i < 4; i++) {

        cout << products[i].id << ". "
             << products[i].name
             << " - Rs." << products[i].price
             << " | Stock: " << products[i].stock
             << endl;
    }
}

Product* ProductManager::getProduct(int id) {

    for (int i = 0; i < 4; i++) {

        if (products[i].id == id) {
            return &products[i];
        }
    }

    return NULL;
}

bool ProductManager::reduceStock(int id) {

    Product* product = getProduct(id);

    if (product != NULL && product->stock > 0) {

        product->stock--;
        return true;
    }

    return false;
}
