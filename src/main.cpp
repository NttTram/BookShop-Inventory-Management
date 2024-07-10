#include <iostream>

#include "Book.hpp"
#include "MenuHandler.hpp"


int main(){
    std::vector<MenuItem> data;
    bool exit = false;
    int userInput;






    ''
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

    }

    return 0;
}