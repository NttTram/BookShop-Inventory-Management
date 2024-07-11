#include <iostream>
#include "Book.hpp"
#include "Inventory.hpp"
#include <fstream>
#include <vector>
#include <string.h>
#include <limits>
#include <sstream>
#include <iomanip>
#include <math.h>
#include "MenuHandler.hpp"


//NEED CLEANING
void LoadData(Inventory* shelf){
    std::string file_path = "books.txt";
    std::ifstream data(file_path);

    
    if(data){
        std::string line;
        while(getline(data, line)){

            std::vector<std::string> splitted;
            std::string word;

            //Split input line into vector
            for(char ch : line)
            {
                std::string cmp;
                
                
                cmp += ch;

                if((cmp.compare(";") == 0) && (!word.empty()))
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
        std::cout<<"Could not open file: "<<file_path<<std::endl;
    }

    
}

void displayBooks( std::map<Book*, int> books){
    //Barcode, title, author, price
    clearConsole();
    // Resetting alignment to default
    std::cout << std::resetiosflags(std::ios::left);
    displayTitle("Books");
    
    std::cout<< setfill(' ') << 
                setw(10) << left<< "|Barcode" << 
                setw(50) << left << "|Title" << 
                setw(30) << left << "|Author" << 
                setw(9) << left << "|Price" << "|" << std::endl;
    std::cout<< setfill('-') << 
                    setw(10) << left << "+" <<
                    setw(50) << left << "+" <<
                    setw(30) << left << "+" <<
                    setw(10) << left << "+" << std::endl;
   
   for (const auto& value : books){
        int barcode = value.first->getBarcode();
        std::string title = value.first->getTitle();
        std::string author = value.first->getAuthor();
        double price = value.first->price;

        std::cout << std::setfill(' ')
                << "|#" << std::setw(8) << std::left << barcode 
                << "|" << std::setw(49) << std::left << title 
                << "|" << std::setw(29) << std::left << author 
                << "|$" << std::setw(7) << std::left << price 
                << "|" << std::endl;
        std::cout<< setfill('-') << 
                    setw(10) << left << "+" <<
                    setw(50) << left << "+" <<
                    setw(30) << left << "+" <<
                    setw(10) << left << "+" << std::endl;
   }



}





int main(){
    std::vector<MenuItem> data;
    bool exit = false;
    int userInput;

    Inventory* bookShelf= new Inventory();
    //TODO:: INVENTORY

    LoadData(bookShelf);
    std::map<Book*, int> books = bookShelf->getAllBooks();
    
    

    
    while(!exit){
        userInput = mainMenu(); 

        if(userInput == 6){ // OPTION:: EXIT
            exitMenu();
            exit = true;
        }
        else if(userInput == 5){ //OPTION:: ABOUT US
            aboutMenu();
        }
        else if(userInput == 4){ //OPTION:: CONTACT US
            contactMenu();
        }
        else if(userInput == 3){ //OPTION:: BUY BOOK

        }
        else if(userInput == 2){ //OPTION:: SEARCH BOOK

        }
        else if(userInput == 1){ //OPTION:: VIEW ALL BOOKS
            displayBooks(books);
            std::cout << "Enter any key to return" << std::endl;
            std::cin.get();
            clearCin();
        
        } else{

        }


    }

    return 0;
}