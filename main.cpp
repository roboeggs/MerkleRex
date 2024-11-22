#include "MerkelMain.h"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

/*
std::vector<std::string> tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    std::string token;
    // int start, end ## used to delineate the position of the tokens
    signed int start, end;
    // start = csvLine.find_first_not_of(separator)
    start = csvLine.find_first_not_of(separator, 0);
    do{
    end  = csvLine.find_first_of(separator, start);
    if(start == csvLine.length() || start == end) break;

    if(end >= 0)
        token = csvLine.substr(start, end - start);
    else
        token = csvLine.substr(start, csvLine.length() - start);

    tokens.push_back(token);

    start = end + 1;
    }while(end != std::string::npos);

    

    return tokens;
}
*/


std::vector<std::string> tokenise(const std::string& csvLine, char separator)
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


int main()
{

    std::vector<std::string> tokens;

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
                continue;
            }
            
            try{
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);
                std::cout << price << ":" << amount << std::endl;
            }catch(std::exception& e){
                std::cout << "Bad float! " << tokens[3] << " or " << tokens[4] << std::endl;
                break;
            }
        }
        
    
        csvFile.close();
    }
    else
    {
        std::cerr << "Could not open file" << std::endl;
    }


    return 0;

    MerkelMain app{};
    app.init();
    return 0;
}