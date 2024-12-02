#include "MerkelMain.h"
// #include "OrderBookEntry.h"
#include <iostream>
// #include <map>
#include <vector>
#include "CSVReader.h"


MerkelMain::MerkelMain() {
    // Инициализация карты в конструкторе
    menu[1] = &MerkelMain::printHelp;
    menu[2] = &MerkelMain::printMarketStats;
    menu[3] = &MerkelMain::enterOffer;
    menu[4] = &MerkelMain::enterBid;
    menu[5] = &MerkelMain::printWallet;
    menu[6] = &MerkelMain::gotoNextTimeframe;
}

void MerkelMain::init() 
{
    
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
    for(std::string const p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, 
                                                                    p, "2020/03/17 17:01:24.884492");
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
    }
    // std::cout << "OrderBook contains: " << orders.size() << " entries" << std::endl;
    // unsigned int bids = 0;
    // unsigned int asks = 0;
    // for(OrderBookEntry& e : orders)
    // {
    //     if (e.orderType == OrderBookType::ask){
    //         asks++;
    //     }
    //     if (e.orderType == OrderBookType::bid){
    //         bids++;
    //     }
    // }
    // std::cout << "OrderBook asks: " << asks << " bids: " << bids << std::endl;
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

void MerkelMain::gotoNextTimeframe() {
    std::cout << "Going to next time frame." << std::endl;
}

int MerkelMain::getUserOption() {
    std::cout << "Type in 1-6" << std::endl;
    int userOption;
    std::cin >> userOption;
    
    if (std::cin.fail() || userOption < 1 || userOption > 6) {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number between 1 and 6." << std::endl;
        return -1; 
    }
    
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}