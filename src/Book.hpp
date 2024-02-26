#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <string>

using namespace std;
class Book;
class Book{
    int barcode;
    String title;
    String author;
    int year;
    
    public:
        double price; 
        int stock;

        String getTitle();
        String getAuthor();
        int getYear();
        double getPrice();



    

};

#endif
