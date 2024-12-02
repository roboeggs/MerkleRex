#pragma once

#include <map>
#include <vector>
#include "OrderBookEntry.h"

#include "OrderBook.h"

class MerkelMain
{
private:
    // A map for storing pointers to methods
    std::map<int, void(MerkelMain::*)()> menu;
    std::vector<OrderBookEntry> orders;
    void printMenu();
    void printHelp();
    void printMarketStats();           
    void enterOffer();
    void enterBid();
    void printWallet();
    void gotoNextTimeframe();
    int getUserOption();

    OrderBook orderBook{"assets/20200317.csv"};

public:
    MerkelMain();
    /** Call this to start the sim */
    void init();
    
};
