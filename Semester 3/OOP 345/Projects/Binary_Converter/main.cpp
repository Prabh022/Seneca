#include <iostream>
#include <string>
#include "BinaryConverter.h"8
#include "BinaryMath.h"
#include "BitwisePlayground.h"
#include "HistoryManager.h"

int main() {
    int choice;
    std::string input1, input2;

    while (true) {
        std::cout << "\n====  Binary Converter Toolkit ====\n";
        std::cout << "1. Decimal to Binary\n";
        std::cout << "2. Binary to Decimal\n";
        std::cout << "3. Binary Add\n";
        std::cout << "4. Binary Subtract\n";
        std::cout << "5. Bitwise AND\n";
        std::cout << "6. Bitwise OR\n";
        std::cout << "7. Bitwise XOR\n";
        std::cout << "8. Show History\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        try {
            if (choice == 1) {
                int decimal;
                std::cout << "Decimal number: ";
                std::cin >> decimal;
                std::string binary = BinaryConverter::decimalToBinary(decimal);
                std::cout << " Binary: " << binary << "\n";
                HistoryManager::addRecord("Decimal " + std::to_string(decimal) + " → Binary " + binary);
            }
            else if (choice == 2) {
                std::cout << "Binary number: ";
                std::cin >> input1;
                int decimal = BinaryConverter::binaryToDecimal(input1);
                std::cout << " Decimal: " << decimal << "\n";
                HistoryManager::addRecord("Binary " + input1 + " → Decimal " + std::to_string(decimal));
            }
            else if (choice == 3) {
                std::cout << "Binary 1: ";
                std::cin >> input1;
                std::cout << "Binary 2: ";
                std::cin >> input2;
                std::string result = BinaryMath::add(input1, input2);
                std::cout << " Sum: " << result << "\n";
                HistoryManager::addRecord(input1 + " + " + input2 + " = " + result);
            }
            else if (choice == 4) {
                std::cout << "Binary 1 (minuend): ";
                std::cin >> input1;
                std::cout << "Binary 2 (subtrahend): ";
                std::cin >> input2;
                std::string result = BinaryMath::subtract(input1, input2);
                std::cout << "→ Difference: " << result << "\n";
                HistoryManager::addRecord(input1 + " - " + input2 + " = " + result);
            }
            else if (choice == 5) {
                std::cout << "Binary 1: ";
                std::cin >> input1;
                std::cout << "Binary 2: ";
                std::cin >> input2;
                std::string result = BitwisePlayground::bitwiseAND(input1, input2);
                std::cout << "→ AND Result: " << result << "\n";
                HistoryManager::addRecord(input1 + " & " + input2 + " = " + result);
            }
            else if (choice == 6) {
                std::cout << "Binary 1: ";
                std::cin >> input1;
                std::cout << "Binary 2: ";
                std::cin >> input2;
                std::string result = BitwisePlayground::bitwiseOR(input1, input2);
                std::cout << " OR Result: " << result << "\n";
                HistoryManager::addRecord(input1 + " | " + input2 + " = " + result);
            }
            else if (choice == 7) {
                std::cout << "Binary 1: ";
                std::cin >> input1;
                std::cout << "Binary 2: ";
                std::cin >> input2;
                std::string result = BitwisePlayground::bitwiseXOR(input1, input2);
                std::cout << " XOR Result: " << result << "\n";
                HistoryManager::addRecord(input1 + " ^ " + input2 + " = " + result);
            }
            else if (choice == 8) {
                HistoryManager::showHistory();
            }
            else if (choice == 9) {
                std::cout << " Exiting Binary Converter. See you again!\n";
                break;
            }
            else {
                std::cout << "Invalid choice. Try again.\n";
            }
        }
        catch (const std::exception& ex) {
            std::cerr << " Error: " << ex.what() << "\n";
        }
    }

    return 0;
}