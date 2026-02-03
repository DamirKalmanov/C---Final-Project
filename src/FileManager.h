#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <fstream>
#include <vector>
#include <memory>
#include <stdexcept>
#include "Expense.h"
#include "Income.h"

class FileManager {
public:
    static void save(const std::vector<std::shared_ptr<Transaction>>& tx,
                     const std::string& filename) {
        std::ofstream file(filename);
        if (!file.is_open()) throw std::runtime_error("Cannot open file");

        for (const auto& t : tx) {
            file << t->getType() << ","
                 << t->getAmount() << ","
                 << t->getCategory() << ","
                 << t->getDate() << "\n";
        }
    }

    static std::vector<std::shared_ptr<Transaction>> load(const std::string& filename) {
        std::ifstream file(filename);
        std::vector<std::shared_ptr<Transaction>> res;
        if (!file.is_open()) return res;

        std::string type, category, date;
        double amount;
        char comma;

        while (file >> type >> comma >> amount >> comma >> category >> comma >> date) {
            if (type == "Income")
                res.push_back(std::make_shared<Income>(amount, category, date));
            else if (type == "Expense")
                res.push_back(std::make_shared<Expense>(amount, category, date));
        }
        return res;
    }
};

#endif