#include <iostream>
#include "Book.hpp"


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




int main(){
    TestBook();
    return 0;
}