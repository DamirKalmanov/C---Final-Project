#ifndef USER_H
#define USER_H

#include <vector>
#include <memory>
#include <numeric>
#include "Transaction.h"

class User {
private:
    std::vector<std::shared_ptr<Transaction>> transactions;

public:
    void addTransaction(const std::shared_ptr<Transaction>& t) {
        transactions.push_back(t);
    }

    void setTransactions(const std::vector<std::shared_ptr<Transaction>>& loaded) {
        transactions = loaded;
    }

    double getBalance() const {
        return std::accumulate(transactions.begin(), transactions.end(), 0.0,
            [](double sum, const std::shared_ptr<Transaction>& t) {
                return sum + t->getSignedAmount();
            });
    }

    const std::vector<std::shared_ptr<Transaction>>& getTransactions() const {
        return transactions;
    }
};

#endif