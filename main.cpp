#include <iostream>

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
            std::cout << "Help - your am is to make money. Analyse the market and make bids and offer" << std::endl;
            break;
        case 2:
            std::cout << "Market looks goog"<< std::endl;
            break;
        case 3:
            std::cout << "Mark and offer - enter the amount" << std::endl;
            break;
        case 4:
            std::cout << "Make a bid - enter the amount" << std::endl;
            break;
        case 5:
            std::cout << "You wallet is empty." << std::endl;
            break;
        case 6:
            std::cout << "Going to next time frame." << std::endl;
            break;

        default:
            std::cout << "Invalid choice. Choose 1-6" << std::endl;
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
    while (true)
    {   
        printMenu();
        int userOption = getUserOption();
        processUserOption(userOption);
    }

    return 0;
}