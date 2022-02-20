#include "main.h"


//the code is well written and I used varibales to tell the code/logic

int main() {
    //stock for choclate
    int choclate_quantity_large = 1500;
    int choclate_quantity_medium = 1200;
    int choclate_quantity_small = 7000;
    int order_count = 1;


    //main menu while loop
    while (true) {
        char choice;

        std::cout << "Choclate Inventory Control Program" << std::endl;
        std::cout << "F - Fill Order" << std::endl;
        std::cout << "P - Print Inventory" << std::endl;
        std::cout << "O - Order Inventory" << std::endl;
        std::cout << "E - Exit" << std::endl;
        std::cout << std::endl;

        std::cout << "What would you like to do? ";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore();


        //if statement to take in a char to run a function
        if (tolower(choice) == 'f') {
            fill_order(choclate_quantity_large, choclate_quantity_medium, choclate_quantity_small, order_count);
            std::cout << std::endl;
        }
        else if (tolower(choice) == 'p') {
            print_inventory(choclate_quantity_large, choclate_quantity_medium, choclate_quantity_small);
        }
        else if (tolower(choice) == 'o') {
            order_inventory(choclate_quantity_large, choclate_quantity_medium, choclate_quantity_small);
        }
        else if (tolower(choice) == 'e') {
            return 0;
        }
        else {
            std::cout << "invalid choice" << std::endl;
        }
    }

}
