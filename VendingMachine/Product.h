
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    int price;
    int stock;
};

class ProductManager {
private:
    Product products[4];

public:
    ProductManager();

    void displayProducts();

    Product* getProduct(int id);

    bool reduceStock(int id);
};

#endif
