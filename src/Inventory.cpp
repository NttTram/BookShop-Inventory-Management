#include "Inventory.hpp"

Inventory::Inventory(){
    totalCost = 0;
}

void addBook(int barcode);
void removeBook(int barcode);
bool findBook(int barcode);
int getStock(int barcode);
void updateStock(int barcode);

void print();