#pragma once

#include "OrderBookEntry.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class CSVReader
{
private:
    static std::vector<std::string> tokenise(const std::string& csvLine, char separator);
    static OrderBookEntry stringsTooBE(std::vector<std::string> tokens);
public:
    CSVReader();
    static std::vector<OrderBookEntry> readCSV(std::string csvFile);

    ~CSVReader();
};


