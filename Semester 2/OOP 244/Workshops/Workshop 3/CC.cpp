#include <iostream>8
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {
   void CC::prnNumber(unsigned long long no) const {
      cout << no / 1000000000000ull << " ";
      no %= 1000000000000ull;
      cout.fill('0');
      cout.width(4);
      cout.setf(ios::right);
      cout << no / 100000000ull << " ";
      no %= 100000000ull;
      cout.width(4);
      cout << no / 10000ull << " ";
      no %= 10000ull;
      cout.width(4);
      cout << no;
      cout.unsetf(ios::right);
      cout.fill(' ');
   }
   bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const
   {
       // Check if name is nullptr or its length is less than 2
       if (name == nullptr || strlen(name) < 2) {
           return false;
       }

       // Validate card number (must be between 1000000000000 and 9999999999999999)
       if (cardNo < 1000000000000ull || cardNo > 9999999999999999ull) {
           return false;
       }

       // Validate CVV (must be between 100 and 999)
       if (cvv < 100 || cvv > 999) {
           return false;
       }

       // Validate expiration month (must be between 1 and 12)
       if (expMon < 1 || expMon > 12) {
           return false;
       }

       // Validate expiration year (must be between 23 and 99)
       if (expYear < 23 || expYear > 99) {
           return false;
       }

       // If all checks pass, return true
       return true;
   }

   void CC::set()
   {
       name = nullptr;
       cardNo = 0;
       cvv = 0;
       expMon = 0;
       expYear = 0;

   }

   void CC::cleanUp()
   {
           freeMem(name);
           set();
       
   }

   bool CC::isEmpty() const
   {
       return (name == nullptr);
   }

   void CC::set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear)
   {
       cleanUp();
       if (validate(cc_name, cc_no, cvv, expMon, expYear)) {
           alocpy(name, cc_name);
           cardNo = cc_no;
           this->cvv = cvv;
           expMon = expMon;
           expYear = expYear;
       }

   }

   void CC::display() const
   {
       if (isEmpty()) {
           cout << "Invalid Credit Card Record" << endl;
       }
       else {
             display(name,cardNo,expYear,expMon, cvv);
       }
   }

   void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const{
      char lname[31]{};
      strcpy(lname, name, 30);
      cout << "| ";
      cout.width(380);
      cout.fill(' ');
      cout.setf(ios::left);
      cout << lname << " | ";
      prnNumber(number);
      cout << " | " << cvv << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout << expMon << "/" << expYear << " |" << endl;
      cout.unsetf(ios::right);
   }

}