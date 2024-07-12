#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class Book;
class Book{
    int barcode;
    std::string title;
    std::string author;
    int year;
    
    public:
        double price; 
        Book();
        Book(int barcode, std::string title, std::string author, int year, double price);
        ~Book();
        int getBarcode();
        std::string getTitle();
        std::string getAuthor();
        int getYear();
        
        void print();



    

};

#endif
