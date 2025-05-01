#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool() const
   {
       return (m_number >= 10000 && m_number <= 99999 && m_balance >= 0);
   }

   Account::operator int() const
   {
       return m_number;
   }

   Account::operator double() const
   {
       return m_balance;
   }

   bool Account::operator~() const
   {
       return m_number == 0;
   }

   Account& Account::operator=(int number) {
       if (m_number == 0) { // Only allow assignment if the Account is NEW
           if (number >= 10000 && number <= 99999) { // Valid 5-digit number
               m_number = number;
           }
           else {
               m_number = -1;    // Invalid state
               m_balance = 0.0;
           }
       }
       return *this;
   }
   Account& Account::operator=(Account& other) {
       if (m_number == 0 && other) { // This (left) must be NEW, and other (right) must be valid
           m_number = other.m_number;
           m_balance = other.m_balance;
           other.m_number = 0;
           other.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator+=(double balance) {
       if (*this && balance > 0) {
           m_balance += balance;
       }
       return *this;
   }

   Account& Account::operator-=(double balance)
   {
       if (*this && balance > 0 && m_balance >= balance) {
           m_balance -= balance;
       }
       return *this;
   }
   Account& Account::operator<<(Account& right) {
       if (this != &right && *this && right) {
           m_balance += right.m_balance;
           right.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator>>(Account& left)
   {
       if (this != &left && *this && left) {
           m_balance += left.m_balance;
           left.m_balance = 0.0;
       }
       return *this;
   }

   double operator+(const Account& left, const Account& right) {
       // If either account is invalid, return 0.0
       if (!left) {  // Assuming the operator bool is overloaded to check validity
           return 0.0;
       }
       if (!right) {  // Same check for the right account
           return 0.0;
       }

       // If both accounts are valid, return the sum of their balances
       return static_cast<double>(left) + static_cast<double>(right);  // Assuming the operator double() is overloaded to get the balance
   }

   double operator+=(double& left, const Account& right)
   {
       if (right) {  // Check if the account is valid
           left += static_cast<double>(right);  // Add the balance of the right Account to the left double
       }
       return left;  // Return the updated left double
   }


 
}                               