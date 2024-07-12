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

    Book* emptyBook = new Book();

    for (auto& book : books){
        if(book.first->getBarcode() == barcode){
            // std::cout<<"--- Found book with barcode: "<<barcode<<" ---"<<std::endl;
            return book.first;
        }
    }
    // std::cout<<"--- Book not found ---"<<std::endl;
    return emptyBook;
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
    std::cout<<"---Updated stock---"<<std::endl;
    print();
}

void Inventory::getTotalCost(){
    std::cout<<"Total Cost: $"<<totalCost<<std::endl;
}

std::map<Book*, int> Inventory::getAllBooks(){
    return books;
}

void Inventory::print(){
    std::cout<<"---Inventory---"<<std::endl;
    for (const auto& value : books){
        std::cout<<endl;
        std::cout<<"Barcode: "<<value.first->getBarcode()<<std::endl;
        std::cout<<"Title: "<<value.first->getTitle()<< std::endl;
        std::cout<<"Available Stock: "<<value.second<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"TotalCost: $"<<totalCost<<std::endl;
}


