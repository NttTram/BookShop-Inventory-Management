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

// IMPLEMENTATION:: Load data from .txt to Inventory
void LoadData(Inventory* shelf){
    std::string file_path = "books.txt";
    std::ifstream data(file_path);

    if(data){
        std::string line;
        while(getline(data, line)){

            std::vector<std::string> splitted;
            std::string word;

            std::istringstream iss(line);
            while(getline(iss, word, ';')){
                splitted.push_back(word);
            }
            
            int stock = std::stoi(splitted[0]);
            int barcode = std::stoi(splitted[1]);
            std::string title = splitted[2];
            std::string author = splitted[3];
            int year = std::stoi(splitted[4]);
            double price = std::stod(splitted[5]);

            shelf->addBook(new Book(barcode, title, author, year, price), stock);
 
        }
        data.close();
    }else{
        std::cerr << "Could not open file: " << file_path << std::endl;
    }

    
}

void pressToContinue(void){
    clearCin();
    std::cout << "Enter any key to continue" << std::endl;
    clearCin();
}

void pressToReturn(void){
    std::cout << "Enter any key to return" << std::endl;
    std::cin.get();
    clearCin();
}

void displayBooks( std::map<Book*, int> books){
    //Barcode, title, author, price
    clearConsole();
    // Resetting alignment to default
    std::cout << std::resetiosflags(std::ios::left);
    displayTitle("Books");
    
    std::cout<< setfill(' ') << 
                setw(10) << left<< "|Barcode" 
                << setw(50) << left << "|Title" 
                << setw(30) << left << "|Author" 
                << setw(9) << left << "|Price" 
                << "|" << std::endl;

    std::cout<< setfill('-') << 
                    setw(10) << left << "+" <<
                    setw(50) << left << "+" <<
                    setw(30) << left << "+" <<
                    setw(10) << left << "+" << std::endl;
   
   // NICE HACK WITH THE [BOOK, STOCK]
   for (const auto& [book, stock] : books){
        
        std::cout << std::setfill(' ')
                << "|#" << std::setw(8) << std::left << book->getBarcode() 
                << "|" << std::setw(49) << std::left << book->getTitle()
                << "|" << std::setw(29) << std::left << book->getAuthor() 
                << "|$" << std::setw(7) << std::left << book->price 
                << "|" << std::endl;
        std::cout<< setfill('-') << 
                    setw(10) << left << "+" <<
                    setw(50) << left << "+" <<
                    setw(30) << left << "+" <<
                    setw(10) << left << "+" << std::endl;
   }
}

void displayCart(std::map<Book*, int> cart){
     //Barcode, title, author, price
    // clearConsole();
    double totalCost = 0;
    // Resetting alignment to default
    std::cout << std::resetiosflags(std::ios::left);
    displayTitle("Shopping Cart");
    
    std::cout<< setfill(' ') 
                << setw(10) << left<< "|Barcode" 
                << setw(50) << left << "|Title" 
                << setw(30) << left << "|Author" 
                << setw(9) << left << "|Price" 
                << "|" << std::endl;

    std::cout<< setfill('-') << 
                    setw(10) << left << "+" <<
                    setw(50) << left << "+" <<
                    setw(30) << left << "+" <<
                    setw(10) << left << "+" << std::endl;
   
    for (const auto& [book, stock] : cart){

        std::cout << std::setfill(' ')
                << "|#" << std::setw(8) << std::left << book->getBarcode() 
                << "|" << std::setw(49) << std::left << book->getTitle() 
                << "|" << std::setw(29) << std::left << book->getAuthor() 
                << "|$" << std::setw(7) << std::left << book->price 
                << "|" << std::endl;

        std::cout << setfill('-') << 
                    setw(10) << left << "+" <<
                    setw(50) << left << "+" <<
                    setw(30) << left << "+" <<
                    setw(10) << left << "+" << std::endl;
        
        totalCost += book->price; //THIS ONLY ADD ONE BOOK. NO OPTION FOR BUY BOOK QUANTITY
    }
    std::cout << setfill(' ') << "|" << setw(91) <<right << "|Total Cost:$" <<setw(7) << left << totalCost << "" << "|" << std::endl;

    std::cout<< setfill('-') << "+" <<
                setw(79) << right << "+" <<
                setw(20) << right << "+" << std::endl;

    // Resetting alignment to default
    std::cout << std::resetiosflags(std::ios::left);
    std::cout << setfill(' ')<< ""; 

}



void searchBook(Inventory* bookShelf){
    int barcode = 0;
    bool valid = false;
    while(!valid){
        try
        {
            clearConsole();
            displayTitle("Search For A Book");
            
            std::cout << "0. Return\n\n\n\nEnter book barcode: ";
            std::cin >> barcode;

            if(std::cin.fail()){
                throw std::invalid_argument("Invalid input: not an integer.");
            }

            if(barcode != 0){
                bool foundBook = bookShelf->findBook(barcode);
                if(foundBook){
                    Book* book = bookShelf->getBook(barcode);
                    displayTitle("Found Book: " + book->getTitle());
                    book->print();

                }else{
                    throw std::runtime_error("Book not found!");
                }
                
                pressToReturn();
            }

            valid = true;
        }
        catch(const std::invalid_argument& e)
        {
            std::cerr << "Error:: " << e.what() << '\n';
            pressToContinue();

        }
        catch(const std::runtime_error& e){
            
            std::cerr << "Error:: " << e.what() << '\n';
            pressToContinue();

        }
    }
        

}


void addBookToCart(std::map<Book*, int>& cart, Inventory* bookShelf){
    bool done = false;
    while(!done){
        try{
            clearConsole();
            displayCart(cart);  
            int barcode;
            std::cout << "0. Done\n\n\n";
            std::cout << "Enter book barcode: ";
            std::cin >> barcode;

            if(std::cin.fail()) throw std::invalid_argument("Invalid input: not an integer.");
            
            if(barcode != 0){
                
                bool foundBook = bookShelf->findBook(barcode);

                if(foundBook){
                    int stock = bookShelf->getStock(barcode);

                    if(stock <= 0){
                        throw std::runtime_error("Out of stock!");
                    }else{
                        Book* book = bookShelf->getBook(barcode);
                        displayTitle("Found Book: " + book->getTitle());
                        book->print();
                        cart[book] = stock;
                        
                    }

                }else{
                    throw std::runtime_error("Book not found!");
                }
                
                pressToReturn();
            } else if(barcode == 0){
                done = true;
            }

        }
        catch(const std::invalid_argument& e)
        {
            
            std::cerr << "Error:: " << e.what() << '\n';
            pressToContinue();
        }
        catch(const std::runtime_error& e){
            
            std::cerr << "Error:: " << e.what() << '\n';
            pressToContinue();
        }

    }
    
}



int main(){
    // std::vector<MenuItem> data;
    bool exit = false;
    int userInput;

    Inventory* bookShelf = new Inventory();
    //TODO:: INVENTORY
    LoadData(bookShelf);

    std::map<Book*, int> cart;
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

            bool valid = false;
            while(!valid){
                int input = buyMenu();
                try{
                    if(input == 1){ //OPTION:: ADD BOOK TO CART
                        addBookToCart(cart, bookShelf);
                    }
                    else if(input == 2){ //OPTION:: CHECK CART
                        displayCart(cart); 
                        pressToReturn();
                    }
                    else if(input == 3){ //OPTION:: CHECKOUT
                        displayCart();
                        
                    }
                    else if(input == 4){ //OPTION:: RETURN
                        valid = true;
                    }
                    else{
                        std::cerr << "Invalid option" << std::endl;
                    }
                }
                catch(const std::invalid_argument& e)
                {
                    // clearCin();
                    std::cerr << "Error:: " << e.what() << '\n';
                    pressToContinue();
                }
                catch(const char* e){
                    // clearCin();
                    std::cerr << "Error:: " << e << '\n';
                    pressToContinue();
                }
            }
        

        }
        else if(userInput == 2){ //OPTION:: SEARCH BOOK
            searchBook(bookShelf);

        }
        else if(userInput == 1){ //OPTION:: VIEW ALL BOOKS
            displayBooks(books);
            pressToReturn();
        
        } else{
            std::cerr << "Invalid option" << std::endl;
        }


    }

    delete bookShelf;

    return 0;
}