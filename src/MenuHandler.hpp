#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>

// Draw the screen with determined size
const int SCREEN_SIZE = 100;


// IMPLEMENTATION:: Keeps Menu text clean
void clearConsole(){
    #ifdef _WIN32
        if (system("cls") != 0) {
            std::cerr << "Failed to clear the console using 'cls'" << std::endl;
        }
    #elif defined(__linux__) || defined(__APPLE__)
        if (system("clear") != 0) {
            std::cerr << "Failed to clear the console using 'clear'" << std::endl;
        }
    #else
        std::cerr << "Unsupported OS" << std::endl;
    #endif
}

// IMPLEMENTATION:: Clear cin to accept next input
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


// IMPLEMENTATION:: Space out text to the middle of screen
int centerPad(const std::string& title){
    
    int padding = SCREEN_SIZE / 2;
    int titlePadding = (title.size() / 2) ;
    int centeringPadding =  padding - titlePadding;


    return centeringPadding;
}

// IMPLEMENTATION:: Display menu Title
void displayTitle(const std::string& title){
    int centerPadding = centerPad(title);

    // Display Menu Title
        std::cout << std::setfill('=') << std::setw(SCREEN_SIZE) << "" << std::endl;
        // std::cout << std::endl;
        std::cout << std::setfill(' ') << std::setw(centerPadding) << "" << title << std::endl;
        // std::cout << std::endl;
        std::cout << std::setfill('=') << std::setw(SCREEN_SIZE) << "" << std::endl;
}


// IMPLEMENTATION:: Display data/menu items
void displayMenuItem(std::vector<MenuItem>& data){
    int dataSize = data.size();
    for(int i = 0; i < dataSize; i++){
        std::cout << i + 1 << ". " << data[i].title << std::endl;
    }

}

// IMPLEMENTATION:: Prompt user for input with validation 
void userPrompt(bool& valid, int& userInput, int dataSize){
        std::cout << std::setfill('=') << std::setw(SCREEN_SIZE) << "" << std::endl;
        std::cout << "Please enter the number of your choice: ";
        std::cin >> userInput;

        // Bound check below and above size. Bound check fail = true;
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



/*
 * Display menu with a title and data (MenuItem).
 *
 * Parameters:
 * - title: Menu Title
 * - data: Data to display
 * 
 * Will be listed from 1 to dataSize (not sorted) 
*/
int displayMenu(const std::string& title, std::vector<MenuItem>& data){
   
    int dataSize = data.size();
    
    int userInput;
    bool valid = false;

    while(!valid){
        clearConsole();
        displayTitle(title);
        displayMenuItem(data);
        userPrompt(valid, userInput, dataSize);
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


int mainMenu(void){

    std::vector<MenuItem> menuList = {
        {1, "View All Books"},
        {2, "Search For A Book"},
        {3, "Buy Book"},
        {4, "Contact Us"},
        {5, "About Us"},
        {6, "Exit"}
    };

  
    return displayMenu("Main Menu", menuList);
}

/* TODO:: BuyMenu
    -->     Enter book ID:
    -->     *book details* if have in stock can buy
    -->     Enter quantity to buy:
*/

void buyMain(void){
    
}



//TODO:: CONTACT US MENU
void contactMenu(void){
    clearConsole();
    std::string storeName = "Tram's BookStore";
    std::string contactNumber = "0349782364";
    std::string email = "contact.tram.bookstore@gmail.com";
    std::string dummyInput;

    displayTitle("Contact Us");


    std::cout << "Store Name: " << storeName << std::endl;
    std::cout << "Contact Number: " << contactNumber << std::endl;
    std::cout << std::endl;
    std::cout << "Email us for any enquires: " << email << std::endl;
    std::cout << std::endl;

    std::cout << "Enter any key to return" << std::endl;
    std::cin.get();
    clearCin();

    
}

//TODO:: EXIT
void exitMenu(void){
    clearConsole();
    displayTitle("Thank you for using our services. See you again!");
}
//TODO:: SearchBookMenu




//TODO:: ABOUT US MENU
void aboutMenu(void){
    clearConsole();
    displayTitle("About Us");

    std::cout 
            << "Tram's BookStore is just a place for Tram and everyone to chill.\n"
            << "Come join us and get away from whatever is stressing you.\n";

    std::cout << std::endl;
    std::cout << "Enter any key to return" << std::endl;
    std::cin.get();
    clearCin();

}


