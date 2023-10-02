#include <string>
class productType {
    private: std::string productName;
    private: int productQuantity;
    private: float productPrice;

    // for set and get the product name 
    public: void set_productName(std::string);
    public: std::string get_productName()const;

    // for set and get the product quantity
    public: void set_productQuantity(int);
    public: int get_productQuantity()const;

    //for set and get the product price
    public: void set_productPrice(float);
    public: float get_productPrice() const;

    // Total = price * quantity
    public: float Total() const;
    
    // print with show the product name , price , quantity
    // and total cost
    public: void print();

    //constructer
    public: productType();
};
