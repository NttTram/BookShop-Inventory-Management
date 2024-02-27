#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <iostream>
#include "Book.hpp"

using namespace std;
class Inventory;
class Inventory{

    map<Book, int> books;
    double totalCost;

    public:

    void addBook(int barcode);
    void removeBook(int barcode);
    bool findBook(int barcode);
    int getStock(int barcode);
    void updateStock(int barcode);
    
    void print();


};

#endif