#ifndef REPORTSERVICE_H
#define REPORTSERVICE_H

#include <map>
#include <string>
#include <vector>
#include <memory>
#include "Transaction.h"

class ReportService {
public:
    static std::map<std::string, double>
    expensesByCategory(const std::vector<std::shared_ptr<Transaction>>& tx) {
        std::map<std::string, double> report;
        for (const auto& t : tx) {
            if (t->getType() == "Expense")
                report[t->getCategory()] += -t->getSignedAmount();
        }
        return report;
    }
};

#endif