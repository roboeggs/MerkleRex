#include <map>

class MerkelMain
{
private:
    // Карта для хранения указателей на методы
    std::map<int, void(MerkelMain::*)()> menu;

public:
    MerkelMain();
    void init();
    void printMenu();
    void printHelp();
    void printMarketStats();           
    void enterOffer();
    void enterBid();
    void printWallet();
    void gotoNextTimefrme();
    int getUserOption();
};
