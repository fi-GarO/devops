#include <iostream>
#include <map>
#include <stdexcept>

// Enum for different coin types
enum CoinType {
    QUARTER,
    DIME,
    NICKEL
};

class Cashier {
private:
    // Map to store the number of coins of each type currently in the system
    std::map<CoinType, int> coinInventory;
    // Amount of money currently in the system
    double moneyInventory;
    // Amount of money the customer still needs to pay
    double remainingPayment;

public:
    Cashier() {
        // Initialize coin inventory and money inventory to 0
        coinInventory[QUARTER] = 0;
        coinInventory[DIME] = 0;
        coinInventory[NICKEL] = 0;
        moneyInventory = 0.0;
        remainingPayment = 0.0;
    }

    void insertCoin(CoinType coinType) {
        // Increase the number of coins of the inserted type
        coinInventory[coinType]++;
        // Update the money inventory
        switch (coinType) {
            case QUARTER:
                moneyInventory += 0.25;
                break;
            case DIME:
                moneyInventory += 0.10;
                break;
            case NICKEL:
                moneyInventory += 0.05;
                break;
        }
    }

    void setRemainingPayment(double amount) {
        remainingPayment = amount;
    }

    double getRemainingPayment() {
        return remainingPayment;
    }

    double getMoneyInventory() {
        return moneyInventory;
    }

    int getCoinInventory(CoinType coinType) {
        return coinInventory[coinType];
    }

    void checkChange() {
        double change = moneyInventory - remainingPayment;
        if (change <= 0) {
            return;
        }
        std::map<CoinType, int> changeInventory;
        changeInventory[QUARTER] = 0;
        changeInventory[DIME] = 0;
        changeInventory[NICKEL] = 0;
        while (change > 0) {
            if (change >= 0.25 && coinInventory[QUARTER] > changeInventory[QUARTER]) {
                change -= 0.25;
                changeInventory[QUARTER]++;
            } else if (change >= 0.10 && coinInventory[DIME] > changeInventory[DIME]) {
                change -= 0.10;
                changeInventory[DIME]++;
            } else if (change >= 0.05 && coinInventory[NICKEL] > changeInventory[NICKEL]) {
                change -= 0.05;
                changeInventory[NICKEL]++;
            } else {
                throw std::runtime_error("Unable to make change with current coin inventory");
            }
        }
    }
};
