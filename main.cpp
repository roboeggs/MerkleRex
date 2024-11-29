#include "MerkelMain.h"
#include "CSVReader.h"

#include <string>
#include <vector>
#include <iostream>


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




int main()
{
    // CSVReader reader;
    // reader.readCSV("assets/20200317.csv");

    // CSVReader::readCSV("assets/20200317.csv");

    MerkelMain app{};
    app.init();
    return 0;
}