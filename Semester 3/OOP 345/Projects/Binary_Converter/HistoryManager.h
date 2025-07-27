#ifndef HISTORY_MANAGER_H
#define HISTORY_MANAGER_H

#include <vector>
#include <string>

class HistoryManager {
public:
    static void addRecord(const std::string& entry);
    static void showHistory();
};

#endif