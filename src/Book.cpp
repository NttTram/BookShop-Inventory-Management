#include "Book.hpp"
Book::Book(){
    barcode = 0;
    title = "N/A";
    author = "N/A";
    year = 0;
    price = 0.00;
}
Book::Book(int barcode, std::string title, std::string author, int year, double price){
    this->barcode = barcode;
    this->title = title;
    this->author = author;
    this->year = year;
    this->price = price;
}
Book::~Book(){
    
}
int Book::getBarcode(){
    return barcode;
}
string Book::getTitle(){
    return title;
}
string Book::getAuthor(){
    return author;
}
int Book::getYear(){
    return year;
}

void Book::print(){
    std::cout<<"--------------------"<<std::endl;
    std::cout<<"Barcode: "<<barcode<<std::endl;
    std::cout<<"Title: "<<title<<std::endl;
    std::cout<<"Author: "<<author<<std::endl;
    std::cout<<"Year: "<<year<<std::endl;
    std::cout<<"Price: $"<<price<<std::endl;
}