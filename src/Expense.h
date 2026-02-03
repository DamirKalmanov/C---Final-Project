#ifndef EXPENSE_H
#define EXPENSE_H

#include "Transaction.h"

class Expense : public Transaction {
public:
    Expense(double amount, const std::string& category, const std::string& date)
        : Transaction(amount, category, date) {}

    double getSignedAmount() const override { return -amount; }
    std::string getType() const override { return "Expense"; }
};

#endif