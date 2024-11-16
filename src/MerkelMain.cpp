#include "MerkelMain.h"
#include "OrderBookEntry.h"
#include <iostream>
#include <map>
#include <vector>

MerkelMain::MerkelMain() {
    // Инициализация карты в конструкторе
    menu[1] = &MerkelMain::printHelp;
    menu[2] = &MerkelMain::printMarketStats;
    menu[3] = &MerkelMain::enterOffer;
    menu[4] = &MerkelMain::enterBid;
    menu[5] = &MerkelMain::printWallet;
    menu[6] = &MerkelMain::gotoNextTimefrme;
}

void MerkelMain::init() {
    std::vector<OrderBookEntry> orders;
    orders.push_back(
        OrderBookEntry{5319.450228, 0.00020075, 
            "2020/03/17 17:01:24.884492", 
            "BTC/USDT", 
            OrderBookType::ask}
    );

    orders.push_back(
        OrderBookEntry{0.02187308, 7.44564869, 
        "2020/03/17 17:01:24.884492", 
        "ETH/BTC", 
        OrderBookType::bid}
    );

    for(OrderBookEntry& order: orders){
        std::cout << order.amount << std::endl;
    }

    while (true)
    {   
        printMenu();
        int userOption = getUserOption();
        auto it = menu.find(userOption);
        if (it != menu.end()) {
            // Вызов метода через указатель на метод-член
            (this->*(it->second))();
        } else {
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
}

void MerkelMain::printMenu() {
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Make an offer " << std::endl;
    // 4 make a bid
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;
    // 6 continue
    std::cout << "6: Continue " << std::endl;

    std::cout << "============" << std::endl;
}

void MerkelMain::printHelp() {
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void MerkelMain::printMarketStats() {
    std::cout << "Market looks good"<< std::endl;
}

void MerkelMain::enterOffer() {
    std::cout << "Make an offer - enter the amount" << std::endl;
}

void MerkelMain::enterBid() {
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void MerkelMain::printWallet() {
    std::cout << "Your wallet is empty." << std::endl;
}

void MerkelMain::gotoNextTimefrme() {
    std::cout << "Going to next time frame." << std::endl;
}

int MerkelMain::getUserOption() {
    std::cout << "Type in 1-6" << std::endl;
    int userOption;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}
