#include <string>
#include <map>
#include "OrderBookEntry.h"

class Wallet
{
private:
    std::map<std::string, double> currencies;
public:
    Wallet(/* args */);
    /** insert currency to the wallet */
    void insertCurrency(std::string type, double amount);
    /** remove currency frome the wallet */
    bool removeCurrency(std::string type, double amount);
    /** check if the wallet contains this much currency or more */
    bool containsCurrency(std::string type, double amount);
    /** generate a string representation of the wallet */
    std::string toString();

    /** checks if the wallet can cope with this ask or bid. */
    bool canFulfillOrder(OrderBookEntry order);
    /** update the contens of the wallet
     * assumes the order was made by the owner of the waller
     */
    void processSale(OrderBookEntry& sale);

    ~Wallet();
};