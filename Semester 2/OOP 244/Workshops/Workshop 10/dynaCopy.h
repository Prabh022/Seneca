#ifndef DYNACOPY_H
#define DYNACOPY_H

namespace seneca {
    // Template function to dynamically copy an array
        template <typename T>
   
    // Two-argument dynaCopy: Creates a new dynamic copy of an array
    
    T* dynaCopy(const T* src, int size) {
        if (src == nullptr || size <= 0) return nullptr;

        T* dest = new T[size];
        for (int i = 0; i < size; ++i) {
            dest[i] = src[i];
        }
        return dest;
    }

    // Three-argument dynaCopy: Replaces destination array with a copy of the source
    template <typename T>
    T* dynaCopy(T*& dest, const T* src, int size) {
        delete[] dest;  // Deallocate previously allocated memory, if any

        if (src == nullptr || size <= 0) {
            dest = nullptr;
        }
        else {
            dest = new T[size];
            for (int i = 0; i < size; ++i) {
                dest[i] = src[i];
            }
        }
        return dest;
    }
    // Template function to print an array of any type
    template <typename T>
    void prnArray(const T* array, int size) {
        if (array == nullptr || size <= 0) {
            std::cout << "(empty)" << std::endl;
            return;
        }

        for (int i = 0; i < size; ++i) {
            std::cout << array[i];
            if (i < size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }

}
#endif // !DYNACOPY_H
