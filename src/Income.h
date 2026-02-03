#ifndef INCOME_H
#define INCOME_H

#include "Transaction.h"

class Income : public Transaction {
public:
    Income(double amount, const std::string& category, const std::string& date)
        : Transaction(amount, category, date) {}

    double getSignedAmount() const override { return amount; }
    std::string getType() const override { return "Income"; }
};

#endif