#include <iostream>
#include "Book.hpp"
#include "Inventory.hpp"

void TestBook(){
    //create Book
    Book *harry_potter = new Book(35474, "Harry Potter and The Three Pigs", "Tram Tran", 2002, 46.69);

    //call methods
    cout<<harry_potter->getTitle()<<endl;
    cout<<harry_potter->getAuthor()<<endl;
    cout<<harry_potter->getYear()<<endl;
    cout<<harry_potter->price<<endl;

    //print
    harry_potter->print();
    }

void TestInventory(){
    Inventory* bookshelf = new Inventory();
    Book *harry_potter = new Book(35474, "Harry Potter and The Three Pigs", "Tram Tran", 2002, 46.69);

    bookshelf->addBook(harry_potter, 1);
    if(bookshelf->findBook(harry_potter)){
        cout<<"Found book in inventory"<<endl;
    } else{
        cout<<"Book not found"<<endl;
    }

    bookshelf->updateStock(harry_potter, 3);
    bookshelf->print();
    bookshelf->removeBook(harry_potter);
    bookshelf->print();
}


int main(){
    TestInventory();
    return 0;
}