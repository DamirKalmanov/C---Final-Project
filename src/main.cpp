#include <iostream>
#include <memory>
#include "Expense.h"
#include "Income.h"
#include "User.h"
#include "FileManager.h"
#include "ReportService.h"

int main() {
    User user;
    const std::string filename = "data/transactions.txt";

    try {
        user.setTransactions(FileManager::load(filename));
    } catch (...) {}

    int choice = -1;
    while (choice != 0) {
        std::cout << "\n=== Smart Expense Tracker ===\n"
                  << "1. Add income\n"
                  << "2. Add expense\n"
                  << "3. Show balance\n"
                  << "4. Expense report by category\n"
                  << "0. Exit\n"
                  << "Choice: ";
        std::cin >> choice;

        if (choice == 1 || choice == 2) {
            double amount;
            std::string category, date;
            std::cout << "Amount: "; std::cin >> amount;
            std::cout << "Category: "; std::cin >> category;
            std::cout << "Date (YYYY-MM-DD): "; std::cin >> date;

            if (choice == 1)
                user.addTransaction(std::make_shared<Income>(amount, category, date));
            else
                user.addTransaction(std::make_shared<Expense>(amount, category, date));
        } else if (choice == 3) {
            std::cout << "Current balance: " << user.getBalance() << "\n";
        } else if (choice == 4) {
            auto rep = ReportService::expensesByCategory(user.getTransactions());
            for (const auto& [cat, sum] : rep)
                std::cout << cat << ": " << sum << "\n";
        }
    }

    try {
        FileManager::save(user.getTransactions(), filename);
    } catch (...) {}

    return 0;
}