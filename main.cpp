#include <iostream>
#include <fstream>
#include <iomanip>
#include "Interface_productType.h"

void display(productType prod[]); // to show the output 
bool check_pass_id(int, int);  // to cheack for the id and the password
bool cheack_choice(int);//for cheacking for the avalied for the choice
void print_Recpict(productType[]);

int main() {
    productType product[20];
    int id_user, pass_user, choice, quantity;
    char null_ver = '\0';
    int try_num = 3;
    int counter = 0;
    double total = 0;

    // product data from 0 to 5 
    product[0].set_productName("Alcohol");
    product[0].set_productPrice(28.89);
    product[1].set_productName("Fruit/veg/salads");
    product[1].set_productPrice(9.69);
    product[2].set_productName("Dairy");
    product[2].set_productPrice(8.29);
    product[3].set_productName ("Chilled convenience");
    product[3].set_productPrice(4.8);
    product[4].set_productName("Bathroom toiletries"); 
    product[4].set_productPrice(4.60);
    product[5].set_productName ("Household/cleaning");
    product[5].set_productPrice (4.85);

    do {
        std::cout << "You have " << try_num << " Try : \n";
        std::cout << "Enter the user ID : ";
        std::cin  >> id_user;

        std::cout << "Enter the user pass : "; // Changed "use" to "user"
        std::cin  >> pass_user;
        try_num--; 
    } while ((!check_pass_id(pass_user, id_user)) && try_num != 0); // Changed "cheack_pass_id" to "check_pass_id"

    if (!check_pass_id(pass_user, id_user)) { // Changed "cheack_pass_id" to "check_pass_id"
        std::cout << "Sorry, You entered an incorrect Password and ID!!\n"; // Corrected the message
    } else {  
        do { 
            display(product);
            std::cout << "Enter your choice (press 0 to Exit): "; // Corrected the message
            std::cin  >> choice;
            std::cout << std::endl;
            if (cheack_choice(choice)) {
                if (choice >= 1 && choice <= 6) {
                    std::cout << "Enter the Quantity that you want : ";
                    std::cin >> quantity;

                    product[choice - 1].set_productQuantity(quantity);
                    product[choice - 1].print();

                    std::cout << std::endl;
                    total += product[choice - 1].Total();
                }
            } else {
                if (choice == 0) { 
                    print_Recpict(product);
                    std::cout << "Total cost = "   
                              << std::setfill(' ') << std::setw(100) << std::left << total    << "\n"
                              << std::setfill('=') << std::setw(100) << std::left << null_ver << "\n";

                    std::cout << "Have a nice day! Thank you for visiting us." << std::endl;
                } else {
                    std::cout << "You entered an incorrect value. Please enter a correct one.\n";
                }
            }
        } while (choice != 0);
    }    
    return 0;
} 

bool check_pass_id(int user_pass, int user_id) {
    int pass_sys = 4625714;
    int id_sys = 4102002;

    return ((user_pass == pass_sys) && (user_id == id_sys));     
}

void display(productType prod[]) {
    char null_ver = '\0';
    std::cout << std::setw(56) << std::setfill('=') << std::left << null_ver  << "\n" 
        << std::setw(27) << std::setfill(' ') << "||" <<  std::right << "List "
        << std::setw(23) << std::setfill(' ') << "||" << null_ver << "\n"
        << std::setw(56) << std::left  << std::setfill('=')  << null_ver  << "\n"
        << std::setw(34) << std::setfill(' ')  << std::left  << "||Name of product"
        << std::setw(19) << std::setfill(' ')  << std::left  << "    ||price" 
        << std::setw(2)  << std::setfill (' ') << std::right << "|| \n"
        << std::setw(56) << std::setfill('=') << std::left << null_ver  << "\n";

    for (int i = 0; i < 6; i++) { // Changed the loop condition from 5 to 6
        std::cout << "||" << ( i + 1) << " " << std::setw(34) << std::setfill(' ') << std::left  << prod[i].get_productName() 
            << "||" << " " << std::setw(12) << std::setfill(' ') << std::left  << prod[i].get_productPrice()
            << std::setw(2) << std::setfill (' ') << std::right << "||\n"
            << std::setw(56) << std::setfill('=') << std::left  << null_ver  << "\n";      
    } 
    std::cout << std::endl;  
} 

bool cheack_choice(int choice) {
    if (choice > 0 && choice <= 6) {
        return true;
    } else {
        return false;
    }
}

void print_Recpict(productType product[]) {
    std::cout 
        << std::setw(100) << std::right << std::setfill('=') << " " << "\n"  
        << std::setw(50) << std::setfill(' ') << std::right << "Recpict"
        << std::setw(50) << std::setfill (' ') << std::left << " " << "\n" 
        << std::setw(100) << std::right << std::setfill('=') << " " << "\n"

        << std::setw(25) << std::setfill(' ')  << std::left  << "||Name of product"
        << std::setw(25) << std::setfill(' ')  << std::left  << "    ||price"
        << std::setw(25) << std::setfill(' ')  << std::left  << "||Quantity"
        << std::setw(25) << std::setfill(' ')  << std::left  << "||Total product" << "\n"
        << std::setw(100) << std::right << std::setfill('=') << " " << "\n";

    for (int i = 0; i < 6; i++) {
        if(product[i].Total() == 0) {
            break;
        } else {
            std::cout
                << std::setfill(' ') 
                << std::setw(25)     << std::left << product[i].get_productName()
                << "     "           
                << std::setw(25)     << std::left << product[i].get_productPrice()
                << "  "              
                << std::setw(25)     << std::left << product[i].get_productQuantity()

                << std::setw(21)     << std::left << product[i].Total() << "\n"
                << std::setw(100)    << std::right << std::setfill('=') << " " << "\n";
                               
    }
 }
}
