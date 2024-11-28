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
    return tokens;
}
OrderBookEntry CSVReader::stringsTooBE(std::vector<std::string> tokens)
{
    double price, amount;
    std::ifstream csvFile{"assets/20200317.csv"};
    std::string line;
    if(csvFile.is_open())
    {
        std::cout << "File open" << std::endl;
        while (std::getline(csvFile, line))
        {
            std::cout << "Read line " << line << std::endl;
            tokens =  tokenise(line, ',');
            
            if(tokens.size() != 5){
                std::cout << "Bad line" << std::endl;
                throw std::exception{};
            }
            
            try{
                price = std::stod(tokens[3]);
                amount = std::stod(tokens[4]);
                std::cout << price << ":" << amount << std::endl;
            }catch(const std::exception& e){
                std::cout << "Bad float! " << tokens[3] << " or " << tokens[4] << std::endl;
                throw;
            }
        }
        
    
        csvFile.close();
    }
    else
    {
        std::cerr << "Could not open file" << std::endl;
    }
    OrderBookEntry obe{ price,
                        amount,
                        tokens[0],
                        tokens[1],
                        OrderBookType::stringToOrderBookType(tokens[2]),
                        
    };
    return obe;
}
std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFile){
    std::vector<OrderBookEntry> entries;
    return entries;
}