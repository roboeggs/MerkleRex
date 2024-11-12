#include <iostream>
#include <string>
#include <vector>
#include <map>


void printMenu()
{
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

void printHelp(){
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void printMarketStats()
{
    std::cout << "Market looks goog"<< std::endl;
}
            
void enterOffer()
{
    std::cout << "Mark and offer - enter the amount" << std::endl;
}

void enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void printWallet()
{
    std::cout << "You wallet is empty." << std::endl;
}
void gotoNextTimefrme()
{
    std::cout << "Going to next time frame." << std::endl;
}

int getUserOption()
{
    std::cout << "Type in 1-6" << std::endl;
    int userOption;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

int main()
{
    // map from ints to function pointers
    std::map<int, void(*)()> menu;
    // connect 1 to the printHelp function
    menu[1] = printHelp;
    menu[2] = printMarketStats;
    menu[3] = enterOffer;
    menu[4] = enterBid;
    menu[5] = printWallet;
    menu[6] = gotoNextTimefrme;

    enum class OrderBookType{bid, ask};

    // Declaring a structure
    struct Order {
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
    };


    // Declaring the vector of structs
    struct Order temp1 = { 5319.450228, 0.00020075, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::ask};
    struct Order temp2 = { 0.02187308, 7.44564869, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid};
    std::vector<Order> orders;

    orders.push_back(temp1);
    orders.push_back(temp2);

    for (auto& a : orders) {
        std::cout << a.price << "             "
             << a.amount << "          "
             << a.timestamp << std::endl;
    }

    while (true)
    {   
        printMenu();
        int userOption = getUserOption();
        menu.find(userOption)->second();
    }

    return 0;
}