#include "Inventory.hpp"

Inventory::Inventory(){
    totalCost = 0;
}
Inventory::~Inventory(){
    for (auto& book : books){
        delete book.first;
    }
}

void Inventory::addBook(Book* book, int stock){
    books[book] = stock;
    totalCost += stock * book->price;
}

void Inventory::removeBook(int barcode){
    books.erase(getBook(barcode));
}

Book* Inventory::getBook(int barcode){
    for (auto& book : books){
        if(book.first->getBarcode() == barcode){
            cout<<"--- Found book with barcode: "<<barcode<<" ---"<<endl;
            return book.first;
        }
    }
    cout<<"--- Book not found ---"<<endl;

}

bool Inventory::findBook(int barcode){
    for (auto& book : books){
        if(book.first->getBarcode() == barcode){
            return true;
        }
    }
    return false;
}

int Inventory::getStock(int barcode){
    return books[getBook(barcode)];
}

void Inventory::updateStock(int barcode, int addStock){
    books[getBook(barcode)] += addStock;
    totalCost += addStock * getBook(barcode)->price;
    cout<<"---Updated stock---"<<endl;
    print();
}

void Inventory::getTotalCost(){
    cout<<"Total Cost: $"<<totalCost<<endl;
}

void Inventory::print(){
    std::cout<<"---Inventory---"<<std::endl;
    for (const auto& value : books){
        std::cout<<endl;
        std::cout<<"Barcode: "<<value.first->getBarcode()<<std::endl;
        std::cout<<"Title: "<<value.first->getTitle()<< std::endl;
        std::cout<<"Available Stock: "<<value.second<<std::endl;
    }
    cout<<endl;
    cout<<"TotalCost: $"<<totalCost<<endl;
}
