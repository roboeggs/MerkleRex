#ifndef ORDERBOOKENTRY_H
#define ORDERBOOKENTRY_H

#pragma once

#include <string>

enum class OrderBookType { bid, ask };

class OrderBookEntry {
public:
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;

    OrderBookEntry(double price,
                   double amount,
                   std::string timestamp,
                   std::string product,
                   OrderBookType orderType);

    ~OrderBookEntry();
};

#endif // ORDERBOOKENTRY_H
