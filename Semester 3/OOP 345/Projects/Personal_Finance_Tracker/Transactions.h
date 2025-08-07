#ifndef MY_TRANSACTIONS_H
#define MY_TRANSACTIONS_H
#include<iostream>
#include<string>

namespace Working {
	enum class TransactionType {
		Income,
		Expense
	};
	class Transaction {
		std::string date;
		std::string category;
		std::string description;
		double amount;
		TransactionType type;

		Transaction();  //Default
		Transaction(const std::string& date,const std::string& category, const std::string& description,
			double amount, TransactionType type);
		//Getters
		std::string getDate() const;
		std::string getCategory() const;
		std::string getDescription() const;
		double getAmount() const;
		TransactionType getType() const;
		//Setters
		void setDate(const std::string& d);
		void setCategory(const std::string& c);
		void setDescription(const std::string& d);
		void setAmount(double a);
		void setType(TransactionType t);

		// Print
		void print() const;

		//CSV Handling
		std::string toCSV() const;
		static Transaction fromCSV(const std::string& line);

		// Helper (enum <-> string)
		static std::string typeToString(TransactionType type);
		static TransactionType stringToType(const std::string& str);
	};

}

#endif // !MY_TRANSACTIONS_H
