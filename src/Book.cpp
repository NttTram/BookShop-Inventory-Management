#include "Book.hpp"

Book::Book(int barcode, string title, string author, int year, double price){
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
    cout<<"--------------------"<<endl;
    cout<<"Barcode: "<<barcode<<endl;
    cout<<"Title: "<<title<<endl;
    cout<<"Author: "<<author<<endl;
    cout<<"Year: "<<year<<endl;
    cout<<"Price: $"<<price<<endl;
}