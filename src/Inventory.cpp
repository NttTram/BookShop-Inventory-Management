#include "Inventory.hpp"

Inventory::Inventory(){
    totalCost = 0;
}

void Inventory::addBook(Book* book, int stock){
    books[book] = stock;
    totalCost += stock * book->price;
}

void Inventory::removeBook(Book* book){
    books.erase(book);
}

bool Inventory::findBook(Book* book){
    if(books.find(book) == books.end())
        return false;

    return true;
}

int Inventory::getStock(Book* book){
    return books[book];
}

void Inventory::updateStock(Book* book, int addStock){
    books[book] += addStock;

    cout<<"---Updated stock---"<<endl;
    print();
}

void Inventory::print(){
    std::cout<<"---Inventory---"<<std::endl;
     for (const auto& value : books){
    std::cout<<endl;
      std::cout<<"Title: "<<value.first->getTitle()<< std::endl;
      std::cout<<"Available Stock: "<<value.second<<std::endl;
     }
     cout<<"TotalCost: $"<<totalCost<<endl;
}