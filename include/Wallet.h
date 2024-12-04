#include <string>

class Wallet
{
private:
    /* data */
public:
    Wallet(/* args */);
    /** insert currency to the wallet */
    void insertCurrency(std::string type, double amount);
    /** check if the wallet contains this much currency or more */
    bool containsCurrency(std::string type, double amount);

    
    ~Wallet();
};

