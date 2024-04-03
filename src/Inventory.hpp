#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <iostream>
#include <map>
#include "Book.hpp"

using namespace std;
class Inventory;
class Inventory{

    map<Book *, int> books;
    double totalCost;

    public:
    
    Inventory();
    ~Inventory();
    
    void addBook(Book* book, int stock);
    void removeBook(int barcode);
    Book* getBook(int barcode);
    bool findBook(int barcode);
    int getStock(int barcode);
    void updateStock(int barcode, int addStock);
    void getTotalCost();
    
    void print();


};

#endif