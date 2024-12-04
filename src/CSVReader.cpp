#include "CSVReader.h"


CSVReader::CSVReader(/* args */)
{
}

CSVReader::~CSVReader()
{
}

std::vector<std::string> CSVReader::tokenise(const std::string& csvLine, char separator)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(csvLine);
    while (std::getline(tokenStream, token, separator))
    {
        tokens.push_back(token);
    }
    return tokens;
}
OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens)
{
    double price, amount;
    if(tokens.size() != 5){
        std::cout << "Bad line" << std::endl;
        throw std::exception{};
    }
    
    try{
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }catch(const std::exception& e){
        std::cout << "CSVReader::stringsToOBE Bad float! " << tokens[3] << " or " << tokens[4] << std::endl;
        throw;
    }
      


    OrderBookEntry obe{ price,
                        amount,
                        tokens[0],
                        tokens[1],
                        OrderBookEntry::stringToOrderBookType(tokens[2])
                        
    };
    return obe;
}


std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFilename){
    std::vector<OrderBookEntry> entries;
    std::ifstream csvFile{csvFilename};
    std::string line;
    if(csvFile.is_open())
    {
        std::cout << "File open" << std::endl;
        while (std::getline(csvFile, line))
        {
            try{
                OrderBookEntry obe = stringsToOBE(tokenise(line, ','));
                entries.push_back(obe);
            }catch(const std::exception& e)
            {
                std::cout << "CSVReader::readCSV bad data " << std::endl;
            }

        }
        
        csvFile.close();
        std::cout << "CSVReader::readCSV read " << entries.size() << " entries" << std::endl;
    }
    else
    {
        std::cerr << "Could not open file" << std::endl;
    }
    
    return entries;
}

OrderBookEntry CSVReader::stringsToOBE( std::string priceString,
                                    std::string amountString,
                                    std::string timestamp,
                                    std::string product,
                                    OrderBookType OrderBookType)
{
    double price, amount;
     try{
        price = std::stod(priceString);
        amount = std::stod(amountString);
    }catch(const std::exception& e){
        std::cout << "CSVReader::stringsToOBE Bad float! " << priceString << " or " << amountString << std::endl;
        throw;
    }
     OrderBookEntry obe{ price,
                        amount,
                        timestamp,
                        product,
                        OrderBookType
                        
    };
                        
    return obe;
    
}