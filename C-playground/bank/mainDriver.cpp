#include "bank.cpp"
#include <iostream>

int main() {
    std::cout << "hello" << std::endl;
    Cashier cashier;
    // Set the remaining payment to $1.50
    cashier.setRemainingPayment(1.50);
    // Insert some coins
    cashier.insertCoin(QUARTER);
    cashier.insertCoin(QUARTER);
    cashier.insertCoin(DIME);
    cashier.insertCoin(NICKEL);
    std::cout << "Remaining payment: $" << cashier.getRemainingPayment() << std::endl;
    std::cout << "Money inventory: $" << cashier.getMoneyInventory() << std::endl;
    std::cout << "Number of quarters: " << cashier.getCoinInventory(QUARTER) << std::endl;
    std::cout << "Number of dimes: " << cashier.getCoinInventory(DIME) << std::endl;
    std::cout << "Number of nickels: " << cashier.getCoinInventory(NICKEL) << std::endl;
    try {
       cashier.checkChange();
       std::cout << "Change given successfully" << std::endl;
    } catch (const std::runtime_error& e) {
       std::cout << e.what() << std::endl;
    }
    return 0;
}
