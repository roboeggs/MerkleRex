#include <iostream>
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

void processUserOption(int userOption)
{
    switch (userOption)
        {
        case 1:
            printHelp();
            break;
        case 2:
            printMarketStats();
            break;
        case 3:
            enterOffer();
            break;
        case 4:
            enterBid();
            break;
        case 5:
            printWallet();
            break;
        case 6:
            gotoNextTimefrme();
            break;

        default:
            break;
        }
}

void menu()
{   
    // в примере тип int
    int userOption = getUserOption();

    processUserOption(userOption);
    
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

    while (true)
    {   
        printMenu();
        int userOption = getUserOption();
        std::cout << "Map work" << std::endl;
        menu.find(userOption)->second;
        // processUserOption(userOption);
    }

    return 0;
}