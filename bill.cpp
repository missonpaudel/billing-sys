#include <iostream>
#include <iomanip>

struct menuItem{
std::string itemName;
double price;
};

const int MENU_SIZE = 5;

void showMenu(const menuItem menu[]);
void order();
void placeOrder(int item_num, double &total,const menuItem menu[] );
double billgenerator(int item_num, const menuItem menu[]);

int main()
{
    menuItem menu[MENU_SIZE] = {{"Burger" , 100.0}, 
                                {"Pizza", 300.0},
                                {"Momos", 150}, 
                                {"Keema Noodles", 160.0}, {"shawarma", 180} };


    std::cout<< "       WELCOME      \n";
    std::cout<< "******************\n";
    std::cout << "Enter your order (enter the index number)\n";
    showMenu(menu);

    int item_num;
    char choice;
    double total;

    do{
        std::cout << "Enter the item number to add to the order (1-5): ";
        std::cin >> item_num;
        
        if (item_num == 0) break;
        placeOrder(item_num, total, menu);
        std::cout << "Do want to add another item to the order (y/n)";
        std::cin >> choice;

    }while (choice == 'y' ||   choice == 'Y');
    std::cout << "\nYour total is Rs "<< std::setprecision(2) << std::fixed << total <<'\n';

    
return 0;
}

void showMenu(const menuItem menu[]){
    for(int i = 0; i < MENU_SIZE; i++){
        std::cout << i + 1 << "-" << menu[i].itemName << " .................... " << menu[i].price << '\n';
    }
}
void placeOrder(int item_num, double &total,const menuItem menu[] ){ 
    if (item_num < 1 || item_num > MENU_SIZE){
        std::cout << "Invalid menu item \n";
        return;
    }
    std::cout << "Added " << menu[item_num - 1].itemName << " to the order\n";
    total += billgenerator(item_num, menu);
}
double billgenerator(int item_num, const menuItem menu[]){
    if (item_num < 1 || item_num > 5){
        return 0;
    }
    return menu[item_num - 1].price;
}