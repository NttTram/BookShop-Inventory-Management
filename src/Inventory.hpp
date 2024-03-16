#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <iostream>
#include <map>
#include "Book.hpp"

using namespace std;
class Inventory;
class Inventory{

    map<Book*, int> books;
    double totalCost;

    public:
    Inventory();
    ~Inventory();

    void addBook(Book* book, int stock);
    void removeBook(Book* book);
    bool findBook(Book* book);
    int getStock(Book* book);
    void updateStock(Book* book, int addStock);
    
    void print();


};

#endif