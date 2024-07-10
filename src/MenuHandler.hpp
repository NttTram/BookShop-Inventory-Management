#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
// IMPLEMENTATION:: Keeps Menu text clean

void clearConsole(){
    #ifdef _WIN32
        std:system("cls");
    #else
        //Assume Unix-like system
        std::system("clear");
    #endif
}

void clearCin(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

struct MenuItem {
    int id;
    std::string title;

    // Constructor
    MenuItem(int id, const std::string& title) : id(id), title(title){};
};

// Draw the screen with determined size
const int SCREEN_SIZE = 50;

/*
 * Display any menu with correct title and data.
 *
 * Parameters:
 * - title: Menu Title
 * - data: Data to display
 * 
 * Will be listed from 1 to dataSize (not sorted) 
*/

int displayMenu(const std::string& title, std::vector<MenuItem>& data)
{
    // Padding to center text in the middle of screen
    int padding = SCREEN_SIZE / 2;
    int titlePadding = (title.size() / 2) ;
    int centeringPadding = padding + titlePadding;
    
    int userInput;
    bool valid = false;

    while(!valid){
        // Display Menu
        std::cout << std::setfill('=') << std::setw(SCREEN_SIZE) << "" << std::endl;
        // std::cout << std::endl;
        std::cout << std::setfill(' ') << std::setw(centeringPadding) << title << "" << std::endl;
        // std::cout << std::endl;
        std::cout << std::setfill('=') << std::setw(SCREEN_SIZE) << "" << std::endl;

        //TODO:: DISPLAY DATA/MENU ITEMS
        int dataSize = data.size();
        for(int i = 0; i < dataSize; i++){
            std::cout << i + 1 << ". " << data[i].title << std::endl;
        }


        // Prompt user for input
        std::cout << std::setfill('=') << std::setw(SCREEN_SIZE) << "" << std::endl;
        std::cout << "Please enter the number of your choice: ";
        std::cin >> userInput;

        // Bound check below and above size'
        // Bound check fail = true;
        bool upperBoundFail = userInput > dataSize ? true : false;
        bool lowerBoundFail = userInput <= 0 ? true : false;

        // Validation for correct input
        if(cin.fail() || lowerBoundFail || upperBoundFail){
            clearCin();
            clearConsole();
        }else{
            valid = true;
        }
    }

    return userInput;

}



/*TODO::Main menu
    -->     1. View All Books
    -->     2. Search for a Book
    -->     3. Buy Book
    -->     ...
    -->     4. Contact us
    -->     5. About us
    -->     0. Exit

*/

void MainMenu(void){

    std::vector<MenuItem> menuList = {
        {1, "View All Books"},
        {2, "Search For A Book"},
        {3, "Buy Book"},
        {4, "Contact Us"},
        {5, "About Us"},
        {6, "Exit"}
    };
  


    int userInput = displayMenu("Main Menu", menuList);

}

/* TODO:: BuyMenu
    -->     Enter book ID:
    -->     *book details* if have in stock can buy
    -->     Enter quantity to buy:
*/
//TODO:: SearchBookMenu



