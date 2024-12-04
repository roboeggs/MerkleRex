#pragma once

#include "OrderBookEntry.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

class CSVReader
{
private:
    static OrderBookEntry stringsToOBE(std::vector<std::string> tokens);
public:
    CSVReader();

    static std::vector<OrderBookEntry> readCSV(std::string csvFilename);
    static std::vector<std::string> tokenise(const std::string& csvLine, char separator);

    static OrderBookEntry stringsToOBE( std::string priceString,
                                    std::string amountString,
                                    std::string timestamp,
                                    std::string product,
                                    OrderBookType OrderBookType);

    ~CSVReader();
};


