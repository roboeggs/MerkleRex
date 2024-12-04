#include <string>
#include <map>

class Wallet
{
private:
    std::map<std::string, double> currencies;
public:
    Wallet(/* args */);
    /** insert currency to the wallet */
    void insertCurrency(std::string type, double amount);
    /** check if the wallet contains this much currency or more */
    bool containsCurrency(std::string type, double amount);
    /** generate a string representation of the wallet */
    std::string toString();

    ~Wallet();
};