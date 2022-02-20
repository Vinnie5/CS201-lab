#pragma once
#pragma once
#include <iostream>
#include <string>
#include <iomanip>

//small choclate order, will take remainder from medium and large
void small_orders(int choclate_order, int& large_order, int& medium_order, int& small_order,
    int& choclate_quantity_large) {
    int stock_l = choclate_quantity_large;

    if (choclate_order % 5 == 0) {
        large_order = stock_l - (stock_l - (choclate_order) / 5);
    }
    else {
        int difference = choclate_order % 5;
        large_order = stock_l - (stock_l - (choclate_order - difference) / 5);
        if (difference >= 3) {
            medium_order = 1;
            small_order = difference - 3;
        }
        else {
            small_order = difference;
        }
    }
}


//small choclate order, will take remainder from large
void medium_orders(int choclate_order, int& medium_order, int& small_order,
    int& choclate_quantity_medium) {

    int stock_m = choclate_quantity_medium;
    if (choclate_order % 3 == 0) {
        medium_order = stock_m - (stock_m - (choclate_order) / 3);
    }
    else {
        int difference = choclate_order % 3;
        medium_order = (choclate_order - difference) / 3;
        small_order = difference;
    }
}


void fill_order(int& choclate_quantity_large, int& choclate_quantity_medium,
    int& choclate_quantity_small, int& order_count)
{
        
    //consistent variables, prices and amount of choclate for each order
    const float choclate_price_large = 30.50f;
    const float choclate_price_medium = 25.99f;
    const float choclate_price_small = 10.50f;
    int large_order = 0;
    int medium_order = 0;
    int small_order = 0;

    int total_lbs_of_choclate = choclate_quantity_small + choclate_quantity_medium * 3 + choclate_quantity_large * 5;
    std::cout << std::endl;
    int choclate_order = 0;
    std::cout << "Please enter the number of pounds of choclate in the order: ";
    std::cin >> choclate_order;
    std::cin.clear();
    std::cin.ignore();


    //main logic to determain how many bars of choclate are need starting from the large to medium and small

    if (choclate_order < total_lbs_of_choclate) {
        if (choclate_order < (choclate_quantity_large * 5)) {
            small_orders(choclate_order, large_order, medium_order, small_order, choclate_quantity_large);
        }
        else if (choclate_order <= (choclate_quantity_large * 5) + (choclate_quantity_medium * 3)) {
            large_order = choclate_quantity_large;
            medium_orders(choclate_order - (choclate_quantity_large * 5), medium_order, small_order, choclate_quantity_medium);
        }
        else {
            large_order = choclate_quantity_large;
            medium_order = choclate_quantity_medium;
            small_order = choclate_order - ((choclate_quantity_large * 5) + (choclate_quantity_medium * 3));
        }

    }
    else {
        std::cout << "Your order can't be filled" << std::endl;
        return;
    }
    float shipping = 0.0f;
    
    //purchase subtoal
    float subTotal = (choclate_price_small * small_order) + (choclate_price_medium * medium_order) + (choclate_price_large * large_order);
    
    
    //shipping calculation
    float tax = subTotal * .075;
    if (choclate_order <= 10) {
        shipping = 5.25;
    }
    else if (choclate_order <= 20) {
        shipping = 7.75;
    }
    else if (choclate_order <= 50) {
        shipping = 12.25;
    }
    else {
        shipping = 19.75;
    }


    std::cout << "Choclate order #" << order_count << std::endl;
    std::cout << "Large Bar : " << std::setw(5) << std::right << large_order << " " << std::fixed << std::setprecision(2) << std::setw(10) << std::right << large_order * choclate_price_large << std::endl;
    std::cout << "Medium Bar: " << std::setw(5) << std::right << medium_order << " " << std::fixed << std::setprecision(2) << std::setw(10) << std::right << medium_order * choclate_price_medium << std::endl;
    std::cout << "Small Bar : " << std::setw(5) << std::right << small_order << " " << std::fixed << std::setprecision(2) << std::setw(10) << std::right << small_order * choclate_price_small << std::endl;
    std::cout << std::endl;
    std::cout << "Sub Total : " << std::setw(10) << std::right << subTotal << std::endl;
    std::cout << "Tax Total : " << std::setw(10) << std::right << tax << std::endl;
    std::cout << "Shipping  : " << std::setw(10) << std::right << shipping << std::endl;
    std::cout << "Total Cost: " << std::setw(10) << std::right << tax + subTotal + shipping << std::endl;

    choclate_quantity_large -= large_order;
    choclate_quantity_medium -= medium_order;
    choclate_quantity_small -= small_order;
    order_count += 1;
}


//prints current warehouse inventory
void print_inventory(int choclate_quantity_large, int choclate_quantity_medium, int choclate_quantity_small) {

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Choclate Inventory" << std::endl;
    std::cout << "Large Bars:  " << choclate_quantity_large << std::endl;
    std::cout << "Medium Bars: " << choclate_quantity_medium << std::endl;
    std::cout << "Small Bars:  " << choclate_quantity_small << std::endl;
    std::cout << std::endl;

}

//order inventory function, fills orders(addition)
void order_inventory(int& choclate_quantity_large, int& choclate_quantity_medium, int& choclate_quantity_small) {
    char order_choice;
    int bars_needed = 0;

    std::cout << "What size of bars should be ordered? (L, M, or S) " << std::endl;
    std::cin >> order_choice;
    std::cout << "How many bars are needed? ";
    std::cin >> bars_needed;

    if (tolower(order_choice) == 'l') {
        choclate_quantity_large += bars_needed;
    }

    else if (tolower(order_choice) == 'm') {
        choclate_quantity_medium += bars_needed;
    }

    else if (tolower(order_choice) == 's') {
        choclate_quantity_small += bars_needed;
    }
}