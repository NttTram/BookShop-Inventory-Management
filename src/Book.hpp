#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <string>

using namespace std;
class Book;
class Book{
    int barcode;
    string title;
    string author;
    int year;
    
    public:
        double price; 
        Book(int barcode, string title, string author, int year, double price);
        ~Book();
        int getBarcode();
        string getTitle();
        string getAuthor();
        int getYear();
        
        void print();



    

};

#endif
