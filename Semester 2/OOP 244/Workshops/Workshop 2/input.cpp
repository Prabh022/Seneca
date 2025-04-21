#include <iostream>
#include "input.h"
using namespace std;
namespace seneca {
    int getInt() {
        int num = 0;
        bool done = false;
        do {
            // extract an integer from the console and put it in num
            cin >> num;
            // if this action fails (the integer is unreadable)
            if (cin.fail()) {
                cout << "Bad integer entry, please try again:\n> ";
                // clear the failure status to activate cin again
                cin.clear();
            }
            else {
                done = true;
            }
            // flush the keyboard buffer up to 1000 characters or '\n', whichever comes first
            cin.ignore(1000, '\n');
        } while (!done);
        return num;
    }
    int getInt(int min, int max) {
        int value;
        bool valid = false;
        do {
            value = getInt();  // call the original one
            if (value < min || value > max) {
                std::cout << "Invalid value, [" << min << "<=value<=" << max << "]: ";
            }
            else {
                valid = true;
            }
        } while (!valid);
        return value;
    }
    bool getInt(int& value, int min, int max) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Bad integer entry, please try again: ";
            return false;
        }
        else if (value < min || value > max) {
            return false;
        }
        return true;
    }

   
}

