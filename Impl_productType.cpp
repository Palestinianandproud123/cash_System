#include "Interface_productType.h"
#include <iostream>
#include <iomanip>

void productType::set_productName(std::string product_name) { 
    productName = product_name;
} 

std::string productType::get_productName() const {
    return productName;
}

void productType::set_productQuantity(int product_quantity) {
    if (product_quantity >= 1) {
        productQuantity = product_quantity;
    } else {
        productQuantity = 0;
    }
}

int productType::get_productQuantity() const {
    return productQuantity;
}

void productType::set_productPrice(float product_price) {
    if (product_price > 0) {
        productPrice = product_price;
    } else {
        productPrice = 0;
    }
}

float productType::get_productPrice() const {
    return productPrice;
}

float productType::Total() const {
    return (productQuantity * productPrice);
}

void productType::print() {
    std::cout << std::setw(25) << std::left  << std::setfill(' ') << "product Name "
              << std::setw(20) << std::left  << std::setfill(' ') << "product price "
              << std::setw(20) << std::left  << std::setfill(' ') << "product Quantity"
              << std::setw(20) << std::left  << std::setfill(' ') << " product total "
              << std::endl;
    
    std::cout << " " << std::setw(25) << std::left << productName
              << " " << std::setw(20) << std::left << productPrice
              << " " << std::setw(20) << std::left << productQuantity
              << std::setw(20) << std::left << Total()
              << std::endl;
}

productType::productType() {
    productName     = " ";
    productPrice    = 0;
    productQuantity = 0;
 }
 
