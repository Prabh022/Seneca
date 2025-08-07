#include"Transactions.h"
#include<iostream>
#include<sstream>
#include<iomanip>
#include<algorithm>

namespace Working {

	Transaction::Transaction()
		: date("1970-01-01"), category("Unknown"), description(""), amount(0.0), type(TransactionType::Expense) {
	}
    Transaction::Transaction(const std::string& date,
        const std::string& category,
        const std::string& description,
        double amount,
        TransactionType type)
        : date(date), category(category), description(description), amount(amount), type(type) {}

    std::string Transaction::getDate() const
    {
        return date;
    }

    std::string Transaction::getCategory() const
    {
        return category;
    }

    std::string Transaction::getDescription() const
    {
        return description;
    }

    double Transaction::getAmount() const
    {
        return amount;
    }

    TransactionType Transaction::getType() const
    {
        return type;
    }

    void Transaction::setDate(const std::string& d)
    {
        date = d;
    }

    void Transaction::setCategory(const std::string& c)
    {
        category = c;
    }

    void Transaction::setDescription(const std::string& d)
    {
        description = d;
    }

    void Transaction::setAmount(double a)
    {
        amount = a;
    }

    void Transaction::setType(TransactionType t)
    {
        type = t;
    }

    void Transaction::print() const
    {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "[ " << date << " | " << std::setw(8) << typeToString(type) << " | "
            << std::setw(10) << category << " | $" << std::setw(8) << amount << " | "
            << description << " ]\n";
    }

    // === CSV Handling ===

    std::string Transaction::toCSV() const {
        std::ostringstream oss;
        oss << date << ',' << category << ',' << description << ','
            << amount << ',' << typeToString(type);
        return oss.str();
    }

    Transaction Transaction::fromCSV(const std::string& line) {
        std::istringstream iss(line);
        std::string token;

        std::string date, category, description, typeStr;
        double amount = 0.0;

        std::getline(iss, date, ',');
        std::getline(iss, category, ',');
        std::getline(iss, description, ',');

        std::getline(iss, token, ',');
        amount = std::stod(token);

        std::getline(iss, typeStr, ',');

        TransactionType type = stringToType(typeStr);

        return Transaction(date, category, description, amount, type);
    }

    // === Type Conversion Helpers ===

    std::string Transaction::typeToString(TransactionType type) {
        switch (type) {
        case TransactionType::Income: return "income";
        case TransactionType::Expense: return "expense";
        default: return "unknown";
        }
    }

    TransactionType Transaction::stringToType(const std::string& str) {
        std::string lower = str;
        std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

        if (lower == "income") return TransactionType::Income;
        else if (lower == "expense") return TransactionType::Expense;
        else return TransactionType::Expense; // default fallback
    }

}