#include "HistoryManager.h"
#include <iostream>

static std::vector<std::string> history;

void HistoryManager::addRecord(const std::string& entry) {
    history.push_back(entry);
}

void HistoryManager::showHistory() {
    std::cout << "\n🔍 Conversion History:\n";
    for (const auto& h : history) std::cout << "• " << h << "\n";
}