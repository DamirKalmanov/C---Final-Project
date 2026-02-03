#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
protected:
    double amount;
    std::string category;
    std::string date;

public:
    Transaction(double amount, const std::string& category, const std::string& date)
        : amount(amount), category(category), date(date) {}

    virtual ~Transaction() = default;

    virtual double getSignedAmount() const = 0;
    virtual std::string getType() const = 0;

    double getAmount() const { return amount; }
    std::string getCategory() const { return category; }
    std::string getDate() const { return date; }
};

#endif