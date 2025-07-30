#ifndef SENECA_DATABASE_H
#define SENECA_DATABASE_H
/*
I have coded all the functions in this file as well. Usually it is preffered to do in the seperate
.cpp file , but I just did all in this for my personal experiences. 
*/
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <type_traits>

namespace seneca {

    enum class Err_Status {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };

    template <typename T>
    class Database {
        // Deleted copy & move operations — enforcing singleton
        Database(const Database&) = delete;
        Database& operator=(const Database&) = delete;
        Database(Database&&) = delete;
        Database& operator=(Database&&) = delete;

        // Data members
        int m_entries = 0;
        std::string keys[20];
        T values[20];
        std::string filename;
        static std::shared_ptr<Database<T>> instance;

        // Private constructor
        Database(const std::string& filename);

        // Encryption stub — specialized later
        void encryptDecrypt(T& value);

    public:
        // Singleton accessor
        static std::shared_ptr<Database<T>> getInstance(const std::string& dbFilename);

        // Query & modifier
        Err_Status GetValue(const std::string& key, T& value);
        Err_Status SetValue(const std::string& key, const T& value);

        // Destructor
        ~Database();
    };

    // Static instance definition
    template <typename T>
    std::shared_ptr<Database<T>> Database<T>::instance = nullptr;

    // Constructor with dynamic type conversion
    template <typename T>
    Database<T>::Database(const std::string& filename) : filename(filename) {
        std::cout << "** Database<T>::Database(const std::string&) [" << this << "]\n";

        std::ifstream fin(filename);
        std::string rawKey, rawValue;

        while (fin >> rawKey >> rawValue && m_entries < 20) {
            std::replace(rawKey.begin(), rawKey.end(), '_', ' ');

            T finalValue;
            if constexpr (std::is_same<T, std::string>::value) {
                finalValue = rawValue;
            }
            else if constexpr (std::is_same<T, long long>::value) {
                finalValue = std::stoll(rawValue);
            }
            else {
                // Add more type conversions here if needed
                static_assert(sizeof(T) == 0, "Unsupported type for Database");
            }

            encryptDecrypt(finalValue);
            keys[m_entries] = rawKey;
            values[m_entries] = finalValue;
            ++m_entries;
        }
    }

    // Encryption stub
    template <typename T>
    void Database<T>::encryptDecrypt(T& value) {
        // No-op (to be specialized)
    }

    // Singleton accessor
    template <typename T>
    std::shared_ptr<Database<T>> Database<T>::getInstance(const std::string& dbFilename) {
        if (instance == nullptr) {
            instance = std::shared_ptr<Database<T>>(new Database<T>(dbFilename));
        }
        return instance;
    }

    // GetValue method
    template <typename T>
    Err_Status Database<T>::GetValue(const std::string& key, T& value) {
        for (int i = 0; i < m_entries; ++i) {
            if (keys[i] == key) {
                value = values[i];
                return Err_Status::Err_Success;
            }
        }
        return Err_Status::Err_NotFound;
    }

    // SetValue method
    template <typename T>
    Err_Status Database<T>::SetValue(const std::string& key, const T& value) {
        for (int i = 0; i < m_entries; ++i) {
            if (keys[i] == key) {
                values[i] = value;
                return Err_Status::Err_Success;
            }
        }

        if (m_entries < 20) {
            keys[m_entries] = key;
            values[m_entries] = value;
            ++m_entries;
            return Err_Status::Err_Success;
        }
        else {
            return Err_Status::Err_OutOfMemory;
        }
    }

    // Destructor
    template <typename T>
    Database<T>::~Database() {
        std::cout << "** Database<T>::~Database() [" << this << "]\n";
        // Optional: backup logic can be added here
    }

} // namespace seneca

#endif // SENECA_DATABASE_H