#include <iostream>
#include "Book.hpp"
#include "Inventory.hpp"
#include <fstream>
#include <vector>
#include <string.h>


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



void LoadData(Inventory* shelf){
    string file_path = "books.txt";
    ifstream data(file_path);

    
    if(data){
        std::string line;
        while(getline(data, line)){

            std::vector<std::string> splitted;
            std::string word;

            //Split input line into vector
            for(char ch : line)
            {
                string cmp;
                cmp += ch;
                cmp += " ";

                if((cmp.compare("; ") == 0) && (!word.empty()))
                {
                    splitted.push_back(word);
                    word.clear();
                }
                else
                    word += ch;
            }
            if(!word.empty())
                splitted.push_back(word);

            //stock(int)[0] ,barcode(int)[1], title(string)[2], author(string)[3], year(int)[4], price(double)[5]
            shelf->addBook(new Book(stoi(splitted[1]), splitted[2], splitted[3], stoi(splitted[4]), stod(splitted[5])), stoi(splitted[0]));

        }
        data.close();
    }else{
        cout<<"Could not open file: "<<file_path<<endl;
    }

    
}

void WriteData(string text){
    //ofstream object
    std::ofstream fileOut;

    //open txt file and allow appending to txt file instead of writing the whole file
    fileOut.open("books.txt", std::ios::app);

    if(fileOut.is_open()){
        //Add txt to file: format stock; barcode; title; author; year; price
        fileOut << "\n";

        fileOut << text;
        

        //close file
        fileOut.close();
    }else{
        std::cerr<<"Unable to open file\n";
    }


}

int main(){
    // TestInventory();
    Inventory* book_shelf = new Inventory();
    string text = "Testing Writing function";
    WriteData(text);
    // LoadData(book_shelf);
    book_shelf->print();
    return 0;
}