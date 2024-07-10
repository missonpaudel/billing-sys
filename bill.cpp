#include <iostream>
#include <iomanip>

struct choices{

};

void showMenu();
void order();
void placeOrder(int item_num);
double billgenerator(int item_num);

int main()
{


    std::cout<< "       WELCOME      \n";
    std::cout<< "******************\n";
    std::cout << "Enter your order (enter the index number)\n";
    showMenu();

    int item_num;
    char choice;
    double total;

    do{
        std::cout << "Enter the item number to add to the order (1-5): ";
        std::cin >> item_num;
        
        if (item_num == 0) break;
        placeOrder(item_num);
        std::cout << "Do want to add another item to the order (y/n)";
        std::cin >> choice;
        total += billgenerator(item_num);

    }while (choice == 'y' ||   choice == 'Y');
    std::cout << "\nYour total is Rs "<< std::setprecision(2) << std::fixed << total <<'\n';

    
return 0;
}

void showMenu(){
    std::cout << "1-Burger .................... 100\n";
    std::cout << "2-Pizza ..................... 300\n";
    std::cout << "3-Momos ..................... 150\n";
    std::cout << "4-Keema noodles ............. 160\n";
    std::cout << "5-Shawarma .................. 180\n";
}
void placeOrder(int item_num){ 
    if (item_num < 1 || item_num > 5){
        std::cout << "Invalid menu item \n";
    }
    switch(item_num)
    {case 1: std::cout << "Addded burger to the order\n";
        billgenerator(item_num);
        break;
    case 2: std::cout << "Addded pizza to the order\n";
        billgenerator(item_num);
        break;
    case 3: std::cout << "Addded momos to the order \n";
        billgenerator(item_num);
        break;
    case 4: std::cout << "Addded keema noodles to the order\n";
        break;
    case 5: std::cout << "Addded shawarma to the order\n";
        break;
        }
}
double billgenerator(int item_num){
    if (item_num < 1 || item_num > 5){
        return 0;
    }
    
    switch(item_num)
    {case 1: return 100;
            break;
    case 2: return 300;
            break;
    case 3: return 150;
            break;
    case 4: return 160;
            break;
    case 5: return 180;
            break;
        }
}