
#include <iostream>
#include "Product.h"
using namespace std;

int main() {

    ProductManager manager;

    manager.displayProducts();

    Product* selected = manager.getProduct(2);

    if (selected != NULL) {
        cout << "\nSelected: " << selected->name << endl;
    }

    manager.reduceStock(2);

    manager.displayProducts();

    return 0;
}
